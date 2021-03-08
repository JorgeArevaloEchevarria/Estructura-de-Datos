// Nombre del alumno .....Jorge Arevalo Ecehvarria
// Usuario del Juez ......A05


#include <iostream>
#include <iomanip>
#include <fstream>
#include"queue_eda.h"

/*// función que resuelve el problema
queue<int> resolver(queue<int> cola) {
	queue<int> colaSol;
	int n = cola.size();
	while(!cola.empty()) {
		int aux = cola.front();
		colaSol.push(aux);
		colaSol.push(aux);
		cola.pop();
	}
	return colaSol;
}*/

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	//if (caso especial)
		//return false;
	int n;
	std::cin >> n;
	while (n > 0) {
		int num,num2;
		queue<int> cola1,cola2;
		std::cin >> num;
		while (num != 0) {
			cola1.push(num);
			std::cin >> num;
		}
		std::cin >> num2;
		while (num2 != 0) {
			cola2.push(num2);
			std::cin >> num2;
		}
		cola1.mezclar(cola2);
		// escribir sol
		cola1.mostrar();
		n--;
	}
	return true;

}

int main() {
	/*
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif*/


	while (resuelveCaso())
		;
	/*
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif*/

	return 0;
}