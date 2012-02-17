#include <Windows.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Engine.h"

#pragma comment(lib,"SDL.lib")
#pragma comment(lib,"SDLmain.lib")
#pragma comment(lib,"SDL_image.lib")

int main(int argc, char *argv[])
{
	Engine* engine = new Engine();

	return 1;
}