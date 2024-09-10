#ifndef CHARACTER_H
#define CHARACTER_H

#include <SDL.h>

class Character {

public:

    Character(SDL_Renderer* renderer);
    ~Character();
    void DrawBackgroundWalk(SDL_Renderer* renderer);
    void DrawBackgroundSideUp(SDL_Renderer* renderer);
    void DrawBackgroundSideUpUp(SDL_Renderer* renderer);
    void DrawBackgroundUp(SDL_Renderer* renderer);
    void DrawBackgroundUpUp(SDL_Renderer* renderer);
    void WalkAnimation(SDL_Renderer* renderer);
    void JumpAnimation(SDL_Renderer* renderer);
    void SideJumpAnimation(SDL_Renderer* renderer);

private:
    SDL_Renderer* renderer;

};

#endif
