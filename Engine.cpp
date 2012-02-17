#include "Engine.h"
#include "Graphics.h"

void Engine::mainLoop()
{
	while(gameRunning)
	{
		processInput();
		update();
		renderFrame();
	}
}
void Engine::renderFrame()
{
		SDL_FillRect(screen, NULL,SDL_MapRGB(screen->format, 50, 055,255));
		g_graphics->drawImage(0,0,0);
		SDL_BlitSurface(g_graphics->getBuffer(), NULL, screen, NULL );
		SDL_Flip(screen);
}
void Engine::processInput()
{
	SDL_Event event;
		if (SDL_PollEvent(&event))
		{ 
			if (event.type == SDL_QUIT)
			{
				gameRunning = false;
			}
		} 
}
void Engine::update()
{

}
//public
Engine::Engine()
{
		g_graphics = new Graphics;
		screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
		g_graphics->loadImage("pic.png");
		gameRunning = true;
		mainLoop();
}
Engine::~Engine()
{

}