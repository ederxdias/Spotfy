#ifndef MUSICA_H
#define MUSICA_H

#include "tData.h"
#include "artistas.h"
#include "propiedades.h"

typedef struct tMusica tMusica;

tMusica *CriaMusica(char* id, char* nM, int popu, double duracao, int exp, tArtistas* art, int qtdA, char* nA, char **idA, 
                    tData_pt dataL, tPropiedades* p,  int qtdPlay);

#endif