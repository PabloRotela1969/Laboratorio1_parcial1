/*
 * Arcade.h
 *
 *  Created on: 15 oct. 2021
 *      Author: MI COMPU
 */

#ifndef ARCADE_H_
#define ARCADE_H_
#include "Input.h"

typedef struct {
  int idArcade;
  char nacionalidadArcade[30];
  int tipoSonido;
  int cantidadJugadores;
  int capacidadMaxFichas;
  char nombreJuego[64];
  int idSalon;
  int libre;
}eArcade;

/**
 * @brief metodo que permite cargar el array de arracades con valores de prueba
 *
 * @param lista lista ya inicializada de arcades
 */
void harcodearArcade(eArcade lista[]);

/**
 * @brief metodo que recibe la lista de arcades y de cada estructura contenida, le adjudica el valor 1 al campo libres
 * de modo que al cargar un nuevo elemento, se consulte una estructura disponible consultando este campo y se lo cargue a 0 y al borrar
 * se devuelva el valor a 1
 *
 * @param lista de estructuras Arcade lista reci�n creada
 * @param cantidad cantidad m�xima de estructuras dentro de la lista
 */
void prepararVectorArcade( eArcade lista[], int cantidad);

/**
 * @brief la funci�n recorre la lista de estructura buscando la primera que tenga el campo libre en 1, al encotrarla devuelve el indice f�sico de su ubicaci�n
 *
 * @param lista lista inicializada de Arcades
 * @param cantidad cantidad m�xima de estructuras dentro de la lista
 * @return -1 = se pas� la lista en null o una cantidad igual o inferior a cero de elementos m�ximos dentro de la lista
 *         0 o mayor que 0 es el indice f�sico de la estructura encontrada como libre
 */
int buscarLibreArcade( eArcade lista[], int cantidad);


/**
 * @brief metodo que s�lo muestra los t�tulos de cada columnas para mostrar una vez al principio de la lista de arcades
 *
 */
void mostrarCamposArcade();

/**
 * @brief funcion usada para verificar si una lista est� totalmente vac�a o cu�ntos hay cargados
 * usada en BuscarArcadePorID y proximoIdArcade
 *
 * @param lista lista inicializada de Arcades
 * @param cantidad cantidad m�xima de estructuras dentro de la lista
 * @return cantidad de estructuras con el campo libre = 0 o sea, ocupadas
 */
int cantidadDeArcadeCargados( eArcade lista[] , int cantidad);

/**
 * @brief funcion que busca el mayor id de estructuras arcade en la lista  y a ese le suma 1
 * usada para la Alta de arcades
 *
 * @param lista lista inicializada de Arcades
 * @param cantidad cantidad m�xima de estructuras dentro de la lista
 * @return pr�ximo numero de ID para un alta
 */
int proximoIDArcade( eArcade lista[] , int cantidad);

/**
 * @brief funci�n que devuelve el valor del indice de la estructura en la lista que contiene el id suministrado
 *
 * @param lista lista inicializada de Arcades
 * @param cantidad cantidad m�xima de estructuras dentro de la lista
 * @param id proveniente de tipeo del usuario para seleccionar un registro mostrado por men� en pantalla
 * @return devuelve el indice de la lista que contiene el arcade cuyo id se ingres�
 */
int buscarArcadePorID( eArcade lista[] , int cantidad , int id );



#endif /* ARCADE_H_ */
