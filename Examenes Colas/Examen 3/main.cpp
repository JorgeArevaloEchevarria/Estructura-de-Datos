
// NOMBRES Y APELLIDOS (USUARIO DEL JUEZ)
//Jorge Arevalo Echevarria

// COMENTARIO SOBRE LA SOLUCIÓN Y SU COSTE JUSTIFICADO
//en el primer bucle busco encontrar el primer elemento que sea menor o igual que el pivote para poder igualarlo a prim, y poder empezar a enlazar la lista
// y en el segundo buccle a partir de ese prim, empiezo a enlazar los siguientes nodos, viendo que si son mayor que el pivote los coloco al final de la lista
//El coste es O(N) lineal, siendo N el numero de elementos de la lista, ya que recorremos el numero de elementos, sin repetir los que hemos colocado al final

#include <iostream>                                             
#include <fstream>               
#include <algorithm>
using namespace std;

#include "queue_eda.h"

class ListaParticion : public queue<int> {
public:
   // imprime la lista
   void print(std::ostream & o = std::cout) const {
      // rellenar
	   Nodo* it = this->prim;//variable que recorre la lista
	   for (int i = 0; i < this->nelems; i++) {
		   cout << it->elem << " ";// mostramos cada elemento de la lista
		   it = it->sig;
	   }
	   cout << endl;
   }
   
   // produce la partición de la lista respecto al privote
   void particion(int pivote) {
	   Nodo* it = this->prim;//variable que usaremos para encontrar el prim de nuestra lista
	   bool encontrado = false;
	   int cont = 0;//para saber cuantos elementos de la lsita hemos comprobado
	   while (!encontrado) { //hay que encontrar el prim que sea menor o igual que el pivote para poder empezar a enlazar la lista
		   if (it->elem <= pivote) {//primero encontra el prim menor que le pivote
			   encontrado = true;
			   prim = it;
		   }
		   else {//si es un posible prim, los colocamos al final
			   Nodo* aux = it->sig;//variable en la guardamos el siguiente para no perder el sig
			   ult->sig = it;
			   ult = it;
			   ult->sig = nullptr;
			   it = aux;
			   cont++;//actualizamos los que llevamos
		   }
	   }

	   Nodo* ant = prim;// guardamos el anetirior para poder ir enlazando la lista
	   it = ant->sig;// actualizamos el nodo que vamos a comprobar
	   for (int i = cont; i < this->nelems-1; i++) {//a partir de cont, para saber por cual nos habiamos quedado modificando
		   if (it->elem > pivote) {//si es ,ayor se coloca al final de la lista
			   Nodo* sig = it->sig;//variable auxiliar para saber cual es el siguiente que hay que comprobar depues de modificar la lista
			   ult->sig = it;
			   ult = it;
			   ult->sig = nullptr;
			   ant->sig = sig;
			   it = sig;
		   }
		   else {//y sino comprobamos el siguiente elemento
			   ant = it;
			   it = it->sig;
		   }
	   }

   }
};


/////////////////////////////////////////////////////////
// de aquí hacia abajo NO se puede modificar nada

inline std::ostream & operator<<(std::ostream & o, ListaParticion const& a) {
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
      lista.push(elem);
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
