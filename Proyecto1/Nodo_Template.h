#pragma once
#include <iostream>
#include <sstream>
using namespace std;
template <class T>
class Nodo {
private:
	T* _info;
	Nodo<T>* _siguiente;
public:
	//Basico------------------------------
	Nodo();
	Nodo(T*, Nodo<T>*);
	~Nodo();
	void setInfo(const T*);
	T* getInfo();
	void setSiguiente(Nodo<T>*);
	Nodo<T>* getSig();
	
};
template <class T>
Nodo<T>::Nodo() {
	this->_info = NULL;
	this->_info = NULL;
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
void Nodo<T>::setInfo(const T* p) {
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