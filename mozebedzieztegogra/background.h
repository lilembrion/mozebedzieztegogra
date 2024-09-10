#include <SDL.h>
#include "draw.h"

class Background {

public:
	void DrawBackground(SDL_Renderer* renderer);

	void operator*(SDL_Renderer* renderer) const {
		// Ustawienie ziarna dla generatora liczb losowych
		//srand(static_cast<unsigned int>(time(0)));

		// Generowanie losowych wsp�rz�dnych w g�rnej po�owie ekranu
		int randX = rand() % SCREENWIDTH;
		int randY = rand() % (SCREENHEIGHT / 2);

		// Kolor k�ka
		SDL_Color circleColor = { 220, 200, 200, 255 };

		// Rysowanie k�ka
		DrawFilledCircle(renderer, randX, randY, rand() % 4, circleColor);
	}
};

