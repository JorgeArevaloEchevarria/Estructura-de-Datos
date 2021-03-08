// Jorge Arevalo Echevarria
// A05


#include <iostream>
#include <iomanip>
#include <fstream>
#include"deque_eda.h"

using namespace std;

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
	void insertar(deque_ext<T>& other, const int pos) {
		if (pos == 0) {
			Nodo* ini = this->fantasma->sig;
			Nodo* otherFant = other.fantasma;
			this->fantasma->sig = otherFant->sig;
			otherFant->sig->ant = this->fantasma;
			otherFant->ant->sig = ini;
		}
		else if (pos == this->nelems) {
			Nodo* ult = this->fantasma->ant;
			Nodo* otherFant = other.fantasma;
			ult->sig = otherFant->sig;
			otherFant->sig->ant = ult;
			this->fantasma->ant = otherFant->ant;
			otherFant->ant->sig = this->fantasma;
		}
		else {
			Nodo* ini = this->fantasma->sig;
			Nodo* otherFant = other.fantasma;
			for (int i = 1; i < pos; i++) {
				ini = ini->sig;
			}
			Nodo* aux = ini->sig;//para dejar ordenado anteriores y siguientes
			ini->sig = otherFant->sig;
			otherFant->sig->ant = ini;
			otherFant->ant->sig = aux;
			aux->ant = otherFant->ant;
		}
		other.fantasma->sig = other.fantasma->ant = other.fantasma;
	}
};

bool resuelveCaso() {
	// leer los datos de la entrada

	deque_ext<int> principal;
	deque_ext<int> other;
	int n, m, aux, pos;

	cin >> n;
	if (!std::cin)
		return false;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		principal.push_back(aux);
	}
	cin >> m >> pos;
	for (int i = 0; i < m; i++) {
		cin >> aux;
		other.push_back(aux);
	}

	principal.insertar(other, pos);
	principal.mostrar();

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}