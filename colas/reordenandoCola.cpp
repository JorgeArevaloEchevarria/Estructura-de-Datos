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

	void mostrar() {
		if (this->empty()) {
			//throw std::domain_error("mostrando una dcola vacia");
		}
		else {
			Nodo* aux = this->fantasma->sig;
			while (aux != this->fantasma) {
				std::cout << aux->elem << " ";
				aux = aux->sig;
			}

		}
		std::cout << std::endl;
	}
	// duplicar los nodos de una lista enlazada simple
	void reordenar() {
		Nodo* pos = this->fantasma->sig;
		while (pos!=this->fantasma) {
			if (pos->elem < 0) {
				if (pos != this->fantasma->sig) {
					Nodo* aux = this->fantasma->sig;
					Nodo* sig = pos->sig;
					Nodo* ant = pos->ant;
					ant->sig = sig;
					sig->ant = ant;//quitamos de la posicion en la que estaba

					this->fantasma->sig = pos;
					pos->sig = aux;
					pos->ant = this->fantasma;
					pos = ant;
				}

			}
			pos = pos->sig;
		}
	}
};

void resuelveCaso() {
	// leer los datos de la entrada

	int n;
	cin >> n;
	while (n != 0 ) {
		deque_ext<int> colaDoble;
		int num;
		for (int i = 0; i < n; i++) {
			cin >> num;
			colaDoble.push_back(num);
		}
	
		colaDoble.reordenar();
		colaDoble.mostrar();
		cin >> n;
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