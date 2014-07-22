#include "GameObject.h"

#include <cmath>

GameObject::GameObject() :
    x_(0), y_(0), xSpeed_(0), ySpeed_(0)
{
}

GameObject::~GameObject()
{
}

float GameObject::x() const
{
    return x_;
}

float GameObject::y() const
{
    return y_;
}

float GameObject::xSpeed() const
{
    return xSpeed_;
}

float GameObject::ySpeed() const
{
    return ySpeed_;
}

void GameObject::setX(float x)
{
    x_ = x;
}

void GameObject::setY(float y)
{
    y_ = y;
}

void GameObject::setXSpeed(float sx)
{
    xSpeed_ = sx;
}

void GameObject::setYSpeed(float sy)
{
    ySpeed_ = sy;
}

double GameObject::getSpeedMagnitude() const
{
    return sqrt(xSpeed_ * xSpeed_ + ySpeed_ * ySpeed_);
}

double GameObject::getSpeedDirection() const
{
    return atan2(ySpeed_, xSpeed_);
}
