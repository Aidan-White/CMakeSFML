#include "bullet.hpp"

Bullet::Bullet(sf::Angle angle, sf::Vector2f playerPos)
{
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

void Bullet::move()     // moves bullet according trajectory upon being fired
{
    sf::Vector2f displacement(5.f, _angle);
    _bullet.move(displacement);
    // add collision here
}