#include "Interfaz.h"

 int Interfaz::getTamEspecialidades() {
	int tamE;
	while (true) {
		cout << "----Bienvenido a la Veterinaria----" << endl;
		cout << "Ingrese la cantidad maxima de especialidades: "; cin >> tamE;
		cin.ignore();
		if (tamE <= 0) {
			cout << "La cantidad de especialidades debe ser mayor a 0" << endl;
		}
		else {
			//system("cls");
			break;
		}
	}
	return tamE;
}

 ContenedoraEspecialidades* Interfaz::crearContenedoraEspecialidades(int tamE) {
	ContenedoraEspecialidades* especialidades = new ContenedoraEspecialidades(tamE);

	return especialidades;
}

 int Interfaz::getTamDoctores() {
	int tamDoc;
	while (true) {
		cout << "Ingrese la cantidad maxima de doctores: "; cin >> tamDoc;
		cin.ignore();
		if (tamDoc <= 0) {
			cout << "La cantidad de doctores debe ser mayor a 0" << endl;
		}
		else {
			//system("cls");
			break;
		}
	}
	return tamDoc;
}

 ContenedoraDoctores* Interfaz::crearContenedoraDoctores(int tamDoc) {
	ContenedoraDoctores* doctores = new ContenedoraDoctores(tamDoc);

	return doctores;
}

 int Interfaz::getTamDuenos() {
	int tamDueno;
	while (true) {
		cout << "Ingrese la cantidad maxima de duenos: "; cin >> tamDueno;
		cin.ignore();
		if (tamDueno <= 0) {
			cout << "La cantidad de duenos debe ser mayor a 0" << endl;
		}
		else {
			//system("cls");
			break;
		}
	}
	return tamDueno;
}

 ContenedoraDueno* Interfaz::crearContenedoraDuenos(int tamDuenos) {
	ContenedoraDueno* duenos = new ContenedoraDueno(tamDuenos);

	return duenos;
}

 int Interfaz::getTamMascotas() {
	int tamM;
	while (true) {
		cout << "Ingrese la cantidad maxima de mascotas en la veterinaria: "; cin >> tamM;
		cin.ignore();
		if (tamM <= 0) {
			cout << "La cantidad de especialidades debe ser mayor a 0" << endl;
		}
		else {
			//system("cls");
			break;
		}
	}
	return tamM;
}

 ContenedoraMascotas* Interfaz::crearContenedoraMascotas(int tamM) {
	ContenedoraMascotas* mascotas = new ContenedoraMascotas(tamM);
	return mascotas;
}

 void Interfaz::defaultSwitch()
 {
	 system("cls");
	 cout << "Opción no válida. Intente de nuevo." << endl;
	 system("pause");

 }

 void Interfaz::regresarPrincipal()
 {
	 system("cls");
	 cout << "Regresando al Menú Principal..." << endl;
	 system("pause");
 }

 int Interfaz::menuPrincipal() {
	int op;
	system("cls");
	endl(cout);
	cout << "----Menu Principal----" << endl;
	cout << "1- Submenú Administración" << endl;
	cout << "2- Submenú Control de Citas " << endl;
	cout << "3- Submenú Búsquedas y Listados" << endl;
	cout << "4- Salir" << endl;
	cout << "Seleccione una opción: "; cin >> op;
	cin.ignore();
	return op;
}
 int Interfaz::menuAdministracion() {
	int op1;
	system("cls");
	endl(cout);
	cout << "----Submenú Administración----" << endl;
	cout << "(1) Ingresar Especialidades" << endl;
	cout << "(2) Ingresar Doctor(por especialidad)" << endl;
	cout << "(3) Ingresar dueno" << endl;
	cout << "(4) Ingresar Mascota(por dueno)" << endl;
	cout << "(0) Regresar al Menú Principal" << endl;
	cout << "Seleccione una opción: "; cin >> op1;
	return op1;
}

 int Interfaz::menuControlCitas()
 {
	 int op2;
	 system("cls");
	 endl(cout);
	 cout << "----Submenú Control Citas----" << endl;
	 cout << "(1) Sacar Cita" << endl;
	 cout << "(2) Cancelar Cita" << endl;
	 cout << "(3) Mostrar Calendario de Citas por Doctor" << endl;
	 cout << "(4) Mostrar Citas por dueno" << endl;
	 cout << "(0) Regresar al Menú Principal" << endl;
	 cout << "Seleccione una opción: "; cin >> op2;
	 return op2;
 }

 int Interfaz::menuBusquedaYListados()
 {
	 int op3;
	 system("cls");
	 endl(cout);
	 cout << "----Submenú Control Citas----" << endl;
	 cout << "(1) Mostrar Listado de Especialidades" << endl;
	 cout << "(2) Mostrar Listado de Doctores por Especialidad" << endl;
	 cout << "(3) Mostrar duenos con sus Mascotas" << endl;
	 cout << "(4) Mostrar Pacientes por Doctor" << endl;
	 cout << "(0) Regresar al Menú Principal" << endl;
	 cout << "Seleccione una opción: "; cin >> op3;
	 return op3;
 }

 void Interfaz::agregarEspecialidades(ContenedoraEspecialidades* especialidades, int tamE) {
	system("cls");
	string nombre, descripcion;
	Especialidad* especialidadPtr = nullptr;
	cout << "(1) Ingresar Especialidades" << endl;
	for (int i = 0; i < tamE; i++) {
		if (especialidades->getCant() == tamE) {
			cout << "Ya no puede ingresar más especialidades, esta lleno" << endl;
			system("pause");
			break;
		}
		cin.ignore();
		cout << "Ingrese el nombre de la especialidad " << i + 1 << ": ";
		getline(cin, nombre);
		if (nombre.empty()) {
			cout << "Error: no ingreso un nombre" << endl;
			system("pause");
			break;
		}

		cout << "Ingrese una descripcion de la especialidad: ";
		getline(cin, descripcion);
		if (descripcion.empty()) {
			cout << "Error: no ingreso una descripcion" << endl;
			system("pause");
			break;
		}
		especialidadPtr = new Especialidad(nombre, descripcion);
		if (especialidades->agregarEspecialidad(especialidadPtr))
			cout << "Especialidad agregada correctamente" << endl;
		else {
			cout << "Error al agregar la especialidad" << endl;
			system("pause");
			break;
		}
		endl(cout);
	}
	cout << especialidades->toString();
	system("pause");
}
	
 void Interfaz::agregarDoctores(ContenedoraDoctores* doctores, ContenedoraEspecialidades* especialidades, int tamDoc) {
	Especialidad* especialidadPtr = nullptr;
	Doctor* doctorPtr = nullptr;
	int pos;
	string cedula;
	string nombre;
	system("cls");
	cout << "(2) Ingresar Doctor(por especialidad)" << endl;
	if (doctores->getCant() == tamDoc) {
		cout << "Ya no puede ingresar más doctores, esta lleno" << endl;
		system("pause");
		return;
	}
	if (especialidades->getCant() == 0) {
		cout << "Error: No hay especialidades ingresadas" << endl;
		system("pause");
		return;
	}
	cout << especialidades->toString() << endl;
	cout << "Elija el numero de la especialidad del doctor: "; cin >> pos;
	if (especialidades->getEspecialidad(pos) == nullptr || pos == 0)
	{
		cout << "Error: No hay especialidades con el numero ingresado" << endl;
		system("pause");
		return;
	}
	especialidadPtr = especialidades->getEspecialidad(pos);
	cout << "Especialidad ingresada: " << especialidadPtr->getNombre()<<endl;
	cin.ignore();
	cout << "Ingrese el nombre del doctor: "; getline(cin, nombre);
	if (nombre.empty()) {
		cout << "Error: no ingreso un nombre" << endl;
		system("pause");
		return;
	}
	cout << "Nombre ingresado: " << nombre << endl;
	cout << "Ingrese la cedula del doctor: "; getline(cin, cedula);
	if (cedula.empty()) {
		cout << "Error: no ingreso una cedula" << endl;
		system("pause");
		return;
	}
	cout << "Cédula ingresada: " << cedula << endl;
	if (doctores->existeDoctor(cedula)) {
		cout << "Ya existe un doctor con esa cedula"<<endl;
		system("pause");
		return;
	}
	doctorPtr = new Doctor(nombre, cedula, especialidadPtr);
	if (doctores->agregarDoctor(doctorPtr))
		cout << "Doctor agregado correctamente" << endl;
	else {
		cout << "Error al agregar el doctor" << endl;
		system("pause");
		return;
	}
	system("pause");
}

 void Interfaz::agregarDueno(ContenedoraDueno* duenos, int tamDueno) {
	system("cls");
	string nombre;
	string cedula;
	Dueno* duenoPtr = nullptr;
	cout << "(3) Ingresar dueno" << endl;
	if (duenos->getCant() == tamDueno) {
		cout << "Ya no puede ingresar más duenos, esta lleno" << endl;
		system("pause");
		return;
	}
	cin.ignore();
	cout << "Ingrese el nombre del dueno: "; getline(cin, nombre);
	if (nombre.empty()) {
		cout << "Error: no ingreso un nombre" << endl;
		system("pause");
		return;
	}
	cin.ignore();
	cout << "Ingrese la cedula del dueno: "; getline(cin, cedula);
	if (cedula.empty()) {
		cout << "Error: no ingreso una cedula" << endl;
		system("pause");
		return;
	}
	if (duenos->existeDueno(cedula)) {
		cout << "Ya existe un dueno con esa cedula" << endl;
		system("pause");
		return;
	}
	duenoPtr = new Dueno(nombre, cedula);
	if (duenos->agregarDueno(duenoPtr))
		cout << "dueno agregado correctamente" << endl;
	else {
		cout << "Error al agregar el dueno" << endl;
		system("pause");
	}
	system("pause");
}

 void Interfaz::agregarMascota(ContenedoraMascotas* mascotas, ContenedoraDueno* duenos, int tamM) {
	system("cls");
	string cedula;
	string nombre;
	string especie;
	Dueno* duenoPtr = nullptr;
	Mascota* mascotaPtr = nullptr;
	cout << "(4) Ingresar Mascota(por dueno)" << endl;
	if (mascotas->getCantidad() == tamM) {
		cout << "Ya no puede ingresar más mascotas, esta lleno" << endl;
		system("pause");
		return;
	}
	if (duenos->getCant() == 0) {
		cout << "Error: No hay duenos ingresados" << endl;
		system("pause");
		return;
	}
	cout << duenos->toString() << endl;
	cout << "Elija la cedula del dueno de la mascota: "; getline(cin, cedula);
	if (cedula.empty()) {
		cout << "Error: no ingreso una cedula" << endl;
		system("pause");
		return;
	}
	if (duenos->getDueno(cedula) == nullptr)
	{
		cout << "Error: No hay duenos con la cedula ingresada: " << cedula << endl;
		system("pause");
		return;
	}
	duenoPtr = duenos->getDueno(cedula);
	cout << "Ingrese el nombre de la mascota: "; getline(cin, nombre);
	if (nombre.empty()) {
		cout << "Error: no ingreso un nombre" << endl;
		system("pause");
		return;
	}
	cout << "Ingrese la especia de la mascota: "; getline(cin, especie);
	if (especie.empty()) {
		cout << "Error: no ingreso una especie" << endl;
		system("pause");
		return;
	}
	mascotaPtr = new Mascota(nombre, especie, duenoPtr);
	if (mascotas->agregarMascota(mascotaPtr))
		cout << "Mascota agregada correctamente" << endl;
	else
		cout << "Error al agregar la mascota" << endl;
	system("pause");


}

 void Interfaz::sacarCita(Agenda* agenda, ContenedoraDoctores* doctores, ContenedoraMascotas* mascotas, ContenedoraEspecialidades* especialidades)
 {
	 int dia;
	 int hora;
	 int pos;
	 Especialidad *especialidadPtr=nullptr;
	 string cedula;
	 Doctor* doctorPtr = nullptr;
	 Mascota* mascotaPtr = nullptr;

	 system("cls");
	 cout << "(1) Sacar Cita" << endl;
	 if (especialidades->getCant() == 0)
	 {
		 cout << "No hay especialidades agregadas" << endl;
		 system("pause");
		 return;
	 }
	 if (doctores->getCant() == 0)
	 {
		 cout << "No hay doctores ingresados" << endl;
		 system("pause");
		 return;
	 }
	 if (mascotas->getCantidad() == 0)
	 {
		 cout << "No hay mascotas ingresadas" << endl;
		 system("pause");
		 return;
	 }
	 cout << agenda->mostrarDias();
	 cout << "Ingrese el dia de la cita: "; cin >> dia;
	 cout << "Ingrese la hora de la cita: "; cin >> hora;
	 if (especialidades->getCant() == 0) {
		 cout << "No hay especialidades agregadas" << endl;
		 system("pause");
		 return;
	 }
	 cout << especialidades->toString() << endl;
	 cout << "Ingrese el numero de la especialidad del doctor: " << endl;
	 cin >> pos;
	 if (especialidades->getEspecialidad(pos) == nullptr)
	 {
		 cout << "Error: No hay especialidades con el numero ingresado" << endl;
		 system("pause");
		 return;
	 }
	 especialidadPtr = especialidades->getEspecialidad(pos);
	 cout << especialidades->DoctorPorEspecialidad(especialidadPtr->getNombre(), doctores);
	 if (doctores->getCant() == 0) {
		 cout << "No hay doctores ingresados";
		 system("pause");
		 return;
	 }
	 cout << "Ingrese la cedula del doctor: " << endl;
	 cin.ignore();
	 getline(cin, cedula);
	 if (cedula.empty()) {
		 cout << "Error: no ingreso una cedula" << endl;
		 system("pause");
		 return;
	 }
	 if (!doctores->existeDoctor(cedula)) {
		 cout << "No existe doctor con esa cedula" << endl;
		 system("pause");
		 return;
	 }
	 doctorPtr = doctores->getDoctor(cedula);
	 cout << "Ingrese la cedula del dueno de la mascota: " << endl;
	 getline(cin, cedula);
	 if (cedula.empty()) {
		 cout << "Error: no ingreso una cedula" << endl;
		 system("pause");
		 return;
	 }
	 if (mascotas->MascotasPorDueno(cedula) == "No hay mascotas registradas" || mascotas->MascotasPorDueno(cedula) == "Error: No hay duenos con la cédula ingresada: " + cedula)
	 {
		 cout << "No hay mascotas registradas o la cedula esta incorrecta" << endl;
		 system("pause");
		 return;
	 }
	 cout << mascotas->MascotasPorDueno(cedula);
	 cout << "Ingrese el numero de la mascota: "; cin >> pos;
	 if (mascotas->getMascota(pos) == nullptr)
	 {
		 cout << "Error: No hay mascotas con el numero ingresado" << endl;
		 system("pause");
		 return;
	 }
	 mascotaPtr = mascotas->getMascota(pos);
	 if (agenda->agregarCita(dia-1, hora, doctorPtr, mascotaPtr))
		 cout << "Cita agregada correctamente" << endl;
	 else
		 cout << "Error al agregar la cita" << endl;

	 system("pause");

 }

 void Interfaz::cancelarCita(Agenda* agenda, ContenedoraDoctores* doctores, ContenedoraMascotas* mascotas)
 {
	 int dia;
	 int hora;
	 int pos;
	 string cedula;
	 Doctor* doctorPtr = nullptr;
	 Mascota* mascotaPtr = nullptr;
	 system("cls");
	 cout << "(2) Cancelar Cita" << endl;
	 if (doctores->getCant() == 0) {
		 cout << "No hay doctores ingresados"<<endl;
		 system("pause");
		 return;
	 }

	 cout << agenda->mostrarDias();
	 cout << "Ingrese el dia de la cita a cancelar: "; cin >> dia;
	 cout << "Ingrese la hora de la cita a cancelar: "; cin >> hora;
	 cin.ignore();

	 cout << "Ingrese la cedula del doctor con el que tiene la cita: ";
	 getline(cin, cedula);
	 if (cedula.empty()) {
		 cout << "Error: no ingreso una cedula" << endl;
		 system("pause");
		 return;
	 }
	 if (doctores->getDoctor(cedula) == nullptr)
	 {
		 cout << "Error: No hay doctores con la cedula ingresada: " << cedula << endl;
		 system("pause");
		 return;
	 }
	 doctorPtr = doctores->getDoctor(cedula);
	 cout << "Ingrese la cedula del dueno: ";
	 getline(cin, cedula);
	 if (cedula.empty()) {
		 cout << "Error: no ingreso una cedula" << endl;
		 system("pause");
		 return;
	 }
	 if (mascotas->MascotasPorDueno(cedula) == "No hay mascotas registradas" || mascotas->MascotasPorDueno(cedula) == "Error: No hay duenos con la cédula ingresada: " + cedula)
	 {
		 cout << "No hay mascotas registradas o la cedula esta incorrecta" << endl;
		 system("pause");
		 return;
	 }
	 cout << mascotas->MascotasPorDueno(cedula);
	 cout << "Ingrese el numero de la mascota: "; cin >> pos;
	 cin.ignore();
	 if (mascotas->getMascota(pos) == nullptr) {
		 cout << "Error no hay mascotas con ese numero" << endl;
		 system("pause");
		 return;
	 }
	 mascotaPtr = mascotas->getMascota(pos);
	 if (agenda->cancelarCita(dia-1, hora, doctorPtr, mascotaPtr))
		 cout << "Cita cancelada correctamente" << endl;
	 else
		 cout << "Error al cancelar la cita" << endl;

	 system("pause");
 }

 void Interfaz::mostrarCalendarioPorDoctor(Agenda* agenda, ContenedoraDoctores* doctores)
 {
	 string cedula;

	 system("cls");
	 cout << "(3) Mostrar Calendario de Citas por Doctor" << endl;
	 cin.ignore();
	 if (doctores->getCant() == 0) {
		 cout << "No hay doctores ingresados";
		 system("pause");
		 return;
	 }
	 cout << "Ingrese la cedula del doctor para ver su agenda: "; getline(cin, cedula);
	 if (cedula.empty()) {
		 cout << "Error: no ingreso una cedula" << endl;
		 system("pause");
		 return;
	 }
	 if (doctores->getDoctor(cedula) != nullptr)
		 cout << agenda->toString(cedula, doctores);
	 else
		 cout << "Error: No hay doctores con la cedula ingresada: " << cedula << endl;
	 system("pause");
 }

 void Interfaz::mostrarCitasPorDueno(Agenda* agenda, ContenedoraMascotas* mascotas,ContenedoraDueno* duenos)
 {
	 string cedula;
	 system("cls");
	 cout << "(4) Mostrar Citas por dueno" << endl;
	 cin.ignore();
	 if (duenos->getCant() == 0) {
		 cout << "No hay duenos ingresados";
		 system("pause");
		 return;
	 }
	 cout << "Ingrese la cedula del dueno para ver sus citas: "; getline(cin, cedula);
	 if (cedula.empty()) {
		 cout << "Error: no ingreso una cedula" << endl;
		 system("pause");
		 return;
	 }
	 if (mascotas->MascotasPorDueno(cedula) == "No hay mascotas registradas" || mascotas->MascotasPorDueno(cedula) == "Error: No hay duenos con la cédula ingresada: " + cedula)
	 {
		 cout << "No hay mascotas registradas o la cedula esta incorrecta" << endl;
		 system("pause");
		 return;
	 }
	 cout << agenda->mostrarCitasPorDueno(cedula);
	 system("pause");

 }

 void Interfaz::mostrarListadoEspecialidades(ContenedoraEspecialidades* especialidades)
 {
	 system("cls");
	 cout << "(1) Mostrar Listado de Especialidades" << endl;
	 if (especialidades->getCant() > 0 ) {
		 cout << especialidades->toString();
	 }
	 else
		 cout << "No hay especialidades registradas" << endl;
	 system("pause");

 }

 void Interfaz::mostrarDoctoresPorEspecialidad(ContenedoraEspecialidades* especialidades, ContenedoraDoctores* doctores)
 {
	 system("cls");
	 cout << "(2) Mostrar Listado de Doctores por Especialidad " << endl;
	 if (especialidades->getCant() > 0 && doctores->getCant() > 0)
		 cout << especialidades->imprimirDoctoresOrdenados(doctores);
	 else
		 cout << "No hay especialidades registradas o doctores registrados" << endl;
	 system("pause");
 }

 void Interfaz::mostrarDuenosConMascotas(ContenedoraDueno* duenos, ContenedoraMascotas* mascotas)
 {
	 system("cls");
	 cout << "(3) Mostrar duenos con sus Mascotas" << endl;
	 if (duenos->getCant() > 0)
		 cout << mascotas->MascotasOrdenadas(duenos);
	 else
		 cout << "No hay duenos registrados" << endl;
	 system("pause");

 }

 void Interfaz::mostrarPacientesPorDoctor(Agenda* agenda, ContenedoraDoctores* doctores)
 {
	 string cedula;
	 system("cls");
	 cout << "(4) Mostrar Pacientes por Doctor" << endl;
	 if (doctores->getCant() == 0) {
		 cout << "No hay doctores registrados en el sistema." << endl;
		 system("pause");
		 return;
	 }
	 cout << "Doctores: " << endl;
	 cin.ignore();
	 cout << doctores->toString();
	 cout << "Ingrese la cedula del doctor para ver sus pacientes: "; getline(cin, cedula);
	 if (cedula.empty()) {
		 cout << "Error: no ingreso una cedula" << endl;
		 system("pause");
		 return;
	 }
	 agenda->mostrarPacientesPorDoctor(cedula, doctores);
	 system("pause");
 }
