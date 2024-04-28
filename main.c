
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "minimap.h"



int main()
{
    TTF_Init();
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *screen ,*perso,*perso2;
screen=SDL_SetVideoMode (800,385,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_WM_SetCaption("minimap\t1",NULL);
SDL_Rect camera,camera2,posperso,posperso2;
SDL_Event event;
minimap m,m2;
temps t;
SDL_Surface *back;
perso2=IMG_Load(" path to player picture ");
perso=IMG_Load("path to minimap player picture ");
back=IMG_Load (" path to backgroun picture ");
int continuer=1,score;
char nomjoueur[20];
printf("Taper le nom du joueur: \n");
scanf("%s",nomjoueur);

printf("Taper le score du joueur: \n");
scanf("%d",&score);

sauvegarder(score,nomjoueur," path to saving score file "); 

init_map(&m);
init_map2 (&m2);
camera.x=0;
camera.y=0;
camera.w=1300;
camera.h=700;
camera2.x=0;
camera2.y=0;
camera2.w=1300;
camera2.h=700;
posperso.x=0;
posperso.y=260;
posperso2.x=0;
posperso2.y=280;
SDL_EnableKeyRepeat(100,10);
initialiser_temps(&t);


while(continuer)
{
    afficher_temps(&t,screen);
    SDL_BlitSurface(back,NULL,screen,NULL);
while(SDL_PollEvent(&event))
	{

		switch(event.type)
		{
		case SDL_QUIT:

			continuer=0;
		break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
            
                case SDLK_LEFT:
                 
                 
                     posperso.x-=5;
                
                    
                break;
                case SDLK_RIGHT:
                  
                      posperso.x+=5;
                    
                break;
                case SDLK_UP:
              
                      posperso.y-=5;
                break;  
                case SDLK_DOWN:
                    
                      posperso.y+=5;

                break;  

            case SDLK_q:
                 
                 
                     posperso2.x-=5;
                
                    
                break;
                case SDLK_d:
                  
                      posperso2.x+=5;
                    
                break;
                case SDLK_z:
              
                      posperso2.y-=5;
                break;  
                case SDLK_s:
                    
                      posperso2.y+=5;

                break;  
            case SDLK_m:
               meilleur(" path to saving score file ",&score,nomjoueur);
                break;  
            
            }
            break;
            
        }
    }        






SDL_BlitSurface(perso,NULL,screen,&posperso);
SDL_BlitSurface(perso2,NULL,screen,&posperso2);

MAJMinimap(posperso ,  &m, camera, 20);
MAJMinimap(posperso2 ,  &m2, camera2, 20);
afficherminimap(m,screen);
afficherminimap2(m2,screen);

afficher_temps(&t,screen);

SDL_Flip(screen);


}

    
}


