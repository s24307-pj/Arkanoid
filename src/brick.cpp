#include "headers/brick.h"

Brick::Brick(int x, int y, int w, int h) {
    rect = {x, y, w, h};
    destroyed = false;
}

void Brick::render(SDL_Renderer* renderer) {
    if (!destroyed) {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect);
    }
}

bool Brick::isDestroyed() {
    return destroyed;
}

void Brick::destroy() {
    destroyed = true;
}

SDL_Rect Brick::getRect() {
    return rect;
}

void Brick::reset() {
    destroyed = false;
}
