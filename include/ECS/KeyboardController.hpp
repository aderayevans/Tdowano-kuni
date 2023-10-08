#ifndef KEYBOARD_CONTROLLER_HPP
#define KEYBOARD_CONTROLLER_HPP

#include <SDL.h>

#include "Components.hpp"

class KeyboardController : public Component
{
enum class EventType
{
    KEYUP,
    KEYDOWN,
    NONE
};
private:
    EventType m_eventType = EventType::NONE;
    SDL_Keycode m_keycode;
public:
    TransformComponent *transform;
    SpriteComponent *sprite;

    bool flipped = false;

    void init() override
    {
        transform = &entity->getComponent<TransformComponent>();
        sprite = &entity->getComponent<SpriteComponent>();
    }

    void update() override
    {
        if (flipped) sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
        else sprite->spriteFlip = SDL_FLIP_NONE;

        switch (m_eventType)
        {
            case EventType::KEYDOWN:
            {
                switch (m_keycode)
                {
                    case SDLK_w:
                    {
                        sprite->play("Run");
                        transform->velocity.y = -1;
                        break;
                    }
                    case SDLK_a:
                    {
                        flipped = true;
                        transform->velocity.x = -1;
                        sprite->play("Run");
                        break;
                    }
                    case SDLK_s:
                    {
                        sprite->play("Run");
                        transform->velocity.y = 1;
                        break;
                    }
                    case SDLK_d:
                    {
                        flipped = false;
                        sprite->play("Run");
                        transform->velocity.x = 1;
                        break;
                    }
                    case SDLK_c:
                    {
                        sprite->play("Attack");
                        break;
                    }
                }
                break;
            }
            case EventType::KEYUP:
            {
                switch (m_keycode)
                {
                    case SDLK_w:
                    {
                        sprite->play("Idle");
                        transform->velocity.y = 0;
                        break;
                    }
                    case SDLK_a:
                    {
                        sprite->play("Idle");
                        transform->velocity.x = 0;
                        break;
                    }
                    case SDLK_s:
                    {
                        sprite->play("Idle");
                        transform->velocity.y = 0;
                        break;
                    }
                    case SDLK_d:
                    {
                        sprite->play("Idle");
                        transform->velocity.x = 0;
                        break;
                    }
                    case SDLK_c:
                    {
                        sprite->play("Idle");
                        break;
                    }
                }
                break;
            }
        }
        m_eventType = EventType::NONE;
    }

    void pressKey(SDL_Keycode p_keycode)
    {
        m_eventType = EventType::KEYDOWN;
        m_keycode = p_keycode;
    }

    void releaseKey(SDL_Keycode p_keycode)
    {
        m_eventType = EventType::KEYUP;
        m_keycode = p_keycode;
    }
};

#endif // KEYBOARD_CONTROLLER_HPP