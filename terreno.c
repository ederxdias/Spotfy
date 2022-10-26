#include "terreno.h"
#include "circulo.h"
#include "funcoes.h"
#include "retangulo.h"
#include "triangulo.h"

struct tTerreno {
  tTriangulo **triangulo;
  int tri;
  tRetangulo **retangulo;
  int ret;
  tCirculo **circulo;
  int cir;
};

tTerreno *InicializaTerreno() {
  tTerreno *terreno = NULL;
  terreno = malloc(sizeof(tTerreno));
  if (terreno == NULL)
    exit(-1);
  return terreno;
};
void LeTerreno(tTerreno *terreno, int num) {
  char tipo;
  int cir = 0, ret = 0, tri = 0;
  terreno->circulo = malloc(Tc() * num);
  terreno->retangulo = malloc(Tr() * num);
  terreno->triangulo = malloc(Tt() * num);
  for (int i = 0; i < num; i++) {
    scanf("%c ", &tipo);
    printf("%c", tipo);
    if (tipo == 'C') {
      float r;
      scanf("%f\n", &r);
      tCirculo *c = CriarCirculo(r);
      terreno->circulo[cir] = c;
      cir++;
    } else if (tipo == 'R') {
      float l, c;
      scanf("%f %f\n", &c, &l);
      tRetangulo *r = CriarRetangulo(c, l);
      terreno->retangulo[ret] = r;
      ret++;
    } else if (tipo == 'T') {
      float h, b;
      scanf("%f %f\n", &h, &b);
      tTriangulo *t = CriarTriangulo(h, b);
      terreno->triangulo[tri] = t;
      tri++;
    }
  }
  terreno->cir = cir;
  terreno->ret = ret;
  terreno->tri = tri;
}

void LiberarTE(void *p) {
  if (p != NULL)
    free(p);
}

float Media(tTerreno *t) {
  float media = 0;

  for (int i = 0; i < t->cir; i++) {
    media += RetornarAreaC(t->circulo[i]);
  }
  for (int i = 0; i < t->ret; i++) {
    media += RetornarAreaR(t->retangulo[i]);
  }
  for (int i = 0; i < t->tri; i++) {

    media += RetornarAreaT(t->triangulo[i]);
  }
  return (media / (t->ret + t->tri + t->cir));
}
float DesvioPadrao(tTerreno *t, float media) {
  float soma = 0;
  for (int i = 0; i < t->cir; i++) {
    soma += pow(RetornarAreaC(t->circulo[i]) - media, 2);
    LiberarC(t->circulo[i]);
  }
  for (int i = 0; i < t->ret; i++) {
    soma += pow(RetornarAreaR(t->retangulo[i]) - media, 2);
    LiberarR(t->retangulo[i]);
  }
  for (int i = 0; i < t->tri; i++) {
    soma += pow(RetornarAreaT(t->triangulo[i]) - media, 2);
    LiberarT(t->triangulo[i]);
  }
  float dv = sqrt(soma / (t->ret + t->tri + t->cir));
  LiberarT(t);
  return dv;
}