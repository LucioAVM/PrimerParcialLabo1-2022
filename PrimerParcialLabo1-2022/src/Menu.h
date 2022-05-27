/*
 * Menu.h
 *
 *  Created on: 26 may. 2022
 *      Author: Ususario
 */

#ifndef MENU_H_
#define MENU_H_


#include "Vivienda.h"
#include "Censista.h"

#define LIBRE 0
#define OCUPADO 1

int mostrarMenu(void);

int altaVivienda(eVivienda viviendaMain[],int TAM, int *idVivienda);

int modificarpasajero(eVivienda viviendaMain[], int TAM);

int bajaVivienda(eVivienda viviendaMain[], int TAM);

void listarViviendas(eVivienda viviendaMain[], int TAM);

void listarCensistas(eCensista censistaMain[]);
#endif /* MENU_H_ */
