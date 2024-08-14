#define SDL_MAIN_HANDLED
#define SCREEN_WIDTH  1920
#define SCREEN_HEIGHT  1080

#include <iostream>
#include <SDL.h>

typedef struct {
    SDL_Renderer *renderer;
    SDL_Window *window;
} Game;

int main() {
    Game game;
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << SDL_GetError() << std::endl;
        return -1;
    }

    game.window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    game.renderer = SDL_CreateRenderer(game.window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Event event;

    bool running = true;

    while(running) {
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                running = false;
            }


        }

        SDL_SetRenderDrawColor(game.renderer, 204, 51, 153, 255); //sets the colour
        SDL_RenderClear(game.renderer); //sets the colour of the background to be the colour on the line above

        SDL_SetRenderDrawColor(game.renderer, 34, 255, 0, 255);

        SDL_Rect rect(0, 0, 100, 100);


        SDL_RenderFillRect(game.renderer, &rect);

        SDL_RenderPresent(game.renderer); //updates the screen
    }

    SDL_DestroyRenderer(game.renderer);
    SDL_DestroyWindow(game.window);
    SDL_Quit();
    return 0;
}