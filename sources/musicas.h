#ifndef _MUSICAS_H_
#define _MUSICAS_H_

#include "musica.h"
#include "peso.h"

typedef struct tMusicas tMusicas;

tMusicas* InicializaVetorMusicas();

tMusicas* LeMusicasDoArquivo(char* caminho, tArtistas *arts);

void AdicionaMusicaAoVetMusicas(tMusicas *v, tMusica* m);

void LiberaVetorMusicas(tMusicas **vet);

void ListarMusicaPeloIndice(tMusicas *mscs, int idx);

tMusica* RetMusicaPeloIdx(tMusicas *mscs, int idx);

void BuscarMusicasPeloNome(tMusicas *mscs, char *busca);

void ExecutaMusicaPeloIdx(tMusicas* mscs, int idx);

void GeraRelatorioMusicas(tMusicas* mscs, char* caminho); 

int RetQtdMusicasNaLista(tMusicas* mscs);

#endif