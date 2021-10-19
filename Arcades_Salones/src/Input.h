/*
 * Input.h
 *
 *  Created on: 15 oct. 2021
 *      Author: MI COMPU
 */

#ifndef INPUT_H_
#define INPUT_H_

char inputChar(char mensaje[]);
int inputInt(char mensaje[]);
char inputCharPosibles(char mensaje[], char posibles[]);
void inputString(char mensaje[], char salida[], int tam);
float inputFloat(char mensaje[]);
int inputIntDesdeHasta(char mensaje[], int desde,int hasta);
float inputFloatDesdefHastaf(char mensaje[],float desde,float hasta);


#endif /* INPUT_H_ */
