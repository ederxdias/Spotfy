#include "musica.h"

struct tMusica
{
    char *id;
    char *nM; //Nome da musica
    int popu;
    double dura_ms;
    int eh_explic;
    char **arts; //Nome de artistas que cantam a musica
    int qtdA; //Quantidade de artistas que produziram a musica
    char **idA; //Id dos artistas que cantam a musica
    char *nA; //Nome dos artistas que cantam a musica
    tData_pt dataL; //Data de lancamento
    tPropiedades* prop; //Propriedades da musica
    int qtdPlay; //Quantidade de playlist que pertence
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

    m->arts = art;

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
