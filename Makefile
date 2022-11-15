#Compilador utilizado
CC = gcc

#Comandos de remocao/criacao de arquivos e pastas
RM = rm
RMDIR = rmdir
MKDIR = mkdir

#Nome do programa
PROG_NAME = main

#Nome da biblioteca a ser criada
LIB_NAME = spotify

#Pastas necesarias para o programa
SOURCE_FILE = sources
HEADER_FILE = headers
OBJS_FILE = objects
#Pasta que guarda os relatorios e o arquivo binario
DATA_SAVE = dataSave

#Flags de compilacao
FLAGS = -Wall -g -c

#Configurando as variaveis
LIB_NAME := $(addprefix lib, $(addsuffix .a, $(LIB_NAME)))

SOURCES_C := $(wildcard ./$(SOURCE_FILE)/*.c)

SOURCES_H := $(wildcard ./$(HEADER_FILE)/*.h)

OBJS := $(subst .c,.o,$(subst $(SOURCE_FILE),$(OBJS_FILE),$(SOURCES_C)))

#Inicio dos comandos make
all: ./$(OBJS_FILE) ./$(DATA_SAVE) $(LIB_NAME) COMANDOS

$(LIB_NAME): $(OBJS)
	@ar crs $@ $(OBJS)

./$(OBJS_FILE)/%.o: ./$(SOURCE_FILE)/%.c ./$(HEADER_FILE)/%.h
	@$(CC) $< -o $@ $(FLAGS) -I ./$(HEADER_FILE)/
	
./$(OBJS_FILE):
	@$(MKDIR) $(OBJS_FILE)
	
./$(DATA_SAVE):
	@$(MKDIR) $(DATA_SAVE)

COMANDOS: $(LIB_NAME)
	@echo "Comando de compilação: "
	@echo "  gcc -o main main.c -L. -lspotify -I ./headers/ -lm \n"
	@echo "Comando para a execução do programa: "
	@echo "  ./main caminhoArquivoArtistas caminhoArquivoMusicas \n"
	@echo "Mais informações:"
	@echo "  A pasta >$(DATA_SAVE)< é onde o programa armazena os arquivos de relatório e binário"
	@echo "  Use o comando >make clean< para apagar tudo o que foi feito"

clean:
	@$(RM) -f $(OBJS) $(PROG_NAME) $(LIB_NAME)
	@$(RMDIR) $(OBJS_FILE)
	@$(RM) -f ./$(DATA_SAVE)/relatorioArtistas.txt ./$(DATA_SAVE)/relatorioMusicas.txt ./$(DATA_SAVE)/playlists.bin
	@$(RMDIR) $(DATA_SAVE)
