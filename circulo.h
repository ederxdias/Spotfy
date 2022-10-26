#ifndef Circulo_H
#define Circulo_H
typedef struct tCirculo tCirculo;
tCirculo *CriarCirculo(float raio);
float AreaCircular(float raio);
float RetornarAreaC(tCirculo *c);
void LiberarC(void *p);
int Tc() ;
#endif