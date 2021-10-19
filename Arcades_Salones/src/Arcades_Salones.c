#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SalonesArcades.h"


#define MAXsalones 100
#define MAXarcades 1000


int main(void)
{
    setbuf(stdout, NULL);
    eSalon listaDeSalons[MAXsalones];
    prepararVectorSalon(  listaDeSalons, MAXsalones);
    eArcade listaDeArcades[MAXarcades];
    prepararVectorArcade(  listaDeArcades, MAXarcades);
    menu( listaDeSalons, MAXsalones, listaDeArcades, MAXarcades );
}

