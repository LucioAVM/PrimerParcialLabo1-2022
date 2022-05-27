/*
 ============================================================================
 Name        : PrimerParcialLabo1-2022.c
 Author      : Monsalbo lucio
 Version     : 0.90
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
#define TamCENSISTA 3

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
	int bandera;

	bandera = 0;

	idVivienda = 19999;

	eVivienda_Inicializar( viviendaMain, TAM);

	do
	{
		menu = mostrarMenu();

		switch(menu)
		{
		case 1:
			if(altaVivienda(viviendaMain,TAM, &idVivienda))//si la funcion devuelve 0 es verdadero(usar para validar)
			{
				printf("\n-----Vivienda dada de alta exitosamente----\n");
				bandera = 1;
			}else{
				printf("\nAh ocurrido un error, intente nuevamente\n");
			}
			break;

		case 2:
			if(modificarVivienda(viviendaMain, TAM) && bandera == 1)
			{
				printf("Vivienda se ah modificado exitosamente\n");
			}else{
				printf("Ah ocurrido un error, intente nuevamente\n");
			}
			break;

		case 3:
			if(bajaVivienda(viviendaMain, TAM) && bandera == 1)
			{
				printf("Vivienda se ah dado de baja exitosamente\n");
			}else{
				printf("Ah ocurrido un error, intente nuevamente\n");
			}
			break;

		case 4:
			listarViviendas(viviendaMain, TAM && bandera == 1);
			break;

		case 5:
			listarCensistas(censistaMain, TamCENSISTA);
			break;

		case 6:
			printf( "\n           GRACIAS POR UTILIZAR ESTE PROGRAMA\n"
					"             PRODUCIDO POR Monsalbo lucio\n"
					"              EDITADO POR Lucio Monsalbo\n"
					"         BUILDEADO POR Alejandro Lucio Monsalbo\n"
					"        TESTEADO POR Valerio Alejandro Monsalbo\n"
					"        ENVIADO POR Monsalbo Lucio Alejandro Valerio\n"
					"   AGRADECIMIENTO ESPECIAL A Lucio Alejandro Valerio Monsalbo\n");
			break;
		}
	}while(menu != 6);

	return EXIT_SUCCESS;
}
