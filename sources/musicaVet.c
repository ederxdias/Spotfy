#include "musicaVet.h"

#define TAM_INICIAL_VET 132

struct tMusicaVet{
    tMusica* *musicas;
    int qtdM;
    int tamVet;
};

tMusicaVet* InicializaVetorMusicas() {
    tMusicaVet* v = (tMusicaVet*)malloc(sizeof(*v));
    v->tamVet = TAM_INICIAL_VET;
    v->musicas = (tMusica**)malloc(sizeof(tMusica*)*v->tamVet);
    v->qtdM = 0;

    return v;
}

tMusicaVet* LeMusicasDoArquivo(char* caminho, tArtistas *arts) {
   tMusicaVet* v = InicializaVetorMusicas();
    tMusica* musica = NULL;

    FILE * f = NULL;

    f = fopen(caminho, "r");

    if(f == NULL){
        printf("Erro ao abrir arquivo: %s\n", caminho);
        exit(1);
    }
    while(!feof(f)) {
        musica = LeMusicaDoArquivo(f);

        if(musica != NULL){
            AdicionarArtistasDaMusica(musica,arts);
            AdicionaMusicaAoVetMusicas(v, musica);
        } 

    }
      
    fclose(f);
 
    return v;
}

void AdicionaMusicaAoVetMusicas(tMusicaVet *v, tMusica* m) {
    if(v->qtdM >= v->tamVet) {
        v->tamVet = v->tamVet*2;
        v->musicas = realloc(v->musicas, sizeof(*v->musicas)*v->tamVet);
    }

    v->musicas[v->qtdM] = m;
    v->qtdM++;
}

void LiberaVetorMusicas(tMusicaVet **vet){
    int i = 0;

    if(*vet != NULL){
        for(i = 0; i < (*vet)->qtdM; i++) {
            LiberaMusica(&(*vet)->musicas[i]);
        }
        
        free((*vet)->musicas);
        (*vet)->musicas = NULL;

        free(*vet);
        *vet = NULL;
    }
}

void ListarMusica(tMusicaVet *mscs, int idx){
    
    ImprimirMusica(mscs->musicas[idx]);
}

tMusica* RetMusicaIdx(tMusicaVet *mscs, int idx) {
    if(idx >= mscs->qtdM){
        printf("Indice maior que a lista de musicas.\n");
        return NULL;
    }
    return mscs->musicas[idx];
}
void BuscarMusicas(tMusicaVet *mscs){
    printf("Por favor digite o nome da musica pedida?:\n");
    char nome[100];
    scanf("%s", nome);
    int n = strlen(nome);
    char  inter[100];
    inter[0] ='\0';
    for(int i=0;i<mscs->qtdM;i++){
        strncat(inter,RetornarNomeMusic(mscs->musicas[i]) ,n);
        if(strcmp(nome,inter)==0){
            printf("Indice da musica:%d\n",RetIndDaMusic(mscs->musicas[i]));
            printf("Id da musica:%s\n", RetIdM(mscs->musicas[i]));
            printf("Titulo da musica: %s\n", RetornarNomeMusic(mscs->musicas[i]));
            printf("Nomes dos Artistas:\n ");
            ImpriNomArtsMusi(mscs->musicas[i]);
            printf("\n\n");
        }
        inter[0]='\0';
    }
}


