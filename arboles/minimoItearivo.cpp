#include<iostream>
#include<vector>
#include<string>
#include"bintree_eda.h"

template <class T >
T minimo(bintree <T > const& arbol) { // O(N)
	auto it = arbol.begin();
	T mini = *it;
	while (it != arbol.end()) {
		if (*it < mini)
			mini = *it;
		++it;
	}
	return mini;
}



bool resuelveCaso() {

	char letra;
	std::cin >> letra;
	if (!std::cin) return false;
	if (letra == 'N') {
		bintree <int> arbolN = leerArbol(-1);
		std::cout << minimo(arbolN) << std::endl;
	}
	else if (letra == 'P') {
		std::string centinela = "#";
		bintree <std::string> arbolP = leerArbol(centinela);
		std::cout << minimo(arbolP) << std::endl;
	}
	return true;
}

int main() {
	// Para la entrada por fichero .
	// Comentar para acepta el reto
/*
# ifndef DOMJUDGE
		std::ifstream in(" datos1 .txt ");
		auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std :: cin to casos .txt
# endif*/


	while (resuelveCaso());



	// Para restablecer entrada . Comentar para acepta el reto
/*
# ifndef DOMJUDGE // para dejar todo como estaba al principio
		std::cin.rdbuf(cinbuf);
		system(" PAUSE ");
# endif
		return 0;*/


}