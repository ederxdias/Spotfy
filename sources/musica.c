#include "musica.h"

struct tMusica
{
    char *id;
    char *nM; //Nome da musica
    int popu;
    int dura_ms;
    int eh_explic;
    tArtistas* artista; //Vetor dos artistas que cantam a musica
    int qtdA; //Quantidade de artistas que produziram a musica
    char **idA; //Id dos artistas que cantam a musica
    char **nA; //Nome dos artistas que cantam a musica
    tData_pt dataL; //Data de lancamento
    tPropiedades* prop; //Propriedades da musica
    int qtdPlay; //Quantidade de playlist que pertence
};

tMusica *CriaMusica(char* id, char* nM, int popu, int duracao, int exp, tArtistas* art, int qtdA, char** nA, char **idA, 
                    tData_pt dataL, tPropiedades* p,  int qtdPlay) {
    
    tMusica *m = (tMusica*)malloc(sizeof(*m));
    int i = 0;

    m->id = (char*)malloc(sizeof(char)*(strlen(id) + 1));
    strncpy(m->id, id, strlen(id));

    m->nM = (char*)malloc(sizeof(char)*(strlen(nM) + 1));
    strncpy(m->nM, nM, strlen(nM));

    m->popu = popu;

    m->dura_ms = duracao;

    m->eh_explic = exp;

    m->arts = art;

    m->qtdA = qtdA;

    //Alocando o vetor com o nome dos artistas
    m->nA = (char**)malloc(sizeof(char*)*qtdA);
    for(i = 0; i < qtdA; i++){
        m->nA[i] = (char*)malloc(sizeof(char)*(strlen(nA[i]) + 1));
        strncpy(m->nA[i], idA[i], strlen(nA[i]));
    }

    //Alocando o vetor com os ids dos artistas
    m->idA = (char**)malloc(sizeof(char*)*qtdA);
    for(i = 0; i < qtdA; i++){
        m->idA[i] = (char*)malloc(sizeof(char)*(strlen(idA[i]) + 1));
        strncpy(m->idA[i], idA[i], strlen(idA[i]));
    }

    m->dataL = dataL;

    m->prop = p;

    m->qtdPlay = qtdPlay;

    return m;
}

void LiberaMusica(tMusica *m) {
    int i = 0;

    free(m->id);

    free(m->nM);

    for(i = 0; i < m->qtdA; i++) {
        free(m->nA[i]);
        free(m->idA[i]);
    }

    free(m->nA);
    free(m->idA);

    LiberaPropiedades(&m->prop);

    LiberaData(m->dataL);

    free(m);
}
