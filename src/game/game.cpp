#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include "game/game.hpp"
#include "graphics/spritesheet.hpp"

// Screen dimensions
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Milliseconds per frame
const int MPF = 1000 / 60;

Game::Game() {};

/**
 * Frees media and shuts down SDL
 */
Game::~Game() {
    // free loaded image
    SDL_DestroyTexture(texture);
    texture = NULL;

    // destroy window
    SDL_DestroyWindow(window);
    window = NULL;

    // quit SDL subsystems
    SDL_Quit();
};

/**
 * Starts up SDL and creates window
 */
bool Game::Initialize() {

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    // Set texture filtering to linear
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        printf("Warning: Linear texture filtering not enabled");
    }

    //Create window
    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    // Create renderer for window
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    // Initialize renderer color
    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);

    // Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return false;
    }

    return true;
}

void Game::Gameloop() {
    // timer
    //uint32_t last_time, delta_time = 0;

    while (!quit_) {
        // start timer
        //last_time = SDL_GetTicks();

        // update game
        Input();
        Render();

        // elapsed time
        //delta_time = SDL_GetTicks() - last_time;
    }
}

void Game::Input() {
    // event handler
    SDL_Event e;

    while (SDL_PollEvent(&e) != 0) {
        // user requests quit
        if (e.type == SDL_QUIT) {
            quit_ = true;
        } else {
            // handle input
        }
    }
}

void Game::Render() {
    // clear frame
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    // iterate over game objects and render them

    // render frame
    SDL_RenderPresent(renderer);
}

void Game::Debug() {
}

//SDL_Texture* loadTexture(std::string path) {
    //SDL_Texture* newTexture = NULL;
    //SDL_Surface* loadedSurface = IMG_Load(path.c_str());

    //if (loadedSurface == NULL){
        //printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        //return NULL;
    //}

    //newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
    //if (newTexture == NULL) {
        //printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        //return NULL;
    //}

    //return newTexture;
//}

//bool loadMedia() {
    //SpriteSheet spritesheet;
    //spritesheet.loadSpriteSheet("tp_array_spritesheet.json");
    //texture = loadTexture("loaded.png");
    //if (texture == NULL) {
        //printf("Unable to load media!\n");
        //return false;
    //}

    //return true;
//}
