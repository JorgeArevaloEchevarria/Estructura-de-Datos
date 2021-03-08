#include<iostream>
#include<vector>
#include"bintree_eda.h"


template <class T >
class bintree_ext : public bintree <T > {
	using Link = typename bintree <T >::Link;

public:
	bintree_ext() : bintree <T >() {}
	bintree_ext(bintree_ext <T > const& l, T const& e, bintree_ext <T > const& r) : bintree <T >(l, e, r) {}
	void frontera(std::vector<int> &v)
	{
		return frontera(this->raiz,v);
	}
private:

	void frontera(Link r, std::vector<int> &v) {
		if (r == nullptr) { return; }
		else {
			frontera(r->left,v);
			frontera(r->right,v);
			if (r->left == nullptr && r->right == nullptr)
				v.push_back(r->elem);

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
	bintree_ext <int > arbol = leerArbol_ext(-1);
	std::vector<int> v;
	arbol.frontera(v);
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
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