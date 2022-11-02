#ifndef ARTISTAS_H
#define ARTISTAS_H

#include "artista.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct tArtistas tArtistas;
tArtistas * CriarArtistas();
void AdicionarArtistas(tArtistas *arts, tArtista *art);
void LiberarArtistasStr(tArtistas *p);
void LiberarArtistasVet(tArtistas *p);

#endif