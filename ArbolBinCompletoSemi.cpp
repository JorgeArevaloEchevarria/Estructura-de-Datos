//Jorge Arevalo Echevarria
// NOMBRES Y APELLIDOS

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#include "bintree_eda.h"

struct tSol {
	int altura;
	bool completo;
	bool semi;
};

tSol semiCompletoAux(bintree<int> arbol) {
	if (arbol.empty()) {
		return {0,true, true};
	}
	else {
		
	
	}
}

int semiCompleto(bintree<int> arbol) {
	// completar (posiblemente definiendo también otras funciones)
	return semiCompletoAux(arbol).maxLong;
}

void resuelveCaso() {
	bintree<char> arbol = leerArbol('.');
	cout << semiCompleto(arbol) << '\n';
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
