/*
 * Input.c
 *
 *  Created on: 15 oct. 2021
 *      Author: MI COMPU
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"

/**
 * @brief funcion que recibe un mensaje y permite capturar las pulsaciones alfanuméricas de un solo carácter
 *
 * @param mensaje mensaje indicativo de lo que se pretende recibir
 * @return el caracter pulsado por el usuario
 */
char inputChar(char mensaje[])
{
    char respuesta;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c", &respuesta);
    return respuesta;
}

/**
 * @brief  funcion que recibe un mensaje y una lista de valores posibles, muestra el mensaje y espera que se pulse alguno de esos caracteres
 * si se ingresó alguno, lo devuelve, sino muestra mensaje de error y vuelve a pedir algún caracter
 *
  * @param mensaje mensaje indicativo de lo que se pretende recibir
 * @param posibles lista de caracteres como respuesta admisible
 * @return el carácter validado
 */
char inputCharPosibles(char mensaje[], char posibles[])
{
    char respuesta;
    int mal = 1;
    do
    {

        printf("%s",mensaje);
        fflush(stdin);
        scanf("%c", &respuesta);
        for(int i = 0; i<strlen(posibles); i++)
        {
            if(respuesta == posibles[i])
            {
                mal = 0;
                break;
            }
        }
        if(mal)
        {
            printf("\nPOR FAVOR, INGRESE UN VALOR PERMITIDO\n");
        }

    }
    while(mal);


    return respuesta;
}



/**
 * @brief método que recibe un mensaje, el campo a cargar y un tamaño límite de capacidad del campo, muestra mensaje indicativo
 *  capta todas las pulsaciones alfanumericas hasta la cantidad pasada y la devuelve en el parametro
 *
 * @param mensaje mensaje mensaje indicativo de lo que se pretende recibir
 * @param salida lista que recibe la cadena
 * @param tam cantidad máxima permitida de caracteres
 */
void inputString(char mensaje[], char salida[], int tam)
{
    printf("%s",mensaje);
    fflush(stdin);
    fgets(salida,tam,stdin);
    salida[strlen(salida)-1]='\0';
    fflush(stdin);
}




/**
 * @brief función que recibe un mensaje indicativo, y por cada pulsación valida que se trate de un caracter numérico incluido el signo menos
 * de modo que se valida que el ingreso de caracteres sólo contengan números positivos o negativos sin otro carácter más, o sea, enteros
 *
 * @param  mensaje mensaje mensaje indicativo de lo que se pretende recibir
 * @return numero ingresado entero
 */
int inputInt(char mensaje[])
{
    int i;
    int largo;
    int mal;
    int tam = 60;
    char salida[tam];

    do
    {
        printf("%s",mensaje);
        fflush(stdin);
        fgets(salida,tam,stdin);
        largo = strlen(salida) - 1;
        salida[largo]='\0';
        for(i=0;i<largo;i++)
        {
            switch(salida[i])
            {
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case '0':
                case '-':
                    mal = 0;
                break;
                default:
                    mal = 1;
                break;

            }
            if(mal)
            {
                printf("\n Debe ser numerica la entrada, intente nuevamente \n");
                break;
            }
        }

    }while(mal);

    return atoi(salida);

}


/**
 * @brief función que recibe un mensaje indicativo, y por cada pulsación valida que se trate de un caracter numérico incluido el signo menos y el punto
 * de modo que se valida que el ingreso de caracteres sólo contengan números positivos o negativos o con coma
 *
 * @param  mensaje mensaje mensaje indicativo de lo que se pretende recibir
 * @return numero ingresado flotante
 */
float inputFloat(char mensaje[])
{
    int i;
    int largo;
    int mal;
    int tam = 60;
    char salida[tam];

    do
    {
        printf("%s",mensaje);
        fflush(stdin);
        fgets(salida,tam,stdin);
        largo = strlen(salida) - 1;
        salida[largo]='\0';
        for(i=0;i<largo;i++)
        {
            switch(salida[i])
            {
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case '0':
                case '-':
                case '.':
                    mal = 0;
                break;
                default:
                    mal = 1;
                break;

            }
            if(mal)
            {
                printf("\n Debe ser numerica la entrada, intente nuevamente \n");
                break;
            }
        }

    }while(mal);

    return atof(salida);

}


/** \brief ingresando un mensaje indicativo y dos numeros, desde y hasta, devuelve un numero entero comprendido en desde y hasta
 *
 * \param mensaje[] char mensaje de lo que se espera recibir
 * \param desde int tope mínimo
 * \param hasta int tope máximo
 * \return int número entero comprendido entre tope minimo y tope máximo
 *
 */
int inputIntDesdeHasta(char mensaje[], int desde,int hasta)
{
    int i;
    int largo;
    int mal;
    int tam = 60;
    char salida[tam];
    int retorno;

    do
    {
        printf("%s ",mensaje);
        fflush(stdin);
        fgets(salida,tam,stdin);
        largo = strlen(salida) - 1;
        salida[largo]='\0';
        for(i=0;i<largo;i++)
        {
            switch(salida[i])
            {
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case '0':
                case '-':
                    mal = 0;
                break;
                default:
                    mal = 1;
                break;

            }
            if(mal)
            {
                printf("\n Debe ser numerica la entrada, intente nuevamente \n");
                break;
            }
        }

        retorno = atoi(salida);
        if( retorno < desde || retorno > hasta)
        {
            mal = 1;
            printf("\n Debe estar comprendido entre %d y %d, intente nuevamente \n",desde,hasta);
        }

    }while(mal);


    return retorno;

}




/** \brief ingresando mensaje indicativo, flotante desde y flotante hasta, devuelve un flotante comprendido entre ambos
 *
 * \param mensaje[] char mensaje de lo que se espera recibir
 * \param desde float tope inferior
 * \param hasta float tope superior
 * \return float decimal entre ambos topes
 *
 */
float inputFloatDesdefHastaf(char mensaje[],float desde,float hasta)
{
    int i;
    int largo;
    int mal;
    int tam = 60;
    char salida[tam];
    float retorno;

    do
    {
        printf("%s , ( valores permitidos desde %f hasta %f ) ",mensaje,desde,hasta);
        fflush(stdin);
        fgets(salida,tam,stdin);
        largo = strlen(salida) - 1;
        salida[largo]='\0';
        for(i=0;i<largo;i++)
        {
            switch(salida[i])
            {
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case '0':
                case '-':
                case '.':
                    mal = 0;
                break;
                default:
                    mal = 1;
                break;

            }
            if(mal)
            {
                printf("\n Debe ser numerica la entrada, intente nuevamente \n");
                break;
            }
        }
        retorno = atof(salida);
        if( retorno < desde || retorno > hasta)
        {
            mal = 1;
            printf("\n Debe estar comprendido entre %f y %f, intente nuevamente \n",desde,hasta);
        }

    }while(mal);


    return retorno;
}




