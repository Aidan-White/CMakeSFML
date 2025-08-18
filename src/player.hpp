#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "bullet.hpp"

class Player 
{
    private:

    // variables
    int _hp;
    sf::Vector2f _lastPos;
    sf::Texture _luigiTexture;
    sf::Angle _gunAngle;

    // objects
    sf::Sprite* _luigiSprite;
    sf::RectangleShape _gun;
    std::vector<Bullet> _bullets;

    // functions
    void initVariables();
    void initLuigi(sf::Texture texture);
    void initGun();

    public:

    // constructors / destructors
    Player(sf::Texture);
    ~Player();

    // getters
    sf::Vector2f getPosition();
    sf::Vector2f getLastPosition();
    float getGunAngle(sf::RenderWindow* window);

    // setters

    // functions
    void move();
    void rotateGun(sf::RenderWindow* window);
    void shootGun();
    void moveBullets();
    void drawPlayer(sf::RenderWindow* window);
    void update(sf::RenderWindow* window);

};

#endif