#ifndef PROPIEDADES_H
#define PROPIEDADES_H

#include "stdio.h"
#include "stdlib.h"

typedef struct tPropiedades tPropiedades;

tPropiedades* CriaPropriedades(double dance, double energy, double speech, double acous, double inst, int key,
                               double live, double vale, double loud, double temp, int time_s, int mode);

void LiberaPropiedades(tPropiedades** p);

void ImprimirPropiedades(tPropiedades *p);

#endif