#include <SDL.h>
#include <iostream>
#include "draw.h"
#include "sidejumpframe2.h"

#define PRZESUNIECIE 210
#define PX 30
#define SCREENWIDTH 640
#define SCREENHIGHT 480
#define SKOK2 -50
#define BOK2 0

void DrawSideJumpFrame3(SDL_Renderer* renderer) {

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
        //DrawRotatedRect(renderer, 337, 320, 150, 20, 120, bodycolor); //reka prawa
    DrawRotatedRect(renderer, 285/5 + PX +BOK2, 520/5 + PRZESUNIECIE + SKOK2, 50/5, 180/5, -10, legscolor); //spodnie prawa
    DrawRotatedRect(renderer, 250/5 + PX + BOK2, 500/5 + PRZESUNIECIE + SKOK2, 50/5, 190/5, 20, legscolor); //spodnie lewa
    DrawRotatedRect(renderer, 185/5 + PX + BOK2, 680/5 + PRZESUNIECIE + SKOK2, 60/5, 50/5, 20, shoescolor); //buty
    DrawRotatedRect(renderer, 315/5 + PX + BOK2, 695/5 + PRZESUNIECIE + SKOK2, 60/5, 50/5, -10, shoescolor); //buty




    // Rysowanie prostokata
    DrawFilledRectangle(renderer, 220/5 + PX + BOK2, 70/5 + PRZESUNIECIE + SKOK2, 200/5, 130/5, bodycolor); //glowa
    DrawFilledRectangle(renderer, 290/5 + PX + BOK2, 220/5 + PRZESUNIECIE + SKOK2, 20/5, 100/5, bodycolor); //szyja
    DrawFilledRectangle(renderer, 260/5 + PX + BOK2, 310/5 + PRZESUNIECIE + SKOK2, 80/5, 180/5, shirtcolor); //koszulka
    DrawFilledRectangle(renderer, 240/5 + PX + BOK2, 490/5 + PRZESUNIECIE + SKOK2, 120/5, 30/5, beltcolor); //pasek
    //DrawFilledRectangle(renderer, 250, 520, 100, 180, legscolor); //spodnie
    //DrawFilledRectangle(renderer, 240, 700, 120, 50, shoescolor); //buty
    DrawFilledRectangle(renderer, 285/5 + PX + BOK2, 280/5 + PRZESUNIECIE + SKOK2, 30/5, 10/5, shoescolor); //obroza
    //DrawFilledRectangle(renderer, 270, 330, 20, 150, bodycolor); //reka lewa

    // Rysowanie trójk¹tow
    DrawFilledTriangle(renderer, 220/5 + PX + BOK2, (800 - 520 - 80)/5 + PRZESUNIECIE + SKOK2,
        350/5 + PX + BOK2, (800 - 470 - 80)/5 + PRZESUNIECIE + SKOK2, 420/5 + PX + BOK2, (800 - 520 - 80)/5 + PRZESUNIECIE + SKOK2, bodycolor); //broda
    DrawFilledTriangle(renderer, 220/5 + PX + BOK2, 110/5 + PRZESUNIECIE + SKOK2, 220/5 + PX + BOK2, 150/5 + PRZESUNIECIE + SKOK2,
        140/5 + PX + BOK2, 50/5 + PRZESUNIECIE + SKOK2, bodycolor); //ucho lewe
    DrawFilledTriangle(renderer, 400/5 + PX + BOK2, 110/5 + PRZESUNIECIE + SKOK2, 400/5 + PX + BOK2, 150/5 + PRZESUNIECIE + SKOK2,
        (600 - 120)/5 + PX + BOK2, 50/5 + PRZESUNIECIE + SKOK2, bodycolor); //ucho prawe
    DrawFilledTriangle(renderer, 310/5 + PX + BOK2, 170/5 + PRZESUNIECIE + SKOK2, 310/5 + PX + BOK2, 190/5 + PRZESUNIECIE + SKOK2,
        360/5 + PX + BOK2, 180/5 + PRZESUNIECIE + SKOK2, nosecolor); //nose
    DrawFilledTriangle(renderer, 285/5 + PX + BOK2, 280/5 + PRZESUNIECIE + SKOK2, 285/5 + PX + BOK2, 290/5 + PRZESUNIECIE + SKOK2,
        250/5 + PX + BOK2, 285/5 + PRZESUNIECIE + SKOK2, beltcolor); //kolec lewy
    DrawFilledTriangle(renderer, 315/5 + PX + BOK2, 280/5 + PRZESUNIECIE + SKOK2, 315/5 + PX + BOK2, 290/5 + PRZESUNIECIE + SKOK2,
        350/5 + PX + BOK2, 285/5 + PRZESUNIECIE + SKOK2, beltcolor); //kolec prawy

    //kolka
    /*
    DrawFilledCircle(renderer, 260, 150, 10, eyescolor1); //oko lewe
    DrawFilledCircle(renderer, 260, 150, 5, eyescolor2);
    DrawFilledCircle(renderer, 380, 150, 10, eyescolor1); //oko prawe
    DrawFilledCircle(renderer, 380, 150, 5, eyescolor2);
    */

    DrawFilledRectangle(renderer, 250/5 + PX + BOK2, 148/5 + PRZESUNIECIE + SKOK2, 20/5, 3/5, eyescolor2); //oko zamkkniete
    DrawFilledRectangle(renderer, 370/5 + PX + BOK2, 148/5 + PRZESUNIECIE + SKOK2, 20/5, 3/5, eyescolor2); //oko zamkkniete


    //kopniety prostokat na wierzchu
    DrawRotatedRect(renderer, 270/5 + PX + BOK2, 330/5 + PRZESUNIECIE + SKOK2, 20/5, 150/5, -30, bodycolor); //reka lewa

    // Prezentacja renderera
    SDL_RenderPresent(renderer);
}

