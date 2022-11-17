#include "interface.h"

int main(int argc, char *argv[]) {
    if(argc < 3) {
        printf("É necessário informar o caminho do arquivo de artistas e o de musicas, repectivamente!\n");
        exit(EXIT_FAILURE);
    }
    
    tArtistas* arts = ListarArtistas(argv[1]);
    tMusicas* mscs = LeMusicasDoArquivo(argv[2], arts);

    tPlaylists* plays = CarregarPlaylistsDeBinario("dataSave/playlists.bin");

    if(plays == NULL) {
        printf("Inicializando Uma Lista De Playlists Vazia!\n\n");
        plays = CriarListaPlay();
    }else{
        printf("Configurando Playlists Anteriores Com As Musicas e Artistas!\n");
        RelacionaPlaylistSalvasComMusicas(plays, mscs);
        printf("Operacao: Leitura De Playlists Concluida!\n\n");
    }

    int opcao = 0;

    ImprimeMenu();

    while(scanf("%d%*c", &opcao) == 1 && opcao != SAIR) {
        switch (opcao){
            case BUSCA_MUSICAS:
                BuscaMusicasInter(mscs);
                break;
            
            case LISTA_MUSICA:
                ListaMusicaPeloIdInter(mscs);
                break;
            
            case EXECUTA_MUSICA:
                ExecutaMusicaInter(mscs);
                break;
            
            case CRIAR_PLAYLIST:
                CriaPlaylistInter(plays);
                break;
            
            case LISTA_PLAYLISTS:
                ListaPlaylistsInter(plays);
                break;
            
            case LISTAR_UMA_PLAYLIST:
                ListarUmaPlayInter(plays, mscs);
                break;
            
            case ADICIONAR_MUSICA_PLAYLIST:
                AdicionarMusicaPlayInter(plays, mscs);
                break;
            
            case RECOMENDAR_MUSICAS:
                RecomendaKMusicsInter(plays, mscs);
                break;
            
            case GERAR_RELATORIO:
                GerarRelatoriosInter(arts, mscs, "./dataSave/");
                break;
            
            default:
                printf("\nOPÇÃO NÃO ENCONTRADA!\n\n");
                break;
        }
        
        ImprimeMenu();
    }

    SalvarPlaylistsEmBinario(plays, "dataSave/playlists.bin");

    LiberarPlaylists(&plays);
    LiberarArtistas(&arts);
    LiberaVetorMusicas(&mscs);

    return EXIT_SUCCESS;
}
