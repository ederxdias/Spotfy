#ifndef PLAYLISTS_H
#define PLAYLISTS_H

#include "playlist.h"
#include "musicas.h"

typedef struct tPlaylists tPlaylists;

tPlaylists *CriarListaPlay();

void AdicionarPlaylist(tPlaylists *plays, tPlaylist *play);

void LiberarPlaylists(tPlaylists **p);

//Salva a playlist no caminho passado, o caminho deve conter tambem o nome do arquivo que sera
//salvo ex: ./pasta/arquivo.bin, caso nao consiga criar o arquivo finaliza o programa 
void SalvarPlaylistsEmBinario(tPlaylists *p, char *caminho);

//Caso nao consiga encontrar o arquivo retorna NULL
tPlaylists *CarregarPlaylistsDeBinario(char *caminho);

//Mostra os nomes e os indices das playlists salvas no tPlaylists* passado
void ListaPlaylists(tPlaylists* plays);

//Adiciona uma musica a uma playlist dentro do tPlaylists* passado, necessita do indice da playlist(idxPlay)
//do indice da musica(idxMusica) e do armazenamento de musicas(tMusicas*)
void AdicionaMusicaEmUmaPlayIdx(tPlaylists* plays, int idxPlay, tMusicas* mscs, int idxMusica);

//Cria diretamente uma playlist no tPlaylists* passado, necessita de uma strig que corresponde ao nome
//da playlist a ser criada
void CriaPlayslistNaLista(tPlaylists* plays, char* nomePlay);

//Imprime informaçoes da playlist que se encontra no tPlaylists* passado
//e esta relacionada ao indice(idxPlay) requerido
void ListarUmaDasPlaylists(tPlaylists* plays, tMusicas* mscs, int idxPlay);

//Busca as k(int) musicas parecidas a playlist indicada pelo indice(idxPlay) no tPlaylists*
void KmusicasRecomendadasDeUmaPlay(tPlaylists* plays, int idxPlay, tMusicas* mscs, int k);

//Relacionar as musicas salvas em playlists anteriores as musicas atuais
void RelacionaPlaylistSalvasComMusicas(tPlaylists* plays, tMusicas* mscs);

#endif