#include "game.hpp"

// PRIVATE

void Game::initVariables()
{
    this->_window = nullptr;
    
}

void Game::initWindow()
{
    this->_videoMode = sf::VideoMode({800,600});

    this->_window = new sf::RenderWindow(_videoMode, "Luigi's Creepypasta Escape");

    this->_window->setFramerateLimit(60);
}

void Game::initTileMap()
{
    constexpr std::array level = 
    {
        1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
        0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
        1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
        0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
        1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
        0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
        1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
        0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
        1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
        0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
        1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
        0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
        1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
        0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
        1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
        0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
        1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
        0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
        1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0
    };
    if (!_map.load("../../images/checkeredTilesetFinished.jpg", {32, 32}, level.data(), 26, 19))
    {
        std::cout << "Error code sucks" << std::endl;
    }
}

void Game::initLuigi()
{
    _luigi = new sf::Sprite(*getTexture("../../images/purpleLuigi.png", _textures));
    _luigi->setTexture(*getTexture("../../images/purpleLuigi.png", _textures));
    _luigi->setPosition(sf::Vector2f(300.f, 300.f));
    _luigi->setScale(sf::Vector2f(0.1f, 0.1f));
}

std::vector<TextureHolder> Game::initTextures()   // NOTE: some images fail to load, "Image not of any known type, or corrupt"
{
    std::vector<TextureHolder> THVector;     // vector to store all textures
    const fs::path dir_path{"..\\..\\images"};      // path to all images used for textures
    for (auto const& entry: fs::directory_iterator{dir_path})
    {
        std::string imagePath = entry.path().generic_string();    // converts path to string
        sf::Texture newTexture;
        if (!newTexture.loadFromFile(imagePath))
        {
            std::cout << imagePath << " Failed to load!" << std::endl;
            continue;
        }
        TextureHolder newTH;
        newTH.texture = newTexture;
        newTH.imagePath = imagePath;
        THVector.push_back(newTH);
    }
    return THVector;
}

// PUBLIC

// constructors / destructors

Game::Game()
{
    initVariables();
    initWindow();
    initTileMap();
    _textures = initTextures();
    initLuigi();
}

Game::~Game()
{
    delete this->_window;
    delete _luigi;
}

// Accessors
const bool Game::running() const
{
    return this->_window->isOpen();
}

sf::Texture* Game::getTexture(std::string path, std::vector<TextureHolder> &textureList)
{
    for (int i = 0; i < textureList.size(); i++)    // searches for texture
    {
        if (textureList[i].imagePath == path)
        {
            sf::Texture* TexturePtr = &textureList[i].texture;
            return TexturePtr;
        }
    }
    std::cout << std::endl << textureList[9].imagePath << std::endl;
    std::cout << std::endl << "Texture not found" << std::endl;
    return nullptr;     // texture not found
}

// Functions

void Game::pollEvents()
{
       // Event polling
    while(const std::optional event = _window->pollEvent())
    {
        if (event->is<sf::Event::Closed>())     // checks if game is closed
        {
            this->_window->close();
        }
        else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())    // checks certain game inputs
        {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
            {
                this->_window->close();
            }
        }
    }
}

void Game::moveLuigi()
{
    // Horizontal Movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right))
    {
        _luigi->move(sf::Vector2f(-3.f, 0.f));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left))
    {
        _luigi->move(sf::Vector2f(3.f, 0.f));
    }

    // Vertical Movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down))
    {
        _luigi->move(sf::Vector2f(0.f, -3.f));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up))
    {
        _luigi->move(sf::Vector2f(0.f, 3.f));
    }
}

void Game::update() // updates game logic
{
    pollEvents();
    moveLuigi();
}

void Game::render() // draws updated frame (clear, draw, display)
{
    _window->clear(sf::Color(0, 0, 0, 255));

    // draw stuff here
    _window->draw(_map);
    _window->draw(*_luigi);

    _window->display();
}