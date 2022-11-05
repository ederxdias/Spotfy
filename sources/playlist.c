#include "playlist.h"

struct tPlaylist{
    int  *mscs;// vetor com indices das musicas
    int qtdM; // quantidade de musicas
    int tamVet; // tamanho do vetor musicas,ele é atualizado com realloc
    int tamNome; //Guarda o tamanho do nome da playlist incluindo o '\0'
    char *nome; // nome da playlist
};

tPlaylist *CriarPlaylist(char* nomePlay){
    tPlaylist *play = (tPlaylist *) malloc(sizeof(*play));

    if(play == NULL){
        printf("Alocação de ponteiro da playlist falhou");
        exit(-1);
    }
    play->tamNome = strlen(nomePlay) + 1;
    play->nome = (char*)calloc(play->tamNome, sizeof(char));
    strncpy(play->nome, nomePlay, strlen(nomePlay));
    play->qtdM =0;
    play->tamVet= 4;
    play->mscs = (int *) malloc(sizeof(int)*play->tamVet);

    return play;
}

void AdicionarMusicas(tPlaylist *play, int idx_msc){
    if(play->qtdM >= play->tamVet){
        play->tamVet= play->tamVet*2;
        play->mscs =(int *) realloc(play->mscs,sizeof(int)*play->tamVet);     
    }
    play->mscs[play->qtdM] = idx_msc;
    play->qtdM++;
}

void LiberarPlaylist(tPlaylist **p){
    if(*p != NULL) {
        free((*p)->mscs);
        (*p)->mscs = NULL;

        free((*p)->nome);
        (*p)->nome = NULL;
        
        free(*p);
        *p = NULL;
    }
}

void SalvarPlaylistEmBinario(tPlaylist *p, FILE * f){
    if(f == NULL) {
        printf("Arquivo deve estar aberdo em modo de escrita binario!\n");
        exit(1);
    }

    /*
     * Salvando cada parte da struct separadamente em um padrao, que na leitura seja 
     * possivel alocar espaco na memoria suficiente para a struct
    */
    fwrite(&p->tamVet, sizeof(p->tamVet), 1, f);
    fwrite(&p->qtdM, sizeof(p->qtdM), 1, f);
    fwrite(p->mscs, sizeof(*p->mscs), p->qtdM, f);
    fwrite(&p->tamNome, sizeof(p->tamNome), 1, f);
    fwrite(p->nome, sizeof(*p->nome), p->tamNome, f);
}

tPlaylist *CarregaPlaylistDeBinario(FILE * f){
    if(f == NULL) {
        printf("Arquivo deve estar aberdo em modo de leitura binario!\n");
        exit(1);
    }
    tPlaylist *p = (tPlaylist*)malloc(sizeof(*p));

    /* 
     * Lendo cada parte da struct de acordo com o padrao de salvamento e 
     * alocando espaco suficiente para seu armazenamento
    */
    fread(&p->tamVet, sizeof(p->tamVet), 1, f);
    p->mscs = (int*)malloc(sizeof(*p->mscs)*p->tamVet);

    fread(&p->qtdM, sizeof(p->qtdM), 1, f);
    fread(p->mscs, sizeof(*p->mscs), p->qtdM, f);
    
    fread(&p->tamNome, sizeof(p->tamNome), 1, f);
    p->nome= (char*)calloc(p->tamNome, sizeof(char));
    
    fread(p->nome, sizeof(*p->nome), p->tamNome, f);

    return p;
}