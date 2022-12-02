#include "game.hpp"
#include "LandSeige.hpp"
#include "drawing.hpp"
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>

#include <Windows.h>

#include <iostream>
using namespace std;

SDL_Renderer *Drawing::gRenderer = NULL;
SDL_Texture *Drawing::assets = NULL;

Mix_Music *music = NULL;
Mix_Music *music2 = NULL;
Mix_Chunk *effect = NULL;
Mix_Chunk *effect2 = NULL;
Mix_Chunk *effect3 = NULL;

bool Game::init()
{
	// Initialization flag
	bool success = true;

	// Initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	TTF_Init();
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		// Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		// Create window
		gWindow = SDL_CreateWindow("Land Siege", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			// Create renderer for window
			Drawing::gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (Drawing::gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				// Initialize renderer color
				SDL_SetRenderDrawColor(Drawing::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				// Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
				// Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) < 0)
				{
					printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool Game::loadMedia()
{
	// Loading success flag
	bool success = true;

	music = Mix_LoadMUS("beat2.wav");
	music2 = Mix_LoadMUS("beat3.wav");
	effect = Mix_LoadWAV("effects/pistol.wav");
	effect2 = Mix_LoadWAV("effects/hit.wav");
	effect2 = Mix_LoadWAV("effects/exp.wav");
	if (music == NULL)
	{
		printf("Unable to load music: %s \n", Mix_GetError());
	}
	Drawing::assets = loadTexture("Artboard 1.png");
	gTexture = loadTexture("main.png");
	if (Drawing::assets == NULL || gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}

void Game::close()
{
	// Free loaded images
	TTF_Quit();
	SDL_DestroyTexture(Drawing::assets);
	Drawing::assets = NULL;
	SDL_DestroyTexture(gTexture);

	// Destroy window
	SDL_DestroyRenderer(Drawing::gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	Drawing::gRenderer = NULL;
	// Quit SDL subsystems
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();
}

SDL_Texture *Game::loadTexture(std::string path)
{
	// The final texture
	SDL_Texture *newTexture = NULL;

	// Load image at specified path
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		// Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(Drawing::gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		// Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}
void Game::run()
{
	bool quit = false;
	bool gameScreen = false;
	SDL_Event e;

	// Mix_Music *music = Mix_LoadMUS("sound.wav");
	// Mix_PlayMusic(music, -1);

	LandSeige landSeige{};

	while (!quit && (landSeige.has_lost() == false))
	{
		if (SDL_GetTicks() > 5000 && begin == false)
		{
			gTexture = loadTexture("Artboard1.png");
			gameScreen = true;
		}
		if (e.type == SDL_MOUSEBUTTONDOWN && gameScreen == true)
		{
			int xMouse, yMouse;
			SDL_GetMouseState(&xMouse, &yMouse);
			gameScreen = false;
			cout << xMouse << "  " << yMouse << endl;
			if (yMouse >= 460 && yMouse <= 590 && xMouse >= 545 && xMouse <= 900)
			{
				// when start clicked
				gTexture = loadTexture("abnew.png");
				begin = true;
			}
			else if (yMouse >= 620 && yMouse <= 750 && xMouse >= 545 && xMouse <= 900)
			{

				quit = true; // when exit clicked
			}
		}
		// Handle events on queue
		while (SDL_PollEvent(&e) != 0 && begin == true && gameScreen == false)
		{
			// User requests quit
			if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
			{
				quit = true;
			}

			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				// this is a good location to add pigeon in linked list.
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse, &yMouse);
				landSeige.createUserEquipment(xMouse, yMouse);
				cout << xMouse << "  " << yMouse << endl;
				// landSeige.createEnemyEquipment();
			}

			if (e.type == SDL_KEYDOWN)
			{
				if (e.key.keysym.sym == SDLK_1)
				{
					landSeige.keypress.push_back(1);
					landSeige.keypressed = 1;
				}
				else if (e.key.keysym.sym == SDLK_2)
				{
					landSeige.keypress.push_back(2);
					landSeige.keypressed = 2;
				}
				else if (e.key.keysym.sym == SDLK_3)
				{
					landSeige.keypress.push_back(3);
					landSeige.keypressed = 3;
				}
				else if (e.key.keysym.sym == SDLK_4)
				{
					landSeige.keypress.push_back(4);
					landSeige.keypressed = 4;
				}
				else if (e.key.keysym.sym == SDLK_5)
				{
					landSeige.keypress.push_back(5);
					landSeige.keypressed = 5;
				}
				else if (e.key.keysym.sym == SDLK_6)
				{
					landSeige.keypress.push_back(6);
					landSeige.keypressed = 6;
				}
				else if (e.key.keysym.sym == SDLK_7)
				{
					landSeige.keypress.push_back(7);
					landSeige.keypressed = -1;
				}
			}
		}
		SDL_RenderClear(Drawing::gRenderer);					  // removes everything from renderer
		SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL); // Draws background to renderer
		//***********************draw the objects here********************
		if (begin == true && gameScreen == false)
		{
			Uint64 current_time = SDL_GetTicks();
			if (SDL_GetTicks() % 100 == 0)
			{
				landSeige.createEnemyEquipment();
			}
			landSeige.drawObjects();
			landSeige.handleprogress();
			landSeige.handlereloader();
		}
		// 	Play the music
		if (Mix_PlayingMusic() == 0)
		{
			// 	Play the music
			Mix_PlayMusic(music, 2);
		}

		if (landSeige.shot == true)
		{
			// 	Play the sound effect
			Mix_PlayChannel(-1, effect, 0);
			landSeige.shot = false;
		}
		if (landSeige.hit == true)
		{
			// 	Play the sound effect
			Mix_PlayChannel(-1, effect2, 0);
			landSeige.hit = false;
		}
		if (landSeige.destroy == true)
		{
			// 	Play the sound effect
			Mix_PlayChannel(-1, effect2, 0);
			landSeige.hit = false;
		}
		// cout << "Playing" << endl;

		//****************************************************************
		SDL_RenderPresent(Drawing::gRenderer); // displays the updated renderer

		SDL_Delay(100); // causes sdl engine to delay for specified miliseconds
	}
}
