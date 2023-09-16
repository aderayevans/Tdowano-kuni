#ifndef RENDERWINDOW_HPP
#define RENDERWINDOW_HPP

#include <iostream>

#include <SDL.h>

class RenderWindow
{
public:
    RenderWindow();
    RenderWindow(const char* p_title, int p_w, int p_h, SDL_WindowFlags p_flags=SDL_WINDOW_FULLSCREEN);

    /**
     * @brief Destroy a window, destroy the rendering context for a window and free associated textures.
     * 
     */
    void destroy();

    /**
     * @brief Clear the current rendering target with the drawing color. This function clears the entire rendering target, ignoring the viewport and the clip rectangle.
     * 
     */
    void clear();
    void present();
    int getRefreshRate();
    inline SDL_Renderer* getRenderer() { return m_renderer; }

private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
};

#endif // RENDERWINDOW_HPP
