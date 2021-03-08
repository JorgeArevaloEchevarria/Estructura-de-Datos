#include<iostream>
#include"bintree_eda.h"
struct tSol{
	int diametro;
	int altura;
};

template <class T >
tSol alturaNodoHoja(bintree <T > const& arbol) { // O(N)

	if (arbol.empty()) {
		return {0,0};
	}
	else {
		tSol res_iz = alturaNodoHoja(arbol.left());
		tSol res_dr = alturaNodoHoja(arbol.right());
		int diametro, altura;
		if (res_dr.diametro < res_iz.diametro)
			diametro = res_iz.diametro;
		else
			diametro = res_dr.diametro;
		if (res_dr.altura < res_iz.altura)
			altura = res_iz.altura;
		else
			altura = res_dr.altura;
		if (diametro < res_dr.altura + res_iz.altura + 1)
			return{ res_dr.altura + res_iz.altura + 1 ,altura + 1 };
		else
			return{ diametro,altura + 1 };
		
	}
}
void resuelveCaso() {
	bintree <char > arbol = leerArbol('.');
	tSol sol = alturaNodoHoja(arbol);
	std::cout << sol.diametro << std::endl;
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