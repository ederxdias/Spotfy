#ifndef PLAYLISTS_H
#define PLAYLISTS_H
#include "playlist.h"
#include "musicaVet.h"

typedef struct tPlaylists tPlaylists;
tPlaylists *CriarListaPlay();
void AdicionarPlaylist(tPlaylists *plays, tPlaylist *play);
void LiberarPlaylists(tPlaylists *p);
#endif