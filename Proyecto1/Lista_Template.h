#pragma once
#include <iostream>
#include <sstream>
#include "Nodo_Template.h"
#include "Iterador.h"
#include "Triatlonista.h"
#include "Triatlonista.h"

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
	virtual T* contadorEspecifico(int);//retorna el valor que se encuentre en x posicion
	virtual T* encontrarEsp(string);
	
	string toString();
	string Listar();
	Nodo<T>* getPriemero();
	Iterador<T>* begin();     // Colocar un iterador al inicio
	Iterador<T>* end();
	//Archivos
	void guardarDeportistas(ofstream&);
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
T* ListaT<T>::contadorEspecifico(int n) {
	int cont = 0;
	_actual = _primero;
	while (_actual != NULL) {
		cont++; // creo que esto es menos meos
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
void ListaT<T>::guardarDeportistas(ofstream& depo) {
	_actual = _primero;
	while (_actual != NULL) {
		if (Triatlonista* dep = dynamic_cast<Triatlonista*>(_actual->getInfo())) {

			//deportista-------------------------------------
			depo << dep->getNombre() << "\t"
				<< dep->getCedula() << "\t"
				<< dep->getTelefono() << "\t"
				<< dep->getFechaNacimiento() << "\t"
				//ciclista----------------------------------------
				<< dep->getHorasDeEntrenamiento() << "\t"
				<< dep->getTempPromedio() << "\t"
				//corredor----------------------------------------
				<< dep->getSexo() << "\t"
				<< dep->getEstatura() << "\t"
				//nadado------------------------------------------
				<< dep->getMasaMuscular() << "\t"
				<< dep->getPeso() << "\t"
				<< dep->getPorcGrasaCorporal() << "\t"
				//triatlonista------------------------------------
				<< dep->getCanPartIronMan() << "\t"
				<< dep->getCanTriatGanador() << endl;
		}
		_actual = _actual->getSig();
	}
}