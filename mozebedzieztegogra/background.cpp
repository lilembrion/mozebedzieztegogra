#include "background.h"
#include <SDL.h>
#include <iostream>
#include "draw.h"


#define SCREENWIDTH 640
#define SCREENHIGHT 480

void Background::DrawBackground(SDL_Renderer* renderer) {

    SDL_Color shipcolor = { 95, 95, 95, 255 }; // szary
    SDL_Color windowcolor = { 145, 145, 70, 255 }; // zolty
    SDL_Color buttoncolor1 = { 245, 145, 70, 255 };
    SDL_Color buttoncolor2 = { 45, 145, 70, 255 };
    SDL_Color buttoncolor3 = { 45, 45, 250, 255 };
    SDL_Color groundcolor = { 128, 43, 11, 255 };
    SDL_Color skycolor = { 82, 95, 167, 255 };
    SDL_Color starcolor = { 249, 231, 191, 255 };

    // Czyszczenie ekranu
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Czarny
    SDL_RenderClear(renderer);

    DrawFilledRectangle(renderer, 0, 0, SCREENWIDTH, SCREENWIDTH, skycolor);
    DrawFilledRectangle(renderer, 0, SCREENHIGHT * 2 / 3, SCREENWIDTH, SCREENHIGHT * 2 / 3, groundcolor);
    // Prezentacja renderera
    SDL_RenderPresent(renderer);
}