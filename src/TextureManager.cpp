#include "TextureManager.hpp"
#include "GameEngine.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* p_filePath)
{
    SDL_Texture* texture = IMG_LoadTexture(GameEngine::s_renderer, p_filePath);
    if (texture == NULL)
    {
        fprintf(stdin, "Failed to load texture at %s: %s\n", p_filePath, SDL_GetError());
    }
    return texture;
}

void TextureManager::Draw(SDL_Texture* p_texture, const SDL_Rect& p_src, const SDL_Rect& p_dst, SDL_RendererFlip p_flip)
{
    SDL_RenderCopyEx(GameEngine::s_renderer, p_texture, &p_src, &p_dst, NULL, NULL, p_flip);
}