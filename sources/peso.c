#include "peso.h"

struct tPeso{
    int item;
    double peso;
};

tPeso* CriaPeso(int item, double peso) {
    tPeso* p = (tPeso*)malloc(sizeof(*p));

    p->item = item;
    p->peso = peso;

    return p;
}

void LiberaPeso(tPeso* *p) {
    if(*p != NULL) {
        free(*p);
        *p = NULL;
    }
}

int RetornaItem(tPeso* p) {
    return p->item;
}

double RetornaPeso(tPeso* p) {
    return p->peso;
}

void OrdenaPeloPesoDecrescente(tPeso** p, int tam) {
    int i = 0, j = 0;
    tPeso* chave = NULL;
    
    for(i = 1; i < tam; i++){
        chave = p[i];
        j = i - 1;

        while(j > -1 && p[j]->peso < chave->peso) {
            p[j+1] = p[j];
            j--;
        }
        p[j+1] = chave;
    }
}

void OrdenaPeloPesoCrescente(tPeso** p, int tam) {
    int i = 0, j = 0;
    tPeso* chave = NULL;
    
    for(i = 1; i < tam; i++){
        chave = p[i];
        j = i - 1;

        while(j > -1 && p[j]->peso > chave->peso) {
            p[j+1] = p[j];
            j--;
        }
        p[j+1] = chave;
    }
}