#pragma once
#include <iostream>
#include <sstream>
#include "Fecha.h"
//#include "Iterador.h"
#include "Grupo.h"
#include "Execpciones.h"
//#include "Lista_Template.h"


using namespace std;

class Curso {
private:
    string _codCurso;
    string _nombreCurso;
    string _nivel;
    int _canGrupos;//tamaño
    Fecha* _fecha; // Esto seria mas bien grupos
    //int _cupMax;//Hace falta? 
    string _descripcion;

    int _numGrupo;
    static int contCurso;
    int _hora;// creo que seria mejor gets y sets de grupo 
    int _can;
    ListaT<Grupo>* _lisGrupos = NULL;
    Iterador<Grupo>* it1;
    Iterador<Grupo>* it2;

   

public:
    Curso(string, string, string, int, string);
    Curso(string, string, int, Fecha*, int, int);
    ~Curso();
    void setIdent(string);
    void setNombreDcurso(string);
    void setDescripcion(string);
    void setNivel(string);
    void setCanGrup(int);
    void setFecha(Fecha*);
    void setHora(int);
    string getIdent();
    string getNombreDcurso();
    string getDescripcion();
    string getNivel();
    int getCanGrup();
    Fecha* getFecha();
    int getHora();
    string Listar();
    string toString();
   
    //Lista-------------------------------
    ListaT<Grupo>* getListaGrupos();
    bool verficarEspacio();
    bool ingresarGrupo(Grupo*);
    Grupo* operator[](int);

};
