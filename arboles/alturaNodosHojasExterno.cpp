#include<iostream>
#include"bintree_eda.h"

struct tSol {
	int nodo;
	int altura;
	int hojas;
};
template <class T >
tSol alturaNodoHoja(bintree <T > const& arbol) { // O(N)

		if (arbol.empty()) {
			return { 0, 0, 0};
		}
		else {
			tSol res_iz = alturaNodoHoja(arbol.left());
			tSol res_dr = alturaNodoHoja(arbol.right());
			if (arbol.left().empty() && arbol.right().empty())
				res_iz.hojas++;


			return { res_dr.nodo + res_iz.nodo + 1,
			std::max(res_iz.altura , res_dr.altura) + 1 ,
			res_dr.hojas + res_iz.hojas};
		}
}
void resuelveCaso() {
	bintree <char > arbol = leerArbol('.');
	tSol sol = alturaNodoHoja(arbol);
	std::cout << sol.nodo << std::endl;
	std::cout << sol.hojas << std::endl;
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