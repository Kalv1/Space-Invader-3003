#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "initData.h"
#include "fichier_SDL.h"


world_t initData(SDL_Renderer * ecran) {
    SDL_Texture* obj = charger_image_transparente("images/vaisseau.bmp", ecran, 255, 0, 0);

    SDL_Rect initPosition = {
            .x = 259,
            .y = 518,
            .w = 82,
            .h = 82
    };

    sprite_t ship = {
            .pos = initPosition,
            .obj = obj,
            .vitesse = 10
    };

    world_t world = {
            .score = 0,
            .ship = ship
    };

    return world;
}
