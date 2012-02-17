#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
class Graphics
{
private:
	    int spriteindex;
        SDL_Surface* sprites[128];
        SDL_Surface* buffer;

public:

	Graphics();
	~Graphics();
	void drawImage(int index, int x, int y);
	void loadImage(char* filename);
	SDL_Surface* getBuffer();
};

#endif