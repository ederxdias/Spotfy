#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "musicaVet.h"

typedef struct tPlaylists tPlaylists;
tPlaylist *CriarListaPlay();
void AdicionarPlaylist(tPlaylists *plays, tPlaylist *play);
void LiberarPlaylists(tPlaylists *p);
#endif