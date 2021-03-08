#include<iostream>
#include<vector>
#include"bintree_eda.h"

template <class T >
void frontera(bintree <T > const& arbol, std::vector<T> &v) { // O(N)
	if (arbol.empty())
		return;
	if (arbol.right().empty() && arbol.left().empty()) 
		v.push_back(arbol.root());

	frontera(arbol.left(),v);
	frontera(arbol.right(),v);
	
}

void resuelveCaso() {
	bintree <int> arbol = leerArbol(-1);
	std::vector<int> v;
	frontera(arbol, v);
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] <<" ";
	}
	std::cout << std::endl;
}
int main() {
	// Para la entrada por fichero .
	// Comentar para acepta el reto
	/*
# ifndef DOMJUDGE
	std::ifstream in(" datos1 .txt ");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std :: cin to casos .txt
# endif*/
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
	{
		resuelveCaso(); std::cin.ignore();
	}
	// Para restablecer entrada . Comentar para acepta el reto
	/*
# ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system(" PAUSE ");
# endif
	return 0;*/
}