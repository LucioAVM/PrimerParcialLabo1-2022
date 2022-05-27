/*
 * Vivienda.h
 *
 *  Created on: 26 may. 2022
 *      Author: Ususario
 */

#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "Censista.h"

#ifndef VIVIENDA_H_
#define VIVIENDA_H_

typedef struct
{
	int idVivienda;//empezar rn 20.000
	char calle[25];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int TipoVivienda;// HACER STRUCT
	int LegajoCensista;// OTRA STRUCT
	int isEmpty;
}eVivienda;

int eVivienda_Inicializar(eVivienda viviendaMain[], int TAM);

int eVivienda_ObtenerID(int idVivienda);

int eVivienda_ObtenerLibre(eVivienda viviendaMain[], int TAM);

int addVivienda(eVivienda viviendaMain[]
		, int *idViviendaAux
		, int libre
		, char *calle
		, int cantidadPersonas
		, int cantidadHabitaciones
		, int TipoVivienda
		, int LegajoCensista);

void idATipo(int idVivienda, char tipoVivinda[]);

void mostrarUnaVivienda(eVivienda viviendaMain, int TAM);

void mostrarViviendas(eVivienda viviendaMain[], int TAM);

int findViviendaById(eVivienda viviendaMain[], int TAM, int id);

void ordenarViviendas(eVivienda viviendaMain[], int TAM);




#endif /* VIVIENDA_H_ */
