#include<iostream>
#include"bintree_eda.h"
struct tSol {
	int diametro;
	int altura;
};

template <class T >
class bintree_ext : public bintree <T > {
	using Link = typename bintree <T >::Link;

public:
	bintree_ext() : bintree <T >() {}
	bintree_ext(bintree_ext <T > const& l, T const& e, bintree_ext <T > const& r) : bintree <T >(l, e, r) {}
	tSol diametro()
	{
		return diametro(this->raiz);
	}
private:

	tSol diametro(Link r) {
		if (r == nullptr) { return{0,0}; }
		else {
			tSol res_iz = diametro(r->left);
			tSol res_dr = diametro(r->right);
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
};

template <typename T >
inline bintree_ext <T > leerArbol_ext(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un arbol vacio
		return {};
	}
	else { // leer recursivamente los hijos
		bintree_ext <T > iz = leerArbol_ext(vacio);
		bintree_ext <T > dr = leerArbol_ext(vacio);
		return { iz , raiz , dr };
	}
}



void resuelveCaso() {
	bintree_ext <char> arbol = leerArbol_ext('.');
	tSol sol = arbol.diametro();
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