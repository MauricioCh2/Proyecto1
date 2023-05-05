#pragma once
#include <fstream>
#include "Gym.h"
#include "Triatlonista.h"
#include "Utilities.h"
#include "Lista_Template.h"
#include "stringMOD.h"
class Archivos {
private: 
	Gym* _gym;
public: 
	Archivos(Gym*);
	~Archivos();
	//Guardar datos-----------------------------------
	bool guardarDatos();
	bool guardarDeportistas();
	bool guardarCursos();
	bool guardarGrupos();
	bool guadarExpediente();
	//lee datos---------------------------------------
	bool cargarDatos();
	bool cargarDeportistas();
	bool cargarCursos();
	bool cargarGrupos();
	bool cargarExpediente();


};