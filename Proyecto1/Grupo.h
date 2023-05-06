#pragma once
#include "Fecha.h"
#include "Deportista.h"
#include "Triatlonista.h"
#include "Lista_Template.h"
//#include "stringMOD.h"
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

	//Internos----------------------------
	string _nombreCurso;
	int _numGrupo;
	//para archivos
	string _codCursoPert; //es ele codigo del curso al que pertenece 
	//eLista triatlonista
	ListaT<Deportista>* _lisDepor;
	

	

public:
	Grupo(string, string, int, Fecha*, int, char, int, int, int, int);
	~Grupo();
	//friend ostream& operator<<(ostream& ou, Grupo& g);
	string toString();
	string Listar();
	
	// gets--------------------------------------
	string getIdent();
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
	//Interno----------------
	string getNombreCurso();
	int getNumGrupo();
	ListaT<Deportista>* getListaDepor();
	int getDispo();
	//Archivos---------------
	string getCodCursoPertenece();
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
	void setnumGrupo(int n);
	void setNombreCurso(string);
	void setCodCursoPertenece(string);
	//Lista deportista
	bool verficarEspacio();
	void ingresarDeportista(Deportista*);
	Deportista* operator[](int);
	string imprimirDeportistas();
};
