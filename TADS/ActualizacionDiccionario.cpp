#include <iostream>
#include <fstream>
#include <algorithm>
#include<vector>
#include<unordered_map>
#include<map>
#include<string>
#include<sstream>
using namespace std;
//coste : introducimos todas las palabras en los diccionarios teniendo un coste n , siendo n el numero de palabras,
//y ya que cada palabra la insertamos tenemos un coste  de O(n log(n))
// despues recorremos los dos diccionarios con los iteradores siendo el coste  el numero de palabras n
//y con la inserccion en los vectores que es constante O(n)
//con lo que se nos queda un coste O(n log(n) + n) 

void resuelveCaso() {

	map<string, string> diccAntiguo;
	map<string, string> diccNuevo;
	vector<string> cambios;
	vector<string> altas;
	vector<string> bajas;
	
	string cadenaClave;
	string cadenaValor;
	string linea1,linea2;

	getline(cin, linea1);//leemos la primera linea que pertenece al diccionario antiguo
	stringstream lin1(linea1);

	while (lin1>> cadenaClave) {//Introducimos los valores en el diccionario antiguo
		lin1 >> cadenaValor;
		diccAntiguo[cadenaClave] = cadenaValor;// añadimos al diccionario con coste(log(n)) siendo n el numero de palabras
	}

	//cin.ignore();

	getline(cin, linea2);//leemos la segunda linea que pertenece al diccionario nuevo
	stringstream lin2(linea2);

	while (lin2 >> cadenaClave) {//introducimos los valores en el diccionario nuevo
		lin2 >> cadenaValor;
		diccNuevo[cadenaClave] = cadenaValor;// añadimos al diccionario con coste(log(n)) siendo n el numero de palabras
	}

	auto itAntiguo = diccAntiguo.begin();
	auto itNuevo = diccNuevo.begin();

	while (itAntiguo != diccAntiguo.end() && itNuevo != diccNuevo.end()) {//miramos que no hayamos recorrido hasta el final ningun diccionario
		if (itAntiguo->first < itNuevo->first) {//como esta ordenado si es menor, es que no esta en el nuevo
			bajas.push_back(itAntiguo->first);//actualizamos bajas
			itAntiguo++;//avanzamos en el antiguo 
		}
		else if (itAntiguo->first > itNuevo->first) {//si es mayor , no esta en el antiguo
			altas.push_back(itNuevo->first);//actualizamos altas
			itNuevo++;//avanzamos el nuevo
		}
		else {//esta en el diccionario nuevo y antiguo
			if (itAntiguo->second != itNuevo->second)//miramos si se ha modificado la variable
				cambios.push_back(itNuevo->first);//actualizamos cambios de variable
			itAntiguo++;//avanzamos los dos iteradores
			itNuevo++;
		}
	}

	while (itAntiguo != diccAntiguo.end()) {//comprobamos si ha acabado el iterador antiguo
		bajas.push_back(itAntiguo->first);//por lo que el iterador nuevo habra acabado y todo seran bajas
		itAntiguo++;
	}

	while (itNuevo != diccNuevo.end()) {//comprobamos si ha acabado el iterador nuevo
		altas.push_back(itNuevo->first);//por lo que el iterador antiguo habra acabado y todo son altas
		itNuevo++;
	}

	if (!altas.empty()) {// mostramos los vectores de altas bajas y cambios
		cout << "+ ";
			for (int i = 0; i < altas.size(); i++) {
				cout << altas[i] << " ";
			}
		cout << std::endl;
	}
	if (!bajas.empty()) {
		cout << "- ";
		for (int i = 0; i < bajas.size(); i++) {
			cout << bajas[i] << " ";
		}
		cout << std::endl;
	}
	if (!cambios.empty()) {
		cout << "* ";
		for (int i = 0; i < cambios.size(); i++) {
			cout << cambios[i] << " ";
		}
		cout << std::endl;
	}

	if (altas.empty() && bajas.empty() && cambios.empty())
		cout << "Sin cambios" << endl;

	cout << "---" << endl;
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
	 /*
 #ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
 #endif*/

	int numCasos;
	cin >> numCasos;
	cin.ignore();
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

	// para dejar todo como estaba al principio
	/*
 #ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
 #endif
 */
	return 0;
}
