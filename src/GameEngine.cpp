#include "GameEngine.hpp"

#include "ECS/Components.hpp"
#include "Collision.hpp"

const short WINDOW_WIDTH = 1920;
const short WINDOW_HEIGHT = 1080;
const char* WINDOW_TITLE = "Tdowanokuni";

const char* PLAYER_IDLE_TEXTURE_PATH = "graphics/Wano/implementStandingToshizo.png";
const char* PLAYER_RUN_TEXTURE_PATH = "graphics/Wano/implementRunningToshizo.png";
const char* PLAYER_ATTACK_TEXTURE_PATH = "graphics/Wano/implementAttackingToshizo.png";
const char* PLAYER_JUMP_TEXTURE_PATH = "graphics/Wano/implementJumpingToshizo.png";

const char* GROUND_TEXTURE_PATH = "graphics/Wano/snowMiniTexture3.png";

SDL_Renderer* GameEngine::s_renderer = nullptr;

Manager manager;

auto& player(manager.addEntity());
auto& ground(manager.addEntity());

GameEngine::GameEngine()
    : m_running(true)
{}

bool GameEngine::init()
{
    bool return_value = true;
    if (SDL_Init(SDL_INIT_EVERYTHING) > 0)
    {
        fprintf(stdin, "Error initializing SDL: %s\n", SDL_GetError());
        return_value = false;
    }
    if (!IMG_Init(IMG_INIT_PNG))
    {
        fprintf(stdin, "Error initializing IMG_Init: %s\n", SDL_GetError());
        return_value = false;
    }

    m_renderWindow = RenderWindow(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WindowFlags::SDL_WINDOW_RESIZABLE);
    GameEngine::s_renderer = m_renderWindow.getRenderer();

    ground.addComponent<TransformComponent>(0, 600);
    ground.addComponent<SpriteComponent>(GROUND_TEXTURE_PATH);
    ground.addComponent<ColliderComponent>("ground");

    player.addComponent<TransformComponent>();
    player.addComponent<SpriteComponent>(PLAYER_IDLE_TEXTURE_PATH, true);
    player.getComponent<SpriteComponent>().addAnimation("Idle", PLAYER_IDLE_TEXTURE_PATH, 4, 100);
    player.getComponent<SpriteComponent>().addAnimation("Run", PLAYER_RUN_TEXTURE_PATH, 5, 100);
    player.getComponent<SpriteComponent>().addAnimation("Attack", PLAYER_ATTACK_TEXTURE_PATH, 2, 300);
    player.getComponent<SpriteComponent>().addAnimation("Jump", PLAYER_JUMP_TEXTURE_PATH, 5, 100);
    player.getComponent<SpriteComponent>().play("Idle");
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");

    return return_value;
}

void GameEngine::handleEvents()
{
    while (SDL_PollEvent(&m_event))
    {
        switch (m_event.type) 
        {
            case SDL_QUIT:
            {
                m_running = false;
                break;
            }
            case SDL_KEYUP:
            {
                player.getComponent<KeyboardController>().releaseKey(m_event.key.keysym.sym);
                break;
            }
            case SDL_KEYDOWN:
            {
                player.getComponent<KeyboardController>().pressKey(m_event.key.keysym.sym);
                switch (m_event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                    {
                        fprintf(stdout, "Pressed ESCAPE\n");
                        m_running = false;
                        break;
                    }
                }
                break;
            }
            case SDL_MOUSEBUTTONUP:
            {
				switch (m_event.button.button) {
					case SDL_BUTTON_LEFT:
                    {
                        fprintf(stdout, "Pressed Mouse Left\n");
                        break;
                    }
					case SDL_BUTTON_RIGHT:
                    {
                        fprintf(stdout, "Pressed Mouse Right\n");
                        break;
                    }
				}
                break;
            }
            default:
                break;
        }
    }
}

void GameEngine::update()
{
    manager.refresh();
    manager.update();

    if (Collision::AABB(player.getComponent<ColliderComponent>().collider,
                        ground.getComponent<ColliderComponent>().collider))
    {
        fprintf(stdout, "Hit Ground!!!\n");
    }
}

void GameEngine::render()
{
    m_renderWindow.clear();

    manager.draw();

    m_renderWindow.present();
}

void GameEngine::clean()
{
    m_renderWindow.destroy();
    IMG_Quit();
    SDL_Quit();
}

bool GameEngine::isRunning()
{
    return m_running;
}
