#include "bullet.hpp"

Bullet::Bullet(sf::Angle angle, sf::Vector2f playerPos)
{
    _alive = true;
    _lifetime = sf::milliseconds(0);
    _bullet.setPosition(playerPos);
    _bullet.setRadius(15);
    _bullet.setFillColor(sf::Color::Blue);
    _bullet.setOutlineColor(sf::Color::Green);
    _bullet.setOutlineThickness(2.f);
    _angle = angle;
}

sf::CircleShape Bullet::getBullet()
{
    return _bullet;
}

bool Bullet::isAlive()
{
    return _alive;
}

void Bullet::move(sf::Time elapsedTime)     // moves bullet according trajectory upon being fired
{
    _lifetime += elapsedTime;
    if (_lifetime >= sf::seconds(5))   // bullet despawns after 20 seconds
    {
        _alive = false;
        return;
    }
    sf::Vector2f displacement(5.f, _angle);
    _bullet.move(displacement);
    // add collision here, change boolean alive to false
}