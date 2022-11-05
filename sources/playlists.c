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
        printf("ALocação de ponteiro da lista de playlist falhou");
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
        printf("SalvarPlaylistsEmBinario: Erro na abertura de arquivo binario.\n");
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
        printf("CarregarPlaylistsDeBinario: Erro na abertura de arquivo binario.\n");
        exit(1);
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