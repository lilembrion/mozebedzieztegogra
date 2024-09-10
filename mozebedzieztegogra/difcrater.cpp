#include "crater.h"
#include "draw.h"
#define s 20

DifCrater::DifCrater(int x, int y, int z) : Crater(x, y, z) {}

void DifCrater::DrawSpaceShip(SDL_Renderer* renderer) {

	// Kolor trójk¹ta
	SDL_Color shipcolor = { 95, 95, 95, 255 }; // szary
	SDL_Color windowcolor = { 145, 145, 70, 255 }; // zolty
	SDL_Color buttoncolor1 = { 245, 145, 70, 255 };
	SDL_Color buttoncolor2 = { 45, 145, 70, 255 };
	SDL_Color buttoncolor3 = { 45, 45, 250, 255 };


	DrawFilledEllipse(renderer, 300 / 5 + Crater::spaceshipX, 420 / 5, 200 / 5, 50 / 5, shipcolor);
	DrawFilledHalfCircle(renderer, 300 / 5 + Crater::spaceshipX, 400 / 5, 80 / 5, shipcolor);
	DrawFilledHalfCircle(renderer, 300 / 5 + Crater::spaceshipX, 400 / 5, 60 / 5, windowcolor);
	DrawFilledRectangle(renderer, 230 / 5 + Crater::spaceshipX , 410 / 5, 20 / 5, 10 / 5, buttoncolor1);
	DrawFilledRectangle(renderer, 260 / 5 + Crater::spaceshipX , 410 / 5, 20 / 5, 10 / 5, buttoncolor2);
	DrawFilledCircle(renderer, 350 / 5 + Crater::spaceshipX, 415 / 5, 5 / 5, buttoncolor3);

	// Prezentacja renderera
	SDL_RenderPresent(renderer);
}
void DifCrater::UpdateSpaceShipPosition() {
    Crater::spaceshipX += 20; // Przesuwanie kamienia w prawo
    if (spaceshipX > SCREENWIDTH) { // Jeœli krater zniknie z ekranu, resetuj jego pozycjê
		spaceshipX = -50;
    }
}
void DifCrater::DrawSpaceShipBackground(SDL_Renderer* renderer) {

	SDL_Color skycolor = { 82, 95, 167, 255 };
	SDL_Color buttoncolor3 = { 45, 45, 250, 255 };
	DrawFilledRectangle(renderer,  Crater::spaceshipX, 20, 80, 80, skycolor);


}