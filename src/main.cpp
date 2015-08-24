
#include "SDL2/SDL.h"
#include <stdio.h>
#include "Game.h"



int main(int argc, char* argv[]){
    if(TheGame::Instance()->init("Air-Lico", 100, 100, 640, 480, false))
    {
        std::cout << "game init success\n";
        while (TheGame::Instance()->running()){
            TheGame::Instance()->handleEvents();
            TheGame::Instance()->update();
            TheGame::Instance()->render();
            SDL_Delay(10); // add the delay
        }
    }
    else{
        std::cout << "game init fails - " << SDL_GetError() << "\n";
        return -1;
    }
    std::cout << "game closing...\n";
    TheGame::Instance()->clean();
    return 0;
}
