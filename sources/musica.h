#ifndef MUSICA_H
#define MUSICA_H

#include "tData.h"
#include "artistas.h"
#include "propiedades.h"

typedef struct tMusica tMusica;

tMusica *CriaMusica(char* id, char* nM, int popu, int duracao, int exp, tArtistas* art, int qtdA, char** nA, char **idA, 
                    tData_pt dataL, tPropiedades* p,  int qtdPlay);

void LiberaMusica(tMusica *m);

tMusica* LeMusicaDoArquivo(FILE * f);

char** CriaUmaMatrizDeChar(int qtdLinha, int qtdChars);

void LiberaMatrizDeChar(char **m, int qtdLinha, int qtdChars);

#endif