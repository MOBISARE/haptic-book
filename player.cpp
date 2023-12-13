#include "player.h"

Player::Player()
{
    // RAS
}

Player::~Player()
{
    // RAS
}

Player::Player(const string* sprite, int positionX, int positionY, int width, int height)
{
    this->sprite = sprite;
    this->positionX = positionX;
    this->positionY = positionY;
    this->width = width;
    this->height = height;
}

// Accesseurs...

const string* Player::getSprite()
{
    return this->sprite;
}

int Player::getPositionX()
{
    return this->positionX;
}

int Player::getPositionY()
{
    return this->positionY;
}

int Player::getWidth()
{
    return this->width;
}

int Player::getHeight()
{
    return this->height;
}
