#ifndef PROPIEDADES_H
#define PROPIEDADES_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct tPropiedades tPropiedades;

tPropiedades* CriaPropriedades(double dance, double energy, double speech, double acous, double inst, int key,
                               double live, double vale, double loud, double temp, int time_s, int mode);

void LiberaPropiedades(tPropiedades** p);

void ImprimirPropiedades(tPropiedades *p);

double RetornaDanceProp(tPropiedades* p);

double RetornaEnergProp(tPropiedades* p);

int RetornaModeProp(tPropiedades* p);

double RetornaSpeechProp(tPropiedades* p);

double RetornaAcoustProp(tPropiedades* p);

double RetornaInstruProp(tPropiedades* p);

double RetornaLivenessProp(tPropiedades* p);

double RetornaValencProp(tPropiedades* p);

double DistanciaEntrePropriedades(tPropiedades* p1, tPropiedades* p2);

#endif