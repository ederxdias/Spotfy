#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "musicas.h"
#include "peso.h"

typedef struct tPlaylist tPlaylist;

tPlaylist *CriarPlaylist(char* nomePlay);

void AdicionarMusicaPlaylist(tPlaylist *play, tMusicas* mscs, int idx_msc);

void LiberarPlaylist(tPlaylist **p);

/* O arquivo onde sera salva a Playlist deve ser passado aberto 
 * no formato de escrita binaria */
void SalvarPlaylistEmBinario(tPlaylist *p, FILE * f);

/* O arquivo onde sera carregada a Playlist deve ser passado aberto 
 * no formato de leitura binaria*/
tPlaylist *CarregaPlaylistDeBinario(FILE * f);

char *RetornaNomeDaPlaylsit(tPlaylist* play);

int RetornaQtdMscsPlaylist(tPlaylist* play);

void ListarPlaylist(tPlaylist* play, tMusicas* mscs);

tPropiedades *MediaDasPropriedadesPlaylist(tPlaylist* play, tMusicas* mscs);

void RecomendaKmusicasParecidas(tPlaylist* play, tMusicas* mscs, int k);

#endif