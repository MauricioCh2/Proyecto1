#pragma once
#include <fstream>
#include "Deportista.h"
//#include "Grupo.h"
#include "Curso.h"
#include "Expediente.h"
#include "Iterador.h"


class Gym {
private:
	string _nombre;
	int _mensualidad;
	ListaT<Deportista>* _lisCliente = NULL;
	//ListaT<Grupo>* _lisGrupo = NULL;
	ListaT<Curso>* _lisCurso = NULL;
	ListaT<Expediente>* _lisExpediente = NULL;
	Fecha* _fechaHoy = NULL;
public:
	//GYM-----------------------------------------------------------
	Gym();
	Gym(Fecha*);
	Fecha* getFecha();
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
	bool verDisponivilidadCursos(string);
	void ingresarGrupo(string,Grupo*);
	string imprimirListadoGrupo(string);
	int PruebaCantGrupos(string c);
	string reporteGrupoEspe(string,string);
	void ingresarClienteAGrupos(string,string, Deportista*);
	string imprimirClientesDeUnGrupo(string, string);
	//Clientes------------------------------------------------------
	bool verDisponivilidadGrupos(string, string);
	string imprimirListaClientes();

	//string imprimirListadoDeportistas();
	//listo  
	ListaT<Grupo>* getListaDgruposDcurso(string);
	string imprimirListadoDeClientesDUnGrupo(string,string);
	void cancelarMatricula(string,string,string);


	ListaT<Deportista>* getListaDepor();
	ListaT<Expediente>* getListaExpediente();

	//ARCHIVOS-------------------------
	void guardarCursos(ofstream&);
	void guardarGrupos(ofstream&);
	void guardarExpedientes(ofstream&);

};
