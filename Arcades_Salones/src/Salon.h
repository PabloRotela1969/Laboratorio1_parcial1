/*
 * Salon.h
 *
 *  Created on: 15 oct. 2021
 *      Author: MI COMPU
 */

#ifndef SALON_H_
#define SALON_H_
#include "Input.h"
typedef struct {
  int idSalon;
  char nombreSalon[30];
  char direccionSalon[30];
  int tipoSalon;
  int libre;
}eSalon;

/**
 * @brief carga la lista de salones con valores de prueba
 *
 * @param lista de salones inicializada
 */
void harcodearSalon(eSalon lista[]);

/**
 * @brief recibe una lista de estrucutras vacías y le carga a cada una en su campo libre un 1, de modo que al dar el alta sea filtrando
 * la lista por este campo
 *
 * @param lista recién creada de estructuras vacías
 * @param cantidad cantidad máxima de estructuras dentro de la lista
 */
void prepararVectorSalon( eSalon lista[], int cantidad);

/**
 * @brief recibe la lista inicializada de estructuras y la cantidad máxima de estructuras, itera estructura por estructura hasta encontrar la primera
 * con campo libre = 1 y devuelve el índice físico en la lista
 *
 * @param lista de salones inicializada
 * @param cantidad cantidad máxima de estructuras dentro de la lista
 * @return
 */
int buscarLibreSalon( eSalon lista[], int cantidad);

/**
 * @brief muestra los titulos de la "grilla" de salones al momento de listarlos porque se necesita una sola vez
 *
 */
void mostrarCamposSalon();

/**
 * @brief recibe la estructura y se encarga de mostrar cada uno de sus campos acorde a los titulos
 *
 * @param elemento estructura a mostrar sus campos
 */
void mostrarUnSalon( eSalon elemento);

/**
 * @brief recibe la lista y su cantidad máxima de estructuras tipo salón, iterándolas, cuenta las que tienen el campo libre = 0, o sea, las que están ocupadas
 *
 * @param lista de salones inicializada
 * @param cantidad cantidad máxima de estructuras dentro de la lista
 * @return cantidad de salones cargados en la lista
 */
int cantidadDeSalonCargados( eSalon lista[] , int cantidad);

/**
 * @brief recibe la lista y su cantidad máxima de estructuras tipo salón, iterándolas, le pasa cada una al metodo Mostrar un salón previa llamada al mostrar campos
 * de esta forma arma una "grilla" con los datos visibles de los salones ( no se muestra el campo libre ) , además se puede paginar al llenar una cantidad de 10 salones
 * pulsando ENTER se muestran de a 10 elementos por pantalla
 *
 * @param lista de salones inicializada
 * @param cantidad cantidad máxima de estructuras dentro de la lista
 * @param mensaje mensaje de tículo para justificar la grilla
 * @return 1 = problema de validación trivial, o la lista vino en NULL o la cantidad de estructuras máximas de la lista, vino en 0
 *         0 = operación terminada exitosamente
 */
int mostrarSalonCargados( eSalon lista[] , int cantidad, char mensaje[]);

/**
 * @brief funcion que recibe la lista y su cantidad máxima de estructuras salón y calcula el máximo id entre cada estructura para devolver el máximo más 1
 * para usar en las altas como futuro ID
 *
 * @param lista de salones inicializada
 * @param cantidad cantidad máxima de estructuras dentro de la lista
 * @return el ID listo para usar en un alta de salón
 */
int proximoIDSalon( eSalon lista[] , int cantidad);

/**
 * @brief funcion que recibe la lista y su cantidad máxima de estructuras salón y un ID ingresado por el usuario, itera buscando la estructura cuyo id coincida con el ingresado
 * devolviendo el indice físico de la ubicación de esa estructura dentro de la lista
 *
 * @param lista de salones inicializada
 * @param cantidad cantidad máxima de estructuras dentro de la lista
 * @param id el ID ingresado por el usuario a buscar
 * @return el indice físico de ubicación en la lista de la estructura con el ID encontrado
 */
int buscarSalonPorID( eSalon lista[] , int cantidad , int id );

/**
 * @brief funcion que permite cargar un nuevo salón, se busca una estructura disponible en la lista, se crea una estructura provisoria, se le consigue un ID automático
 * y se carga, se le ofrece al usuario confirmar o cancelar
 * si el usuario confirma, se copia esa estructura a la de la lista con el indice disponible encontrado
 *
 * @param lista de salones inicializada
 * @param cantidad cantidad máxima de estructuras dentro de la lista
 * @return 1 = se pasó la lista en null o una cantidad igual o inferior a cero de elementos máximos dentro de la lista
 *         0 = operación completada exitosamente
 */
int altaSalon( eSalon lista[] , int cantidad  );

/**
 * @brief funcion que recibe la lista y su tamaño, muestra todas sus estructuras cargadas y permite seleccionar al usuario por el ID la que necesita modificar
 * encuentra el indice de tal estructura y crea una estructura provisoria y copia el valor de esa estructura encontrada a la provisoria
 * luego le muestra un menú con los campos que puede modificar, con el campo elegido por el usuario a continuación le pide que carge el nuevo valor que se reemplazará en la estructura provisoria
 * si el usuario confirma la modificación, se reemplaza en la lista, la estructura con el indice encontrado, los valores de la estructura provisoria
 *
 * @param lista de salones inicializada
 * @param cantidad cantidad máxima de estructuras dentro de la lista
 * @return 1 = se pasó la lista en null o una cantidad igual o inferior a cero de elementos máximos dentro de la lista
 *         0 = operación completada exitosamente
 */
int modificaSalon( eSalon lista[] , int cantidad  );


#endif /* SALON_H_ */
