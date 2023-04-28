#pragma once
#include <iostream>
#include <sstream>
#include "Fecha.h"
#include "Lista_Template.h"
#include "Grupo.h"
//#include "Lista_Template.h"
using namespace std;

class Curso {
private:
    string _descripcion;
    string _nivel;
    int _cupMax;
    Fecha* _fecha;
    int _hora;
    //ListaT<Grupo>* _lisCurso = NULL;//Junan Pablo Cartin 
public:
    Curso(string, string, int, Fecha*, int);
    ~Curso();
    void setDescripcion(string);
    void setNivel(string);
    void setCup(int);
    void setFecha(Fecha*);
    void setHora(int);
    string getDescripcion();
    string getNivel();
    int getCup();
    Fecha* getFecha();
    int getHora();
};