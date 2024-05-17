#include "headers/paddle.h"
#include <SDL.h>
#include <algorithm>

Paddle::Paddle(SDL_Renderer* renderer, int screenWidth, int screenHeight)
        : renderer(renderer), screenWidth(screenWidth), screenHeight(screenHeight), velX(0.0f), lastUpdate(SDL_GetTicks()) {
    rect.w = 100;
    rect.h = 20;
    rect.x = (screenWidth - rect.w) / 2;
    rect.y = screenHeight - rect.h - 30;
}

void Paddle::handleInput() {
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    velX = 0.0f;

    const float acceleration = 1.0f;

    if (currentKeyStates[SDL_SCANCODE_LEFT]) {
        velX -= acceleration;
    } else if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
        velX += acceleration;
    }

}

void Paddle::update() {
    Uint32 timeSinceLastFrame = SDL_GetTicks() - lastUpdate;

    float deltaTime = timeSinceLastFrame / 1500.0f;

    deltaTime = std::min(deltaTime, 0.05f);

    rect.x += velX * deltaTime * 1500;
    lastUpdate = SDL_GetTicks();

    if (rect.x < 0) {
        rect.x = 0;
    } else if (rect.x + rect.w > screenWidth) {
        rect.x = screenWidth - rect.w;
    }
}

SDL_Rect Paddle::getRect() {
    return rect;
}

void Paddle::render() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}

void Paddle::reset() {
    rect.x = (screenWidth - rect.w) / 2;
    rect.y = screenHeight - rect.h - 30;
    velX = 0;
}
