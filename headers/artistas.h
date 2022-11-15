#ifndef ARTISTAS_H
#define ARTISTAS_H

#include "artista.h"
#include "peso.h"
#include <stdio.h>
#include <stdlib.h>

#define NOT_FOUND -1

typedef struct tArtistas tArtistas;

tArtistas* CriarArtistas();

//Adiciona um tArtista ao vetor dentro de tArtistas
void AdicionarArtistas(tArtistas* arts, tArtista* art);

void LiberarArtistas(tArtistas* *p);

//Le os tArtista do arquivo que o caminho indica, e retorna um tArtistas com os tArtista lidos já
//ordenados em ordem crescente de id
tArtistas* ListarArtistas(char* caminho);

//Retorna o indice do artista caso o encontre ou retorna NOT_FOUND caso nao o encontre
int AcharIndexArtPeloId(tArtistas* arts, char* id);

//Aqui eh realizada a busca binaria, portanto o vetor deve estar ordenado em ordem crencente de id para
//funcionar. Retorna o indice do artista caso o encontre ou retorna NOT_FOUND caso nao o encontre
int AcharIndexArtPeloIdB(tArtistas* arts, char* id);

//Retorna o artista(tArtista*) correspondente ao indice(idx) passado, caso nao exista tal artista retorna NULL
tArtista* RetornaArtistaPonteiro(tArtistas* arts, int idx);

//Relatorio com o ranking dos artistas com mais musicas em playlist, caminho passado deve ser apenas do
//diretorio que o arquivo sera salvo
void GeraRelatorioArtistas(tArtistas* arts, char* caminho);

#endif