#ifndef PADDLE_H
#define PADDLE_H

#include <SDL.h>
#include <string>

class Paddle {
public:
    Paddle(SDL_Renderer* renderer, int screenWidth, int screenHeight, const std::string& texturePath);
    ~Paddle();
    void handleInput();
    void update();
    void render();
    SDL_Rect getRect();
    void reset();

private:
    SDL_Texture* loadTexture(const std::string& path);
    SDL_Renderer* renderer;
    SDL_Rect rect;
    SDL_Texture* texture;
    int screenWidth;
    int screenHeight;
    float velX;
    Uint32 lastUpdate;
};

#endif
