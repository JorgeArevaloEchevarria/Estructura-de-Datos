#include<iostream>
#include"bintree_eda.h"
struct tSol {
	int multiplo7;
	int profundidad;
};

bool esPrimo(int num) {
	int divisor = 1, divisores = 0;
	do {
		if (num % divisor == 0) {
			divisores++;
		}
		divisor++;
	} while (divisor <= num);
	if (divisores == 2) 
		return true;
	else 
		return false;
}


template <class T >
tSol barreraPrimos(bintree <T > const& arbol) { // O(N)

	if (arbol.empty()) {
		return { 0,0 };
	}
	else {

		tSol iz = barreraPrimos(arbol.left());
		tSol dr = barreraPrimos(arbol.right());

		if (arbol.root() % 7 == 0 && arbol.root()!=7)//multiplos de 7, sin contar el 7
			return{ arbol.root(),1 };
		else if (esPrimo(arbol.root()))
			return{ 0,0 };
		else {
			if (iz.multiplo7 == 0)
				return {dr.multiplo7,dr.profundidad+1};
			else if (dr.multiplo7 == 0)
				return { iz.multiplo7,iz.profundidad + 1 };
			else {
				if (iz.profundidad > dr.profundidad)
					return { dr.multiplo7,dr.profundidad + 1 };
				else
					return { iz.multiplo7,iz.profundidad + 1 };
			}
		}
	}
}

void resuelveCaso() {
	bintree <int> arbol = leerArbol(-1);
	tSol sol = barreraPrimos(arbol);
	if (sol.multiplo7 != 0)
		std::cout << sol.multiplo7 << " " << sol.profundidad << std::endl;
	else
		std::cout << "NO HAY" << std::endl;
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
		resuelveCaso();
	}
	// Para restablecer entrada . Comentar para acepta el reto
	/*
# ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system(" PAUSE ");
# endif
	return 0;*/
}