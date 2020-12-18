#ifndef H_COLLISION
#define H_COLLISION

#include "initData.h"

void exceed_limit_right(sprite_t *ship);

void exceed_limit_left(sprite_t *ship);

void exceed_limit_up(sprite_t *ship);

void exceed_limit_down(sprite_t *ship);

void exceed_limit_ennemy(world_t *world);

int sprites_collide(sprite_t *ship, sprite_t *roche);

void handle_sprites_collision(world_t *world, sprite_t *ship, sprite_t *roche);

#endif