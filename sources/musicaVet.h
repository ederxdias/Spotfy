#ifndef _MUSICAVET_H_
#define _MUSICAVET_H_

#include "musica.h"

typedef struct tMusicaVet tMusicaVet;

tMusicaVet* InicializaVetorMusicas();

tMusicaVet* LeMusicasDoArquivo(char* caminho);

void AdicionaMusicaAoVetMusicas(tMusicaVet *v, tMusica* m);

char** CriaUmaMatrizDeChar(int qtdLinha, int qtdChars);

void LiberaMatrizDeChar(char **m, int qtdLinha, int qtdChars);

void LiberaVetorMusicas(tMusicaVet *vet);

#endif