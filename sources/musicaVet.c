#include "musicaVet.h"

struct tMusicaVet{
    tMusica* *musicas;
    int qtdM;
    int tamVet;
};

tMusicaVet* InicializaVetorMusicas() {
    tMusicaVet* v = (tMusicaVet*)malloc(sizeof(*v));
    v->tamVet = 10;
    v->musicas = (tMusica**)malloc(sizeof(tMusica*)*v->tamVet);
    v->qtdM = 0;

    return v;
}

tMusicaVet* LeMusicasDoArquivo(char* caminho) {
   tMusicaVet* v = InicializaVetorMusicas;

    char id[100], nM[10000], nA[10000], idA[10000];
    int popu, exp, qtdPlay = 0, dia, mes, ano;
    double danceability, energy, speechiness, acousticness;
    double instrumentalness, liveness, valence, loudness, tempo;
    double duracao;
    tPropiedades* p;
    tData_pt data;

    FILE * f = NULL;

    f = fopen(caminho, "r");

    if(f == NULL){
        printf("Erro ao abrir arquivo: %s\n", caminho);
        exit(1);
    }


}