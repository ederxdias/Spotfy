#include "propiedades.h"

struct tPropiedades
{
    double danceability;
    double energy;
    double speechiness;
    double acousticness;
    double instrumentalness;
    double liveness;
    double valence;
    double loudness;
    double tempo;
    int time_signature;
    int mode;
    int key;
};

tPropiedades* CriaPropriedades(double dance, double energy, double speech, double acous, double inst, int key,
                               double live, double vale, double loud, double temp, int time_s, int mode){
    
    tPropiedades* p = (tPropiedades*)malloc(sizeof(*p));

    p->danceability = dance;
    p->energy = energy;
    p->speechiness = speech;
    p->acousticness = acous;
    p->instrumentalness = inst;
    p->liveness = live;
    p->valence = vale;
    p->loudness = loud;
    p->tempo = temp;
    p->time_signature = time_s;
    p->mode = mode;
    p->key = key;

    return p;
}

void LiberaPropiedades(tPropiedades** p) {
    if(*p != NULL){
        free(*p);
        *p = NULL;
    }
}
void ImprimirPropiedades(tPropiedades *p){
    printf("danceability: [%.1f] ", p->danceability);
    printf("energy: [%.1f] ", p->energy);
    printf("key: [%d]", p->key);
    printf("loudness: %.2f db ", p->loudness);
    printf("mode: %d ", p->mode);
    printf("\n");
    printf("speechiness: [%.1f]  ", p->speechiness);
    printf("acousticness: [%.1f]  ", p->acousticness);
    printf("instrumentalness: [%.1f]  ", p->instrumentalness);
    printf("liveness: [%.1f]  ", p->liveness);
    printf("valence: [%1.f]  ", p->valence);
    printf("\n");
    printf("tempo: %.2f BPM  ", p->tempo);
    printf("Time_signature: %d", p->time_signature);
    printf("\n");
}
