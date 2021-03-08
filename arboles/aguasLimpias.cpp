#include<iostream>
#include"bintree_eda.h"
struct tSol {
	int caudal;
	int navegables;
};


template <class T >
tSol aguasLimpias(bintree <T > const& arbol) { // O(N)
	if (arbol.empty()) 
		return{0,0};
	else if (arbol.left().empty() && arbol.right().empty())
		return{ 1,0 };
	else {
		tSol iz = aguasLimpias(arbol.left());
		tSol dr = aguasLimpias(arbol.right());
		
		if (iz.caudal > 2)
			iz.navegables++;
		if (dr.caudal > 2)
			dr.navegables++;
		if((iz.caudal + dr.caudal - arbol.root())<0)
			return{ 0 ,iz.navegables + dr.navegables };
		else
			xreturn{ iz.caudal + dr.caudal-arbol.root() ,iz.navegables + dr.navegables };
	}
}

void resuelveCaso() {
	bintree <int> arbol = leerArbol(-1);
	tSol sol = aguasLimpias(arbol);
	std::cout << sol.navegables << std::endl;
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