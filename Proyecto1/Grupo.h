#pragma once
#include "Curso.h"
#include "Fecha.h"
class Grupo {
private: 
	//hay que ver como listar los cursos 
	string cedInstructor;
	string nomInstructor;
	int cupMax; 
	Fecha* fechaInicio;
	int semDuracion;
	//Horarios
	char diaSemana;
	string horaInicio;

	int connumGrupo; 
public: 
	Grupo(string,string, int, Fecha*, int, );
};