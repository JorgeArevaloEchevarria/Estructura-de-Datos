//Jorge Arevalo Echevarria
// NOMBRES Y APELLIDOS

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#include "bintree_eda.h"

struct tSol {
	int adivinos;
	int numPares;
};

tSol adivinoAux(bintree<int> arbol) {
	if (arbol.empty()) {
		return {0,0};
	}
	else {
		tSol iz = adivinoAux(arbol.left());
		tSol dr = adivinoAux(arbol.right());
	
		if (iz.numPares + dr.numPares == arbol.root()) {
			iz.adivinos++;
		}
		
		if (arbol.root() % 2 == 0) {
			iz.numPares++;
		}
		return{ iz.adivinos + dr.adivinos,iz.numPares + dr.numPares };
	}
}

int adivino(bintree<int> arbol) {
   // completar (posiblemente definiendo también otras funciones)
	return adivinoAux(arbol).adivinos;
}

void resuelveCaso() {
   bintree<int> arbol = leerArbol(-1);
   cout << adivino(arbol) << '\n';
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
