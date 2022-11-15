#ifndef _MUSICAS_H_
#define _MUSICAS_H_

#include "musica.h"
#include "peso.h"

typedef struct tMusicas tMusicas;

tMusicas* InicializaVetorMusicas();

//Faz a leitura das musicas do arquivo e relaciona as musicas aos aos artistas realcionados
tMusicas* LeMusicasDoArquivo(char* caminho, tArtistas *arts);

void AdicionaMusicaAoVetMusicas(tMusicas *v, tMusica* m);

void LiberaVetorMusicas(tMusicas **vet);

//Imprime informacoes da musica e de seus artistas na tela
void ListarMusicaPeloIndice(tMusicas *mscs, int idx);

tMusica* RetMusicaPeloIdx(tMusicas *mscs, int idx);

//Encontra uma musica de acordo com a string(busca) passada e imprime nome e indice das musicas
//encontradas
void BuscarMusicasPeloNome(tMusicas *mscs, char *busca);

void ExecutaMusicaPeloIdx(tMusicas* mscs, int idx);

//Gera um relatorio em ordem decrescentes das musicas que mais estiveram em playlists, o caminho passado
//deve ser apenas ate o diretorio onde o aquivo sera salvo
void GeraRelatorioMusicas(tMusicas* mscs, char* caminho); 

//Retorna a quantidade de musicas que o tMusicas* possui no momento
int RetQtdMusicasNaLista(tMusicas* mscs);

#endif