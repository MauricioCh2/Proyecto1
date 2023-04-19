#pragma once
#include <iostream>
#include <string>
#include <sstream>
//esta va a ser la que tenga las listas de todo 
//#include "Deportista.h"
#include "Ciclista.h"
#include "Corredor.h"
#include "Deportista.h"
#include "Nadador.h"
#include "Triatlonista.h"
class Gym {
	//sera que guardamos la fecha aqui?, se lo podriamos pasar por parametros y todo 

	//ListaClientes* LClient = new ListaClientes();
	//ListaCursos* LCursos = new ListaCursos();
	Gym();
	~Gym();
	//Clientes------------------------------------------------------
	void ingresarListaClientes(Deportista*);
};