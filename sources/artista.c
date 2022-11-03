#include "artista.h"

struct tArtista
{
    char *id; // id do artista na base do Spotify.
    double seg; // Número de seguidores.
    char *gen; // Uma lista de generos associados ao artista.
    char *nA; // Nome do artista.
    int popu; // Popularidade do artista entre 0 e 100.
    int playP;
};


tArtista *CriarArtista(char *id, double seg, char *gen, char *nA, int popu){
    tArtista *art =(tArtista*) malloc(sizeof(*art));
    if(art == NULL){
        printf("Falha na alocação do ponteiro de artista");
        exit(-1);
    }
    art->id = (char*)malloc(sizeof(char)*(strlen(id)+1));
    strncpy(art->id, id, strlen(id));
    art->seg = seg;
    art->gen = (char*)malloc(sizeof(char)*(strlen(gen)+1));
    strncpy(art->gen, gen, strlen(gen));
    art->nA = (char*)malloc(sizeof(char)*(strlen(nA)+1));
    strncpy(art->nA, nA, strlen(nA));
    art->popu = popu;
    return art;
}


tArtista *LeArtista(FILE *arq){
    char id[10000];
    int fim_a = fscanf(arq,"%[^;];",id);
    double seg;
    fscanf(arq,"%lf;",&seg);
    char gen[10000];
    fscanf(arq,"%[^;];",gen);
    char nA[10000]; 
    fscanf(arq,"%[^;];",nA);
    int popu;
    fscanf(arq,"%d\n",&popu);
    tArtista *art1 = CriarArtista(id,seg,gen,nA,popu);
    return art1;
}

void LiberaArtista(tArtista *p){
    if(p->id != NULL){
        free(p->id);
    }
        
    if(p->gen!=NULL){
        free(p->gen);
    }
        
    if (p->nA!=NULL){
        free(p->nA);
    }
    if(p != NULL){
        free(p);
    } 
}
char *RetNa(tArtista *a){
    return a->nA;
}
char *RetId(tArtista *a){
    return a->id;
}
char *RetGen(tArtista *a){
    return a->gen;
}
int RetPopu(tArtista *a){
    return a->popu;
}
double RetSeg(tArtista *a){
    return a->seg;
}