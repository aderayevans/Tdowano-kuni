#ifndef RENDERWINDOW_HPP
#define RENDERWINDOW_HPP

#include <iostream>

#include <SDL_image.h>

#include "Entity.hpp"

class RenderWindow
{
public:
    RenderWindow(const char* p_title, int p_w, int p_h);
    
    SDL_Texture* loadTexture(const char* p_filePath);
    void destroy();
    void clear();
    void render(Entity& p_entity);
    void present();
    int getRefreshRate();

private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
};

#endif // RENDERWINDOW_HPP
