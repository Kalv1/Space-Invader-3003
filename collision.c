#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "math.h"
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


int sprites_collide(sprite_t *ship, sprite_t *roche){
    int collision = 0;
    float dist_centre_sprite = sqrt(pow(ship->pos.x-roche->pos.x,2)+pow(ship->pos.y-roche->pos.y,2));
        if(dist_centre_sprite <= (ship->pos.h+roche->pos.h)/2){
            collision = 1;
        }
    return collision;
}

void handle_sprites_collision(world_t *world, sprite_t *ship, sprite_t *roche){
    int collision;
    collision = sprites_collide(ship,roche);

        if (collision == 1){
            //vie -1
            world->ship.nbVies --;

            //score -10
            //world->score = world->score - 2;

            //ralentissement
            printf("test");
            world->ship.vitesse = world->ship.vitesse;

            world->roche.visible = 1;
        }
}