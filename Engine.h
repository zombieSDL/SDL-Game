#ifndef _ENGINE_H
#define _ENGINE_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Graphics.h"

class Engine
{
private:
	void mainLoop();
	void renderFrame();
	void processInput();
	void update();
public:
	Graphics* g_graphics;
	SDL_Surface* screen;
	bool gameRunning;
	Engine();
	~Engine();
};

#endif