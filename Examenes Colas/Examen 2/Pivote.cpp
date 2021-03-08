
// NOMBRES Y APELLIDOS (USUARIO DEL JUEZ)

// COMENTARIO SOBRE LA SOLUCIÓN Y SU COSTE JUSTIFICADO
// O(N) coste lineal, siendo N el numero de nodos o elementos de la lista, ya que recorremos todos los nodos solo una vez


#include <iostream>               
#include <fstream>               
#include <algorithm>
using namespace std;

#include "deque_eda.h"

class ListaParticion : public deque<int> {
public:
   void print(std::ostream& o = std::cout) const {
      // rellenar
	   Nodo* it = this->fantasma->sig;//variable que recorrera los nodos de la lista
	   while(it != this->fantasma){
		   cout << it->elem << " ";
		   it = it->sig;
	   }
	   cout << endl;
   }
   
   // produce la partición de la lista respecto al privote
   void particion(int pivote) {

	   Nodo* it = this->fantasma->sig;//va recorriendo los nodos de la lista
	   for (int i = 0; i < this->nelems; i++) {// pongo for, ya que si pusiera while(it != fantasma), al ir añadiendo al final, volveria a recorrer los que ya he colocado
		   if (it->elem >= pivote) {//miramos si el elemento es mayor o igual al pivote
				Nodo* ant = it->ant;//guardamos los nodos para dejar la lista actualizada
				Nodo* sig = it->sig;
			   
				ant->sig = sig;//actualizamos el orden de la lista
				sig->ant = ant;
				this->fantasma->ant->sig = it;// y movemos el nodo al final de la lista
				it->ant = this->fantasma->ant;
				it->sig = this->fantasma;
				this->fantasma->ant = it;
				it = sig;//y pasamos a comprobar el siguiente nodo

		   }else
				it = it->sig;
	   }


   }
};



/////////////////////////////////////////////////////////
// de aquí hacia abajo NO se puede modificar nada

inline std::ostream& operator<<(std::ostream & o, ListaParticion const& a) {
   a.print(o);
   return o;
}

bool resuelveCaso() {
   int N, pivote;
   cin >> N >> pivote;
   if (!cin)
      return 0;
   
   ListaParticion lista;
   // leemos la lista de la entrada
   int elem;
   for (int i = 0; i < N; ++i) {
      cin >> elem;
      lista.push_back(elem);
   }
   
   
   lista.particion(pivote);
   
   cout << lista << '\n';
   
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
   // system("PAUSE");
#endif
   return 0;
}
