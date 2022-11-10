#ifndef ARTISTAS_H
#define ARTISTAS_H

#include "artista.h"
#include "peso.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct tArtistas tArtistas;

tArtistas * CriarArtistas();

void AdicionarArtistas(tArtistas *arts, tArtista *art);

void LiberarArtistas(tArtistas **p);

tArtistas *ListarArtistas(char *caminho);

tArtista * AcharStructArt(tArtistas *arts, char *id);

int AcharIndexArt(tArtistas *arts, char *id);

tArtista * RetornarArtistaPonteiro(tArtistas *arts, int idx);

void MudarArtista(tArtistas *arts, tArtista *art, int idx);

void ImprimirArtistas(tArtistas *arts, int idx);

void AdicionarQtdArt(tArtistas *arts, int qtd);

void RealocarArtistas(tArtistas *arts, int qtdA);

void LiberarVetorArts(tArtistas **arts);

void GeraRelatorioArtistas(tArtistas* arts, char* caminho);

#endif