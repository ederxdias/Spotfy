
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
    
    int idx = 170;
    printf("Digite o indice da musica: ");
    //scanf("%d", &idx);
    ListarMusica(mscs, idx);

    LiberaVetorMusicas(&mscs);
    LiberarArtistas(&arts);

    return 0;
}

