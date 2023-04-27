#pragma once
#include "Lista_Template.h"

template <class T>
class Iterador {
	Nodo<T>* pNodo;

public:
	Iterador();
	Iterador(Nodo<T>*);
	virtual ~Iterador();
	Nodo<T>* getPNodo();
	Iterador* operator = (Iterador<T>*);
	bool operator != (const Iterador<T>&);
	T* operator * ();
	void operator ++ ();

};

template<class T>
inline Iterador<T>::Iterador()
{
	pNodo = NULL;
}

template<class T>
inline Iterador<T>::Iterador(Nodo<T>* p)
{
	pNodo = p;
}

template<class T>
inline Iterador<T>::~Iterador()
{

}

template<class T>
inline Nodo<T>* Iterador<T>::getPNodo()
{
	return pNodo;
}

template<class T>
inline Iterador<T>* Iterador<T>::operator=(Iterador<T>* i)
{
	if (i != NULL) {
		return new Iterador(i->pNodo);
	}
	return NULL;
}

template<class T>
inline bool Iterador<T>::operator != (const Iterador<T>& i)
{
	if (&i != NULL) {
		if (this->pNodo == NULL && i.pNodo == NULL) {
			return false;
		}if (this->pNodo != i.pNodo) {
			return true;
		}
	}
	return true;
}

template<class T>
inline T* Iterador<T>::operator*()
{
	if (pNodo != NULL) {
		return this->getPNodo()->getInfo();
	}
}

template<class T>
inline void Iterador<T>::operator++()
{
	pNodo = pNodo->getSig();
}