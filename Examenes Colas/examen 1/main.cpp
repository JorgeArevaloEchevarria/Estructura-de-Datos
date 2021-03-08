
// NOMBRES Y APELLIDOS (USUARIO DEL JUEZ)

// COMENTARIO SOBRE LA SOLUCIÓN Y SU COSTE 
//el coste es O(min(N,M)) ya que recorremos hasta el final de la lista mas corta de las dos,
//y despues actualizaremos la lista con modificaciones de coste constante 


#include <iostream>                              
#include <fstream>               
#include <algorithm>
using namespace std;

#include "deque_eda.h"

class EntremezclarListas : public deque<int> {
public:
   // imprime la lista
   void print(std::ostream& o = std::cout) const {
	   // rellenar
	   Nodo* it = this->fantasma->sig;//variable que recorrera los nodos de la lista
	   while (it != this->fantasma) {
		   cout << it->elem << " ";
		   it = it->sig;
	   }
	   cout << endl;
   }

   // modifica this para entremezclar sus elementos con los de other
   void entremezclar(EntremezclarListas & other) {


	   if (this->empty()) {//si la lista principal esta vacia, guardamos la otra lista como principal
		   this->fantasma->sig = other.fantasma->sig;
		   other.fantasma->sig->ant = this->fantasma;
		   this->fantasma->ant = other.fantasma->ant;
		   other.fantasma->ant->sig = this->fantasma;
	   }
	   else {//si la principal no esta vacia

		   Nodo* itOther = other.fantasma->sig;//variable para recorrer la lista secundaria
		   Nodo* it = this->fantasma->sig;//variable para recorrer la lista principal

		   while (itOther != other.fantasma && it != this->fantasma) {//hasta que no acabemos de recorrer una de las dos listas
			   Nodo* aux = it->sig;//variable en la que guardamos el nodo sig del it de la principal
			   Nodo* auxOther = itOther->sig;//variable en la que guardamos el nodo sig del it de la secundaria
			   it->sig = itOther;//actualizamos los nodos introduciendo de la lista secundaria en la principal
			   itOther->ant = it;
			   itOther->sig = aux;
			   aux->ant = itOther;

			   it = aux;//actualizamos los iteradores cogiendo sus siguientes de cada lista para la siguiente vuelta
			   itOther = auxOther;
			  
		   }

		   if (it == fantasma) {//miramos si la lista principal se ha acabado, para añadir los que quedan de la secundaria
			   itOther->ant = this->fantasma->ant;
			   this->fantasma->ant->sig = itOther;
			   other.fantasma->ant->sig = this->fantasma;
		   }
		   //no miramos el caso de que no acabe la lista secundaria, ya que los nodos ya estarian bien colocados en la principal
		   this->nelems += other.nelems;//actualizamos el nelems de la lista principal
	   }
		other.fantasma->sig = other.fantasma->ant = other.fantasma;
      // rellenar
   }
   
};


/////////////////////////////////////////////////////////
// de aquí hacia abajo NO se puede modificar nada

inline std::ostream& operator<<(std::ostream & o, EntremezclarListas const& a) {
   a.print(o);
   return o;
}

EntremezclarListas leerLista() {
   EntremezclarListas lista;
   int n, val;
   cin >> n; // tamaño
   while (n--) {
      cin >> val;
      lista.push_back(val);
   }
   return lista;
}

void resuelveCaso() {
   auto lista1 = leerLista();
   auto lista2 = leerLista();
   
   lista1.entremezclar(lista2);
   
   cout << lista1 << '\n';
}


int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int casos;
   cin >> casos;
   for (int i = 0; i < casos; ++i) {
      resuelveCaso();
   }

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
 //  system("PAUSE");
#endif
   return 0;
}
