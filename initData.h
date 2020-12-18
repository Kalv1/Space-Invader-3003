#ifndef H_INITDATA
#define H_INITDATA

#define NB_ROCHERS 9

struct sprite_s{
    SDL_Rect pos;
    SDL_Texture *obj;
    int vitesse; // vitesse verticale
    int nbVies;
    int visible; // est ce que le sprite est visible ? 
};

typedef struct sprite_s sprite_t;

sprite_t alearoc(SDL_Texture* rocheobj);

struct world_s{
    sprite_t ship;
    sprite_t roche;
    sprite_t *tabRoche;
    int score; // pour plus tard
};

typedef struct world_s world_t;


world_t initData(SDL_Renderer * ecran);
int generate_number(int a, int b);

void destroy_date(world_t w);

#endif