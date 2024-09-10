#include "gwiazdki.h"
#include "draw.h"
#include <cstdlib>
#include <ctime>

void Gwiazdki::Draw(SDL_Renderer* renderer) {

    x = rand() % SCREENWIDTH;
    y = rand() % (SCREENHEIGHT / 2);

    SDL_Color yellow = { 200, 200, 10, 255 };

    DrawFilledCircle(renderer, x, y, x % 3, yellow);
}