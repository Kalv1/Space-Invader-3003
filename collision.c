#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

#include "collision.h"
#include "initData.h"

#define SHIP_SIZE 62 //besoin que de une constante car le vaisseau est carré 
 
void exceed_limit_right(sprite_t *ship){
    if ((ship->pos.x + SHIP_SIZE/2) > 600-(SHIP_SIZE/2) ){
        ship->pos.x= 600 - (SHIP_SIZE);
    }
}

void exceed_limit_up(sprite_t *ship){
    if ((ship->pos.y) < 0 ){
        ship->pos.y = 0;
    }
}


void exceed_limit_left(sprite_t *ship){
    if ((ship->pos.x - SHIP_SIZE/2) < 0 - (SHIP_SIZE/2) ){
        ship->pos.x = 0;
    }
}

void exceed_limit_down(sprite_t *ship){
    if ((ship->pos.y) > 600 - SHIP_SIZE ){
        ship->pos.y = 600 - SHIP_SIZE;
    }
}