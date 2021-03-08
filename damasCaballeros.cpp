//Jorge Arevalo Echevarria
// NOMBRES Y APELLIDOS

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#include "bintree_eda.h"

struct tSol {
	int caballeros;
	int salvados;
};

tSol damasCaballerosAux(bintree<char> arbol, int monstruos) {
	if (arbol.empty()) {
		return { 0,0 };
	}
	else {
		if (arbol.root() == 'M')
			monstruos++;

		tSol iz = damasCaballerosAux(arbol.left(),monstruos);
		tSol dr = damasCaballerosAux(arbol.right(),monstruos);

		if (arbol.root() == 'D') {
			if (iz.caballeros + dr.caballeros >= monstruos)
				iz.salvados++;
		}
		else if (arbol.root() == 'C') {
			iz.caballeros++;
		}
		return{ iz.caballeros + dr.caballeros,iz.salvados + dr.salvados };
	}
}

int damasCaballeros(bintree<char> arbol) {
	// completar (posiblemente definiendo también otras funciones)
	return damasCaballerosAux(arbol,0).salvados;
}

void resuelveCaso() {
	bintree<char> arbol = leerArbol('.');
	cout << damasCaballeros(arbol) << '\n';
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
