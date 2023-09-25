#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif
#include "../include/Game.h"

void runLoop(void* arg) {
    Game *game = (Game*)arg;
    game->handleEvents();
    game->update();
}

int main(int argc, char **argv) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 84;
    }
    uint32_t frameStart, frameTime;

    Game* game = new Game();
    game->init("Super Mario Bros",
            SNES_RESOLUTION_WIDTH * ZOOM,
            SNES_RESOLUTION_HEIGHT * ZOOM,
            false);

#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop_arg(runLoop, game, 0, 1);
#else
    while (game->running()) {
        frameStart = SDL_GetTicks();
        runLoop(game);
        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < FRAME_DURATION) SDL_Delay(FRAME_DURATION - frameTime);
    }

#endif
    game->clean();
    delete game;
    return EXIT_SUCCESS;
}
