#ifndef PADDLE_H
#define PADDLE_H

#include <SDL.h>
#include "ball.h"

class Paddle {
public:
    Paddle(SDL_Renderer* renderer, int screenWidth, int screenHeight);
    void handleInput();
    void update();
    void render();

private:
    SDL_Renderer* renderer;
    SDL_Rect rect;
    int screenWidth;
    int screenHeight;
    float velX;
    Uint32 lastUpdate;
};

#endif
