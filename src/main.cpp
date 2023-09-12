#include <iostream>
#include <vector>
#include <cmath>

// for initializing and shutdown functions
#include <SDL.h>
// for rendering images and graphics on screen
#include <SDL_image.h>

#include "renderwindow.hpp"
#include "entity.hpp"
#include "vector2f.hpp"
#include "time.hpp"

const short WINDOW_WIDTH = 1920;
const short WINDOW_HEIGHT = 1080;
const char* WINDOW_TITLE = "SDL2 GAME";

const char* IDLE_TEXTURE_PATH = "graphics/Samurai/Idle.png";
const char* BACKGROUND_TEXTURE_PATH = "graphics/Wano/firstBg.png";

bool init();

int main(int argc, char **argv)
{
    if (!init()) {
        return 0;
    }
    RendererWindow rendererWindow(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);

    SDL_Event event;

    bool gameRunning = true;

    SDL_Texture* texture = rendererWindow.loadTexture(IDLE_TEXTURE_PATH);
    SDL_Texture* background_texture = rendererWindow.loadTexture(BACKGROUND_TEXTURE_PATH);

    std::vector<Entity> entities = {
        Entity(Vector2f(0, 0), texture),
        Entity(Vector2f(50, 0), texture),
        Entity(Vector2f(50, 50), texture),
        Entity(Vector2f(50, 100), texture),
    };
    {
        Entity background(Vector2f(0, 0), background_texture);
        entities.push_back(background);
    }

    Time time;
    time.setRefreshRate(rendererWindow.getRefreshRate());

    while (gameRunning) 
    {
        time.startPerformanceCouter();

	    // Event loop
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                gameRunning = false;
            }
        }
	    // Physics loop

	    // Rendering loop
        rendererWindow.clear();
        for (Entity& e : entities)
        {
            rendererWindow.render(e);
        }
        rendererWindow.present();
        time.cappingFrameRate();
    }

    rendererWindow.destroy();
    SDL_Quit();

    return 0;
}

bool init()
{
    bool return_value = true;
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        fprintf(stdin, "Error initializing SDL Video: %s\n", SDL_GetError());
        return_value = false;
    }
    if (!IMG_Init(IMG_INIT_PNG))
    {
        fprintf(stdin, "Error initializing IMG_Init: %s\n", SDL_GetError());
        return_value = false;
    }
    return return_value;
}