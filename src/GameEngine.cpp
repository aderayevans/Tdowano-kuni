#include "GameEngine.hpp"

GameEngine::GameEngine()
    : m_running(true)
{
}

bool GameEngine::init()
{
    bool return_value = true;
    if (SDL_Init(SDL_INIT_EVERYTHING) > 0)
    {
        fprintf(stdin, "Error initializing SDL: %s\n", SDL_GetError());
        return_value = false;
    }
    if (!IMG_Init(IMG_INIT_PNG))
    {
        fprintf(stdin, "Error initializing IMG_Init: %s\n", SDL_GetError());
        return_value = false;
    }
    return return_value;
}

void GameEngine::eventLoop()
{
    while (SDL_PollEvent(&m_event))
    {
        if (m_event.type == SDL_QUIT)
        {
            m_running = false;
        }
    }
}

bool GameEngine::isRunning()
{
    return m_running;
}
