/**
 * \file texture.h
 * \brief header de textures
 * \version 1.0
 * \date 8 Novembre 2020
 */

#include "base.h"


SDL_Texture *load_image(const char path[], SDL_Renderer *renderer);

void apply_texture(SDL_Texture *texture,SDL_Renderer *renderer,int x, int y);

void  init_textures(SDL_Renderer *renderer, SDLT_t *textures);

void refresh(SDL_Renderer *renderer, world_t *world, SDLT_t *textures);