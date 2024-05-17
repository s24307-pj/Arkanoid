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

void BrickManager::checkCollision(Ball& ball) {
    for (auto& brick : bricks) {
        if (!brick.isDestroyed()) {
            SDL_Rect brickRect = brick.getRect();
            SDL_Rect ballRect = ball.getRect();

            if (ballRect.x + ballRect.w > brickRect.x &&
                ballRect.x < brickRect.x + brickRect.w &&
                ballRect.y + ballRect.h > brickRect.y &&
                ballRect.y < brickRect.y + brickRect.h) {
                brick.destroy();
                ball.changeDirectionBasedOnCollision(brickRect);
            }
        }
    }
}

void BrickManager::reset() {
    for (auto& brick : bricks) {
        brick.reset();
    }
}
