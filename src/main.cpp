#include <iostream>

// for initializing and shutdown functions
#include <SDL.h>
// for rendering images and graphics on screen
#include <SDL_image.h>
// for using SDL_Delay() functions
#include <SDL_timer.h>

const short WINDOW_WIDTH = 640;
const short WINDOW_HEIGHT = 480;

const char* WINDOW_TITLE = "SDL2 GAME";

int main(int argc, char **argv)
{
    // returns zero on success else non-zero
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        fprintf(stdin, "Error initializing SDL Video: %s\n", SDL_GetError());
    }
    if (!IMG_Init(IMG_INIT_PNG))
    {
        fprintf(stdin, "Error initializing IMG_Init: %s\n", SDL_GetError());
    }
    SDL_Window* window = SDL_CreateWindow(
                                        WINDOW_TITLE,
                                        SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED,
                                        WINDOW_WIDTH, WINDOW_HEIGHT, 0
    );

    if (window == NULL)
    {
        fprintf(stdin, "Error creating window: %s\n", SDL_GetError());
    }
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Event event;

    bool gameRunning = true;

    while (gameRunning) 
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                gameRunning = false;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}