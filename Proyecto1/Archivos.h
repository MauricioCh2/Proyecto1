#pragma once
#include <fstream>
#include "Gym.h"
#include "Triatlonista.h"
#include "Utilities.h"
class Archivos {
private: 
	Gym* _gym;
public: 
	Archivos(Gym*);
	~Archivos();
	//Guardar datos-----------------------------------
	bool guardarDatos();
	bool guardarDeportistas();
	//lee datos---------------------------------------
	bool cargarDatos();
	bool cargarDeportistas();

};