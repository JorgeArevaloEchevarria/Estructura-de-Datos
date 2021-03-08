// NOMBRES Y APELLIDOS (USUARIO DEL JUEZ)
//jorge arevalo ecehvarria ---usuario:A05

#include <iostream>                                             
#include <fstream>                                             
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

// COMENTARIO SOBRE LA SOLUCIÓN Y SU COSTE JUSTIFICADO
//el coste de cada funcion, al lado en un comentario
const int POSICIONES = 16;// de 0-15 posibles puntos en el carnet
const int MAX_PUNTOS = 15;
const int MIN_PUNTOS = 0;

class carnet_puntos {

	private :
		unordered_map<string,int> puntos;//<dni,puntos> tabla en la que guardamos los dni y los puntos asignados a cada dni
		int  listaPuntos[POSICIONES] = {0};//utilizamos la posicion para el numero de puntos, y el valor para saber el numero de conductores con esos puntos
	public:
		carnet_puntos() {}

		void nuevo(string const &dni) {//coste O(Constante) ya que realizamos comprobacines o modificaciones en la tabla que son de coste constante y ademas
										// el coste de modificar el valor del array es tambien constante

			if (puntos.count(dni)) {//O(c) miaramos si el conductor esta en la tabla
				throw std::domain_error("Conductor duplicado");
			}
			else {
				puntos[dni] = MAX_PUNTOS;//O(c) // inicializamos el nuevo conductor
				listaPuntos[MAX_PUNTOS]++;//(c)
			}
		}

		void quitar(string const &dni, int const &p) {//coste O(Constante) ya que realizamos comprobacines o modificaciones en la tabla que son de coste constante y ademas
										// el coste de modificar el valor del array es tambien constante
			if (!puntos.count(dni)) {//O(c) miaramos si el conductor esta en la tabla
				throw std::domain_error("Conductor inexistente");
			}
			else {
				int puntosAc = std::max( MIN_PUNTOS, puntos[dni] - p);//nos aseguramos de que no tenga puntos menores a 0
				listaPuntos[puntos.at(dni)]--;//actualizamos la lista y la tabla con los nuevos puntos
				puntos[dni] = puntosAc;
				listaPuntos[puntosAc]++;
			}
		}

		int consultar(string const &dni)const {//coste O(constante) ya que realizamos consultas de valor y comprobacion
			if (!puntos.count(dni)) {//O(c) comprobamos si esta en la tabla
				throw std::domain_error("Conductor inexistente");
			}
			else{
				return puntos.at(dni);// si esta  pedimos el valor O(c)
			}
		}

		int cuantos_con_puntos(int const &p) const{//coste O(constante) ya que delvolvemos el valor de la posicion del array
			if( MIN_PUNTOS <= p && p <= MAX_PUNTOS){//comprobamos si los puntos son validos
				return listaPuntos[p];
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
		}
		catch (exception &e) {
			cout << "ERROR: " << e.what()<<endl;
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