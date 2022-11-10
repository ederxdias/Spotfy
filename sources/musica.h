#ifndef MUSICA_H
#define MUSICA_H

#include "artistas.h"
#include "propiedades.h"

typedef struct tMusica tMusica;

tMusica *CriaMusica(char* id, char* nM, int popu, int duracao, int exp, int qtdA, char** nA, char **idA, 
                    char *dataL, tPropiedades* p,  int qtdPlay);

void LiberaMusica(tMusica **m);

tMusica* LeMusicaDoArquivo(FILE * f);

char** CriaUmaMatrizDeChar(int qtdLinha, int qtdChars);

void LiberaMatrizDeChar(char **m, int qtdLinha, int qtdChars);

void AdicionarArtistasDaMusica(tMusica *msc, tArtistas *arts);

char *RetIdM(tMusica *msc);

int RetQtdArtsM(tMusica *msc);

void ConfiguraMusicaNaPlaylist(tMusica *msc);

void ImprimirMusica(tMusica *msc);

char *RetornarNomeMusic(tMusica *msc);

char** RetornaNomeDosArtistasDaM(tMusica *msc);

char *RetornarNomeMusic(tMusica *msc);

#endif