#include "musicas.h"

#define TAM_INICIAL_VET 132

struct tMusicas{
    tMusica* *musicas;
    int qtdM;
    int tamVet;
};

tMusicas* InicializaVetorMusicas() {
    tMusicas* v = (tMusicas*)malloc(sizeof(*v));
    v->tamVet = TAM_INICIAL_VET;
    v->musicas = (tMusica**)malloc(sizeof(tMusica*)*v->tamVet);
    v->qtdM = 0;

    return v;
}

tMusicas* LeMusicasDoArquivo(char* caminho, tArtistas *arts) {
    tMusicas* v = InicializaVetorMusicas();
    tMusica* musica = NULL;

    FILE * f = NULL;

    f = fopen(caminho, "r");

    if(f == NULL){
        printf("LeMusicasDoArquivo: Erro ao abrir arquivo: %s\n\n", caminho);
        exit(1);
    }

    printf("Operacao: Leitura de Musicas e Conexao Musica/Artista Iniciada!\n");

    while(!feof(f)) {
        musica = LeMusicaDoArquivo(f);

        if(musica != NULL){
            AdicionarArtistasDaMusica(musica,arts);
            AdicionaMusicaAoVetMusicas(v, musica);
        } 

    }
      
    fclose(f);

    printf("Operacao: Leitura de Musicas e Conexao Musica/Artista Finalizada!\n\n");
 
    return v;
}

void AdicionaMusicaAoVetMusicas(tMusicas *v, tMusica* m) {
    if(v->qtdM >= v->tamVet) {
        v->tamVet = v->tamVet*2;
        v->musicas = realloc(v->musicas, sizeof(*v->musicas)*v->tamVet);
    }

    v->musicas[v->qtdM] = m;
    v->qtdM++;
}

void LiberaVetorMusicas(tMusicas **vet){
    int i = 0;

    if(*vet != NULL){
        for(i = 0; i < (*vet)->qtdM; i++) {
            LiberaMusica(&(*vet)->musicas[i]);
        }
        
        free((*vet)->musicas);
        (*vet)->musicas = NULL;

        free(*vet);
        *vet = NULL;
    }
}

void ListarMusicaPeloIndice(tMusicas *mscs, int idx){
    if(idx >= mscs->qtdM || idx < 0) {
        printf("\nO indice %d nao corresponde a nenhuma musica!\n\n", idx);
        return;
    }
    ImprimirMusica(mscs->musicas[idx]);
}

tMusica* RetMusicaPeloIdx(tMusicas *mscs, int idx) {
    if(idx >= mscs->qtdM || idx < 0){
        printf("O indice %d nao corresponde a nenhuma musica!\n\n", idx);
        return NULL;
    }
    return mscs->musicas[idx];
}

void BuscarMusicasPeloNome(tMusicas *mscs, char *busca){
    int eMusica = 0;
    for(int i = 0; i < mscs->qtdM; i++){
        if(strcmp(busca, RetornaNomeMusic(mscs->musicas[i])) == 0){
            eMusica++;
            printf("Indice da musica: %d\n", i);
            printf("Id da musica: %s\n", RetornaIdMusica(mscs->musicas[i]));
            printf("Titulo da musica: %s\n", RetornaNomeMusic(mscs->musicas[i]));
            printf("Nomes dos Artistas:\n");
            
            char** Arts = RetornaNomeDosArtistasDaM(mscs->musicas[i]);
            for(int j = 1; j <= RetQtdArtsM(mscs->musicas[i]); j++){
                printf("%s ", Arts[j-1]);

                if(!(j%3)){
                    printf("\n");
                }
                else if(j != RetQtdArtsM(mscs->musicas[i])){
                    printf("| ");
                }
            }

            printf("\n\n");

        }
    }

    if(!eMusica){
        printf("Nenhuma musica foi encontrada!\n\n");
    }
}

void ExecutaMusicaPeloIdx(tMusicas* mscs, int idx) {
    if(idx >= mscs->qtdM || idx < 0){
        printf("\nO indice %d nao corresponde a nenhuma musica!\n\n", idx);
        return;
    }

    ExecutarMusica(mscs->musicas[idx]);
}

void GeraRelatorioMusicas(tMusicas* mscs, char* caminho) {
    int i = 0, flag = 0;
    char path[1000];
    strcpy(path, caminho);
    strcat(path, "relatorioMusicas.txt");
    FILE * f = fopen(path, "w");

    if(f == NULL) {
        printf("Erro ao abrir caminho para relatorio de musicas: %s\n\n", path);
        return;
    }
    //rMp eh a relacao musica e a quatidade de playlist que a musica foi adicionada
    tPeso** rMp = (tPeso**)calloc(mscs->qtdM, sizeof(tPeso*));

    for(i = 0; i < mscs->qtdM; i++) {
        rMp[i] = CriaPeso(i, RetQtdPlayMusica(mscs->musicas[i]));
    }

    OrdenaPeloPesoDecrescente(rMp, mscs->qtdM);

    for(i = 0; i < mscs->qtdM; i++) {
        if(RetornaPeso(rMp[i]) > 0.0) {
            fprintf(f, "%d- ", i + 1);
            ImprimirMusicaArquivo(mscs->musicas[RetornaItem(rMp[i])], f);
            flag++;
        }
        else if(RetornaPeso(rMp[i]) == 0.0) {
            //Caso encontre uma musica que nao esta em playlist pode parar, pois 
            //as proximas tambem nao estarao
            break;
        }
    }

    if(!flag){
        fprintf(f, "Nenhuma musica esta em playlist!");
    }

    for(i = 0; i < mscs->qtdM; i++) {
        LiberaPeso(&rMp[i]);
    }

    free(rMp);
    rMp = NULL;

    fclose(f);
}

int RetQtdMusicasNaLista(tMusicas* mscs) {
    return mscs->qtdM;
}