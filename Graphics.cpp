#include "Graphics.h"

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    int rmask = 0xff000000;
    int gmask = 0x00ff0000;
    int bmask = 0x0000ff00;
    int amask = 0x000000ff;
#else
    int rmask = 0x000000ff;
    int gmask = 0x0000ff00;
    int bmask = 0x00ff0000;
    int amask = 0xff000000;
#endif

	/*int spriteindex;
	SDL_Surface* sprites[128];
	SDL_Surface* derp;
	SDL_Surface* buffer;
	*/

	Graphics::Graphics()
	{
		printf("initialize");
		SDL_Init(SDL_INIT_VIDEO);
		buffer = SDL_CreateRGBSurface(SDL_HWSURFACE , 500, 500, 32, rmask, gmask, bmask, amask);
		spriteindex = -1;
	}
	Graphics::~Graphics()
	{

	}
	void Graphics::drawImage(int index, int x, int y)
	{
		SDL_Rect tempRect;
		tempRect.x = x;
		tempRect.y = y;
		tempRect.h = derp->h;
		tempRect.h = derp->w;
		SDL_BlitSurface(derp, &tempRect, buffer,NULL);
	}
	
	bool Graphics::loadImage(char* filename)
	{
		
		spriteindex++;
		derp = IMG_Load("pic.png");
		
		if(derp==NULL)
		{
			return 1; //error
			
		}
		return 0;
	}
	
	SDL_Surface* Graphics::getBuffer()
	{
		if(buffer==NULL)
		{
			//printf("buffer is empty\n");
		}
		return buffer;	
	}