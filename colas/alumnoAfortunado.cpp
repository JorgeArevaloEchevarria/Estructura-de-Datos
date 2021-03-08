// Jorge Arevalo Echevarria
// A05


#include <iostream>
#include <iomanip>
#include <fstream>
#include<queue>
using namespace std;
/*
template <class T>
class deque_ext : public deque<T> {
	using Nodo = typename deque<T>::Nodo; // para poder usar Nodo aquí
public:
	deque_ext() : deque <T>() {}

	void print(std::ostream& o = std::cout) const {
		Nodo* it = this->prim;
		for (int i = 0; i < this->nelems; i++) {
			cout << it->elem << " ";
			it = it->sig;
		}
		cout << endl;
	}
	// duplicar los nodos de una lista enlazada simple
	int afortunado(const int m) {
		Nodo* pos = this->fantasma->sig;
		while (this->nelems != 1) {
			for (int i = 0; i < m; i++) {
				pos = pos->sig;
				if (pos == this->fantasma)
					pos = pos->sig;
			}
			Nodo* ant = pos->ant;
			Nodo* sig = pos->sig;
			ant->sig = sig;
			sig->ant = ant;
			pos = sig;
			this->nelems--;
		}
		return this->fantasma->sig->elem;
	}
};*/

int afortunado(queue<int> cola,const int m) {

	while (cola.size() != 1) {
		for (int i = 0; i < m; i++) {
			int num = cola.front();
			cola.pop();
			cola.push(num);
		}
		cola.pop();
	}
	return cola.front();
}

void resuelveCaso() {
	// leer los datos de la entrada

	
	int n, m;

	cin >> n;
	cin >> m;
	while (n != 0 && m != 0) {
		queue<int> cola;
		for (int i = 1; i <= n; i++) {
			cola.push(i);
		}

		cout << afortunado(cola,m) << endl;
		cin >> n;
		cin >> m;
	}
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}