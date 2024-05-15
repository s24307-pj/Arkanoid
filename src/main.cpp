#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include "headers/menu.h"
#include "headers/paddle.h"
#include "headers/ball.h"
#include "headers/brickManager.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0 || TTF_Init() == -1) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        std::cerr << "TTF could not initialize! TTF_Error: " << TTF_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Arkanoid",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!window || !renderer) {
        std::cerr << "Window or renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    Paddle paddle(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    BrickManager brickManager;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 16; j++) {
            brickManager.addBrick(j * 50, i * 20, 48, 18);
        }
    }

    bool quit = false, startGame = false;

    while (!quit) {
        showMenu(window, SDL_GetWindowSurface(window), quit, startGame, SCREEN_WIDTH, SCREEN_HEIGHT);

        while (!quit && startGame) {
            SDL_Event e;
            while (SDL_PollEvent(&e)) {
                if (e.type == SDL_QUIT) {
                    quit = true;
                } else if (e.type == SDL_KEYDOWN) {

                }
            }

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);

            brickManager.render(renderer);
            paddle.handleInput();
            paddle.update();
            paddle.render();
            SDL_RenderPresent(renderer);
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
