#include "crater.h"
#include "draw.h"

#define v 20

Crater::Crater(int x, int y, int z) : craterX(x), craterY(y), spaceshipX(z) {}
Crater::Crater(const Crater& other) : craterX(other.craterX), craterY(other.craterY), spaceshipX(other.spaceshipX) {

}

void Crater::DrawCrater(SDL_Renderer* renderer) {

    SDL_Color red = { 108, 23, 1, 255 };
    SDL_Color darkred = { 90, 3, 1, 255 };

    DrawFilledRectangle(renderer, craterX, craterY, 40, 50, red);
    DrawFilledTriangle(renderer, craterX, craterY, craterX, craterY + 50, craterX - 10, craterY + 50, red);
    DrawFilledTriangle(renderer, craterX + 40, craterY + 50, craterX + 50, craterY + 50, craterX + 40, craterY, red);
    DrawFilledEllipse(renderer, craterX + 20, craterY, 20, 10, darkred);
    
}

void Crater::UpdateCraterPosition() {
    craterX -= v; // Przesuwanie krateru w lewo
    if (craterX < -50) { //resetuj pozycjê
        craterX = SCREENWIDTH;
    }
}

void Crater::DrawBackground(SDL_Renderer* renderer) {

    SDL_Color groundcolor = { 128, 43, 11, 255 };

    DrawFilledRectangle(renderer, craterX + v, craterY - 10, 50, 70, groundcolor);
}

int Crater::getX(){
    return craterX;
}