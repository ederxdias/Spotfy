
#include "artista.h"
#include "artistas.h"


struct tArtistas
{
    tArtista *artista;
    int qtda;
};

tArtistas IniciarArtistas(int tam){
    tArtistas *artistas = malloc(sizeof(artistas));
    if(artistas == NULL){
        printf("Ponteiro Artistas NULL");
        exit(-1)
    }
    artistas->artista = malloc(sizeof(tArtista *)*tam);
    artistas->qtda =0;
}

