#pragma once
#include <iostream>
#include <sstream>
#include "Nodo_Template.h"
using namespace std;
template <class T>
class ListaT {
private:
	Nodo<T>* _primero;
	Nodo<T>* _actual;
public:
	ListaT();
	virtual ~ListaT();
	void insertarElem(T&);// nota aqui no se puede poner con const
	virtual bool eliminarUltimo();
	virtual bool listaVacia();
	virtual int contador();
	template <class T> // NOta: jamas hacer esto dentro de la clase, solo serviria para un tipo de dato 
	friend ostream& operator << (ostream& out, ListaT<T>& l);//friend le da acceso a todos los miembros de la clase por esto no serviria sin friend
	string toString();
};
template <class T>
ostream& operator << (ostream& out, ListaT<T>& l) { 
	Nodo<T>* _actual = l._primero;
	while (_actual != NULL) {
		out << *_actual->getInfo();
		_actual = _actual->getSig();
	}
	return out;
}
template <class T>
ListaT<T>::ListaT() {
	_primero = NULL;
	_actual = NULL;
}
template <class T>
void ListaT<T>::insertarElem(T& p) {
	_actual = _primero;
	if (listaVacia())
	{
		_primero = new Nodo<T>(&p, NULL);
	}
	else
	{
		while (_actual->getSig() != NULL)
		{
			_actual = _actual->getSig();
		}
		_actual->setSiguiente(new Nodo<T>(&p, NULL));
	}
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
	if (_primero == NULL) return true;
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