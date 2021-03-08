// Jorge Arevalo Echevarria
// A05


#include <iostream>
#include <iomanip>
#include <fstream>
#include"queue_eda.h"

using namespace std;

template <class T>
class queue_ext : public queue<T> {
	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí
public:
	queue_ext() : queue <T>() {}

	void print(std::ostream& o = std::cout) const {
		Nodo* it = this->prim;
		for (int i = 0; i < this->nelems; i++) {
			cout << it->elem << " ";
			it = it->sig;
		}
		cout << endl;
	}
	// duplicar los nodos de una lista enlazada simple
	void mezclar(queue_ext<T>& other) {
		if (this->empty()) {
			this->prim = other.prim;
			this->ult = other.ult;
			this->nelems = other.nelems;
		}
		else if (other.empty()) {
			Nodo* prin=this->prim;
			Nodo* aux = other.prim;

			while (aux != nullptr) {
				other.prim = other.prim->sig;
				if (aux->elem < prin->elem) {
					aux->sig = prin;
					this->prim = aux;
					prin = aux;
					aux = other.prim;
				}
				else {
					while (prin->sig != nullptr && aux->elem > prin->sig->elem)
						prin = prin->sig;

					aux->sig = prin->sig;
					prin->sig = aux;
					aux = other.prim;
				}
			
			}
			this->nelems += other.nelems;
		}
		/*
		other.ult = nullptr;
		other.nelems = 0;*/
	}
};

void resuelveCaso() {
	// leer los datos de la entrada

	queue_ext<int> principal;
	queue_ext<int> other;
	int n;

	cin >> n;
	while (n != 0) {
		principal.push(n);
		cin >> n;
	}

	cin >> n;
	while (n != 0) {
		other.push(n);
		cin >> n;
	}

	principal.mezclar(other);
	principal.mostrar();

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		resuelveCaso();
	}


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}