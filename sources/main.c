
#include "artistas.h"
#include "musicas.h"
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

    tArtistas *arts = ListarArtistas("data_tests/artists_3480.csv");

    tMusicas *mscs = LeMusicasDoArquivo("data_tests/tracks_3480.csv",arts);
    //BuscarMusicasPeloNome(mscs, "One Time");

    tPlaylists* plays = CriarListaPlay();
    
    CriaPlayslistNaLista(plays, "Teste");
    ListaPlaylists(plays);

    AdicionaMusicaEmUmaPlayIdx(plays, 0, mscs, 5);

    SalvarPlaylistsEmBinario(plays, "plays.bin");

    LiberarPlaylists(&plays);

    plays = CarregarPlaylistsDeBinario("plays.bin");

    ListarMusica(mscs, 5);

    printf("Kmusicas\n");
    KmusicasRecomendadasDeUmaPlay(plays, 0, mscs, 5);

    printf("Gerando relatorio art\n");
    GeraRelatorioArtistas(arts, "retorioArt.txt");
    printf("Gerando relatorio mscs\n");
    GeraRelatorioMusicas(mscs, "relatorioMscs.txt");

    LiberaVetorMusicas(&mscs);
    LiberarArtistas(&arts);
    LiberarPlaylists(&plays);

    return EXIT_SUCCESS;
}

