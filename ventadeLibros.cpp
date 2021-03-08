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
using libro = string;
using plaga = string;
const int DIVISION = 4;


struct datosSector {
	int plantas;
	map<plaga, pair<int, bool>>datosPlaga;//mapa con clave las plagas y de valor numero de plantas infectadas y bool de si ya esta en la lista para fumigar
};


class smart_farming {

private:
	unordered_map<libro,int> ejemplares;
	

public:
	smart_farming() {}

	void alta(string const& id, int const& n) {//coste

		if (sectores.count(id)) {//O(c) miaramos si el conductor esta en la tabla
			sectores[id].plantas += n;
		}
		else {
			sectores[id].plantas = n;
		}
	}

	void datos(string const& id, string const p, int const& n) {//coste 

		if (!sectores.count(id)) {//O(c) miaramos si el conductor esta en la tabla
			throw std::domain_error("Sector no existente");
		}
		else {
			if (n > sectores.at(id).plantas) {
				throw std::domain_error("Numero de plantas incorrecto");
			}
			else {
				bool cuarto = false;
				if (sectores.at(id).datosPlaga.count(p)) {
					sectores[id].datosPlaga[p].first += n;
				}
				else {
					sectores[id].datosPlaga[p].first = n;
				}

				bool fumigar = sectores[id].datosPlaga[p].second;
				if ((sectores.at(id).plantas / DIVISION) <= sectores.at(id).datosPlaga.at(p).first && !fumigar) {// si la plaga supera 1/4 de la plantacion
					listaPlagas.push_back({ id,p });
					sectores[id].datosPlaga[p].second = true;
				}
			}
		}
	}

	vector<pair<sector, plaga>> fumigar() {//coste O(log(P)) siendo p en numero de plagas, ya que el find necesita buscar por el map ordenado siendo el caso pero log(P)
		vector<pair<sector, plaga>> salida = listaPlagas;
		auto it = listaPlagas.begin();
		while (it != listaPlagas.end()) {
			auto itDatosPlaga = sectores.at(it->first).datosPlaga.find(it->second);//eliminamos la plaga del sector
			itDatosPlaga->second.first = 0;
			itDatosPlaga->second.second = false;
			it++;
		}
		listaPlagas.clear();//al fumigar eliminamos las plagas
		return salida;
	}

	map<plaga, pair<int, bool>> plagas(string const& id) const {//coste O(constante) ya que delvolvemos el mapa que tenemos en la tabla, y si devolviesemos un vector,
																//tendriamos que recorrer el map y copiar los datos en el vector
		if (sectores.count(id)) {
			return sectores.at(id).datosPlaga;
		}
		else {
			throw std::domain_error("Puntos no validos");
		}
	}
};


bool resuelveCaso() {

	string instruccion;
	cin >> instruccion;

	if (!cin)
		return false;

	smart_farming sf;

	while (instruccion != "FIN") {
		try {
			if (instruccion == "alta") {
				string s;
				cin >> s;
				int n;
				cin >> n;
				sf.alta(s, n);
			}
			else if (instruccion == "datos") {
				string s, p;
				int n;
				cin >> s;
				cin >> p;
				cin >> n;
				sf.datos(s, p, n);
			}
			else if (instruccion == "fumigar") {
				vector<pair<sector, plaga>> v = sf.fumigar();
				auto it = v.cbegin();
				while (it != v.cend()) {
					cout << "Fumigar la plaga " << it->second << " en el sector : " << it->first << endl;
					it++;
				}
			}
			else if (instruccion == "plagas") {
				string s;
				cin >> s;
				map<plaga, pair<int, bool>> salida = sf.plagas(s);
				auto it = salida.cbegin();
				cout << "Plagas del sector " << s << " : ";
				while (it != salida.cend()) {
					cout << it->first << " " << it->second.first << " ";
					it++;
				}
				cout << endl;
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