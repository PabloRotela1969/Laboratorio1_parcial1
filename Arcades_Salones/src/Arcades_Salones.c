#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SalonesArcades.h"


#define MAXsalones 20
#define MAXarcades 30


int main(void)
{
    setbuf(stdout, NULL);
    eSalon listaDeSalons[MAXsalones];
    prepararVectorSalon(  listaDeSalons, MAXsalones);
    eArcade listaDeArcades[MAXarcades];
    prepararVectorArcade(  listaDeArcades, MAXarcades);
    menu( listaDeSalons, MAXsalones, listaDeArcades, MAXarcades );
}

