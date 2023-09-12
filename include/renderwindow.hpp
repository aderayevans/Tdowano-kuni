#ifndef RENDERWINDOW_HPP
#define RENDERWINDOW_HPP

#include <iostream>

#include <SDL_image.h>

#include "entity.hpp"

class RendererWindow
{
public:
    RendererWindow(const char* p_titles, int p_w, int p_h);
    
    SDL_Texture* loadTexture(const char* file_path);
    void destroy();
    void clear();
    void render(Entity& p_entity);
    void present();
    int getRefreshRate();

private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;

    int windowDisplayID;
};

#endif // RENDERWINDOW_HPP
