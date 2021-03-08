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

	if (!std::cin)
		return false;

	queue<int> cola;
	int num;
	for (int i = 0; i < n; i++) {
		std::cin >> num;
		cola.push(num);
	}

	int m,pos;
	std::cin >> m;
	std::cin >> pos;
	queue<int> colaAux;
	for (int i = 0; i < m; i++) {
		std::cin >> num;
		colaAux.push(num);
	}

	cola.insertar(colaAux, pos);
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