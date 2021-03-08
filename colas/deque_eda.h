//
//  deque_eda.h
//
//  Implementación del TAD cola doble con nodos doblemente enlazados
//  y nodo fantasma (circular)
//
//  Estructuras de Datos y Algoritmos
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2016-2019 Alberto Verdejo
//

#ifndef deque_eda_h
#define deque_eda_h

#include <stdexcept>
#include <cassert>
#include<iostream>

template <class T>
class deque {
protected:
	/*
	 Nodo que almacena internamente el elemento (de tipo T),
	 y dos punteros, uno al nodo anterior y otro al nodo siguiente.
	 */
	struct Nodo {
		Nodo() : ant(nullptr), sig(nullptr) {}
		Nodo(T const& elem, Nodo* ant, Nodo* sig) : elem(elem), ant(ant), sig(sig) {}
		T elem;
		Nodo* ant;
		Nodo* sig;
	};

	// puntero al nodo fantasma
	Nodo* fantasma;

	// número de elementos
	int nelems;

public:

	// constructor: cola doble vacía
	deque() : fantasma(new Nodo()), nelems(0) {
		fantasma->sig = fantasma->ant = fantasma; // circular
	}

	// destructor
	~deque() {
		libera();
	}

	// constructor por copia
	deque(deque<T> const& other) {
		copia(other);
	}

	// operador de asignación
	deque<T>& operator=(deque<T> const& that) {
		if (this != &that) {
			libera();
			copia(that);
		}
		return *this;
	}

	// añadir un elemento por el principio
	void push_front(T const& e) {
		inserta_elem(e, fantasma, fantasma->sig);
	}

	// añadir un elemento por el final
	void push_back(T const& e) {
		inserta_elem(e, fantasma->ant, fantasma);
	}

	// consultar el primer elemento de la dcola
	T const& front() const {
		if (empty())
			throw std::domain_error("la dcola vacia no tiene primero");
		return fantasma->sig->elem;
	}

	// consultar el último elemento de la dcola
	T const& back() const {
		if (empty())
			throw std::domain_error("la dcola vacia no tiene ultimo");
		return fantasma->ant->elem;
	}

	// eliminar el primer elemento
	void pop_front() {
		if (empty())
			throw std::domain_error("eliminando el primero de una dcola vacia");
		borra_elem(fantasma->sig);
	}

	// elminar el último elemento
	void pop_back() {
		if (empty())
			throw std::domain_error("eliminando el ultimo de una dcola vacia");
		borra_elem(fantasma->ant);
	}

	// consultar si la dcola está vacía
	bool empty() const {
		return nelems == 0;
	}

	// consultar el tamaño de la cola doble
	int size() const {
		return nelems;
	}

	void duplica() {
		if (empty()) {
			//throw std::domain_error("duplicando una dcola vacia");
		}
		else {
			Nodo* aux = fantasma->sig;
			while (aux != fantasma) {
				Nodo* auxDup = new Nodo(aux->elem, aux, aux->sig);
				Nodo* auxSig = aux->sig;
				aux->sig = auxDup;
				auxSig->ant = auxDup;
				aux = auxSig;
			}
		}
	}

	void invertir() {
		if (this->nelems>1) {
			Nodo* prim = this->fantasma->sig;
			Nodo* ult = this->fantasma->ant;
			Nodo* auxPrim = prim->sig;
			fantasma->ant = prim;

			for (int i = 1; i < this->nelems; i++) {
				prim->sig = ult->sig;
				prim->ant = ult;
				ult->sig = prim;
				prim = auxPrim;
				auxPrim = prim->sig;
			}
			fantasma->sig = ult;
		}
	}

	void insertar(deque<T> &other, const int pos) {
		if (pos == 0) {
			Nodo* ini = this->fantasma->sig;
			Nodo* otherFant = other.fantasma;
			this->fantasma->sig = otherFant->sig;
			otherFant->sig->ant = this->fantasma;
			otherFant->ant->sig = ini;
		}
		else if (pos == this->nelems) {
			Nodo* ult = this->fantasma->ant;
			Nodo* otherFant = other.fantasma;
			ult->sig = otherFant->sig;
			otherFant->sig->ant = ult;
			this->fantasma->ant = otherFant->ant;
			otherFant->ant->sig = this->fantasma;
		}
		else {
			Nodo* ini = this->fantasma->sig;
			Nodo* otherFant = other.fantasma;
			for (int i = 1; i < pos; i++) {
				ini = ini->sig;
			}
			Nodo* aux = ini->sig;//para dejar ordenado anteriores y siguientes
			ini->sig = otherFant->sig;
			otherFant->sig->ant = ini;
			otherFant->ant->sig = aux;
			aux->ant = otherFant->ant;
		}
		other.fantasma->sig = other.fantasma->ant = other.fantasma;
	}

	void mostrar() {
		if (empty()) {
			//throw std::domain_error("mostrando una dcola vacia");
		}
		else {
			Nodo* aux = fantasma->sig;
			while (aux != fantasma) {
				std::cout << aux->elem << " ";
				aux = aux->sig;
			}
			
		}
		std::cout << std::endl;
	}

protected:

	void libera() {
		// primero rompemos la circularidad
		fantasma->ant->sig = nullptr;
		fantasma->ant = nullptr;
		while (fantasma != nullptr) {
			Nodo* a_borrar = fantasma;
			fantasma = fantasma->sig;
			delete a_borrar;
		}
	}

	void copia(deque<T> const& other) {
		fantasma = new Nodo();
		fantasma->sig = fantasma;
		fantasma->ant = fantasma;
		nelems = 0;

		// act recorre la cola que estamos copiando
		Nodo* act = other.fantasma->sig;
		while (act != other.fantasma) {
			push_back(act->elem);
			act = act->sig;
		}
	}

	// insertar un nuevo nodo entre anterior y siguiente
	Nodo* inserta_elem(T const& e, Nodo* anterior, Nodo* siguiente) {
		Nodo* nuevo = new Nodo(e, anterior, siguiente);
		anterior->sig = nuevo;
		siguiente->ant = nuevo;
		++nelems;
		return nuevo;
	}

	// eliminar el nodo n
	void borra_elem(Nodo* n) {
		assert(n != nullptr);
		n->ant->sig = n->sig;
		n->sig->ant = n->ant;
		delete n;
		--nelems;
	}
};

#endif // deque_eda_h
