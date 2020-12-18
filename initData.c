#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "initData.h"
#include "fichier_SDL.h"
#include "math.h"

#define DIST_ROCHE 80


int generate_number(int a, int b){
    return rand()%(b-a)+a;
}

sprite_t alearoc(SDL_Texture* rocheobj){
        SDL_Rect initPositionRoche = {
            .x = generate_number(62/2,600-(40)),
            .y = -generate_number(0,500),
            .w = 40,
            .h = 40
        };

        sprite_t roche = {
            .pos = initPositionRoche,
            .obj = rocheobj,
            .vitesse = 2, 
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
            .vitesse = 15,
            .nbVies = 10,
            .visible = 0
    };

    

    world_t world = {
            .score = 0,
            .ship = ship,
            .tabRoche = malloc(sizeof(sprite_t) * NB_ROCHERS)
    };

    for(int i = 0 ; i < NB_ROCHERS ; i++){
        world.tabRoche[i] = alearoc(rocheobj);
    }

    return world;
}

void destroy_data(world_t w){
    SDL_DestroyTexture(w.ship.obj);
    SDL_DestroyTexture(w.roche.obj);
    free(w.tabRoche);
}
