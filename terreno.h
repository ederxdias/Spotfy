#ifndef AREA_H
#define AREA_H
#include "funcoes.h"

typedef struct tTerreno tTerreno;

void LeTerreno(tTerreno *terreno, int num);
void LiberarTE(void *p);
void LeTerreno(tTerreno *terreno, int num);
tTerreno *InicializaTerreno();
float AreaTotal(tTerreno *t);
float Media(tTerreno *t);
float DesvioPadrao(tTerreno *t, float media);
float LiberarTerreno(tTerreno *t);
#endif