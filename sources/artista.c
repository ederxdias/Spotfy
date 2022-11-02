#include "artista.h"

struct tArtista
{
    char *id;
    double seg;
    char *gen;
    char *nA;
    int popu;
    int playP;
};

tArtista *IniciarArtista(){
    tArtista *art = malloc(sizeof(art));
    if(art == NULL){
        printf("Falha na alocação do ponteiro de artista");
        exit(-1);
    }
    return art;
}

tArtista *LeArtista(FILE *arq, tArtista *art){
    art->id = malloc(10000);
    fscanf(arq,"%[^;];", art->id);
    fscanf(arq,"%f;",art->seg);
    art->gen = malloc(10000);
    fscanf(arq,"%[^;];",art->gen);
    art->nA = malloc(10000);
    fscanf(arq,"%[^;];", art->nA);
    fscanf(arq,"%d\n",art->popu);
}

void LiberarArtistaStr(tArtista *p){
    if(p != NULL)
        free(p);
}
void LiberaArtistaVet(tArtista *p){
    if(p->id!=NULL)
        free(p->id);
    if(p->gen!=NULL);
        free(p->gen);
    if (p->nA!=NULL)
        free(p->nA);
}