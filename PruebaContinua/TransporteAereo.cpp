// NOMBRES Y APELLIDOS (USUARIO DEL JUEZ)
//jorge arevalo ecehvarria ---usuario:A05

#include <iostream>                                             
#include <fstream>                                             
#include <algorithm>
#include <unordered_map>
#include<map>
#include <vector>
using namespace std;

// COMENTARIO SOBRE LA SOLUCIÓN Y SU COSTE JUSTIFICADO
//el coste de cada funcion, al lado en un comentario
using id_nave = string;
using id_modulo = string;



class transporte_aereo {

private:
	unordered_map<id_nave, map<id_modulo,int>> naves;
	vector<id_nave> navesDefectuosas;

public:
	transporte_aereo() {}

	void alta(string const& nave) {//coste costante

		if (naves.count(nave)) {//O(c) miaramos si el conductor esta en la tabla
			throw std::domain_error("Nave Repetida");
		}
		else {
			naves[nave];//O(C)
		}
	}

	void mantenimineto(string const& nave, string const modulo, int const& f) {//coste en el caso peor insertamos en el map siendo coste O(logM) siendo m los modulos

		if (!naves.count(nave)) {//O(c) miaramos si el conductor esta en la tabla
			throw std::domain_error("Nave desconocida");
		}
		else {
			if (naves.at(nave).count(modulo)) {
				naves[nave][modulo] += f;//si esta añadimos el valor
			}
			else {
				naves[nave][modulo] = f;//y si no esta lo incializamos con ese valor
			}
		}
	}

	void estropear(string const& nave, string const modulo) {//coste en el caso peor insertamos en el map siendo coste O(logM) siendo m los modulos

		if (!naves.count(nave)) {//O(c) miaramos si el conductor esta en la tabla
			throw std::domain_error("Nave desconocida");
		}
		else {
			if (!naves.at(nave).count(modulo)) {
				throw std::domain_error("el modulo no pertenece a esa nave");
			}
			else {
				if (naves[nave][modulo] > 0)
					naves[nave][modulo]--;//coste O(log M) ya que tiene que buscar ese modulo en el map

				if (naves.at(nave).at(modulo) == 0)//aqui mirar tambien con el bool
					navesDefectuosas.push_back(nave);

			}
		}
	}

	vector<string> defectuosas() {//no me ha dado tiempo pero para evitar la repeticion tenia pensado implementar un bool que me diga si ya tengo la nave en la lista
		return navesDefectuosas;
	}




	map<id_modulo, int> modulos(string const& nave) const {//coste O(constante) ya que delvolvemos el mapa que tenemos en la tabla, y si devolviesemos un vector,
														//tendriamos que recorrer el map y copiar los datos en el vector
		return naves.at(nave);
	}
};


bool resuelveCaso() {

	string instruccion;
	cin >> instruccion;

	if (!cin)
		return false;

	transporte_aereo ta;

	while (instruccion != "FIN") {
		try {
			if (instruccion == "alta") {
				string n;
				cin >> n;
				ta.alta(n);
			}
			else if (instruccion == "mantenimiento") {
				string n, m;
				int f;
				cin >> n;
				cin >> m;
				cin >> f;
				ta.mantenimineto(n, m, f);
			}
			else if (instruccion == "estropear") {
				string n, m;
				cin >> n;
				cin >> m;
				ta.estropear(n, m);
			}
			else if (instruccion == "modulos") {
				string n;
				cin >> n;
				map<id_modulo, int> salida = ta.modulos(n);
				auto it = salida.cbegin();
				cout << "Modulos de la nave " << n << " : ";
				while (it != salida.cend()) {
					cout << it->first << " ";
					it++;
				}
				cout << endl;
			}
			else if (instruccion == "defectuosas") {
				string n;
				cin >> n;
				ta.defectuosas();// y muestro por pantalla
			}
		}
		catch (exception & e) {
			cout << "ERROR: " << e.what() << endl;
		}
		cin >> instruccion;
	}

	cout << "---" << endl;

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