/*
 * Censista.h
 *
 *  Created on: 20 may. 2022
 *      Author: Monsalbo lucio
 */

#ifndef CENSISTA_H_
#define CENSISTA_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int legajoCensista;
	char Nombre[25];
	int edad;
	long int telefono;
}eCensista;


/**
 * DESCRIPCION	muestra el array de la estructura eCensistas
 *
 * PARAMETRO	eCensista censistaMain
 *
 * RETORNO		void
 */
void mostrarUnCensista(eCensista censistaMain);


/**
 * DESCRIPCION	muestra todo el array de censistas
 *
 * PARAMETRO	eCensista censistaMain[]
 *
 * RETORNO		void
 */
void mostrarCensistas(eCensista censistaMain[]);

#endif /* CENSISTA_H_ */
