#include "musica.h"
#include "propiedades.h"
#include "tData.h"
#include "artistas.h"

struct tMusica
{
    char *id;
    char *nM;
    int popu;
    float dura_ms;
    int eh_explic;
    tArtistas *artista;
    char **idA;
    tData_pt dataL;
};

