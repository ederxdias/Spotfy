#include "artistas.h"

struct tArtistas
{
    tArtista **art;
    int qtda;
    int tamVet;
};

tArtistas * CriarArtistas(){
    tArtistas *arts = malloc(sizeof(*arts));
    if(arts == NULL){
        printf("Ponteiro Artistas NULL!\n\n");
        exit(-1);
    }
    arts->qtda=0;
    arts->tamVet = 15;
    arts->art =(tArtista **) malloc(sizeof(tArtista *)*arts->tamVet);
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
//     printf("%.1f;", RetSeg(arts->art[qtda-1]));
//     printf("%s;", RetGen(arts->art[qtda-1]));
//     printf("%s;", RetNa(arts->art[qtda-1]));
//     printf("%d\n", RetPopu(arts->art[qtda-1]));
  
}

void LiberarArtistas(tArtistas **p){
    if(*p != NULL){

        for(int i=0; i < (*p)->qtda; i++){
            LiberaArtista(&(*p)->art[i]);
        }

        free((*p)->art);
        (*p)->art = NULL;

        free(*p);
        *p = NULL;
    }
}

tArtistas* ListarArtistas(char *caminho){
    FILE * fa = fopen(caminho,"r");
    if (fa == NULL)
  {
    printf("Erro abertura do arquivo!!\n\n");
    exit(EXIT_FAILURE);
  }
    tArtistas *arts = CriarArtistas();
    tArtista *art;
    while(!feof(fa)){
         art = LeArtista(fa);
        if (art != NULL){
            AdicionarArtistas(arts, art);
        }else{
            printf("Alocação desse ponteiro de artista do arquivo falhou!\n\n");
        }
    }
    fclose(fa);
    return arts;
}


int AcharIndexArt(tArtistas *arts, char *id){
    for(int i=0;i<arts->qtda;i++){
        if(strcmp(id,RetId(arts->art[i])) == 0){
            return i;
        }
    }
    return -1;
}

tArtista * RetornarArtistaPonteiro(tArtistas *arts, int idx){
    return arts->art[idx];
}

void MudarArtista(tArtistas *arts, tArtista *art, int idx){
    arts->art[idx] = art;
}

void ImprimirArtistas(tArtistas *arts, int idx){
    ImprimirArtista(arts->art[idx]);
}

void AdicionarQtdArt(tArtistas *arts, int qtd){
    arts->qtda = qtd;
}

void RealocarArtistas(tArtistas *arts, int qtdA){
    arts->art = realloc(arts->art,sizeof(tArtista**)*qtdA);
}

void LiberarVetorArts(tArtistas **arts){
    if((*arts)->art != NULL){
        free((*arts)->art);
        (*arts)->art = NULL;
    }
}