#ifndef MUSICA_H
#define MUSICA_H

#include "artistas.h"
#include "propiedades.h"

typedef struct tMusica tMusica;

tMusica *CriaMusica(char* id, char* nM, int popu, int duracao, int exp, int qtdA, char** nA, char **idA, 
                    char *dataL, tPropiedades* p,  int qtdPlay);

void LiberaMusica(tMusica **m);

//Le a musica do arquivo que ja deve estar aberto em modo leitura, caso a linha encontrada esteja fora do
//padrao esperado a linha eh desconsiderada e a funcao retorna NULL
tMusica* LeMusicaDoArquivo(FILE * f);

//Funcao auxiliar na leitura da musica, cria uma matriz de char de acordo com o tamanho informado
char** CriaUmaMatrizDeChar(int qtdLinha, int qtdChars);

void LiberaMatrizDeChar(char **m, int qtdLinha, int qtdChars);

//Funcao para relacionar os artistas que produziram a musica
void AdicionarArtistasDaMusica(tMusica *msc, tArtistas *arts);

char *RetornaIdMusica(tMusica *msc);

//Retorna a quantidade de artistas que produziram a musica
int RetQtdArtsM(tMusica *msc);

void ConfiguraMusicaNaPlaylist(tMusica *msc);

void ImprimirMusica(tMusica *msc);

char *RetornaNomeMusic(tMusica *msc);

//Retorna uma vetor de strigs com o nome de cada artista que produziu a musica
char** RetornaNomeDosArtistasDaM(tMusica *msc);

void ExecutarMusica(tMusica* msc);

//Imprime informacoes da musica no arquivo que ja deve estar aberto em modo escrita
void ImprimirMusicaArquivo(tMusica *msc, FILE * f);

//Retorna a quantidade de playlist que a musica esta inserida
int RetQtdPlayMusica(tMusica* msc);

tPropiedades* RetornaPropriedadesMusica(tMusica* msc);

#endif