#ifndef PLAYLISTS_H
#define PLAYLISTS_H

#include "playlist.h"
#include "musicas.h"

typedef struct tPlaylists tPlaylists;

tPlaylists *CriarListaPlay();

void AdicionarPlaylist(tPlaylists *plays, tPlaylist *play);

void LiberarPlaylists(tPlaylists **p);

void SalvarPlaylistsEmBinario(tPlaylists *p, char *caminho);

//Caso nao consiga encontrar o arquivo retorna NULL
tPlaylists *CarregarPlaylistsDeBinario(char *caminho);

void ListaPlaylists(tPlaylists* plays);

void AdicionaMusicaEmUmaPlayIdx(tPlaylists* plays, int idxPlay, tMusicas* mscs, int idxMusica);

void CriaPlayslistNaLista(tPlaylists* plays, char* nomePlay);

void ListarUmaDasPlaylists(tPlaylists* plays, tMusicas* mscs, int idxPlay);

void KmusicasRecomendadasDeUmaPlay(tPlaylists* plays, int idxPlay, tMusicas* mscs, int k);

#endif