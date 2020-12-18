CC = gcc 
EXEC = main
SRC = main.c fichier_SDL.c initData.c collision.c
OBJ = $(SRC:.c=.o)
CFLAGS = -W -Wall -ansi -std=c99 -g
LDFLAGS = `sdl2-config --cflags --libs` -lSDL2_ttf -lSDL2_image -lm
INCLUDES = -I./SDL2_ttf -I./SDL2_image

all: $(EXEC)
main: $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o 	$@ $^ $(LDFLAGS)
%.o: %.c 
	$(CC) $(CFLAGS) -o $@ -c $<
clean:
	rm -rf *.o *~
mrproper:
	rm -rf $(EXEC)
