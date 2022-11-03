#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "musicaVet.h"

typedef struct tPlaylist tPlaylist;
tPlaylist *CriarPlaylist();
void AdicionarMusicas(tPlaylist *play, int idx_msc);
void AdicionarIndxP(tPlaylist *play, int idxp)
void LiberarPlaylist(tPlaylist *p);
#endif