
#include "artistas.h"
#include "musicaVet.h"



int main(int argc, char *argv[]) {
    char edr[1000];
    if (argc <= 1) {
        printf("Favor informar o diretorio! de entrada\n");
        return 1;
    }

    sprintf(edr, "./data_tests/%s", argv[1]);

    tArtistas *arts = ListarArtistas(edr);

    sprintf(edr,"./data_tests/%s", argv[2]);

    tMusicaVet *mscs = LeMusicasDoArquivo(edr,arts);
    ListarMusica(mscs,3);

    LiberaVetorMusicas(&mscs);

    LiberarArtistas(&arts);

    return 0;
}

