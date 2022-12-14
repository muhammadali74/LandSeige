
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "audio.h"

class Game
{
    // Screen dimension constants
    const int SCREEN_WIDTH = 1440;
    const int SCREEN_HEIGHT = 810;

    // The window we'll be rendering to
    SDL_Window *gWindow = NULL;
    bool begin = false;
    // Current displayed texture
    SDL_Texture *gTexture = NULL;
    Audio sound;

public:
    bool init();
    bool loadMedia();
    void close();
    SDL_Texture *loadTexture(std::string path);
    void run();
    
};
