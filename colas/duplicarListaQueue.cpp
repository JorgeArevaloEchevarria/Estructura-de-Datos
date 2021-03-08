// Nombre del alumno .....Jorge Arevalo Ecehvarria
// Usuario del Juez ......A05


#include <iostream>
#include <iomanip>
#include <fstream>
#include"queue_eda.h"


/*// función que resuelve el problema
queue<int> resolver(queue<int> cola) {
	queue<int> colaSol;
	int n = cola.size();
	while(!cola.empty()) {
		int aux = cola.front();
		colaSol.push(aux);
		colaSol.push(aux);
		cola.pop();
	}
	return colaSol;
}*/

template <class T>
class queue_ext : public queue<T> {
	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí
public:
	queue_ext() : queue <T>() {}

	void print(std::ostream& o = std::cout) const {
		Nodo* it = this->prim;
		for (int i = 0; i < this->nelems; i++) {
			std::cout << it->elem << " ";
			it = it->sig;
		}
		std::cout << std::endl;
	}
	// duplicar los nodos de una lista enlazada simple
	void duplica() {
		if (this->empty()) {
			//throw std::domain_error("la cola vacia no tiene elemtos que duplicar");
		}
		else {
			Nodo* auxPrim = this->prim;
			//aux->sig = prim->sig;
			//prim->sig = aux;
			while (auxPrim != this->ult) {
				Nodo* auxSig = new Nodo(auxPrim->elem);
				auxSig->sig = auxPrim->sig;
				auxPrim->sig = auxSig;
				auxPrim = auxSig->sig;
				this->nelems++;
			}
			Nodo* auxSig = new Nodo(this->ult->elem);
			auxPrim->sig = auxSig;
			this->ult = auxSig;
		}
	}
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	//if (caso especial)
		//return false;
	int num;
	queue_ext<int> cola;
	std::cin >> num;

	if (!std::cin)
		return false;

	while (num != 0) {
		cola.push(num);
		std::cin >> num;
	}

	cola.duplica();
	// escribir sol
	cola.mostrar();
	return true;

}

int main() {
	
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


	while (resuelveCaso());
	
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}