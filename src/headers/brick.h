#ifndef BRICK_H
#define BRICK_H

#include <SDL.h>

class Brick {
private:
    SDL_Rect rect;
    bool destroyed;
public:
    Brick(int x, int y, int w, int h);
    void render(SDL_Renderer* renderer);
    bool isDestroyed();
    void destroy();
    SDL_Rect getRect();

    void reset();
};

#endif
