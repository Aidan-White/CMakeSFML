#include "player.hpp"
#include <iostream>
#include <cmath>

// PRIVATE FUNCTIONS

void Player::initVariables()
{
    _hp = 10;
    _lastPos = sf::Vector2f (0.f, 0.f);
    _lastShot = sf::milliseconds(0);
}

void Player::initLuigi(sf::Texture texture)
{
    _luigiTexture = texture;
    _luigiSprite = new sf::Sprite(_luigiTexture);
    _luigiSprite->setPosition(sf::Vector2f(0.f, 0.f));
    _luigiSprite->setScale(sf::Vector2f(0.1f, 0.1f));
}

void Player::initGun()
{
    _gun.setPosition(sf::Vector2f (0.f, 0.f));
    _gun.setSize(sf::Vector2f(100.f, 20.f));
    _gun.setFillColor(sf::Color::Red);
}

// PUBLIC FUNCTIONS

    // Constructors / Destructors

Player::Player(sf::Texture texture)
{
    initVariables();
    initLuigi(texture);
    initGun();
}

Player::~Player()
{
    delete _luigiSprite;
}

    // Getters

sf::Vector2f Player::getPosition()
{
    return _luigiSprite->getPosition();
}

sf::Vector2f Player::getLastPosition()
{
    return _lastPos;
}

float Player::getGunAngle(sf::RenderWindow* window)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
    sf::Vector2u windowSize = window->getSize();
    float x = mousePosition.x - (static_cast<float>(window->getSize().x) / 2); // - this->getPosition().x;                  // x = mousePos.x - windowSize / 2
    float y = mousePosition.y - (static_cast<float>(window->getSize().y) / 2); // - this->getPosition().y;
    float relAngle = 0;     // [0, 90), to x-axis
    float absAngle = 0;     // [0, 360], from origin
    if (x != 0)
    {
        float relAngle = fabs(std::atan(y / x));
        relAngle *= 180.f / (3.1415f);
        if (x > 0 && y >= 0)    // first quadrant, [0, 90)
        {
            absAngle = relAngle;
        }
        else if (x < 0 && y > 0)    // second quadrant, (90, 180)
        {
            absAngle = 180.f - relAngle;
        }
        else if (x < 0 && y <= 0)   // third quadrant, [180, 270)
        {
            absAngle = 180.f + relAngle;
        }
        else if (x > 0 && y < 0)    // fourth quadrant, (270, 360)
        {
            absAngle = 360.f - relAngle;
        }
    }
    else    // x == 0, absAngle = 0, 90, 270
    {
        if (y > 0) {absAngle = 90;}
        else if (y < 0) {absAngle = 270;}
        else {absAngle = 0;}    // both x and y == 0
    }
    return absAngle;
}

    // Setters

    // Functions


void Player::move()
{
    _lastPos = this->getPosition(); // saves luigi's last position before moving him

    // Horizontal Movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right))
    {
        _luigiSprite->move(sf::Vector2f(-3.f, 0.f));
        _gun.move(sf::Vector2f(-3.f, 0.f));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left))
    {
        _luigiSprite->move(sf::Vector2f(3.f, 0.f));
        _gun.move(sf::Vector2f(3.f, 0.f));
    }

    // Vertical Movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down))
    {
        _luigiSprite->move(sf::Vector2f(0.f, -3.f));
        _gun.move(sf::Vector2f(0.f, -3.f));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up))
    {
        _luigiSprite->move(sf::Vector2f(0.f, 3.f));
        _gun.move(sf::Vector2f(0.f, 3.f));
    }
}

void Player::rotateGun(sf::RenderWindow* window)    // rotates gun relative to player depending on mouse position
{
    sf::Angle gunAngle = sf::degrees(getGunAngle(window));
    _gunAngle = gunAngle;
    _gun.setRotation(gunAngle);
}

void Player::shootGun(sf::Time elapsedTime)     // creates bullets if mouse is pressed
{
    _lastShot += elapsedTime;
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && _lastShot >= sf::milliseconds(250))
    {
        Bullet newBullet(_gunAngle, this->getPosition());
        _bullets.push_back(newBullet);
        _lastShot = sf::milliseconds(0);
    }
}

void Player::moveBullets(sf::Time elapsedTime)      // moves bullets on screen
{
    for (int i = 0; i < _bullets.size(); i++)
    {
        if (_bullets[i].isAlive())
        {
            _bullets[i].move(elapsedTime);
        }
        else
        {
            _bullets.erase(_bullets.begin() + i);
        }
    }
}

void Player::drawPlayer(sf::RenderWindow* window)   // draws all objects within player
{
    window->draw(*_luigiSprite);
    window->draw(_gun);
    for (int i = 0; i < _bullets.size(); i++)
    {
        window->draw(_bullets[i].getBullet());
    }
}

void Player::update(sf::RenderWindow* window, sf::Time elapsedTime)
{
    // updates all logic within player
    this->move();
    this->rotateGun(window);
    this->shootGun(elapsedTime);
    this->moveBullets(elapsedTime);
}