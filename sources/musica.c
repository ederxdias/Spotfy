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
    int qtdPlay; //Quantidade de playlist que musica pertence
    tArtista* *arts_msc;// Array dos artistas que produziram a musica
};

tMusica *CriaMusica(char* id, char* nM, int popu, int duracao, int exp, int qtdA, char** nA, char **idA, 
                    char *dataL, tPropiedades* p,  int qtdPlay) {
    
    tMusica *m = (tMusica*)calloc(1, (sizeof(*m)));
    int i = 0;

    m->id = (char*)calloc((strlen(id) + 1), sizeof(char));
    strncpy(m->id, id, strlen(id));

    m->nM = (char*)calloc((strlen(nM) + 1), sizeof(char));
    strncpy(m->nM, nM, strlen(nM));

    m->popu = popu;

    m->dura_ms = duracao;

    m->eh_explic = exp;

    m->qtdA = qtdA;

    //Alocando o vetor com o nome dos artistas
    m->nA = (char**)malloc(sizeof(char*)*qtdA);
    for(i = 0; i < qtdA; i++){
        m->nA[i] = (char*)calloc((strlen(nA[i]) + 1), sizeof(char));
        strncpy(m->nA[i], nA[i], strlen(nA[i]));
    }

    //Alocando o vetor com os ids dos artistas
    m->idA = (char**)malloc(sizeof(char*)*qtdA);
    for(i = 0; i < qtdA; i++){
        m->idA[i] = (char*)calloc((strlen(idA[i]) + 1), sizeof(char));
        strncpy(m->idA[i], idA[i], strlen(idA[i]));
    }
    //Alocando a struct de vetor dos artistas;
    m->arts_msc = (tArtista**)calloc(m->qtdA, sizeof(tArtista*));

    m->dataL = (char*)calloc((strlen(dataL)+1), sizeof(char));
    strncpy(m->dataL, dataL, strlen(dataL));

    m->prop = p;

    m->qtdPlay = qtdPlay;

    return m;
}

void LiberaMusica(tMusica **m) {
    int i = 0;

    if(*m != NULL){
        free((*m)->id);
        (*m)->id = NULL;

        free((*m)->nM);
        (*m)->nM = NULL;

        for(i = 0; i < (*m)->qtdA; i++) {
            free((*m)->nA[i]);
            (*m)->nA[i] = NULL;
            free((*m)->idA[i]);
            (*m)->idA[i] = NULL;
        }

        free((*m)->arts_msc);
        (*m)->arts_msc = NULL;
        
        free((*m)->nA);
        (*m)->nA =NULL;
        
        free((*m)->idA);
        (*m)->idA = NULL;
        
        free((*m)->dataL);
        (*m)->dataL = NULL;
        
        LiberaPropiedades(&(*m)->prop);

        free(*m);
        *m = NULL;
    }
}

tMusica* LeMusicaDoArquivo(FILE * f) {
    if(f == NULL){
        printf("LeMusicadoArquivo: Erro o arquivo passado deve estar aberto em modo leitura!\n");
        exit(EXIT_FAILURE);
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
            fscanf(f, "%*[^\n]\n\r");
            return NULL;
        }

        //Lendo propriedades da musica
        if(fscanf(f, "%lf;%lf;%d;%lf;%d;%lf;%lf;%lf;%lf;%lf;%lf;%d\n\r", &danceability, &energy, &key,&loudness, &mode, &speechiness, 
           &acousticness, &instrumentalness, &liveness, &valence, &tempo, &time_signature) != 12){
            fscanf(f, "%*[^\n]\n\r");
            LiberaMatrizDeChar(nA, LINHAS_MAX, QTD_CHARS_MAX);
            LiberaMatrizDeChar(idA, LINHAS_MAX, QTD_CHARS_MAX);
            
            return NULL;
        }

        p = CriaPropriedades(danceability, energy, speechiness, acousticness, instrumentalness, key, 
                             liveness, valence, loudness, tempo, time_signature, mode);

        musica = CriaMusica(id, nM, popu, duracao, exp, qtdArt, nA, idA, data, p, 0);

        LiberaMatrizDeChar(nA, LINHAS_MAX, QTD_CHARS_MAX);
        LiberaMatrizDeChar(idA, LINHAS_MAX, QTD_CHARS_MAX);

        return musica;
    }
    fscanf(f, "%*[^\n]\n\r");

    return NULL;
}

