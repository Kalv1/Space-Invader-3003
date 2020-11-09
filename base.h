/**
 * \file base.h
 * \brief Header definissant les bases du projet (structure et les constantes)
 * \version 1.0
 * \date 8 Novembre 2020
 */


#include <SDL2/SDL.h>

/**
 * \brief Représentation pour stocker les textures nécessaires à l'affichage graphique
*/

struct SDLT_s{
    SDL_Texture* fond; // fond d'ecran 
    SDL_Texture* ship;

};

typedef struct SDLT_s SDLT_t;




/**
 * \brief Structure definissant le vaisseau position X, position Y...
*/

struct ship_s{
    int x;
    int y;  
    int hauteur; // hauteur
    int largeur; // largeur
};

typedef struct ship_s ship_t;

/**
 * \brief Représentation du monde du jeu
*/

struct world_s{

    ship_t ship;

    int gameover; 

};

typedef struct world_s world_t;


