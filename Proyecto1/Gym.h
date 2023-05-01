#pragma once
#include <iostream>
#include <string>
#include <sstream>
//esta va a ser la que tenga las listas de todo 

#include "Deportista.h"
#include "Lista_Template.h"
//#include "Grupo.h"
#include "Curso.h"


class Gym {
	//sera que guardamos la fecha aqui?, se lo podriamos pasar por parametros y todo
	//Lista de clientes
private:
	string _nombre;
	int _mensualidad;
	ListaT<Deportista>* _lisCliente = NULL;
	//ListaT<Grupo>* _lisGrupo = NULL;
	ListaT<Curso>* _lisCurso = NULL;
public:
	Gym();
	//Administracion------------------------------------------------
	string getNombreDgym();
	void setNombreDgym(string);
	int getMensualidadDgym();
	void setMensualidadDgym(int);
	//Cursos--------------------------------------------------------
	void ingresarCursos(Curso*);
	string imprimirListaCursos();
	string imprimirListaEspe(string);
	string imprimirListadoCursos();
	
	ListaT<Curso>* getListaCurso();
	//Grupos--------------------------------------------------------
	void ingresarGrupo(string,Grupo*);
	string imprimirListadoGrupo(string);
	int PruebaCantGrupos(string c);
	string reporteGrupoEspe(string,string);
	void ingresarClienteAGrupos(string,string, string);
	//Clientes------------------------------------------------------
	void ingresarListaClientes(Deportista*);
	string imprimirListaClientes();


	ListaT<Deportista>* getListaDepor();

};
