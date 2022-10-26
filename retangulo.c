#include "retangulo.h"
#include "funcoes.h"
struct tRetangulo {
  float comprimento;
  float largura;
  float area;
};

tRetangulo *CriarRetangulo(float comprimento, float largura) {
  tRetangulo *retangulo = NULL;
  retangulo = malloc(sizeof(tRetangulo));
  if (retangulo == NULL)
    exit(-1);
  retangulo->comprimento = comprimento;
  retangulo->largura = largura;
  retangulo->area = AreaRetangular(comprimento, largura);
  return retangulo;
}
float AreaRetangular(float comprimento, float largura) {
  float area = comprimento * largura;
  return area;
}
float RetornarAreaR(tRetangulo *r) { return r->area; }
void LiberarR(void *p) {
  if (p != NULL)
    free(p);
}
int Tr() { return sizeof(tRetangulo); }