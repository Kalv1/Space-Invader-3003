#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "initData.h"
#include "fichier_SDL.h"
#include "math.h"

#define NB_ROCHES 5


int generate_number(int a, int b){
    return rand()%(b-a)+a;
}

world_t initData(SDL_Renderer * ecran) {
    SDL_Texture* obj = charger_image_transparente("images/vaisseau.bmp", ecran, 255, 0, 0);
    SDL_Texture* rocheobj = charger_image_transparente("images/Asteroide.bmp", ecran, 255, 0, 0);


    SDL_Rect initPosition = {
            .x = 259,
            .y = 518,
            .w = 62,
            .h = 62
    };



    SDL_Rect initPositionRoche = {
            .x = generate_number(62/2,600-(62/2)),
            .y = 62,
            .w = 40,
            .h = 40
    };

    sprite_t ship = {
            .pos = initPosition,
            .obj = obj,
            .vitesse = 10
    };

    sprite_t roche = {
            .pos = initPositionRoche,
            .obj = rocheobj,
            .vitesse = 3
    };

    world_t world = {
            .score = 0,
            .ship = ship,
            .roche = roche
    };

    return world;
}
