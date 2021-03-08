#include<iostream>
#include"bintree_eda.h"
struct tSol {
	bool gene;
	int nivel;
};

template <class T >
tSol arbolGenealogico(bintree <T > const& arbol) { // O(N)

	if (arbol.empty()) {
		return { true,0};
	}
	else {
		
		tSol res_iz = arbolGenealogico(arbol.left());
		tSol res_dr = arbolGenealogico(arbol.right());
		if (res_iz.gene && res_dr.gene) {
			if (arbol.left().empty() && arbol.right().empty()) {
				return{ true,1};
			}
			else {
				if (arbol.left().empty())
					return{ false,0 };
				else {
					if (arbol.root() < arbol.left().root() + 18)
						return{ false,0 };
					else {
						if (!arbol.right().empty()) {
							if (arbol.left().root() < arbol.right().root() + 2 || arbol.root() < arbol.right().root() + 18)
								return{ false,0 };
							else {
								if (res_iz.nivel > res_dr.nivel)
									return{ true,res_iz.nivel + 1};
								else
									return{ true,res_dr.nivel + 1 };
							}
						}
						return{ true,res_iz.nivel + 1 };
					}
				}
			}
		}
		else
			return{ false,0 };
	}
}
void resuelveCaso() {
	bintree <int> arbol = leerArbol(-1);
	tSol sol = arbolGenealogico(arbol);
	if(sol.gene)
		std::cout << "SI " << sol.nivel << std::endl;
	else
		std::cout << "NO " << std::endl;
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