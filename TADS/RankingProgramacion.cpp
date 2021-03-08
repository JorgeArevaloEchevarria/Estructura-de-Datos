#include <iostream>
#include <fstream>
#include <algorithm>
#include<vector>
#include<unordered_map>
#include<map>
#include<string>
#include<sstream>
using namespace std;
//coste : introducimos los problemas y los alumnos tiene coste lienal respecto al numero de problemas(P) enviados siendo O(P),
// ya que las operaciones del unordered_map son constantes
// ordenar el vector es de coste O(E log(E)) siendo E el numero de equipos
// con lo que se nos queda un coste de O(E log(E) + P)

struct datosProblema {
	bool resuelto = false;
	int fallos=0;
};//guarda datos del problema

struct datosEquipo {
	int problemasResueltos=0;
	int segundos=0;
	unordered_map<string, datosProblema> infoProblemas;

};//guarda datos de un equipo

struct resultado {
	string nombre;
	int num_prob_res;
	int tiempo;
	bool operator<(resultado const& r) const {
		return num_prob_res > r.num_prob_res ||
			(num_prob_res == r.num_prob_res && tiempo < r.tiempo) ||
			(num_prob_res == r.num_prob_res && tiempo == r.tiempo && nombre < r.nombre);
	}
};




void resuelveCaso() {

	unordered_map<string,datosEquipo> equipos;//tabla que nos da los datos de cada equipo

	string nombreEquipo,nombreProblema,calificacion;
	int segundos;
	
	while (cin >> nombreEquipo,nombreEquipo != "FIN") {
		cin >> nombreProblema;
		cin >> segundos;
		cin >> calificacion;

		auto & info_eq = equipos[nombreEquipo];
		auto & info_prob = info_eq.infoProblemas[nombreProblema];
		if (!info_prob.resuelto) {
			if (calificacion == "AC") {// si han aprobado se actualiza los resultados
				info_eq.problemasResueltos++;
				info_eq.segundos += (segundos + info_prob.fallos * 20);
				info_prob.resuelto = true;
			}
			else {//si es es fallo, se incrementan los fallos
				info_prob.fallos++;
			}
		}//si ya esta resuelto, lo ignoramos
	}
	vector<resultado> resultados;
	for (auto const& it : equipos) {//introducimos los resultados de los equipos en el vector
		resultados.push_back({it.first,it.second.problemasResueltos,it.second.segundos});
	}

	sort(resultados.begin(), resultados.end());//ordenamos los equipos se

	for (auto& res : resultados) {//mostramos el vector
		cout << res.nombre << " " << res.num_prob_res << " " << res.tiempo << endl;
	}
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