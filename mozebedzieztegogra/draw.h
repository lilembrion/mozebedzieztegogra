#ifndef DRAW_H
#define DRAW_H

#include <cstdlib> 
#include <ctime>   
#define SCREENWIDTH 640
#define SCREENHEIGHT 480


#include <SDL.h>

void DrawTriangle(SDL_Renderer* renderer, int x1, int y1, int x2, int y2, int x3, int y3, SDL_Color color);
void DrawFilledTriangle(SDL_Renderer* renderer, int x1, int y1, int x2, int y2, int x3, int y3, SDL_Color color);
void DrawFilledRectangle(SDL_Renderer* renderer, int x, int y, int width, int height, SDL_Color color);
void DrawRotatedRect(SDL_Renderer* renderer, int x, int y, int width, int height, double angle, SDL_Color color);
void DrawFilledCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius, SDL_Color color);
void DrawFilledHalfCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius, SDL_Color color);
void DrawFilledEllipse(SDL_Renderer* renderer, int centerX, int centerY, int radiusX, int radiusY, SDL_Color color);

#endif // DRAW_H
