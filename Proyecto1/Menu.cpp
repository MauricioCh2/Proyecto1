#include "Menu.h"
Fecha* Menu::getFechaActual()
{
	return this->fecha;
}
void Menu::inicio() {
	_gym = new Gym();
	bool fin = false;
	bool ex = false;
	imprimirString("Bienvenido al GYM de triatlon");

	imprimirString("Digite la Fecha en formato dia/mes/annio");
	do {
		try {
			fecha = validarFecha();
			ex = true;
		}
		catch (...) {
			cout << "Error con el formato de fecha (ejemplo: 15/4/23 ) " << endl;
			limpiar();
		}
	} while (ex == false);
	//cout<<fecha->toString()<< "prueba ";
	Fecha* f1 = new Fecha(1, 4, 23);
	Deportista* c1 = new Triatlonista(111, "a", "1", f1, 1, 23, 'h', 1.10, 10, 10, 10, 1, 1);
	Fecha* f2 = new Fecha(1, 4, 23);
	Deportista* c2 = new Triatlonista(222, "a", "1", f2, 1, 23, 'h', 1.10, 10, 10, 10, 1, 1);
	Fecha* f3 = new Fecha(1, 4, 23);
	Deportista* c3 = new Triatlonista(333, "a", "1", f3, 1, 23, 'h', 1.10, 10, 10, 10, 1, 1);
	Fecha* f4 = new Fecha(30, 3, 23);
	Deportista* c4 = new Triatlonista(444, "a", "1", f4, 1, 23, 'h', 1.10, 10, 10, 10, 1, 1);
	Fecha* f5 = new Fecha(30, 3, 23);
	Deportista* c5 = new Triatlonista(555, "a", "1", f5, 1, 23, 'h', 1.10, 10, 10, 10, 1, 1);
	Fecha* f6 = new Fecha(1, 1, 23);
	Deportista* c6 = new Triatlonista(666, "a", "1", f6, 1, 23, 'h', 1.10, 10, 10, 10, 1, 1);
	Fecha* f7 = new Fecha(1, 1, 23);
	Deportista* c7 = new Triatlonista(777, "a", "1", f7, 1, 23, 'h', 1.10, 10, 10, 10, 1, 1);
	Fecha* f8 = new Fecha(1, 1, 23);
	Deportista* c8 = new Triatlonista(888, "a", "1", f8, 1, 23, 'h', 1.10, 10, 10, 10, 1, 1);
	Fecha* f9 = new Fecha(1, 1, 23);
	Deportista* c9 = new Triatlonista(999, "a", "1", f9, 1, 23, 'h', 1.10, 10, 10, 10, 1, 1);
	Fecha* f10 = new Fecha(1, 1, 23);
	Deportista* c10 = new Triatlonista(100, "a", "1", f10, 1, 23, 'h', 1.10, 10, 10, 10, 1, 1);
	Fecha* f11 = new Fecha(1, 1, 23);
	Deportista* c11 = new Triatlonista(000, "a", "1", f11, 1, 23, 'h', 1.10, 10, 10, 10, 1, 1);
	c1->setFechaDeultimoPago(f1);
	c2->setFechaDeultimoPago(f2);
	c3->setFechaDeultimoPago(f3);
	c4->setFechaDeultimoPago(f4);
	c5->setFechaDeultimoPago(f5);

	c6->setFechaDeultimoPago(f6);
	c7->setFechaDeultimoPago(f7);
	c8->setFechaDeultimoPago(f8);
	c9->setFechaDeultimoPago(f9);
	//c10 Inactivo
	//c11 Inactivo


	_gym->ingresarListaClientes(c1);
	_gym->ingresarListaClientes(c2);
	_gym->ingresarListaClientes(c3);
	_gym->ingresarListaClientes(c4);
	_gym->ingresarListaClientes(c5);
	_gym->ingresarListaClientes(c6);
	_gym->ingresarListaClientes(c7);
	_gym->ingresarListaClientes(c8);
	_gym->ingresarListaClientes(c9);
	_gym->ingresarListaClientes(c10);
	_gym->ingresarListaClientes(c11);

	while (!fin) {
		llamarMenus();
	}
}


string Menu::menuPrincipal() {
	stringstream s;
	  s << "	   <Menu Principal>		  " << endl
		<< "[1]Administracion General-------------" << endl
		<< "[2]Control de Deportista--------------" << endl
		<< "[3]Control de Cursos------------------" << endl
		<< "[4]Control de Grupo-------------------" << endl
		<< "[5]Control de Pagos-------------------" << endl
		<< "[5]Guardar Archivos y salir-----------" << endl
		<< "Digite una opcion: ";

	return s.str();
}

