#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "tic.h"

void initialiser_tic(tic *t)
{
    t->XO_Img=IMG_Load("xo.png");

    t->xoR[1][1].x=19;
    t->xoR[1][1].y=20;
    t->xoR[1][2].x=116;
    t->xoR[1][2].y=20;
    t->xoR[1][3].x=214;
    t->xoR[1][3].y=20;

    t->xoR[2][1].x=19;
    t->xoR[2][1].y=117;
    t->xoR[2][2].x=116;
    t->xoR[2][2].y=117;
    t->xoR[2][3].x=214;
    t->xoR[2][3].y=117;

    t->xoR[3][1].x=19;
    t->xoR[3][1].y=213;
    t->xoR[3][2].x=116;
    t->xoR[3][2].y=213;
    t->xoR[3][3].x=214;
    t->xoR[3][3].y=213;

    t->posxo[1].x=0;
    t->posxo[1].y=0;
    t->posxo[1].w=64;
    t->posxo[1].h=67;

    t->posxo[2].x=67;
    t->posxo[2].y=0;
    t->posxo[2].w=64;
    t->posxo[2].h=67;

    for(int i=1;i<4;i++)
    {
        for(int j=1;j<4;j++)
        {
            t->tab[i][j]=0;
        }
    }
    
    t->tour=1;
    t->winner=0;   
}

void Random_Xo(tic *t)
{
    int x,y;
    srand(time(NULL));
    do{
        do{
            x=rand()%4;
        }while(x==0);

        do{
            y=rand()%4;
        }while(y==0);

        Put_Xo(t,x,y);
        printf("%d,%d\n",x,y);
    }while(t->tab[x][y]==0);

}

void Put_Xo(tic* t,int x,int y)
{
    if(t->tour==1)
    {
        if(t->tab[x][y]==0)
        {
           t->tab[x][y]=1;
           t->tour=2;
        }
    }
    else
    {
        if(t->tab[x][y]==0)
        {
           t->tab[x][y]=2; 
           t->tour=1;
        }
    }
}


void Afficher(tic *t,SDL_Surface* screen)
{
    for(int i=1;i<4;i++)
    {
        for(int j=1;j<4;j++)
        {
            if(t->tab[i][j]==1){
               SDL_BlitSurface(t->XO_Img,&t->posxo[1],screen,&t->xoR[i][j]); 
            }
            else if (t->tab[i][j]==2){
                SDL_BlitSurface(t->XO_Img,&t->posxo[2],screen,&t->xoR[i][j]);
            }   
        }
    }
    SDL_Flip(screen);
}



int Resultat(tic *t)
{
    int j=1;
    int total=0;
    int verif=0;
    while(j<4){
    for(int i=1;i<4;i++)
    {
        if(t->tab[i][j]==1)
        {
            total--;
        }
        else if(t->tab[i][j]==2)
        {
            total++;
        }
        if(i==3){
            if(total==-3){
                t->winner=1;
                return 1;
            }
            else if(total==3){
                t->winner=2;
                return 1;
            }
        }
        
    }
    total=0;
    j++;
    }

    j=1;
    while(j<4){
    for(int i=1;i<4;i++)
    {
        if(t->tab[j][i]==1)
        {
            total--;
        }
        else if(t->tab[j][i]==2)
        {
            total++;
        }
        if(i==3){
            if(total==-3){
                t->winner=1;
                return 1;
            }
            else if(total==3){
                t->winner=2;
                return 1;
            }
        }
        
    }
    total=0;
    j++;
    }
    
    for(int i=1;i<4;i++)
    {
        if(t->tab[i][i]==1)
        {
            total--;
        }
        else if(t->tab[i][i]==2)
        {
            total++;
        }
    }

    if(total==-3){
        t->winner=1;
        return 1;
    }
    else if(total==3){
        t->winner=2;
        return 1;
    }

    total=0;
    for(int i=1;i<4;i++)
    {
        if(t->tab[i][4-i]==1)
        {
            total--;
        }
        else if(t->tab[i][4-i]==2)
        {
            total++;
        }
    }

    if(total==-3){
        t->winner=1;
        return 1;
    }
    else if(total==3){
        t->winner=2;
        return 1;
    }
    

    for(int i=1;i<4;i++)
    {
        for(int j=1;j<4;j++)
        {
            if(t->tab[i][j]!=0)
            {
                verif++;
            }
        }
    }
    if(verif==9){
        return 1;
    }
    else{
        return 0;
    }

}

void liberer(tic *t)
{
    SDL_FreeSurface(t->XO_Img);
}




