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
	void insertarDultimo(T*);
	virtual bool eliminarUltimo();
	virtual bool listaVacia();
	virtual int contador();
	virtual T* contadorEspecifico(int);//retorna el valor que se encuentre en x posicion
	virtual T* encontrarEsp(string);
	virtual bool ExisteEspesifico(string);
	virtual bool eliminarEspe(string);
	virtual T* encontrarPen();
	//virtual bool cambiaNodos(string, string);
	string toString();
	string Listar();

	Nodo<T>* getPriemero();

	Iterador<T>* begin();     // Colocar un iterador al inicio
	Iterador<T>* end();
	//Archivos
	//void guardarDeportistas(ofstream&);
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
template<class T>
inline void ListaT<T>::insertarDultimo(T* p)
{
	_actual = _primero;
	if (_primero == NULL)
	{
		_primero = new Nodo<T>(p, _primero);
	}
	else
	{
		if (_primero->getSig() == NULL)
		{
			
			_primero->setSiguiente(new Nodo<T>(p, NULL));
		}
		else
		{
			while (_actual->getSig() != NULL)
			{
				_actual = _actual->getSig();
			}
			_actual->setSiguiente(new Nodo<T>(p, NULL));
		}
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
T* ListaT<T>::contadorEspecifico(int n) {
	int cont = 0;
	_actual = _primero;
	while (_actual != NULL) {
		cont++;
		if (cont == n) {
			break;
		}
		_actual = _actual->getSig();
	}
	return _actual->getInfo();
}
template <class T>
T* ListaT<T>::encontrarEsp(string s) {
	_actual = _primero;
	T* t;
	while (_actual != NULL) {
		t = dynamic_cast<T*>(_actual->getInfo());
		if (t->getIdent() == s) {
			return t;
		}
		_actual = _actual->getSig();

	}
	return NULL;
}
template<class T>
inline bool ListaT<T>::ExisteEspesifico(string s)
{
	T* t;
	_actual = _primero;
	while (_actual != NULL) {
		t = dynamic_cast<T*>(_actual->getInfo());
		if (t->getIdent() == s) {
			return true;
		}
		_actual = _actual->getSig();

	}
	return false;
}
template <class T>
bool ListaT<T>::eliminarEspe(string i) {
	Nodo<T>* pAnterior = NULL;
	T* t;
	_actual = _primero;
	//si la lista esta vacia
	if (_primero == NULL) {
		return false;
	}
	// si el elemento esta de primero
	t = dynamic_cast<T*>(_primero->getInfo());
	if (t->getIdent() == i) {
		_actual = _actual->getSig();
		delete (_primero);
		_primero = _actual;
		return true;
	}
	// en caso de no ser el primero recorrera la lista
	while (_actual != NULL && t->getIdent() != i) {
		pAnterior = _actual;
		_actual = _actual->getSig();
		t = dynamic_cast <T*>(_actual->getInfo());
	}

	if (_actual == NULL) { return false; }//Si no lo encontro	
	else {// el nodo fue encontrado
		pAnterior->setSiguiente(_actual->getSig());
		delete _actual;
		return true;
	}
	return false;


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
template <class T>
string ListaT<T>::Listar() {
	stringstream s;
	_actual = _primero;
	while (_actual != NULL) {
		s << _actual->ListarN();
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
template <class T>
T* ListaT<T>::encontrarPen() {
	int cont = 0;
	_actual = _primero;
	while (_actual->getSig()->getSig() != NULL) {
		
		_actual = _actual->getSig();
	}
	return _actual->getInfo();
	
}
