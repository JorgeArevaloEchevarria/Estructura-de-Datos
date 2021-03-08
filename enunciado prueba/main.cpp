
// NOMBRES Y APELLIDOS (USUARIO DEL JUEZ)
//jorge arevalo ecehvarria ---usuario:A05

#include <iostream>                                             
#include <fstream>                                             
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

// COMENTARIO SOBRE LA SOLUCIÓN Y SU COSTE JUSTIFICADO
//he utilizado unordered_map, ya que no necesito guardar el orden de los numeros, sino sus apariciones
//en el primer for insertamos los valores en el diccionario
//y en el segundo comprobamos las apariciones y las muestro por pantalla
//Coste : recorremos los N numeros insertandolos, teniendo un coste O(N), ya que las operaciones que usamos del unordered map son constantes
//y en el segundo bucle comprobamos las M preguntas ,teniendo un coste O(M),ya que utilizamos las operaciones del unordered_map que son constantes
// con lo que se nos queda un coste total de O(N+M)


bool resuelveCaso() {
   int N, M;
   cin >> N >> M;
   if (!cin)
      return false;

   unordered_map<int,vector<int>> ocurrencias;//la clave es el numero, y el valor sera un vector con las posiciones en las que aparece
   int num;
   for (int i = 1; i <= N; i++) {//empezamos en 1 para que coincida con los valores en la salida
	   cin >> num;
	   ocurrencias[num].push_back(i);//introucimos los datos en el diccionario, con coste constante
   }
   int ocu;//numero de ocurrencia del numero
   int numOcu;//numero que queremos ver para la ocurrencia
   for (int i = 0; i < M; i++) {//aqui empezamos por 0 ya que es recorrer hasta M, no nos importa el valor de la posicion i
		cin >> ocu;
		cin >> numOcu;
		if (ocurrencias[numOcu].size() < ocu) {//miramos si la busca una ocurrencia, mas de las que hay
			cout << "NO HAY" << endl;
		}
		else {
			cout << ocurrencias[numOcu].at(ocu-1) << endl;//mostramos por pantalla la posicion de la ocurrencia
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
