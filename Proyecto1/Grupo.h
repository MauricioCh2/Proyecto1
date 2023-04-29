#pragma once
#include "Fecha.h"
#include "Deportista.h"
#include "Triatlonista.h"
class Grupo {
private:
	string _cedInstructor;
	string _nomInstructor;
	int _cupMax;//tamaño
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

	//ector triatlonista
	int _can;
	Deportista** _VClientes;

public:
	Grupo(string, string, int, Fecha*, int, char, int, int, int, int);
	~Grupo();
	//friend ostream& operator<<(ostream& ou, Grupo& g);
	string toString();
	//vector deportista
	void ingresarElemento(Deportista&);
	Deportista* operator[](int);
	// gets--------------------------------------
	string getCedInstructor();
	string getNomInstructor();
	int getCupMax();
	Fecha* getFechaInicio();
	int getSemDuracion();
	char getDiaSemana();
	int getHoraInicio();
	int getMinInicio();
	int getHoraFinaliza();
	int getMinFinaliza();

	string getNombreCurso();
	int getConnumGrupo();
	Deportista* getVectorClientes();
	// sets--------------------------------------
	void setCedInstructor(string);
	void setNomInstructo(string);
	void setcupMax(int);
	void setFechaInicio(Fecha*);
	void setSemDuracion(int);
	void setDiaSem(char);
	void setHoraInicio(int);
	void setMinutoInicio(int);
	void setHoraFinal(int);
	void setMinutoFinal(int);
	void setNombreCurso();
	//Vector triatlonista
};
