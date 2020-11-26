#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

#include "collision.h"
#include "initData.h"

void exceed_limit_right(sprite_t *ship){
    if ((ship->pos.x + 82/2) > 600-(82/2) ){
        ship->pos.x= 600 - (82);
    }
}

void exceed_limit_up(sprite_t *ship){
    if ((ship->pos.y) < 0 ){
        ship->pos.y = 0;
    }
}


void exceed_limit_left(sprite_t *ship){
    if ((ship->pos.x - 82/2) < 0 - (82/2) ){
        ship->pos.x = 0;
    }
}

void exceed_limit_down(sprite_t *ship){
    if ((ship->pos.y) > 600 - 82 ){
        ship->pos.y = 600 - 82;
    }
}