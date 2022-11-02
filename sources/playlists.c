#include "playlist.h"

struct tPlaylists
{
    tPlaylist **play;
    int tamVet;
    int qtdp;
};

tPlaylist *CriarListaPlay(){
    tPlaylists *list_play = (tPlaylists *) malloc(sizeof(*lista_play));
    if(list_play == NULL){
        printf("ALocação de ponteiro da lista de playlist falhou");
        exit(-1);
    
    }
    list_play->tamVet = 5;
    list_play ->qtdp = 0;
    list_play->play = (tPlaylist **)malloc(sizeof(tPlaylist **)*list_play->tamVet);
    return  list_play;
}

void AdicionarPlaylist(tPlaylists *plays, tPlaylist *play){
       plays->qtdp++;
    int qtdp = plays->qtdp;
    if(qtdp>plays->tamVet){
        plays->tamVet= plays->tamVet*2;
        plays->play = realloc(palys->play,sizeof(tPlaylist **)*plays->tamVet);     
    }
    AdicionarIdxP(play, qtdp-1);
    plays->play[qtdp-1] = play;
}

void LiberarPlaylistsStr(tPlaylists *p){
    if(p != NULL)
        free(p);
}
void LiberarPlaylistVet(tPlaylists *p){
    for(int i=0; i < p->qtdp; i++){
        free(p->play[i]);
    }
}

void salvarPlaylists(tPlaylist *p,FILE *fp)
{
    fp = fopen(ARQUIVO,"wb");

  if (fp == NULL){
      printf("Erro na abertura do arquivo\n");
      exit(1);
    }

    //grava todos os cadastros do array pontos
    fwrite(p, sizeof(*p), 1, fp);
    fclose(fp);
}

tPlaylists *CarregarPlaylists(FILE *fp)
{
    fp = fopen(ARQUIVO,"rb");

  if (fp == NULL){
      printf("Erro na abertura do arquivo\n");
      exit(1);
    }

   tPlaylists *p= malloc(sizeof *p);

   long t = fread(p, sizeof *p, 1, fp);

   return p;  
}

