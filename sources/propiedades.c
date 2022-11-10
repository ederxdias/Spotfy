#include "propiedades.h"

struct tPropiedades
{
    double danceability;
    double energy;
    int mode;
    double speechiness;
    double acousticness;
    double instrumentalness;
    double liveness;
    double valence;
    double loudness;
    double tempo;
    int time_signature;
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
    printf("Danceability: [%.2lf] | ", p->danceability);
    printf("Energy: [%.2lf] | ", p->energy);
    printf("Key: [%d]\n", p->key);
    printf("Loudness: %.2lf db | ", p->loudness);
    printf("Mode: %d | ", p->mode);
    printf("Speechiness: [%.2lf] | ", p->speechiness);
    printf("Acousticness: [%.2lf]\n", p->acousticness);
    printf("Instrumentalness: [%.2lf] | ", p->instrumentalness);
    printf("Liveness: [%.2lf] | ", p->liveness);
    printf("Valence: [%1.2lf]", p->valence);
    printf("\n");
    printf("Tempo: %.2lf BPM | ", p->tempo);
    printf("Time_signature: %d", p->time_signature);
    printf("\n");
}

double RetornaDanceProp(tPropiedades* p) {
    return p->danceability;
}

double RetornaEnergProp(tPropiedades* p) {
    return p->energy;
}

int RetornaModeProp(tPropiedades* p) {
    return p->mode;
}

double RetornaSpeechProp(tPropiedades* p) {
    return p->speechiness;
}

double RetornaAcoustProp(tPropiedades* p) {
    return p->acousticness;
}

double RetornaInstruProp(tPropiedades* p) {
    return p->instrumentalness;
}

double RetornaLivenessProp(tPropiedades* p) {
    return p->liveness;
}

double RetornaValencProp(tPropiedades* p) {
    return p->valence;
}

double DistanciaEntrePropriedades(tPropiedades* p1, tPropiedades* p2) {
    double dist = 0;

    dist += pow((p1->danceability - p2->danceability), 2);
    dist += pow((p1->energy - p2->energy), 2);
    dist += pow((p1->mode - p2->mode), 2);
    dist += pow((p1->speechiness - p2->speechiness), 2);
    dist += pow((p1->acousticness - p2->acousticness), 2);
    dist += pow((p1->instrumentalness - p2->instrumentalness), 2);
    dist += pow((p1->liveness - p2->liveness), 2);
    dist += pow((p1->valence - p2->valence), 2);

    dist = sqrt(dist);

    return dist;
}