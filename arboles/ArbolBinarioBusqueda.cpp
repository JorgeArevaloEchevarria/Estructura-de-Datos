#include<iostream>
#include"bintree_eda.h"
struct tSol {
	bool ok;
	int min;
	int max;
};


template <class T >
tSol arbolBinarioBusqueda(bintree <T > const& arbol) { // O(N)
	tSol sol;
	if (arbol.empty()) {
		sol.ok = true;
	}
	else {

		tSol iz = arbolBinarioBusqueda(arbol.left());
		tSol dr = arbolBinarioBusqueda(arbol.right());

		if (arbol.left().empty())
			sol.min = arbol.root();
		else
			sol.min = iz.min;

		if (arbol.right().empty())
			sol.max = arbol.root();
		else
			sol.max = dr.max;
		bool ok = ((arbol.left().empty() || iz.max < arbol.root()) && (arbol.right().empty() || dr.min > arbol.root()));
		sol.ok = iz.ok && dr.ok && ok;

	
	}

	return	sol;
}

void resuelveCaso() {
	bintree <int> arbol = leerArbol(-1);
	int minIz, maxDr;
	if (arbolBinarioBusqueda(arbol).ok)
		std::cout << "SI" << std::endl;
	else
		std::cout << "NO" << std::endl;
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
		resuelveCaso();
	}
	// Para restablecer entrada . Comentar para acepta el reto
	/*
# ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system(" PAUSE ");
# endif
	return 0;*/
}