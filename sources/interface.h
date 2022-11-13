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

void ImprimeMenu();

void BuscaMusicasInter(tMusicas* mscs);

void ListaMusicaPeloIdInter(tMusicas* mscs);

void ExecutaMusicaInter(tMusicas* mscs);

void CriaPlaylistInter(tPlaylists* plays);

void ListaPlaylistsInter(tPlaylists* plays);

void ListarUmaPlayInter(tPlaylists* plays, tMusicas* mscs);

void AdicionarMusicaPlayInter(tPlaylists* plays, tMusicas* mscs);

void RecomendaKMusicsInter(tPlaylists* plays, tMusicas* mscs);

void GerarRelatoriosInter(tArtistas* arts, tMusicas* mscs, char* caminho);

#endif