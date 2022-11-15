#include "artista.h"

typedef int (*fptrComp)(const void*, const void*);

struct tArtista
{
    char *id; // id do artista na base do Spotify.
    double seg; // Número de seguidores.
    char *gen; // Uma lista de generos associados ao artista.
    char *nA; // Nome do artista.
    int popu; // Popularidade do artista entre 0 e 100.
    int playP; //Quantidade de musicas em playlist
};


tArtista *CriarArtista(char *id, double seg, char *gen, char *nA, int popu){
    tArtista *art =(tArtista*) malloc(sizeof(*art));
    if(art == NULL){
        printf("Falha na alocação do ponteiro de artista!\n\n");
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
    art->playP = 0;
    
    return art;
}


tArtista *LeArtista(FILE *arq){
    if(arq == NULL) {
        printf("LeArtista: Arquivo deve estar aberto em modo leitura!\n");
        exit(EXIT_FAILURE);
    }
    char id[100];
    if(fscanf(arq,"%[^;];",id) != 1){
        fscanf(arq, "%*[^\n]\n");
        return NULL;
    }
    
    double seg;
    if(fscanf(arq,"%lf;",&seg) != 1){
        fscanf(arq, "%*[^\n]\n");
        return NULL;
    }

    char gen[10000];
    if(fscanf(arq,"%[^;];",gen) != 1) {
        fscanf(arq, "%*[^\n]\n");
        return NULL;
    }

    char nA[10000]; 
    if(fscanf(arq,"%[^;];",nA) != 1) {
        fscanf(arq, "%*[^\n]\n");
        return NULL;
    }

    int popu;
    if(fscanf(arq,"%d\n",&popu) != 1) {
        fscanf(arq, "%*[^\n]\n");
        return NULL;
    }
    
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
    printf("Genero: %s\n",art->gen);
}

void IncrementaQtdPlaylistArtista(tArtista *art) {
    art->playP++;
}

int RetQtdPlayArt(tArtista* art) {
    return art->playP;
}

void ImprimeArtistaArquivo(tArtista* art, FILE * f) {
    if(f == NULL) {
        printf("ImprimeArtistaArquivo: o arquivo deve estar aberto no modo de escrita!\n\n");
        exit(EXIT_FAILURE);
    }

    fprintf(f, "Nome: %s | ", art->nA);
    fprintf(f, "Id: %s | ", art->id);
    fprintf(f, "Seguidores: %.0lf | ", art->seg);
    fprintf(f, "Popularidade: %d | ", art->popu);
    fprintf(f, "Genero: %s\n",art->gen);
}

int EhIdArt1MaiorIdArt2(const void* art1, const void* art2) {
    if(strcmp((*(tArtista**)art1)->id, (*(tArtista**)art2)->id) > 0){
        return 1;
    }
    else
        return 0;
}

int RelacionaId1ComId2(char* id1, char* id2) {
    if(strcmp(id1, id2) == 0) {
        return ID1_IGUAL;
    }
    else if(strcmp(id1, id2) > 0) {
        return ID1_MAIOR;
    }
    else {
        return ID1_MENOR;
    }
}

void OrdenaArrArtistasCrescenteId(tArtista* *art, int tam) {
    fptrComp compara = EhIdArt1MaiorIdArt2;
    qsort(art, tam, sizeof(*art), compara);
}
