#include "peso.h"

typedef int (*fptrComp)(const void*, const void*);

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

int EhPeso1MaiorQePeso2(const void* p1, const void* p2) {
    if((*(tPeso**)p1)->peso > (*(tPeso**)p2)->peso) {
        return 1;
    }
    else
        return 0;
}

int EhPeso1MenorQePeso2(const void* p1, const void* p2) {
    if((*(tPeso**)p1)->peso < (*(tPeso**)p2)->peso) {
        return 1;
    }
    else
        return 0;
}

void OrdenaPeloPesoDecrescente(tPeso** p, int tam) {
    fptrComp compara = EhPeso1MenorQePeso2;
    qsort(p, tam, sizeof(*p), compara);
}

void OrdenaPeloPesoCrescente(tPeso** p, int tam) {
    fptrComp compara = EhPeso1MaiorQePeso2;
    qsort(p, tam, sizeof(*p), compara);
}