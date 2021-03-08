//Jorge Arevalo Echevarria
// NOMBRES Y APELLIDOS

#include <iostream>
#include <fstream>
#include <algorithm>
#include<vector>
#include<unordered_map>
#include<string>
#include<set>
using namespace std;
// coste el rellenar las tablas tiene coste lineal respecto el numero de deportes, y el numero de alumnos ->O(D+A)
//ya que las operaciones en los unordered_map son de coste constante
//y el ordenar del vector es de coste O(D log D) 
//con lo que el coste total seria O((D log D) + A)


bool resuelveCaso() {
	unordered_map<string, set<string>> deportes;
	unordered_map<string, string> estudiantes;
	string alumno;
	string deporte;
	cin >> alumno;
	if (!cin)
		return false;


	while (alumno != "_FIN_") {
		if (isupper(alumno[0])) {//estoy agregando un deporte
			deporte = alumno;
			deportes[deporte];//operaciones de coste constante
		}
		else {//estoy agregando un alumno
			if (estudiantes.count(alumno)) {//si el alumno ya estaba
				if (estudiantes[alumno] != deporte) {//operaciones de coste constante
					string deporteBorrar = estudiantes[alumno];//se mira en que deporte estaba apauntado
					deportes[deporteBorrar].erase(alumno);//y eliminamos al alumno de ese deporte
				}
			}
			else {//si el alumno es nuevo
				estudiantes[alumno] = deporte;
				deportes[deporte].insert(alumno);
			}
		}
		cin >> alumno;
	}
	//vector en el que mostraremos la salida
	vector<pair<string, int>> resumen;
	for (auto it : deportes) {
		resumen.push_back({ it.first,it.second.size() });
	}
	sort(resumen.begin(), resumen.end(), [](pair<string, int>const & a, pair<string, int>const & b) {
		return (a.second > b.second || a.second == b.second && a.first < b.first);	
	});
	for (auto& par : resumen)
		cout << par.first << " " << par.second << endl;
	cout << "---" << endl;
	return true;
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
	 /*
 #ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
 #endif*/

	while(resuelveCaso());
	

	// para dejar todo como estaba al principio
	/*
 #ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
 #endif
 */
	return 0;
}