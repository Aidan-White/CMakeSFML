#include "game.hpp"

int main()
{
    // Init game engine
    Game game;

    while (game.running())
    {
        // Update
        game.update();

        // Render
        game.render();

    }

    // End of application
    return 0;
}

