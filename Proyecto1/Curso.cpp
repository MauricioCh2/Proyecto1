#include"Curso.h"
int Curso::contCurso = 0;
Curso::Curso(string cod, string nomC, string niv, int canGrupos, string desc)
{
    _codCurso = cod;
    _nombreCurso = nomC;
    _nivel = niv;
    _canGrupos = canGrupos;
    _descripcion = desc;
    _can = 0;

    _lisGrupos = new ListaT<Grupo>;

}
//probablemente eliminemos este 
Curso::Curso(string d, string n, int c, Fecha* f, int h, int canGrupo) {
    _descripcion = d;
    _nivel = n;
    _cupMax = c;
    _fecha = f;
    _hora = h;
    _can = 0;
   /* _VGrupos = new Grupo * [canGrupo];
    _canGrupos = canGrupo;
    for (int i = 0; i < _canGrupos; i++) {
        _VGrupos[i] = NULL;
    }*/

}
Curso::~Curso() {
    _lisGrupos->eliminarUltimo();
    delete _lisGrupos;
    /*for (int i = 0; i < _can; i++) {
        if (_VGrupos[i] != NULL)
            delete _VGrupos[i];
    }
    delete[] _VGrupos;*/
}
void Curso::setIdent(string i)
{
    _codCurso = i;
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
string Curso::getIdent()
{
    return _codCurso;
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
string Curso::Listar()
{
    stringstream s;
    s << _codCurso << "\t\t" << _nombreCurso << "\t\t" << _nivel << endl;
    return s.str();
}
string Curso::toString() {
    stringstream s;
    s << "Nombre del curso: " << _nombreCurso << endl;
    s << "Nivel del curso: " << _nivel << endl;
    s << "Cantidad de grupos: " << _canGrupos << endl;
    s << "Descripcion : "<<_descripcion << endl;
    s << "Detalles de grupos abiertos" << endl;
    s << "#Grupo\t Dia\t\t Horario\t Grupo \t Cantidad" << endl;
    s << _lisGrupos->Listar();
    return s.str();
}





//LIsta------------------------------------------

ListaT<Grupo>* Curso::getListaGrupos()
{
    return _lisGrupos;
}

bool Curso::verficiarEspacio()
{

    return false;
}
void Curso::ingresarGrupo(Grupo* grupo) {
    if (_cupMax < _lisGrupos->contador()) {
        _lisGrupos->insertarElem(grupo);
    }
    else {
        cout << "si, aqui definitivamente deberia haber una excepcion" << endl;
    }
    
}
Grupo* Curso::operator[](int k) { // la idea es que retorne el grupo que se encuentre en la posicion dentro de los[]
    return _lisGrupos->contadorEspecifico(k);
}
