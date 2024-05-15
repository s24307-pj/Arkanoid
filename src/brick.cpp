#include "headers/brick.h"

Brick::Brick(int x, int y, int w, int h) {
    rect = {x, y, w, h};
}

void Brick::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}
