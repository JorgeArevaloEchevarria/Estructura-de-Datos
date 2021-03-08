//Jorge Arevalo Echevarria
// NOMBRES Y APELLIDOS

#include <iostream>
#include <fstream>
#include <algorithm>
#include<vector>
#include "bintree_eda.h"
#include<sstream>
using namespace std;



bintree<int> reconstruccionArBin(vector<int> preorden) {
	
	
	int raiz = preorden.front();
	bintree<int> arbol = bintree<int>(raiz);
	bintree<int> arbolAux = arbol;
	vector<int>::iterator it = preorden.begin();
	it++;

	while (it != preorden.end()) {
		while (!arbolAux.empty()) {//encontramos donde se ubicaria del arbol
			if (arbolAux.root() < *it) {
				arbolAux = arbolAux.left();
			}
			else {
				arbolAux = arbolAux.right();
			}
		}
		arbolAux = bintree<int>(*it);
		arbolAux = arbol;
	}
	return arbol;
}


bool resuelveCaso() {
	vector<int> preorden;
	stringstream s;
	string linea;
	getline(cin, linea);
	
	if (!std::cin) return false;
	

	int num;
	while(s>>num){
		preorden.push_back(num);
	}
	bintree<int> arbol = reconstruccionArBin(preorden);
	vector<int> postorden = arbol.postorder();
	for (int i : postorden) {
		cout << i << " ";
	}
	cout << endl;

   return true;
}


int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   while (resuelveCaso());

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
