#ifndef BRICK_MANAGER_H
#define BRICK_MANAGER_H

#include "ball.h"
#include "brick.h"
#include <vector>

class BrickManager {
private:
    std::vector<Brick> bricks;
public:
    BrickManager();
    void addBrick(int x, int y, int w, int h);
    void render(SDL_Renderer* renderer);
};

#endif
