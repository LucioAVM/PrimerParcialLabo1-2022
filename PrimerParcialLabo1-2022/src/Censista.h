/*
 * Censista.h
 *
 *  Created on: 26 may. 2022
 *      Author: Ususario
 */

#ifndef CENSISTA_H_
#define CENSISTA_H_
#include <stdio.h>
#include <stdlib.h>
#include "Vivienda.h"

typedef struct
{
	int legajoCensista;
	char Nombre[25];
	int edad;
	long int telefono;
}eCensista;

void mostrarUnCensista(eCensista censistaMain, int TAM);


#endif /* CENSISTA_H_ */
