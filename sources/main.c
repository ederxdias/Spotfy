#include <stdio.h>
#include "artistas.h"

int main(int argc, char *argv[]) {

    FILE * test = fopen("./data_tests/artists_2.csv","r");
    if (test == NULL)
  {
    printf("Erro abertura do arquivo!!");
    exit(EXIT_FAILURE);
  }
    tArtistas *arts = CriarArtistas();
    while(1){
        tArtista *art = LeArtista(test);
        if(art == NULL)
            break;
        AdicionarArtistas(arts, art);
    }

    return 0;
}