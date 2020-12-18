#ifndef __TTF_SDL__
#define __TTF_SDL__

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>


void init_ttf();

TTF_Font *load_font(const char *path, int font_size);

void apply_text(SDL_Renderer *renderer, int x, int y, int w, int h, const char *text, TTF_Font *font);

void clean_font(TTF_Font *font);

#endif