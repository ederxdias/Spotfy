#ifndef ARTISTAS_H
#define ARTISTAS_H

#include "artista.h"
#include "peso.h"
#include <stdio.h>
#include <stdlib.h>

#define NOT_FOUND -1

typedef struct tArtistas tArtistas;

/**
 * @brief Cria um tArtistas* alocado dinamicamente na memoria
 * 
 * @return tArtistas* 
 */
tArtistas* CriarArtistas();

/**
 * @brief Adiciona um tArtista* ao vetor dentro de tArtistas*
 * 
 * @param arts: tArtistas* que recebera o tArtista*
 * @param art: tArtista* que sera colocado no tArtistas*
 */
void AdicionarArtistas(tArtistas* arts, tArtista* art);

/**
 * @brief Libera o tArtistas*
 * 
 * @param p: o tArtistas** que representa o caminho do tArtistas*
 */
void LiberarArtistas(tArtistas* *p);

/**
 * @brief Le os tArtista do arquivo que o caminho indica, e retorna um tArtistas com os tArtista lidos já
 * ordenados em ordem crescente de id
 * 
 * @param caminho: uma strig que representa o caminho do arquivo
 * @return tArtistas*: um tArtitas* ordenado em ordem crescente de id
 */
tArtistas* ListarArtistas(char* caminho);

/**
 * @brief Procura o indice do tArtista* no tArtistas*
 * 
 * @param arts: tArtistas* para buscar o indice
 * @param id: id do tArtista* a ser procurado 
 * @return int: indice do artista caso o encontre ou retorna NOT_FOUND caso nao o encontre
 */
int AcharIndexArtPeloId(tArtistas* arts, char* id);

/**
 * @brief Aqui eh realizada a busca binaria, portanto o vetor deve estar ordenado em ordem crencente de 
 * id para funcionar
 * 
 * @param arts: tArtistas* para buscar o indice 
 * @param id: id do tArtista* a ser procurado 
 * @return int: indice do artista caso o encontre ou retorna NOT_FOUND caso nao o encontre
 */
int AcharIndexArtPeloIdB(tArtistas* arts, char* id);

/**
 * @brief Retorna o artista(tArtista*) correspondente ao indice(idx) passado
 * 
 * @param arts: tArtistas* que o tArtista* procurado se encontra
 * @param idx: int que representa o indice do artista no tArtistas* 
 * @return tArtista*: artista correspondente ao indice, caso nao exista tal artista retorna NULL 
 */
tArtista* RetornaArtistaPonteiro(tArtistas* arts, int idx);

/**
 * @brief Produz um relatorio com o ranking dos artistas com mais musicas em playlist em um arquivo
 * 
 * @param arts: tArtistas* que o ranking sera criado
 * @param caminho: caminho passado deve ser apenas do diretorio que o arquivo sera salvo
 */
void GeraRelatorioArtistas(tArtistas* arts, char* caminho);

#endif