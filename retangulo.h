#ifndef Retangulo_H
#define Retangulo_H
#include "funcoes.h"
typedef struct tRetangulo tRetangulo;
tRetangulo *CriarRetangulo(float comprimento, float largura);
float AreaRetangular(float comprimento, float largura);
float RetornarAreaR(tRetangulo *r);
void LiberarR(void *p);
int Tr();
#endif