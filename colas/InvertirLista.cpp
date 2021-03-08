// Nombre del alumno .....Jorge Arevalo Ecehvarria
// Usuario del Juez ......A05


#include <iostream>
#include <iomanip>
#include <fstream>
#include"deque_eda.h"


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
	int num;
	deque<int> cola;
	std::cin >> num;

	if (!std::cin)
		return false;

	while (num != 0) {
		cola.push_back(num);
		std::cin >> num;
	}

	cola.invertir();
	// escribir sol
	cola.mostrar();
	return true;

}

int main() {

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