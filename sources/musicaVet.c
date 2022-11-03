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

tMusicaVet* LeMusicasDoArquivo(char* caminho) {
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

        if(musica == NULL)
            break;

        AdicionaMusicaAoVetMusicas(v, musica);
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

void LiberaVetorMusicas(tMusicaVet *vet){
    int i = 0;

    for(i = 0; i < vet->qtdM; i++) {
        LiberaMusica(vet->musicas[i]);
    }
    free(vet->musicas);

    free(vet);
}