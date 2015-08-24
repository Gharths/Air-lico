#include <iostream>
#include <vector>
#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    //attempt to initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL init success\n";
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (m_pWindow != 0) //window init success
        {
            std::cout << "Window creation success\n";
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
            if (m_pRenderer != 0)
            {
                std::cout << "Renderer creation Success\n";
                SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
            }
            else
            {
                std::cout << "renderer init fail\n";
                return false; // renderer init fail
            }
        }
        else
        {
            std::cout << "window init fail\n";
            return false; // window init fail
        }
    }
    else
    {
        std::cout << "SDL init fail\n";
        return false; // SDL init fail
    }
    std::cout << "init success\n";
    if(!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer))
    {
        return false;
    }
    m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
    m_bRunning = true; // everything inited successfully,
    //start the main loop
    return true;
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color

    for(std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }

    SDL_RenderPresent(m_pRenderer); //draw to the screen
}

void Game::clean()
{
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

void Game::handleEvents()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            m_bRunning = false;
            break;
        default:
            break;
        }
    }
}

void Game::update()
{
    for(std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}

Game* Game::s_pInstance = 0;