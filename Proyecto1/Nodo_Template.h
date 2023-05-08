#pragma once
#include <iostream>
#include <sstream>
using namespace std;
template <class T>
class Nodo {
private:
	T* _info;//Objeto DEL Nodo
	Nodo<T>* _siguiente;
public:
	//Basico------------------------------
	Nodo();
	Nodo(T*, Nodo<T>*);
	~Nodo();
	void setInfo( T*);
	T* getInfo();
	void setSiguiente(Nodo<T>*);
	Nodo<T>* getSig();
	string toStringNodo() const;
	string ListarN() const;

	
};
template <class T>
Nodo<T>::Nodo() {
	this->_info = NULL;
	this->_siguiente = NULL;
}
template <class T>
Nodo<T>::Nodo(T* p, Nodo* s) {
	_siguiente = s;
	_info = p;
}
template <class T>
Nodo<T>::~Nodo() {

}
template <class T>
void Nodo<T>::setInfo(T* p) {
	_info = p;
}
template <class T>
T* Nodo<T>::getInfo() {
	return _info;
}
template <class T>
void Nodo<T>::setSiguiente(Nodo* s) {
	_siguiente = s;
}
template <class T>
Nodo<T>* Nodo<T>::getSig() {
	return _siguiente;
}
template <class T>
string Nodo<T>::toStringNodo()const {
	
	return _info->toString();
}
template <class T>

string Nodo<T>::ListarN()const {
	return _info->Listar();
}