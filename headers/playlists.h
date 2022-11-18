#ifndef PLAYLISTS_H
#define PLAYLISTS_H

#include "playlist.h"
#include "musicas.h"

typedef struct tPlaylists tPlaylists;

/**
 * @brief Cria um tPlaylists* alocado dinamicamente
 * 
 * @return tPlaylists* 
 */
tPlaylists *CriarListaPlay();

/**
 * @brief Adiciona uma playlist(tPlaylist*) a uma lista de playlists(tPlaylists*)
 * 
 * @param plays: tPlaylists* 
 * @param play: tPlaylist* 
 */
void AdicionarPlaylist(tPlaylists *plays, tPlaylist *play);

/**
 * @brief Libera o tPlaylists*
 * 
 * @param p: tPlaylists** que representa o caminho na tPlaylists* 
 */
void LiberarPlaylists(tPlaylists **p);

/**
 * @brief Salva o tPlaylists* em um arquivo binario
 * 
 * @param p: tPlaylist* 
 * @param caminho: uma string que representa o caminho do arquivo binario que o tPlaylists* sera salvo 
 */
void SalvarPlaylistsEmBinario(tPlaylists *p, char *caminho);

/**
 * @brief Carrega o tPlaylists* de um arquivo binario, caso nao consiga ler retorna NULL
 * 
 * @param caminho: uma string que representa o caminho do arquivo binario que o tPlaylists* sera carregado
 */
tPlaylists *CarregarPlaylistsDeBinario(char *caminho);

/**
 * @brief Mostra os nomes e os indices das playlists salvas no tPlaylists* passado
 * 
 * @param plays: tPlaylists* 
 */
void ListaPlaylists(tPlaylists* plays);

/**
 * @brief Adiciona uma musica a uma playlist dentro do tPlaylists* passado
 * 
 * @param plays: tPlaylists*   
 * @param idxPlay: int indice da playlist(tPlaylist*) no tPlaylists* 
 * @param mscs: tMusicas*  
 * @param idxMusica: int indice da musica(tMusica*) no tMusicas* 
 */
void AdicionaMusicaEmUmaPlayIdx(tPlaylists* plays, int idxPlay, tMusicas* mscs, int idxMusica);

/**
 * @brief Cria diretamente uma playlist no tPlaylists* passado
 * 
 * @param plays: tPlaylists* 
 * @param nomePlay: uma strig que representa o nome da playlist(tPlaylist*) a ser criado 
 */
void CriaPlayslistNaLista(tPlaylists* plays, char* nomePlay);

/**
 * @brief Imprime informaçoes da playlist que se encontra no tPlaylists* passado
 * 
 * @param plays: tPlaylists* 
 * @param mscs: tMusicas* banco de musicas 
 * @param idxPlay: indice da playlist(tPlaylist*) que esta no tPlaylists* 
 */
void ListarUmaDasPlaylists(tPlaylists* plays, tMusicas* mscs, int idxPlay);

/**
 * @brief Busca as k(int) musicas parecidas a playlist indicada pelo indice(idxPlay) no tPlaylists*
 * 
 * @param plays: tPlaylists* 
 * @param idxPlay: int indice da playlist(tPlaylist*) no tPlaylists* 
 * @param mscs: tMusicas* banco de dados de musicas 
 * @param k: int que representa as quantidade de musicas recomendadas 
 */
void KmusicasRecomendadasDeUmaPlay(tPlaylists* plays, int idxPlay, tMusicas* mscs, int k);

/**
 * @brief Relacionar as musicas salvas em playlists anteriores as musicas atuais
 * 
 * @param plays: tPlaylists* 
 * @param mscs: tMusicas* banco de dados 
 */
void RelacionaPlaylistSalvasComMusicas(tPlaylists* plays, tMusicas* mscs);

#endif