#include "interface.h"

void ImprimeMenu() {
    printf("\t\t\t =OPÇÕES DIPONÍVEIS=\n");
    printf("BUSCAR MUSICAS = %d\tLISTAR UMA MUSICA = %d\tEXECUTAR UMA MUSICA = %d\n",
    BUSCA_MUSICAS, LISTA_MUSICA, EXECUTA_MUSICA);
    printf("CRIAR UMA PLAYLIST = %d\tLISTAR PLAYLISTS = %d\tLISTAR UMA DAS PLAYLISTS = %d\n",
    CRIAR_PLAYLIST, LISTA_PLAYLISTS, LISTAR_UMA_PLAYLIST);
    printf("\t\tADICIONAR UMA MUSICA A UMA PLAYLIST = %d\n\t    RECOMENDAR MUSICAS PARECIDAS COM A PLAYLIST = %d\n", 
    ADICIONAR_MUSICA_PLAYLIST, RECOMENDAR_MUSICAS);
    printf("\t\t  GERAR RELATÓRIOS = %d\tSAIR = %d\n", GERAR_RELATORIO, SAIR);
    printf("\t\t    ==>AGUARDANDO ESCOLHA: ");
}

void BuscaMusicasInter(tMusicas* mscs) {
    char nome[1000];
    printf("\nDIGIE A PALAVRA CHAVE QUE DESEJA BUSCAR: ");
    scanf("%s%*c", nome);
    printf("\nBuscando Musicas:\n\n");
    BuscarMusicasPeloNome(mscs, nome);
    printf("Busca Concluída!\n\n");
}

void ListaMusicaPeloIdInter(tMusicas* mscs) {
    int indice = 0;
    printf("\nDIGIE O INDICE DA MUSICA DESEJADA: ");
    scanf("%d%*c", &indice);
    printf("\nListagem Iniciada!\n\n");
    ListarMusicaPeloIndice(mscs, indice);
    printf("Listagem Finalizada!\n\n");
}

void ExecutaMusicaInter(tMusicas* mscs) {
    int indice = 0;
    printf("\nDIGIE O INDICE DA MUSICA DESEJADA: ");
    scanf("%d%*c", &indice);
    printf("\nExecução da Musica Iniciada!\n\n");
    ExecutaMusicaPeloIdx(mscs, indice);
    printf("\nExecução da Musica Finalizada!\n\n");
}

void CriaPlaylistInter(tPlaylists* plays) {
    char nome[1000];
    printf("\nDIGITE O NOME DA PLAYLIST A SER CRIADA: ");
    scanf("%[^\n]%*c", nome);
    printf("\nCriando Playlist!\n\n");
    CriaPlayslistNaLista(plays, nome);
    printf("Playlist \"%s\" Criada!\n\n", nome);
}

void ListaPlaylistsInter(tPlaylists* plays) {
    printf("\nListando Playlists!\n\n");
    ListaPlaylists(plays);
    printf("\nListagem de Playlists Concluida!\n\n");
}

void ListarUmaPlayInter(tPlaylists* plays, tMusicas* mscs) {
    int indice = 0;
    printf("\nDIGITE O INDICE DA PLAYLIST A SER LISTADA: ");
    scanf("%d%*c", &indice);
    printf("\nListagem da Playlist Iniciada!\n\n");
    ListarUmaDasPlaylists(plays, mscs, indice);
    printf("Listagem da Playlist Concluida!\n\n");
}

void AdicionarMusicaPlayInter(tPlaylists* plays, tMusicas* mscs) {
    int idxPlay = -1, idxMusi = -1;
    printf("\nDIGITE O INDICE DA MUSICA E O INDICE DA PLAYLIST: ");
    scanf("%d %d%*c", &idxMusi, &idxPlay);
    printf("\nAdição Musica na Playlist Iniciada!\n\n");
    AdicionaMusicaEmUmaPlayIdx(plays, idxPlay, mscs, idxMusi);
    printf("Adição Musica na Playlist Concluida!\n\n");
}

void RecomendaKMusicsInter(tPlaylists* plays, tMusicas* mscs) {
    int idxPlay = -1, k = 0;

    printf("\nDIGITE O INDICE DA PLAYLIST MODELO E A QUANTIDADE DE MUSICAS PARECIDAS DESEJADA: ");
    scanf("%d %d%*c", &idxPlay, &k);
    printf("\nRecomendacao Iniciada!\n\n");
    KmusicasRecomendadasDeUmaPlay(plays, idxPlay, mscs, k);
    printf("Recomendacao Finalizada!\n");
}

void GerarRelatoriosInter(tArtistas* arts, tMusicas* mscs,  char* caminho) {
    printf("\nCriação de Relatório de Artistas Iniciada!\n");
    GeraRelatorioArtistas(arts, caminho);
    printf("Criação de Relatório de Artistas Concluida!\n\n");
    printf("Criação de Relatório de Musicas Iniciada!\n");
    GeraRelatorioMusicas(mscs, caminho);
    printf("Criação de Relatório de Musicas Concluida!\n\n");
}
