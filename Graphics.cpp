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

	Graphics::Graphics()
	{
		printf("initializing....\n");
		SDL_Init(SDL_INIT_VIDEO);
		buffer = SDL_CreateRGBSurface(SDL_HWSURFACE , 500, 500, 32, rmask, gmask, bmask, amask);
		spriteindex = -1;
		printf("initialized!\n\n");
	}
	Graphics::~Graphics()
	{

	}
	void Graphics::drawImage(int index, int x, int y)
	{
		SDL_Rect tempRect;
		tempRect.x = x;
		tempRect.y = y;
		tempRect.h = sprites[index]->h;
		tempRect.h = sprites[index]->w;
		SDL_BlitSurface(sprites[index], &tempRect, buffer,NULL);
	}
	
	void Graphics::loadImage(char* filename)
	{
		if(spriteindex<=127){
			spriteindex++;
			sprites[spriteindex] = IMG_Load("pic.png");
		
			if(sprites[spriteindex]==NULL)
			{
				printf("error loading image\n");
			
			}
			printf("image %i loaded successfully from %s \n",spriteindex, filename);
		}
		else
		{
			printf("error allocating image to array\n");
		}
	}
	
	SDL_Surface* Graphics::getBuffer()
	{
		if(buffer==NULL)
		{
			//printf("buffer is empty\n");
		}
		return buffer;	
	}