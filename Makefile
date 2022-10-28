CC = gcc
RM = rm
RMDIR = rmdir
MKDIR = mkdir

PROG_NAME = main
SOURCE_FILE = sources
OBJS_FILE = objects

FLAGS = -Wall -g -c

LIBS = -lm

SOURCES_C := $(wildcard ./$(SOURCE_FILE)/*.c)

SOURCES_H := $(wildcard ./$(SOURCE_FILE)/*.h)

OBJS := $(subst .c,.o,$(subst $(SOURCE_FILE),$(OBJS_FILE),$(SOURCES_C)))

all: ./$(OBJS_FILE) $(PROG_NAME)

$(PROG_NAME): $(OBJS)
	@$(CC) -o $@ $(OBJS) $(LIBS)

./$(OBJS_FILE)/%.o: ./$(SOURCE_FILE)/%.c ./$(SOURCE_FILE)/%.h
	@$(CC) $< -o $@ $(FLAGS)

./$(OBJS_FILE)/main.o: ./$(SOURCE_FILE)/main.c $(SOURCES_H)
	@$(CC) $< -o $@ $(FLAGS)
	
./$(OBJS_FILE):
	@$(MKDIR) $(OBJS_FILE)

clean:
	@$(RM) -f $(OBJS) $(PROG_NAME)
	@$(RMDIR) $(OBJS_FILE)
