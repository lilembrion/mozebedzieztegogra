#include <SDL.h>
#include <iostream>
#include "draw.h"
#include "sidejumpframe2.h"

#define PRZESUNIECIE 210
#define PX 30
#define SCREENWIDTH 640
#define SCREENHIGHT 480
#define SKOK -30

void DrawSideJumpFrame2(SDL_Renderer* renderer) {

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
    DrawRotatedRect(renderer, 337/5 + PX, 320/5 + PRZESUNIECIE + SKOK, 150/5, 20/5, 50, bodycolor); //reka prawa
    DrawRotatedRect(renderer, 285/5 + PX, 520/5 + PRZESUNIECIE + SKOK, 50/5, 190/5, -20, legscolor); //spodnie prawa
    DrawRotatedRect(renderer, 250/5 + PX, 510/5 + PRZESUNIECIE + SKOK, 50/5, 190/5, 10, legscolor); //spodnie lewa
    DrawRotatedRect(renderer, 215/5 + PX, 695/5 + PRZESUNIECIE + SKOK, 60/5, 50/5, 10, shoescolor); //buty
    DrawRotatedRect(renderer, 348/5 + PX, 697/5 + PRZESUNIECIE + SKOK, 60/5, 50/5, -20, shoescolor); //buty




    // Rysowanie prostokata
    DrawFilledRectangle(renderer, 220/5 + PX, 70/5 + PRZESUNIECIE + SKOK, 200/5, 130/5, bodycolor); //glowa
    DrawFilledRectangle(renderer, 290/5 + PX, 220/5 + PRZESUNIECIE + SKOK, 20/5, 100/5, bodycolor); //szyja
    DrawFilledRectangle(renderer, 260/5 + PX, 310/5 + PRZESUNIECIE + SKOK, 80/5, 180/5, shirtcolor); //koszulka
    DrawFilledRectangle(renderer, 240/5 + PX, 490/5 + PRZESUNIECIE + SKOK, 120/5, 30/5, beltcolor); //pasek
    //DrawFilledRectangle(renderer, 250, 520, 100, 180, legscolor); //spodnie
    //DrawFilledRectangle(renderer, 240, 700, 120, 50, shoescolor); //buty
    DrawFilledRectangle(renderer, 285/5 + PX, 280/5 + PRZESUNIECIE + SKOK, 30/5, 10/5, shoescolor); //obroza
    //DrawFilledRectangle(renderer, 270, 330, 20, 150, bodycolor); //reka lewa

    // Rysowanie trójk¹tow
    DrawFilledTriangle(renderer, 220/5 + PX, (800 - 520 - 80)/5 + PRZESUNIECIE + SKOK, 350/5 + PX,
        (800 - 470 - 80)/5 + PRZESUNIECIE + SKOK, 420/5 + PX, (800 - 520 - 80)/5 + PRZESUNIECIE + SKOK, bodycolor); //broda
    DrawFilledTriangle(renderer, 220/5 + PX, 110/5 + PRZESUNIECIE + SKOK, 220/5 + PX, 150/5 + PRZESUNIECIE + SKOK,
        140/5 + PX, 50/5 + PRZESUNIECIE + SKOK, bodycolor); //ucho lewe
    DrawFilledTriangle(renderer, 400/5 + PX, 110/5 + PRZESUNIECIE + SKOK, 400/5 + PX, 150/5 + PRZESUNIECIE + SKOK,
        (600 - 120)/5 + PX, 50/5 + PRZESUNIECIE + SKOK, bodycolor); //ucho prawe
    DrawFilledTriangle(renderer, 310/5 + PX, 170/5 + PRZESUNIECIE + SKOK, 310/5 + PX, 190/5 + PRZESUNIECIE + SKOK,
        360/5 + PX, 180/5 + PRZESUNIECIE + SKOK, nosecolor); //nose
    DrawFilledTriangle(renderer, 285/5 + PX, 280/5 + PRZESUNIECIE + SKOK, 285/5 + PX, 290/5 + PRZESUNIECIE + SKOK,
        250/5 + PX, 285/5 + PRZESUNIECIE + SKOK, beltcolor); //kolec lewy
    DrawFilledTriangle(renderer, 315/5 + PX, 280/5 + PRZESUNIECIE + SKOK, 315/5 + PX, 290/5 + PRZESUNIECIE + SKOK,
        350/5 + PX, 285/5 + PRZESUNIECIE + SKOK, beltcolor); //kolec prawy

    //kolka

    DrawFilledCircle(renderer, 260/5 + PX, 150/5 + PRZESUNIECIE + SKOK, 10/5, eyescolor1); //oko lewe
    DrawFilledCircle(renderer, 260/5 + PX, 150/5 + PRZESUNIECIE + SKOK, 5/5, eyescolor2);
    DrawFilledCircle(renderer, 380/5 + PX, 150/5 + PRZESUNIECIE + SKOK, 10/5, eyescolor1); //oko prawe
    DrawFilledCircle(renderer, 380/5 + PX, 150/5 + PRZESUNIECIE + SKOK, 5/5, eyescolor2);

    //kopniety prostokat na wierzchu
    DrawRotatedRect(renderer, 270/5 + PX, 330/5 + PRZESUNIECIE + SKOK, 20/5, 150/5, 30, bodycolor); //reka lewa

    // Prezentacja renderera
    SDL_RenderPresent(renderer);
}

