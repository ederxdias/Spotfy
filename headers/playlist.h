#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "musicas.h"
#include "peso.h"

typedef struct tPlaylist tPlaylist;

tPlaylist *CriarPlaylist(char* nomePlay);

//Adiciona uma musica ao tPlaylist* passado, necessita do armazenamento das musicas(tMusicas*)
//e do indice da musica que sera salva
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

//Imprime o nome da playlist e o nome e id das musicas que ela possui
void ListarPlaylist(tPlaylist* play, tMusicas* mscs);

tPropiedades *MediaDasPropriedadesPlaylist(tPlaylist* play, tMusicas* mscs);

//Procura as k(int) musicas parecidas com a playlist(tPlaylist*) passada, necessita do armazenamento
//de musicas(tMusicas*)
void RecomendaKmusicasParecidas(tPlaylist* play, tMusicas* mscs, int k);

//Para linkar as informações ja salvas da playlist anterior as musicas
void RelacionaPlaylistSalvaComMusicas(tPlaylist* play, tMusicas* mscs);

#endif