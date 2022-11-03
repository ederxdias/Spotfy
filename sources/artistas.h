#ifndef ARTISTAS_H
#define ARTISTAS_H

#include "artista.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct tArtistas tArtistas;
tArtistas * CriarArtistas();
void AdicionarArtistas(tArtistas *arts, tArtista *art);
void LiberarArtistas(tArtistas *p);
tArtistas *ListarArtistas(char *caminho);
tArtista * AcharStructArt(tArtistas *arts, char *id);
int AcharIndexArt(tArtistas *arts, char *id);
tArtista * RetornarStructArt(tArtistas *arts, int idx);
#endif