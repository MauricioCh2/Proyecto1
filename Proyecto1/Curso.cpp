#include"Curso.h"
int Curso::contCurso = 0;
Curso::Curso(string nomC, string niv, int canGrupos , string desc )
{
    _nombreCurso = nomC;
    _nivel = niv;
    _canGrupos = canGrupos;
    _descripcion = desc;
    _can = 0;

    _VGrupos = new Grupo * [canGrupos];
    _canGrupos = canGrupos;
    for (int i = 0; i < _canGrupos; i++) {
        _VGrupos[i] = NULL;
    }
    contCurso++;
    _numCurso = contCurso;
    
}
//probablemente eliminemos este 
Curso::Curso(string d, string n, int c, Fecha* f, int h,int canGrupo) {
    _descripcion = d;
    _nivel = n;
    _cupMax = c;
    _fecha = f;
    _hora = h;
    _can = 0;
    _VGrupos = new Grupo * [canGrupo];
    _canGrupos = canGrupo;
    for (int i = 0; i < _canGrupos; i++) {
        _VGrupos[i] = NULL;
    }

}
Curso::~Curso() {
    for (int i = 0; i < _can; i++) {
        if (_VGrupos[i] != NULL)
            delete _VGrupos[i];
    }
    delete[] _VGrupos;
}
void Curso::setDescripcion(string d) {
    _descripcion = d;
}
void Curso::setNivel(string n) {
    _nivel = n;
}
void Curso::setCup(int c) {
    _cupMax = c;
}
void Curso::setFecha(Fecha* f) {
    _fecha = f;
}
void Curso::setHora(int h) {
    _hora = h;
}
string Curso::getDescripcion() {
    return _descripcion;
}
string Curso::getNivel() {
    return _nivel;
}
int Curso::getCup() {
    return _cupMax;
}
Fecha* Curso::getFecha() {
    return _fecha;
}
int Curso::getHora() {
    return _hora;
}
string Curso::toString() {
    stringstream s;
    s << _numCurso<< "\t" <<_nombreCurso << "\t" << _nivel << endl;
    return s.str();
}

Grupo* Curso::getVectorGrupos()
{
    return nullptr;
}

//Vector------------------------------------------
void Curso::ingresarElemento( Grupo& grupo) {
    if (_can<_canGrupos) {
        _VGrupos[_can++] = &grupo;
        _can++;
    }
}
Grupo* Curso::operator[](int k) {
    return _VGrupos[k];
}