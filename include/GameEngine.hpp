#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include <iostream>
#include <vector>

#include <SDL.h>
#include <SDL_image.h>

#include "RenderWindow.hpp"

class GameEngine
{
public:
    GameEngine();

    bool init();
    void clean();
    void update();
    void render();
    void handleEvents();
    bool isRunning();
    inline RenderWindow& getRenderWindow() { return m_renderWindow; }

public:
    static SDL_Renderer* s_renderer;

private:
    SDL_Event m_event;
    RenderWindow m_renderWindow;
    bool m_running;
};

#endif // GAMEENGINE_HPP
