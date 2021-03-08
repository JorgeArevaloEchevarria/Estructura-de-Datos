//Jorge Arevalo Echevarria
// NOMBRES Y APELLIDOS

#include <iostream>
#include <fstream>
#include <algorithm>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
// coste O(N) siendo N el numero de capitulos ya que los accesos al diccionario son de coste constante

void resuelveCaso() {

	int Ncap;
	cin >> Ncap;
	unordered_map<int, int> emision;//guarda la ultima vex que se ha emitido
	int maximo = 0;//longitud del maximo tramo
	int p = 1;//posicion en la que empieza el tramo sin repeticiones
	int cap;
	for (int i = 1; i <= Ncap; i++) {
		cin >> cap;
		int & donde = emision[cap];//coste constante
		if (donde >= p)//rompe el tramo ya que tenemos el mismo capitulo en el tramo
			p = donde+1;//actualizamos el principio del siguiente tramo
		maximo = max(maximo, i - p + 1);//comprobamos si el tramo es mas largo que el maximo
		donde = i;//introducimos la posicion donde se ha emitido el capitulo
	}
	cout << maximo << endl;
	
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
