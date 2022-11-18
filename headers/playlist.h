#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "musicas.h"
#include "peso.h"

typedef struct tPlaylist tPlaylist;

/**
 * @brief Cria um tPlaylist* alocado dinamicamente com o nome passado
 * 
 * @param nomePlay: uma string que representa o nome da playlist(tPlaylist*) a ser criada 
 * @return tPlaylist* 
 */
tPlaylist *CriarPlaylist(char* nomePlay);

/**
 * @brief Adiciona uma musica ao tPlaylist* passado
 * 
 * @param play: tPlaylist* onde a musica sera adicionada 
 * @param mscs: tMusicas* onde a musica se encontra 
 * @param idx_msc: indice que representa a musica no tMusicas*  
 */
void AdicionarMusicaPlaylist(tPlaylist *play, tMusicas* mscs, int idx_msc);

/**
 * @brief Libera o tPlaylist*
 * 
 * @param p: tPlaylist** que representa o caminho para o tPlaylist* 
 */
void LiberarPlaylist(tPlaylist **p);

/**
 * @brief Salva a playlist(tPlaylist*) em um arquivo binario
 * 
 * @param p: tPlaylist* que sera salvo 
 * @param f: FILE* que representa o arquivo binario que deve estar aberto em modo escrita binaria "wb" 
 */
void SalvarPlaylistEmBinario(tPlaylist *p, FILE * f);

/**
 * @brief Carrega uma playlist(tPlaylist*) em um arquivo binario
 * 
 * @param f: FILE* que representa o arquivo binario que deve estar aberto em modo leitura binaria "rb"
 * @return tPlaylist* 
 */
tPlaylist *CarregaPlaylistDeBinario(FILE * f);

/**
 * @brief Retorna o nome da playlist(tPlaylist*)
 * 
 * @param play: tPlaylist*  
 * @return char* uma string que representa o nome da playlist(tPlaylist*) 
 */
char *RetornaNomeDaPlaylsit(tPlaylist* play);

/**
 * @brief Retorna a quantidade de musicas na playlist(tPlaylist*)
 * 
 * @param play: tPlaylist* 
 * @return int que representa a quantidade playlist(tPlaylist*) 
 */
int RetornaQtdMscsPlaylist(tPlaylist* play);

/**
 * @brief Imprime o nome da playlist e o nome e id das musicas que ela possui
 * 
 * @param play: tPlaylist*
 * @param mscs: tMusicas* 
 */
void ListarPlaylist(tPlaylist* play, tMusicas* mscs);

/**
 * @brief Retorna o tPropiedades* referente a media da playlist(tPlaylist*)
 * 
 * @param play: tPlaylist* 
 * @param mscs: tMusicas* 
 * @return tPropiedades* 
 */
tPropiedades *MediaDasPropriedadesPlaylist(tPlaylist* play, tMusicas* mscs);

/**
 * @brief Procura as k(int) musicas parecidas com a playlist(tPlaylist*) passada
 * 
 * @param play: tPlaylist* 
 * @param mscs: tMusicas* 
 * @param k: int 
 */
void RecomendaKmusicasParecidas(tPlaylist* play, tMusicas* mscs, int k);

/**
 * @brief Para linkar as informações ja salvas da playlist anterior as musicas
 * 
 * @param play: tPlaylist* 
 * @param mscs: tMusicas* 
 */
void RelacionaPlaylistSalvaComMusicas(tPlaylist* play, tMusicas* mscs);

#endif