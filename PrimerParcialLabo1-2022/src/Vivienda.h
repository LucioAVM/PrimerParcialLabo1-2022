/*
 * Vivienda.h
 *
 *  Created on: 20 may. 2022
 *      Author: Monsalbo lucio
 */


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


/**
 * DESCRIPCION	inicializa todos los campos isEmpty de eViviendas en LIBRE
 *
 * PARAMETRO	eVivienda viviendaMain[]
 * PARAMETRO	int TAM
 *
 * RETORNO		1 = ERROR  0 = INICIALIZACION EXITOSA
 */
int eVivienda_Inicializar(eVivienda viviendaMain[], int TAM);


/**
 * DESCRIPCION	recibe ID y le suma 1
 *
 * PARAMETRO	int idVivienda
 *
 * RETORNO		el id + 1
 */
int eVivienda_ObtenerID(int idVivienda);


/**
 * DESCRIPCION	busca lugar libre en el array y lo devuelve en caso de encontrarlo
 *
 * PARAMETRO	eVivienda viviendaMain[]
 * PARAMETRO	int TAM
 *
 * RETORNO		-1 = ERROR    != -1 = lugar libre
 */
int eVivienda_ObtenerLibre(eVivienda viviendaMain[], int TAM);


/**
 * DESCRIPCION	recibe parametros de la estructura, valida y los carga en la estructura principal
 *
 * PARAMETRO	eVivienda viviendaMain[]
 * PARAMETRO	int *idViviendaAux
 * PARAMETRO	int libre
 * PARAMETRO	char calle[]
 * PARAMETRO	int cantidadPersonas
 * PARAMETRO	int cantidadHabitaciones
 * PARAMETRO	int TipoVivienda
 * PARAMETRO	int LegajoCensista
 *
 * RETORNO		0 = ERROR   != ID
 */
int addVivienda(eVivienda viviendaMain[]
		, int *idViviendaAux
		, int libre
		, char calle[]
		, int cantidadPersonas
		, int cantidadHabitaciones
		, int TipoVivienda
		, int LegajoCensista);


/**
 * DESCRIPCION	reemplaza el id de vivienda por el nombre que le corresponde
 *
 * PARAMETRO	int idVivienda
 * PARAMETRO	char tipoVivinda[]
 *
 * RETORNO		void
 */
void idATipo(int idVivienda, char tipoVivinda[]);


/**
 * DESCRIPCION	muestra una sola vivienda
 *
 * PARAMETRO	eVivienda viviendaMain
 * PARAMETRO	int TAM
 *
 * RETORNO		void
 */
void mostrarUnaVivienda(eVivienda viviendaMain, int TAM);


/**
 * DESCRIPCION	muestra todas las viviendas
 *
 * PARAMETRO	eVivienda viviendaMain
 * PARAMETRO	int TAM
 *
 * RETORNO		void
 */
void mostrarViviendas(eVivienda viviendaMain[], int TAM);


/**
 * DESCRIPCION	busca el id y devuelve el lugar que ocupa en el array
 *
 * PARAMETRO	eVivienda viviendaMain
 * PARAMETRO	int TAM
 * PARAMETRO	int id
 *
 * RETORNO		-1 = ERROR   != id
 */
int findViviendaById(eVivienda viviendaMain[], int TAM, int id);


/**
 * DESCRIPCION	ordena las viviendas a traves de un burbujeo por calle y en caso de coincidir por cantida de personas
 *
 * PARAMETRO	eVivienda viviendaMain
 * PARAMETRO	int TAM
 *
 * RETORNO		void
 */
void ordenarViviendas(eVivienda viviendaMain[], int TAM);

#endif /* VIVIENDA_H_ */
