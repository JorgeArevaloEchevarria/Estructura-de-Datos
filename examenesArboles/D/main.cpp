
// NOMBRE Y APELLIDOS (USUARIO DEL JUEZ)
//jorge Arevalo Echevarria

// COMENTARIO SOBRE LA SOLUCIÓN Y SU COSTE JUSTIFICADO
// realizo una busqueda hacia abajo hasta llegar a las hojas, y despues voy comprobando hacia arriba si el arbol es inclinado
// y comprobando las condiciones de inclinado con la altura, y en el caso de que no lo sea devuelvo false

#include <iostream>     
#include <fstream>               
#include <algorithm>
using namespace std;

#include "bintree_eda.h"


// Implementa aquí la función pedida. Puedes definir las funciones
// auxiliares que 

/*Coste:
	T(n){C0 si el arbol.empty()
		{T(ni)+T(nd) +c1 siendo ni el numero de nodos del hijo izquierdo, y nd el numero de nodos del hijo derecho
		quedando un coste O(n) siendo lineal respecto al numero de nodos del arbol
		sumamos la cantidad costante ya que en cada vuelta incrementamos la altura, siendo de coste constante
*/

typedef struct tSol {// me declaro un struct con un bool y la altura 
	int altura;
	bool inclinadoIz;
};

tSol inclinado_izqAux(bintree<char> arbol) {
	if (arbol.empty()) {//miramos si esta vacio e inicializamos la altura y tambien que es inclinado
		return{ 0,true };
	}
	else {
		tSol iz = inclinado_izqAux(arbol.left());//exploramos el hijo iz
		tSol dr = inclinado_izqAux(arbol.right());//exploramos el hijo dr

		if (iz.inclinadoIz && dr.inclinadoIz) {//comprobamos si los hijos han sido inlcinados
			if (iz.altura > dr.altura) {//y comprobamos que no supere la altura
				return{ iz.altura + 1, true };
			}
			else if (iz.altura == 0 && dr.altura == 0) {// aqui compruebo si es hoja, para que no devuelva false
				return { 1,true };
			}
		}
		
		return { 0,false };
	}
}

bool inclinado_izq(bintree<char> arbol) {
	return inclinado_izqAux(arbol).inclinadoIz;// devolvemos el bool para la funcion resuelve caso
}


void resuelveCaso() {
   auto arbol = leerArbol('.');
   if (inclinado_izq(arbol))
      cout << "SI\n";
   else
      cout << "NO\n";
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   cin >> numCasos;
   
   for (int i = 0; i < numCasos; ++i) {
      resuelveCaso();
   }

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   // system("PAUSE");
#endif
   return 0;
}
