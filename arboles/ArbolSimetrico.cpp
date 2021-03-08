#include<iostream>
#include"bintree_eda.h"
struct tSol {
	bool gene;
	int nivel;
};
/*
f(arbol1,arbol2)

T(n1,Tn2)={T(n1iz,n2dr)+t(n1dr,n2iz)+C}
O(min(n1,n2))//n1 lado izquierdo, n2 lado derecho

o con una variable

T(n1,n2) = c si uno de los arboles es vacio
T(n1,n2)= T(n1i,n2d) + T(n1d,n2i) + c 
la recurrencia es deñ orden O(min(n1,n2)) siendo n1 = n1i +n1d y n2 = n2i +n2d
el coste es lineal en eñ numero de nodods del arbol porque cada nodo del arbol se compara una unica vez con su nodo simetrico
la comparacion es de coste constante
*/

template <class T >
bool arbolSimetrico(bintree <T > const& arbolIz, bintree <T > const& arbolDr) { // O(N)
	if (arbolIz.empty() && arbolDr.empty())
		return true;
	else if (arbolIz.empty() && !arbolDr.empty() || !arbolIz.empty() && arbolDr.empty())
		return false;
	else {
		/*
		if (arbolSimetrico(arbolIz.left(), arbolDr.right())) {
			if (arbolSimetrico(arbolIz.right(), arbolDr.left())) {
				if ((arbolIz.left().empty() && arbolDr.right().empty()) || (!arbolIz.left().empty() && !arbolDr.right().empty())) {
					if ((arbolIz.right().empty() && arbolDr.left().empty()) || (!arbolIz.right().empty() && !arbolDr.left().empty()))
						return true;

					else return false;
				}
				else return false;
			}
			else return false;
		}
		else return false;*/
		if (arbolSimetrico(arbolIz.left(), arbolDr.right()) && arbolSimetrico(arbolIz.right(), arbolDr.left())) {

			return true;

		}
		else return false;
	}
	
}

void resuelveCaso() {
	bintree <char> arbol = leerArbol('.');
	bool sol = arbolSimetrico(arbol.left(),arbol.right());
	if (sol)
		std::cout << "SI "<< std::endl;
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
		resuelveCaso();// std::cin.ignore();
	}
	// Para restablecer entrada . Comentar para acepta el reto
	/*
# ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system(" PAUSE ");
# endif
	return 0;*/
}