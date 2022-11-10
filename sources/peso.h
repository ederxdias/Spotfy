#ifndef _PESO_H_
#define _PESO_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct tPeso tPeso;

tPeso* CriaPeso(int item, int peso);

void LiberaPeso(tPeso* *p);

int RetornaItem(tPeso* p);

double RetornaPeso(tPeso* p);

void OrdenaPeloPesoDecrescente(tPeso** p, int tam);

#endif