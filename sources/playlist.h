#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "musicaVet.h"

typedef struct tPlaylist tPlaylist;
tPlaylist *CriarPlaylist();
void AdicionarMusicas(tPlaylist *play, tMusica *msc);
void AdicionarIndxP(tPlaylist *play, idxp);
void LiberarPlaylistStr(tPlaylist *p);
void LiberarMusicastVet(tPlaylist *p);
#endif