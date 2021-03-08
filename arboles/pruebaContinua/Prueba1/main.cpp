//Pedro Llamas Do Espíritu Santo
//71710287J
#include "Arbin.h"
#include <iostream>
#include <string>

using namespace std;


/** Indica aquí, razonadamente, la complejidad de numero_adivinos
La complejidad de la funcion será del O(n) siendo n el numero de nodos (tiene un coste lineal) ya que para poder resolver el problema se deben visitar todos los nodos 
del arbol (de ello se encarga la funcion "resuelveAdivinos" la cual se llama desde "numero_adivinos". Es necesario visitarlos todos para ver si tiene
un valor par o impar y si además es un nodo adivino.
*/

int resuelveAdivinos(const Arbin<int>& a, int& numAdivinos) {
	int acumNodosPares = 0;

	if (!a.esVacio()) { //Si el arbol no es vacio
		if (!a.hijoIz().esVacio()) { //Primero los hijos izquierdos
			acumNodosPares += resuelveAdivinos(a.hijoIz(), numAdivinos);
		}

		if (!a.hijoDer().esVacio()) { //Despues los hijos derechos
			acumNodosPares += resuelveAdivinos(a.hijoDer(), numAdivinos);
		}

		if (a.raiz() == acumNodosPares) { //Comprobamos si el valor del nodo (raiz) coincide con el numero de hijos con valor par
			numAdivinos++;
		}

		if (a.raiz() % 2 == 0) { //Por ultimo aumentamos el numero de nodos pares si procede
			acumNodosPares++;
		}		
	}

	return acumNodosPares;
}

unsigned int numero_adivinos(const Arbin<int>& a) {
	// A IMPLEMENTAR
	int numAdivinos = 0;
	resuelveAdivinos(a, numAdivinos);

	return numAdivinos;

}

Arbin<int> lee_arbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<int>();
	case '[': {
		int raiz;
		in >> raiz;
  		in >> c;
		return Arbin<int>(raiz);
	}
	case '(': {
		Arbin<int> iz = lee_arbol(in);
		int raiz;
		in >> raiz;
		Arbin<int> dr = lee_arbol(in);
		in >> c;
		return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}


int main() {
	Arbin<int> arbol;
	while (cin.peek() != EOF)  {
		Arbin<int> a = lee_arbol(cin);
		cout << numero_adivinos(a) << endl;
		string resto_linea;
		getline(cin, resto_linea);
	}
	return 0;
}
