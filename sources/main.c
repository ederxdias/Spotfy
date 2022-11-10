
#include "artistas.h"
#include "musicaVet.h"
#include "playlists.h"
#include "peso.h"


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
    //BuscarMusicasPeloNome(mscs, "One Time");

    tPlaylists* plays = CriarListaPlay();
    
    CriaPlayslistNaLista(plays, "Teste");
    //ListaPlaylists(plays);

    AdicionaMusicaEmUmaPlayIdx(plays, 0, mscs, 5);

    ListarMusica(mscs, 5);

    KmusicasRecomendadasDeUmaPlay(plays, 0, mscs, -1);

    //GeraRelatorioArtistas(arts, "retorioArt.txt");
    //GeraRelatorioMusicas(mscs, "relatorioMscs.txt");

    LiberaVetorMusicas(&mscs);
    LiberarArtistas(&arts);
    LiberarPlaylists(&plays);

    return 0;
}

