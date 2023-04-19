#include "Menu.h"
void Menu::inicio() {

	bool fin = false;
	imprimirString("Bienvenido al GYM de triatlon");

	imprimirString("Digite la Fecha en formato dia/mes/annio");
	fecha = validarFecha();
	//cout<<fecha->toString()<< "prueba ";
	while (!fin) {
		llamarMenus();
	}


}
bool Menu::llamarMenus() {
	int op = 0;
	int opE = 0;

	imprimirString(menuPrincipal());
	op = recivirInt();
	switch (op) {
	case 1://clientes
		imprimirString(menuCliente());
		opE = recivirInt();
		opMenuCliente(opE);
		break;
	case 2://Registro y control (verificación y reporte) de pagos
		throw new string("opcion aun en desarrollo");
		break;
	case 3://Reportes generales
		throw new string("opcion aun en desarrollo");

		break;
	case 4://Registro y actualizacion de cursos
		imprimirString(menuCursos());
		op = recivirInt();
		opMenuCursos(op);

		break;
	case 5:// manejo de reservaciones 
		throw new string("opcion aun en desarrollo");

		break;
	case 6: //Salir
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
string Menu::menuPrincipal() {
	stringstream s;
	s << "QUE DESEA HACER?" << endl
		<< "[1]Registrar o editar clientes-----------------" << endl
		<< "[2]Registro y control de pagos--------" << endl
		<< "[3]Reportes generales-----------------" << endl
		<< "[4]Registro y actualizacion de cursos-" << endl
		<< "[5]Manejo de reservaciones------------" << endl
		<< "[5]Salir------------------------------" << endl;

	return s.str();
}
//clientes-----------------------------------------------------------------
string Menu::menuCliente() {
	stringstream s;
	s << "MENU CLIENTES" << endl
		<< "[1]Registrar Clientes-----------------" << endl
		<< "[2]Edicion e clientes--------" << endl
		<< "[3]Eliminar clientess-----------------" << endl
		<< "[4]Cancelar---------------------------" << endl;


	return s.str();
}
bool Menu::opMenuCliente(int opC) {
	//Deportista
	string cedula = "";
	string nombre = "";
	string telefono = "";
	Fecha* fechaNa;
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
	//clientes (esto puede variar)
	Deportista* cliente = NULL;

	//esto debe incluir la fecha de registro de los datos
	// no se si en general del cliente o solo del triatonista
	switch (opC) {
	case 1:
		imprimirString("Ingreso de datos del cliente: ");
		//deportista
		imprimirString("Cedula: ");
		cedula = recivirString();
		imprimirString("Nombre: ");
		nombre = recivirString();
		imprimirString("Telefono: ");
		telefono = recivirString();
		imprimirString("Fecha nacimiento: ");
		fechaNa = validarFecha();
		//Ciclista
		imprimirString("Horas de entrenamiento: ");
		horasEntrenem = recivirDouble();
		imprimirString("Temperatura promedio al entrenar: ");
		temProm = recivirDouble();
		//Corredor
		imprimirString("Sexo: ");
		sexo = recivirChar();
		imprimirString("Estatura: ");
		estatura = recivirDouble();
		//Nadador
		imprimirString("Porcentaje masa corporal: ");
		masaMuscular = recivirDouble();
		imprimirString("Peso: ");
		peso = recivirDouble();
		imprimirString("Porcentaje de grasa corporal: ");
		PgrasaCorporalMC = recivirDouble();
		//triatlonista
		imprimirString("Cantidad de participaciones en Iron Man");
		cantPartiEnIronMan = recivirDouble();
		imprimirString("Cantidad de triatlones ganados:");
		canTriaGanados = recivirDouble();

		cliente = new Triatlonista(cedula, nombre, telefono, fechaNa, horasEntrenem, temProm, sexo, estatura, masaMuscular, peso, PgrasaCorporalMC, canTriaGanados, cantPartiEnIronMan);
		cout << cliente->toString();
		enter();
		limpiarPantalla();
		break;
	case 2:

		break;
	case 3:

		break;
	case 4:
		limpiarPantalla();
		return true;
		break;
	default:
		return false;
		break;
	}


	imprimirString("Datos ingresados correctamente ");
	return false;
}
//Pagos-----------------------------------------------------------------
string Menu::menuPagos() {
	return "";
}
bool Menu::opMenuPAgos(int) {
	return false;
}

//Reporte generales------------------------------------------------------
string Menu::menuReportesGenerales() {

	return "";
}
bool Menu::opMenuReportes(int) {
	return false;
}
//Registro y actualizacion de cursos-------------------------------------
string Menu::menuCursos() {
	stringstream s;
	s << "MENU CURSOS" << endl
		<< "[1]Nuevo curso------------------------" << endl
		<< "[2]Edicion de cursos------------------" << endl
		<< "[3]Eliminar curso---------------------" << endl
		<< "[4]Cancelar---------------------------" << endl;
	return s.str();
}
bool Menu::opMenuCursos(int op) {
	string nombre;
	string descripcion;
	string fecha;
	string horario;
	int cupMax;
	//Deportista* cliente;
	//Curso* curso;
	switch (op) {
	case 1: //nuevo curso
		imprimirString("Ingreso de datos del curso: ");
		imprimirString("nombre: ");
		nombre = recivirString();
		imprimirString("Descripcon del curso: ");
		descripcion = recivirString();
		imprimirString("Fecha: ");
		fecha = recivirString();
		imprimirString("Horario: ");
		horario = recivirString();
		imprimirString("Peso: ");
		cupMax = recivirInt();
		//curso*= new Curso(nombre, descripcion, fecha, horario, cupMax, NULL);
		// ese null seria la liusta de clientes pero creo que iria a null ya que aun no se le asgnaria nada 
		//luegoesto se debe ir a la lista obviamente
		// gym->ingresarListaCursos(curso);
		enter();
		limpiarPantalla();
		break;
	case 2:// edicion de cursos

		break;
	case 3://eliminar curso 

		break;
	case 4://cancelar
		limpiarPantalla();
		return true;
		break;
	default: break;

	}
	return false;
}
//Reservaciones----------------------------------------------------------
string Menu::menuReservaciones() {
	return "";

}
bool Menu::opMenuReservaciones(int) {
	return false;

}