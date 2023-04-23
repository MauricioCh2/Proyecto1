#pragma once
#include <iostream>
#include <string>
#include <sstream>
//esta va a ser la que tenga las listas de todo 

#include "Deportista.h"
#include "Lista_Template.h"


class Gym {
	//sera que guardamos la fecha aqui?, se lo podriamos pasar por parametros y todo 

	//Lista de clientes
private:
	ListaT<Deportista>* _lisCliente = NULL;
public: 
	Gym();
	~Gym();
	//Clientes------------------------------------------------------
	void ingresarListaClientes(Deportista*);
};