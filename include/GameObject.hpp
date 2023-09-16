#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <iostream>

#include <SDL.h>

#include "Math/Vector2f.hpp"

class GameObject
{
public:
    GameObject() = default;
    GameObject(const char* p_filePath, const Vector2f& p_pos);

    void update();
    void render();

    inline void setPosition(const Vector2f& p_pos) { m_pos = p_pos; }
    inline void setTexture(SDL_Texture* p_texture) { m_texture = p_texture; }

    inline Vector2f getPosition() const { return m_pos; }
    inline SDL_Texture* getTexture() const { return m_texture; }
    inline SDL_Rect getCurrentFrame() const { return m_currentFrame; }

private:
    Vector2f m_pos;
    SDL_Texture* m_texture;
    SDL_Rect m_currentFrame;
    SDL_Rect m_updatedFrame;
};

#endif // GAMEOBJECT_HPP
