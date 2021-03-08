
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <string>


// función que resuelve el problema
bool resolver(std::string const& expresion) {
	std::stack<char> pila;

	for (char c : expresion) {
		if (c == '(' || c == '[' || c == '{') {
			pila.push(c);
		}
		if (c == ')') {
			if (!pila.empty()) {
				if (pila.top() == '(') {
					pila.pop();
				}
				else return false;
			}
			else return false;

		}
		else if (c == ']') {
			if (!pila.empty()) {
				if (pila.top() == '[') {
					pila.pop();
				}
				else return false;
			}
			else return false;

		}
		else if (c == '}') {
			if (!pila.empty()) {
				if (pila.top() == '{') {
					pila.pop();
				}
				else return false;
			}
			else return false;

		}
	}
	return pila.empty();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	std::string expresion;
	getline(std::cin, expresion);

	if (!std::cin)
		return false;

	if (resolver(expresion)) {
		std::cout << "SI" << std::endl;
	}
	else std::cout << "NO" << std::endl;


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}