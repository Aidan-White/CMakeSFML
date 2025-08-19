#include "game.hpp"

int main()
{
    // Init game engine
    Game game;
    sf::Clock clock;

    while (game.running())
    {
        // Update
        game.update(clock.restart());   // .restart() returns the elapsed time since last restart

        // Render
        game.render();

    }

    // End of application
    return 0;
}