//------------------------------------------------------------------------
//Administracion General--------------------------------------------------
string Menu::menuAdministracion() {
	stringstream s;
	  s << "	   <Menu Administracion>		  " << endl
		<< "[1]Nombre del Gimnasio----------------" << endl
		<< "[2]Monto de mensualidad---------------" << endl
		<< "[3]Atras----------------------------\n\n"
		<< "Digite una opcion: ";

	return s.str();

}
bool Menu::opMenuAdministracion(int op) {

	switch (op) {
	case 1://Nombre del Gimnasio
		imprimirString("<1. Administración General > <1. Nombre del Gimnasio>  ");
		imprimirString("Ingrese el nombre del Gimnasio : _ FitnessUNA");
		_gym->setNombreDgym(" _ FitnessUNA");
		imprimirString("<Digite Enter >");
		break;
	case 2://Monto de mensualidad
		imprimirString("<1. Administración General>  <2. Monto de mensualidad >  ");
		imprimirString("Ingrese el Monto de mensualidad: 25000 ");
		_gym->setMensualidadDgym(25000);
		imprimirString("<Digite Enter >");
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
		s << "	   <Menu Deportista>		  " << endl
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
	  s << "[1]Listado general--------" << endl
		<< "[2]Listado de deportistas activos ----" << endl
		<< "[3]Listado de deportistas inactivos---" << endl
		<< "[4]Listado de deportistas en morosidad" << endl
		<< "[5]Atras------------------------------\n\n"
		<< "Digite una opcion: ";
	return s.str();
}

bool Menu::opMenuDeportista(int op)
{
	int opSub=0;
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


	iter = _gym->getListaDepor()->begin();
	iter2 = _gym->getListaDepor()->end();

	bool ex = false;
	//clientes (esto puede variar)
	Deportista* cliente = NULL;
	switch (op) {
	case 1: // Ingreso nuevo deportista 
		imprimirString("<2.Control Deportistas>  <1.Ingreso nuevo deportista>");

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
		imprimirString("Nombre: ");
		do {
			try {
				nombre = recivirString();
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
				cout << "Error con el formato de fecha (ejemplo: 15/4/23 ) " << endl;
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

		system("pause");

		cliente = new Triatlonista(cedula, nombre, telefono, fechaNa, horasEntrenem, temProm, sexo, estatura, masaMuscular, peso, PgrasaCorporalMC, canTriaGanados, cantPartiEnIronMan);
		_gym->ingresarListaClientes(cliente);
		enter();
		limpiarPantalla();
		break;
	case 2: //Modificacion de deportista

		Deportista* aux;
		Deportista* auxAborrar;
		imprimirString("<2.Control Deportistas>  <2.Modificacion de deportista>");
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

		for (; iter->getPNodo() != iter2->getPNodo(); iter->operator++()) {
			if (iter->operator*()->getCedula() == cedulaAbuscar) {
				aux = atualizarINFO(iter->operator*());
				auxAborrar = iter->operator*();
				iter->getPNodo()->setInfo(aux);
				delete auxAborrar;
				//Clona el deportista y despues los substitulle con el original para asi poder cambira la infoamcion y no violar ninun principio
			}
		}
		

		break;
	case 3: //Listado de deportistas
		iter = _gym->getListaDepor()->begin();
		iter2 = _gym->getListaDepor()->end();
		imprimirString("<2.Control Deportistas>  <3.Listado de deportistas>");
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
		
		break;
	case 4: //Detalle de deportista especificp
		imprimirString("<2.Control Deportistas>  <4.Detalle deportista especifico>");
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

		for (; iter->getPNodo() != iter2->getPNodo(); iter->operator++()) {
			if (iter->operator*()->getCedula() == cedulaAbuscar) {
				imprimirString("La infomacion de ese deportista es espesifico es: ");
				imprimirString(iter->operator*()->toString());
			}
		}
		
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
	delete fechaNa;
}
//Control Cursos--------------------------------------------------------------
string Menu::menuCursos()
{
	stringstream s;
	s << "	   <Menu Cursos>		  " << endl
		<< "[1]Ingreso nuevo curso----------------" << endl
		<< "[2]Reporte de curso específico--------" << endl
		<< "[3]Modificación de curso específico---" << endl
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
	switch (op) {
	case 1: // Ingreso nuevo curso;
		imprimirString("< 3.Control Cursos> < 1.Ingreso nuevo curso >");
		imprimirString("Codigo del Curso");
		do {
			try {
				codCurso = recivirString();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		imprimirString("Nombre del Curso");
		do {
			try {
				nombreCurso = recivirString();
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
		do {
			try {
				descripcion = recivirString();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		curso = new Curso(codCurso, nombreCurso, nivel, canG, descripcion);
		_gym->ingresarCursos(curso);
		enter();
		limpiarPantalla();
		break;
	case 2: //Reporte de curso específico 
		imprimirString("< 3.Control Cursos> < 2.Reporte de curso especifico>");
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
		imprimirString(_gym->imprimirListaEspe(ident));
		imprimirString("Opcion en desarrollo");
		break;
	case 3://Modificación de curso específico 
		imprimirString("< 3.Control Cursos> < 3. Modificación de  curso especifico >");
		imprimirString("Opcion en desarrollo");
		break;
	default:
		break;
	};
	return false;
}

//Control de grupos-------------------------------------------------------
string Menu::menuGrupos()
{
	stringstream s;
	s << "	   <Menu Grupos>		  " << endl
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
	string codCurso = "";
	string numGrup = "";
	Fecha* fechaMa = NULL;
	switch (op) {
	case 1: // Ingreso nuevo grupo;
		imprimirString("< 4.Control Grupos> < 1.Ingreso nuevo grupo>");
		imprimirString("Lista de cursos");
		imprimirString("<Numero de curso> \t <Nombre del curso>\t  <Nivel>\t");
		imprimirString(_gym->imprimirListadoCursos());
		imprimirString("Digite el curso a elegir: ");
		do {
			try {
				curso = recivirString();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
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
				nomInstructor = recivirString();
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
				cout << "Error con el formato de fecha (ejemplo: 15/4/23 ) " << endl;
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
		imprimirString("Digite el día de la semana (l-k-m-j-v-s-d) ):");
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
		horIn = validarHora(horInicio);
		minIn = validarMinuto(horInicio);
		imprimirString("Digite la hora de finalizacion en hora militar (hora:minuto):");
		do {
			try {
				horaFinal = recivirString();
				horFin = validarHora(horaFinal);
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
		
		enter();
		limpiarPantalla();

		break;
	case 2: //Modificacion de  grupo especifico
		imprimirString("< 4.Control Grupos>  <2. Modificación  de  grupo especifico>");
		imprimirString("Opcion en desarrollo");
		break;
	case 3: //matricula de grupo especifico
		imprimirString("< 4.Control Grupos>  <3.Matricula en grupo especifico>");
		imprimirString("Digite el ID del usuario que desea matricular:");
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
		imprimirString("En que curso desea matricular?");
		_gym->imprimirListadoCursos();

		do {
			try {
				codCurso = recivirString();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		imprimirString("Para dicho curso quedan los siguientes grupos disponibles: ");
		imprimirString(_gym->imprimirListadoGrupo(curso));
		imprimirString("Digite el grupo en el que desea ser ingresado: ");
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
		
		imprimirString("Digite la fecha de matricula: ");
		do {
			try {
				fechaMa = validarFecha();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;

		_gym->ingresarClienteAGrupos(numGrup, codCurso, cedCliente);

		
		imprimirString("Opcion en desarrollo");
		break;
	case 4: //Reporte de grupo especifico 
		imprimirString("< 5.Control Grupos> < 4.Reporte de grupo especifico >");
		codCurso = "";
		numGrup = "";
		imprimirString(_gym->imprimirListadoCursos());
		imprimirString("En cual curso se encuentra el grupo?");
		do {
			try {
				codCurso = recivirString();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		imprimirString(_gym->imprimirListadoGrupo(codCurso));

		_gym->reporteGrupoEspe(codCurso, numGrup);
		imprimirString("Opcion en desarrollo");
		break;
	case 5: //Reporte deportistas matriculados en grupo
		imprimirString("< 5.Control Grupos> < 5. Reporte deportistas matriculados por grupo>");
		imprimirString("Opcion en desarrollo");

		break;
	case 6://Cancelacion de  matricula en grupo
		imprimirString("< 5.Control Grupos>  <6. Cancelación de  matricula en grupo>");
		imprimirString("Opcion en desarrollo");
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
	  s << "	   <Menu Pagos>		  " << endl
	    << "[1]Registro nuevo de pago-------------" << endl
		<< "[2]Reporte de pagos por deportista----" << endl
		<< "[3]Atras------------------------------\n\n"
		<< "Digite una opcion: "
		<< endl;
	return s.str();
}

bool Menu::opMenuPagos(int op)
{
	Fecha* fechAux = NULL;
	int cedulaAbuscar = 0;
	bool ex=false;
	Iterador<Deportista>* iter;
	Iterador<Deportista>* iter2;

	iter = _gym->getListaDepor()->begin();
	iter2 = _gym->getListaDepor()->end();

	switch (op) {
	case 1: // Registro nuevo de pago\n"
		imprimirString("<5.Control  Pagos> <1.Registro de nuevo  pago>");
		imprimirString("Cedula del Cliente: ");
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

		for (; iter->getPNodo() != iter2->getPNodo(); iter->operator++()) {
			if (iter->operator*()->getCedula() == cedulaAbuscar) {
				iter->operator*()->setFechaDeultimoPago(Cobro::getFechaDeultimoPago(iter->operator*(),this->fecha));
				imprimirString("ESTE MENSAJE CONFIRMA EL REGISTRO DE UN NUEVO PAGO MENSUAL");
			}
		}
		//listar los cursos con su codigo 
		break;
	case 2: 
		imprimirString("<5.Control  Pagos> <2.Reporte de pagos por deportista>");////////////////
		imprimirString("Cedula del Cliente: ");
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

		for (; iter->getPNodo() != iter2->getPNodo(); iter->operator++()) {
			if (iter->operator*()->getCedula() == cedulaAbuscar) {
				imprimirString("El ultimo pago de este Cliente esta regitrado en la fecha: ");
				if (iter->operator*()->getFechaDeultimoPago() != NULL) {
					imprimirString(iter->operator*()->getFechaDeultimoPago()->toString());
				}
				imprimirString("{Este cliente esta [inactivo], por lo que no se tiene regitrado un pago reciente}");
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

Deportista* Menu::atualizarINFO(Deportista* depAactaulizar)
{
	Deportista* DepOriginal = depAactaulizar;
	Deportista* Clon =  new Triatlonista(depAactaulizar->getCedula(), depAactaulizar->getNombre(), depAactaulizar->getTelefono(), depAactaulizar->getFechaNacimiento() , depAactaulizar->getHorasDeEntrenamiento(), depAactaulizar->getTempPromedio(), depAactaulizar->getSexo(), depAactaulizar->getEstatura(), depAactaulizar->getMasaMuscular(), depAactaulizar->getPeso(), depAactaulizar->getPorcGrasaCorporal() , depAactaulizar->getCanTriatGanador(), depAactaulizar->getCanPartIronMan() );

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
		Clon->setCedula(cedula);
		break;
		case 2:
		imprimirString("Nombre: ");
		do {
			try {
				nombre = recivirString();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		Clon->setNombre(nombre);
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
		break;
		case 4:
		imprimirString("Fecha nacimiento: ");
		do {
			try {
				fechaNa = validarFecha();
				ex = true;
			}
			catch (...) {
				cout << "Error con el formato de fecha (ejemplo: 15/4/23 ) " << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		Clon->setFechaNacimiento(fechaNa);
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
		break;


		default:break;
		}

		system("pause");
		
		return Clon;
}


string Menu::QueQuiereEditarTri()
{
	stringstream s;
	s << "	   <Que quiere editar>		  " << endl
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

bool Menu::llamarMenus() {
	int op = 0;
	int opE = 0;

	imprimirString(menuPrincipal());
	op = recivirInt();
	switch (op) {
	case 1://Administracion General 
		limpiarPantalla();
		imprimirString(menuAdministracion());
		op = recivirInt();
		opMenuAdministracion(op);
		break;
	case 2://Control de Deportistas
		limpiarPantalla();
		imprimirString(menuDeportista());
		op = recivirInt();
		opMenuDeportista(op);
		break;
	case 3://Control de Cursos
		limpiarPantalla();
		imprimirString(menuCursos());
		op = recivirInt();
		opMenuCursos(op);
		break;
	case 4://Control de Grupos
		limpiarPantalla();
		imprimirString(menuGrupos());
		op = recivirInt();
		opMenuGrupos(op);

		break;
	case 5://Control Pagos
		limpiarPantalla();
		imprimirString(menuPagos());
		op = recivirInt();
		opMenuPagos(op);

		break;
	case 6: //Guardar en Archivos y salir
		limpiarPantalla();
		imprimirString("Buen dia...");
		return true;
		//Completar Archivos al 100%
		//Y despues "delete()" cuando ya leyo y gurado TODO
		break;
	default:
		break;
	}
	return false;

}


