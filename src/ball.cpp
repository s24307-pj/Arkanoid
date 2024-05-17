#include <algorithm>
#include "headers/ball.h"

Ball::Ball(int x, int y, int w, int h, int initSpeedX, int initSpeedY)
        : rect{x, y, w, h}, dx(initSpeedX), dy(initSpeedY), speedX(initSpeedX), speedY(initSpeedY), isLaunched(false) {}

void Ball::launch() {
    isLaunched = true;
}

void Ball::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}

void Ball::checkCollision(SDL_Rect paddle) {
    if (rect.y + rect.h >= paddle.y && rect.y < paddle.y + paddle.h &&
        rect.x + rect.w > paddle.x && rect.x < paddle.x + paddle.w) {
        dy = -abs(dy);

        if (rect.x + rect.w / 2 < paddle.x + paddle.w / 2) {
            dx = -abs(dx);
        } else {
            dx = abs(dx);
        }
    }
}


SDL_Rect Ball::getRect() {
    return rect;
}

void Ball::update() {
    if (!isLaunched) return;

    frameCounter++;
    if (frameCounter % 10 == 0) {
        int potentialX = rect.x + std::clamp(dx, -maxSpeed, maxSpeed);
        int potentialY = rect.y + std::clamp(dy, -maxSpeed, maxSpeed);

        if (potentialX <= 0 || potentialX + rect.w >= 800) {
            dx = -dx;
            potentialX = rect.x;
        }

        if (potentialY <= 0) {
            dy = -dy;
            potentialY = rect.y;
        }

        rect.x = potentialX;
        rect.y = potentialY;

        if (rect.y >= 600) {
            rect.x = 400;
            rect.y = 300;
            dx = 2;
            dy = -2;
        }
    }
}


void Ball::changeDirectionBasedOnCollision(SDL_Rect& collider) {
    if ((rect.x < collider.x + collider.w && rect.x + rect.w > collider.x) &&
        (rect.y < collider.y + collider.h && rect.y + rect.h > collider.y)) {
        if (rect.x < collider.x || rect.x + rect.w > collider.x + collider.w) {
            dx = -dx;
        }
        if (rect.y < collider.y || rect.y + rect.h > collider.y + collider.h) {
            dy = -dy;
        }
    }
}

void Ball::reset(int x, int y, int initSpeedX = -1, int initSpeedY = -1) {
    rect.x = x;
    rect.y = y;
    dx = initSpeedX;
    dy = initSpeedY;
    isLaunched = false;
    frameCounter = 0;
}
