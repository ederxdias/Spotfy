#include "triangulo.h"
#include "funcoes.h"
struct tTriangulo {
  float altura;
  float base;
  float area;
};
tTriangulo *CriarTriangulo(float altura, float base) {
  tTriangulo *triangulo = NULL;
  triangulo = malloc(sizeof(tTriangulo));
  if (triangulo == NULL)
    exit(-1);
  triangulo->altura = altura;
  triangulo->base = base;
  triangulo->area = AreaTriangular(base, altura);
  printf("ss%fss", triangulo->area);
  return triangulo;
}

float AreaTriangular(float base, float altura) {
  float area = (base * altura) / 2;
  return area;
}
float RetornarAreaT(tTriangulo *t) { return t->area; }
void LiberarT(void *p) {
  if (p != NULL)
    free(p);
}
int Tt() { return sizeof(tTriangulo); }