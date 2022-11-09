
#include "artistas.h"
#include "musicaVet.h"
#include "playlists.h"


int main(int argc, char *argv[]) {
    char edr[1000];
    if (argc <= 2) {
       printf("Favor informar o diretorio! de entrada\n");
        return 1;
    }

    sprintf(edr, "./data_tests/%s", argv[1]);
    sprintf(edr,"./data_tests/%s", argv[2]);
   
    tArtistas *arts = ListarArtistas("data_tests/artists_2.csv");

    tMusicaVet *mscs = LeMusicasDoArquivo("data_tests/tracks_5.csv",arts);
    BuscarMusicas(mscs);
    
    ListarMusica(mscs,3);

    tPlaylist* play = CriarPlaylist("Play Teste");
    AdicionarMusicaPlaylist(play, mscs, 3);

    tPlaylists* listaPlay = CriarListaPlay();

    AdicionarPlaylist(listaPlay, play);

    LiberaVetorMusicas(&mscs);
    LiberarArtistas(&arts);

    SalvarPlaylistsEmBinario(listaPlay, "playTeste.bin");
    LiberarPlaylists(&listaPlay);

    listaPlay = CarregarPlaylistsDeBinario("playTeste.bin");

    LiberarPlaylists(&listaPlay);

    return 0;
}

