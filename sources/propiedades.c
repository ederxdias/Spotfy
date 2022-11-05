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

void LiberaPropiedades(tPropiedades* p) {
    if(p != NULL){
        free(p);
        p = NULL;
    }
}
