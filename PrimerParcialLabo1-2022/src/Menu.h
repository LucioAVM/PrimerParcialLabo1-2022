/*
 * Menu.h
 *
 *  Created on: 20 may. 2022
 *      Author: Monsalbo lucio
 */

#ifndef MENU_H_
#define MENU_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Censista.h"
#include "Vivienda.h"
#include "Monsalbo.h"

#define LIBRE 0
#define OCUPADO 1

/**
 * DESCRIPCION 	muestra el menu
 *
 * PARAMETRO 	void
 *
 * RETORNO		la opcion ingresada por el usuario
 */
int mostrarMenu(void);

/**
 * DESCRIPCION	da de alta una nueva vivienda y lo carga en la estructura main
 *
 * PARAMETRO	eVivienda viviendaMain[]
 * PARAMETRO	eCensista censistaMain[]
 * PARAMETRO	int TAM
 * PARAMETRO	int *idVivienda
 *
 * RETORNO		0 = ERROR  1 = ALTA EXITOSA
 */
int altaVivienda(eVivienda viviendaMain[], eCensista censistaMain[],int TAM, int *idVivienda);

/**
 * DESCRIPCION	busca por id a la vivienda y modifica lo que el usuario pida dentro de las opciones
 *
 * PARAMETRO	eVivienda viviendaMain[]
 * PARAMETRO	int TAM
 *
 * RETORNO		0 = ERROR  1 = MODIFICACION EXITOSA
 */
int modificarVivienda(eVivienda viviendaMain[], int TAM);


/**
 * DESCRIPCION	busca por id a la vivienda y la da de baja
 *
 * PARAMETRO	eVivienda viviendaMain[]
 * PARAMETRO	int TAM
 *
 * RETORNO		0 = ERROR  1 = BAJA EXITOSA
 */
int bajaVivienda(eVivienda viviendaMain[], int TAM);


/**
 * DESCRIPCION	muestra una lista de las vivendas ordenadas por calle y en caso de ser iguales por cantidad de personas
 *
 * PARAMETRO	eVivienda viviendaMain[]
 * PARAMETRO	int TAM
 *
 * RETORNO		void
 */
void listarViviendas(eVivienda viviendaMain[], int TAM);


/**
 * DESCRIPCION	realiza una lista de los censistas
 *
 * PARAMETRO	eCensista censistaMain[]
 *
 * RETORNO		void
 */
void listarCensistas(eCensista censistaMain[]);
#endif /* MENU_H_ */