char** CriaUmaMatrizDeChar(int qtdLinha, int qtdChars){
    int i = 0;
    char **m = NULL;

    m = (char**)malloc(sizeof(char*)*qtdLinha);

    for(i = 0; i < qtdLinha; i++) {
        m[i] = (char*)malloc(sizeof(char)*qtdChars);
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
// Prencher A estruct Musica com as structs dos artistas que produziram a musica
void AdicionarArtistasDaMusica(tMusica *msc, tArtistas *arts){
    int i = 0, idx = 0;

    for(i = 0; i < msc->qtdA; i++){
        idx = AcharIndexArtPeloIdB(arts,msc->idA[i]);
        // Há casos em que o indice do artista procurado não existe;
        if(idx == NOT_FOUND){
            msc->arts_msc[i] = NULL;
        }
        else{
            msc->arts_msc[i] = RetornaArtistaPonteiro(arts, idx);
        }
    }
}
// Retorna o Id da Musica
char *RetornaIdMusica(tMusica *msc) {
    return msc->id;
}
// Retorna o Quantidade de Artistas da musica
int RetQtdArtsM(tMusica *msc) {
    return msc->qtdA;
}

void ConfiguraMusicaNaPlaylist(tMusica *msc) {
    int i = 0;

    for(i = 0; i < msc->qtdA; i++){
        if(msc->arts_msc[i] != NULL){
            IncrementaQtdPlaylistArtista(msc->arts_msc[i]);
        }
    }
    msc->qtdPlay++;
}

void ImprimirMusica(tMusica *msc){
    int i = 0;
    printf("Informações da Música: \n");
    printf("Nome: %s  ", msc->nM);
    printf(" Id: %s\n", msc->id);
    printf("Data de Lançamento: %s  ", msc->dataL);
    printf("\tPopularity: %d\n", msc->popu);
    printf("\nMais Informações Sobre a Música: \n");
    printf("Duracao em ms: %d |", msc->dura_ms);
    printf(" Explicit: %d  | ", msc->eh_explic);
    ImprimirPropiedades(msc->prop);
    printf("\nArtistas que Produziram a Música:\n");
    for(i = 0; i < msc->qtdA;i++){
        printf("Artista %d:\n", i + 1);
        printf("Nome: %s | ", msc->nA[i]);
        printf("Id: %s \n", msc->idA[i]);

        printf("\nMais informações sobre o artista:\n");
        if(msc->arts_msc[i] != NULL){
            ImprimirArtista(msc->arts_msc[i]);
        }else{
            printf("Mais informações não foram encontradas sobre esse artista.");
        }
        printf("\n\n");
    }
}
// Retorna o nome da Musica
char *RetornaNomeMusic(tMusica *msc){
    return msc->nM;
}

//Imprimir Os nomes dos Artistas
char** RetornaNomeDosArtistasDaM(tMusica *msc){
    return msc->nA;
}

void ExecutarMusica(tMusica* msc) {
    char search[128] = "firefox https://open.spotify.com/track/";

    strcat(search, RetornaIdMusica(msc));

    system(search);
}

void ImprimirMusicaArquivo(tMusica *msc, FILE * f){
    int i = 0;

    if(f == NULL) {
        printf("ImprimeMusicaArquivo: arquivo deve ser passado aberto em modo escrita!\n");
        exit(1);
    }
    
    fprintf(f, "Nome: %s|", msc->nM);
    fprintf(f, "Id: %s|", msc->id);
    fprintf(f, "Data de Lançamento: %s|", msc->dataL);
    fprintf(f, "Popularity: %d", msc->popu);
    for(i = 0; i < msc->qtdA;i++){
        fprintf(f, "|NomeArtista%d: %s|", i + 1, msc->nA[i]);
        fprintf(f, "IdArtista%d: %s", i + 1, msc->idA[i]);
    }
    fprintf(f, "\n");
}

int RetQtdPlayMusica(tMusica* msc) {
    return msc->qtdPlay;
}

tPropiedades* RetornaPropriedadesMusica(tMusica* msc) {
    return msc->prop;
}