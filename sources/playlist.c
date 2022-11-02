#include "playlist.h"

struct tPlaylist{
    tMusica **mscs;
    int qtdM;
    int tamVet;
    char nome*;
    char idxp;
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
    play->mscs = (tMusica **) malloc(sizeof(tMusica **)*play->tamVet);
    return play;
}

void AdicionarMusicas(tPlaylist *play, tMusica *msc){
       play->qtdM++;
    int qtdM = play->qtdM;
    if(qtdM>play->tamVet){
        play->tamVet= play->tamVet*2;
        play->mscs = realloc(play->mscs,sizeof(tMusica **)*play->tamVet);     
    }
    play->mscs[qtdM-1] = msc;
}

void AdicionarIndxP(tPlaylist *play, idxp){
    play->idxp = idxp;
}
void LiberarPlaylistStr(tPlaylist *p){
    if(p != NULL)
        free(p);
}
void LiberarMusicastVet(tPlaylist *p){
    for(int i=0; i < p->qtdp; i++){
        free(p->mscs[i]);
    }
}

