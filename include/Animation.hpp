#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

class Animation
{
public:
    int index;
    int frames;
    int speed;
    int width;
    int height;
    SDL_Texture* texture;

    Animation() : texture(nullptr), index(0), frames(0), speed(0), width(0), height(0) {}

    Animation(SDL_Texture* p_texture, int p_index, int p_frames, int p_speed, int p_width, int p_height)
        : texture(p_texture), index(p_index), frames(p_frames), speed(p_speed), width(p_width), height(p_height)
    {}

    ~Animation()
    {
        // SDL_DestroyTexture(texture);
    }
};

#endif // ANIMATION_HPP