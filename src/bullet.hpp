#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>

class Bullet
{
    private: 

    bool _alive;
    sf::Time _lifetime;
    
    sf::CircleShape _bullet;
    sf::Angle _angle;

    public:

    Bullet(sf::Angle angle, sf::Vector2f playerPos);

    sf::CircleShape getBullet();

    bool isAlive();

    void move(sf::Time elapsedTime);

};

#endif