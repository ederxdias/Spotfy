#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include "artistas.h"
#include "musicas.h"
#include "playlists.h"

enum{
    SAIR = 0,
    BUSCA_MUSICAS = 1,
    LISTA_MUSICA = 2,
    EXECUTA_MUSICA = 3,
    CRIAR_PLAYLIST = 4,
    LISTA_PLAYLISTS = 5,
    LISTAR_UMA_PLAYLIST = 6,
    ADICIONAR_MUSICA_PLAYLIST = 7,
    RECOMENDAR_MUSICAS = 8,
    GERAR_RELATORIO = 9
};

/**
 * @brief Imprime o menu com as opções existentes
 * 
 */
void ImprimeMenu();

/**
 * @brief A interface que busca musicas no tMusicas*
 * 
 * @param mscs: tMusicas* que a busca sera feita 
 */
void BuscaMusicasInter(tMusicas* mscs);

/**
 * @brief A interface que lista uma musica pelo indice dela no tMusicas*
 * 
 * @param mscs: tMusicas* no qual a musica se encontra
 */
void ListaMusicaPeloIdInter(tMusicas* mscs);

/**
 * @brief A interface que executa uma musica do tMusicas* pelo indice dela
 * 
 * @param mscs: tMusicas* onde a musica se encontra 
 */
void ExecutaMusicaInter(tMusicas* mscs);

/**
 * @brief Interface para criar uma playlist(tPlaylist*) no tPlaylist*
 * 
 * @param plays: tPlaylists* que a playlist(tPlaylist*) sera criada
 */
void CriaPlaylistInter(tPlaylists* plays);

/**
 * @brief Interface para listar as playlist(tPlaylist*) que se encontra no tPlaylists*
 * 
 * @param plays: tPlaylists* que as playlists(tPlaylist*) sera listada 
 */
void ListaPlaylistsInter(tPlaylists* plays);

/**
 * @brief Interface para listar uma playlist(tPlaylist*) no tPlaylists*
 * 
 * @param plays: tPlaylists* que a playlist(tPlaylist*) que sera listada se encontra 
 * @param mscs: tMusicas* para auxiliar na listagem da playlist 
 */
void ListarUmaPlayInter(tPlaylists* plays, tMusicas* mscs);

/**
 * @brief Interface para adicionar uma musica(tMusica*) em uma playlist(tPlaylist*) que se encontra
 * no tPlaylists* 
 * 
 * @param plays: tPlaylists* no qual a playlist(tPlaylist*) se encontra 
 * @param mscs: tMusicas* no qual a musica que sera adicionada na playlist se encontra 
 */
void AdicionarMusicaPlayInter(tPlaylists* plays, tMusicas* mscs);

/**
 * @brief Interface para recomentar as k musicas mais parecidas com a playlist solicitada
 * 
 * @param plays: tPlaylists* no qual se encontra a playlist(tPlaylist*) que sera modelo para a recomendacao 
 * @param mscs: tMusicas* para auxiliar na recomendacao de musicas 
 */
void RecomendaKMusicsInter(tPlaylists* plays, tMusicas* mscs);

/**
 * @brief Interface para gerar um arquivo de relatorio dos artistas(tArtistas*) e um das musicas(tMusicas*)
 * 
 * @param arts: tArtistas* que o relatorio sera feito  
 * @param mscs: tMusicas* que o relatorio sera feito 
 * @param caminho: caminho ate o local que sera salvo o arquivo de raltorio 
 */
void GerarRelatoriosInter(tArtistas* arts, tMusicas* mscs, char* caminho);

#endif