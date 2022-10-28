#include "tData.h"

struct tData{
    int dia;
    int mes;
    int ano;
};

static tData_pt TruncaData(tData_pt data);

tData_pt CriaData(int dia, int mes, int ano){
    tData_pt d = (tData_pt)malloc(sizeof(tData));
    
    d->dia = dia;
    d->mes = mes;
    d->ano = ano;

    d = TruncaData(d);

    return d;
}

void LiberaData(tData_pt data) {
    if(data != NULL) {
        free(data);
        data = NULL;
    }
}

tData_pt AvancaDias(tData_pt data, int dias){
    while(dias--) data = AvancaUmDia(data);

    return data;
}

int EhData1IgualData2(tData_pt data1, tData_pt data2){
    if(data1->dia == data2->dia){
        if(data1->mes == data2->mes){
            if(data1->ano == data2->ano) return 1;
        }
    }

    return 0;
}

void ImprimeDataT(tData_pt data){
    printf("%02d/%02d/%04d", data->dia, data->mes, data->ano);
}

void ImprimeDataF(tData_pt data, char * caminho) {
    FILE * f = NULL;
    f = fopen(caminho, "a");
    
    if(f == NULL) {
        printf("ARQUIVO NAO ENCONTRADO!\n");
    }

    fprintf(f, " %02d/%02d/%04d ", data->dia, data->mes, data->ano);

    fclose(f);
}

static tData_pt TruncaData(tData_pt data){
    int qtdDM;
    
    if(data->mes < 1) data->mes = 1;
    else if(data->mes > 12) data->mes = 12;

    qtdDM = QtdDiasNoMes(data);
    
    if(data->dia < 1) data->dia = 1;
    else if(data->dia > qtdDM) data->dia = qtdDM;

    return data;
}

int QtdDiasNoMes(tData_pt data){
    if(data->mes == 2){
        if(EhBissexto(data)) return 29;
        else return 28;
    }
    else if(data->mes == 4 || data->mes == 6 || data->mes == 9 || data->mes == 11) return 30;
    else return 31;
}

int EhBissexto(tData_pt data){
    if(!(data->ano%400)) return 1;
    else if(!(data->ano%4) && data->ano%100) return 1;
    else return 0;
}

tData_pt AvancaUmDia(tData_pt data){
    int qtdDM;

    data->dia++;
    qtdDM = QtdDiasNoMes(data);

    if(data->dia > qtdDM){
        data->dia = 1;
        data->mes++;

        if(data->mes > 12){
            data->mes = 1;
            data->ano++;
        }
    }

    return data;
}