#ifndef Triangulo_H
#define Triangulo_H
typedef struct tTriangulo tTriangulo;
tTriangulo *CriarTriangulo(float altura, float base);
float AreaTriangular(float base, float altura);
float RetornarAreaT(tTriangulo *t);
void LiberarT(void *p);
int Tt();

#endif