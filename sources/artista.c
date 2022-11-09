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
    art->id = (char*)calloc((strlen(id)+1), sizeof(char));
    strncpy(art->id, id, strlen(id));
    art->seg = seg;
    art->gen = (char*)calloc((strlen(gen)+1), sizeof(char));
    strncpy(art->gen, gen, strlen(gen));
    art->nA = (char*)calloc((strlen(nA)+1), sizeof(char));
    strncpy(art->nA, nA, strlen(nA));
    art->popu = popu;
    return art;
}


tArtista *LeArtista(FILE *arq){
    char id[100];
    fscanf(arq,"%[^;];",id);
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

void LiberaArtista(tArtista **p){
    if(*p != NULL){
        if((*p)->id != NULL){
            free((*p)->id);
            (*p)->id = NULL;
        }
        
        if((*p)->gen != NULL){
            free((*p)->gen);
            (*p)->gen = NULL;
        }
        
        if ((*p)->nA != NULL){
            free((*p)->nA);
            (*p)->nA = NULL;
        }

        free(*p);
        *p = NULL;
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

void ImprimirArtista(tArtista *art){
    printf("Nome: %s | ", art->nA);
    printf("Id: %s | ", art->id);
    printf("Seguidores: %.0lf | ", art->seg);
    printf("Popularidade: %d\n", art->popu);
    printf("Generos: %s\n",art->gen);
}

void IncrementaQtdPlaylistArtista(tArtista *art) {
    art->playP++;
}