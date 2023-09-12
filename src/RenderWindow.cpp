#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
    : m_window(NULL), m_renderer(NULL)
{
    m_window = SDL_CreateWindow(p_title,
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                p_w, p_h, SDL_WINDOW_SHOWN
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
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(m_renderer, p_filePath);
    if (texture == NULL)
    {
        fprintf(stdin, "Failed to load texture at %s: %s\n", p_filePath, SDL_GetError());
    }
    return texture;
}

void RenderWindow::clear()
{
    SDL_RenderClear(m_renderer);
}

void RenderWindow::render(Entity& p_entity)
{
    // SDL_Rect src(p_entity.getCurrentFrame());

    // SDL_Rect dst;
    // dst.x = p_entity.getPosition().x * 4;
    // dst.y = p_entity.getPosition().y * 4;
    // dst.w = p_entity.getCurrentFrame().w;
    // dst.h = p_entity.getCurrentFrame().h;

    SDL_RenderCopy(m_renderer, p_entity.getTexture(), NULL, NULL);
}

void RenderWindow::present()
{
    SDL_RenderPresent(m_renderer);
}

int RenderWindow::getRefreshRate()
{
    int displayIndex = SDL_GetWindowDisplayIndex( m_window );

    SDL_DisplayMode mode;
    SDL_GetDisplayMode(displayIndex, 0, &mode);

    return mode.refresh_rate;
}
