#include <iostream>
#include <fstream>
#include <algorithm>
#include<vector>
#include<unordered_map>
#include<map>
#include<string>
#include<sstream>
using namespace std;
// coste O(P log(P)) siendo P el numero de palabras del texto ya que en el caso peor
//veremos todas las palabras del texto( que seria lineal segun el numero de palabras  O(P)),
// y por cada palabra haremos accesos al diccionario que seran de coste O(log(P))

void resuelveCaso() {

	int nLineas;
	std::cin >> nLineas;
	while (nLineas != 0) {
		map<string, vector<int>> referencias;
		string linea, palabra;
		std::cin.ignore();
		for (int i = 1; i <= nLineas; i++) {//el numero de lineas no afecta al coste, ya que accedemos al diccionario por cada palabra
			std::getline(std::cin, linea);
			std::stringstream lin(linea);
			while (lin >> palabra) {//lee palabra a palabra de la linea
				if (palabra.length() > 2) {

					for (char & c :palabra)
						c = tolower(c);

					std::vector<int>& apareciones = referencias[palabra];// por cada palabra hacemos un acceso al diccionario O(log P)
					if (apareciones.empty() || apareciones.back() != i)
						apareciones.push_back(i);//modificacion del vector de coste constante
				}
			}
		}

		for (auto it : referencias) {
			std::cout << it.first << " ";
			for (int i = 0; i < it.second.size(); i++) {
				std::cout << it.second[i] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << "---" << std::endl;
		std::cin >> nLineas;

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
	/*
 #ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
 #endif
 */
	return 0;
}
