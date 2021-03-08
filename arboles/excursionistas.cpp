#include<iostream>
#include"bintree_eda.h"
struct tSol {
	int grupos;
	int excursionistas;
};

template <class T >
tSol excursionistas(bintree <T > const& arbol) { // O(N)

	if (arbol.empty()) {
		return { 0,0 };
	}
	else {
		tSol res_iz = excursionistas(arbol.left());
		tSol res_dr = excursionistas(arbol.right());

		if (arbol.root() == 0) {
			if (res_dr.excursionistas > res_iz.excursionistas)
				return { res_dr.grupos + res_iz.grupos,res_dr.excursionistas };
			else return { res_dr.grupos + res_iz.grupos,res_iz.excursionistas };

		}
		else {
			if (res_dr.grupos == 0 && res_iz.grupos==0)
				return { 1,arbol.root()};
			else {
				if (res_dr.excursionistas > res_iz.excursionistas) 
					return { res_dr.grupos + res_iz.grupos,res_dr.excursionistas+arbol.root()};
				else
					return { res_dr.grupos + res_iz.grupos,res_iz.excursionistas+arbol.root()};
			}
		}
	}
}
void resuelveCaso() {
	bintree <int> arbol = leerArbol(-1);
	tSol sol = excursionistas(arbol);
	std::cout << sol.grupos <<" "<<sol.excursionistas<< std::endl;
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