#ifndef BRICK_H
#define BRICK_H

#include <SDL.h>

class Brick {
private:
    SDL_Rect rect;
public:
    Brick(int x, int y, int w, int h);
    void render(SDL_Renderer* renderer);
};

#endif
