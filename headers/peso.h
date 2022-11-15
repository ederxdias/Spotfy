#ifndef _PESO_H_
#define _PESO_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct tPeso tPeso;

tPeso* CriaPeso(int item, double peso);

void LiberaPeso(tPeso* *p);

int RetornaItem(tPeso* p);

double RetornaPeso(tPeso* p);

void OrdenaPeloPesoDecrescente(tPeso** p, int tam);

void OrdenaPeloPesoCrescente(tPeso** p, int tam);

int EhPeso1MaiorQePeso2(const void* p1, const void* p2);

int EhPeso1MenorQePeso2(const void* p1, const void* p2);

#endif