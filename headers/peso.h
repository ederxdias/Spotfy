#ifndef _PESO_H_
#define _PESO_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct tPeso tPeso;

/**
 * @brief Cria um tPeso* alocado dinamicamente 
 * 
 * @param item: um int que representa o item 
 * @param peso: um double que representa o peso do item 
 * @return tPeso* 
 */
tPeso* CriaPeso(int item, double peso);

/**
 * @brief Libera o tPeso*
 * 
 * @param p: tPeso** que representa o caminho para o tPeso* a ser liberado 
 */
void LiberaPeso(tPeso* *p);

/**
 * @brief Retorna o item referente ao tPeso*
 * 
 * @param p: tPeso* 
 * @return int o item do tPeso*
 */
int RetornaItem(tPeso* p);

/**
 * @brief Retorna o peso do tPeso*
 * 
 * @param p: tPeso* 
 * @return double o peso do tPeso*
 */
double RetornaPeso(tPeso* p);

/**
 * @brief Ordena um vetor de tPeso* em ordem decrescente 
 * 
 * @param p: tPeso** que representa o vetor de tPeso* 
 * @param tam: int que representa o tamanho do vetor de tPeso** 
 */
void OrdenaPeloPesoDecrescente(tPeso** p, int tam);

/**
 * @brief Ordena um vetor de tPeso* em ordem crescente 
 * 
 * @param p: tPeso** que representa o vetor de tPeso* 
 * @param tam: int que representa o tamanho do vetor de tPeso** 
 */
void OrdenaPeloPesoCrescente(tPeso** p, int tam);

#endif