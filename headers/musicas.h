#ifndef _MUSICAS_H_
#define _MUSICAS_H_

#include "musica.h"
#include "peso.h"

typedef struct tMusicas tMusicas;

/**
 * @brief Cria um tMusicas* alocado dinamicamente
 * 
 * @return tMusicas* 
 */
tMusicas* InicializaVetorMusicas();

/**
 * @brief Faz a leitura das musicas do arquivo e relaciona as musicas aos aos artistas relacionados
 * ignora os tArtista* 
 * 
 * @param caminho: caminho do arquivo que os tArtista* estao para ser lidos 
 * @param arts: tArtistas* que tem os tArtista* relacionados as musicas a serem lidas
 * @return tMusicas* 
 */
tMusicas* LeMusicasDoArquivo(char* caminho, tArtistas *arts);

/**
 * @brief Adiciona uma musica(tMusica*) ao vetor tMusicas*
 * 
 * @param v: tMuscias* onde sera adicionado o tMusica* 
 * @param m: tMusica* que sera adicionado ao tMusicas* 
 */
void AdicionaMusicaAoVetMusicas(tMusicas *v, tMusica* m);

/**
 * @brief Libera o tMusicas*
 * 
 * @param vet: tMusicas** que representa o caminho do tMusicas* a ser liberado 
 */
void LiberaVetorMusicas(tMusicas **vet);

/**
 * @brief Imprime informacoes da musica(tMusica*) e de seus artistas na tela que esta no tMusicas*
 * 
 * @param mscs: tMusicas* onde a musica(tMusica*) esta
 * @param idx: indice onde a musica(tMusica*) esta no vetor do tMusicas* 
 */
void ListarMusicaPeloIndice(tMusicas *mscs, int idx);

/**
 * @brief Retorna a musica(tMusica*) que esta no tMusicas*
 * 
 * @param mscs: tMusicas* onde a musica esta 
 * @param idx: indice que representa a musica desejada no tMusicas* 
 * @return tMusica* 
 */
tMusica* RetMusicaPeloIdx(tMusicas *mscs, int idx);

/**
 * @brief Imprime no terminal as musicas com os nomes que contem a strig busca
 * 
 * @param mscs: tMusicas* onde sera realizada a busca 
 * @param busca: string que sera usada na busca 
 */
void BuscarMusicasPeloNome(tMusicas *mscs, char *busca);

/**
 * @brief Executa uma das musica(tMusica*) que se encontra no tMusicas*
 * 
 * @param mscs: tMusicas*  
 * @param idx: indice que representa a musica(tMusica*) que esta no tMusicas* que sera executada 
 */
void ExecutaMusicaPeloIdx(tMusicas* mscs, int idx);

/**
 * @brief Gera um relatorio em um arquivo em ordem decrescentes das musicas que mais estiveram 
 * em playlists
 * 
 * @param mscs: tMusicas* que sera gerado o relatorio 
 * @param caminho: uma string que representa o caminho ate o local que sera salvo o arquivo de relatorio
 */
void GeraRelatorioMusicas(tMusicas* mscs, char* caminho); 

/**
 * @brief Retorna a quantidade de musicas que o tMusicas* possui no momento
 * 
 * @param mscs: tMusicas* 
 * @return int representa a quantidade de musicas(tMusica*) que o tMusicas* tem
 */
int RetQtdMusicasNaLista(tMusicas* mscs);

#endif