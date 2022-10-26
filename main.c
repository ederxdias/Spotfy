#include "terreno.h"


int main(void) {
  int n;
  scanf("%d", &n);
  tTerreno *t = InicializaTerreno();
  LeTerreno(t, n);
  float media = Media(t);
  float desvio_padrao = DesvioPadrao(t, media);
  printf("\nMEDIA DESMATAMENTO: %.3f\n", media);
  printf("DESVIO PADRAO: %.3f\n", desvio_padrao);

  return 0;
}