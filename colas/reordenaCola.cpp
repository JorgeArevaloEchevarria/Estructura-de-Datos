// Jesus Martin Moraleda
// A43


#include <iostream>
#include <iomanip>
#include <fstream>
#include"list_eda.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void reordena(list<int> &lista) {
	list<int>::iterator it = lista.begin();
	list<int>::iterator it = lista.begin();
	bool ordenado = false;
	while (!ordenado) {
		if (*it < 0) {
			lista.push_front(*it);
			it = lista.erase(it);
		}
		if (it == lista.end()) {
			ordenado = true;
		}
		else
			it++;
	}
}

bool resuelveCaso() {
	// leer los datos de la entrada

	list<int> lista;

	int k,n;
	std::cin >> k;
	while (k > 0) {
		std::cin >> n;
		lista.push_back(n);
		k--;
	}

	reordena(lista);
	list<int>::iterator it = lista.begin();
	while (it != lista.end()) {
		int k = *it;
		std::cout << k << " ";
		it++;
	}

	std::cout << std::endl;


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	/*
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 
*/

	while (resuelveCaso())
		;

	/*0
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif*/

	return 0;
}