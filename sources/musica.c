#include "musica.h"

#define LINHAS_MAX 32
#define QTD_CHARS_MAX 2000

struct tMusica
{
    char *id;
    char *nM; //Nome da musica
    int popu;
    int dura_ms;
    int eh_explic;
    tArtistas* artistas; //Vetor dos artistas que cantam a musica
    int qtdA; //Quantidade de artistas que produziram a musica
    char **idA; //Id dos artistas que cantam a musica
    char **nA; //Nome dos artistas que cantam a musica
    tData_pt dataL; //Data de lancamento
    tPropiedades* prop; //Propriedades da musica
    int qtdPlay; //Quantidade de playlist que pertence
};

tMusica *CriaMusica(char* id, char* nM, int popu, int duracao, int exp, tArtistas* art, int qtdA, char** nA, char **idA, 
                    tData_pt dataL, tPropiedades* p,  int qtdPlay) {
    
    tMusica *m = (tMusica*)malloc(sizeof(*m));
    int i = 0;

    m->id = (char*)malloc(sizeof(char)*(strlen(id) + 1));
    strncpy(m->id, id, strlen(id));

    m->nM = (char*)malloc(sizeof(char)*(strlen(nM) + 1));
    strncpy(m->nM, nM, strlen(nM));

    m->popu = popu;

    m->dura_ms = duracao;

    m->eh_explic = exp;

    m->artistas = art;

    m->qtdA = qtdA;

    //Alocando o vetor com o nome dos artistas
    m->nA = (char**)malloc(sizeof(char*)*qtdA);
    for(i = 0; i < qtdA; i++){
        m->nA[i] = (char*)malloc(sizeof(char)*(strlen(nA[i]) + 1));
        strncpy(m->nA[i], idA[i], strlen(nA[i]));
    }

    //Alocando o vetor com os ids dos artistas
    m->idA = (char**)malloc(sizeof(char*)*qtdA);
    for(i = 0; i < qtdA; i++){
        m->idA[i] = (char*)malloc(sizeof(char)*(strlen(idA[i]) + 1));
        strncpy(m->idA[i], idA[i], strlen(idA[i]));
    }

    m->dataL = dataL;

    m->prop = p;

    m->qtdPlay = qtdPlay;

    return m;
}

void LiberaMusica(tMusica *m) {
    int i = 0;

    free(m->id);

    free(m->nM);

    for(i = 0; i < m->qtdA; i++) {
        free(m->nA[i]);
        free(m->idA[i]);
    }

    free(m->nA);
    free(m->idA);

    LiberaPropiedades(&m->prop);

    LiberaData(m->dataL);

    free(m);
}

tMusica* LeMusicaDoArquivo(FILE * f) {
    if(f == NULL){
        printf("Erro o arquivo passado deve estar aberto em modo leitura!\n");
        exit(1);
    }

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

    if(fscanf(f, "%[^;];%[^;];%d;%d;%d;", id, nM, &popu, &duracao, &exp) == 5){
        i = 0;
        nA = CriaUmaMatrizDeChar(LINHAS_MAX, QTD_CHARS_MAX);
        
        //Lendo separadamente os nomes dos artistas
        while(fscanf(f, "%[^|;]%c", nA[i], &test) == 2 && test != ';'){
            i++;
        }

        i = 0;
        idA = CriaUmaMatrizDeChar(LINHAS_MAX, QTD_CHARS_MAX);
        
        //Lendo separadamente os ids dos artistas
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

        LiberaMatrizDeChar(nA, LINHAS_MAX, QTD_CHARS_MAX);
        LiberaMatrizDeChar(idA, LINHAS_MAX, QTD_CHARS_MAX);

        return musica;
    }

    return NULL;
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