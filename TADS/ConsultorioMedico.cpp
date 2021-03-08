// NOMBRES Y APELLIDOS (USUARIO DEL JUEZ)
//jorge arevalo ecehvarria ---usuario:A05

#include <iostream>                                             
#include <fstream>                                             
#include <algorithm>
#include <unordered_map>
#include <list>
#include<map>
using namespace std;

// COMENTARIO SOBRE LA SOLUCIÓN Y SU COSTE JUSTIFICADO
//el coste de cada funcion, al lado en un comentario

class Fecha {
private:
	int dia, hora, minuto;
public:

	Fecha(int d, int h, int m) {
		dia = d;
		hora = h;
		minuto = m;
	}

	int getDia() {
		return dia;
	}

	int getHora() {
		return hora;
	}

	int getMinuto() {
		return minuto;
	}

	bool operator<(Fecha f) const {
		bool menor = false;

		if (this->dia < f.getDia())
			menor = true;
		else if (this->dia == f.getDia() && this->hora < f.getHora())
			menor = true;
		else if ((this->dia == f.getDia() && this->hora == f.getHora()) && this->minuto < f.getMinuto())
			menor = true;

		return menor;
	}

	bool operator==(Fecha f) const {
		return ((this->dia == f.getDia()) && (this->hora == f.getHora()) && (this->minuto == f.getMinuto()));
	}
};

class consultorio_medico {

private:
	unordered_map<string,map<Fecha,string>> citas;//tabla en la que guardamos los medicos, con otra tabla ordenada por la fechas, y de valor los pacientes
public:
	consultorio_medico() {}

	void nuevoMedico(string const& medico) {//coste O(Constante) ya que realizamos comprobacines o modificaciones en la tabla que son de coste constante 
		if (!citas.count(medico))
			citas[medico];
	}

	void pideConsulta(string const& paciente, string const& medico, Fecha const& f) {//coste O(Constante) ya que realizamos comprobacines o modificaciones en la tabla que son de coste constante y ademas
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

	string siguientePaciente(string const& medico) const{//coste O(Constante) ya que realizamos comprobacines o modificaciones en la tabla que son de coste constante y ademas
								
		if (!citas.count(medico)) {//O(c) miaramos si el conductor esta en la tabla
			throw std::domain_error("Medico no existente");
		}
		else {
			if(citas.at(medico).empty())
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

	vector<pair<string,Fecha>> listaPacientes(string medico,int dia)const {//coste O(constante) ya que delvolvemos la lista de la posicion del array
		if (!citas.count(medico)) {//O(c) miaramos si el conductor esta en la tabla
			throw std::domain_error("Medico no existente");
		}
		else {
			vector<pair<string, Fecha>> lista;
			Fecha f = Fecha(dia,00,00);
			auto it = citas.at(medico).find(f);
			Fecha fp= it->first;

			while (fp.getDia() == dia) {
				lista.push_back({ it->second, it->first });
				it++;
				fp = it->first;
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
					int dia, hora, min;
					string puntos;
					cin >> paciente;
					cin >> medico;
					cin >> dia;
					cin >> hora >> puntos >> min;
					Fecha f = Fecha(dia, hora, min);
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
					vector<pair<string, Fecha>> lista = consultorio.listaPacientes(medico, dia);
					cout << "Doctor " << medico << " dia " << dia << endl;
					auto it = lista.cbegin();
					Fecha fp=it->second;
					while (it != lista.cend()) {
						cout << it->first << " " << fp.getHora() << ":" << fp.getMinuto() << endl;
						it++;
						fp = it->second;
					}
				}
			}
			catch (exception & e) {
				cout << "ERROR: " << e.what() << endl;
			}

		cout << "---" << endl;
	}

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