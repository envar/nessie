#include "graphics/sprite.hpp"

Sprite::Sprite(SDL_Renderer* renderer, std::string spritesheet) {
    texture = IMG_LoadTexture(renderer, spritesheet.c_str());
}
