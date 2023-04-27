#pragma once
#include <iostream>
#include <sstream>
#include "Nodo_Template.h"
#include "Iterador.h"
using namespace std;
template <class T>
class ListaT {
private:
	Nodo<T>* _primero;
	Nodo<T>* _actual;
public:
	ListaT();
	virtual ~ListaT();
	void insertarElem(T*);// nota aqui no se puede poner con const
	virtual bool eliminarUltimo();
	virtual bool listaVacia();
	virtual int contador();
	string toString();
	Nodo<T>* getPriemero();
	Iterador<T>* begin();     // Colocar un iterador al inicio
	Iterador<T>* end();
};
template <class T>
ListaT<T>::ListaT() {
	_primero = NULL;
	_actual = NULL;
}
template <class T>
void ListaT<T>::insertarElem(T* p) {
	_actual = _primero;
	_primero = new Nodo<T>(p, _primero);
}
template <class T>
ListaT<T>::~ListaT() {
	while (!listaVacia()) {
		eliminarUltimo();
	}
}
template <class T>
bool ListaT<T>::eliminarUltimo() {
	_actual = _primero;
	if (_primero == NULL)
	{
		return false;
	}
	else
	{
		if (_primero->getSig() == NULL)
		{
			delete _primero;
			_primero = NULL;
		}
		else
		{

			while (_actual->getSig()->getSig() != NULL)
			{
				_actual = _actual->getSig();
			}
			delete  _actual->getSig();
			_actual->setSiguiente(NULL);
		}
		return true;
	}
}
template <class T>
bool ListaT<T>::listaVacia() {
	if (_primero == NULL) {
		return true;
	}
	return false;
}
template <class T>
int ListaT<T>::contador() {
	int cont = 0;
	_actual = _primero;
	while (_actual != NULL) {
		cont++;
		_actual = _actual->getSig();
	}
	return cont;
}

template <class T>
string ListaT<T>::toString() {
	stringstream s;
	_actual = _primero;
	while (_actual != NULL) {
		s << _actual->toStringNodo();
		_actual = _actual->getSig();
	}
	return s.str();
}

template<class T>
inline Nodo<T>* ListaT<T>::getPriemero()
{
	return _primero;
}

template<class T>
Iterador<T>* ListaT<T>::begin() {
	return new Iterador<T>(_primero);
}

template<class T>
Iterador<T>* ListaT<T>::end() {
	return new Iterador<T>();
}