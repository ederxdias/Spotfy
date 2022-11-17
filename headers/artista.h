#ifndef ARTISTA_H
#define ARTISTA_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ID1_MAIOR 1
#define ID1_MENOR -1
#define ID1_IGUAL 0

typedef struct tArtista tArtista;

tArtista *CriarArtista(char *id, double seg, char *gen, char *nA, int popu);

//Le o artista de um arquivo que deve estar aberto em modo leitura, caso o padrao da linha encontrada
//nao for o esperado a linha é ignorada e retorna NULL
tArtista *LeArtista(FILE *arq);

void LiberaArtista(tArtista **p);

//Retorna nome do artista
char *RetNa(tArtista *a);

//Retorna id do artista
char *RetId(tArtista *a);

//Retorna generos do artista
char *RetGen(tArtista *a);

//Retorna a popularidade do artista
int RetPopu(tArtista *a);

//Retorna a quantidade de seguidores do artista
double RetSeg(tArtista *a);

void ImprimirArtista(tArtista *art);

//Retorna quantidade de musicas que o artista tem em playlist
int RetQtdPlayArt(tArtista* art);

//Aumenta em um a quantidade de playlist que a musica do artista participa
void IncrementaQtdPlaylistArtista(tArtista *art);

void ImprimeArtistaArquivo(tArtista* art, FILE * f);

int EhIdArt1MaiorIdArt2(tArtista* art1, tArtista* art2);

void OrdenaArrArtistasCrescenteId(tArtista* *art, int tam);

//Compara os ids, retorna ID1_IGUAL se os ids forem iguais. retorna ID1_MAIOR se
//o id1 for maior que o id2 e retirna ID1_MENOR ser o id1 for menor que o id2
int RelacionaId1ComId2(char* id1, char* id2);

#endif