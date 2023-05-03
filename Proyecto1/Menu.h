/*
Recordemos usar la misma convencion a la hora de escribir el nombe de las cosas
Archivos:
Nombre_Archivo
Clase:
MiCLase
Atributos:
mi_atributo
(Nota: no es necesario pero los profes usan _ al inicio de
un atributo privado sin embargo esto no es universal )
Metodos:
misMetodos();
constantes:
MI_COSNTANTE
(Esto si no estoy mal aplica para define y eso)

Fuentes, tiktok.... digo, chatGPT
(Convenciones
CamelCase es cuando se escribe  la primera palabra en minuscula pero el resto pegadas y con la primera letra
en mayus (exceptuando las clases
Snake_case es cuando las palabras se separan por "_")

)
Nada de esto es necesario pero para llevar un orden y que se vea coquete no estamal
*/
#pragma once
#include <iostream>
#include <sstream>
#include "Cobro.h"
#include "Utilities.h"
#include "Gym.h"
#include "Fecha.h"
#include "Triatlonista.h"
#include "Lista_Template.h"
using namespace std;

class Menu {
private:
	Fecha* fecha;
	Gym* _gym;
public:
	Fecha* getFechaActual();
	//Inicio------------------------------------------------------------
	void inicio();
	bool llamarMenus();
	string menuPrincipal();
	//Administracion general--------------------------------------------
	string menuAdministracion();
	bool opMenuAdministracion(int);
	//Control de deportistas--------------------------------------------
	string menuDeportista();
	string subMenuListas();
	bool opMenuDeportista(int);
	//Control de Cursos-------------------------------------------------
	string menuCursos();
	bool opMenuCursos(int);
	//Control de Grupos-------------------------------------------------
	string menuGrupos();
	bool opMenuGrupos(int);
	//Control de pagos--------------------------------------------------
	string menuPagos();
	bool opMenuPagos(int);
	//Guardar en Archivos y salir 
	//realmente esto no requiere metodo 
	void atualizarINFO(Deportista*,Expediente*);
	string QueQuiereEditarTri();
	void atualizarINFOcurso(Curso*);
	void atualizarINFOgrupo(Grupo*);
	string QueQuiereEditarCurso();
	string QueQuiereEditarGrupo();

	
};