#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <unistd.h>
#include "fichier_SDL.h"
#include "initData.h"
#include "time.h"
#include "collision.h"
#include "initTTF.c"

#define DEPLACEMENT 1
#define WINDOWN_H 600
#define DIST_ROCHE 40
#define NB_ROCHERS 9


int main() {

    SDL_Window *fenetre = NULL;  // Déclaration de la fenêtre
    SDL_Event evenements = {0}; // Événements liés à la fenêtre
    srand(time(NULL));
    int etat = 0;
    bool terminer = false;
    init_ttf();


    if (SDL_Init(SDL_INIT_VIDEO) < 0) // Initialisation de la SDL
    {
        printf("Erreur d’initialisation de la SDL: %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    // Créer la fenêtre
    fenetre = SDL_CreateWindow("Warblade Like", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOWN_H, WINDOWN_H,
                               0);
    if (fenetre == NULL) // En cas d’erreur
    {
        printf("Erreur de la creation d’une fenetre: %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    // Mettre en place un contexte de rendu de l’écran
    SDL_Renderer *ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
    // Charger l’image
    SDL_Texture *fond = charger_image("images/fond.bmp", ecran);

    world_t world = initData(ecran);

    //Charger la font:
    TTF_Font *font = load_font("font/Android 101.ttf", 30);

    FILE *pfile = fopen("myfile.txt", "rb");
    char a[6];
    fscanf(pfile, "%[^\n]", a);
    fclose(pfile);
    int b = atoi(a);

    SDL_Rect SrcR = {0,0,82,82};
    int tempsAv = 0;
    // Boucle principale
    while (!terminer) {
        SDL_RenderClear(ecran);
        SDL_RenderCopy(ecran, fond, NULL, NULL);
        SDL_RenderCopy(ecran, world.ship.obj, &SrcR, &world.ship.pos);
        for (int i = 0; i < NB_ROCHERS; i++) {
            SDL_RenderCopy(ecran, world.tabRoche[i].obj, &SrcR, &world.tabRoche[i].pos);
        }


        char *str = malloc(sizeof(char) * 20);

        if (etat == 0) {
            sprintf(str, "SCORE: %6d", world.score);
            apply_text(ecran, 250, 20, 100, 50, str, font);

            sprintf(str, "VIE: %6d", world.ship.nbVies);
            apply_text(ecran, 20, 20, 50, 25, str, font);

            sprintf(str, "HIGH-SCORE: %6d", b);
            apply_text(ecran, 235, 70, 125, 50, str, font);

            SDL_RenderPresent(ecran);
        }


        //SDL_PollEvent ...
        SDL_RenderPresent(ecran);
        while (SDL_PollEvent(&evenements))
            switch (evenements.type) {
                case SDL_QUIT:
                    terminer = true;
                    break;
                case SDL_KEYDOWN:
                    switch (evenements.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            terminer = true;
                            break;
                        case SDLK_LEFT:
                            world.ship.pos.x -= world.ship.vitesse * DEPLACEMENT;
                            exceed_limit_left(&world.ship);
                            break;
                        case SDLK_RIGHT:
                            world.ship.pos.x += world.ship.vitesse * DEPLACEMENT;
                            exceed_limit_right(&world.ship);
                            break;
                        case SDLK_UP:
                            world.ship.pos.y -= world.ship.vitesse * DEPLACEMENT;
                            exceed_limit_up(&world.ship);
                            break;
                        case SDLK_DOWN:
                            world.ship.pos.y += world.ship.vitesse * DEPLACEMENT;
                            exceed_limit_down(&world.ship);
                            break;
                    }
            }


        int tempsActu = SDL_GetTicks();

        if (tempsActu > tempsAv + 50) {
            for (int i = 0; i < NB_ROCHERS; i++) {
                world.tabRoche[i].pos.y += world.tabRoche[i].vitesse * 2;
                handle_sprites_collision(&world, &world.ship, &world.tabRoche[i]);
                exceed_limit_ennemy(&world);
                if (world.ship.nbVies == 0) {
                    etat = 1; //perdu
                }
                tempsAv = tempsActu;
            }
        }


        if (etat == 1) {
            sprintf(str, "SCORE: %6d", world.score);
            apply_text(ecran, (600 / 2) - 100, (600) / 2 - 75, 200, 100, "GAMEOVER", font);
            apply_text(ecran, (600 / 2) - 100, (600) / 2 + 10, 200, 75, str, font);
            SDL_RenderPresent(ecran);
            terminer = true;
        }
        free(str);
    }


    int c = world.score;


    if (b < c) {
        pfile = fopen("myfile.txt", "w+");
        if (pfile == NULL) {
            perror("Error opening file");
        } else {
            fprintf(pfile, "%d", c);
            fprintf(pfile, "%s", ";\n");
            if (ferror(pfile)) {
                perror("Error writing to myfile.txt \n");
                fclose(pfile);
            }
        }
    }


    sleep(2);
    destroy_data(world);
    TTF_CloseFont(font);
    SDL_DestroyTexture(fond);
    SDL_DestroyRenderer(ecran);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    return 0;
}
