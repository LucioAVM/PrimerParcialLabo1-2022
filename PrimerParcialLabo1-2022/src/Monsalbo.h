/*
 * Monsalbo.h
 *
 *  Created on: 20 may. 2022
 *      Author: Monsalbo lucio
 */

#ifndef MONSALBO_H_
#define MONSALBO_H_

/**
 * DESCRIPCION	pide y valida un float ingresado por el usuario
 *
 * PARAMETRO	float* resultado
 * PARAMETRO	char* mensaje
 * PARAMETRO	char* mensajeError
 * PARAMETRO	int minimo
 * PARAMETRO	int reintentos
 *
 * RETORNO		-1 = ERROR  0 = todo ok
 */
int getFloat(float* resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


/**
 * DESCRIPCION	pide y valida un int ingresado por el usuario
 *
 * PARAMETRO	char mensaje[]
 * PARAMETRO	int minimo
 * PARAMETRO	int maximo
 * PARAMETRO	int reintentos
 *
 * RETORNO		-1 = ERROR  != int ingresado
 */
int getInt(char mensaje[], int minimo, int maximo, int reintentos);


/**
 * DESCRIPCION	pide y valida un char ingresado por el usuario
 *
 * PARAMETRO	char resultado[]
 * PARAMETRO	int minimo
 * PARAMETRO	int maximo
 * PARAMETRO	int reintentos
 *
 * RETORNO		-1 = ERROR  0 = TODO OK
 */
int getChar(char resultado[], char mensaje[], char mensajeError[], int reintentos);


/**
 * DESCRIPCION	pide y valida un string solo de letras ingresado por el usuario
 *
 * PARAMETRO	char mensaje[]
 * PARAMETRO	char input[]
 *
 * RETORNO		-2 = SIN INTENTOS  -1 = ERROR  0 = TODO OK
 */
int getStringLetras(char mensaje[], char input[]);


/**
 * DESCRIPCION	pide y valida un string ingresado por el usuario
 *
 * PARAMETRO 	char mensaje[]
 * PARAMETRO 	char input[]
 *
 * RETORNO		void
 */
void getString(char mensaje[],char input[]);


/**
 * DESCRIPCION	valida un string solo letras ingresado por el usuario
 *
 * PARAMETRO	char str[]
 *
 * RETORNO		-1 ERROR  0 = TODO OK
 */
int soloLetras(char str[]);


/**
 * DESCRIPCION	 valida un array de solo numeros ingresado por el usuario
 *
 * PARAMETRO	char mensaje[]
 *
 * RETORNO		-2 = SIN INTENTOS  -1 = ERROR  0 = TODO OK
 */
int getNumeros(char mensaje[]);


/**
 * DESCRIPCION	pide un int al usuario
 *
 * PARAMETRO	char mensaje[]
 *
 * RETORNO		el numero ingresado
 */
int getDataNum(char mensaje[]);


/**
 * DESCRIPCION	valida entre si o no
 *
 * PARAMETRO	char *texto
 *
 * RETORNO		1 = SI  2 = NO
 */
int validacionS_N(char *texto);


/**
 * DESCRIPCION	valida entre si o no (MUESTRA UN INT)
 *
 * PARAMETRO	char *texto
 * PARAMETRO	int parametro
 *
 * RETORNO		1 = SI  2 = NO
 */
int validacionS_NParametrizadoInt(char *texto, int parametro);

#endif /* MONSALBO_H_ */
