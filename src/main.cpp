#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"
#include "Entity.hpp"

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "SDL HAS FAILED TO INIT. SDL_ERROR: " << SDL_GetError() << std::endl;

	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "SDL_IMAGE HAS FAILED TO INIT. IMAGE_ERROR: " << SDL_GetError() << std::endl;

	RenderWindow window("DEBUG", 1280, 720);

	SDL_Texture* cum = window.loadTexture("res/gfx/comemonster.png");

	Entity platform0(100, 50, cum);

	bool gameRunning = true;

	SDL_Event event;

	while (gameRunning)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				gameRunning = false;
		}

		window.clear();
		window.render(platform0);
		window.display();
	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}