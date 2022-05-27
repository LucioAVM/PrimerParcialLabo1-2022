/*
 * Censista.c
 *
 *  Created on: 20 may. 2022
 *      Author: Monsalbo lucio
 */
#include "Censista.h"
#include <string.h>

void mostrarUnCensista(eCensista censistaMain)
{
	int legajo;
	char Nombre[25];
	int edad;
	long int telefono;

	legajo = censistaMain.legajoCensista;
	strcpy(Nombre, censistaMain.Nombre);
	edad = censistaMain.edad;
	telefono = censistaMain.telefono;

	printf("      %4d        %4s      %5d        %5ld \n",legajo ,Nombre, edad, telefono);
}

void mostrarCensistas(eCensista censistaMain[])
{
	int i;
	printf("----LEGAJO----NOMBRE----EDAD----TELEFONO----\n");

	for(i = 0 ; i < 3 ; i++)
	{
		mostrarUnCensista(censistaMain[i]);
	}
}
