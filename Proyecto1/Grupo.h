#pragma once
#include "Fecha.h"
class Grupo {
private:
	string _cedInstructor;
	string _nomInstructor;
	int _cupMax;
	Fecha* _fechaInicio;
	int _semDuracion;
	//Horarios
	char _diaSemana;
	int _horaInicio;
	int _minInicio;

	int _horaFinaliza;
	int _minFinaliza;

	string _nombreCurso;
	int _connumGrupo;


public:
	Grupo(string, string, int, Fecha*, int, char, int, int, int, int);
	~Grupo();
	//friend ostream& operator<<(ostream& ou, Grupo& g);
	string toString();


};