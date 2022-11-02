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

tArtista *CriarArtista(char *id, double seg, char *gen, char *nA, int popu){
    tArtista *art =(tArtista*) malloc(sizeof(*art));
    if(art == NULL){
        printf("Falha na alocação do ponteiro de artista");
        exit(-1);
    }
    art->id = (char*)malloc(sizeof(char)*(strlen(id)+1));
    strcpy(art->id, id);
    art->seg = seg;
    art->gen = (char*)malloc(sizeof(char)*(strlen(gen)+1));
    strcpy(art->gen, gen);
    art->nA = (char*)malloc(sizeof(char)*(strlen(nA)+1));
    strcpy(art->nA, nA);
    art->popu = popu;
    return art;
}

tArtista *LeArtista(FILE *arq, tArtista *art){
    char id[10000];
    fscanf(arq,"%[^;];",id);
    double seg;
    fscanf(arq,"%f;",seg);
    char gen[10000];
    fscanf(arq,"%[^;];",gen);
    char nA[10000]; 
    fscanf(arq,"%[^;];",nA);
    int popu;
    fscanf(arq,"%d\n",popu);
    tArtista *art = CriarArtista(id,seg,gen,nA,popu);
    return art;
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