#include "artistas.h"

struct tArtistas
{
    tArtista* *art;
    int qtda;
    int tamVet;
};

tArtistas* CriarArtistas(){
    tArtistas* arts = malloc(sizeof(*arts));
    if(arts == NULL){
        printf("Ponteiro Artistas NULL!\n\n");
        exit(-1);
    }
    arts->qtda=0;
    arts->tamVet = 15;
    arts->art =(tArtista **) malloc(sizeof(tArtista *)*arts->tamVet);
    return arts;
}



void AdicionarArtistas(tArtistas* arts, tArtista* art){
    arts->qtda++;
    
    int qtda = arts->qtda;
    
    if(qtda>arts->tamVet){
        arts->tamVet= arts->tamVet*2;
        arts->art = realloc(arts->art,sizeof(tArtista **)*arts->tamVet);     
    }
    arts->art[qtda-1] = art;
}

void LiberarArtistas(tArtistas* *p){
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

tArtistas* ListarArtistas(char* caminho){
    FILE * fa = fopen(caminho,"r");
    if (fa == NULL)
  {
    printf("Listar Artistas: Erro abertura do arquivo!!\n\n");
    exit(EXIT_FAILURE);
  }

    printf("Operacao: Leitura de Artistas Iniciada!\n");

    tArtistas *arts = CriarArtistas();
    tArtista *art;
    while(!feof(fa)){
         art = LeArtista(fa);
        if (art != NULL){
            AdicionarArtistas(arts, art);
        }else{
            printf("Alocação desse um ponteiro de artista do arquivo falhou!\n");
        }
    }
    fclose(fa);

    printf("Operacao: Leitura de Artistas Finalizada!\n\n");

    printf("Operacao: Ordenacao de Artistas Iniciada!\n");
    OrdenaArrArtistasCrescenteId(arts->art, arts->qtda);
    printf("Operacao: Ordenacao de Artistas Finalizada!\n\n");

    return arts;
}


int AcharIndexArtPeloId(tArtistas* arts, char* id){
    if(arts->qtda == 0) {
        return NOT_FOUND;
    }

    for(int i=0;i<arts->qtda;i++){
        if(strcmp(id,RetId(arts->art[i])) == 0){
            return i;
        }
    }
    return NOT_FOUND;
}

int AcharIndexArtPeloIdB(tArtistas* arts, char* id) {
    if(arts->qtda == 0) {
        return NOT_FOUND;
    }

    int i = 0, f = arts->qtda - 1, idx = NOT_FOUND;

    while(i <= f) {
        idx = (i+f)/2;
        if(RelacionaId1ComId2(id, RetId(arts->art[idx])) == ID1_IGUAL){
            return idx;
        }
        else if(RelacionaId1ComId2(id, RetId(arts->art[idx])) == ID1_MENOR){
            f = idx - 1;
        }
        else if(RelacionaId1ComId2(id, RetId(arts->art[idx])) == ID1_MAIOR){
            i = idx + 1;
        }
    }

    return NOT_FOUND;
}

tArtista* RetornaArtistaPonteiro(tArtistas* arts, int idx){
    if(idx >= arts->qtda || idx < 0 || arts->qtda == 0) {
        return NULL;
    }
    return arts->art[idx];
}

void GeraRelatorioArtistas(tArtistas* arts, char* caminho) {
    int i = 0, flag = 0;
    char path[1000];
    strcpy(path, caminho);
    strcat(path, "relatorioArtistas.txt");
    FILE * f = fopen(path, "w");

    if(f == NULL) {
        printf("Erro ao abrir caminho para relatorio de artistas: %s\n\n", path);
        return;
    }
    //rAp eh a relacao artista e a quatidade de playlist que as musicas dele foram adicionadas
    tPeso** rAp = (tPeso**)calloc(arts->qtda, sizeof(tPeso*));

    for(i = 0; i < arts->qtda; i++) {
        rAp[i] = CriaPeso(i, RetQtdPlayArt(arts->art[i]));
    }

    OrdenaPeloPesoDecrescente(rAp, arts->qtda);

    for(i = 0; i < arts->qtda; i++) {
        if(RetornaPeso(rAp[i]) > 0.0) {
            fprintf(f, "%d- ", i + 1);
            ImprimeArtistaArquivo(arts->art[RetornaItem(rAp[i])], f);
            flag++;
        }
    }

    if(!flag){
        fprintf(f, "Nenhum artista tem musica em playlist, ou ele nao foi encontrado no arquivo de artistas!");
    }

    for(i = 0; i < arts->qtda; i++) {
        LiberaPeso(&rAp[i]);
    }

    free(rAp);
    rAp = NULL;

    fclose(f);
}
