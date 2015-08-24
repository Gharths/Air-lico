#ifndef TEXTUREMANAGER_H_INCLUDED
#define TEXTUREMANAGER_H_INCLUDED
#include <iostream>
#include <string>
#include <map>
#include "SDL2/SDL.h"

class TextureManager
{
public:

    static TextureManager* Instance()
    {
        if (s_pInstance == 0)
        {
            s_pInstance = new TextureManager();
            return s_pInstance;
        }
        return s_pInstance;typedef TextureManager TheTextureManager;
    }
    //load a file named "filename"
    bool load(std::string filename, std::string id, SDL_Renderer* pRenderer);
    //draw
    void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    //draw frame
    void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame,SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
private:
    static TextureManager* s_pInstance;
    TextureManager(){}
    std::map<std::string, SDL_Texture*> m_textureMap;
};
#endif // TEXTUREMANAGER_H_INCLUDED
typedef TextureManager TheTextureManager;
