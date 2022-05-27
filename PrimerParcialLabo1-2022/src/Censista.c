/*
 * Censista.c
 *
 *  Created on: 26 may. 2022
 *      Author: Ususario
 */
#include "Censista.h"
#include <string.h>

void mostrarUnCensista(eCensista censistaMain, int TAM)
{
	int legajo;
	char Nombre[25];
	int edad;
	long int telefono;

	legajo = censistaMain.legajoCensista;
	strcpy(Nombre, censistaMain.Nombre);
	edad = censistaMain.edad;
	telefono = censistaMain.telefono;

	printf( "----LEGAJO----NOMBRE----EDAD----TELEFONO----"
			"      %4d        %4s      %5d        %5ld \n",legajo ,Nombre, edad, telefono);
}
