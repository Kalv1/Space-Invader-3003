#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "fichier_SDL.h"
#include "initData.h"
#include "collision.h"
#include "sdl2-ttf-light.c"

#define DEPLACEMENT 1
#define WINDOWN_H 600
#define DIST_ROCHE 40
#define NB_ROCHERS 9




int main(int argc, char *argv[]){

    SDL_Window* fenetre;  // Déclaration de la fenêtre
    SDL_Event evenements; // Événements liés à la fenêtre
    srand(time(NULL));
    int etat = 0;
    bool terminer = false;
    init_ttf();

    if(SDL_Init(SDL_INIT_VIDEO) < 0) // Initialisation de la SDL
    {
        printf("Erreur d’initialisation de la SDL: %s",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    // Créer la fenêtre
    fenetre = SDL_CreateWindow("Warblade Like", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, WINDOWN_H, WINDOWN_H, 0);
    if(fenetre == NULL) // En cas d’erreur
    {
        printf("Erreur de la creation d’une fenetre: %s",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    // Mettre en place un contexte de rendu de l’écran
    SDL_Renderer* ecran;
    ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
    // Charger l’image
    SDL_Texture* fond = charger_image( "images/fond.bmp", ecran );

    world_t world = initData(ecran);

    //Charger la font:
    TTF_Font *font = load_font("Android 101.ttf",40);



    SDL_Rect SrcR;
    SrcR.w = 82; // Largeur de l’objet en pixels (à récupérer)
    SrcR.h = 82; // Hauteur de l’objet en pixels (à récupérer)
    int tempsAv = 0;
    // Boucle principale
    while(!terminer)
    {
        SDL_RenderClear(ecran);
        SDL_RenderCopy(ecran, fond, NULL, NULL);
        SDL_RenderCopy(ecran, world.ship.obj, &SrcR, &world.ship.pos);
        for(int i = 0; i< NB_ROCHERS; i++){
             SDL_RenderCopy(ecran, world.tabRoche[i].obj, &SrcR, &world.tabRoche[i].pos);
        }
        char *str = malloc(sizeof(char) * 20);
        sprintf(str,"SCORE: %6d", world.score);
        apply_text(ecran,10,10,50,20,str,font);
        //SDL_PollEvent ...
        SDL_RenderPresent(ecran);
        while( SDL_PollEvent( &evenements ) )
        switch(evenements.type)
            {
                case SDL_QUIT:
                    terminer = true; 
                    break;
                case SDL_KEYDOWN:
                    switch(evenements.key.keysym.sym){
                        case SDLK_ESCAPE:
                            terminer = true;  break;
                        case SDLK_LEFT:
                            world.ship.pos.x -= world.ship.vitesse*DEPLACEMENT;
                            exceed_limit_left(&world.ship);
                            break;
                        case SDLK_RIGHT:
                            world.ship.pos.x += world.ship.vitesse*DEPLACEMENT;
                            exceed_limit_right(&world.ship);
                            break;
                        case SDLK_UP:
                            world.ship.pos.y -= world.ship.vitesse*DEPLACEMENT;
                            exceed_limit_up(&world.ship);
                            break;
                        case SDLK_DOWN:
                            world.ship.pos.y += world.ship.vitesse*DEPLACEMENT;
                            exceed_limit_down(&world.ship);
                            break;
                    }
            }


            int tempsActu = SDL_GetTicks();

            if(tempsActu > tempsAv + 50 ){
                for(int i = 0; i < NB_ROCHERS; i++){
                world.tabRoche[i].pos.y += world.tabRoche[i].vitesse *5;
                handle_sprites_collision(&world, &world.ship, &world.tabRoche[i]);
                exceed_limit_ennemy(&world);
                    if(world.ship.nbVies == 0){
                        etat = 1; //perdu
                    }
                tempsAv = tempsActu;
                }
            }

        if(etat == 1){
            printf("GAMEOVER");
            terminer = true;
        }
    }
    
    TTF_CloseFont(font);
    SDL_DestroyTexture(fond);
    SDL_DestroyRenderer(ecran);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    return 0;
}
