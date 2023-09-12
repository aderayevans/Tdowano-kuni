#include <iostream>
#include <vector>
#include <cmath>

// for initializing and shutdown functions
#include <SDL.h>
// for rendering images and graphics on screen
#include <SDL_image.h>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Vector2f.hpp"
#include "Time.hpp"
#include "GameEngine.hpp"

const short WINDOW_WIDTH = 1920;
const short WINDOW_HEIGHT = 1080;
const char* WINDOW_TITLE = "Tdowanokuni";

const char* IDLE_TEXTURE_PATH = "graphics/Samurai/Idle.png";
const char* BACKGROUND_TEXTURE_PATH = "graphics/Wano/firstBg.png";

int main(int argc, char **argv)
{
    GameEngine gameEngine;
    if (!gameEngine.init()) {
        return 1;
    }
    RenderWindow renderWindow(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);

    SDL_Texture* texture = renderWindow.loadTexture(IDLE_TEXTURE_PATH);
    SDL_Texture* background_texture = renderWindow.loadTexture(BACKGROUND_TEXTURE_PATH);

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
    time.setRefreshRate(renderWindow.getRefreshRate());

    while (gameEngine.isRunning()) 
    {
        time.startPerformanceCouter();

	    // Event loop
        gameEngine.eventLoop();
	    // Physics loop

	    // Rendering loop
        renderWindow.clear();
        for (Entity& e : entities)
        {
            renderWindow.render(e);
        }
        renderWindow.present();
        time.cappingFrameRate();
    }

    renderWindow.destroy();
    SDL_Quit();

    return 0;
}
