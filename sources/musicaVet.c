#include "musicaVet.h"

#define LINHAS_MAX 32
#define QTD_CHARS_MAX 2000
#define TAM_INICIAL_VET 132

struct tMusicaVet{
    tMusica* *musicas;
    int qtdM;
    int tamVet;
};

tMusicaVet* InicializaVetorMusicas() {
    tMusicaVet* v = (tMusicaVet*)malloc(sizeof(*v));
    v->tamVet = TAM_INICIAL_VET;
    v->musicas = (tMusica**)malloc(sizeof(tMusica*)*v->tamVet);
    v->qtdM = 0;

    return v;
}

tMusicaVet* LeMusicasDoArquivo(char* caminho) {
   tMusicaVet* v = InicializaVetorMusicas();

    char id[100], nM[10000], **nA, **idA;
    char test = 'F';
    int popu, exp, dia, mes, ano, duracao;
    int time_signature, mode, key, i = 0, qtdArt = 0;
    double danceability, energy, speechiness, acousticness;
    double instrumentalness, liveness, valence, loudness, tempo;
    tPropiedades* p;
    tData_pt data;
    tMusica* musica = NULL;
    tArtistas* a = NULL;

    FILE * f = NULL;

    f = fopen(caminho, "r");

    if(f == NULL){
        printf("Erro ao abrir arquivo: %s\n", caminho);
        exit(1);
    }

    while(fscanf(f, "%[^;];%[^;];%d;%d;%d;", id, nM, &popu, &duracao, &exp) == 5) {
        i = 0;
        nA = CriaUmaMatrizDeChar(LINHAS_MAX, QTD_CHARS_MAX);
        while(fscanf(f, "%[^|;]%c", nA[i], &test) == 2 && test != ';'){
            i++;
        }

        i = 0;
        idA = CriaUmaMatrizDeChar(LINHAS_MAX, QTD_CHARS_MAX);
        while(fscanf(f, "%[^|;]%c", idA[i], &test) == 2 && test != ';'){
            i++;
        }
        qtdArt = i+1;
        //Lendo data da musica
        if(fscanf(f, "%d-%d-%d;", &ano, &mes, &dia) != 3){
            printf("Erro de leitura da data da musica!\n");
            exit(1);
        }
        //Lendo propriedades da musica
        if(fscanf(f, "%lf;%lf;%d;%lf;%d;%lf;%lf;%lf;%lf;%lf;%lf;%d", &danceability, &energy, &key,&loudness, &mode, &speechiness, 
           &acousticness, &instrumentalness, &liveness, &valence, &tempo, &time_signature) != 12){
            printf("Erro de leitura das propriedades da musica!\n");
            exit(1);
        }
        
        data = CriaData(dia, mes, ano);
        p = CriaPropriedades(danceability, energy, speechiness, acousticness, instrumentalness, key, 
                             liveness, valence, loudness, tempo, time_signature, mode);

        musica = CriaMusica(id, nM, popu, duracao, exp, a, qtdArt, nA, idA, data, p, 0);

        AdicionaMusicaAoVetMusicas(v, musica);

        LiberaMatrizDeChar(nA, LINHAS_MAX, QTD_CHARS_MAX);
        LiberaMatrizDeChar(idA, LINHAS_MAX, QTD_CHARS_MAX);
    }

    fclose(f);

    return v;
}

void AdicionaMusicaAoVetMusicas(tMusicaVet *v, tMusica* m) {
    if(v->qtdM >= v->tamVet) {
        v->tamVet = v->tamVet*2;
        v->musicas = realloc(v->musicas, sizeof(*v->musicas)*v->tamVet);
    }

    v->musicas[v->qtdM] = m;
    v->qtdM++;
}

char** CriaUmaMatrizDeChar(int qtdLinha, int qtdChars){
    int i = 0;
    char **m = NULL;

    m = (char**)malloc(sizeof(char*)*qtdLinha);

    for(i = 0; i < qtdLinha; i++) {
        m[i] = (char*)malloc(sizeof(char*)*qtdChars);
    }

    return m;
}

void LiberaMatrizDeChar(char **m, int qtdLinha, int qtdChars) {
    int i = 0;

    for(i = 0; i < qtdLinha; i++) {
        free(m[i]);
    }

    free(m);
}

void LiberaVetorMusicas(tMusicaVet *vet){
    int i = 0;

    for(i = 0; i < vet->qtdM; i++) {
        LiberaMusica(vet->musicas[i]);
    }
    free(vet->musicas);

    free(vet);
}