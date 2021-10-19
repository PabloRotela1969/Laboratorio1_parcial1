/*
 * SalonesArcades.h
 *
 *  Created on: 15 oct. 2021
 *      Author: MI COMPU
 */

#ifndef SALONESARCADES_H_
#define SALONESARCADES_H_
#include "Salon.h"
#include "Arcade.h"
#include "Input.h"

/**
 * @brief metodo de menu principal, consta de tres submen�es, el de salones, arcades e informes
 *
 * @param listaS lista inicializada de estructura salon
 * @param topeS cantidad m�xima de estructuras salon
 * @param listaA lista inicializada de estructura arcade
 * @param topeA cantidad m�xima de estructuras arcade
 */
void menu(eSalon listaS[], int topeS, eArcade listaA[], int topeA);

/**
 * @brief Al borrar un sal�n, se eliminan l�gicamente los arcades que tienen su mismo id de sal�n ( punto 2 )
 * Se pide al usuario que ingrese el id del sal�n, se valida , si se encontr�, se muestra aparte y luego se itera por toda la lista de arcades
 * para pasar a libre = 1 a todas las estructuras arcade cuyo idSal�n sea el seleccionado
 *
 * @param listaS lista inicializada de estructura salon
 * @param topeS cantidad m�xima de estructuras salon
 * @param listaA lista inicializada de estructura arcade
 * @param topeA cantidad m�xima de estructuras arcade
 * @return 1 = si hubo problemas triviales como alguna de las dos listas vinieron en NULL o alguno de los dos topes de lista en cero
 *         0 = operaci�n exitosa
 *         2 = operaci�n cancelada por el usuario
 */
int eliminarSalonYsusArcades(eSalon listaS[], int topeS, eArcade listaA[], int topeA);

/**
 * @brief funci�n que permite dar de alta un nuevo arcade y agregarle un sal�n a seleccionar de una grilla por su id
 * la func�n crea una estructura provisoria arcade, busca una estructura libre en la lista de arcades y retiene su indice en la lista, permite cargar todos los campos
 * el de sal�n lo ingresa el usuario y se valida existente y no borrado, si el usuario confirma, se reemplaza esa estructura provisoria en la lista con el indice inicial encontrado
 *
 * @param listaS lista inicializada de estructura salon
 * @param topeS cantidad m�xima de estructuras salon
 * @param listaA lista inicializada de estructura arcade
 * @param topeA cantidad m�xima de estructuras arcade
 * @return 1 = si hubo problemas triviales como alguna de las dos listas vinieron en NULL o alguno de los dos topes de lista en cero
 *         0 = operaci�n exitosa
 *         2 = operaci�n cancelada por el usuario
 */
int altaArcadeConSuSalon(eSalon listaS[], int topeS, eArcade listaA[], int topeA);

/**
 * @brief funci�n que itera en la lista de arcades y por cara uno lleno, lo manda a la funci�n mostrar un arcade, que permite mostrar los datos del arcade y los de su sal�n
 *
 * @param listaS lista inicializada de estructura salon
 * @param topeS cantidad m�xima de estructuras salon
 * @param listaA lista inicializada de estructura arcade
 * @param topeA cantidad m�xima de estructuras arcade
 * @return 1 = si hubo problemas triviales como alguna de las dos listas vinieron en NULL o alguno de los dos topes de lista en cero
 *         0 = operaci�n exitosa
 *         2 = operaci�n cancelada por el usuario
 */
int listarArcadesConSuSalon(eSalon listaS[], int topeS, eArcade listaA[], int topeA);

/**
 * @brief funcion que mostrando la grilla de arcades, permite elegir por ID el que el usuario quiera borrar, encuentra el indice correspondiente a ese arcade
 * si el usuario confirma, el campo libre de esa estructura, pasa a valer 1 con lo que se disponibiliza para alojar otro registro nuevo
 *
 * @param listaS lista inicializada de estructura salon
 * @param topeS cantidad m�xima de estructuras salon
 * @param listaA lista inicializada de estructura arcade
 * @param topeA cantidad m�xima de estructuras arcade
 * @return 1 = si hubo problemas triviales como alguna de las dos listas vinieron en NULL o alguno de los dos topes de lista en cero
 *         0 = operaci�n exitosa
 *         2 = operaci�n cancelada por el usuario
 */
int eliminarArcade(eSalon listaS[], int topeS, eArcade listaA[], int topeA);


/**
 * @brief metodo que permite operar con las estructuras salon, tanto en su ABM como para listar en forma de grilla los salones o cargar datos de ejemplo
 *
 * @param listaS lista inicializada de estructura salon
 * @param topeS cantidad m�xima de estructuras salon
 * @param listaA lista inicializada de estructura arcade
 * @param topeA cantidad m�xima de estructuras arcade
 */
void menuSalon(eSalon listaS[] , int topeS, eArcade listaA[], int topeA);



