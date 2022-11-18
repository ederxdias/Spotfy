#ifndef MUSICA_H
#define MUSICA_H

#include "artistas.h"
#include "propiedades.h"

typedef struct tMusica tMusica;

/**
 * @brief Cria um tMusica* alocado dinamicamente na memoria
 * 
 * @param id: uma string que representa o id da musica
 * @param nM: uma string que representa o nome da musica
 * @param popu: um int que representa a popularidade da musica 
 * @param duracao: um int que representa a duracao da musica em ms 
 * @param exp: um int que representa se a musica eh explicita ou nao 
 * @param qtdA: um int que representa a quantidade de artistas da musicas 
 * @param nA: um vetor de strings com o nome de cada artista que produziu a musica 
 * @param idA: um vetor de strings com o id de cada artista que produziu a musica 
 * @param dataL: uma strig que representa a data de lancamento da musica 
 * @param p: tPropiedades* com as propriedades da musica 
 * @param qtdPlay: um int que representa a quantidade de playlist que a musica se encontra 
 * @return tMusica* 
 */
tMusica *CriaMusica(char* id, char* nM, int popu, int duracao, int exp, int qtdA, char** nA, char **idA, 
                    char *dataL, tPropiedades* p,  int qtdPlay);

/**
 * @brief Libera o tMusica*
 * 
 * @param m: tMusica** que representa o caminho do tMusica* a ser liberado 
 */
void LiberaMusica(tMusica **m);

/**
 * @brief Le a musica do arquivo, caso a linha encontrada esteja fora do padrao esperado a linha
 *  eh desconsiderada e a funcao retorna NULL
 * 
 * @param f: FILE * que representa o arquivo onde sera realizada a leitura da musica(tMusica*),
 * o arquivo deve ja estar aberto em modo leitura "r"  
 * @return tMusica* 
 */
tMusica* LeMusicaDoArquivo(FILE * f);

/**
 * @brief Funcao auxiliar na leitura da musica. Cria uma matriz de char aloca dinamicamente 
 * de acordo com o tamanho informado
 * 
 * @param qtdLinha: um int que representa a quantidade de linha da matriz
 * @param qtdChars: um int que representa a quantidade de char em cada linha 
 * @return char** que representa a matriz 
 */
char** CriaUmaMatrizDeChar(int qtdLinha, int qtdChars);

/**
 * @brief Libera uma matriz de char(char**)
 * 
 * @param m: char** que representa a matride char
 * @param qtdLinha: um int que representa a quantidade de linha da matriz
 * @param qtdChars: um int que representa a quantidade de char em cada linha 
 */
void LiberaMatrizDeChar(char **m, int qtdLinha, int qtdChars);

/**
 * @brief Funcao para relacionar os artistas(tArtista*) que produziram a musica(tMusica*)
 * 
 * @param msc: tMusica* que sera relacionado os artistas 
 * @param arts: tArtistas* que contem os artistas(tArtista*) que produziram a musica(tMusica*) 
 */
void AdicionarArtistasDaMusica(tMusica *msc, tArtistas *arts);

/**
 * @brief Retorna o id da musica
 * 
 * @param msc: tMusica* que retornara o id 
 * @return char* um string que representa o id da musica 
 */
char *RetornaIdMusica(tMusica *msc);

/**
 * @brief Retorna a quantidade de artistas que produziram a musica(tMusicas*)
 * 
 * @param msc: tMusica* que retonara a quantidade de artistas 
 * @return int representa a quantidade de artistas que produziram a musica 
 */
int RetQtdArtsM(tMusica *msc);

/**
 * @brief Configura a musica em um playlist
 * 
 * @param msc: tMusica* que sera configurado 
 */
void ConfiguraMusicaNaPlaylist(tMusica *msc);

/**
 * @brief Imprime informacoes da musica(tMusica*) no terminal
 * 
 * @param msc: tMusica* a ser impresso no terminal 
 */
void ImprimirMusica(tMusica *msc);

/**
 * @brief Retorna o nome da musica(tMusica*)
 * 
 * @param msc: tMusica* que sera retornado o nome 
 * @return char* uma string que representa o nome da musica 
 */
char *RetornaNomeMusic(tMusica *msc);

/**
 * @brief Retorna uma vetor de strigs com o nome de cada artista que produziu a musica
 * 
 * @param msc: tMusica* que retornara o vetor de strings com o nome dos artistas que produziram a musica 
 * @return char** vetor de string com o nome dos artistas 
 */
char** RetornaNomeDosArtistasDaM(tMusica *msc);

/**
 * @brief Executa a musica(tMusica*) pelo terminal
 * 
 * @param msc: tMusica* que sera executado 
 */
void ExecutarMusica(tMusica* msc);

/**
 * @brief Imprime informacoes da musica no arquivo
 * 
 * @param msc: tMusica* que sera impressa no arquivo
 * @param f: FILE * que representa o aquivo, o arquivo deve esta aberto em modo escrita "w" 
 */
void ImprimirMusicaArquivo(tMusica *msc, FILE * f);

/**
 * @brief Retorna a quantidade de playlist que a musica esta inserida
 * 
 * @param msc: tMusica* que sera retornada a quantidade de playlista que esta 
 * @return int a quantidade da musica 
 */
int RetQtdPlayMusica(tMusica* msc);

/**
 * @brief Retorna o tPropiedades* que a tMusica* tem
 * 
 * @param msc: tMusicas* que a propriedade sera retornada 
 * @return tPropiedades* 
 */
tPropiedades* RetornaPropriedadesMusica(tMusica* msc);

#endif