#include"Curso.h"

Curso::Curso(string d, string n, int c, Fecha* f, int h){
    _descripcion=d;
    _nivel=n;
    _cupMax=c;
    _fecha=f;
    _hora=h;
    //_lista=NULL;
}
Curso::~Curso(){}
void Curso::setDescripcion(string d){
    _descripcion=d;
}
void Curso::setNivel(string n){
    _nivel=n;
}
void Curso::setCup(int c){
    _cupMax=c;
}
void Curso::setFecha(Fecha* f){
    _fecha=f;
}
void Curso::setHora(int h){
    _hora=h;
}
string Curso::getDescripcion(){
    return _descripcion;
}
string Curso::getNivel(){
    return _nivel;
}
int Curso::getCup(){
    return _cupMax;
}
Fecha* Curso::getFecha(){
    return _fecha;
}
int Curso::getHora(){
    return _hora;
}