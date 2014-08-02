/**
 *  @file   GameObject.cpp
 *  @author Blurred-9L
 */

#include "GameObject.h"

#include <cmath>

/**
 *  @details    The GameObject's constructor. Sets everything to 0.
 */
GameObject::GameObject() :
    x_(0), y_(0), xSpeed_(0), ySpeed_(0)
{
}

/**
 *  @details    The GameObject's destructor.
 */
GameObject::~GameObject()
{
}

/**
 *  @details    Gets the GameObject's x attribute.
 *
 *  @return     The x coordinate of the GameObject.
 */
float GameObject::x() const
{
    return x_;
}

/**
 *  @details    Gets the GameObject's y attribute.
 *
 *  @return     The y coordinate of the GameObject.
 */
float GameObject::y() const
{
    return y_;
}

/**
 *  @details    Gets the GameObject's xSpeed attribute.
 *
 *  @return     The speed of the GameObject along the x axis.
 */
float GameObject::xSpeed() const
{
    return xSpeed_;
}

/**
 *  @details    Gets the GameObject's ySpeed attribute.
 *
 *  @return     The speed of the GameObject along the y axis.
 */
float GameObject::ySpeed() const
{
    return ySpeed_;
}

/**
 *  @details    Sets the GameObject's x attribute.
 *
 *  @param[in]  x                   The new x coordinate of the GameObject.
 */
void GameObject::setX(float x)
{
    x_ = x;
}

/**
 *  @details    Sets the GameObject's y attribute.
 *
 *  @param[in]  y                   The new y coordinate of the GameObject.
 */
void GameObject::setY(float y)
{
    y_ = y;
}

/**
 *  @details    Sets the GameObject's xSpeed attribute.
 *
 *  @param[in]  sx                  The new speed along the x axis.
 */
void GameObject::setXSpeed(float sx)
{
    xSpeed_ = sx;
}

/**
 *  @details    Sets the GameObject's ySpeed attribute.
 *
 *  @param[in]  sy                  The new speed along the y axis.
 */
void GameObject::setYSpeed(float sy)
{
    ySpeed_ = sy;
}

/**
 *  @details    Computes the magnitude of the GameObject's speed vector.
 *
 *  @return     The magnitude of the GameObject's speed vector.
 */
double GameObject::getSpeedMagnitude() const
{
    return sqrt(xSpeed_ * xSpeed_ + ySpeed_ * ySpeed_);
}

/**
 *  @details    Computes the direction of the GameObject's speed vector.
 *
 *  @return     The direction of the GameObject's speed vector in radians.
 */
double GameObject::getSpeedDirection() const
{
    return atan2(ySpeed_, xSpeed_);
}
