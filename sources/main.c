
#include "artistas.h"
#include "musicaVet.h"
#include "playlists.h"


int main(int argc, char *argv[]) {
    /*char edr[1000];
    if (argc <= 2) {
       printf("Favor informar o diretorio! de entrada\n");
        return 1;
    }

    sprintf(edr, "./data_tests/%s", argv[1]);
    sprintf(edr,"./data_tests/%s", argv[2]);
    */

    tArtistas *arts = ListarArtistas("data_tests/artists_2.csv");

    tMusicaVet *mscs = LeMusicasDoArquivo("data_tests/tracks_2.csv",arts);
    BuscarMusicasPeloNome(mscs, "Long, Long, Long - Remastered 2009");

    tPlaylists* plays = CriarListaPlay();
    ListaPlaylists(plays);
    
    int idx = 172;
    CriaPlayslistNaLista(plays, "Teste");
    ListaPlaylists(plays);

    AdicionaMusicaEmUmaPlayIdx(plays, 0, mscs, idx);
    AdicionaMusicaEmUmaPlayIdx(plays, 0, mscs, idx+1);
    AdicionaMusicaEmUmaPlayIdx(plays, 0, mscs, idx+2);
    ListaPlaylists(plays);

    CriaPlayslistNaLista(plays, "Teste2");
    ListaPlaylists(plays);
    ListarUmaDasPlaylists(plays, mscs, 0);

    ListarMusica(mscs, 172);

    LiberaVetorMusicas(&mscs);
    LiberarArtistas(&arts);
    LiberarPlaylists(&plays);

    return 0;
}

