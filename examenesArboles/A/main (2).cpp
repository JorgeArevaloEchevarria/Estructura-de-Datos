
// NOMBRE Y APELLIDOS (USUARIO DEL JUEZ)

// COMENTARIO SOBRE LA SOLUCIÓN Y SU COSTE JUSTIFICADO


#include <iostream>                                                            
#include <fstream>               
#include <algorithm>
using namespace std;

#include "bintree_eda.h"


// Implementa aquí la función pedida. Puedes definir las funciones
// auxiliares que necesites
/*Coste:
	T(n){C0 si el arbol.empty()
		{T(ni)+T(nd) +c1 siendo ni el numero de nodos del hijo izquierdo, y nd el numero de nodos del hijo derecho
		quedando un coste O(n) siendo lineal respecto al numero de nodos del arbol
*/

typedef struct tSol {
	int numPares;
	bool pareado;
};

tSol pareado(bintree<int> arbol) {
	if (arbol.empty()) {
		return{ 0,true };
	}
	else {

		tSol iz = pareado(arbol.left());
		tSol dr = pareado(arbol.right());
		
		if (iz.pareado && dr.pareado) {
			if (abs(iz.numPares - dr.numPares) < 2) {
				if (arbol.root() % 2 == 0)
					iz.numPares++;

				return { iz.numPares + dr.numPares,true };
			}
		}
		
		return { 0,false };
	}
}


void resuelveCaso() {
   auto arbol = leerArbol(-1);
   if (pareado(arbol).pareado)
      cout << "SI\n";
   else
      cout << "NO\n";
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
   // system("PAUSE");
#endif
   return 0;
}
