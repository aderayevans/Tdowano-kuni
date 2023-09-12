#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <iostream>

#include <SDL_image.h>

#include "vector2f.hpp"

class Entity
{
public:
    Entity(const Vector2f& p_pos, SDL_Texture* p_texture);

    inline void setPosition(const Vector2f& p_pos) { m_pos = p_pos; }
    inline void setTexture(SDL_Texture* p_texture) { m_texture = p_texture; }

    inline Vector2f getPosition() const { return m_pos; }
    inline SDL_Texture* getTexture() const { return m_texture; }
    inline SDL_Rect getCurrentFrame() const { return m_currentFrame; }

private:
    Vector2f m_pos;
    SDL_Texture* m_texture;
    SDL_Rect m_currentFrame;
};

#endif // ENTITY_HPP