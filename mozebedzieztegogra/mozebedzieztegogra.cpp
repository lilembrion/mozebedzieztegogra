#include <SDL.h>
#include <iostream>
#include <vector>
#include "draw.h"
#include "character.h"
#include "crater.h"
#include "background.h"
#include "gwiazdki.h"

#define PKY 330

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Nie można zainicjalizować SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Animation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREENWIDTH, SCREENHEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Nie można utworzyć okna: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Nie można utworzyć renderera: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    srand(static_cast<unsigned int>(time(0)));

    bool running = true;
    bool keyPressed = false;
    bool spacePressed = false;
    SDL_Event event;

    Character character(renderer);
    Crater crater{ SCREENWIDTH, PKY, 0 };
    Background background;
    Crater* difcrater = new DifCrater{ 50, 50, 0};
    Crater* copiedCrater = nullptr; // skopiowany krater
    Gwiazdki gwiazdki;

    // Rysowanie tła
    background.DrawBackground(renderer);
    //character.~Character();

    while (running) {

        keyPressed = false; // Resetowanie flagi na początku każdej iteracji
        spacePressed = false; // Resetowanie flagi na początku każdej iteracji

        while (SDL_PollEvent(&event)) {

            if (event.type == SDL_QUIT) {
                running = false;
            }

            else if (event.type == SDL_KEYDOWN) {
                keyPressed = true; // Ustawienie flagi, gdy klawisz jest wciśnięty

                if (event.key.keysym.sym == SDLK_RIGHT) { 
                    character.WalkAnimation(renderer);
                }

                if (event.key.keysym.sym == SDLK_SPACE) {
                    spacePressed = true;
                    gwiazdki.Draw(renderer);
                    character.SideJumpAnimation(renderer); // Wywołanie metody na obiekcie
                }

                // Aktualizacja i rysowanie krateru
                crater.UpdateCraterPosition();
                crater.DrawBackground(renderer);
                crater.DrawCrater(renderer);
                difcrater->UpdateSpaceShipPosition();
                difcrater->DrawSpaceShipBackground(renderer);
                difcrater->DrawSpaceShip(renderer);

                if (copiedCrater == nullptr) {
                    copiedCrater = new Crater(SCREENWIDTH+SCREENWIDTH/2, crater.craterY, 0);
                }

                if (copiedCrater != nullptr) {
                    copiedCrater->UpdateCraterPosition();
                    copiedCrater->DrawBackground(renderer);
                    copiedCrater->DrawCrater(renderer);
                }
                
            }
        }

        // Jeśli żaden klawisz nie jest wciśnięty, wywołaj JumpAnimation
        if (!keyPressed) {
            character.JumpAnimation(renderer);
        }

        background* renderer;

        if (crater.craterX >= 40 && crater.craterX <= 100 && !spacePressed) {
            running = false;
        }
        // Prezentacja renderera
        SDL_RenderPresent(renderer);
        // Dodanie opóźnienia
        //SDL_Delay(16); // Opóźnienie 16 ms (około 60 FPS)
    }
    //character.DrawGameOver(renderer);
    character.~Character();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}