#include "musica.h"

struct tMusica
{
    char *id;
    char *nM; //Nome da musica
    int popu;
    double dura_ms;
    int eh_explic;
    tArtistas *artista; //Vetor de artistas que cantam a musica
    int qtdA; //Quantidade de artistas que produziram a musica
    char **idA; //Id dos artistas que cantam a musica
    char *nA; //Nome dos artistas que cantam a musica
    tData_pt dataL; //Data de lancamento
    tPropiedades* prop; //Propriedades da musica
    int qtdPlay; //Quantidade de playlist que pertence
};

struct tMusicaVet{
    tMusica* *musicas;
    int qtdM;
    int tamVet;
};

tMusica *CriaMusica(char* id, char* nM, int popu, double duracao, int exp, tArtistas* art, int qtdA, char* nA, char **idA, 
                    tData_pt dataL, tPropiedades* p,  int qtdPlay) {
    
    tMusica *m = (tMusica*)malloc(sizeof(*m));
    int i = 0;

    m->id = (char*)malloc(sizeof(char)*(strlen(id)+1));
    strcpy(m->id, id);

    m->nM = (char*)malloc(strlen(nM)+1);
    strcpy(m->nM, nM);

    m->dura_ms = duracao;

    m->eh_explic = exp;

    m->artista = art;

    m->nA = (char*)malloc(sizeof(char)*(strlen(nA)+1));
    strcpy(m->nA, nA);

    //Alocando o vetor com os ids dos artistas
    m->qtdA = qtdA;
    m->idA = (char**)malloc(sizeof(char*));
    for(i = 0; i < qtdA; i++){
        m->idA[i] = (char*)malloc(sizeof(char)*(strlen(idA[i])+1));
        strcpy(m->idA[i], idA[i]);
    }

    m->dataL = dataL;

    m->prop = p;

    m->qtdPlay = qtdPlay;

    return m;
}


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