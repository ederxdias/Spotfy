#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "musicaVet.h"

typedef struct tPlaylist tPlaylist;

tPlaylist *CriarPlaylist(char* nomePlay);

void AdicionarMusicas(tPlaylist *play, int idx_msc);

void LiberarPlaylist(tPlaylist **p);

/* O arquivo onde sera salva a Playlist deve ser passado aberto 
 * no formato de escrita binaria */
void SalvarPlaylistEmBinario(tPlaylist *p, FILE * f);

/* O arquivo onde sera carregada a Playlist deve ser passado aberto 
 * no formato de leitura binaria */
tPlaylist *CarregaPlaylistDeBinario(FILE * f);

#endif