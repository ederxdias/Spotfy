#ifndef _TDATA_H_
#define _TDATA_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct tData tData;
typedef tData *tData_pt;

tData_pt CriaData(int dia, int mes, int ano);

tData_pt AvancaDias(tData_pt data, int dias);

tData_pt AvancaUmDia(tData_pt data);

int EhData1IgualData2(tData_pt data1, tData_pt data2);

void LiberaData(tData_pt data);

//Funcao para imprimir a data no terminal
void ImprimeDataT(tData_pt data);

/* Funcao para imprimir a data no arquivo que o caminho indica,
 * a data e escrita entre espacos continuando o que ja tinha no arquivo.
*/
void ImprimeDataF(tData_pt data, char * caminho);

int QtdDiasNoMes(tData_pt data);

int EhBissexto(tData_pt data);

#endif
