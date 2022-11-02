
#include "artista.h"
#include "artistas.h"
#include <stdio.h>
#include <stdlib.h>


struct tArtistas
{
    tArtista **art;
    int qtda;
};

tArtistas * IniciarArtistas(){
    tArtistas *arts = malloc(sizeof(arts));
    if(arts == NULL){
        printf("Ponteiro Artistas NULL");
        exit(-1);
    }
    arts->qtda=0;
    arts->art = malloc(sizeof(tArtista **));
    return arts;
}

void AdicionarArtistas(tArtistas *arts, tArtista *art){
    arts->qtda++;
    int qtda = arts->qtda;
    arts->art = realloc(arts->art,sizeof(tArtista *)*qtda);
    arts->art[qtda-1] = art;
}

