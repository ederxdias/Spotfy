#ifndef ARTISTA_H
#define ARTISTA_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ID1_MAIOR 1
#define ID1_MENOR -1
#define ID1_IGUAL 0

typedef struct tArtista tArtista;

/**
 * @brief Cria um tArtista* por meio dos parametros passados, caso falhe encerra o programa
 * 
 * @param id: uma string que representa o id do artista
 * @param seg: um double que representa a quantidade de seguidores do artista
 * @param gen: uma string que representa os generos musicas do artista
 * @param nA: uma string que representa o nome do artista 
 * @param popu: um int que representa a popularidade do artista 
 * @return tArtista* 
 */
tArtista *CriarArtista(char *id, double seg, char *gen, char *nA, int popu);

/**
 * @brief Le o artista de um arquivo que deve estar aberto em modo leitura, caso 
 * o padrao da linha encontrada nao for o esperado a linha é ignorada e retorna NULL
 * 
 * @param arq: um FILE * que deve estar aberto em modo leitura "r"
 * @return tArtista* 
 */
tArtista *LeArtista(FILE *arq);

/**
 * @brief Libera um tArtista*
 * 
 * @param p: um tArtista** indicando o caminho para o tArtista*
 */
void LiberaArtista(tArtista **p);

/**
 * @brief Retorna o nome do artista
 * 
 * @param a: o tArtista* para que retorne retorne o nome 
 * @return char*: uma strig como o nome do artista
 */
char *RetNa(tArtista *a);

/**
 * @brief Retorna o id do artista
 * 
 * @param a: o tArtista* para que retorne o id 
 * @return char*: uma strig como o id do artista 
 */
char *RetId(tArtista *a);

/**
 * @brief Retorna os generos musicais que o artista faz parte
 * 
 * @param a: o tArtista* para que retorne os generos
 * @return char*: uma strig que representa os generos 
 */
char *RetGen(tArtista *a);

/**
 * @brief Retorna a popularidade do artista
 * 
 * @param a: o tArtista* para que retorne a popularidade
 * @return int: representa a popularidade 
 */
int RetPopu(tArtista *a);

/**
 * @brief Retorna a quantidade de seguidores do artista
 * 
 * @param a: o tArtista* para que retorne a quantidade de seguidores
 * @return double: representa a quantidade de seguidores do artista 
 */
double RetSeg(tArtista *a);

/**
 * @brief Imprime as informações de um artista na tela
 * 
 * @param art: tArtista* para imprimir na tela
 */
void ImprimirArtista(tArtista *art);

/**
 * @brief Retorna a quantidade de musicas que o artista tem em playlist
 * 
 * @param art: o tArtista* para retornar a quantidade de musicas em playlist
 * @return int: representa a quantidade de musicas em playlist
 */
int RetQtdPlayArt(tArtista* art);

/**
 * @brief Incrementa em um a quantidade de musicas em playlist de um artista
 * 
 * @param art: o tArtista* que sera incrementado
 */
void IncrementaQtdPlaylistArtista(tArtista *art);

/**
 * @brief Imprime as informações do artista em um arquivo
 * 
 * @param art: o tArtista* que será impresso no arquivo
 * @param f: o FILE* que deve estar aberto em modo escrita "w"
 */
void ImprimeArtistaArquivo(tArtista* art, FILE * f);

/**
 * @brief Compara os artistas por meio dos id
 * 
 * @param art1: primeiro tArtista* que sera comparado
 * @param art2: segundo tArtista* que sera comparado 
 * @return int: retorna 1 caso o id do primeiro artista for maior que o do segundo e 0 caso contrario 
 */
int EhIdArt1MaiorIdArt2(tArtista* art1, tArtista* art2);

/**
 * @brief Ordena um vetor de artista(tArtista**) em ordem crescente de id
 * 
 * @param art: tArtista** que representa o vetor de tArtista* 
 * @param tam: o tamanho do vetor de tArtista*
 */
void OrdenaArrArtistasCrescenteId(tArtista* *art, int tam);

/**
 * @brief Compara dois ids distintos
 * 
 * @param id1: uma string que representa o primeiro id
 * @param id2: uma string que representa o segundo id 
 * @return int: retorna ID1_IGUAL se os ids forem iguais. retorna ID1_MAIOR se o 
 * id1 for maior que o id2 e retorna ID1_MENOR ser o id1 for menor que o id2
 */
int RelacionaId1ComId2(char* id1, char* id2);

#endif