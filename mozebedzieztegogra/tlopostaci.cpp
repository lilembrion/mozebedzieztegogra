#include <SDL.h>
#include <iostream>
#include "draw.h"
#include "character.h"

#define SCREENWIDTH 640
#define SCREENHIGHT 480
#define SKOK -30
#define SKOK2 -50

Character::Character(SDL_Renderer* renderer) : renderer(renderer) {
    // Constructor body (if needed)
}

Character::~Character() {

    SDL_Color white = { 233, 233, 233, 255 };
    SDL_Color black = { 0, 0, 0, 255 };

    DrawFilledRectangle(renderer, 0, 0, SCREENWIDTH, SCREENHEIGHT, black);
    DrawFilledCircle(renderer, SCREENWIDTH / 2, SCREENHEIGHT / 2 - 50, 100, white);
    DrawFilledRectangle(renderer, SCREENWIDTH / 2 - 40, SCREENHEIGHT / 2, 80, 90, white);
    DrawFilledCircle(renderer, SCREENWIDTH / 2 - 45, SCREENHEIGHT / 2 - 50, 20, black);
    DrawFilledCircle(renderer, SCREENWIDTH / 2 + 45, SCREENHEIGHT / 2 - 50, 20, black);
    DrawFilledTriangle(renderer, SCREENWIDTH / 2 - 10, SCREENHEIGHT / 2 + 10, SCREENWIDTH / 2 + 10, SCREENHEIGHT / 2 + 10,
        SCREENWIDTH / 2, SCREENHEIGHT / 2 - 40, black);

    SDL_RenderPresent(renderer);
    SDL_Delay(4000);
}

void Character::DrawBackgroundWalk(SDL_Renderer* renderer) {

    SDL_Color groundcolor = { 128, 43, 11, 255 };
    SDL_Color skycolor = { 82, 95, 167, 255 };
    SDL_Color starcolor = { 249, 231, 191, 255 };
    SDL_Color test = { 100, 231, 191, 255 };

    DrawFilledRectangle(renderer, 44, 232 - 30+ SKOK, 80+5, 88 - SKOK + 30, skycolor);
    DrawFilledRectangle(renderer, 44, 320, 80+5, 42, groundcolor);

    // Prezentacja renderera
    SDL_RenderPresent(renderer);
}

void Character::DrawBackgroundSideUp(SDL_Renderer* renderer) {

    SDL_Color groundcolor = { 128, 43, 11, 255 };
    SDL_Color skycolor = { 82, 95, 167, 255 };
    SDL_Color starcolor = { 249, 231, 191, 255 };
        SDL_Color test = { 100, 231, 191, 255 };
        SDL_Color test2 = { 100, 2, 191, 255 };

    DrawFilledRectangle(renderer, 44, 232 + SKOK -20, 80+5, 88 - SKOK + 20, skycolor);
    DrawFilledRectangle(renderer, 44, 320, 80+5, 42 + SKOK, groundcolor);

    // Prezentacja renderera
    SDL_RenderPresent(renderer);
}

void Character::DrawBackgroundSideUpUp(SDL_Renderer* renderer) {

    SDL_Color groundcolor = { 128, 43, 11, 255 };
    SDL_Color skycolor = { 82, 95, 167, 255 };
    SDL_Color starcolor = { 249, 231, 191, 255 };
    SDL_Color test = { 100, 231, 191, 255 };

    DrawFilledRectangle(renderer, 44, 232 + SKOK2 - 20, 80+5, 88 - SKOK2 + 20, skycolor);
    //DrawFilledRectangle(renderer, 44, 320, 80+5, 42, test);

    // Prezentacja renderera
    SDL_RenderPresent(renderer);
}

void Character::DrawBackgroundUp(SDL_Renderer* renderer) {

    SDL_Color groundcolor = { 128, 43, 11, 255 };
    SDL_Color skycolor = { 82, 95, 167, 255 };
    SDL_Color starcolor = { 249, 231, 191, 255 };
    SDL_Color test = { 100, 231, 191, 255 };
    SDL_Color test2 = { 100, 2, 191, 255 };

    DrawFilledRectangle(renderer, 44, 232 + SKOK - 20, 80 + 5, 88 - SKOK + 20, skycolor);
    DrawFilledRectangle(renderer, 44, 320, 80 + 5, 42, groundcolor);

    // Prezentacja renderera
    SDL_RenderPresent(renderer);
}

void Character::DrawBackgroundUpUp(SDL_Renderer* renderer) {

    SDL_Color groundcolor = { 128, 43, 11, 255 };
    SDL_Color skycolor = { 82, 95, 167, 255 };
    SDL_Color starcolor = { 249, 231, 191, 255 };
    SDL_Color test = { 100, 231, 191, 255 };

    DrawFilledRectangle(renderer, 44, 232 + SKOK2 - 20, 80 + 5, 88 - SKOK2 + 20, skycolor);
    DrawFilledRectangle(renderer, 44, 320, 80 + 5, 42 + SKOK, groundcolor);
    //DrawFilledRectangle(renderer, 44, 320, 80+5, 42, test);

    // Prezentacja renderera
    SDL_RenderPresent(renderer);
}
