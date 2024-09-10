#include <iostream>
#include "draw.h"
#include "frame1.h"
#include "character.h"

#define PX 30
#define SCREENWIDTH 640
#define SCREENHIGHT 480
#define BOK 0

void DrawFrame1(SDL_Renderer* renderer) {

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
    //DrawRotatedRect(renderer, 280, 330, 150, 20, 120, bodycolor); //reka lewa
    DrawRotatedRect(renderer, 337/5 + PX + BOK, 320/5 + 210, 150/5, 20/5, 80, bodycolor); //reka prawa


    // Rysowanie prostokata
    DrawFilledRectangle(renderer, 220/5 + PX + BOK, 70/5 + 210, 200/5, 130/5, bodycolor); //glowa
    DrawFilledRectangle(renderer, 290/5 + PX + BOK, 220/5 + 210, 20/5, 100/5, bodycolor); //szyja
    DrawFilledRectangle(renderer, 260/5 + PX + BOK, 310/5 + 210, 80/5, 180/5, shirtcolor); //koszulka
    DrawFilledRectangle(renderer, 240/5 + PX + BOK, 490/5 + 210, 120/5, 30/5, beltcolor); //pasek
    DrawFilledRectangle(renderer, 250/5 + PX + BOK, 520/5 + 210, 100/5, 180/5, legscolor); //spodnie
    DrawFilledRectangle(renderer, 240/5 + PX + BOK, 700/5 + 210, 120/5, 50/5, shoescolor); //buty
    DrawFilledRectangle(renderer, 285/5 + PX + BOK, 280/5 + 210, 30/5, 10/5, shoescolor); //obroza
    DrawFilledRectangle(renderer, 270/5 + PX + BOK, 330/5 + 210, 20/5, 150/5, bodycolor); //reka lewa

    // Rysowanie trójk¹tow
    DrawFilledTriangle(renderer, 220/5 + PX + BOK, (800 - 520 - 80)/5 + 210, 350/5 + PX + BOK, (800 - 470 - 80)/5 + 210,
        420/5 + PX + BOK, (800 - 520 - 80)/5 + 210, bodycolor); //broda
    DrawFilledTriangle(renderer, 220/5 + PX + BOK, 110/5 + 210, 220/5 + PX + BOK, 150/5 + 210, 140/5 + PX + BOK, 50/5 + 210, bodycolor); //ucho lewe
    DrawFilledTriangle(renderer, 400/5 + PX + BOK, 110/5 + 210, 400/5 + PX + BOK, 150/5 + 210, (600 - 120)/5 + PX + BOK, 50/5 + 210, bodycolor); //ucho prawe
    DrawFilledTriangle(renderer, 310/5 + PX + BOK, 170/5 + 210, 310/5 + PX + BOK, 190/5 + 210, 360/5 + PX + BOK, 180/5 + 210, nosecolor); //nose
    DrawFilledTriangle(renderer, 285/5 + PX + BOK, 280/5 + 210, 285/5 + PX + BOK, 290/5 + 210, 250/5 + PX + BOK, 285/5 + 210, beltcolor); //kolec lewy
    DrawFilledTriangle(renderer, 315/5 + PX + BOK, 280/5 + 210, 315/5 + PX + BOK, 290/5 + 210, 350/5 + PX + BOK, 285/5 + 210, beltcolor); //kolec prawy

    //kolka

    DrawFilledCircle(renderer, 260/5 + PX + BOK, 150/5 + 210, 10/5, eyescolor1); //oko lewe
    DrawFilledCircle(renderer, 260/5 + PX + BOK, 150/5 + 210, 5/5, eyescolor2);
    DrawFilledCircle(renderer, 380/5 + PX + BOK, 150/5 + 210, 10/5, eyescolor1); //oko prawe
    DrawFilledCircle(renderer, 380/5 + PX + BOK, 150/5 + 210, 5/5, eyescolor2);


    // Prezentacja renderera
    SDL_RenderPresent(renderer);
}