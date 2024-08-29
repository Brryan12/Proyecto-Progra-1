#include "ContenedoraMascotas.h"

ContenedoraMascotas::ContenedoraMascotas(int tam)
{
	this->tam = tam;
	this->cantidad = 0;
	this->mascotas = new Mascota * [tam];
	for (int i = 0; i < tam; i++) {
		mascotas[i] = nullptr;
	}
}

ContenedoraMascotas::~ContenedoraMascotas()
{
	for (int i = 0; i < cantidad; i++) {
		delete mascotas[i];
	}
	delete[] mascotas;
}

void ContenedoraMascotas::agregarMascota(Mascota* mascota)
{
	if (cantidad < tam) {
		mascotas[cantidad] = mascota;
		cantidad++;
	}
}
