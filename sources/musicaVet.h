#ifndef _MUSICAVET_H_
#define _MUSICAVET_H_

#include "musica.h"

typedef struct tMusicaVet tMusicaVet;

tMusicaVet* InicializaVetorMusicas();

tMusicaVet* LeMusicasDoArquivo(char* caminho, tArtistas *arts);

void AdicionaMusicaAoVetMusicas(tMusicaVet *v, tMusica* m);

void LiberaVetorMusicas(tMusicaVet **vet);

void ListarMusica(tMusicaVet *mscs, int idx);

tMusica* RetMusicaPeloIdx(tMusicaVet *mscs, int idx);

void BuscarMusicasPeloNome(tMusicaVet *mscs, char *busca);

#endif