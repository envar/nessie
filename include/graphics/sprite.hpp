#ifndef sprite_hpp
#define sprite_hpp

#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/**
 * @class Sprite
 *
 * @brief Displays a frame or a sequence of frames from a spritesheet
 */
class Sprite {
public:
    /** constructor */
    Sprite(SDL_Renderer* renderer, std::string spritesheet);

    /** x y position */
    SDL_Point pos;

    /** size */
    SDL_Rect size;

    /** current frame index */
    int current_frame;

private:
    SDL_Renderer* renderer;
    SDL_Texture* texture;
};

#endif /* sprite_hpp */
