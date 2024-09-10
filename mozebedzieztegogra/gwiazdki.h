#include <SDL.h>
#include "drawable.h"

class Gwiazdki : public Drawable {

public:

    void Draw(SDL_Renderer* renderer) override;
    int x, y;
};

