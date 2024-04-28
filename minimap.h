#ifndef minimap_H
#define minimao_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>

typedef struct 
{SDL_Surface *map;
SDL_Surface  *minijoueur;
SDL_Rect positionmap;
SDL_Rect positionminijoueur;
}minimap;


typedef struct temps
{
SDL_Surface *texte;
 SDL_Rect position;
  
    TTF_Font *police ;

 char entree[100]; 
 int secondesEcoulees; 
SDL_Color couleurBlanche;
time_t t1,t2; 
int min, sec;
}temps;


void init_map (minimap *m);
void init_map2 (minimap *m2);
void MAJMinimap(SDL_Rect posJoueur,  minimap * m, SDL_Rect camera, int redimensionnement);
void afficherminimap (minimap m, SDL_Surface * screen);
void afficherminimap2 (minimap m2, SDL_Surface * screen);
void initialiser_temps(temps *t);
void afficher_temps(temps *t, SDL_Surface *ecran);
void free_temps(temps *t,SDL_Surface *ecran);
void sauvegarder( int score, char nomjoueur[], char nomfichier[]);
void meilleur( char nomfichier[], int *score, char nomjoueur[]);

#endif
