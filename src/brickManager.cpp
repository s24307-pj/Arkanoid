#include "headers/brickManager.h"
#include "headers/ball.h"

BrickManager::BrickManager() {}

void BrickManager::addBrick(int x, int y, int w, int h) {
    bricks.emplace_back(x, y, w, h);
}

void BrickManager::render(SDL_Renderer* renderer) {
    for (auto& brick : bricks) {
        brick.render(renderer);
    }
}

