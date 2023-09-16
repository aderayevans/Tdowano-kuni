#include <iostream>
#include <vector>
#include <cmath>

#include "Time.hpp"
#include "GameEngine.hpp"

int main(int argc, char **argv)
{
    GameEngine gameEngine;
    if (!gameEngine.init()) {
        return 1;
    }

    Time time;
    time.setRefreshRate(gameEngine.getRenderWindow().getRefreshRate());

    while (gameEngine.isRunning()) 
    {
        time.startPerformanceCouter();

        gameEngine.handleEvents();
        gameEngine.update();
        gameEngine.render();
        time.cappingFrameRate();
    }

    gameEngine.clean();

    return 0;
}
