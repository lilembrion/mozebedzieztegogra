#include <SDL.h>
#include "frame1.h"
#include "sidejumpframe2.h"
#include "sidejumpframe3.h"
#include "character.h"

void Character::SideJumpAnimation(SDL_Renderer* renderer) {

	DrawBackgroundUpUp(renderer);
	DrawFrame1(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(200); 

	DrawBackgroundWalk(renderer);
	DrawSideJumpFrame2(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(200);

	DrawBackgroundSideUp(renderer);
	DrawSideJumpFrame3(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(250);

	DrawBackgroundSideUpUp(renderer);
	DrawSideJumpFrame2(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(200);
	/*
	DrawBackgroundUp(renderer);
	DrawFrame1(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(200);
	*/
}
