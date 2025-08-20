#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "tilemap.hpp"
#include "wall.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class Level
{
    private:

    // objects
    TileMap _map;
    std::vector<Wall> _walls;

    // functions
    void initTileMap();
    void initWalls();

    public:

    // constructors/destructors
    Level();

    // functions
    void draw(sf::RenderWindow* window);

};

#endif