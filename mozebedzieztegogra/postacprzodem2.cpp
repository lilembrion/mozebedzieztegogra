#include <iostream>
#include "draw.h"
#include "jumpframe2.h"

#define PRZESUNIECIE 210
#define PX 30
#define SCREENWIDTH 640
#define SCREENHIGHT 480

void DrawJumpFrame2(SDL_Renderer* renderer) {

	// Kolor trójk¹ta
	SDL_Color bodycolor = { 201, 227, 154, 255 }; // jasnozielony
	SDL_Color nosecolor = { 164, 199, 97, 255 }; // ciemniejszy jasnozielony
	SDL_Color eyescolor1 = { 235, 235, 235, 255 }; // prawie bialy
	SDL_Color eyescolor2 = { 102, 131, 45, 255 }; // ciemnozielony
	SDL_Color shirtcolor = { 154, 63, 147, 255 }; // fiolet
	SDL_Color beltcolor = { 82, 32, 78, 255 }; // ciemny fiolet
	SDL_Color legscolor = { 40, 127, 103, 255 }; // morski
	SDL_Color shoescolor = { 30, 67, 56, 255 }; // ciemny morski
    SDL_Color groundcolor = { 128, 43, 11, 255 };
    SDL_Color skycolor = { 82, 95, 167, 255 };

	// Czyszczenie ekranu
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Czarny
	//SDL_RenderClear(renderer);

    //tlo
    //DrawFilledRectangle(renderer, 0, 0, SCREENWIDTH, SCREENWIDTH, skycolor);
    //DrawFilledRectangle(renderer, 0, SCREENHIGHT * 2 / 3, SCREENWIDTH, SCREENHIGHT * 2 / 3, groundcolor);

    //kopniete prostokaty
    //DrawRotatedRect(renderer, 280/5 + PX, 340/5 + PRZESUNIECIE, 160/5, 20/5, 180, bodycolor); //reka lewa
    //DrawRotatedRect(renderer, 337/5 + PX, 320/5 + PRZESUNIECIE, 150/5, 20/5, 0, bodycolor); //reka prawa


    // Rysowanie prostokata
    DrawFilledRectangle(renderer, 200/5 + PX, 70/5 + PRZESUNIECIE, 200/5, 130/5, bodycolor); //glowa
    DrawFilledRectangle(renderer, 290/5 + PX, 220/5 + PRZESUNIECIE, 20/5, 100/5, bodycolor); //szyja
    DrawFilledRectangle(renderer, 260/5 + PX, 310/5 + PRZESUNIECIE, 80/5, 180/5, shirtcolor); //koszulka
    DrawFilledRectangle(renderer, 240/5 + PX, 490/5 + PRZESUNIECIE, 120/5, 30/5, beltcolor); //pasek
    DrawFilledRectangle(renderer, 250/5 + PX, 520/5 + PRZESUNIECIE, 100/5, 160/5, legscolor); //spodnie
    DrawFilledRectangle(renderer, 240/5 + PX, 680/5 + PRZESUNIECIE, 120/5, 50/5, shoescolor); //buty
    DrawFilledRectangle(renderer, 285/5 + PX, 280/5 + PRZESUNIECIE, 30/5, 10/5, shoescolor); //obroza

    // Rysowanie trójk¹tow
    DrawFilledTriangle(renderer, 200/5 + PX, (800 - 520 - 80)/5 + PRZESUNIECIE, 
        300/5 + PX, (800 - 470 - 80)/5 + PRZESUNIECIE, 400/5 + PX, (800 - 520 - 80)/5 + PRZESUNIECIE, bodycolor); //broda
    DrawFilledTriangle(renderer, 200/5 + PX, 110/5 + PRZESUNIECIE, 200/5 + PX, 150/5 + PRZESUNIECIE, 
        120/5 + PX, 50/5 + PRZESUNIECIE, bodycolor); //ucho lewe
    DrawFilledTriangle(renderer, 400/5 + PX, 110/5 + PRZESUNIECIE, 400/5 + PX, 150/5 + PRZESUNIECIE,
        (600 - 120)/5 + PX, 50/5 + PRZESUNIECIE, bodycolor); //ucho prawe
    DrawFilledTriangle(renderer, 290/5 + PX, 170/5 + PRZESUNIECIE, 290/5 + PX, 190/5 + PRZESUNIECIE,
        340/5 + PX, 180/5 + PRZESUNIECIE, nosecolor); //nose
    DrawFilledTriangle(renderer, 285/5 + PX, 280/5 + PRZESUNIECIE, 285/5 + PX, 290/5 + PRZESUNIECIE,
        250/5 + PX, 285/5 + PRZESUNIECIE, beltcolor); //kolec lewy
    DrawFilledTriangle(renderer, 315/5 + PX, 280/5 + PRZESUNIECIE, 315/5 + PX, 290/5 + PRZESUNIECIE,
        350/5 + PX, 285/5 + PRZESUNIECIE, beltcolor); //kolec prawy

    //kolka
    /*
    DrawFilledCircle(renderer, 240, 150, 10, eyescolor1); //oko lewe
    DrawFilledCircle(renderer, 240, 150, 5, eyescolor2);
    DrawFilledCircle(renderer, 360, 150, 10, eyescolor1); //oko prawe
    DrawFilledCircle(renderer, 360, 150, 5, eyescolor2);
    */

    DrawFilledRectangle(renderer, 230/5 + PX, 148/5 + PRZESUNIECIE, 20/5, 3/5, eyescolor2); //oko zamkkniete
    DrawFilledRectangle(renderer, 350/5 + PX, 148/5 + PRZESUNIECIE, 20/5, 3/5, eyescolor2); //oko zamkkniete

	// Prezentacja renderera
	SDL_RenderPresent(renderer);
}