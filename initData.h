#ifndef H_INITDATA
#define H_INITDATA


struct sprite_s{
    SDL_Rect pos;
    SDL_Texture *obj;
    int vitesse; // vitesse verticale
};

typedef struct sprite_s sprite_t;


struct world_s{
    sprite_t ship;
    int score; // pour plus tard
};

typedef struct world_s world_t;


world_t initData(SDL_Renderer * ecran);

#endif