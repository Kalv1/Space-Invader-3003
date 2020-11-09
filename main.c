#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "texture.h"
#include "base.h"

int main(int argc, char *argv[]){
    SDL_Window* fenetre;  // Déclaration de la fenêtre
    SDL_Event evenements; // Événements liés à la fenêtre
    world_t world;
    SDL_t textures;
    SDL_Renderer *renderer;
    bool terminer = false;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) // Initialisation de la SDL
    {
        printf("Erreur d’initialisation de la SDL: %s",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    // Créer la fenêtre
    fenetre = SDL_CreateWindow("Warblade Like", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_RESIZABLE);
    if(fenetre == NULL) // En cas d’erreur
    {
        printf("Erreur de la creation d’une fenetre: %s",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }


    // Boucle principale
    while(!terminer)
    {
        refresh(renderer,&world,&textures);
        while( SDL_PollEvent( &evenements ) )
        switch(evenements.type)
            {
                case SDL_QUIT:
                    terminer = true; 
                    break;
                case SDL_KEYDOWN:
                    switch(evenements.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        terminer = true;  break;
                }
            }
    }
    // QUITTER SDL
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    return 0;
}