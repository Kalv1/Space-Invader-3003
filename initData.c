#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "initData.h"
#include "fichier_SDL.h"
#include "math.h"


int generate_number(int a, int b){
    return rand()%(b-a)+a;
}

sprite_t alearoc(SDL_Texture* rocheobj){
        SDL_Rect initPositionRoche = {
            .x = generate_number(62/2,600-(40)),
            .y = -12,
            .w = 40,
            .h = 40
        };

        sprite_t roche = {
            .pos = initPositionRoche,
            .obj = rocheobj,
            .vitesse = 1, // pas utilisé 
            .visible = 0
    };

    return roche;
}

world_t initData(SDL_Renderer * ecran) {
        
    SDL_Texture* obj = charger_image_transparente("images/vaisseau.bmp", ecran, 255, 0, 0);
    SDL_Texture* rocheobj = charger_image_transparente("images/Asteroide.bmp", ecran, 255, 0, 0);


    SDL_Rect initPosition = {
            .x = 259, //centre
            .y = 518, //centre
            .w = 62,
            .h = 62
    };


    sprite_t ship = {
            .pos = initPosition,
            .obj = obj,
            .vitesse = 3,
            .nbVies = 3,
            .visible = 0
    };

    

    world_t world = {
            .score = 0,
            .ship = ship,
            .tabRoche = {alearoc(rocheobj),alearoc(rocheobj),alearoc(rocheobj)}
    };

    return world;
}
