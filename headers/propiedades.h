#ifndef PROPIEDADES_H
#define PROPIEDADES_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct tPropiedades tPropiedades;

/**
 * @brief Cria um tPropiedades* alocado dinamicamente 
 * 
 * @param dance: double -> danceability
 * @param energy: double -> energy 
 * @param speech: double -> speechiness 
 * @param acous: double -> acousticness 
 * @param inst: double -> instrumentalness 
 * @param key: int -> key 
 * @param live: double -> liveness
 * @param vale: double -> valence 
 * @param loud: double -> loudness 
 * @param temp: double -> tempo 
 * @param time_s: int -> time_signature
 * @param mode: int -> mode 
 * @return tPropiedades* 
 */
tPropiedades* CriaPropriedades(double dance, double energy, double speech, double acous, double inst, int key,
                               double live, double vale, double loud, double temp, int time_s, int mode);

/**
 * @brief Libera o tPropiedades*
 * 
 * @param p: tPropiedades** que representa o caminho para o tPropiedades* 
 */
void LiberaPropiedades(tPropiedades** p);

/**
 * @brief Imprime as informações do tPropiedades* no terminal
 * 
 * @param p: tPropiedades* 
 */
void ImprimirPropiedades(tPropiedades *p);

/**
 * @brief Retorna a danceability
 * 
 * @param p: tPropiedades* 
 * @return double 
 */
double RetornaDanceProp(tPropiedades* p);

/**
 * @brief Retorna a energy
 * 
 * @param p: tPropiedades* 
 * @return double 
 */
double RetornaEnergProp(tPropiedades* p);

/**
 * @brief Retorna o mode 
 * 
 * @param p: tPropiedades* 
 * @return int 
 */
int RetornaModeProp(tPropiedades* p);

/**
 * @brief Retorna o speechiness
 * 
 * @param p: tPropiedades*
 * @return double 
 */
double RetornaSpeechProp(tPropiedades* p);

/**
 * @brief Retorna o acousticness
 * 
 * @param p: tPropiedades* 
 * @return double 
 */
double RetornaAcoustProp(tPropiedades* p);

/**
 * @brief Retorna a instrumentalness
 * 
 * @param p: tPropiedades*  
 * @return double 
 */
double RetornaInstruProp(tPropiedades* p);

/**
 * @brief Retorna a liveness
 * 
 * @param p: tPropiedades* 
 * @return double 
 */
double RetornaLivenessProp(tPropiedades* p);

/**
 * @brief Retorna a valence
 * 
 * @param p: tPropiedades* 
 * @return double 
 */
double RetornaValencProp(tPropiedades* p);

/**
 * @brief Retorna a distancia entre duas propriedades*
 * 
 * @param p1: tPropiedades* 
 * @param p2: tPropiedades* 
 * @return double 
 */
double DistanciaEntrePropriedades(tPropiedades* p1, tPropiedades* p2);

#endif