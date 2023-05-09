#pragma once
#include <fstream>
#include "Gym.h"
#include "Triatlonista.h"
#include "Utilities.h"
#include "Lista_Template.h"
#include "stringMOD.h"
#include "Fecha.h"
class Archivos {
private: 
	Gym* _gym;
	ListaT<Deportista>* lisAux;
public: 
	Archivos(Gym*);
	~Archivos();
	//Guardar datos-----------------------------------
	bool guardarDatos();
	bool guardarCursos();
	bool guardarGrupos();
	bool guadarExpediente();
	//lee datos---------------------------------------
	bool cargarDatos();
	
	bool cargarCursos();
	bool cargarGrupos();
	bool cargarExpediente();


};