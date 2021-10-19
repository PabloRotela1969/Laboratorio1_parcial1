/*
 * Arcade.c
 *
 *  Created on: 15 oct. 2021
 *      Author: MI COMPU
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arcade.h"



void harcodearArcade(eArcade lista[])
{
  int idArcades[20] = {10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,17,28,29};
  char nacionalidadArcades[20][30] = {"Argentina","Estadounidense","Brasileña", "Argentina", "Argentina", "Uruguaya","Alemana", "Estadounidense", "Alemana","Estadounidense","Brasileña", "Argentina", "Argentina", "Uruguaya","Uruguaya","Alemana", "Estadounidense", "Alemana","Estadounidense","Brasileña"};
  int tipoSonidos[20] = {1,1,2,2,2,1,1,2,2,1,2,2,1,2,2,1,2,2,1,1};
  int cantidadJugadoress[20] = {10,11,12,3,4,1,6,4,4,4,8,8,12,14,1,2,4,6,4,8};
  int capacidadMaxFichass[20] = {1,3,6,2,6,8,2,8,6,8,12,16,18,20,4,6,8,12,14,6};
  char nombreJuegos[20][64] = {"primero","segundo","tercero", "cuarto","quinto","sexto","septimo","juego8","juego9","juego10","juego11", "juego12","juego13","juego14","juego16","juego17","juego18","juego19", "juego20", "juego21"};
  int idSalons[20] = {10,11,12,10,10,10,10,15,15,15,15,15,16,17,17,19,19,19,19,19};
  int libres[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

for(int i = 0; i < 20; i++)
{
   lista[i].idArcade = idArcades[i];
   strcpy(lista[i].nacionalidadArcade , nacionalidadArcades[i]);
   lista[i].tipoSonido = tipoSonidos[i];
   lista[i].cantidadJugadores = cantidadJugadoress[i];
   lista[i].capacidadMaxFichas = capacidadMaxFichass[i];
   strcpy(lista[i].nombreJuego , nombreJuegos[i]);
   lista[i].idSalon = idSalons[i];
   lista[i].libre = libres[i];

  }
}


void prepararVectorArcade( eArcade lista[], int cantidad)
{
   for(int i = 0; i<cantidad; i++)
   {

         lista[i].libre = 1;
   }
}


int buscarLibreArcade( eArcade lista[], int cantidad)
{
	int respuesta = -1;
	if(lista != NULL && cantidad > 0)
	{
	   for(int i = 0; i<cantidad; i++)
	   {
		   if(lista[i].libre == 1)
		   {
			 respuesta = i;
			 break;
		   }
		}
	}

 return respuesta;
}


void mostrarCamposArcade()
{
     printf("| %8s | %30s | %10s | %17s | %18s | %64s | %30s  | \n","IDARCADE","NACIONALIDAD ARCADE","TIPOS","CANT.JUGADORES","MAX FICHAS","NOMBRE JUEGO","SALON" );
}




int cantidadDeArcadeCargados( eArcade lista[] , int cantidad)
{

int respuesta = 0;

if(lista != NULL && cantidad > 0)
{

   for(int i = 0; i<cantidad; i++)
   {

       if(lista[i].libre == 0)
       {

         respuesta++;
       }
    }
}
 return respuesta;
}




int proximoIDArcade( eArcade lista[] , int cantidad)
{

   int max = 0;
   if(lista != NULL && cantidad > 0 && cantidadDeArcadeCargados( lista,cantidad) > 0)

   {
     for(int i = 0; i<cantidad; i++)

     {
       if((lista[i].libre == 0 && max < lista[i].idArcade))

        {
         max = lista[i].idArcade;
         }
      }
      max++;
    }
   return max;
}


int buscarArcadePorID( eArcade lista[] , int cantidad , int id )
{
   int encontrado = -1;
   if(lista != NULL && cantidad > 0 && cantidadDeArcadeCargados( lista,cantidad) > 0)
   {
     for(int i = 0; i<cantidad; i++)

     {
       if((lista[i].libre == 0 && lista[i].idArcade == id))

        {
         encontrado = i;
         }
      }
    }
   return encontrado;
}






