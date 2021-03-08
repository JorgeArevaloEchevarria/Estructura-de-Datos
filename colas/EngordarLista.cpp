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
	void engordar(deque_ext<T> &other) {
		if (this->empty()) {
			//reordenar el fantasma
			this->fantasma->sig = other.fantasma->sig;
			this->fantasma->sig->ant = this->fantasma;
			this->fantasma->ant = other.fantasma->ant;
			this->fantasma->ant->sig = this->fantasma;
			this->nelems = other.nelems;
		}
		else {
			Nodo* auxOther = other.fantasma->sig;
			Nodo* auxOtherSig = auxOther->sig;
			int cont = 0;
			while(auxOther != other.fantasma){
				if (cont % 2 == 0) {//van al principio
					Nodo* auxSig = this->fantasma->sig;
					auxOther->ant = this->fantasma;
					auxOther->sig = auxSig;
					auxSig->ant = auxOther;
					this->fantasma->sig = auxOther;
					auxOther = auxOtherSig;
					auxOtherSig = auxOther->sig;
				}
				else {//van al final
					Nodo* auxAnt = this->fantasma->ant;
					auxOther->sig = this->fantasma;
					auxOther->ant = auxAnt;
					auxAnt->sig = auxOther;
					this->fantasma->ant = auxOther;
					auxOther = auxOtherSig;
					auxOtherSig = auxOther->sig;
				}
				cont++;
				this->nelems++;
			}
		}
		other.fantasma->ant = other.fantasma->sig = other.fantasma;
	}
};

void resuelveCaso() {
	// leer los datos de la entrada

	int n;
	int num;
	cin >> n;

	deque_ext<int> colaPrin;
	deque_ext<int> colaSec;
	for (int i = 0; i < n; i++) {
		cin >> num;
		colaPrin.push_back(num);
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		colaSec.push_back(num);
	}
	
	colaPrin.engordar(colaSec);
	colaPrin.mostrar();
	
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}