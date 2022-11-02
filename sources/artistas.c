#include "artistas.h"

struct tArtistas
{
    tArtista **art;
    int qtda;
    int tamVet;
};

tArtistas * IniciarArtistas(){
    tArtistas *arts = malloc(sizeof(arts));
    if(arts == NULL){
        printf("Ponteiro Artistas NULL");
        exit(-1);
    }
    arts->qtda=0;
    arts->tamVet = 4;
    arts->art = malloc(sizeof(tArtista **)*arts->tamVet);
    return arts;
}

void AdicionarArtistas(tArtistas *arts, tArtista *art){
    arts->qtda++;
    int qtda = arts->qtda;
    if(qtda>4){
        arts->tamVet= arts->tamVet*2
        arts->art = realloc(arts->art,sizeof(tArtista *)*arts->tamVet);     
    }
    arts->art[qtda-1] = art;
}
void LiberarArtistasStr(tArtistas *p){
    if(p != NULL)
        free(p);
}
void LiberarArtistasVet(tArtistas *p,){
    for(int i=0; i < p->qtda; i++){
        free(p->art[i]);
    }
}

