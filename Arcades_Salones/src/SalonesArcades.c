/*
 * SalonesArcades.c
 *
 *  Created on: 15 oct. 2021
 *      Author: MI COMPU
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SalonesArcades.h"




void mostrarJuegosCargadosSinRepetir(eArcade listaA[], int topeA)
{
	if(listaA != NULL && topeA > 0)
	{
		eArcade listaSinRepetidos[topeA];
		int z = -1;
		int seRepite;
		int topeAreducido = topeA - 1;

		for(int i = 0; i< topeA - 1; i++)
		{
			if(listaA[i].libre == 0 )
			{
				seRepite = 0;
				for(int j = i + 1; j < topeAreducido; j++)
				{
					if(listaA[j].libre == 0 && strcmp(listaA[i].nombreJuego, listaA[j].nombreJuego) == 0)
					{
						seRepite = 1;
						break;
					}
				}
				if(seRepite == 0)
				{
					z++;
					listaSinRepetidos[z] = listaA[i];
				}
			}
		}


		if(z > -1)
		{
			printf("| %64s | \n","NOMBRES DE JUEGOS CARGADOS" );
			for(int i = 0; i<= z; i++)
			{
				printf("| %64s | \n",listaSinRepetidos[i].nombreJuego);
			}
		}

	}
}



int eliminarSalonYsusArcades(eSalon listaS[], int topeS, eArcade listaA[], int topeA)
{
	int error = 1;
	int idSalon;
	int indiceSalon;
	if (listaS != NULL && topeS > 0 && listaA != NULL && topeA > 0)
	{
		mostrarSalonCargados(listaS, topeS, "Eliminar Salones");
		idSalon = inputInt(" Ingrese el ID desde el listado: ");
		indiceSalon = buscarSalonPorID(listaS, topeS, idSalon);
		if (indiceSalon > -1)
		{
			mostrarCamposSalon();
			mostrarUnSalon(listaS[indiceSalon]);

			error = 2;
			if (inputIntDesdeHasta("Confirma con 1, cancela con 2 : ", 1, 2) == 1)
			{
				for(int i = 0; i < topeA; i++)
				{
					if(listaA[i].idSalon == listaS[indiceSalon].idSalon)
					{
						listaA[i].libre = 1;
					}
				}
				listaS[indiceSalon].libre = 1;
				error = 0;
			}
		}
		else
		{
			printf("\n No se encontró el registro buscado \n");
		}
	}
	else
	{
		printf("\n No hay elementos para mostrar \n");
		error = 1;
	}

return error;
}




int altaArcadeConSuSalon(eSalon listaS[], int topeS, eArcade listaA[], int topeA)
{

    int error = 1;
    int indiceArcade;
    int idArcade;
    int idSalon;
    int indiceSalon;
    eArcade nuevoArcade;
    int opcion;
	if(listaS != NULL && topeS > 0 && listaA != NULL && topeA > 0)
	{

		indiceArcade = buscarLibreArcade( listaA, topeA );
		if( indiceArcade > -1)
		{
			    printf("\nALTA DE ARCADE\n");
			    idArcade = proximoIDArcade( listaA, topeA);
				nuevoArcade.idArcade = idArcade;
				inputString(" Ingrese nacionalidad de Arcade : ", nuevoArcade.nacionalidadArcade , 30);
				nuevoArcade.tipoSonido = inputIntDesdeHasta(" ingrese el tipo de Sonido (1 = Mono , 2 = Stereo ):",1,2);
				nuevoArcade.cantidadJugadores = inputInt(" ingrese la cantidad deJugadores : ");
				nuevoArcade.capacidadMaxFichas = inputInt(" ingrese la capacidad Maxima de Fichas : ");
				inputString(" Ingrese nombre del Juego : ", nuevoArcade.nombreJuego , 64);
				mostrarSalonCargados(listaS, topeS, "ELIJA UN SALON");
				do
				{
					opcion = 0;
					idSalon = inputInt("Ingrese el ID del salón :");
					indiceSalon = buscarSalonPorID(listaS, topeS, idSalon);
					if(indiceSalon == -1)
					{
						printf("\n No se encontró el salón con ese ID, vuelva a ingresar uno \n");
						opcion = 1;
					}
				}while(opcion);
				nuevoArcade.idSalon = idSalon;
				nuevoArcade.libre = 0;
    			opcion = inputIntDesdeHasta("Confirma con 1, cancela con 2 : ",1,2);
				error = 2;
				if(opcion == 1)
				{
					  listaA[indiceArcade] = nuevoArcade;
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



int listarArcadesConSuSalon(eSalon listaS[], int topeS, eArcade listaA[], int topeA)
{
	int error = 1;

	if(listaS != NULL && topeS > 0 && listaA != NULL && topeA > 0)
	{
		printf("| %8s | %30s | %10s | %17s | %18s | %64s | %30s  | \n","ID ARC.","NACIONALIDAD ARCADE","TIPO ","CANT. JUGADORES"," MAXFICHAS","NOMBRE JUEGO","SALON" );
		for(int i = 0; i< topeA; i++)
		{
			if(listaA[i].libre == 0 )
			{
				mostrarUnArcade(listaA[i], listaS, topeS);
			}
			error = 0;
		}
	}
	return error;
}


void mostrarUnArcade( eArcade arcade , eSalon listaS[] , int topeS)
{
	char tipo[30];
	if(arcade.tipoSonido == 1)
	{
		strcpy(tipo,"Mono");
	}
	else
	{
		strcpy(tipo,"Estereo");
	}
	for(int j = 0; j < topeS; j++)
	{
		if(listaS[j].libre == 0 && listaS[j].idSalon == arcade.idSalon)
		{

			printf("| %8d | %30s | %10s | %17d | %18d | %64s | %30s  |  \n",arcade.idArcade,arcade.nacionalidadArcade,tipo,arcade.cantidadJugadores,arcade.capacidadMaxFichas,arcade.nombreJuego,listaS[j].nombreSalon );
		}

	}


}




int eliminarArcade(eSalon listaS[], int topeS, eArcade listaA[], int topeA) // punto 6
{
	int error = 1;
    int indice;
    int id;
	if(listaS != NULL && topeS > 0 && listaA != NULL && topeA > 0)
	{

		listarArcadesConSuSalon(listaS, topeS, listaA, topeA);
		id = inputInt(" Ingrese el ID desde el listado: ");
		indice = buscarArcadePorID( listaA, topeA , id);
		 if( indice > -1)
		  {
			   mostrarCamposArcade();
			   mostrarUnArcade( listaA[indice], listaS, topeS);
			   error = 2;
				if( inputIntDesdeHasta("Confirma con 1, cancela con 2 : ",1,2) == 1)
				 {
					  listaA[indice].libre = 1;
					  error = 0;
				 }
		  }
		  else
		   {
				  printf("\n No se encontró el registro buscado \n");
		   }
	}
	else
	{
		 printf("\n No hay elementos para mostrar \n");
		 error = 1;
	}

	return error;
}



int listarSalonesConMasDe4Arcades(eSalon listaS[], int topeS, eArcade listaA[], int topeA)
{
	int error = 1;
	eArcade listaArcadesConMasDe4Salones[topeA];

	int cantidadArcades;
	int indiceEncontrados = -1;
	int indiceSalon = 0;
	if(listaS != NULL && topeS > 0 && listaA != NULL && topeA > 0)
	{
		error = 0;
		for(int i = 0; i < topeA - 1; i++)
		{
			if(listaA[i].libre == 0 )
			{
				cantidadArcades = 1;
				for(int j = i + 1; j <topeA; j++)
				{
					if(listaA[j].libre == 0 && listaA[i].idSalon == listaA[j].idSalon)
					{
						cantidadArcades ++;
					}
				}

				if(cantidadArcades > 4)
				{
					indiceEncontrados ++;
					listaArcadesConMasDe4Salones[indiceEncontrados] = listaA[i];

				}
			}
		}
		if(indiceEncontrados > -1)
		{
			printf("\nLISTA DE SALONES CON MÁS DE 4 ARCADES ENCONTRADOS\n");
			mostrarCamposSalon();
			for(int i = 0; i < indiceEncontrados; i ++)
			{
				indiceSalon = buscarSalonPorID(listaS, topeS, listaArcadesConMasDe4Salones[i].idSalon);
				mostrarUnSalon(listaS[indiceSalon]);
			}
		}

	}
	return error;
}




int arcadesConMas2Jugadores(eSalon listaS[], int topeS, eArcade listaA[], int topeA)
{
	int error = 1;
	mostrarCamposArcade();
	if(listaS != NULL && topeS > 0 && listaA != NULL && topeA > 0)
	{
		error = 0;
		for(int i = 0; i < topeA; i++)
		{
			if(listaA[i].libre == 0 && listaA[i].cantidadJugadores > 2)
			{
				mostrarUnArcade(listaA[i], listaS, topeS);
			}
		}
	}
	return error;
}




int listarDataDeSalonesConSuID(eSalon listaS[], int topeS, eArcade listaA[], int topeA)
{
	int error = 1;
	int cantidadArcades = 0;
	int IdSalon = -1;
	int indiceSalon = -1;
	if(listaS != NULL && topeS > 0 && listaA != NULL && topeA > 0)
	{
		error = 0;
		mostrarSalonCargados(listaS, topeS, "Lista de salones");
		do
		{
			IdSalon = inputInt("Ingrese el ID del salon : ");
			indiceSalon = buscarSalonPorID(listaS, topeS, IdSalon);
			if(indiceSalon == -1)
			{
				printf("\n No se encontró el ID ingresado, vuelva a ingresarlo \n");
			}
		}while(indiceSalon == -1);


		for(int i = 0; i < topeA; i++)
		{
			if(listaA[i].libre == 0 )
			{
				if(listaA[i].idSalon == IdSalon)
				{
					cantidadArcades ++;
				}

			}
		}
		mostrarUnSalon(listaS[indiceSalon]);
		printf( "\n posee %d arcades \n", cantidadArcades);


	}
	return error;
}



int listarArcadesConIDdeSalon(eSalon listaS[], int topeS, eArcade listaA[], int topeA)
{
	int error = 1;

	int IdSalon = -1;
	int indiceSalon = -1;
	if(listaS != NULL && topeS > 0 && listaA != NULL && topeA > 0)
	{
		error = 0;
		mostrarSalonCargados(listaS, topeS, "Lista de salones");
		do
		{
			IdSalon = inputInt("Ingrese el ID del salon : ");
			indiceSalon = buscarSalonPorID(listaS, topeS, IdSalon);
			if(indiceSalon == -1)
			{
				printf("\n No se encontró el ID ingresado, vuelva a ingresarlo \n");
			}
		}while(indiceSalon == -1);

		mostrarCamposArcade();
		for(int i = 0; i < topeA; i++)
		{
			if(listaA[i].libre == 0 )
			{
				if(listaA[i].idSalon == IdSalon)
				{
					mostrarUnArcade(listaA[i], listaS, topeS);
				}

			}
		}


	}
	return error;
}





int salonConMayorCantidadDeArcades(eSalon listaS[], int topeS, eArcade listaA[], int topeA)
{
	int error = 1;
	int frecuencias[topeA];
	int maxFrecuencia = 0;
	int idMax;
    int idSalones[topeA];
	int cantidadArcades;
	int indiceEncontrados = -1;
	int indiceSalon = 0;
	if(listaS != NULL && topeS > 0 && listaA != NULL && topeA > 0)
	{
		error = 0;
		for(int i = 0; i < topeA - 1; i++)
		{
			if(listaA[i].libre == 0 )
			{
				cantidadArcades = 1;
				for(int j = i + 1; j <topeA; j++)
				{
					if(listaA[j].libre == 0 && listaA[i].idSalon == listaA[j].idSalon)
					{
						cantidadArcades ++;
					}
				}

				if(cantidadArcades > 0)
				{
					indiceEncontrados ++;
					frecuencias[indiceEncontrados] = cantidadArcades;
					idSalones[indiceEncontrados] = listaA[i].idSalon;

				}
			}
		}

		for(int i = 0; i <= indiceEncontrados; i++)
		{
			if(i == 0 || maxFrecuencia < frecuencias[i])
			{
				maxFrecuencia = frecuencias[i];
				idMax = idSalones[i];
			}
		}

		if(indiceEncontrados > -1)
		{
			printf("\nSALON CON MAYOR CANTIDAD DE ARCADES ENCONTRADOS\n");
			mostrarCamposSalon();
			indiceSalon = buscarSalonPorID(listaS, topeS, idMax);
			mostrarUnSalon(listaS[indiceSalon]);
			printf("\n CONTIENE %d ARCADES \n", maxFrecuencia);
		}

	}
	return error;
}








int montoMaximoDeUnSalonPorID(eSalon listaS[], int topeS, eArcade listaA[], int topeA)
{
	int error = 1;

	int IdSalon = -1;
	int indiceSalon = -1;
	int cantidadDeFichasMaximoAcumulado = 0;
	float valorFicha = 0.0;
	if(listaS != NULL && topeS > 0 && listaA != NULL && topeA > 0)
	{
		error = 0;
		mostrarSalonCargados(listaS, topeS, "Lista de salones");
		do
		{
			IdSalon = inputInt("Ingrese el ID del salon : ");
			indiceSalon = buscarSalonPorID(listaS, topeS, IdSalon);
			if(indiceSalon == -1)
			{
				printf("\n No se encontró el ID ingresado, vuelva a ingresarlo \n");
			}
		}while(indiceSalon == -1);


		for(int i = 0; i < topeA; i++)
		{
			if(listaA[i].libre == 0 )
			{
				if(listaA[i].idSalon == IdSalon)
				{
					cantidadDeFichasMaximoAcumulado += listaA[i].capacidadMaxFichas;
				}

			}
		}
		if(cantidadDeFichasMaximoAcumulado > 0)
		{
			valorFicha = inputFloat("Ingrese el valor de una ficha en pesos : ");
			printf("El monto máximo que puede recaudar el salon es %5.2f \n", (cantidadDeFichasMaximoAcumulado * valorFicha));
		}
		else
		{
			printf("\n No se encontraron arcades en este salon \n");
		}
	}
	return error;
}






int conJuegoMostrarArcadesQueLoTienen(eSalon listaS[], int topeS, eArcade listaA[], int topeA)
{
	int error = 1;

	char nombreJuegoIngresado[64];
	int cantidad = 0;
	if(listaS != NULL && topeS > 0 && listaA != NULL && topeA > 0)
	{
		error = 0;

		inputString("Ingrese el nombre de un juego :" , nombreJuegoIngresado, 64);


		mostrarCamposArcade();
		for(int i = 0; i < topeA; i++)
		{
			if(listaA[i].libre == 0 )
			{
				if( strcmp(listaA[i].nombreJuego , nombreJuegoIngresado ) == 0)
				{
					mostrarUnArcade(listaA[i], listaS, topeS);
					cantidad++;
				}

			}
		}
		printf("\n El juego %s se encuentra en %d arcades : \n", nombreJuegoIngresado, cantidad);


	}
	return error;
}





void menu(eSalon listaS[], int topeS, eArcade listaA[], int topeA)
{

	if(listaS != NULL && topeS > 0 && listaA != NULL && topeA > 0)
	{
		    int opcion;
		    int limiteOpcion = 4;

				do
				  {

				   printf(" MENU PRINCIPAL\n");
				   printf(" 1 - Menu Salones  \n");
				   printf(" 2 - Menu Arcades \n");
				   printf(" 3 - Menu Informes \n");
				   printf(" 4 - salir \n");
				   opcion = inputIntDesdeHasta(" OPCION: ",1,limiteOpcion);
				   switch(opcion)
				   {
						 case 1:
							menuSalon(listaS, topeS, listaA, topeA);
							break;
						 case 2:
							menuArcade(listaS, topeS, listaA, topeA);
							break;
						 case 3:
							 menuInformes(listaS, topeS, listaA, topeA);
							break;

				   }

				}
		        while(opcion != limiteOpcion);

	}
}


void menuInformes(eSalon listaS[] , int topeS, eArcade listaA[], int topeA)
{
    int opcion;
    int tope = 8;
    int resultado;
    do
      {
       resultado = 0;
       printf(" MENU INFORMES\n");
	   printf(" 1 - listar salones con más de 4 arcades \n");
	   printf(" 2 - lista de arcades con más de 2 jugadores \n");
	   printf(" 3 - mostrar todos los datos de un salon por su ID \n");
	   printf(" 4 - listar data de Arcades por ID de salón \n");
	   printf(" 5 - salon con mayor cantidad de arcades \n");
	   printf(" 6 - monto máximo que puede recaudar un salon por su ID y valor de ficha \n");
	   printf(" 7 - mostrar arcades que contienen un nombre de juego \n");
	   printf(" 8 - salir \n");
       opcion = inputIntDesdeHasta(" OPCION: ",1,tope);
       switch(opcion)
       {
		 case 1:
			resultado = listarSalonesConMasDe4Arcades(listaS, topeS, listaA, topeA);
			break;
		 case 2:
			 resultado = arcadesConMas2Jugadores(listaS, topeS, listaA, topeA);
			break;
		 case 3:
			 resultado = listarDataDeSalonesConSuID(listaS, topeS, listaA, topeA);
			break;
		 case 4:
			 resultado = listarArcadesConIDdeSalon(listaS, topeS, listaA, topeA);
			break;
		 case 5:
			 resultado = salonConMayorCantidadDeArcades(listaS, topeS, listaA, topeA);
			break;
		 case 6:
			 resultado = montoMaximoDeUnSalonPorID(listaS, topeS, listaA, topeA);
			break;
		 case 7:
			 resultado = conJuegoMostrarArcadesQueLoTienen(listaS, topeS, listaA, topeA);
			break;
       }
       switch(resultado)
       {
                  case 0:
                      printf(" ok \n");
                  break;
                  case 1:
                      printf(" operacion terminada con error \n");
                  break;
                  case 2:
                      printf(" operacion cancelada por el usuario \n");;
                   break;
       }
    }while(opcion != tope);
 }





void menuSalon(eSalon listaS[] , int topeS, eArcade listaA[], int topeA)
{
    int opcion;
    int tope = 6;
    int resultado;
    do
      {
       resultado = 0;
       printf(" MENU SALON\n");
       printf(" 1 - alta  \n");
       printf(" 2 - baja \n");
       printf(" 3 - modifica \n");
       printf(" 4 - listar \n");
       printf(" 5 - carga datos de ejemplo \n");
       printf(" 6 - salir \n");
       opcion = inputIntDesdeHasta(" OPCION: ",1,tope);
       switch(opcion)
       {
             case 1:
                resultado = altaSalon(listaS, topeS);
                break;
             case 2:
            	 resultado = eliminarSalonYsusArcades(listaS, topeS, listaA, topeA);
                break;
             case 3:
                resultado = modificaSalon(listaS, topeS);
                break;
             case 4:
                mostrarSalonCargados(listaS, topeS, " Listado ");
                break;
             case 5:
                harcodearSalon(listaS);
                break;
       }
       switch(resultado)
       {
                  case 0:
                      printf(" ok \n");
                  break;
                  case 1:
                      printf(" operacion terminada con error \n");
                  break;
                  case 2:
                      printf(" operacion cancelada por el usuario \n");;
                   break;
       }
    }while(opcion != tope);
 }




void menuArcade(eSalon listaS[] , int topeS, eArcade listaA[], int topeA)
{
    int opcion;
    int tope = 7;
    int resultado;
    do
      {
       resultado = 0;
       printf(" MENU ARCADE\n");
       printf(" 1 - alta  \n");
       printf(" 2 - baja \n");
       printf(" 3 - modifica \n");
       printf(" 4 - listar \n");
       printf(" 5 - imprimir juegos \n");
       printf(" 6 - carga datos de ejemplo \n");
       printf(" 7 - salir \n");
       opcion = inputIntDesdeHasta(" OPCION: ",1,tope);
       switch(opcion)
       {
             case 1:
            	 resultado = altaArcadeConSuSalon(listaS, topeS, listaA, topeA);
                break;
             case 2:
            	 resultado = eliminarArcade(listaS, topeS, listaA, topeA);
                break;
             case 3:
                resultado = modificaArcade(listaS, topeS, listaA, topeA);
                break;
             case 4:
            	 resultado = listarArcadesConSuSalon(listaS, topeS, listaA, topeA);
                break;
             case 5:
			    mostrarJuegosCargadosSinRepetir(listaA, topeA);
			 break;
             case 6:
                harcodearArcade(listaA);
                break;
       }
       switch(resultado)
       {
                  case 0:
                      printf(" ok \n");
                  break;
                  case 1:
                      printf(" operacion terminada con error \n");
                  break;
                  case 2:
                      printf(" operacion cancelada por el usuario \n");;
                   break;
       }
    }while(opcion != tope);
 }






int modificaArcade(eSalon listaS[] , int topeS, eArcade listaA[], int topeA)
{
      int error = 1;
      if( listaA != NULL && topeA != 0)
     {
      int indice;
      int id;
      int idSalon;
      int indiceSalon;
      eArcade provisorio;
      int opcion;


			listarArcadesConSuSalon(listaS, topeS, listaA, topeA);
			id = inputInt(" Ingrese el id del registro a modificar ; ");
			indice = buscarArcadePorID( listaA, topeA, id );
			 if( indice > -1)
			  {
				 mostrarUnArcade( listaA[indice], listaS, topeS);
				 provisorio = listaA[indice];
				 printf("\nITEMS A MOFICAR DE UN ARCADE\n ");
				 printf(" 1 - nacionalidad del Arcade\n ");
				 printf(" 2 - tipo de Sonido\n ");
				 printf(" 3 - cantidad de Jugadores\n ");
				 printf(" 4 - capacidad Maxma de Fichas\n ");
				 printf(" 5 - nombre de Juego\n ");
				 printf(" 6 - Salon\n ");
				 opcion = inputIntDesdeHasta("Elija opción del 1 al 6",1,6);
				 error = 2;
				 switch(opcion)
				 {
				  case 1:
				   inputString(" Ingrese nacionalidad del Arcade : " , provisorio.nacionalidadArcade , 30);
						break;
				  case 2:
					provisorio.tipoSonido = inputIntDesdeHasta(" Ingrese tipo de Sonido ( 1 = Mono, 2 = Estereo ) ",1,2);
						break;
				  case 3:
					provisorio.cantidadJugadores = inputInt(" Ingrese cantidad de Jugadores ");
						break;
				  case 4:
					provisorio.capacidadMaxFichas = inputInt(" Ingrese capacidad Maxima de Fichas ");
						break;
				  case 5:
				   mostrarJuegosCargadosSinRepetir(listaA, topeA);
				   inputString(" Ingrese nombre del Juego : " , provisorio.nombreJuego , 64);
						break;
				  case 6:

					  mostrarSalonCargados(listaS, topeS, "Lista de salones para seleccionar" );
					  do
					  {
						  idSalon = inputInt("Ingrese el ID del salon : ");
						  indiceSalon = buscarSalonPorID(listaS, topeS, idSalon);
						  if(indiceSalon == -1)
						  {
							  printf("\nNo se encontró el salón con ese ID, ingréselo nuevamente \n");
						  }
					  }while(indiceSalon == -1);
					  provisorio.idSalon = idSalon;
						break;
				   }

				  opcion = inputIntDesdeHasta("Confire pulsando 1 , cancela con 0 ",0,1);
				  if(opcion)
				  {
					   listaA[indice] = provisorio;
					   error = 0;
				  }

			 }
       }
    return error;
}



