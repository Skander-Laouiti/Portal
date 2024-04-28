#ifndef minimap_H
#define minimap_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>

typedef struct tic
{
SDL_Surface* XO_Img;
SDL_Rect xoR[4][4];
SDL_Rect posxo[3];
int tab[4][4];
int tour;
int winner;
TTF_Font *Police;
SDL_Color Text_Color;
char Text[50];
SDL_Rect Pos_Text;
SDL_Surface *txt;
}tic;


void initialiser_tic(tic *t);
int Resultat(tic *t);
void Put_Xo(tic *t,int x,int y);
void Random_Xo(tic *t);
void Afficher(tic *t,SDL_Surface* screen);
void liberer(tic *t);


#endif
