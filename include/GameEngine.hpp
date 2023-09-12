#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include <iostream>

// for initializing and shutdown functions
#include <SDL.h>
// for rendering images and graphics on screen
#include <SDL_image.h>

class GameEngine
{
public:
    GameEngine();

    bool init();
    void eventLoop();
    bool isRunning();

private:
    SDL_Event m_event;
    bool m_running;
};

#endif // GAMEENGINE_HPP
