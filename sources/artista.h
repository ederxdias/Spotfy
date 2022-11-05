#ifndef ARTISTA_H
#define ARTISTA_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tArtista tArtista;
tArtista *CriarArtista(char *id, double seg, char *gen, char *nA, int popu);
tArtista *LeArtista(FILE *arq);
void LiberaArtista(tArtista *p);
char *RetNa(tArtista *a);
char *RetNa(tArtista *a);
char *RetId(tArtista *a);
char *RetGen(tArtista *a);
int RetPopu(tArtista *a);
double RetSeg(tArtista *a);
void ImprimirArtista(tArtista *art);


#endif