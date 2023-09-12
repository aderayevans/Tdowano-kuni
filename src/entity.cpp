#include "entity.hpp"

Entity::Entity(const Vector2f& p_pos, SDL_Texture* p_texture)
    : m_pos(p_pos), m_texture(p_texture)
{
    m_currentFrame.x = 0;
    m_currentFrame.y = 0;
    m_currentFrame.w = 768;
    m_currentFrame.h = 128;
}