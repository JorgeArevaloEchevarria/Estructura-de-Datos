//jorge Arevalo Echevarria


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"

using namespace std;

template <class T>
class queueDuplica : public queue<T> {
	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí
public:
	void print(std::ostream& o = std::cout) const {
		Nodo* it = this->prim;
		for (int i = 0; i < this->nelems; i++) {
			cout << it->elem << " ";
			it = it->sig;
		}
		cout << endl;
	}

	void  mezcla(queueDuplica<T>* otra) {

		if (this->empty()) {
			this->prim = otra->prim;
			this->ult = otra->ult;
			this->nelems = otra->nelems;
		}
		else if (!otra->empty()) {
			Nodo* actual = this->prim;
			Nodo* insertable = otra->prim;


			while (insertable != nullptr) {
				otra->prim = otra->prim->sig;

				if (insertable->elem < actual->elem) {
					insertable->sig = actual;
					this->prim = insertable;
					actual = insertable;
					insertable = otra->prim;
				}
				else {
					while (actual->sig != nullptr && insertable->elem > actual->sig->elem)
						actual = actual->sig;

					insertable->sig = actual->sig;
					actual->sig = insertable;
					insertable = otra->prim;
				}
			}
			this->nelems += otra->nelems;

		}
		//vaciar la lista 2
		/*otra->prim = nullptr;
		otra->ult = nullptr;
		otra->nelems = 0;*/

	}
};

bool resuelveCaso() {
	// leer los datos de la entrada
	int aux;

	queueDuplica<int> principal;
	queueDuplica<int>* otra = new queueDuplica<int>();
	cin >> aux;
	while (aux != 0) {
		principal.push(aux);
		cin >> aux;
	}
	cin >> aux;
	while (aux != 0) {
		otra->push(aux);
		cin >> aux;
	}

	principal.mezcla(otra);
	principal.print();

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}