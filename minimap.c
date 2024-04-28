#include "minimap.h"
#include <SDL/SDL.h>

void init_map (minimap *m)
{ m -> map = IMG_Load(" path to minimap picture ");
  m-> minijoueur = IMG_Load(" path to minimap player picture");
  m->positionmap.x =250;
  m->positionmap.y =25;
  m->positionminijoueur.x =250;
  m->positionminijoueur.y =21;
}

void init_map2 (minimap *m2)
{ 
  m2-> minijoueur = IMG_Load(" path to minimap player picture ");
  m2->positionminijoueur.x =255;
  m2->positionminijoueur.y =21;
}

void MAJMinimap(SDL_Rect posJoueur,  minimap * m, SDL_Rect camera, int redimensionnement)
{
  SDL_Rect posJoueurABS;
  posJoueurABS.x = 0;
  posJoueurABS.y = 0;
  posJoueurABS.x = posJoueur.x + camera.x;
  posJoueurABS.y = posJoueur.y + camera.y;
  m->positionminijoueur.x=(posJoueurABS.x * redimensionnement/100)+250;
  m->positionminijoueur.y=(posJoueurABS.y * redimensionnement/100)+21;
}

void afficherminimap (minimap m, SDL_Surface * screen)
{
  SDL_BlitSurface(m.map,NULL,screen,&m.positionmap);
  SDL_BlitSurface(m.minijoueur,NULL,screen,&m.positionminijoueur);
}

void afficherminimap2 (minimap m2, SDL_Surface * screen)
{
  
  SDL_BlitSurface(m2.minijoueur,NULL,screen,&m2.positionminijoueur);
}

void sauvegarder( int score, char nomjoueur[], char nomfichier[])
{FILE* f=NULL;
	
f=fopen(nomfichier,"a");

if(f!=NULL)
{
fprintf(f,"%d  %s \n",score,nomjoueur);
}
else
{printf("ERREUR");}

fclose(f);
}

void initialiser_temps(temps *t)
{
 t->texte = NULL; 
 t->position.x=600;
   t->position.y=30;
     t->police = NULL;
  t->police = TTF_OpenFont(" path to text police file ",28);
    strcpy( t->entree,"");
(t->secondesEcoulees)=0;
time(&(t->t1)); 



}


void afficher_temps(temps *t,SDL_Surface *ecran)
{	
SDL_Color couleurBlanche= {0,255,255};

    	time(&(t->t2));

		t->secondesEcoulees = t->t2 - t->t1;

        t->min=((t->secondesEcoulees/60)%60);
	t->sec= ((t->secondesEcoulees)%60);

	 sprintf(t->entree,"Time: %02d:%02d",t->min,t->sec);
        t->texte = TTF_RenderUTF8_Solid(t->police, t->entree, couleurBlanche);
      

SDL_BlitSurface(t->texte, NULL, ecran, &(t->position)); 
  


 
	
}

void free_temps(temps *t,SDL_Surface *ecran)
{SDL_FreeSurface(t->texte);
 TTF_CloseFont(t->police);
}

void meilleur( char nomfichier[], int *score, char nomjoueur[])
{int scr=0;
char nm[20];
int i=0;

FILE* f=NULL;

f=fopen(nomfichier,"r");

if (f!=NULL)
{
while(!feof(f))
{
fflush(stdin);
fscanf(f,"%d %s \n",&(*score),nomjoueur);

if(scr<*score)
{
scr=*score;
strcpy(nm,nomjoueur);
}

}


if(feof(f))
{printf("Le meilleur joueur est: %s \n",nm);}

}

else
{printf("ERREUR");}

fclose(f);
}

