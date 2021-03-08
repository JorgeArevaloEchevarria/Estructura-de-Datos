
// NOMBRE Y APELLIDOS (USUARIO DEL JUEZ)

// COMENTARIO SOBRE LA SOLUCIÓN Y SU COSTE JUSTIFICADO


#include <iostream>                              
#include <fstream>               
#include <algorithm>
using namespace std;

#include "bintree_eda.h"


// Implementa aquí la función pedida. Puedes definir las funciones
// auxiliares que necesites
/*
Coste :
	T(n){ C0 si arbol.empty()
		{T(ni)+T(nd) + 1 si !arbol.empty() siendo ni el numero de nodos hijo iz, y nd el numero de nodos hijo dr
		siendo el coste final O(n) siendo n el numero de nodos del arbol
*/

typedef struct tSol {
	int sumaNodos;
	bool esDiestro;
};

tSol diestro(bintree<int> arbol) {
	if (arbol.empty()) {
		return{0,true};
	}
	else {

		tSol iz = diestro(arbol.left());
		tSol dr = diestro(arbol.right());
	
		if (iz.esDiestro && dr.esDiestro) {
			if (iz.sumaNodos < dr.sumaNodos)
				return { iz.sumaNodos + dr.sumaNodos + arbol.root(),true };
			else if (iz.sumaNodos == 0 && dr.sumaNodos == 0)
				return { arbol.root(),true };
		}
		return { 0,false };
	}

}


void resuelveCaso() {
   auto arbol = leerArbol(-1);
   if (diestro(arbol).esDiestro)
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
