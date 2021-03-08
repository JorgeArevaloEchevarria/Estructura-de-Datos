#include<iostream>
#include"bintree_eda.h"


template <class T >
class bintree_ext : public bintree <T > {
	using Link = typename bintree <T >::Link;

private:
	struct tSol {
		int nodo;
		int hoja;
		int altura;
	};

public:
	bintree_ext() : bintree <T >() {}
	bintree_ext(bintree_ext <T > const& l, T const& e, bintree_ext <T > const& r) : bintree <T >(l, e, r) {}
	tSol nodosHojasAltura()
	{
		return nodosHojasAltura(this->raiz);
	}
private:
	/*struct tSol {
		bool eq;
		int altura;
	};*/
	tSol nodosHojasAltura(Link r) {
		if (r == nullptr) { return { 0, 0, 0 }; }
		else {
			tSol Izda = nodosHojasAltura(r-> left);
			tSol Drch = nodosHojasAltura(r-> right);
			if (r->left == nullptr && r->right == nullptr)
				Izda.hoja++;
			
			return {
			Izda.nodo + Drch.nodo + 1,
			Izda.hoja + Drch.hoja,
			std::max(Izda.altura , Drch.altura) + 1 };
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
	bintree_ext <char > arbol = leerArbol_ext('.');
	std::cout<<arbol.nodosHojasAltura().nodo <<" "<< arbol.nodosHojasAltura().hoja
	<< " " << arbol.nodosHojasAltura().altura<<std::endl;
}
int main() {
	// Para la entrada por fichero .
	/*
# ifndef DOMJUDGE
	std::ifstream in(" datos1 .txt ");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std :: cin to casos .txt
# endif
*/
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
	{
		resuelveCaso(); std::cin.ignore();
	}
	/*
# ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system(" PAUSE ");
# endif
	return 0;
	*/
}