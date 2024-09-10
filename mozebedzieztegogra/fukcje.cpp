#include "draw.h"
#include <cmath>
#include <vector>
#include <algorithm>

void DrawTriangle(SDL_Renderer* renderer, int x1, int y1, int x2, int y2, int x3, int y3, SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    SDL_RenderDrawLine(renderer, x2, y2, x3, y3);
    SDL_RenderDrawLine(renderer, x3, y3, x1, y1);
}

void DrawFilledTriangle(SDL_Renderer* renderer, int x1, int y1, int x2, int y2, int x3, int y3, SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    int minX = std::min({ x1, x2, x3 });
    int maxX = std::max({ x1, x2, x3 });
    int minY = std::min({ y1, y2, y3 });
    int maxY = std::max({ y1, y2, y3 });

    for (int y = minY; y <= maxY; y++) {
        for (int x = minX; x <= maxX; x++) {
            int w1 = (x - x1) * (y2 - y1) - (y - y1) * (x2 - x1);
            int w2 = (x - x2) * (y3 - y2) - (y - y2) * (x3 - x2);
            int w3 = (x - x3) * (y1 - y3) - (y - y3) * (x1 - x3);

            if ((w1 >= 0 && w2 >= 0 && w3 >= 0) || (w1 <= 0 && w2 <= 0 && w3 <= 0)) {
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }
    }
}

void DrawFilledRectangle(SDL_Renderer* renderer, int x, int y, int width, int height, SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect rect = { x, y, width, height };
    SDL_RenderFillRect(renderer, &rect);
}

void DrawRotatedRect(SDL_Renderer* renderer, int x, int y, int width, int height, double angle, SDL_Color color) {
    double radians = angle * M_PI / 180.0;
    SDL_Point points[4];
    points[0] = { x, y };
    points[1] = { static_cast<int>(x + width * cos(radians)), static_cast<int>(y + width * sin(radians)) };
    points[2] = { static_cast<int>(x + width * cos(radians) - height * sin(radians)), static_cast<int>(y + width * sin(radians) + height * cos(radians)) };
    points[3] = { static_cast<int>(x - height * sin(radians)), static_cast<int>(y + height * cos(radians)) };

    SDL_RenderDrawLines(renderer, points, 4);
    SDL_RenderDrawLine(renderer, points[3].x, points[3].y, points[0].x, points[0].y);

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    int minX = std::min({ points[0].x, points[1].x, points[2].x, points[3].x });
    int maxX = std::max({ points[0].x, points[1].x, points[2].x, points[3].x });
    int minY = std::min({ points[0].y, points[1].y, points[2].y, points[3].y });
    int maxY = std::max({ points[0].y, points[1].y, points[2].y, points[3].y });

    for (int y = minY; y <= maxY; ++y) {
        std::vector<int> intersections;
        for (int i = 0; i < 4; ++i) {
            SDL_Point p1 = points[i];
            SDL_Point p2 = points[(i + 1) % 4];
            if ((p1.y <= y && p2.y > y) || (p2.y <= y && p1.y > y)) {
                int x = p1.x + (y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y);
                intersections.push_back(x);
            }
        }
        std::sort(intersections.begin(), intersections.end());
        for (size_t i = 0; i < intersections.size(); i += 2) {
            if (i + 1 < intersections.size()) {
                SDL_RenderDrawLine(renderer, intersections[i], y, intersections[i + 1], y);
            }
        }
    }
}

void DrawFilledCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius, SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    for (int w = 0; w < radius * 2; w++) {
        for (int h = 0; h < radius * 2; h++) {
            int dx = radius - w;
            int dy = radius - h;
            if ((dx * dx + dy * dy) <= (radius * radius)) {
                SDL_RenderDrawPoint(renderer, centerX + dx, centerY + dy);
            }
        }
    }
}

// Funkcja rysuj¹ca wype³nion¹ górn¹ po³owê ko³a
void DrawFilledHalfCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius, SDL_Color color) {
    // Ustawienie koloru rysowania
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    // Rysowanie wype³nionej górnej po³owy ko³a
    for (int y = 0; y <= radius; ++y) {
        for (int x = -radius; x <= radius; ++x) {
            if (x * x + y * y <= radius * radius) {
                SDL_RenderDrawPoint(renderer, centerX + x, centerY - y);
            }
        }
    }
}
// Funkcja rysuj¹ca wype³nion¹ elipsê
void DrawFilledEllipse(SDL_Renderer* renderer, int centerX, int centerY, int radiusX, int radiusY, SDL_Color color) {
    // Ustawienie koloru rysowania
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    // Rysowanie wype³nionej elipsy
    for (int y = -radiusY; y <= radiusY; ++y) {
        for (int x = -radiusX; x <= radiusX; ++x) {
            if ((x * x * radiusY * radiusY + y * y * radiusX * radiusX) <= (radiusX * radiusX * radiusY * radiusY)) {
                SDL_RenderDrawPoint(renderer, centerX + x, centerY + y);
            }
        }
    }
}
