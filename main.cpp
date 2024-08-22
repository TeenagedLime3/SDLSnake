#define SDL_MAIN_HANDLED
#define UPDATE_INTERVAL 0.5f

#include <iostream>
#include <SDL.h>
#include <numeric>

#include "Snake.h"

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

    SDL_DisplayMode dm;

    if (SDL_GetDesktopDisplayMode(0, &dm) != 0) {
        SDL_Log("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
        return 1;
    }

    const int WINDOW_WIDTH = dm.w/2;
    const int WINDOW_HEIGHT = dm.h/2;

    game.window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    game.renderer = SDL_CreateRenderer(game.window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Event event;

    bool running = true;

    int STEP_SIZE = std::gcd(WINDOW_WIDTH, WINDOW_HEIGHT);

    Snake* snake = new Snake(WINDOW_WIDTH / (float) STEP_SIZE, WINDOW_HEIGHT / (float) STEP_SIZE);

    Uint32 lastFrameTime = SDL_GetTicks();
    float accumulatedTime = 0.0f;

    while(running) {
        Uint32 currentFrameTime = SDL_GetTicks();

        accumulatedTime += (currentFrameTime - lastFrameTime) / 1000.0f; // in seconds

        lastFrameTime = currentFrameTime;

        // input
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                running = false;
            }
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_UP: {
                        snake->changeDirection(Direction::UP);
                        break;
                    }
                    case SDLK_DOWN: {
                        snake->changeDirection(Direction::DOWN);
                        break;
                    }
                    case SDLK_LEFT: {
                        snake->changeDirection(Direction::LEFT);
                        break;
                    }
                    case SDLK_RIGHT: {
                        snake->changeDirection(Direction::RIGHT);
                        break;
                    }
                }
            }
        }

        // update
        while(accumulatedTime > UPDATE_INTERVAL) {
            snake->moveSnake();
            accumulatedTime -= UPDATE_INTERVAL;
        }

        // render

        SDL_SetRenderDrawColor(game.renderer, 15, 236, 241, 255); //sets the colour
        SDL_RenderClear(game.renderer); //sets the colour of the background to be the colour on the line above

        SDL_SetRenderDrawColor(game.renderer, 241, 82, 15, 255); //head colour

        SDL_Rect head(snake->getHeadXLocation() * STEP_SIZE, snake->getHeadYLocation() * STEP_SIZE, STEP_SIZE, STEP_SIZE); //head
        SDL_RenderFillRect(game.renderer, &head);

        for(int i = 0; i < snake->getLength(); i++) {

            if(i % 2 == 0) {
                SDL_SetRenderDrawColor(game.renderer, 61, 241, 15, 255);
            } else {
                SDL_SetRenderDrawColor(game.renderer, 174, 241, 15, 255);
            }
            SDL_Rect tailSection(snake->getTailXLocation(i) * STEP_SIZE, snake->getTailYLocation(i) * STEP_SIZE, STEP_SIZE , STEP_SIZE); //creates the tail sections
            SDL_RenderFillRect(game.renderer, &tailSection);
        }

        SDL_RenderPresent(game.renderer); //updates the screen
    }

    SDL_DestroyRenderer(game.renderer);
    SDL_DestroyWindow(game.window);
    SDL_Quit();
    return 0;
}