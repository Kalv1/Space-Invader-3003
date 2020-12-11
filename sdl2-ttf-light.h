

#ifndef __SDL2_TTF_LIGHT__H
#define __SDL2_TTF_LIGHT__H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>


void init_ttf();
TTF_Font * load_font(const char* path, int font_size);
void apply_text(SDL_Renderer *renderer,int x, int y, int w, int h, const char *text, TTF_Font *font);
void clean_font(TTF_Font * font);

#endif