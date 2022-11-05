#ifndef PLAYLISTS_H
#define PLAYLISTS_H

#include "playlist.h"
#include "musicaVet.h"

typedef struct tPlaylists tPlaylists;

tPlaylists *CriarListaPlay();

void AdicionarPlaylist(tPlaylists *plays, tPlaylist *play);

void LiberarPlaylists(tPlaylists **p);

void SalvarPlaylistsEmBinario(tPlaylists *p, char *caminho);

tPlaylists *CarregarPlaylistsDeBinario(char *caminho);

#endif