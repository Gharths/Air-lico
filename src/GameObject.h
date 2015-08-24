#ifndef GAMOBJECT_H_INCLUDED
#define GAMOBJECT_H_INCLUDED
#include <iostream>
#include <string>
#include <map>
#include "SDL2/SDL.h"
#include "LoaderParams.h"

class GameObject
{
public:
    virtual void draw()=0;
    virtual void update()=0;
    virtual void clean()=0;
protected:
    GameObject(const LoaderParams* pParams){}
    virtual ~GameObject(){}
};

#endif // GAMOBJECT_H_INCLUDED
