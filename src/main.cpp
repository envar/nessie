#include <stdio.h>
#include <string>
#include "game/game.hpp"

int main() {
//int main(int argc, char* args[]) {
    Game game;

    // initialize game
    if (!game.Initialize()) {
        printf("Failed to initialize game!\n");
        return 1;
    }

    // start game
    game.Gameloop();

    return 0;
}
