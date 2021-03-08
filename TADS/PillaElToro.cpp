//Jorge Arevalo Echevarria
// NOMBRES Y APELLIDOS

#include <iostream>
#include <fstream>
#include <algorithm>
#include<vector>
#include<map>
#include<string>
using namespace std;

//O(P log(P)), con P el numero de palabras del texto
//acceso por cada palabra al diccionario de coste O(log P)
//Modificacion del vector de coste Constante

void resuelveCaso() {

	int N;
	cin >> N;
	while (N != 0) {
		cin.ignore();//para quitar el salto de linea detras de N
		map<string, int> ejercicios;//para cada palabra, el vector de lineas donde aparece

		//leemos el texto
		std::string nombre,puntuacion;
		for (int i = 0; i < N; i++) {
			getline(cin, nombre);
			cin >> puntuacion;
			if (!ejercicios.count(nombre))
				ejercicios[nombre] = 0;
			if (puntuacion == "CORRECTO")
				ejercicios[nombre]++;
			else
				ejercicios[nombre]--;
			cin.ignore();//para quitar el salto de linea detras de N
		}
		//mostrar referencias
		for (auto cv : ejercicios) {//recorre las palabras en el texto
			if (cv.second != 0) {
				cout << cv.first << ", ";
				cout << cv.second;
				cout << "\n";
			}
		}
		cout << "---\n";
		cin >> N;
	}

}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
	/*
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif*/

		resuelveCaso();

	// para dejar todo como estaba al principio
/*#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif*/
	return 0;
}