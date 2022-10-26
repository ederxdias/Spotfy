#include "circulo.h"
#include "funcoes.h"
struct tCirculo {
  float raio;
  float area;
};
tCirculo *CriarCirculo(float raio) {
  tCirculo *circulo = NULL;
  circulo = malloc(sizeof(tCirculo));
  circulo->raio = raio;
  if (circulo == NULL)
    exit(-1);
  circulo->area = AreaCircular(raio);
  return circulo;
}
float AreaCircular(float raio) {
  double area = M_PI * pow(raio, 2);
  return area;
}
float RetornarAreaC(tCirculo *c) { return c->area; }
void LiberarC(void *p) {
  if (p != NULL)
    free(p);
}
int Tc() { return sizeof(tCirculo); }