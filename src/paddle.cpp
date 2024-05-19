#include "headers/paddle.h"
#include <SDL_image.h>
#include <iostream>

Paddle::Paddle(SDL_Renderer* renderer, int screenWidth, int screenHeight, const std::string& texturePath)
        : renderer(renderer), screenWidth(screenWidth), screenHeight(screenHeight), velX(0.0f), lastUpdate(SDL_GetTicks()) {
    rect.w = 100;
    rect.h = 20;
    rect.x = (screenWidth - rect.w) / 2;
    rect.y = screenHeight - rect.h - 30;

    // Load texture
    texture = loadTexture(texturePath);
    if (!texture) {
        std::cerr << "Failed to load paddle texture! SDL_Error: " << SDL_GetError() << std::endl;
    }
}

Paddle::~Paddle() {
    SDL_DestroyTexture(texture);
}

SDL_Texture* Paddle::loadTexture(const std::string& path) {
    SDL_Texture* newTexture = IMG_LoadTexture(renderer, path.c_str());
    if (!newTexture) {
        std::cerr << "Unable to load texture " << path << "! SDL_image Error: " << IMG_GetError() << std::endl;
    }
    return newTexture;
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
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void Paddle::reset() {
    rect.x = (screenWidth - rect.w) / 2;
    rect.y = screenHeight - rect.h - 30;
    velX = 0;
}
