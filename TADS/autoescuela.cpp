// NOMBRES Y APELLIDOS (USUARIO DEL JUEZ)
//jorge arevalo ecehvarria ---usuario:A05

#include <iostream>                                             
#include <fstream>                                             
#include <algorithm>
#include <unordered_map>
#include <list>
using namespace std;

// COMENTARIO SOBRE LA SOLUCIÓN Y SU COSTE JUSTIFICADO
//el coste de cada funcion, al lado en un comentario

class autoescuela {

private:
	unordered_map<string, pair<int, std::list<string>::iterator>> puntos;//tabla en la que guardamos los dni, con los puntos asignados a cada dni,
	//y el iterador de la poscion que ocupa dentro de los puntos que tenga asociados en listaDni
	//el iterador lo utilizamos para poder elminiar de listaDni con coste constante
	int  listaPuntos[POSICIONES] = { 0 };//utilizamos la posicion para el numero de puntos, y el valor para saber el numero de conductores con esos puntos
	list<string> listaDni[POSICIONES];//utilizamos la posicion para el numero de puntos, y el valor para saber los dnis con esos puntos
public:
	carnet_puntos() {}

	void nuevo(string const& dni) {//coste O(Constante) ya que realizamos comprobacines o modificaciones en la tabla que son de coste constante y ademas
									// el coste de modificar el valor del array es tambien constante

		if (puntos.count(dni)) {//O(c) miaramos si el conductor esta en la tabla
			throw std::domain_error("Conductor duplicado");
		}
		else {
			puntos[dni].first = MAX_PUNTOS;//O(c) // inicializamos el nuevo conductor
			listaPuntos[MAX_PUNTOS]++;//O(c) 
			listaDni[MAX_PUNTOS].push_front(dni);
			puntos[dni].second = listaDni[MAX_PUNTOS].begin();// inicializamos dando el iterador de la poscion que ocupa en la lista
		}
	}

	void quitar(string const& dni, int const& p) {//coste O(Constante) ya que realizamos comprobacines o modificaciones en la tabla que son de coste constante y ademas
									// el coste de modificar el valor del array es tambien constante
		if (!puntos.count(dni)) {//O(c) miaramos si el conductor esta en la tabla
			throw std::domain_error("Conductor inexistente");
		}
		else {
			int puntosAntes = puntos[dni].first;
			if (puntosAntes != 0) {
				int puntosAc = std::max(MIN_PUNTOS, puntos[dni].first - p);//nos aseguramos de que no tenga puntos menores a 0
				listaPuntos[puntosAntes]--;//actualizamos la lista y la tabla con los nuevos puntos
				listaDni[puntosAntes].erase(puntos[dni].second);
				puntos[dni].first = puntosAc;
				listaDni[puntosAc].push_front(dni);
				puntos[dni].second = listaDni[puntosAc].begin();
				listaPuntos[puntosAc]++;
			}
		}
	}

	void recuperar(string const& dni, int const& p) {//coste O(Constante) ya que realizamos comprobacines o modificaciones en la tabla que son de coste constante y ademas
									// el coste de modificar el valor del array es tambien constante
		if (!puntos.count(dni)) {//O(c) miaramos si el conductor esta en la tabla
			throw std::domain_error("Conductor inexistente");
		}
		else {
			int puntosAntes = puntos[dni].first;
			if (puntosAntes != 15) {
				int puntosAc = std::min(MAX_PUNTOS, puntos[dni].first + p);//nos aseguramos de que no tenga puntos menores a 0
				listaPuntos[puntosAntes]--;//actualizamos la lista y la tabla con los nuevos puntos con costes constantes
				listaDni[puntosAntes].erase(puntos[dni].second);
				puntos[dni].first = puntosAc;
				listaDni[puntosAc].push_front(dni);
				puntos[dni].second = listaDni[puntosAc].begin();
				listaPuntos[puntosAc]++;
			}
		}
	}

	int consultar(string const& dni)const {//coste O(constante) ya que realizamos consultas de valor y comprobacion
		if (!puntos.count(dni)) {//O(c) comprobamos si esta en la tabla
			throw std::domain_error("Conductor inexistente");
		}
		else {
			return puntos.at(dni).first;// si esta  pedimos el valor O(c)
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