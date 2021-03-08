#include<iostream>
#include"bintree_eda.h"
struct tSol {
	int altura;
	int ramaCorta;
};


template <class T >
tSol subArbol(bintree <T > const& arbol) { // O(N)

	if (arbol.empty()) {
		return { 0,0};
	}
	else {
		
		tSol iz = subArbol(arbol.left());
		tSol dr = subArbol(arbol.right());

		int minRama = std::min(iz.ramaCorta, dr.ramaCorta) + 1;
		int maxAl = std::max(std::max(dr.altura, iz.altura),minRama);
		
		
		return {maxAl,minRama};
	}
}

void resuelveCaso() {
	bintree <char> arbol = leerArbol('.');
	tSol sol = subArbol(arbol);
	std::cout << sol.altura << std::endl;
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