/**
 * @brief metodo que permite operar con las estructuas de arcade en su ABM con relaci�n a salones, listar en forma de grilla, y ver todos los juegos cargados, as� como cargar datos de ejemplo
 *
 * @param listaS lista inicializada de estructura salon
 * @param topeS cantidad m�xima de estructuras salon
 * @param listaA lista inicializada de estructura arcade
 * @param topeA cantidad m�xima de estructuras arcade
 */
void menuArcade(eSalon listaS[] , int topeS, eArcade listaA[], int topeA);

/**
 * @brief metodo que permite encontrar cada uno de los informes solicitados
 *
 * @param listaS lista inicializada de estructura salon
 * @param topeS cantidad m�xima de estructuras salon
 * @param listaA lista inicializada de estructura arcade
 * @param topeA cantidad m�xima de estructuras arcade
 */
void menuInformes(eSalon listaS[] , int topeS, eArcade listaA[], int topeA);


/**
 * @brief metodo creada exprofeso para el punto 5 del enunciado, cuando se quiere modificar un arcade, se itera buscando un elemento compar�ndolo con el resto por el campo nombre de juego
 * si encuentra un repetido, carga una bandera de repetidos, si luego de correr el resto de los elementos no encontr� ninguno, ese elemento se carga en un array de lista sin repeticiones
 * luego se toma el siguiente elemento y se repite el proceso con el resto de los elementos, de modo que al recorrer la lista original, la lista sin repeticiones queda cargada
 * al final, si encontr� alg�n elemento, se muestran todos los encontrados
 *
 * @param listaA  lista inicializada de Arcades
 * @param topeA cantidad cantidad m�xima de estructuras dentro de la lista
 */
void mostrarJuegosCargadosSinRepetir(eArcade listaA[], int topeA);


/**
 * @brief funci�n de informes  iterando la lista de arcades, toma un elemento y busca en el resto de la lista a todas las estructuras que tengan el mismo idSal�n ( punto A )
 * al encontrarlo incrementa un contador si al final de la iteraci�n ese contador supera el valor 4, guarda esa estructura encontrada en una lista provisoria para recomenzar el proceso
 * al agotar las iteraciones itera por los arcades encontrados y con su ID busca el indice para mostrar el todos los datos del sal�n encontrado correspondiente a ese arcade
 * sabiendo que un arcade solo pertenece a un sal�n
 *
 * @param listaS lista inicializada de estructura salon
 * @param topeS cantidad m�xima de estructuras salon
 * @param listaA lista inicializada de estructura arcade
 * @param topeA cantidad m�xima de estructuras arcade
 * @return 1 = si hubo problemas triviales como alguna de las dos listas vinieron en NULL o alguno de los dos topes de lista en cero
 *         0 = operaci�n exitosa
 */
int listarSalonesConMasDe4Arcades(eSalon listaS[], int topeS, eArcade listaA[], int topeA);

/**
 * @brief funcion que permite modificar los datos de una estructura arcade, se le pide al usuario que elija un arcade de la grilla por su id, se valida que exista y con ese id
 * se busca el indice de la estructura en la lista al que corresponde, se copian los datos actuales a una estructura provisoria, se le pide al usuario que ingrese el campo de la estructura
 * que desea modificar, se pide al usuario nuevo valor para ese campo que se almacena en la estructura provisoria, si el usuario confirma, la estructura del indice encontrado se reemplaza
 * con los valores de la estructura provisoria
 *
 * @param listaS lista inicializada de estructura salon
 * @param topeS cantidad m�xima de estructuras salon
 * @param listaA lista inicializada de estructura arcade
 * @param topeA cantidad m�xima de estructuras arcade
 * @return 1 = si hubo problemas triviales como alguna de las dos listas vinieron en NULL o alguno de los dos topes de lista en cero
 *         0 = operaci�n exitosa
 *         2 = operaci�n cancelada por el usuario
 */
int modificaArcade(eSalon listaS[] , int topeS, eArcade listaA[], int topeA);


/**
  * @brief metodo complementario a "listarArcadesConSuSalon" , recibe una estructura arcade y con su id de salon itera en la lista de salones hasta encontrar la estructura sal�n al que refiere
 * y lo muestra
 * @param arcade la estructura arcade
 * @param listaS lista inicializada de estructura salon
 * @param topeS cantidad m�xima de estructuras salon
 */
void mostrarUnArcade( eArcade arcade , eSalon listaS[] , int topeS);

/**
 * @brief funcion que recorre la lista de arcades consultando el campo de cada estructura, cantidadJugadores , si es mayor a 2 se muestra ( punto B )
 *
 * @param listaS lista inicializada de estructura salon
 * @param topeS cantidad m�xima de estructuras salon
 * @param listaA lista inicializada de estructura arcade
 * @param topeA cantidad m�xima de estructuras arcade
 * @return 1 = si hubo problemas triviales como alguna de las dos listas vinieron en NULL o alguno de los dos topes de lista en cero
 *         0 = operaci�n exitosa
 */
int arcadesConMas2Jugadores(eSalon listaS[], int topeS, eArcade listaA[], int topeA);

