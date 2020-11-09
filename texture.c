/**
 * \file texture.c
 * \brief Programme contenant les données du jeu
 * \version 1.0
 * \date 8 Novembre 2020
 */

#include "texture.h"


SDL_Texture *load_image(const char path[], SDL_Renderer *renderer)
{
    SDL_Surface *tmp = NULL;
    SDL_Texture *texture = NULL;
    tmp = SDL_LoadBMP(path);
    if(NULL == tmp)
    {
        fprintf(stderr, "Erreur pendant chargement image BMP: %s", SDL_GetError());
        return NULL;
    }
    SDL_SetColorKey(tmp, SDL_TRUE, SDL_MapRGB(tmp->format, 255, 0, 255));
    texture = SDL_CreateTextureFromSurface(renderer, tmp);
    SDL_FreeSurface(tmp);
    if(NULL == texture)
    {
        fprintf(stderr, "Erreur pendant creation de la texture liee a l'image chargee: %s", SDL_GetError());
        return NULL;
    }
    return texture;
}



void apply_texture(SDL_Texture *texture,SDL_Renderer *renderer,int x, int y){
    SDL_Rect dst = {0, 0, 0, 0};
    
    SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
    dst.x = x; dst.y=y;
    
    SDL_RenderCopy(renderer, texture, NULL, &dst);
    
}

void  init_textures(SDL_Renderer *renderer, SDLT_t *textures){
    textures->background = load_image( "images/fond.bmp",renderer);
    textures->sprite = load_image( "images/vaisseau.bmp",renderer);
}

void refresh(SDL_Renderer *renderer, world_t *world, SDL_t *textures){
    
    //on vide le renderer
    clear_renderer(renderer);
    apply_background(renderer, textures);


    update_screen(renderer);

}
