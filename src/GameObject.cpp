#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char* p_filePath, const Vector2f& p_pos)
    : m_pos(p_pos)
{
    SDL_QueryTexture(m_texture, NULL, NULL, &m_currentFrame.w, &m_currentFrame.h);
    m_currentFrame.x = p_pos.x;
    m_currentFrame.y = p_pos.y;
}

void GameObject::update()
{
    m_updatedFrame = m_currentFrame;
}

void GameObject::render()
{
    // TextureManager::Draw(m_texture, m_currentFrame, m_updatedFrame);
}