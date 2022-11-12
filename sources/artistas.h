#ifndef ARTISTAS_H
#define ARTISTAS_H

#include "artista.h"
#include "peso.h"
#include <stdio.h>
#include <stdlib.h>

#define NOT_FOUND -1

typedef struct tArtistas tArtistas;

tArtistas* CriarArtistas();

void AdicionarArtistas(tArtistas* arts, tArtista* art);

void LiberarArtistas(tArtistas* *p);

//Le os tArtista do arquivo que o caminho indica, e retorna um tArtistas com os tArtista lidos já
//ordenados em ordem crescente de id
tArtistas* ListarArtistas(char* caminho);

tArtista* AcharStructArt(tArtistas* arts, char* id);

//Retorna o indice do artista caso o encontre ou retorna NOT_FOUND caso nao o encontre
int AcharIndexArtPeloId(tArtistas* arts, char* id);

//Aqui eh realizada a busca binaria, portanto o vetor deve estar ordenado em ordem crencente de id para
//funcionar. Retorna o indice do artista caso o encontre ou retorna NOT_FOUND caso nao o encontre
int AcharIndexArtPeloIdB(tArtistas* arts, char* id);

tArtista* RetornaArtistaPonteiro(tArtistas* arts, int idx);

void GeraRelatorioArtistas(tArtistas* arts, char* caminho);

#endif