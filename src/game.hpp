#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <list>
#include <filesystem>
#include <iterator>
#include <iostream>
#include "tilemap.hpp"
#include "player.hpp"

namespace fs = std::filesystem;

// look up "pre-compiled headers" to compile things faster

struct TextureHolder    // holds textures, along with the paths of their original images
{
    std::string imagePath;
    sf::Texture texture;
};

class Game
{
    private:
    // variables
    // sf::Vector2f _luigiLastPos;

    // window
    sf::RenderWindow* _window;
    sf::VideoMode _videoMode;

    // game objects

    sf::View _camera;
    std::vector<TextureHolder> _textures;
    TileMap _map;
    // std::vector<sf::Sprite*> enemies;
    // sf::Sprite* _luigi;
    Player* _player;

    // private funcitons
    void initVariables();
    void initWindow();
    void initTileMap();
    // void initLuigi();
    void initPlayer();
    std::vector<TextureHolder> initTextures();
    void initCamera();



    public:
        // constructors / destructors
        Game();
        ~Game();
        


        // accessors
        const bool running() const;
        
        sf::Texture* getTexture(std::string path, std::vector<TextureHolder> &textureList); 
        /* 
        - searches for and returns a pointer to a texture, or returns nullptr
        - always type directories in this format: "d1/d2/d3", NOT "d1\\d2\\d3\\" when using this function
        */

        // functions
        void pollEvents();
        void moveCamera();
        void update();
        void render();
};

#endif