#ifndef game_hpp
#define game_hpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Game {
    public:
        Game();
        ~Game();

        bool Initialize();
        void Gameloop();
        void Input();
        void Render();
        void Debug();

        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Texture* texture;

    private:
        bool quit_ = false;
};

#endif /* game_hpp */
