#include "artistas.h"

struct tArtistas
{
    tArtista **art;
    int qtda;
    int tamVet;
};

tArtistas * CriarArtistas(){
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
    if(qtda>arts->tamVet){
        arts->tamVet= arts->tamVet*2;
        arts->art = realloc(arts->art,sizeof(tArtista **)*arts->tamVet);     
    }
    arts->art[qtda-1] = art;
    
    // printf("%s;", RetId(arts->art[qtda-1]));
    // printf("%.1f;", RetSeg(arts->art[qtda-1]));
    // printf("%s;", RetGen(arts->art[qtda-1]));
    // printf("%s;", RetNa(arts->art[qtda-1]));
    // printf("%d\n", RetPopu(arts->art[qtda-1]));
}
void LiberarArtistasStr(tArtistas *p){
    if(p != NULL)
        free(p);
}
void LiberarArtistasVet(tArtistas *p){
    for(int i=0; i < p->qtda; i++){
        free(p->art[i]);
    }
}

tArtistas* ListarArtistas(char *edr){
    FILE * test = fopen(edr,"r");
    if (test == NULL)
  {
    printf("Erro abertura do arquivo!!");
    exit(EXIT_FAILURE);
  }
    tArtistas *arts = CriarArtistas();
    while(1){
        tArtista *art = LeArtista(test);
        if(art == NULL)
            break;
        AdicionarArtistas(arts, art);
    }
    fclose(test);
    return arts;
}

int AcharIndexArt(tArtistas *arts, char *id){

    for(int i=0;i<arts->tamVet;i++){
        if(strcmp(id,RetId(arts->art[i])) == 0){
            return i;
        }
    }
    return 0;
}
tArtista * RetornarStructArt(tArtistas *arts, int idx){
    return arts->art[idx];
}

