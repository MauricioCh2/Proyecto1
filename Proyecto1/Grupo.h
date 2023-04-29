#pragma once
#include "Curso.h"
#include "Fecha.h"
class Grupo {
public:
	//hay que ver como listar los cursos 
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
private:
	Grupo(string, string, int, Fecha*, int, char, int, int, int, int);
	~Grupo();
	//friend ostream& operator<<(ostream& ou, Grupo& g);
	string toString();


	string getNombreCurso();
	int getConnumGrupo();
	Deportista* getVectorClientes();
	// sets--------------------------------------
	void setCedInstructor(string);
	void setNomInstructo(string);
	void setcupMax(int);
	void setFechaInicio(Fecha* );
	void setSemDuracion(int);
	void setDiaSem(char);
	void setHoraInicio(int);
	void setMinutoInicio(int);
	void setHoraFinal(int);
	void setMinutoFinal(int);
	void setNombreCurso();
	//Vector triatlonista
};