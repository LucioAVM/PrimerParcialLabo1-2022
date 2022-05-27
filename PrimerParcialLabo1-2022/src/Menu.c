/*
 * Menu.c
 *
 *  Created on: 26 may. 2022
 *      Author: Ususario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Vivienda.h"
#include "Monsalbo.h"

int mostrarMenu(void)
{
	int retorno;

	printf("\n\t\t\tADMINISTRACION DE VIVIENDAS\n"
			"\t\t\t...........................\n\n"
			"1. ALTA\n\n"
			"2. MODIFICACION\n\n"
			"3. BAJA\n\n"
			"4. LISTAR VIVIENDAS\n\n"
			"5. LISTAR CENSISTAS"
			"6. FINALIZAR PROGRAMA\n"
			"Ingrese una opcion:\t");
	fflush(stdin);
	scanf("%d", &retorno);

	return retorno;
}

int altaVivienda(eVivienda viviendaMain[],int TAM, int *idVivienda)
{
	int retorno = 0;

	char calle[25];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int TipoVivienda;// HACER STRUCT
	int LegajoCensista;// OTRA STRUCT

	int validacionCalle;
	int idViviendaAux;

	int libre;

	//BUSCA LIBRE
	libre = eVivienda_ObtenerLibre(viviendaMain, TAM);

	if(libre != -1)
	{
		//PIDE DATOS DEL PASAJERO AL USUARIO
								    //CALLE

		validacionCalle = getStringLetras("\n\nIngresar nombre de la cale:\t", calle);
		if(validacionCalle == -1)
		{
			printf("\n\nERROR, no se pudo ingresar correctamente la calle \n");
		}


						 	//CANTIDAD DE PERSONAS

		cantidadPersonas = getInt("\n\nIngrese la cantidad de personas en la vivienda:\t", 0, 20, 5);



							  //CANTIDAD DE HABITACIONES
		cantidadHabitaciones = getInt("\n\nIngrese estado del vuelo\t", 0, 30, 5);



							  //TIPO DE VIVIENDA
		TipoVivienda = getInt("\n\nIngrese el tipo de vivienda:\n"
				"1.CASA\n"
				"2.DEPARTEMANTE\n"
				"3.CASILLA\n"
				"4.RANCHO\n", 0, 4, 5);


							//LEGAJO DEL CENSISTA
		LegajoCensista = getInt("\n\nIngrese estado del vuelo\t", 0, 100, 5);

		idViviendaAux = *idVivienda;


		idViviendaAux = addVivienda(viviendaMain
				, &idViviendaAux
				, libre
				, calle
				, cantidadPersonas
				, cantidadHabitaciones
				, TipoVivienda
				, LegajoCensista);

		if(idViviendaAux != -1)
		{
			*idVivienda = idViviendaAux;
			retorno = 1;

		}
	}else{
		printf("\nNo se encontro lugar libre en el sistema");
	}
	return retorno;
}

int modificarpasajero(eVivienda viviendaMain[], int TAM)
{
	int retorno;
	int menu;

	int IDIngresado;
	int index;

	int validacion;
	int validacionCalle;

	eVivienda auxiliar;

	retorno = 0;

	mostrarViviendas(viviendaMain, TAM);

	printf("ingrese el ID de la vivienda que desea modificar\t");
	scanf("%d",&IDIngresado);

	index = findViviendaById(viviendaMain, TAM, IDIngresado);

	if(index != -1)
	{
		auxiliar = viviendaMain[index];
		do
		{
			printf("\n\nLista de modificaciones:\n"
					"1- CALLE\n"
					"2- CANTIDAD DE PERSONAS\n"
					"3- CANTIDAD DE HABITACIONES\n"
					"4- TIPO DE VIVIENDA\n"
					"Ingrese la opcion deseada:\t");
			fflush(stdin);
			scanf("%d", &menu);

			switch(menu)
			{

			case 1:
				validacionCalle = getStringLetras("\n\nIngresar nombre de la cale:\t", auxiliar.calle);
				if(validacionCalle == -1)
				{
					printf("\n\nERROR, no se pudo ingresar correctamente la calle \n");
				}
				break;


			case 2:
				//CANTIDAD DE PERSONAS

				auxiliar.cantidadPersonas = getInt("\n\nIngrese la cantidad de personas en la vivienda:\t", 0, 20, 5);
				break;


			case 3:
				//CANTIDAD DE HABITACIONES
				auxiliar.cantidadHabitaciones = getInt("\n\nIngrese estado del vuelo\t", 0, 30, 5);				break;


			case 4:
				//TIPO DE VIVIENDA
				auxiliar.TipoVivienda = getInt("\n\nIngrese el tipo de vivienda:\n"
						"1.CASA\n"
						"2.DEPARTEMANTE\n"
						"3.CASILLA\n"
						"4.RANCHO\n", 0, 4, 5);
				break;


			case 5://queres aplicar las modificaciones (mostrar modificasiones Si o NO
				do
				{

					printf( "ORIGINAL:"
							" ____________________________________________________________________________________________________________\n"
							"|---ID-------CALLE-------CANTIDAD DE PERSONAS-------CANTIDAD DE HABITACIONES-------TIPO DE VIVIENDA----------| \n");
					mostrarUnaVivienda(auxiliar, TAM);

					printf( "MODIFICADO:"
							" __________________________________________________________________________________________________________\n"
							"|---ID-------CALLE-------CANTIDAD DE PERSONAS-------CANTIDAD DE HABITACIONES-------TIPO DE VIVIENDA----------|\n");
					mostrarUnaVivienda(viviendaMain[index], TAM);

					printf("\nDesea realizar las siguientes modificaciones?\n"
							"1_ SI\n"
							"2_ NO\n"
							"Ingrese la opcion deseada:\t");

					scanf("%d",&validacion);
					if(validacion == 1)
					{
						strcpy(viviendaMain[index].calle, auxiliar.calle);
						viviendaMain[index].cantidadPersonas = auxiliar.cantidadPersonas;
						viviendaMain[index].cantidadHabitaciones = auxiliar.cantidadHabitaciones;
						viviendaMain[index].TipoVivienda = auxiliar.TipoVivienda;
						retorno = 1;
					}else{
						if(validacion == 2)
						{
							printf("se han descartado los cambios\n");
						}
					}
				}while(validacion != 1 && validacion != 2);

				break;
			}
		}while(menu != 6);
	}
	return retorno;
}

int bajaVivienda(eVivienda viviendaMain[], int TAM)
{
	int IDIngresado;
	int index;
	int validacion;
	int retorno;

	retorno = 0;

	mostrarViviendas(viviendaMain, TAM);

	printf("ingrese el ID de la vivienda que desea dar de baja\t");
	scanf("%d",&IDIngresado);

	index = findViviendaById(viviendaMain, TAM, IDIngresado);

	printf("\n\tQuiere dar de baja la siguiente vivienda?\n"
			" ____________________________________________________________________________________________________________\n"
			"|---ID-------CALLE-------CANTIDAD DE PERSONAS-------CANTIDAD DE HABITACIONES-------TIPO DE VIVIENDA----------| \n");
	mostrarUnaVivienda(viviendaMain[index], TAM);
	printf("1- SI\n"
			"2- NO\n"
			"Ingrese la opcion deseada:\n");
	scanf("%d",&validacion);

	if(validacion == 1)
	{
		viviendaMain[index].isEmpty = LIBRE;
		printf("la vivienda %d se ah dado de baja exitosamente", IDIngresado);
	}else{
		if(validacion == 2)
		{
			printf("Se han descartados los cambios");
		}else{
			printf("ERROR, ingrese una opcion valida");
		}
	}
	return retorno;
}

void listarViviendas(eVivienda viviendaMain[], int TAM)
{
	ordenarViviendas(viviendaMain, TAM);

	printf(" ____________________________________________________________________________________________________________\n"
			"|---ID-------CALLE-------CANTIDAD DE PERSONAS-------CANTIDAD DE HABITACIONES-------TIPO DE VIVIENDA----------| \n");
	mostrarViviendas(viviendaMain, TAM);
}

