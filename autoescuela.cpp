// NOMBRES Y APELLIDOS (USUARIO DEL JUEZ)
//jorge arevalo ecehvarria ---usuario:A05

#include <iostream>                                             
#include <fstream>                                             
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

// COMENTARIO SOBRE LA SOLUCIÓN Y SU COSTE JUSTIFICADO
//el coste de cada funcion, al lado en un comentario

class autoescuela {

	using alumno = string;
	using profesor = string;

private:
	unordered_map<alumno, pair<int,profesor>> alumnos;//tabla en la que guardamos los dni, con los puntos asignados a cada dni,
	//y el iterador de la poscion que ocupa dentro de los puntos que tenga asociados en listaDni
	//el iterador lo utilizamos para poder elminiar de listaDni con coste constante
	unordered_map<profesor, set<alumno>> profesores;
	
public:
	autoescuela() {}

	void alta(alumno const& a, profesor p) {//coste O(Constante) ya que realizamos comprobacines o modificaciones en la tabla que son de coste constante y ademas
		
		if (!alumnos.count(a)) {
			alumnos[a].second = p;
			alumnos[a].first = 0;
		} 
		else {
			
			profesores[alumnos.at(a).second].erase(a);
			profesores[p].insert(a);
			alumnos[a].second = p;
		}
	}

	bool es_alumno(alumno a, profesor p) {
		if (alumnos.at(a).second == p)
			return true;
		else
			return false;
	}

	int puntuacion(alumno const& a ) {//coste O(Constante) ya que realizamos comprobacines o modificaciones en la tabla que son de coste constante y ademas
		if (!alumnos.count(a)) {
			throw std::domain_error("El alumno " + a+ " no esta matriculado");
		}
		else {
			return alumnos.at(a).first;
		}
	}

	void actulizar(alumno const& a,int const& n){//coste O(constante) ya que realizamos consultas de valor y comprobacion
		if (!alumnos.count(a)) {
			throw std::domain_error("El alumno " + a + " no esta matriculado");
		}
		else {
			alumnos[a].first += n;
		}
	}

	int cuantos_con_puntos(int const& p) const {//coste O(constante) ya que delvolvemos el valor de la posicion del array
		if (MIN_PUNTOS <= p && p <= MAX_PUNTOS) {//comprobamos si los puntos son validos
			return listaPuntos[p];
		}
		else {
			throw std::domain_error("Puntos no validos");
		}
	}

	list<string> lista_por_puntos(int p) {//coste O(constante) ya que delvolvemos la lista de la posicion del array
		if (MIN_PUNTOS <= p && p <= MAX_PUNTOS) {//comprobamos si los puntos son validos
			return listaDni[p];
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

	carnet_puntos dgt;

	while (instruccion != "FIN") {
		try {
			if (instruccion == "nuevo") {
				string dni;
				cin >> dni;
				dgt.nuevo(dni);
			}
			else if (instruccion == "quitar") {
				string dni;
				int p;
				cin >> dni;
				cin >> p;
				dgt.quitar(dni, p);
			}
			else if (instruccion == "recuperar") {
				string dni;
				int p;
				cin >> dni;
				cin >> p;
				dgt.recuperar(dni, p);
			}
			else if (instruccion == "consultar") {
				string dni;
				cin >> dni;
				int n = dgt.consultar(dni);
				cout << "Puntos de " << dni << ": " << n << endl;
			}
			else if (instruccion == "cuantos_con_puntos") {
				int p;
				cin >> p;
				int n = dgt.cuantos_con_puntos(p);
				cout << "Con " << p << " puntos hay " << n << endl;;
			}
			else if (instruccion == "lista_por_puntos") {
				int p;
				cin >> p;
				list<string> lista = dgt.lista_por_puntos(p);
				cout << "Tienen " << p << " puntos:";
				auto it = lista.cbegin();
				while (it != lista.cend()) {
					cout << " " << *it;
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