/**
 * @brief funci�n que pide un ID de sal�n al usuario desde la grilla de salones no borrados, se valida existencia y con el id del salon se itera en la lista de arcades ( punto C )
 * contando la cantidad de arcades que tienen ese mismo c�digo de sal�n, para al final mostrar los datos del sal�n y el resumen de la cantidad de arcades que se encontraron
 *
 * @param listaS lista inicializada de estructura salon
 * @param topeS cantidad m�xima de estructuras salon
 * @param listaA lista inicializada de estructura arcade
 * @param topeA cantidad m�xima de estructuras arcade
 * @return 1 = si hubo problemas triviales como alguna de las dos listas vinieron en NULL o alguno de los dos topes de lista en cero
 *         0 = operaci�n exitosa
 */
int listarDataDeSalonesConSuID(eSalon listaS[], int topeS, eArcade listaA[], int topeA);


/**
 * @brief funci�n que permite listar todos los arcades ingresando el id desde la grilla de salones ( punto D )
 * luego de ingresar el id del sal�n y validarse su existencia, se itera la lista de arcades estructura por estructura donde el campo idSalon coincida con el id ingresado, mostrando cada arcade
 *
 * @param listaS lista inicializada de estructura salon
 * @param topeS cantidad m�xima de estructuras salon
 * @param listaA lista inicializada de estructura arcade
 * @param topeA cantidad m�xima de estructuras arcade
 * @return 1 = si hubo problemas triviales como alguna de las dos listas vinieron en NULL o alguno de los dos topes de lista en cero
 *         0 = operaci�n exitosa
 */
int listarArcadesConIDdeSalon(eSalon listaS[], int topeS, eArcade listaA[], int topeA);

/**
 * @brief funci�n itera por el array de arcades, toma uno y busca en el resto de la lista, todos los que coincidan con el id de sal�n del primero ( punto E )
 * por cada encuentro incrementa un contador, al final de la b�squeda, guarda ese cantidad y el id del sal�n correspondiente, repite este proceso por todos los arcades
 * al terminar, itera por las cantidades encontradas buscando la mayor, sin perder el id del sal�n
 * al final, muestra los datos del sal�n por el id y muestra la cantidad mayor de veces en que fue encontrado entre los arcades
 *
 *
 * @param listaS lista inicializada de estructura salon
 * @param topeS cantidad m�xima de estructuras salon
 * @param listaA lista inicializada de estructura arcade
 * @param topeA cantidad m�xima de estructuras arcade
 * @return 1 = si hubo problemas triviales como alguna de las dos listas vinieron en NULL o alguno de los dos topes de lista en cero
 *         0 = operaci�n exitosa
 */
int salonConMayorCantidadDeArcades(eSalon listaS[], int topeS, eArcade listaA[], int topeA);



/**
 * @brief funcion que muestra la grilla de salones y permite al usuario seleccionar uno por su ID ( punto F )
 * Luego suma de todos los arcades de ese sal�n, el campo cantidad maxima de fichas , pide al usuario el valor unitario de la ficha en pesos
 * y muestra al final, la multiplicaci�n de ese valor por el acumulado
 *
 * @param listaS lista inicializada de estructura salon
 * @param topeS cantidad m�xima de estructuras salon
 * @param listaA lista inicializada de estructura arcade
 * @param topeA cantidad m�xima de estructuras arcade
 * @return 1 = si hubo problemas triviales como alguna de las dos listas vinieron en NULL o alguno de los dos topes de lista en cero
 *         0 = operaci�n exitosa
 */
int montoMaximoDeUnSalonPorID(eSalon listaS[], int topeS, eArcade listaA[], int topeA);


/**
 * @brief funcion que pide al usuario que ingrese el nombre de un juego ( punto G )
 * y luego itera en la lista de arcades buscando estructura por estructura en el campo nombre del juego, cada vez que encuentra una que coincide, muestra los datos del arcade
 *
 * @param listaS lista inicializada de estructura salon
 * @param topeS cantidad m�xima de estructuras salon
 * @param listaA lista inicializada de estructura arcade
 * @param topeA cantidad m�xima de estructuras arcade
 * @return 1 = si hubo problemas triviales como alguna de las dos listas vinieron en NULL o alguno de los dos topes de lista en cero
 *         0 = operaci�n exitosa
 */
int conJuegoMostrarArcadesQueLoTienen(eSalon listaS[], int topeS, eArcade listaA[], int topeA);



/**
 * @brief funcion que permite ordenar la lista de arcades por todos sus campos operables por el usuario ( EXCEPTO campo libre ) incluso por el nombre de los salones
 *
 * @param listaS lista inicializada de estructura salon
 * @param topeS cantidad m�xima de estructuras salon
 * @param listaA lista inicializada de estructura arcade
 * @param topeA cantidad m�xima de estructuras arcade
 * @return 1 = si hubo problemas triviales como alguna de las dos listas vinieron en NULL o alguno de los dos topes de lista en cero
 *         0 = operaci�n exitosa
 */
int ordenarListaArcades(eSalon listaS[], int topeS, eArcade listaA[], int topeA);

#endif /* SALONESARCADES_H_ */
