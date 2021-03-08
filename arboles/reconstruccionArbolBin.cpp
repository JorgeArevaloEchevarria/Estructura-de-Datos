#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include"bintree_eda.h"

//preorden raiz,iz,dr
//inorder iz,raiz,dr
bintree <int > reconstruccion(std::vector<int> &preorden, std::vector<int> &inorder) { // O(N)

	if (preorden.size() == 1 && inorder.size() == 1) {
		return bintree<int>(preorden.front());
	}
	else if (preorden.empty() && inorder.empty()) {
		return bintree<int>();
	
	}else{
		std::vector<int> preordenIz;
		std::vector<int> preordenDr;
		std::vector<int> inorderIz;
		std::vector<int> inorderDr;
		auto itIno = inorder.begin();
		auto itPre = preorden.begin();
		itPre++;

		while (preorden.front() != *itIno) {
			inorderIz.push_back(*itIno);
			preordenIz.push_back(*itPre);
			itIno++;
			itPre++;
		}
		itIno++;
		while (itIno != inorder.end()) {
			inorderDr.push_back(*itIno);
			preordenDr.push_back(*itPre);
			itIno++;
			itPre++;
		}

		bintree<int> arbolIz = reconstruccion(preordenIz, inorderIz);
		bintree<int> arbolDr = reconstruccion(preordenDr, inorderDr);

		return bintree<int>(arbolIz, preorden.front(), arbolDr);
	}

}

void rellenar(std::vector<int>& vec) {
	int aux;
	std::string line;
	std::getline(std::cin, line);
	std::stringstream flux(line);

	if (line != "\n") {
		while (flux >> aux) {
			vec.push_back(aux);
		}
	}

}

bool resuelveCaso() {
	std::vector<int> preorden;
	std::vector<int> inorden;
	rellenar(preorden);
	rellenar(inorden);

	bintree<int> arbol=(reconstruccion(preorden, inorden));
	std::vector<int> postorden = arbol.postorder();
	auto it = postorden.begin();
	while (it != postorden.end()) {
		std::cout << *it << " ";
		it++;
	}
	
	std::cout << "\n";

	if (!std::cin) { return false; }
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