
// JOSE OTEGUI MARIN (E52)

/*EXPLICACION DEL ALGORITMO
He creado un struct tSol que lleva la suma de los valores de los nodos y del numero de acumulados para la solucion.
Cada vez que se visita un nodo se suman los valores acumulados de todos sus hijos y se compruea si ese valor es igual 
al valor del nodo actual. En caso afirmativo suma 1 a los valores de los acumulados de sus hijos.
*/

//COSTE: el coste del algoritmo es de O(n) ya que se recorre una unica vez cada nodo del arbol


#include <iostream>                                             
#include <fstream>               
#include <algorithm>
using namespace std;

#include "bintree_eda.h"



typedef struct{
	int suma;
	int numAcumulados;
}tSol;

tSol profundizarAux(bintree<int> arbol){
	if (arbol.empty()) {
		return { 0,0 };
	}
	else {
		tSol iz = profundizarAux(arbol.left());
		tSol dr = profundizarAux(arbol.right());
	
		if (iz.suma + dr.suma == arbol.root()) {
			return{ iz.suma + dr.suma + arbol.root(),iz.numAcumulados + dr.numAcumulados + 1 };
		}
		else{
			return { iz.suma + dr.suma + arbol.root(),iz.numAcumulados + dr.numAcumulados };
		}
	}
	
}

int profundizar(bintree<int> arbol) {
	return profundizarAux(arbol).numAcumulados;
}


void resuelveCaso() {
   auto arbol = leerArbol(-1);
   cout << profundizar(arbol) << '\n';
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
