#ifndef BALL_H
#define BALL_H

#include <SDL.h>

class Ball {
private:
    SDL_Rect rect;
    int dx, dy;
    int speedX, speedY;
    const int maxSpeed = 1;
    bool isLaunched;
    int frameCounter = 0;
public:
    Ball(int x, int y, int w, int h, int initSpeedX = -1, int initSpeedY = -1);
    void update();
    void launch();
    void render(SDL_Renderer* renderer);
    void checkCollision(SDL_Rect paddle);
    SDL_Rect getRect();
    void changeDirectionBasedOnCollision(SDL_Rect& collider);

    void reset(int x, int y, int initSpeedX, int initSpeedY);
};


#endif
