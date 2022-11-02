#ifndef _MUSICAVET_H_
#define _MUSICAVET_H_

#include "musica.h"

typedef struct tMusicaVet tMusicaVet;

tMusicaVet* InicializaVetorMusicas();

tMusicaVet* LeMusicasDoArquivo(char* caminho);

#endif