/*
 * Salon.c
 *
 *  Created on: 15 oct. 2021
 *      Author: MI COMPU
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Salon.h"


void harcodearSalon(eSalon lista[])
{

  int idSalons[10] = {10,11,12,13,14,15,16,17,18,19};
   char nombreSalons[10][30] = {"alfa","beta","gamma", "delta", "epsilon", "zeta","eta","theta", "iota", "kappa"};
   char direccionSalons[10][30] = {"Cucha cucha 23","San Martin de Tours 34","Guardia Vieja 55", "Los Aljibes 223", "Los Ceibos 103", "23 de Octubre 101","Los Platanos 220","Washington 991", "Tucuman 554", "Camacua 989"};
  int tipoSalons[10] = {1,1,2,1,2,1,1,1,2,2};
  int libres[10] = {0,0,0,0,0,0,0,0,0,0};

for(int i = 0; i < 10; i++)
{
   lista[i].idSalon = idSalons[i];
   strcpy(lista[i].nombreSalon , nombreSalons[i]);
   strcpy(lista[i].direccionSalon , direccionSalons[i]);
   lista[i].tipoSalon = tipoSalons[i];
   lista[i].libre = libres[i];

  }
}


void prepararVectorSalon( eSalon lista[], int cantidad)
{

   for(int i = 0; i<cantidad; i++)
   {

         lista[i].libre = 1;
    }
}


int buscarLibreSalon( eSalon lista[], int cantidad)
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



void mostrarCamposSalon()
{
     printf("| %7s | %30s | %30s | %9s  | \n","ID","NOMBRE SALON","DIR. SALON","TIPOSALON" );
}




void mostrarUnSalon( eSalon elemento)
{
	char tipo[30];
	if(elemento.tipoSalon == 1)
	{
		strcpy(tipo,"Shopping");
	}
	else
	{
		strcpy(tipo,"Local");
	}
     printf("| %7d | %30s | %30s | %9s  |  \n",elemento.idSalon,elemento.nombreSalon,elemento.direccionSalon,tipo );
}




int cantidadDeSalonCargados( eSalon lista[] , int cantidad)
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



int mostrarSalonCargados( eSalon lista[] , int cantidad, char mensaje[])
{

int error = 1;
 int NoHayParaMostrar = 1;
 int cantidadElementosPorPagina = 10;
 float resto;
if(lista != NULL && cantidad > 0 && cantidadDeSalonCargados( lista,cantidad) > 0)
{
   printf(" %s \n", mensaje);
   mostrarCamposSalon();
   for(int i = 0; i<cantidad; i++)
   {
       if(lista[i].libre == 0)
       {
             error = 0;
             resto  = i % cantidadElementosPorPagina;
             if ( resto  == 0 && i > 0 )
             {
                   inputChar("Pulse enter para continuar : ");
                      mostrarCamposSalon();
             }
            NoHayParaMostrar = 0;
          mostrarUnSalon(lista[i]);
      }
  }
  if(  NoHayParaMostrar )
  {
       printf(" no hay elementos para mostrar\n");
  }
  }
return error;
}




int ordenarSalonesCargados( eSalon lista[] , int cantidad)
{

   int error = 1;
   int campo;
   eSalon aux;
   if(lista != NULL && cantidad > 0 && cantidadDeSalonCargados( lista,cantidad) > 0)
   {
	   printf(" ELIJA CAMPO DE ORDENAMIENTO \n");
	   printf(" 0. ID\n");
	   printf(" 1. Nombre\n");
	   printf(" 2. Direccion\n");
	   printf(" 3. tipo\n");
	   error = 0;
	   campo = inputIntDesdeHasta(" Ingrese campo por numero : ", 0, 3);

	   for(int i = 0; i<cantidad -1; i++)
	   {
		   if(lista[i].libre == 0)
		   {
			   for(int j = i + 1; j<cantidad; j++ )
		       {
				   if(lista[j].libre == 0)
				   {
					   switch(campo)
					   {
					   case 0:
						   if(lista[i].idSalon > lista[j].idSalon)
						   {
							   aux = lista[i];
							   lista[i] = lista[j];
							   lista[j] = aux;
						   }
						   break;

					   case 1:
						   if(strcmp(lista[i].nombreSalon, lista[j].nombreSalon) > 0)
						   {
							   aux = lista[i];
							   lista[i] = lista[j];
							   lista[j] = aux;
						   }
						   break;
					   case 2:
						   if(strcmp(lista[i].direccionSalon, lista[j].direccionSalon) > 0)
						   {
							   aux = lista[i];
							   lista[i] = lista[j];
							   lista[j] = aux;
						   }
						   break;
					   case 3:
						   if(lista[i].tipoSalon > lista[j].tipoSalon)
						   {
							   aux = lista[i];
							   lista[i] = lista[j];
							   lista[j] = aux;
						   }
						   break;
					   }
				   }

			   }
		   }
	   }
  }

return error;
}











int proximoIDSalon( eSalon lista[] , int cantidad)
{

   int max = 0;
   if(lista != NULL && cantidad > 0 && cantidadDeSalonCargados( lista,cantidad) > 0)

   {
     for(int i = 0; i<cantidad; i++)

     {
       if((lista[i].libre == 0 && max < lista[i].idSalon))

        {
         max = lista[i].idSalon;
         }
      }
      max++;
    }
   return max;
}



int buscarSalonPorID( eSalon lista[] , int cantidad , int id )
{
   int encontrado = -1;
   if(lista != NULL && cantidad > 0 && cantidadDeSalonCargados( lista,cantidad) > 0)
   {
     for(int i = 0; i<cantidad; i++)

     {
       if((lista[i].libre == 0 && lista[i].idSalon == id))

        {
         encontrado = i;
         }
      }
    }
   return encontrado;
}


int altaSalon( eSalon lista[] , int cantidad  )
{
     int error = 1;
     int indice;
     int id;
      eSalon nuevo;
      int opcion;
      if( lista != NULL && cantidad != 0)
       {
                indice = buscarLibreSalon( lista, cantidad );
                 if( indice > -1)
                  {
                       printf("alta de Salon\n");
                       id = proximoIDSalon( lista, cantidad);
                        nuevo.idSalon = id;
                        inputString(" Ingrese nombreSalon : ", nuevo.nombreSalon , 30);
                        inputString(" Ingrese direccionSalon : ", nuevo.direccionSalon , 30);
                        nuevo.tipoSalon = inputIntDesdeHasta(" ingrese el tipoSalon ( 1 = Shopping , 2 = Local ) : ",1,2);
                        nuevo.libre = 0;
                        opcion = inputIntDesdeHasta("Confirma con 1, cancela con 2 : ",1,2);
                        error = 2;
                        if(opcion == 1)
                        {
                              lista[indice] = nuevo;
                              error = 0;
                        }
                  }
                  else
                  {
                          printf("\n No hay más espacio disponible \n");
                  }
      }
    return error;
}




int modificaSalon( eSalon lista[] , int cantidad  )
{
      int error = 1;
      if( lista != NULL && cantidad != 0)
     {
      int indice;
      int id;
      eSalon provisorio;
      int opcion;
                mostrarSalonCargados( lista, cantidad, " Listado para modificar ");
                id = inputInt(" Ingrese el id del registro a modificar ; ");
                indice = buscarSalonPorID( lista, cantidad, id );
                 if( indice > -1)
                  {
                     mostrarUnSalon( lista[indice]);
                     provisorio = lista[indice];
                     printf("\nSELECCIONE DE LA LISTA LO QUE DESEA MODIFICAR \n");
                     printf("  1 - nombre Salon\n ");
                     printf(" 2 - direccion de Salon\n ");
                     printf(" 3 - tipo de Salon\n ");

                     opcion = inputIntDesdeHasta("Elija opción del 1 al 3",1,3);
                     error = 2;
                     switch(opcion)
                     {
						  case 1:
						   inputString("Ingrese nombre de Salon : " , provisorio.nombreSalon , 30);
								break;
						  case 2:
						   inputString("Ingrese direccionSalon : " , provisorio.direccionSalon , 30);
								break;
						  case 3:
							provisorio.tipoSalon = inputIntDesdeHasta("Ingrese tipoSalon ( 1 = Shopping , 2 = Local ) : ",1,2);
								break;
                       }
                       opcion = inputIntDesdeHasta("Confire pulsando 1 , cancela con 0 ",0,1);
                       if(opcion)
                       {
                           lista[indice] = provisorio;
                           error = 0;
                       }

                 }
                 else
                 {
                	 printf("\n No se encontró el registro con el ID ingresado \n");

                 }
       }
    return error;
}


