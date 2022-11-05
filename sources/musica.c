#include "musica.h"

#define LINHAS_MAX 128
#define QTD_CHARS_MAX 512

struct tMusica
{
    char *id;
    char *nM; //Nome da musica
    int popu;
    int dura_ms;
    int eh_explic;
    int qtdA; //Quantidade de artistas que produziram a musica
    char **idA; //Id dos artistas que cantam a musica
    char **nA; //Nome dos artistas que cantam a musica
    char *dataL; //Data de lancamento
    tPropiedades* prop; //Propriedades da musica
    int qtdPlay; //Quantidade de playlist que pertence
    tArtistas *arts_msc;// Array dos artistas que produziram a musica
};

tMusica *CriaMusica(char* id, char* nM, int popu, int duracao, int exp, int qtdA, char** nA, char **idA, 
                    char *dataL, tPropiedades* p,  int qtdPlay) {
    
    tMusica *m = (tMusica*)malloc(sizeof(*m));
    int i = 0;

    m->id = (char*)malloc(sizeof(char)*(strlen(id) + 1));
    strncpy(m->id, id, strlen(id));

    m->nM = (char*)malloc(sizeof(char)*(strlen(nM) + 1));
    strncpy(m->nM, nM, strlen(nM));

    m->popu = popu;

    m->dura_ms = duracao;

    m->eh_explic = exp;

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
    //Alocando a struct de vetor dos artistas;
    m->arts_msc = (tArtistas *) malloc(sizeof(tArtistas *));

    m->dataL = (char*)malloc(sizeof(char)*strlen(dataL)+1);
    strncpy(m->dataL, dataL, strlen(dataL));

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
    LiberarVetorArts(m->arts_msc);
    free(m->arts_msc);
    free(m->nA);
    free(m->idA);
    free(m->dataL);
    LiberaPropiedades(m->prop);

    free(m);
}

tMusica* LeMusicaDoArquivo(FILE * f) {
    if(f == NULL){
        printf("Erro o arquivo passado deve estar aberto em modo leitura!\n");
        exit(1);
    }

    char id[100], nM[10000], **nA, **idA, data[20];
    char test = 'F';
    int popu, exp, duracao;
    int time_signature, mode, key, i = 0, qtdArt = 0;
    double danceability, energy, speechiness, acousticness;
    double instrumentalness, liveness, valence, loudness, tempo;
    tPropiedades* p;
    tMusica* musica = NULL;

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
        if(fscanf(f, "%[^;];", data) != 1){
            printf("Erro de leitura da data da musica!\n");
            exit(1);
        }

        //Lendo propriedades da musica
        if(fscanf(f, "%lf;%lf;%d;%lf;%d;%lf;%lf;%lf;%lf;%lf;%lf;%d", &danceability, &energy, &key,&loudness, &mode, &speechiness, 
           &acousticness, &instrumentalness, &liveness, &valence, &tempo, &time_signature) != 12){
            printf("Erro de leitura das propriedades da musica!\n");
            exit(1);
        }

        p = CriaPropriedades(danceability, energy, speechiness, acousticness, instrumentalness, key, 
                             liveness, valence, loudness, tempo, time_signature, mode);

        musica = CriaMusica(id, nM, popu, duracao, exp, qtdArt, nA, idA, data, p, 0);

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

void AdicionarArtistasDaMusica(tMusica *msc, tArtistas *arts){
    msc->arts_msc = CriarArtistas();
    // Deixa o vetor de artistas dentro da musica do tamanho do numero de artistas
     AdicionarQtdArt(msc->arts_msc,msc->qtdA);
    int idx;
    static int cont =0;
    for(int i=0; i<msc->qtdA; i++){
        idx = AcharIndexArt(arts,msc->idA[i]);
        MudarArtista(msc->arts_msc,RetornarStructArt(arts,idx),i);
        // ImprimirArtista1(msc->arts_msc, i);
    }
    cont++;
    // printf("\n#%d#\n",cont);
}
