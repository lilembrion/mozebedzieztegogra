#include "frame1.h"
#include "frame2.h"
#include "frame3.h"
#include "frame4.h"
#include "character.h"

#define PX 0

void Character::WalkAnimation(SDL_Renderer* renderer) {
    // Rysowanie klatek animacji

    DrawBackgroundWalk(renderer);
    DrawFrame1(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(250);

    DrawBackgroundWalk(renderer);
    DrawFrame2(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(250);

    DrawBackgroundWalk(renderer);
    DrawFrame3(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(250);

    DrawBackgroundWalk(renderer);
    DrawFrame4(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(250);
}