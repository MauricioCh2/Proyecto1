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
    //string codCurso;
    string _nombreCurso;
    string _nivel;
    int _canGrupos;//tamaño
    Fecha* _fecha; // Esto seria mas bien grupos
    int _cupMax;//Hace falta? 
    string _descripcion;

    int _numCurso;
    static int contCurso;
    int _hora;// creo que seria mejor gets y sets de grupo 
    int _can;
    Grupo** _VGrupos;

public:
    Curso(string, string, int, string); 
    Curso(string, string, int, Fecha*, int, int);
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
    string toString();
    Grupo* getVectorGrupos();
    //Vector-------------------------------
    void ingresarElemento(Grupo&);
    Grupo* operator[](int);

};