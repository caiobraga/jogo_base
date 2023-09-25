#pragma once

#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "ecs/ecs.h"
#include "scenes/GameScene.h"
#include "scenes/EditorScene.h"
#include "scenes/IntroScene.h"
#include "Constants.h"

class Game {

public:

    void init(const char* title, int width, int height, bool fullscreen);

    void handleEvents();

    void update();

    void clean();

    [[nodiscard]] bool running() const;

private:
    bool isRunning;
    SDL_Window* window;
    SDL_Event event;
    Scene* currentScene;
};
