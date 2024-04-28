app:fonction.o main.o
	gcc minimap.o main.o -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -o app
main.o:main.c
	gcc -c main.c
fonction.o:minimap.c
	gcc -c minimap.c
