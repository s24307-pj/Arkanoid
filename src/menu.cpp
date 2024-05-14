#include "headers/menu.h"
#include <SDL_ttf.h>

void showMenu(SDL_Window* window, SDL_Surface* screenSurface, bool& quit, bool& startGame, int SCREEN_WIDTH, int SCREEN_HEIGHT ) {
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));

    TTF_Font* font = TTF_OpenFont("../assets/fonts/dancing-script/DancingScript-Regular.ttf", 24);

    SDL_Color textColor = {255, 255, 255};

    SDL_Surface* textPlay = TTF_RenderText_Solid(font, "Start a game", textColor);
    SDL_Surface* textQuit = TTF_RenderText_Solid(font, "Quit", textColor);

    SDL_Rect playButtonRect = { (SCREEN_WIDTH - textPlay->w) / 2, (SCREEN_HEIGHT - textPlay->h) / 2 - 50, textPlay->w, textPlay->h };
    SDL_BlitSurface(textPlay, NULL, screenSurface, &playButtonRect);

    SDL_Rect quitButtonRect = { (SCREEN_WIDTH - textQuit->w) / 2, (SCREEN_HEIGHT - textQuit->h) / 2 + 50, textQuit->w, textQuit->h };
    SDL_BlitSurface(textQuit, NULL, screenSurface, &quitButtonRect);

    SDL_UpdateWindowSurface(window);

    SDL_FreeSurface(textPlay);
    SDL_FreeSurface(textQuit);
    TTF_CloseFont(font);

    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            quit = true;
        } else if (e.type == SDL_KEYDOWN) {
        } else if (e.type == SDL_MOUSEBUTTONDOWN) {
            int x, y;
            SDL_GetMouseState(&x, &y);

            if (x > playButtonRect.x && x < playButtonRect.x + playButtonRect.w &&
                y > playButtonRect.y && y < playButtonRect.y + playButtonRect.h) {
                startGame = true;
            }

            if (x > quitButtonRect.x && x < quitButtonRect.x + quitButtonRect.w &&
                y > quitButtonRect.y && y < quitButtonRect.y + quitButtonRect.h) {
                quit = true;
            }
        }
    }
}
