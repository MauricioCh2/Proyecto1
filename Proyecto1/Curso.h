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
    //Constructor
    string _codCurso;
    string _nombreCurso;
    string _nivel;
    int _canGrupos;//tamaño
    string _descripcion;
    // otros
    int _numGrupo;
    ListaT<Grupo>* _lisGrupos = NULL;
    Iterador<Grupo>* it1;
    Iterador<Grupo>* it2;

   

public:
    Curso(string, string, string, int, string);
    ~Curso();
    //Sets-----------------
    void setIdent(string);
    void setNombreDcurso(string);
    void setDescripcion(string);
    void setNivel(string);
    void setCanGrup(int);
    
   
    //gets
    string getIdent();
    string getNombreDcurso();
    string getDescripcion();
    string getNivel();
    int getCanGrup();
   
    //curso
    string Listar();
    string toString();
   
    //Lista-------------------------------
    void setListaGrupos(ListaT<Grupo>*);
    ListaT<Grupo>* getListaGrupos();
    bool verficarEspacio();
    bool ingresarGrupo(Grupo*);
    Grupo* operator[](int);

};
