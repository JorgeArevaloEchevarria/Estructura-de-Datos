
// NOMBRE Y APELLIDOS 
//Jorge Arevalo Echevarria
// COMENTARIO SOBRE LA SOLUCIÓN
// NO OLVIDES PONER EL COSTE JUSTIFICADO DE CADA OPERACIÓN JUNTO A ELLA

#ifndef OFICINAEMPLEO
#define OFICINAEMPLEO

#include <iostream>               
#include <string>
#include <stdexcept>
#include <algorithm>
#include<unordered_map>
#include<deque>
#include<set>
using namespace std;

class oficinaEmpleo {

	unordered_map<string, deque<string>> empleos;//mapa desordenado de empleo, de clave el empleo y de valor una doble cola de personas, para mostrar por antiguedad
	unordered_map<string, set<string>> personas;//mapa desordenado de personas con los posibles empleos disponibles
   
public:
  
	void altaOficina(string nombre, string empleo) {//tenemos O(log n) siendo n el numero de elementos del set, ya que insertamos en el, y el coste del resto de operaciones del unordered map es cosntante
		if (!personas[nombre].count(empleo)) {
			empleos[empleo].push_back(nombre);//metemos al final, para guardar eñl orden de antiguedad, luego sacamos por el principio
			personas[nombre].insert(empleo);//añadimos el empleo a la persona
		}
		/*
		if(!empleos.count(empleo))
			empleos[empleo];

		if (personas.count(nombre)) {
			if (personas.at(nombre).empty())
				if (personas.at(nombre).count(empleo))
					personas[nombre].insert(empleo);
		}
		else {
			personas[nombre].insert(empleo);
		}
		*/
	}

	string ofertaEmpleo(string empleo) {////tenemos coste o(n) siendo n los elementos del set,
		if (empleos.at(empleo).empty()) {//miramos si hay gente para el empleo
			throw std::domain_error("No existen personas apuntadas a este empleo");
		}
		else {
			string persona = empleos.at(empleo).front();//miramos la personas mas antigua para el empleo
			empleos[empleo].pop_front();//lo sacamos
			personas[persona].erase(empleo);//eliminamos la oferta para esa persona
			if (empleos.at(empleo).empty())//comprobamos si hay mas personas para ese empleo
				empleos.erase(empleo);//eliminamos el empleo
			return persona;
		}
	}

	set<string> listadoEmpleos(string persona) {// coste constante ya que solo devolvemos el set 
		if (!personas.count(persona)) {
			throw std::domain_error("Persona inexistente");
		}
		else {
			return personas.at(persona);
		}
	}
};



#endif
