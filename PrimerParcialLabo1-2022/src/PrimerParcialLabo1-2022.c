/*
 ============================================================================
 Name        : PrimerParcialLabo1-2022.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Vivienda.h"
#include "Censista.h"
#include "menu.h"
#define TAM 5

int main(void)
{
	setbuf(stdout, NULL);

	eVivienda viviendaMain[TAM];
	eCensista censistaMain[] = {
			{100,"Ana",34,12032345}
			,{101,"Juan",24,430154678},
			{102,"Sol",47,590237487}
	};

	int menu;
	int idVivienda;

	idVivienda = 19999;

	do
	{
		menu = mostrarMenu();

		switch(menu)
		{
		case 1:
			if(altaVivienda(viviendaMain,TAM, &idVivienda))//si la funcion devuelve 0 es verdadero(usar para validar)
			{
				printf("\n-----Vivienda dada de alta exitosamente----\n");
			}else{
				printf("\nAh ocurrido un error, intente nuevamente\n");
			}
			break;

		case 2:
			if(modificarpasajero(viviendaMain, TAM))
			{
				printf("Vivienda se ah modificado exitosamente\n");
			}else{
				printf("Ah ocurrido un error, intente nuevamente\n");
			}
			break;

		case 3:
			if(bajaVivienda(viviendaMain, TAM))
			{
				printf("Vivienda se ah dado de baja exitosamente\n");
			}else{
				printf("Ah ocurrido un error, intente nuevamente\n");
			}
			break;

		case 4:
			if(listarViviendas(viviendaMain, TAM))
			{
				printf("Vivienda se ah listado exitosamente\n");
			}else{
				printf("Ah ocurrido un error, intente nuevamente\n");
			}
			break;

		case 5:
			if(listarCensistas(censistaMain))
			{
				printf("Cencistas listados exitosamente\n");
			}else{
				printf("Ah ocurrido un error, intente nuevamente\n");
			}
			break;
		}
	}while(menu != 6);

	return EXIT_SUCCESS;
}
