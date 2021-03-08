

#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include <algorithm>
#include<stack>



 struct vuelo {
	int dia;
	int mes;
	int anio;
	int victimas;
};

// función que resuelve el problema
void resolver(std::stack<vuelo> &vuelos) {

		
		bool encontrado = false;

		vuelo vueloActual = vuelos.top();
		vuelos.pop();

		while (!vuelos.empty() && !encontrado) {
			vuelo vueloAux = vuelos.top();
			if (vueloActual.victimas < vueloAux.victimas) {
				std::cout << std::setfill('0') << std::setw(2);
				std::cout << vueloAux.dia << "/";
				std::cout << std::setfill('0') << std::setw(2);
				std::cout << vueloAux.mes << "/";
				std::cout << vueloAux.anio << std::endl;
				encontrado = true;
				vuelos.push(vueloActual);
			}
			else {
				vuelos.pop();
			}
		}

		if (!encontrado) {
			std::cout << "NO HAY" << std::endl;
			vuelos.push(vueloActual);
		}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int k;
	std::stack<vuelo> vuelos;

	std::cin >> k;

	if (!std::cin)
		return false;

	for (int i = 0; i < k; i++) {
		vuelo v;
		char barra;
		
		std::cin >> v.dia;
		std::cin >> barra;
		std::cin >> v.mes;
		std::cin >> barra;
		std::cin >> v.anio;

		std::cin >> v.victimas;
		vuelos.push(v);

		resolver(vuelos);

	}
	std::cout << "---" << std::endl;
	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}