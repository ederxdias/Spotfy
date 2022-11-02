#include "musicas.h"

struct tMusicas
{
    tMusica **msc;
    int qtd;
    int tamVet;
};

tMusicas *CriarMusicas(){
    tMusicas *mscs = (tMusicas *)malloc(sizeof(*mscs));
    if(mscs == NULL){
        printf("Falha na alocação do ponteiro musicas");
        exit(-1);
    }
    mscs->qtd = 0;
    mscs->tamVet = 4;
    mscs->msc = (tMusica *)malloc(sizeof(tMusica **)*mscs->tamVet); 
    return mscs
}
