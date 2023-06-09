#include "Menu.h"

void Menu::inicio() {
	bool fin = false;
	bool ex = false;
	imprimirString("\x1b[33m Bienvenido al GYM de triatlon");

	imprimirString("Digite la Fecha en formato dia/mes/annio");
	do {
		try {
			fecha = validarFecha();
			ex = true;
		}
		catch (...) {
			imprimirString("Error con el formato de fecha (ejemplo: 15/4/23 )  << endl");
			limpiar();
		}
	} while (ex == false);
	_gym = new Gym(fecha);
	arch = new Archivos(_gym);
	arch->cargarDatos();
	while (!fin) {
		llamarMenus();	}
}


string Menu::menuPrincipal() {
	stringstream s;
	limpiarPantalla();
	  s << "\x1b[33m	   <Menu Principal>		  \x1B[37m" << endl
		<< "[1]Administracion General-------------" << endl
		<< "[2]Control de Deportista--------------" << endl
		<< "[3]Control de Cursos------------------" << endl
		<< "[4]Control de Grupo-------------------" << endl
		<< "[5]Control de Pagos-------------------" << endl
		<< "[6]Guardar Archivos y salir-----------" << endl
		<< "Digite una opcion:";

	return s.str();
}

//------------------------------------------------------------------------

//Administracion General--------------------------------------------------
string Menu::menuAdministracion() {
	stringstream s;
	  s << "\x1b[33m	   <Menu Administracion>		  \x1B[37m" << endl
		<< "[1]Nombre del Gimnasio----------------" << endl
		<< "[2]Monto de mensualidad---------------" << endl
		<< "[3]Atras----------------------------\n\n"
		<< "Digite una opcion: ";

	return s.str();

}
bool Menu::opMenuAdministracion(int op) {
	string nombre;
	int mensualidad;
	bool ex = false;
	switch (op) {
	case 1://Nombre del Gimnasio
		imprimirString("\x1b[33m <1. Administracion General > <1. Nombre del Gimnasio>  ");
		imprimirString("Ingrese el nombre del Gimnasio :");
		ignorarCin();
		nombre = recivirGetLine();
		_gym->setNombreDgym(nombre);
		enter();
		limpiarPantalla();

		break;
	case 2://Monto de mensualidad
		imprimirString("\x1b[33m <1. Administracion General>  <2. Monto de mensualidad >  ");
		imprimirString("Ingrese el Monto de mensualidad:");
		do {
			try {
				mensualidad = recivirInt();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		_gym->setMensualidadDgym(mensualidad);
		enter();
		limpiarPantalla();
		break;
	case 3: 
		limpiarPantalla();
		return true;
		break;
	default:

		break;
	};
	return false;
}
//Control  Deportistas --------------------------------------------------
string Menu::menuDeportista() {
	stringstream s;
	s << "\x1b[33m	   <Menu Deportista>		  \x1B[37m" << endl
		<< "[1]Ingreso de nuevo deportista--------" << endl
		<< "[2]Modificacion de deportista---------" << endl
		<< "[3]Listado de deportista--------------" << endl
		<< "[4]Detalle de deportista en especifico" << endl
		<< "[5]Atras------------------------------\n\n"
		<< "Digite una opcion: ";
	return s.str();
}
string Menu::subMenuListas(){
	stringstream s;
	  s << "[1]Listado general--------------------" << endl
		<< "[2]Listado de deportistas activos ----" << endl
		<< "[3]Listado de deportistas inactivos---" << endl
		<< "[4]Listado de deportistas en morosidad" << endl
		<< "[5]Atras------------------------------\n\n"
		<< "Digite una opcion: ";
	return s.str();
}

bool Menu::opMenuDeportista(int op)
{
	if (_gym->getListaCurso()->listaVacia() == true) {
		limpiar();
		imprimirString("-------------------------------------------------------------");
		imprimirString("\x1b[31mERROR: No es posible trabajar con Deportistas sin primero ingresar algun Cursos\x1B[37m");
		imprimirString("-------------------------------------------------------------");
		enter();
		op = 5;
	}
	else if (_gym->getListaCurso()->getPriemero()->getInfo()->getListaGrupos() == NULL) {
		imprimirString("-------------------------------------------------------------");
		imprimirString("\x1b[31mERROR: No es posible trabajar con Deportistas sin primero ingresar algun Grupo\x1B[37m");
		imprimirString("(Nota: Para crear un grupo es necesario tener al menus un Curso)");
		imprimirString("-------------------------------------------------------------");
		enter();
		op = 5;
	}
	int opSub = 0;
	//Deportista
	int cedula = 0;
	string nombre = "";
	string telefono = "";
	Fecha* fechaNa = NULL;
	//Ciclista
	int horasEntrenem = 0;
	double temProm = 0;
	//Corredor
	char sexo;
	double estatura = 0.0;
	//Nadador
	double masaMuscular = 0.0;
	double peso = 0.0;
	double PgrasaCorporalMC = 0.0;
	//triatlonista
	int cantPartiEnIronMan = 0;
	int canTriaGanados = 0;

	int cedulaAbuscar = 0;
	Iterador<Deportista>* iter;
	Iterador<Deportista>* iter2;
	Iterador<Expediente>* iterexp;
	Iterador<Expediente>* iter2exp;
	Expediente* ExpeAeditar = NULL;
	
	bool ex = false;
	//clientes (esto puede variar)
	Deportista* cliente = NULL;
	//Cursos y grupos
	string codCurso = "";
	string numGrup = "";
	Fecha* fechaMa = NULL; // no se si es neceario 
	stringMOD* IDcurso = NULL;
	stringMOD* IDgrupo = NULL;
	Expediente* exaux = NULL;
	switch (op) {
	case 1: // Ingreso nuevo deportista 
		imprimirString("\x1b[33m<2.Control Deportistas>  <1.Ingreso nuevo deportista>");
		do {

			imprimirString("Lista de cursos");
			imprimirString("<Codigo>\t<Curso>\t\t<Nivel>");
			imprimirString(_gym->imprimirListadoCursos());
			imprimirString("Seleccione un curso:  ");
			
				try {
					codCurso = recivirStringN();
					
					ex = true;
				}
				catch (ErrorV* e) {
					cout << e->what() << endl;
					limpiar();
				}
			} while (ex == false);
			ex = false;
			if (_gym->getListaCurso()->ExisteEspesifico(codCurso) == false) {
				imprimirString("\x1B[31m ----Ese curso no existe----");
				break; break;
			}
			
		
		imprimirString("Para dicho curso quedan los siguientes grupos disponibles: ");
		do {
			imprimirString("Seleccione un grupo:  ");
			imprimirString("<Num>\t<Dia>\t<Horario>\t<CupMax>\t<Disp>");
			imprimirString(_gym->imprimirListadoGrupo(codCurso));
			imprimirString("Digite el grupo en el que desea ser ingresado: ");
			imprimirString("O digite 'salir;' para ir atras ");

			do {
				try {
					numGrup = recivirStringN();
					ex = true;
				}
				catch (ErrorV* e) {
					cout << e->what() << endl;
					limpiar();
				}
			} while (ex == false);
			ex = false;
			if (_gym->getListaDgruposDcurso(codCurso)->ExisteEspesifico(numGrup) == false) {
				imprimirString("\x1B[31m ----Ese grupo de ese curso no existe----");
				break; break;
			}
			
			if (numGrup == "salir") {
				break;
			}
			if (_gym->verDisponivilidadGrupos(codCurso, numGrup) != true) {
				imprimirString("Ese grupo no esta disponible digite otro ");
			}
		} while (_gym->verDisponivilidadGrupos(codCurso, numGrup) != true );
		if (numGrup == "salir") {
			limpiarPantalla();
			return true;
		}

		do {
			imprimirString("Digite la fecha de matricula: ");
			do {
				try {
					fechaMa = validarFecha();
					ex = true;
				}
				catch (...) {
					imprimirString("\x1B[31m Error con el formato de fecha (ejemplo: 15/4/23 )");
					limpiar();
				}
			} while (ex == false);
			ex = false;

			if (fechaMa->operator<(*fecha)) {
				imprimirString("Digite una fecha mayor a la actual ");
			}
		} while (fechaMa->operator<(*fecha)); //fecha ma tiene que ser mayor para poder salir

		

		//deportista
		imprimirString("Cedula: ");
		do {
			try {
				cedula = recivirInt();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		}while (ex == false);
		ex = false;
		if (_gym->getListaDepor()->ExisteEspesifico(to_string(cedula)) == true) {
			imprimirString("\x1B[31m ERROR: Esa Cedula ya exsiste en el sistema");
			break; break;
		}
		imprimirString("Nombre: ");
		do {
			try {
				ignorarCin();
				nombre = recivirGetLine();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		imprimirString("Telefono: ");
		do {
			try {
				telefono = recivirString();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;

				limpiar();
			}
		}while (ex == false);
		ex = false;
		imprimirString("Fecha nacimiento: ");
		do {
			try {
				fechaNa = validarFecha();
				ex = true;
			}
			catch (...) {
				cout << "\x1B[31m Error con el formato de fecha (ejemplo: 15/4/23 ) " << endl;
				limpiar();
			}
		}while (ex == false);
		ex = false;
		//Ciclista
		imprimirString("Horas de entrenamiento: ");
		do {
			try {
				horasEntrenem = recivirDouble();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		imprimirString("Temperatura promedio al entrenar en Grados Celcius: ");
		do {
			try {
					temProm = recivirDouble();
					ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		//Corredor
		imprimirString("Sexo(H=hombre,M=mujer): ");
		do {
			try {
				sexo = recivirChar();
				if (sexo == 'M' || sexo == 'H' || sexo == 'm' || sexo == 'h') {
					ex = true; 
				}
				else {
					throw new ErrorV('c');
				}
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		imprimirString("Estatura en metros (ejemplo: 1.50cm): ");
		do {
			try {
					estatura = recivirDouble();
					ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		//Nadador
		imprimirString("Porcentaje masa corporal: ");
		do {
			try {
				masaMuscular = recivirDouble();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		}while (ex == false);
		ex = false;
		imprimirString("Peso en kg: ");
		do {
			try {
				peso = recivirDouble();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		imprimirString("Porcentaje de grasa corporal: ");
		do {
			try {
				PgrasaCorporalMC = recivirDouble();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		//triatlonista
		imprimirString("Cantidad de participaciones en Iron Man");
		do {
			try {
				cantPartiEnIronMan = recivirDouble();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		imprimirString("Cantidad de triatlones ganados:");
		do {
			try {
				canTriaGanados = recivirDouble();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		}while (ex == false);

		
	
		cliente = new Triatlonista(cedula, nombre, telefono, fechaNa, horasEntrenem, temProm, sexo, estatura, masaMuscular, peso, PgrasaCorporalMC, canTriaGanados, cantPartiEnIronMan);
		_gym->ingresarClienteAGrupos(numGrup, codCurso, cliente);

		exaux = new Expediente(cedula, nombre, telefono, fechaNa, horasEntrenem, temProm, sexo, estatura, masaMuscular, peso, PgrasaCorporalMC, canTriaGanados, cantPartiEnIronMan);
		IDcurso= new stringMOD(codCurso);
		IDgrupo= new stringMOD(numGrup);
		exaux->getlisCursosIdent()->insertarElem(IDcurso);
		exaux->getlisGruposIdent()->insertarElem(IDgrupo);

		_gym->getListaExpediente()->insertarElem(exaux);
		enter();
		limpiarPantalla();
		break;
	case 2: //Modificacion de deportista
		iter = _gym->getListaDepor()->begin();
		iter2 = _gym->getListaDepor()->end();
		
		imprimirString("\x1b[33m <2.Control Deportistas>  <2.Modificacion de deportista>");
		imprimirString("Seleccione el curso");
		imprimirString("<Codigo>\t<Curso>\t\t<Nivel>");
		imprimirString(_gym->imprimirListadoCursos());

		do {
			try {
				codCurso = recivirStringN();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		if (_gym->getListaCurso()->ExisteEspesifico(codCurso) == false) {
			imprimirString("\x1B[31m ----Ese curso no existe----");
			break; break;
		}
		imprimirString("Seleccione el grupo: ");
		imprimirString("<Num>\t<Dia>\t<Horario>\t<CupMax>\t<Disp>");
		imprimirString(_gym->imprimirListadoGrupo(codCurso));
		imprimirString("Digite el grupo en el que desea ser ingresado: ");
		do {
			try {
				numGrup = recivirStringN();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		if (_gym->getListaDgruposDcurso(codCurso)->ExisteEspesifico(numGrup) == false) {
			imprimirString("\x1B[31m ----Ese grupo de ese curso no existe----");
			break; break;
		}
		imprimirString("Cedula\t Nombre\t Telefono\t CanGrupos ");
		imprimirString(_gym->imprimirListadoDeClientesDUnGrupo(codCurso, numGrup));

		imprimirString("Cual seria la cedula del Deportista?\n");
		do {
			try {
				cedulaAbuscar = recivirInt();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		if (_gym->getListaDepor()->ExisteEspesifico(to_string(cedulaAbuscar)) == false) {
			imprimirString("\x1B[31m ERROR: Esa Cedula no existe em el sistema");
			break; break;
		}
		iterexp = _gym->getListaExpediente()->begin();
		iter2exp = _gym->getListaExpediente()->end();

		for (; iterexp->getPNodo() != iter2exp->getPNodo(); iterexp->operator++()) {
			if (iterexp->operator*()->getCedula() == cedulaAbuscar) {
				ExpeAeditar = iterexp->operator*();

			}
		}

		for (; iter->getPNodo() != iter2->getPNodo(); iter->operator++()) {
			if (iter->operator*()->getCedula() == cedulaAbuscar) {
				atualizarINFO(iter->operator*(), ExpeAeditar);

			}
		}

		
		enter();
		limpiarPantalla();
		break;
	case 3: //Listado de deportistas

		iter = _gym->getListaDepor()->begin();
		iter2 = _gym->getListaDepor()->end();
		imprimirString("\x1b[33m <2.Control Deportistas>  <3.Listado de deportistas>");
		imprimirString(subMenuListas());
		opSub = recivirInt();
		switch (opSub){
			case 1: //listado general
				imprimirString(_gym->imprimirListaClientes());
				break;
			case 2://deportistas activos
				imprimirString("-------------------------------------------");
				imprimirString("Deportistas Activos");
				imprimirString("-------------------------------------------");

				for (; iter->getPNodo() != iter2->getPNodo(); iter->operator++()) {
					if ( Cobro::EstadoDcliente(iter->getPNodo()->getInfo(), this->fecha ) == 1)
					{
						imprimirString(iter->operator*()->toString());
					}
				}
				imprimirString("---------------------Fin--------------------");
				imprimirString("-------------------------------------------");
				break;
			case 3://deportistas inactivos
				imprimirString("-------------------------------------------");
				imprimirString("Deportistas Inactivos");
				imprimirString("-------------------------------------------");

				for (; iter->getPNodo() != iter2->getPNodo(); iter->operator++()) {
					if (Cobro::EstadoDcliente(iter->getPNodo()->getInfo(), this->fecha) == 3)
					{
						imprimirString(iter->operator*()->toString());
					}
				}
				imprimirString("---------------------Fin--------------------");
				imprimirString("-------------------------------------------");
				
				break;
			case 4:// deportistas con morosidad
				imprimirString("-------------------------------------------");
				imprimirString("Deportistas con morosidad seguna la fecha de hoy");
				imprimirString("-------------------------------------------");

				for (; iter->getPNodo() != iter2->getPNodo(); iter->operator++()) {
					if (Cobro::EstadoDcliente(iter->getPNodo()->getInfo(), this->fecha) == 2)
					{
						imprimirString(iter->operator*()->toString());
					}
				}
				imprimirString("---------------------Fin--------------------");
				imprimirString("-------------------------------------------");
				
				break;
			case 5://atras
				limpiarPantalla();
				return true;
				break;
			default:
				
				break;
		}
		delete iter;
		delete iter2;
		enter();
		limpiarPantalla();
		break;
	case 4: //Detalle de deportista especificp
		iter = _gym->getListaDepor()->begin();
		iter2 = _gym->getListaDepor()->end();
		imprimirString("\x1b[33m <2.Control Deportistas>  <4.Detalle deportista especifico>");
		imprimirString("Cedula\t Nombre\t Telefono\t CanGrupos ");
		imprimirString(_gym->getListaDepor()->Listar());
		imprimirString("Cual seria la cedula del Deportista?\n");
		do {
			try {
				cedulaAbuscar = recivirInt();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);

		if (_gym->getListaDepor()->ExisteEspesifico(to_string(cedulaAbuscar)) == false) {
			imprimirString("\x1B[31m ERROR: Esa Cedula no existe en el sistema");
			break; break;
		}

		for (; iter->getPNodo() != iter2->getPNodo(); iter->operator++()) {
			if (iter->operator*()->getCedula() == cedulaAbuscar) {
				imprimirString("La infomacion de ese deportista es espesifico es: ");
				imprimirString(iter->operator*()->toString());
			}
		}
		enter();
		limpiarPantalla();
		break;
	case 5: //Atras
		limpiarPantalla();
		return true;
		break;
	default:

		break;
	};
	return false;
	delete iter;
	delete iter2;
}
//Control Cursos--------------------------------------------------------------
string Menu::menuCursos()
{
	stringstream s;
	s << "\x1b[33m	   <Menu Cursos>		  \x1B[37m" << endl
		<< "[1]Ingreso nuevo curso----------------" << endl
		<< "[2]Reporte de curso especifico--------" << endl
		<< "[3]Modificacion de curso especifico---" << endl
		<< "[5]Atras------------------------------\n\n"
		<< "Digite una opcion: ";

	return s.str();
}
bool Menu::opMenuCursos(int op)
{
	bool ex=false;
	string ident = "";
	string codCurso = "";
	string nombreCurso = "";
	string nivel = "";
	int canG = 0;
	string descripcion = "";
	Curso* curso = NULL;
	
	Iterador<Curso>* iter;
	Iterador<Curso>* iter2;


	switch (op) {
	case 1: // Ingreso nuevo curso;
		imprimirString("\x1b[33m < 3.Control Cursos> < 1.Ingreso nuevo curso >");
		imprimirString("Codigo del Curso");
		do {
			try {
				codCurso = recivirStringN();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		
		if (_gym->getListaCurso()->ExisteEspesifico(codCurso) == true) {
			imprimirString("\x1B[31m ----Ese curso ya exisiste----");
			break; break;
		}
		
		imprimirString("Nombre del Curso");
		do {
			try {
				ignorarCin();
				nombreCurso = recivirGetLine();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		imprimirString("Nivel del curso: ");
		do {
			try {
				nivel = recivirString();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		imprimirString("Cantidad de grupos: ");
		do {
			try {
				canG = recivirInt();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		imprimirString("Descripcion del curso: ");
		ignorarCin();
		descripcion = recivirGetLine();
	
		curso = new Curso(codCurso, nombreCurso, nivel, canG, descripcion);
		_gym->ingresarCursos(curso);
		enter();
		limpiarPantalla();
		break;
	case 2: //Reporte de curso específico 
		imprimirString("\x1b[33m < 3.Control Cursos> < 2.Reporte de curso especifico>\n");
		imprimirString("Listado de cursos");
		imprimirString("<Codigo>\t<Curso>\t\t<Nivel>");
		imprimirString(_gym->imprimirListadoCursos());

		imprimirString("Cual curso desea ver en especifico");
		do {
			try {
				 ident = recivirString();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		if (_gym->getListaCurso()->ExisteEspesifico(ident) == false) {
			imprimirString("\x1B[31m----Ese curso no existe----");
			break; break;
		}
		imprimirString(_gym->imprimirListaEspe(ident));
		enter();
		limpiarPantalla();
		break;
	case 3://Modificaci/n de curso específico 
		


		iter = _gym->getListaCurso()->begin();
		iter2 = _gym->getListaCurso()->end();
		imprimirString("\x1b[33m < 3.Control Cursos> < 3. Modificación de  curso especifico >");
		imprimirString("Listado de cursos");
		imprimirString("<Codigo>\t<Curso>\t\t<Nivel>");
		imprimirString(_gym->imprimirListadoCursos());

		imprimirString("Cual curso desea modificar en especifico: ");
		imprimirString("Ingrese el codigo del Curso: ");
		do {
			try {
				ident = recivirString();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		if (_gym->getListaCurso()->ExisteEspesifico(ident) == false) {
			imprimirString("\x1B[31m ----Ese curso no existe----");
			break; break;
		}
		

		for (; iter->getPNodo() != iter2->getPNodo(); iter->operator++()) {
			if (iter->operator*()->getIdent() == ident) {
				atualizarINFOcurso(iter->operator*());
				//Clona el deportista y despues los substitulle con el original para asi poder cambira la infoamcion y no violar ninun principio
			}
		}
		delete iter;
		delete iter2;
		enter();
		limpiarPantalla();
		break;
	default:
		break;
	};
	return false;
	delete iter;
	delete iter2;
}

//Control de grupos-------------------------------------------------------
string Menu::menuGrupos()
{
	stringstream s;
	s << "\x1b[33m	   <Menu Grupos>		  \x1B[37m" << endl
		<< "[1]Ingreso nuevo grupo-----------------------" << endl
		<< "[2]Modificacion de  grupo especifico---------" << endl
		<< "[3]Matricula en grupo especifico-------------" << endl
		<< "[4]Reporte de grupo especifico---------------" << endl
		<< "[5]Reporte deportistas matriculados en grupo-" << endl
		<< "[6]Cancelacion de  matricula en grupo--------" << endl
		<< "[7]Atras\n\n"
		<< "Digite una opcion: "
		<< endl;
	return s.str();
}
bool Menu::opMenuGrupos(int op)
{
	if (_gym->getListaCurso()->listaVacia() == true) {
		limpiar();
		imprimirString("-------------------------------------------------------------");
		imprimirString("\x1B[31m ERROR: No es posible trbajar con grupos sin primero ingresar algun Cursos");
		imprimirString("-------------------------------------------------------------");
		enter();
		op = 7;
	}
	string curso;
	string numCurso;
	string cedInstr = "";
	string nomInstructor = "";
	int cupMax = 0;
	Fecha* fechaInicio = NULL;
	int semDuracion = 0;
	Grupo* grupo = NULL;
	char dia;
	string horInicio = "";
	string horaFinal = "";
	int horIn = 0;
	int minIn = 0;
	int horFin = 0;
	int minFin = 0;
	bool ex = false;
	//op 3
	string cedCliente = "";
	int cedint = 0;
	string codCurso = "";
	string numGrup = "";
	Fecha* fechaMa = NULL;

	Iterador<Curso>* iterCurso;
	Iterador<Curso>* iter2Curso;
	Iterador<Grupo>* iterGrupo;
	Iterador<Grupo>* iter2Grupo;

	Iterador<Expediente>* iterexp;
	Iterador<Expediente>* iter2exp;
	Expediente* ExpeAeditar = NULL;
	stringMOD* IDcurso = NULL;
	stringMOD* IDgrupo = NULL ;


	string identDcurso = "";
	string identDgrupo = "";
	Deportista* depAux = NULL;
	switch (op) {
	case 1: // Ingreso nuevo grupo;
		imprimirString("\x1b[33m < 4.Control Grupos> < 1.Ingreso nuevo grupo>");
			
		do {
			
				imprimirString("Lista de cursos");
				imprimirString("<Codigo>\t<Curso>\t\t<Nivel>");
				imprimirString(_gym->imprimirListadoCursos());
				imprimirString("Digite el curso a elegir: ");
				imprimirString("O digite 'salir' para ir de vuelta al menu: ");

				do {
					try {
						curso = recivirStringN();
						ex = true;
					}
					catch (ErrorV* e) {
						cout << e->what() << endl;
						limpiar();
					}
				} while (ex == false);
				ex = false;
				if (_gym->getListaCurso()->ExisteEspesifico(curso) == false) {
					imprimirString("\x1B[31m ----Ese curso no existe----");
					break; break;
				}
				if (curso == "salir") {
					break;
				}
				if (_gym->verDisponivilidadCursos(curso) != true) {
					imprimirString("Ese curso no esta disponible digite otro ");

				}

		} while (_gym->verDisponivilidadCursos(curso)!=true);
		if (curso == "salir") {
			limpiarPantalla();
			return true;
		}
		//Verificar spacio
		
		//Listar cursos para elegir en cual se va aingresar el grupo
		//recorrer la lista e ingresar
		//If() {} tenemos que validar si caben mas grupos en ese curso 
		imprimirString("Cedula del instructor");
		do {
			try {
				cedInstr = recivirString();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		imprimirString("Nombre del instructor");
		do {
			try {
				ignorarCin();
				nomInstructor = recivirGetLine();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		imprimirString("Cupo maximo del grupo: ");
		do {
			try {
				cupMax = recivirInt();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		imprimirString("Fecha de inicio: ");
		do {
			try {
				fechaInicio = validarFecha();
				ex = true;
			}
			catch (...) {
				cout << "\x1B[31m Error con el formato de fecha (ejemplo: 15/4/23 ) " << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		imprimirString("Semanas de duracion: ");
		do {
			try {
				semDuracion = recivirInt();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		//Horario----------------------------------------------------------------------------------
		imprimirString("Digite el dia de la semana (l-k-m-j-v-s-d) ):");
		do {
			try {
				dia = validarDia();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		imprimirString("Digite la hora de inicio en hora militar (hora:minuto):");
		do {
			try {
				horInicio = recivirString();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;

		do {
			try {
				horIn = validarHora(horInicio);
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
			ignorarCin();
			try {
				minIn = validarMinuto(horInicio);
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;

		imprimirString("Digite la hora de finalizacion en hora militar (hora:minuto):");
		do {
			try {
				horaFinal = recivirString();
				
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;

		do {
			try {
				horFin = validarHora(horaFinal);
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		do {
			try {
				minFin = validarMinuto(horaFinal);
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		
		grupo = new Grupo(cedInstr, nomInstructor, cupMax, fechaInicio, semDuracion, dia, horIn, minIn, horFin, minFin);
		_gym->ingresarGrupo(curso, grupo);
		numGrup = to_string(grupo->getNumGrupo());
		_gym->reporteGrupoEspe(curso, numGrup );
		
		enter();
		limpiarPantalla();

		break;
	case 2: //Modificacion de  grupo especifico
		iterCurso = _gym->getListaCurso()->begin();
		iter2Curso = _gym->getListaCurso()->end();
		imprimirString("\x1b[33m < 4.Control Grupos>  <2. Modificacion  de  grupo especifico>");
		imprimirString("De cual Curso proviene el Grupo que desea modificar?: ");
		
		imprimirString("<Codigo>\t<Curso>\t\t<Nivel>");
		imprimirString(_gym->imprimirListadoCursos());
		imprimirString("Ingrese el codigo del Curso: ");

		do {
			try {
				identDcurso = recivirStringN();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		if (_gym->getListaCurso()->ExisteEspesifico(identDcurso) == false) {
			imprimirString("\x1B[31m ----Ese curso no existe----");
			break; break;
		}

		if (_gym->getListaDgruposDcurso(identDcurso) == NULL) {
			imprimirString("El curso que escogio no tiene Grupos, por lo tanto no es posible editar un Grupo");
		}
		else
		{
			imprimirString("Para dicho curso quedan los siguientes grupos disponibles: ");
			imprimirString("<Num>\t<Dia>\t<Horario>\t<CupMax>\t<Disp>");
			imprimirString(_gym->imprimirListadoGrupo(identDcurso));
			imprimirString("Digite el grupo en el que desea ser ingresado: ");
			do {
				try {
					numGrup = recivirStringN();
					ex = true;
				}
				catch (ErrorV* e) {
					cout << e->what() << endl;
					limpiar();
				}
			} while (ex == false);
			ex = false;
			if (_gym->getListaDgruposDcurso(identDcurso)->ExisteEspesifico(numGrup) == false) {
				imprimirString("\x1B[31m ----Ese grupo de ese curso no existe----");
				break; break;
			}
			iterGrupo = _gym->getListaDgruposDcurso(identDcurso)->begin();
			iter2Grupo = _gym->getListaDgruposDcurso(identDcurso)->end();
			for (; iterGrupo->getPNodo() != iter2Grupo->getPNodo(); iterGrupo->operator++()) {
				if (iterGrupo->operator*()->getIdent() == numGrup) {
					atualizarINFOgrupo(iterGrupo->operator*());
				}
			}
		}
		enter();
		limpiarPantalla();
		break;
	case 3://Matricula en grupo especifico
		cedCliente = "";
		codCurso = "";
		numGrup = "";
		imprimirString("\x1b[33m < 5.Control Grupos> < 3. Matricula en grupo especifico>");
		imprimirString("<Listado de clientes> ");
		imprimirString("Cedula\t Nombre\t Telefono\t CanGrupos ");
		imprimirString(_gym->getListaDepor()->Listar());
		do {
			try {
				cedCliente = recivirStringN();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		if (_gym->getListaDepor()->ExisteEspesifico(cedCliente) == false) {
			imprimirString("\x1B[31m ERROR: Esa Cedula no existe en el sistema");
			break; break;
		}
		imprimirString("Curso: ");
		imprimirString("<Codigo>\t<Curso>\t\t<Nivel>");
		imprimirString(_gym->imprimirListadoCursos());
		do {
			try {
				codCurso = recivirStringN();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;

		if (_gym->getListaCurso()->ExisteEspesifico(codCurso) == false) {
			imprimirString("\x1B[31m ----Ese curso no existe----");
			break; break;
		}
		imprimirString("Para ese curso existen los siguientes grupos: ");
		imprimirString("<Num>\t<Dia>\t<Horario>\t<CupMax>\t<Disp>");
		imprimirString(_gym->imprimirListadoGrupo(codCurso));
		imprimirString("Seleccione un grupo o digute 'salir' para salir: ");
		do{
			do {
				try {
					numGrup = recivirStringN();
					ex = true;
				}
				catch (ErrorV* e) {
					cout << e->what() << endl;
					limpiar();
				}
			} while (ex == false);
			ex = false;
			if (numGrup == "salir") {
				break;
			}
			if (_gym->getListaDgruposDcurso(codCurso)->ExisteEspesifico(numGrup) == false) {
				imprimirString("\x1B[31m ----Ese grupo de ese curso no existe----");
				break; break;
			}
		} while (_gym->verDisponivilidadGrupos(codCurso, numGrup) != true);
		if (numGrup == "salir") {
			limpiarPantalla();
			return true;
		}
		depAux = _gym->getListaDepor()->encontrarEsp(cedCliente);
		do {
			imprimirString("Digite la fecha de matricula: ");
			do {
				try {
					fechaMa = validarFecha();
					ex = true;
				}
				catch (...) {
					imprimirString("Error con el formato de fecha (ejemplo: 15/4/23 )");
					limpiar();
				}
			} while (ex == false);
			ex = false;

			if (fechaMa->operator<(*fecha)) {
				imprimirString("Digite una fecha mayor a la actual ");
			}
		} while (fechaMa->operator<(*fecha)); //fecha ma tiene que ser mayor para poder salir

		IDcurso = new stringMOD(codCurso);
		IDgrupo = new stringMOD(numGrup);
		iterexp = _gym->getListaExpediente()->begin();
		iter2exp = _gym->getListaExpediente()->end();

		cedint = stoi(cedCliente);
		for (; iterexp->getPNodo() != iter2exp->getPNodo(); iterexp->operator++()) {
			if (iterexp->operator*()->getCedula() == cedint) {
				ExpeAeditar = iterexp->operator*();
				if (ExpeAeditar->getlisCursosIdent()->contador() < 4) {
					ExpeAeditar->getlisCursosIdent()->insertarElem(IDcurso);
					ExpeAeditar->getlisGruposIdent()->insertarElem(IDgrupo);
				}
				else {
					imprimirString("No es posible matricular mas  de 4 cursos ");
					break;
				}
			}
		}

		_gym->ingresarClienteAGrupos(numGrup, codCurso, depAux);
		enter();
		limpiarPantalla();
		break;
	case 4: //Reporte de grupo especifico 
		imprimirString("\x1b[33m < 5.Control Grupos> < 4.Reporte de grupo especifico >");
		codCurso = "";
		numGrup = "";
		imprimirString("<Codigo>\t<Curso>\t\t<Nivel>");
		imprimirString(_gym->imprimirListadoCursos());
		imprimirString("En cual curso se encuentra el grupo?");
		do {
			try {
				codCurso = recivirStringN();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		if (_gym->getListaCurso()->ExisteEspesifico(codCurso) == false) {
			imprimirString("\x1B[31m ----Ese curso no existe----");
			break; break;
		}
		imprimirString("<Num>\t<Dia>\t<Horario>\t<CupMax>\t<Disp>");
		imprimirString(_gym->imprimirListadoGrupo(codCurso));
		imprimirString("Cual grupo desea ver? ");
		do {
			try {
				numGrup = recivirStringN();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		if (_gym->getListaDgruposDcurso(codCurso)->ExisteEspesifico(numGrup) == false) {
			imprimirString("\x1B[31m ----Ese grupo de ese curso no existe----");
			break; break;
		}
		imprimirString(_gym->reporteGrupoEspe(codCurso, numGrup));
		enter();
		limpiar();
		limpiarPantalla();
		break;
	case 5: //Reporte deportistas matriculados en grupo
		imprimirString("\x1b[33m < 5.Control Grupos> < 5. Reporte deportistas matriculados por grupo>");
		imprimirString("Seleccione un curso");
		imprimirString("<Codigo>\t<Curso>\t\t<Nivel>");
		imprimirString(_gym->imprimirListadoCursos());

		do {
			try {
				codCurso = recivirStringN();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		if (_gym->getListaCurso()->ExisteEspesifico(codCurso) == false) {
			imprimirString(" \x1B[31m ----Ese curso no existe----");
			break; break;
		}
		imprimirString("<Num>\t<Dia>\t<Horario>\t<CupMax>\t<Disp>");
		imprimirString(_gym->imprimirListadoGrupo(codCurso));
		imprimirString("Seleccione un grupo: ");
		do {
			try {
				numGrup = recivirStringN();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;


		if (_gym->getListaDgruposDcurso(codCurso)->ExisteEspesifico(numGrup) == false) {
			imprimirString("\x1B[31m ----Ese grupo de ese curso no existe----");
			break; break;
		}
		imprimirString(_gym->imprimirClientesDeUnGrupo(codCurso,numGrup));
		enter();
		limpiarPantalla();
		break;
	case 6://Cancelacion de  matricula en grupo
		imprimirString("\x1b[33m < 5.Control Grupos>  <6. Cancelacion de  matricula en grupo>");
		imprimirString("Seleccione un curso");
		imprimirString("<Codigo>\t<Curso>\t\t<Nivel>");
		imprimirString(_gym->imprimirListadoCursos());

		do {
			try {
				codCurso = recivirStringN();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		if (_gym->getListaCurso()->ExisteEspesifico(codCurso) == false) {
			imprimirString("\x1B[31m ----Ese curso no existe----");
			break; break;
		}
		imprimirString("<Num>\t<Dia>\t<Horario>\t<CupMax>\t<Disp>");
		imprimirString(_gym->imprimirListadoGrupo(codCurso));
		imprimirString("Seleccione un grupo: ");
		do {
			try {
				numGrup = recivirString();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		if (_gym->getListaDgruposDcurso(codCurso)->ExisteEspesifico(numGrup) == false) {
			imprimirString("\x1B[31m ----Ese grupo de ese curso no existe----");
			break; break;
		}
		imprimirString("<Listado de clientes dentro del grupo> ");
		imprimirString("Cedula\t Nombre\t Telefono\t CanGrupos ");
		imprimirString(_gym->imprimirListadoDeClientesDUnGrupo(codCurso, numGrup));
		imprimirString("Digite la cedula del cliente que desea eliminar?");
		do {
			try {
				cedCliente = recivirString();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;

		if (_gym->getListaDepor()->ExisteEspesifico(cedCliente) == false) {
			imprimirString("\x1B[31m ERROR: Esa Cedula no existe en el sistema");
			break; break;
		}
		IDcurso = new stringMOD(codCurso);
		IDgrupo = new stringMOD(numGrup);
		cedint = stoi(cedCliente);
		iterexp = _gym->getListaExpediente()->begin();
		iter2exp = _gym->getListaExpediente()->end();

		for (; iterexp->getPNodo() != iter2exp->getPNodo(); iterexp->operator++()) {
			if (iterexp->operator*()->getCedula() == cedint) {
				ExpeAeditar = iterexp->operator*();
				ExpeAeditar->getlisCursosIdent()->eliminarEspe(codCurso);
				ExpeAeditar->getlisGruposIdent()->eliminarEspe(numGrup);
				if (ExpeAeditar->getlisCursosIdent()->contador() == 0) {
					_gym->getListaExpediente()->eliminarEspe(cedCliente);
				}
			}
		}


		_gym->cancelarMatricula(codCurso, numGrup, cedCliente);
		enter();
		limpiarPantalla();
		break;
	case 7:
		limpiarPantalla();
		return true;
		break;
	default:

		break;
	}
	return false;
}
//Control Pagos-------------------------------------------------------
string Menu::menuPagos()
{
	stringstream s;
	s << "\x1b[33m	   <Menu Pagos>		  \x1B[37m" << endl
		<< "[1]Registro nuevo de pago-------------" << endl
		<< "[2]Reporte de pagos por deportista----" << endl
		<< "[3]Atras------------------------------\n\n"
		<< "Digite una opcion: "
		<< endl;
	return s.str();
}

bool Menu::opMenuPagos(int op)
{
	if (_gym->getMensualidadDgym() == 0) {
		imprimirString("-------------------------------------------------------------");
		imprimirString("\x1B[31m ERROR: La mensualidad del gym no se a definido, lo cual es indispensable");
		imprimirString("-------------------------------------------------------------");
		enter();
		op = 3;
	}
	else if (_gym->getListaCurso()->listaVacia() == true) {
		limpiar();
		imprimirString("-------------------------------------------------------------");
		imprimirString("\x1B[31m ERROR: No es posible trabajar con Deportistas sin primero ingresar algun Cursos");
		imprimirString("-------------------------------------------------------------");
		enter();
		op = 3;
	}
	else if (_gym->getListaCurso()->getPriemero()->getInfo()->getListaGrupos() == NULL) {
		imprimirString("-------------------------------------------------------------");
		imprimirString("\x1B[31m ERROR: No es posible trabajar con Deportistas sin primero ingresar algun Grupo");
		imprimirString("(Nota: Para crear un grupo es necesario tener al menus un Curso)");
		imprimirString("-------------------------------------------------------------");
		enter();
		op = 3;
	}

	Fecha* fechAux = NULL;
	Fecha* fechAux2 = new Fecha(0,0,0);
	int cedulAbuscar = 0;
	string codCurso = "";
	string numGrup = "";
	bool ex = false;
	Iterador<Deportista>* iter;
	Iterador<Deportista>* iter2;
	Iterador<Expediente>* iterexp;
	Iterador<Expediente>* iter2exp;
	Expediente* ExpeAeditar = NULL;


	switch (op) {
	case 1: // Registro nuevo de pago\n"
		iter = _gym->getListaDepor()->begin();
		iter2 = _gym->getListaDepor()->end();
		imprimirString("-------------------------------------------------------------");
		imprimirString("\x1b[33m <5.Control  Pagos> <1.Registro de nuevo  pago>");
		imprimirString("-------------------------------------------------------------");
		imprimirString("En cual curso se encuentra el deportista que desa realizar el pago?");
		imprimirString("<Codigo>\t<Curso>\t\t<Nivel>");
		imprimirString(_gym->imprimirListadoCursos());

		do {
			try {
				codCurso = recivirStringN();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		if (_gym->getListaCurso()->ExisteEspesifico(codCurso) == false) {
			imprimirString("\x1B[31m ----Ese curso no existe----");
			break; break;
		}
		
		imprimirString("Seleccione el grupo: ");
		imprimirString("<Num>\t<Dia>\t<Horario>\t<CupMax>\t\t<Disp>");
		imprimirString(_gym->imprimirListadoGrupo(codCurso));
		imprimirString("Digite el grupo en el que desea ser ingresado: ");
		do {
			try {
				numGrup = recivirStringN();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		if (_gym->getListaDgruposDcurso(codCurso)->ExisteEspesifico(numGrup) == false) {
			imprimirString("\x1B[31m ----Ese grupo de ese curso no existe----");
			break; break;
		}

		imprimirString("Cedula\t Nombre\t Telefono\t CanGrupos ");
		imprimirString("Deportistas disponibles en este grupo para realisar el pago: ");
		imprimirString(_gym->imprimirListadoDeClientesDUnGrupo(codCurso, numGrup));
		imprimirString("Cedula\t Nombre\t Telefono\t CanGrupos ");
		imprimirString("Cedula del Cliente: ");
		do {
			try {

				cedulAbuscar = recivirInt();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		if (_gym->getListaDepor()->ExisteEspesifico(to_string(cedulAbuscar)) == false) {
			imprimirString("\x1B[31m ERROR: Esa Cedula no existe en el sistema");
			break; break;
		}

		iterexp = _gym->getListaExpediente()->begin();
		iter2exp = _gym->getListaExpediente()->end();

		for (; iterexp->getPNodo() != iter2exp->getPNodo(); iterexp->operator++()) {
			if (iterexp->operator*()->getCedula() == cedulAbuscar) {
				ExpeAeditar = iterexp->operator*();

			}
		}


		for (; iter->getPNodo() != iter2->getPNodo(); iter->operator++()) {
			if (iter->operator*()->getCedula() == cedulAbuscar) {
				fechAux = Cobro::getFechaDeultimoPago(iter->operator*(), this->fecha, _gym->getMensualidadDgym());
				fechAux2->setDia(fechAux->getDia());
				fechAux2->setMes(fechAux->getMes());
				fechAux2->setAno(fechAux->getAno());
				if (fechAux2->getDia() != 0 && fechAux2->getMes() != 0 && fechAux2->getAno() != 0) {
					iter->operator*()->setFechaDeultimoPago(fechAux2);
					ExpeAeditar->getlisFecha()->insertarElem(fechAux2);
					imprimirString("");
					imprimirString2("ESTE MENSAJE CONFIRMA EL REGISTRO DE UN NUEVO PAGO DE PARTE DEL CLIENTE: ");
					imprimirInt(cedulAbuscar);
				}
				else
				{
					imprimirString("Nota de Confirmaccion: NO SE REALIZO NINGUN PAGO ");
				}

			}
		}
		//listar los cursos con su codigo 
		break;
	case 2:
		iter = _gym->getListaDepor()->begin();
		iter2 = _gym->getListaDepor()->end();
		imprimirString("\x1b[33m <5.Control  Pagos> <2.Reporte de pagos por deportista>");
		imprimirString("Cedula del Cliente: ");
		do {
			try {

				cedulAbuscar = recivirInt();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);

		if (_gym->getListaDepor()->ExisteEspesifico(to_string(cedulAbuscar)) == false) {
			imprimirString("\x1B[31m ERROR: Esa Cedula no existe en el sistema");
			break; break;
		}

		for (; iter->getPNodo() != iter2->getPNodo(); iter->operator++()) {
			if (iter->operator*()->getCedula() == cedulAbuscar) {
				imprimirString("A continuación se detalla el historial de pagos: ");
				if (iter->operator*()->getFechaDeultimoPago() != NULL) {
					imprimirString(iter->operator*()->imprimirPAGOS(_gym->getMensualidadDgym()));
				}
				else {
					imprimirString("{Este cliente esta [inactivo], por lo que no se tiene regitrado un pago reciente}");
				}
			}
		}
		break;
	case 3: //Cancelar
		limpiarPantalla();
		return true;

		break;
	default:

		break;
	}

	return false;
}


void Menu::atualizarINFO(Deportista* depAactaulizar, Expediente* expeCon)
{
	Deportista* Clon = depAactaulizar;

	int opSub = 0;
	//Deportista
	int cedula = 0;
	string nombre = "";
	string telefono = "";
	Fecha* fechaNa = NULL;
	//Ciclista
	int horasEntrenem = 0;
	double temProm = 0;
	//Corredor
	char sexo;
	double estatura = 0.0;
	//Nadador
	double masaMuscular = 0.0;
	double peso = 0.0;
	double PgrasaCorporalMC = 0.0;
	//triatlonista
	int cantPartiEnIronMan = 0;
	int canTriaGanados = 0;
	bool ex = false;
	int op = 0;

		imprimirString("Actualisando informacion de Deportista");
		imprimirString(QueQuiereEditarTri());
		do {
			try {
				op = recivirInt();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		switch (op)
		{
		case 1:		
		imprimirString("Cedula: ");
		do {
			try {
				cedula = recivirInt();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		if (_gym->getListaDepor()->ExisteEspesifico(to_string(cedula)) == true) {
			imprimirString("\x1B[31m ERROR: Esa Cedula ya existe en el sistema");
			break; break;
		}
		Clon->setCedula(cedula);
		expeCon->setCedula(cedula);
		break;
		case 2:
		imprimirString("Nombre: ");
		do {
			try {
				ignorarCin();
				nombre = recivirGetLine();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		Clon->setNombre(nombre);
		expeCon->setNombre(nombre);
		break;
		case 3:
		imprimirString("Telefono: ");
		do {
			try {
				telefono = recivirString();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;

				limpiar();
			}
		} while (ex == false);
		ex = false;
		Clon->setTelefono(telefono);
		expeCon->setTelefono(telefono);
		break;
		case 4:
		imprimirString("Fecha nacimiento: ");
		do {
			try {
				fechaNa = validarFecha();
				ex = true;
			}
			catch (...) {
				cout << "\x1B[31m Error con el formato de fecha (ejemplo: 15/4/23 ) " << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		Clon->setFechaNacimiento(fechaNa);
		expeCon->setFechaNacimiento(fechaNa);
		break;
		case 5:
		//Ciclista
		imprimirString("Horas de entrenamiento: ");
		do {
			try {
				horasEntrenem = recivirDouble();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		Clon->setHorasDeEntrenamiento(horasEntrenem);
		expeCon->setHorasDeEntrenamiento(horasEntrenem);
		break;
		case 6:
		imprimirString("Temperatura promedio al entrenar en Grados Celcius: ");
		do {
			try {
				temProm = recivirDouble();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		Clon->setTempPromedio(temProm);
		expeCon->setTempPromedio(temProm);
		break;
		case 7:
		//Corredor
		imprimirString("Sexo(H=hombre,M=mujer): ");
		do {
			try {
				sexo = recivirChar();
				if (sexo == 'M' || sexo == 'H' || sexo == 'm' || sexo == 'h') {
					ex = true;
				}
				else {
					throw new ErrorV('c');
				}
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		Clon->setSexo(sexo);
		expeCon->setSexo(sexo);
		break;
		case 8:
		imprimirString("Estatura en metros (ejemplo: 1.50cm): ");
		do {
			try {
				estatura = recivirDouble();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		Clon->setEstatura(estatura);
		expeCon->setEstatura(estatura);
		break;
		case 9:
		//Nadador
		imprimirString("Porcentaje masa corporal: ");
		do {
			try {
				masaMuscular = recivirDouble();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		Clon->setMasaMuscular(masaMuscular);
		expeCon->setMasaMuscular(masaMuscular);
		break;
		case 10:
		imprimirString("Peso en kg: ");
		do {
			try {
				peso = recivirDouble();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		Clon->setPeso(peso);
		expeCon->setPeso(peso);
		break;
		case 11:
		imprimirString("Porcentaje de grasa corporal: ");
		do {
			try {
				PgrasaCorporalMC = recivirDouble();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		Clon->setPorcGrasaCorporal(PgrasaCorporalMC);
		expeCon->setPorcGrasaCorporal(PgrasaCorporalMC);
		break;
		case 12:
		//triatlonista
		imprimirString("Cantidad de participaciones en Iron Man");
		do {
			try {
				cantPartiEnIronMan = recivirDouble();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		Clon->setCanPartIronMan(cantPartiEnIronMan);
		expeCon->setCanPartIronMan(cantPartiEnIronMan);
		break;
		case 13:
		imprimirString("Cantidad de triatlones ganados:");
		do {
			try {
				canTriaGanados = recivirDouble();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		Clon->setCanTriatGanador(canTriaGanados);
		expeCon->setCanTriatGanador(canTriaGanados);
		break;

		default:break;
		}

		
		enter();
		
}


string Menu::QueQuiereEditarTri()
{
	stringstream s;
	s << "\x1b[33m	   <Que quiere editar>		  \x1B[37m" << endl
		<< "[1]Editar Cedula-----------------------" << endl
		<< "[2]Editar Nombre---------" << endl
		<< "[3]Editar telefono-------------" << endl
		<< "[4]Editar Fecha de Nacimento---------------" << endl
		<< "[5]Editar Horas de Entrenamiento" << endl
		<< "[6]Editar Temperatura Promedio--------" << endl
		<< "[7]Editar Sexo--------" << endl
		<< "[8]Editar Estatura--------" << endl
		<< "[9]Editar Masa Muscular--------" << endl
		<< "[10]Editar peso --------" << endl
		<< "[11]Editar Porecentaje de grasa Corporal --------" << endl
		<< "[12]Editar Cantidad de Triatlones Ganados--------" << endl
		<< "[13]Editar Cantidad participaciones en IronMan--------" << endl
		<< "[14]Atras\n\n"
		<< "Digite una opcion: "
		<< endl;
	return s.str();
}

void Menu::atualizarINFOcurso(Curso* original)
{
	string ident = "";
	string codCurso = "";
	string nombreCurso = "";
	string nivel = "";
	int canG = 0;
	string descripcion = "";
	bool ex = false;
	int op = 0;
	Curso* Clon = original;
	imprimirString("Actualisando informacion de Curso");
	imprimirString(QueQuiereEditarCurso());
	do {
		try {
			op = recivirInt();
			ex = true;
		}
		catch (ErrorV* e) {
			cout << e->what() << endl;
			limpiar();
		}
	} while (ex == false);
	ex = false;
	switch (op)
	{
	case 1:

		imprimirString("Codigo del Curso");
		do {
			try {
				codCurso = recivirStringN();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		if (_gym->getListaCurso()->ExisteEspesifico(codCurso) == true) {
			imprimirString("\x1B[31m ERROR:ese codigo de curso ya exisite");
			break; break;
		}
		Clon->setIdent(codCurso);
		break;
	case 2:
		imprimirString("Nombre del Curso");
		do {
			try {
				ignorarCin();
				nombreCurso = recivirGetLine();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;

		Clon->setNombreDcurso(nombreCurso);
		break;
	case 3:
		imprimirString("Nivel del curso: ");
		do {
			try {
				nivel = recivirString();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;

		Clon->setNivel(nivel);
		break;
	case 4:
		imprimirString("Cantidad de grupos: ");
		do {
			try {
				canG = recivirInt();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		Clon->setCanGrup(canG);
		break;
	case 5:
		imprimirString("Descripcion del curso: ");
		ignorarCin();
		descripcion = recivirGetLine();

		ex = false;
		Clon->setDescripcion(descripcion);
		break;

	default:
		break;
	}

}

void Menu::atualizarINFOgrupo(Grupo* original)
{
	string cedInstr = "";
	string nomInstructor = "";
	int cupMax = 0;
	Fecha* fechaInicio = NULL;
	int semDuracion = 0;
	Grupo* grupo = NULL;
	char dia;
	string horInicio = "";
	string horaFinal = "";
	int horIn = 0;
	int minIn = 0;
	int horFin = 0;
	int minFin = 0;
	bool ex = false;
	int op = 0;
	
	Grupo* Clon = original;
	imprimirString("Actualisando informacion de Grupo");
	imprimirString(QueQuiereEditarGrupo());
	do {
		try {
			op = recivirInt();
			ex = true;
		}
		catch (ErrorV* e) {
			cout << e->what() << endl;
			limpiar();
		}
	} while (ex == false);
	ex = false;
	switch (op)
	{
		case 1:

			imprimirString("Cedula del instructor");
			do {
				try {
					cedInstr = recivirString();
					ex = true;
				}
				catch (ErrorV* e) {
				cout << e->what() << endl;
					limpiar();
				}	
			} while (ex == false);
			ex = false;
			Clon->setCedInstructor(cedInstr);
		break;
		case 2:
			imprimirString("Nombre del instructor");
			do {
				try {
					ignorarCin();
					nomInstructor = recivirGetLine();
				ex = true;
				}
				catch (ErrorV* e) {
					cout << e->what() << endl;
					limpiar();
				}
			} while (ex == false);
			ex = false;
			Clon->setNomInstructo(nomInstructor);
		break;
		case 3:
			imprimirString("Cupo maximo del grupo: ");
			do {
				try {
					cupMax = recivirInt();
					ex = true;
				}
				catch (ErrorV* e) {
					cout << e->what() << endl;
					limpiar();
				}
			} while (ex == false);
			ex = false;
			Clon->setcupMax(cupMax);
		break;
		case 4:
			imprimirString("Fecha de inicio: ");
			do {
				try {
					fechaInicio = validarFecha();
					ex = true;
				}
				catch (...) {
					cout << "\x1B[31m Error con el formato de fecha (ejemplo: 15/4/23 ) " << endl;
					limpiar();
				}
			} while (ex == false);
			ex = false;
			Clon->setFechaInicio(fechaInicio);
		break;
		case 5:
			imprimirString("Semanas de duracion: ");
			do {
				try {
					semDuracion = recivirInt();
					ex = true;
				}
				catch (ErrorV* e) {
					cout << e->what() << endl;
						limpiar();
				}
			} while (ex == false);
			ex = false;
			Clon->setSemDuracion(semDuracion);
		break;
		case 6:
		//Horario----------------------------------------------------------------------------------
			imprimirString("Digite el dia de la semana (l-k-m-j-v-s-d) ):");
			do {
				try {
					dia = validarDia();
	
					ex = true;
				}
				catch (ErrorV* e) {
					cout << e->what() << endl;
					limpiar();
				}
			} while (ex == false);
			ex = false;
			Clon->setDiaSem(dia);
		break;
		case 7:
			imprimirString("Digite la hora de inicio en hora militar (hora:minuto):");
			do {
				try {
					horInicio = recivirString();
					ex = true;
				}
				catch (ErrorV* e) {
					cout << e->what() << endl;
					limpiar();
				}
			} while (ex == false);
			ex = false;
			do {
				try {
					horIn = validarHora(horInicio);
					ex = true;
				}
				catch (ErrorV* e) {
					cout << e->what() << endl;
					limpiar();
				}
			} while (ex == false);
			ex = false;
			Clon->setHoraInicio(horIn);
			do {
				try {
					minIn = validarMinuto(horInicio);
					ex = true;
				}
				catch (ErrorV* e) {
					cout << e->what() << endl;
					limpiar();
				}
			} while (ex == false);
			ex = false;
			Clon->setMinutoInicio(minIn);
		break;


		case 8:
			imprimirString("Digite la hora de finalizacion en hora militar (hora:minuto):");
			do {
				try {
					horaFinal = recivirString();
						
					ex = true;
				}
				catch (ErrorV* e) {
					cout << e->what() << endl;
					limpiar();
				}
			} while (ex == false);
			ex = false;

			do {
				try {
					horFin = validarHora(horaFinal);
					ex = true;
				}
				catch (ErrorV* e) {
					cout << e->what() << endl;
					limpiar();
				}
			} while (ex == false);
			ex = false;
			Clon->setHoraFinal(horFin);
			do {
				try {
					minFin = validarMinuto(horaFinal);
					ex = true;
				}
				catch (ErrorV* e) {
					cout << e->what() << endl;
					limpiar();
				}
			} while (ex == false);
			ex = false;
			Clon->setMinutoFinal(minFin);
		break;
		default:
		break;
	}
	
}

string Menu::QueQuiereEditarCurso()
{
	stringstream s;
	s << "\x1b[33m	   <Que quiere editar>		  \x1B[37m" << endl
		<< "[1]Editar Codigo de Curso-----------------------" << endl
		<< "[2]Editar Nombre de Curso---------" << endl
		<< "[3]Editar Nivel de Curso-------------" << endl
		<< "[4]Editar CupoMaximo de Curso---------------" << endl
		<< "[5]Editar Decripcion de Curso" << endl
		<< "[14]Atras\n\n"
		<< "Digite una opcion: "
		<< endl;
	return s.str();
}

string Menu::QueQuiereEditarGrupo()
{
	stringstream s;
	s << "\x1b[33m	   <Que quiere editar>		  \x1B[37m" << endl
		<< "[1]Editar Cedula de Instructor-----------------------" << endl
		<< "[2]Editar Nombre de Instructor---------" << endl
		<< "[3]Editar CupoMaximo-------------" << endl
		<< "[4]Editar Fecha de Inicio---------------" << endl
		<< "[5]Editar Duracion" << endl
		<< "[6]Editar Dia de la Semana en la que se lleva a cabo--------" << endl
		<< "[7]Editar Hora de Inicio--------" << endl
		<< "[8]Editar Hora de Finalizacion--------" << endl
		<< "[9]Atras\n\n"
		<< "Digite una opcion: "
		<< endl;
	return s.str();
}

bool Menu::llamarMenus() {
	int op = 0;
	int opE = 0;
	bool ex = false;
	
	imprimirString(menuPrincipal());
	do {
		try {
			op = recivirInt();
			ex = true;
		}
		catch (ErrorV* e) {
			cout << e->what() << endl;
			limpiar();
		}
	} while (ex == false);
	ex = false;

	switch (op) {
	case 1://Administracion General 
		limpiarPantalla();
		imprimirString(menuAdministracion());
		do {
			try {
				op = recivirInt();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		opMenuAdministracion(op);
		enter();

		break;
	case 2://Control de Deportistas
		limpiarPantalla();
		imprimirString(menuDeportista());
		do {
			try {
				op = recivirInt();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		opMenuDeportista(op);
		enter();

		break;
	case 3://Control de Cursos
		limpiarPantalla();
		imprimirString(menuCursos());
		do {
			try {
				op = recivirInt();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		opMenuCursos(op);
		enter();

		break;
	case 4://Control de Grupos
		limpiarPantalla();
		imprimirString(menuGrupos());
		do {
			try {
				op = recivirInt();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		opMenuGrupos(op);
		enter();

		break;
	case 5://Control Pagos
		limpiarPantalla();
		imprimirString(menuPagos());
		do {
			try {
				op = recivirInt();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		opMenuPagos(op);
		enter();
		break;
	case 6: //Guardar en Archivos y salir
		limpiarPantalla();
		imprimirString("Buen dia...");
		arch = new Archivos(_gym);
		arch->guardarDatos();
		//limpiar();
		exit(0);
		return true;
		//Completar Archivos al 100%
		//Y despues "delete()" cuando ya leyo y gurado TODO
		break;
	default:
		break;
	}
	return false;

}


