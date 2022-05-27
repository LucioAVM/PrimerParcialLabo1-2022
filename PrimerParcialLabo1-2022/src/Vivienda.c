/*
 * Vivienda.c
 *
 *  Created on: 26 may. 2022
 *      Author: Ususario
 */

#include <string.h>
#include "vivienda.h"

int eVivienda_Inicializar(eVivienda viviendaMain[], int TAM)
{
	int i;
	int retorno;

	retorno = 1;

	if (viviendaMain != NULL && TAM > 0)
	{
		for (i = 0; i < TAM; i++)
		{
			viviendaMain[i].isEmpty = LIBRE;
		}
		retorno = 0;
	}
	return retorno;
}


int eVivienda_ObtenerID(int idVivienda)
{
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	idVivienda = idVivienda+1;

	return idVivienda;
}

int eVivienda_ObtenerLibre(eVivienda viviendaMain[], int TAM)
{
	int retorno = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (viviendaMain != NULL && TAM > 0)
	{
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++)
		{
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (viviendaMain[i].isEmpty == 0)
			{
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int addVivienda(eVivienda viviendaMain[]
		, int *idViviendaAux
		, int libre
		, char *calle
		, int cantidadPersonas
		, int cantidadHabitaciones
		, int TipoVivienda
		, int LegajoCensista)
{
	int retorno;
	int validacion;
	int idAuxiliar;

	validacion = -1;
	retorno = 0;

	if(viviendaMain != NULL && libre > -1 && calle != NULL && cantidadPersonas > 0 && cantidadHabitaciones > 0 && TipoVivienda < 4 && TipoVivienda < 0 && LegajoCensista < 0)
	{
		eVivienda auxiliar;

		strcpy(auxiliar.calle, calle);
		auxiliar.cantidadPersonas = cantidadPersonas;
		auxiliar.cantidadHabitaciones = cantidadHabitaciones;
		auxiliar.TipoVivienda = TipoVivienda;
		auxiliar.LegajoCensista = LegajoCensista;

		do
		{
			printf("\nEsta seguro que quiere dar de alta la vivienda ingresado?"
					"\n1- SI"
					"\n2- NO\n"
					"\nIngrese opcion:\t");
			scanf("%d", &validacion);
		}while(validacion != 1 && validacion != 2);

		if(validacion == 1)
		{
			idAuxiliar = *idViviendaAux;
			*idViviendaAux = eVivienda_ObtenerID(idAuxiliar);

			viviendaMain[libre].idVivienda = idAuxiliar;
			strcpy(viviendaMain[libre].calle, auxiliar.calle);
			viviendaMain[libre].cantidadPersonas = auxiliar.cantidadPersonas;
			viviendaMain[libre].cantidadHabitaciones = auxiliar.cantidadHabitaciones;
			viviendaMain[libre].TipoVivienda = auxiliar.TipoVivienda;
			viviendaMain[libre].LegajoCensista = auxiliar.LegajoCensista;

			viviendaMain[libre].isEmpty = OCUPADO;

			retorno = idAuxiliar;
		}else{
			printf("\nAlta cancelada");
		}
	}
	return retorno;
}

void idATipo(int idVivienda, char tipoVivinda[])
{
	switch(idVivienda)
	{
	case 1:
		strcpy(tipoVivinda,"CASA");
		break;
	case 2:
		strcpy(tipoVivinda,"DEPARTAMENTO");
		break;
	case 3:
		strcpy(tipoVivinda,"CASILLA");
		break;
	case 4:
		strcpy(tipoVivinda,"RANCHO");
		break;
	}
}

void mostrarUnaVivienda(eVivienda viviendaMain, int TAM)
{
	int id;
	char calle[25];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int idVivienda;
	char tipoVivienda[25];
	int LegajoCensista;

	id = viviendaMain.idVivienda;
	strcpy(calle, viviendaMain.calle);
	cantidadPersonas = viviendaMain.cantidadPersonas;
	cantidadHabitaciones = viviendaMain.cantidadHabitaciones;

	idVivienda = viviendaMain.idVivienda;
	idATipo(idVivienda,tipoVivienda);

	LegajoCensista = viviendaMain.LegajoCensista;



	printf( " %4d        %4s      %5d        %5d            %5s                   %5d 			\n",id ,calle, cantidadPersonas, cantidadHabitaciones, tipoVivienda,LegajoCensista);
}

void mostrarViviendas(eVivienda viviendaMain[], int TAM)
{
	int i;

	printf( " ________________________________________________________________________________________________________________________\n"
			"|---ID-------CALLE-------CANTIDAD DE PERSONAS-------CANTIDAD DE HABITACIONES-------TIPO DE VIVIENDA-------LEGAJO CENSISTA| \n");

	for(i = 0; i < TAM; i++)
	{
		if(viviendaMain[i].isEmpty == OCUPADO)
		{
			mostrarUnaVivienda(viviendaMain[i],TAM);
		}
	}
	printf( "|_____________________________________________________________________________________________________________________| \n");
}

int findViviendaById(eVivienda viviendaMain[], int TAM, int id)
{
	int retorno = -1;
	int i;

	if (viviendaMain != NULL && TAM > 0)
	{
		for (i = 0; i < TAM; i++)
		{
			if (viviendaMain[i].idVivienda == id && viviendaMain[i].isEmpty == OCUPADO)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

void ordenarViviendas(eVivienda viviendaMain[], int TAM)
{
    int i;
    int j;
    int retornoCmp;
    eVivienda auxiliar;

    for(i=0; i<TAM-1; i++)
    {
    	for(j=i+1; j<TAM; j++)
    	{
    		retornoCmp = strcmp(viviendaMain[i].calle, viviendaMain[j].calle);
    		if(retornoCmp == 1)
    		{
    			auxiliar = viviendaMain[i];
    			viviendaMain[i] = viviendaMain[j];
    			viviendaMain[j] = auxiliar;
    		}else{
    			if(retornoCmp == 0 && viviendaMain[i].cantidadPersonas < viviendaMain[j].cantidadPersonas)
    			{
    				auxiliar = viviendaMain[i];
    				viviendaMain[i] = viviendaMain[j];
    				viviendaMain[j] = auxiliar;
    			}
    		}
    	}
    }
}