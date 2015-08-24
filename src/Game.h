#ifndef __Game__
#define __Game__
#include <iostream>
#include <vector>
#include "SDL2/SDL.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"

class Game
{
public:
    static Game* Instance()
    {
        if (s_pInstance == 0)
        {
            s_pInstance = new Game();
            return s_pInstance;
        }
        return s_pInstance;
    }
    //set the running variable to true
    bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void render();
    void update();
    void handleEvents();
    void clean();

    SDL_Renderer* getRenderer(){return m_pRenderer;}

    //A function to access private running variable
    bool running(){return m_bRunning;}
private:
    Game(){}
    static Game* s_pInstance;

    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;

    bool m_bRunning;
    int m_currentFrame;

    std::vector<GameObject*> m_gameObjects;
};

typedef Game TheGame;
#endif // __Game__
