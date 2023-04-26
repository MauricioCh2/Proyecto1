#include "Menu.h"
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
	while (!fin) {
		llamarMenus();
	}
}


string Menu::menuPrincipal() {
	stringstream s;
	  s << "	   <Menu Principal>		  " << endl
		<< "[1]Administracion General-------------" << endl
		<< "[2]Control de Deportista--------------" << endl
		<< "[3]Reportes generales-----------------" << endl
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
		imprimirString("<2.Control Deportistas>  <2.Modificacion de deportista>");
		imprimirString("en dersarrollo");
		break;
	case 3: //Listado de deportistas
		imprimirString("<2.Control Deportistas>  <3.Listado de deportistas>");
		imprimirString(subMenuListas());
		opSub = recivirInt();
		switch (opSub){
			case 1: //listado general
				imprimirString(_gym->imprimirListaClientes());
				break;
			case 2://deportistas activos
				imprimirString("en dersarrollo");
				
				break;
			case 3://deportistas inactivos
				imprimirString("en dersarrollo");
				
				break;
			case 4:// deportistas con morosidad
				imprimirString("en dersarrollo");
				
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
		imprimirString("en dersarrollo");
		break;
	case 5: //Atras
		limpiarPantalla();
		return true;
		break;
	default:

		break;
	};
	return false;
}
//Control Cursos--------------------------------------------------------------
string Menu::menuCursos()
{
	stringstream s;
		s << "	   <Menu Cursos>		  " << endl
		<< "[1].Ingreso nuevo curso---------------" << endl
		<< "[2]. Reporte de curso específico------" << endl
		<< "[3]. Modificación de curso específico-" << endl
		<< "[5]Atras------------------------------\n\n"
		<< "Digite una opcion: ";

	return s.str();
}
bool Menu::opMenuCursos(int op)
{
	switch (op) {
	case 1: // Ingreso nuevo curso;
		imprimirString("< 3.Control Cursos> < 1.Ingreso nuevo curso >");
		imprimirString("Opcion en desarrollo");
		break;
	case 2: //Reporte de curso específico 
		imprimirString("< 3.Control Cursos> < 2.Reporte de curso especifico>");
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
	switch (op) {
	case 1: // Ingreso nuevo grupo;
		//listar los cursos con su codigo 
		imprimirString("< 4.Control Grupos> < 1.Ingreso nuevo grupo>");
		imprimirString("Opcion en desarrollo");
		break;
	case 2: //Modificacion de  grupo especifico
		imprimirString("< 4.Control Grupos>  <2. Modificación  de  grupo especifico>");
		imprimirString("Opcion en desarrollo");
		break;
	case 3: //matricula de grupo especifico
		imprimirString("< 4.Control Grupos>  <3.Matricula en grupo especifico>");
		imprimirString("Opcion en desarrollo");

		break;
	case 4: //Reporte de grupo especifico 
		imprimirString("< 5.Control Grupos> < 4.Reporte de grupo especifico >");
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
	int deportista = 0;

	switch (op) {
	case 1: // Registro nuevo de pago\n"
		imprimirString("<5.Control  Pagos> <1.Registro de nuevo  pago>");

		//listar los cursos con su codigo 
		imprimirString("Opcion en desarrollo");
		break;
	case 2: //Modificacion de  grupo especifico
		imprimirString("<5.Control  Pagos> <1.Registro de nuevo  pago>");

		imprimirString("Opcion en desarrollo");
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
		opMenuCursos(op);
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


