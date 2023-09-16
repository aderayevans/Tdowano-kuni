#include "RenderWindow.hpp"

RenderWindow::RenderWindow()
    : m_window(NULL), m_renderer(NULL)
{}

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h, SDL_WindowFlags p_flags)
    : m_window(NULL), m_renderer(NULL)
{
    m_window = SDL_CreateWindow(p_title,
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                p_w, p_h, p_flags
    );

    if (m_window == NULL)
    {
        fprintf(stdin, "Error creating window: %s\n", SDL_GetError());
    }

    // m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
}

void RenderWindow::destroy()
{
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
}

void RenderWindow::clear()
{
    SDL_RenderClear(m_renderer);
}

void RenderWindow::present()
{
    SDL_SetRenderDrawColor(m_renderer, 0, 255, 255, 255);
    SDL_RenderPresent(m_renderer);
}

int RenderWindow::getRefreshRate()
{
    int displayIndex = SDL_GetWindowDisplayIndex( m_window );

    SDL_DisplayMode mode;
    SDL_GetDisplayMode(displayIndex, 0, &mode);

    return mode.refresh_rate;
}