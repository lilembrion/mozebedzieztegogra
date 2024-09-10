#include <SDL.h>
#include "jumpframe1.h"
#include "jumpframe2.h"
#include "jumpframe3.h"
#include "character.h"

void Character::JumpAnimation(SDL_Renderer* renderer) {

    DrawBackgroundUp(renderer);
    DrawJumpFrame1(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(150);

    
    DrawBackgroundWalk(renderer);
    DrawJumpFrame2(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(150);

    DrawBackgroundUp(renderer);
    DrawJumpFrame3(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(150);
    
    DrawBackgroundUpUp(renderer);
    DrawJumpFrame2(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(150);
}
