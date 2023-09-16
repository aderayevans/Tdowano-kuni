#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include <iostream>

#include <SDL_image.h>

class TextureManager
{
public:
    static SDL_Texture* LoadTexture(const char* p_filePath);
    static void Draw(SDL_Texture* p_texture, const SDL_Rect& p_src, const SDL_Rect& p_dst, SDL_RendererFlip p_flip);
};

#endif // TEXTURE_MANAGER_HPP