#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "fichier_SDL.h"


int main(int argc, char *argv[]){
    SDL_Window* fenetre;  // Déclaration de la fenêtre
    SDL_Event evenements; // Événements liés à la fenêtre
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

    // Mettre en place un contexte de rendu de l’écran
    SDL_Renderer* ecran;ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
    // Charger l’image
    SDL_Texture* fond = charger_image( "images/fond.bmp", ecran );

    // Charger l’image avec la transparence
    Uint8 r = 255, g = 0, b = 0;
    SDL_Texture* obj = charger_image_transparente("images/vaisseau.bmp", ecran, r, g, b);
    SDL_Rect SrcR;
    SrcR.x = 0;
    SrcR.y = 0;
    SrcR.w = 82; // Largeur de l’objet en pixels (à récupérer)
    SrcR.h = 82; // Hauteur de l’objet en pixels (à récupérer)

    SDL_Rect DestR;
    DestR.x = 259;
    DestR.y = 518;
    DestR.w = 82;
    DestR.h = 82;


    
    // Boucle principale
    while(!terminer)
    {
        SDL_RenderClear(ecran);
        SDL_RenderCopy(ecran, fond, NULL, NULL);
        SDL_RenderCopy(ecran, obj, &SrcR, &DestR);
        //SDL_PollEvent ...
        SDL_RenderPresent(ecran);
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

    SDL_DestroyTexture(fond);
    SDL_DestroyRenderer(ecran);
    // QUITTER SDL
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    return 0;
}