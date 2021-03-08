//
//  queue_eda.h
//
//  Implementación del TAD cola con nodos enlazados
//  y punteros al primero y al último nodo
//
//  Estructuras de Datos y Algoritmos
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2016-2019 Alberto Verdejo
//

#ifndef queue_eda_h
#define queue_eda_h

#include<iostream>
#include<stack>
#include <stdexcept>  // std::domain_error

template <class T>
class queue {
protected:

	/*
	 Nodo que almacena internamente el elemento (de tipo T),
	 y un puntero al nodo siguiente, que puede ser nullptr si
	 el nodo es el último de la lista enlazada.
	 */
	struct Nodo {
		Nodo() : sig(nullptr) {}
		Nodo(T const& elem, Nodo* si = nullptr) : elem(elem), sig(si) {}
		T elem;
		Nodo* sig;
	};

	// punteros al primer y último elemento
	Nodo* prim;
	Nodo* ult;

	// número de elementos en la cola
	int nelems;

public:

	// constructor: cola vacía
	queue() : prim(nullptr), ult(nullptr), nelems(0) {}

	// destructor
	~queue() {
		libera();
	}

	// constructor por copia
	queue(queue<T> const& other) {
		copia(other);
	}

	// operador de asignación
	queue<T>& operator=(queue<T> const& other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

	// añadir un elemento al final de la cola
	void push(T const& elem) {
		Nodo* nuevo = new Nodo(elem);

		if (ult != nullptr)
			ult->sig = nuevo;
		ult = nuevo;
		if (prim == nullptr) // la cola estaba vacía
			prim = nuevo;
		++nelems;
	}

	//duplica la cola
	void duplica() {
		if (empty()) {
			//throw std::domain_error("la cola vacia no tiene elemtos que duplicar");
		}
		else {
			Nodo* auxPrim = prim ;
			//aux->sig = prim->sig;
			//prim->sig = aux;
			while(auxPrim != ult) {
				Nodo* auxSig = new Nodo(auxPrim->elem);
				auxSig->sig = auxPrim->sig;
				auxPrim->sig = auxSig;
				auxPrim = auxSig->sig;
				nelems++;
			}
			Nodo* auxSig = new Nodo(ult->elem);
			auxPrim->sig = auxSig;
			ult = auxSig;
		}
	}

	void mostrar() {

		if (empty()) {
			//throw std::domain_error("la cola vacia no tiene elemtos que mostrar");
			std::cout << std::endl;
		}
		else {
			Nodo* auxI = prim;
			while (auxI != ult) {
				std::cout << auxI->elem << " ";
				auxI = auxI->sig;
			}
			std::cout << ult->elem << std::endl;
		}
	}

	void invertir() {
		if (this->nelems>1) {
			Nodo* aux;
			Nodo* auxSig = this->prim->sig;
			Nodo* auxUlt = this->ult;
			this->ult = prim;
			this->ult->sig = nullptr;
			auxUlt->sig = this->ult;
			prim = auxSig;
			

			for (int i = 1; i < this->nelems-1;i++) {//ya que el primer numero lo modificamos antes
				auxSig = this->prim->sig;
				aux = auxUlt->sig;
				auxUlt->sig = prim;
				prim->sig = aux;
				prim = auxSig;
			}
		}
	}

	void mezclar(queue<T> const& other) {
		Nodo* aux=prim;
		Nodo* auxOther = other.prim;
		Nodo* auxOther2 = other.prim->sig;
		while (other.ult != auxOther || aux != ult) {
			if (aux != ult && auxOther != other.ult) {
				auxOther2 = auxOther->sig;
				auxOther->sig = aux->sig;
				aux->sig = auxOther;
				auxOther = auxOther2;
			} 
			if (aux == ult) {
				aux->sig = auxOther;
				aux = aux->sig;
				auxOther = auxOther->sig;
				ult = aux;
			}
		}
		if (aux == ult) {
			aux->sig = auxOther;
			aux = aux->sig;
			ult = aux;
		}
		else {
			auxOther2 = aux->sig;
			aux->sig = auxOther;
			auxOther->sig = auxOther2;
		}
	}

	// consultar el primero de la cola
	T const& front() const {
		if (empty())
			throw std::domain_error("la cola vacia no tiene primero");
		return prim->elem;
	}

	// eliminar el primero de la cola
	void pop() {
		if (empty())
			throw std::domain_error("eliminando de una cola vacia");
		Nodo* a_borrar = prim;
		prim = prim->sig;
		if (prim == nullptr) // la cola se ha quedado vacía
			ult = nullptr;
		delete a_borrar;
		--nelems;
	}

	// consultar si la cola está vacía
	bool empty() const {
		return nelems == 0;
	}

	// consultar el tamaño de la cola
	int size() const {
		return nelems;
	}

protected:

	void libera() {
		while (prim != nullptr) {
			Nodo* a_borrar = prim;
			prim = prim->sig;
			delete a_borrar;
		}
		ult = nullptr;
	}

	// this está sin inicializar
	void copia(queue const& other) {
		if (other.empty()) {
			prim = ult = nullptr;
			nelems = 0;
		}
		else {
			Nodo* act = other.prim; // recorre la cola original
			Nodo* ant = new Nodo(act->elem); // último nodo copiado
			prim = ant;
			while (act->sig != nullptr) {
				act = act->sig;
				ant->sig = new Nodo(act->elem);
				ant = ant->sig;
			}
			ult = ant;
			nelems = other.nelems;
		}
	}
};

#endif // queue_eda_h
