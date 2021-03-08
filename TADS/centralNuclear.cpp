#include <iostream>
#include <fstream>
#include <algorithm>
#include<vector>
#include<unordered_map>
#include<map>
#include<string>
#include<sstream>
using namespace std;
//coste : introducimos los envios y las consultas tiene coste lienal respecto al numero de envios(E) y consultas(C) siendo O(E+C),
// ya que las operaciones del unordered_map son constantes
//ya que las consultas despues las introducimos en el vector y para mostrarlas el coste seria O(E+2C), es decir O(E+C)

bool resuelveCaso() {
	
	unordered_map<string, vector<string>> envios;

	int N, M;
	cin >> N;
	if (!cin)
		return false;

	cin >> M;

	for (int i = 0; i < N; i++) {//introudcimos los envios en nuestro diccionario
		string tipo, hora;
		cin >> tipo;
		cin >> hora;
		envios[tipo].push_back(hora);//coste constante
	}
	vector<pair<string, int>> salida;//creamos un vector para la salida
	string tipoConsulta;
	int numEnvio;
	
	for (int i = 0; i < M; i++) {//guardamos la salida en un vector para mostrarla en una linea
		cin >> tipoConsulta;
		cin >> numEnvio;
		salida.push_back({ tipoConsulta,numEnvio });
	}
	
	for (auto it : salida){//mostramos la salida segun el vector
		if (envios[it.first].size() < it.second) {//miramos si el numero de envio es valido
			cout << "-- ";
		}
		else {
			cout << envios[it.first].at(it.second-1)<<" ";//sino mostramos el envio
		}
	}
	cout << endl;
	return true;
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
 #ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
 #endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
 #ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
 #endif
 
	return 0;
}