#include <SDL.h>
#include "draw.h"


class Crater {

public:

	Crater(int x, int y, int z);
	Crater(const Crater& other); // Konstruktor kopiuj¹cy

	void UpdateCraterPosition();
	void DrawCrater(SDL_Renderer* renderer);
	void DrawBackground(SDL_Renderer* renderer);
	int getX();

	virtual void DrawSpaceShip(SDL_Renderer* renderer) {
		 //cokolwiek 
		SDL_Color groundcolor = { 128, 43, 11, 255 };

		DrawFilledRectangle(renderer, craterX, craterY - 10, 60, 70, groundcolor);
	}
	virtual void UpdateSpaceShipPosition() {
		//cokolwiek
		craterX += 43;
	}

	virtual void DrawSpaceShipBackground(SDL_Renderer* renderer) {
		//cokolwiek
		craterX += 43;
	}

	int craterX; // Pocz¹tkowa pozycja
	int craterY; // Pozycja Y krateru

private:
	int spaceshipX;

	friend class DifCrater;
};

class DifCrater : public Crater {
public:

	DifCrater(int x, int y, int z);

	void DrawSpaceShip(SDL_Renderer* renderer) override;
	void UpdateSpaceShipPosition() override;
	void DrawSpaceShipBackground(SDL_Renderer* renderer) override;


};
