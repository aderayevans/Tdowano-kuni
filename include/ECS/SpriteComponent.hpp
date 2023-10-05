#ifndef SPRITE_COMPONENT_HPP
#define SPRITE_COMPONENT_HPP

#include <map>

#include <SDL.h>

#include "Animation.hpp"
#include "Components.hpp"
#include "TextureManager.hpp"

class SpriteComponent : public Component
{
private:
    TransformComponent *m_transform;
    SDL_Texture *m_texture, *m_animatedTexture;
    SDL_Rect m_srcRect, m_dstRect;

    bool m_animated = false;
    int m_frames = 1;
    int m_speed = 100;

    int m_width;
    int m_height;
    int m_scale = 1;

    int m_animationIndex = 0;

    std::map<const char*, Animation> m_animations;

    std::string m_state;

public:
    SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

public:
    SpriteComponent() = default;
    SpriteComponent(const char* p_path, bool p_animated = false)
        : m_animated(p_animated)
    {
        setTexture(p_path);
    }

    ~SpriteComponent()
    {
        SDL_DestroyTexture(m_texture);
    }

    void addAnimation(const char* p_label, const char* p_path, int p_frames, int p_speed)
    {
        SDL_Texture* texture = TextureManager::LoadTexture(p_path);
        int width, height;
        SDL_QueryTexture(texture, NULL, NULL, &width, &height);
        auto result = m_animations.emplace(p_label, Animation(texture, 0, p_frames, p_speed, width, height));
        fprintf(stdout, "Added animation (%s) with result: %s\n", p_label, result.second ? "true": "false");
    }

    void setTexture(const char* p_path)
    {
        m_texture = TextureManager::LoadTexture(p_path);
    }

    void init() override
    {
        m_transform = &entity->getComponent<TransformComponent>();

        m_srcRect.x = m_srcRect.y = 0;

        SDL_QueryTexture(m_texture, NULL, NULL, &m_width, &m_height);

        m_srcRect.w = m_dstRect.w = m_width;
        m_srcRect.h = m_dstRect.h = m_height;
    }

    void update() override
    {
        if (m_animated)
        {
            m_srcRect.w = static_cast<int>(m_width / m_frames);
            m_animationIndex = static_cast<int>((SDL_GetTicks() / m_speed) % m_frames);
            m_srcRect.x = m_srcRect.w * m_animationIndex;
            // fprintf(stdout, "updating m_animationIndex %d\n", m_animationIndex);
            // fprintf(stdout, "updating m_srcRect.x %d\n", m_srcRect.x);
            m_srcRect.h = m_height;
            m_srcRect.y = 0;
        }

        m_dstRect.x = static_cast<int>(m_transform->position.x);
        m_dstRect.y = static_cast<int>(m_transform->position.y);
        m_dstRect.w = static_cast<int>(m_width / m_frames);
        m_dstRect.h = m_height;
    }

    void draw() override
    {
        if (m_animated)
        {
            TextureManager::Draw(m_animatedTexture, m_srcRect, m_dstRect, spriteFlip);
        }
        else
        {
            TextureManager::Draw(m_texture, m_srcRect, m_dstRect, spriteFlip);
        }
    }

    void setState(const char* p_state)
    {
        m_state = std::string(p_state);
    }

    void play(const char* p_animation)
    {
        setState(p_animation);

        if (m_animations.find(p_animation) != m_animations.end())
        {
            m_frames = m_animations[p_animation].frames;
            m_animatedTexture = m_animations[p_animation].texture;
            m_animationIndex = m_animations[p_animation].index;
            m_speed = m_animations[p_animation].speed;
            m_width = m_animations[p_animation].width;
            m_height = m_animations[p_animation].height;
        }
        else 
        {
            fprintf(stdout, "Invalid animation state, could not found (%s)\n", p_animation);
        }
    }

    int getScale() const { return m_scale; }
    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }
};

#endif // SPRITE_COMPONENT_HPP