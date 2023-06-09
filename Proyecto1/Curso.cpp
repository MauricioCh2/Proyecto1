#include"Curso.h"
Curso::Curso(string cod, string nomC, string niv, int canGrupos, string desc)
{
    _codCurso = cod;
    _nombreCurso = nomC;
    _nivel = niv;
    _canGrupos = canGrupos;
    _descripcion = desc;
    _numGrupo = 0;

    _lisGrupos = new ListaT<Grupo>;

}
//probablemente eliminemos este 

Curso::~Curso() {
    delete _lisGrupos;
}
void Curso::setIdent(string i)
{
    _codCurso = i;
}
void Curso::setNombreDcurso(string s)
{
    _nombreCurso = s;
}
void Curso::setDescripcion(string d) {
    _descripcion = d;
}
void Curso::setNivel(string n) {
    _nivel = n;
}
void Curso::setCanGrup(int c) {
    _canGrupos = c;
}


string Curso::getIdent()
{
    return _codCurso;
}
string Curso::getNombreDcurso()
{
    return _nombreCurso;
}
string Curso::getDescripcion() {
    return _descripcion;
}
string Curso::getNivel() {
    return _nivel;
}
int Curso::getCanGrup() {
    return _canGrupos;
}


string Curso::Listar()
{
    stringstream s;
    s << _codCurso << "\t\t" << _nombreCurso << "\t\t" << _nivel << endl;
    return s.str();
}
string Curso::toString() {
    stringstream s;
    s << "-------------------------------CURSO----------------------------" << endl;
    s << "\tNombre del curso:................" << _nombreCurso << endl;
    s << "\tNivel del curso:................." << _nivel << endl;
    s << "\tCantidad  maxima de grupos:......" << _canGrupos << endl;
    s << "\tCantidad  de grupos disponibles:.";
    if (_lisGrupos != NULL) {
        s << _canGrupos - _lisGrupos->contador() << endl;
    }
    else {
        s << _canGrupos << endl;
    } 
    s << "\tDescripcion:....................." << _descripcion << endl;
    s << "\tDetalles de grupos abiertos:" << endl;
    if (_lisGrupos->contador()!=0) {
        s << "<Num>\t<Dia>\t<Horario>\t<CupMax>\t<Disp>" << endl;
        s << _lisGrupos->Listar();
    }
    else {
        s << "\tNo hay grupos " << endl;
    }
   
    s << "----------------------------------------------------------------" << endl;

    return s.str();
}





//LIsta------------------------------------------

void Curso::setListaGrupos(ListaT<Grupo>* l)
{
    _lisGrupos = l;
}

ListaT<Grupo>* Curso::getListaGrupos()
{
    return _lisGrupos;
}

bool Curso::verficarEspacio()
{
   
    if (_lisGrupos!=NULL) {
        if (_lisGrupos->contador() == _canGrupos) {
          
            return false;
        }
        if (_lisGrupos->contador() < _canGrupos) {
            return true;
        }
    }
   
    return false;
}
bool Curso::ingresarGrupo(Grupo* grupo) {
   
        _numGrupo = _numGrupo++;
        _lisGrupos->insertarElem(grupo);
        _lisGrupos->contador();
        grupo->setnumGrupo(_numGrupo);
        grupo->setNombreCurso(_nombreCurso);
        grupo->setCodCursoPertenece(_codCurso);
        return true;
}
Grupo* Curso::operator[](int k) { // la idea es que retorne el grupo que se encuentre en la posicion dentro de los[]
    return _lisGrupos->contadorEspecifico(k);
}
