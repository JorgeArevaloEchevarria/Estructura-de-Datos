//Jorge Arevalo Echevarria
// NOMBRES Y APELLIDOS

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#include "bintree_eda.h"

struct tSol {
	int longitud;
	int maxLong;
};

tSol caminoParesAux(bintree<int> arbol) {
	tSol sol;
	if (arbol.empty()) {
		sol.longitud = 0;
		sol.maxLong = 0;
	}
	else {
		
		tSol iz = caminoParesAux(arbol.left());
		tSol dr = caminoParesAux(arbol.right());

		if (iz.maxLong > dr.maxLong)
			sol.maxLong = iz.maxLong;
		else
			sol.maxLong = dr.maxLong;

		if (arbol.root() % 2 == 0) {

			if (iz.longitud + dr.longitud + 1 > sol.maxLong)
				sol.maxLong = iz.longitud + dr.longitud + 1;

			if (iz.longitud > dr.longitud)
				sol.longitud = iz.longitud + 1;
			else
				sol.longitud = dr.longitud + 1;
		}
		else {
			sol.longitud = 0;
		}
	}
	return sol;
}

int caminoPares(bintree<int> arbol) {
   // completar (posiblemente definiendo también otras funciones)
	return caminoParesAux(arbol).maxLong;
}

void resuelveCaso() {
   bintree<int> arbol = leerArbol(-1);
   cout << caminoPares(arbol) << '\n';
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
