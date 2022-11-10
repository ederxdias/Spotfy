#include "playlists.h"

struct tPlaylists
{
    tPlaylist **play;
    int tamVet;
    int qtdp;
};

tPlaylists *CriarListaPlay(){
    tPlaylists *list_play = (tPlaylists *) malloc(sizeof(*list_play));
    
    if(list_play == NULL){
        printf("Alocação de ponteiro da lista de playlist falhou! \n\n");
        exit(-1);
    
    }

    list_play->tamVet = 4;
    list_play ->qtdp = 0;
    list_play->play = (tPlaylist **)malloc(sizeof(tPlaylist *)*list_play->tamVet);
    return  list_play;
}

void AdicionarPlaylist(tPlaylists *plays, tPlaylist *play){
    if(plays->qtdp >= plays->tamVet){
        plays->tamVet= plays->tamVet*2;
        plays->play = realloc(plays->play,sizeof(tPlaylist *)*plays->tamVet);     
    }
    
    plays->play[plays->qtdp] = play;
    plays->qtdp++;
}


void LiberarPlaylists(tPlaylists **p){
    if(*p != NULL){
        for(int i=0; i < (*p)->qtdp; i++){
            LiberarPlaylist(&(*p)->play[i]);
        }
        free((*p)->play);
        (*p)->play = NULL;

        free(*p);
        *p = NULL;
    }
}

void SalvarPlaylistsEmBinario(tPlaylists *p, char *caminho){
    FILE * f = NULL;

    f = fopen(caminho, "wb");

    if(f == NULL) {
        printf("SalvarPlaylistsEmBinario: Erro na abertura de arquivo binario.\n\n");
        exit(1);
    }
    int i = 0;

    fwrite(&p->tamVet, sizeof(p->tamVet), 1, f);
    fwrite(&p->qtdp, sizeof(p->qtdp), 1, f);

    for(i = 0; i < p->qtdp; i++){
        SalvarPlaylistEmBinario(p->play[i], f);
    }

    fclose(f);
}

tPlaylists *CarregarPlaylistsDeBinario(char *caminho) {
    FILE * f = NULL;

    f = fopen(caminho, "rb");

    if(f == NULL) {
        printf("\nCarregarPlaylistsDeBinario: Save nao encontrado.\n\n");
        return NULL;
    }

    tPlaylists *p = (tPlaylists*)malloc(sizeof(*p));
    
    int i = 0;

    fread(&p->tamVet, sizeof(p->tamVet), 1, f);
    p->play = (tPlaylist**)malloc(sizeof(tPlaylist*)*p->tamVet);
    fread(&p->qtdp, sizeof(p->qtdp), 1, f);

    for(i = 0; i < p->qtdp; i++){
        p->play[i] = CarregaPlaylistDeBinario(f);
    }

    fclose(f);

    return p;
}

void ListaPlaylists(tPlaylists* plays) {
    int i = 0;

    if(plays->qtdp == 0){
        printf("Nenhuma playlist foi criada ainda!\n\n");
        return;
    }

    printf("Playlists criadas: %d\n\n", plays->qtdp);

    for(i = 0; i < plays->qtdp; i++) {
        printf("Indice da playlist: %d\n", i);
        printf("Nome da playlist: %s\n", RetornaNomeDaPlaylsit(plays->play[i]));
        printf("Quantidade de musicas: %d \n\n", RetornaQtdMscsPlaylist(plays->play[i]));
    }
}

void AdicionaMusicaEmUmaPlayIdx(tPlaylists* plays, int idxPlay, tMusicaVet* mscs, int idxMusica) {
    if(idxPlay >= plays->qtdp || idxPlay < 0) {
        printf("Playlist nao existe!\n\n");
        return;
    }

    AdicionarMusicaPlaylist(plays->play[idxPlay], mscs, idxMusica);
}

void CriaPlayslistNaLista(tPlaylists* plays, char* nomePlay) {
    tPlaylist* play = CriarPlaylist(nomePlay);

    AdicionarPlaylist(plays, play);
}

void ListarUmaDasPlaylists(tPlaylists* plays, tMusicaVet* mscs, int idxPlay) {
    if(idxPlay >= plays->qtdp || idxPlay < 0) {
        printf("Playlist nao existe!\n\n");
        return;
    }

    ListarPlaylist(plays->play[idxPlay], mscs);
}

void KmusicasRecomendadasDeUmaPlay(tPlaylists* plays, int idxPlay, tMusicaVet* mscs, int k) {
    if(plays->qtdp < idxPlay || idxPlay < 0) {
        printf("Essa playlist nao foi encontrada!\n\n");
        return;
    }

    RecomendaKmusicasParecidas(plays->play[idxPlay], mscs, k);
}