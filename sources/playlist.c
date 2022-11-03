#include "playlist.h"

struct tPlaylist{
    int  *muscs;// vetor com indices das musicas
    int qtdM; // quantidade de musicas
    int tamVet; // tamanho do vetor musicas,ele é atualizado com realloc
    char nome*; // nome da playlist
    char idxp; // index da playlist
};

tPlaylist *CriarPlaylist(){
    char nome[100];
    scanf("%s", nome);//pensar em como pegar o nome
    tPlaylist *play = (tPlaylist *) malloc(sizeof(*play));
    if(play == NULL){
        printf("ALocação de ponteiro da playlist falhou");
        exit(-1);
    }
    play->qtdM =0;
    play->tamVet= 4;
    play->mscs = (int *) malloc(sizeof(int)*play->tamVet);
    return play;
}

void AdicionarMusicas(tPlaylist *play, int idx_msc){
       play->qtdM++;
    int qtdM = play->qtdM;
    if(qtdM >play->tamVet){
        play->tamVet= play->tamVet*2;
        play->mscs =(int *) realloc(play->mscs,sizeof(int)*play->tamVet);     
    }
    play->mscs[qtdM-1] = indx_msc;
}

void AdicionarIndxP(tPlaylist *play, int idxp){
    play->idxp = idxp;
}

void LiberarPlaylist(tPlaylist *p){
    for(int i=0; i < p->qtdp; i++){
        free(p->mscs[i]);
    }
    if(p != NULL)
        free(p);
}

