// NOMBRES Y APELLIDOS (USUARIO DEL JUEZ)
//jorge arevalo ecehvarria ---usuario:A05

#include <iostream>                                             
#include <fstream>                                             
#include <algorithm>
#include <unordered_map>
#include <vector>
#include<map>
using namespace std;

// COMENTARIO SOBRE LA SOLUCIÓN Y SU COSTE JUSTIFICADO
//el coste de cada funcion, al lado en un comentario

struct fecha {
	int dia, hora, minuto;

	bool operator<(fecha f) const {
		bool menor = false;

		if (this->dia < f.dia)
			menor = true;
		else if (this->dia == f.dia && this->hora < f.hora)
			menor = true;
		else if ((this->dia == f.dia && this->hora == f.hora) && this->minuto < f.minuto)
			menor = true;

		return menor;
	}
};

class consultorio_medico {

private:
	unordered_map<string, map<fecha,string>> citas;//tabla en la que guardamos los medicos, con otra tabla ordenada por la fechas, y de valor los pacientes
public:
	consultorio_medico() {}

	void nuevoMedico(string const& medico) {//coste O(Constante) ya que realizamos comprobacines o modificaciones en la tabla que son de coste constante 
		if (!citas.count(medico))
			citas[medico];
	}

	void pideConsulta(string const& paciente, string const& medico, fecha const& f) {//coste O(Constante) ya que realizamos comprobacines o modificaciones en la tabla que son de coste constante y ademas
									// el coste de modificar el valor del array es tambien constante
		if (!citas.count(medico)) {//O(c) miaramos si el conductor esta en la tabla
			throw std::domain_error("Medico no existente");
		}
		else {
			if (citas[medico].count(f)) {
				throw std::domain_error("Fecha ocupada");
			}
			else {
				citas[medico][f] = paciente;
			}
		}
	}

	string siguientePaciente(string const& medico) const {//coste O(Constante) ya que realizamos comprobacines o modificaciones en la tabla que son de coste constante y ademas

		if (!citas.count(medico)) {//O(c) miaramos si el conductor esta en la tabla
			throw std::domain_error("Medico no existente");
		}
		else {
			if (citas.at(medico).empty())
				throw std::domain_error("No hay pacientes");
			else {
				return citas.at(medico).begin()->second;
			}
		}
	}

	void atiendeConsulta(string const& medico) {//coste O(constante) ya que realizamos consultas de valor y comprobacion
		if (!citas.count(medico)) {//O(c) miaramos si el conductor esta en la tabla
			throw std::domain_error("Medico no existente");
		}
		else {
			if (citas.at(medico).empty())
				throw std::domain_error("No hay pacientes");
			else {
				citas[medico].erase(citas[medico].begin());
			}
		}
	}

	vector<pair<string, fecha>> listaPacientes(string medico, int dia)const {//coste O(constante) ya que delvolvemos la lista de la posicion del array
		if (!citas.count(medico)) {//O(c) miaramos si el conductor esta en la tabla
			throw std::domain_error("Medico no existente");
		}
		else {
			vector<pair<string, fecha>> lista;
			//fecha f = { dia,00,00 };
			//auto it = citas.at(medico).find(f);he intenado que el iterador comenzase a partir de ese dia, pero no me lo encontraba
			auto it = citas.at(medico).begin();
			while (it !=citas.at(medico).end()) {
				if(it->first.dia==dia)
					lista.push_back({ it->second, it->first });
				it++;
				if(it != citas.at(medico).end() && it->first.dia>dia)
					it = citas.at(medico).end();
			}
			return lista;
		}
	}
};


bool resuelveCaso() {

	int n;
	cin >> n;
	if (!cin)
		return false;

	consultorio_medico consultorio;
	string instruccion;

	for (int i = 0; i < n; i++) {

		cin >> instruccion;

		try {
			if (instruccion == "nuevoMedico") {
				string medico;
				cin >> medico;
				consultorio.nuevoMedico(medico);
			}
			else if (instruccion == "pideConsulta") {

				string paciente;
				string medico;
				char puntos;
				fecha f;
				cin >> paciente;
				cin >> medico;
				cin >> f.dia;
				cin >> f.hora;
				cin >> puntos;
				cin>> f.minuto;
				consultorio.pideConsulta(paciente, medico, f);
			}
			else if (instruccion == "siguientePaciente") {
				string medico;
				cin >> medico;
				string p = consultorio.siguientePaciente(medico);
				cout << "Siguiente paciente doctor " << medico << endl;
				cout << p << endl;
			}
			else if (instruccion == "atiendeConsulta") {
				string medico;
				cin >> medico;
				consultorio.atiendeConsulta(medico);
			}
			else if (instruccion == "listaPacientes") {
				string medico;
				cin >> medico;
				int dia;
				cin >> dia;
				vector<pair<string, fecha>> lista = consultorio.listaPacientes(medico, dia);
				cout << "Doctor " << medico << " dia " << dia << endl;
				auto it = lista.cbegin();
				while (it != lista.cend()) {
					cout << it->first << " ";
					if (it->second.hora < 10)
						cout << "0";
					cout<< it->second.hora << ":";
					if (it->second.minuto < 10)
						cout << "0";
					cout<< it->second.minuto << endl;
					it++;
				}
			}
		}
		catch (exception & e) {
			cout << e.what() << endl;
		}
		
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