#include <SDL.h>

class Drawable {
public:
	virtual ~Drawable() = default;
	virtual void Draw(SDL_Renderer * renderer) = 0;
};

