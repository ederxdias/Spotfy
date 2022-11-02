#ifndef ARTISTA_H
#define ARTISTA_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tArtista tArtista;
tArtista *CriarArtista(char *id, double seg, char *gen, char *nA, int popu);
tArtista *LeArtista(FILE *arq);
void LiberarArtistaStr(tArtista *p);
void LiberaArtistaVet(tArtista *p);
char *RetNa(tArtista *a);


#endif