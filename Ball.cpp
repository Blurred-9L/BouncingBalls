/**
 *  @file   Ball.cpp
 *  @author Blurred-9L
 */

#include "Ball.h"

/**
 *  @details    The Ball object's default constructor. Sets radius to 0.
 */
Ball::Ball() :
    radius_(0)
{
}

/**
 *  @details    The Ball object's destructor.
 */
Ball::~Ball()
{
}

/**
 *  @details    Gets the Ball's radius attribute.
 *
 *  @return     The radius of the Ball object.
 */
float Ball::radius() const
{
    return radius_;
}

/**
 *  @details    Sets the Ball's radius attribute.
 *
 *  @param[in]  radius              The new radius for the ball.
 */
void Ball::setRadius(float radius)
{
    radius_ = radius;
}

/**
 *  @details    Updates the Ball's position on the game's scene by
 *              calculating the next x and y coordinates of the ball
 *              by adding its speed on the x and y axis.
 */
void Ball::updatePosition()
{
    x_ += xSpeed_;
    y_ += ySpeed_;
}

/**
 *  @details    Modifies the ball's position to stay on a valid position
 *              inside the game's scene. The ball is only allowed to exit
 *              this area through its bottom, which results in a life lost.
 *
 *  @param[in]  width               The width of the game's scene.
 *  @param[in]  height              The height of the game's scene.
 */
void Ball::checkBounds(unsigned width, unsigned height)
{
    float rectWidth = radius_ * 2;
    
    if (x_ < 0) {
        xSpeed_ = -xSpeed_;
        x_ = 0;
    } else if (x_ + rectWidth > width) {
        xSpeed_ = -xSpeed_;
        x_ = width - rectWidth;
    }
    
    if (y_ < 0) {
        ySpeed_ = -ySpeed_;
        y_ = 0;
    }
}

/**
 *  @details    Checks if a given point is inside the ball's bounding box.
 *
 *  @param[in]  x                   The x coordinate of the point.
 *  @param[in]  y                   The y coordinate of the point.
 *
 *  @return     A boolean value indicating if the given point is inside the
 *              ball's bounding box.
 */
bool Ball::contains(float x, float y)
{
    float width, height;
    
    width = height = radius_ * 2;
    
    return ((x > x_) && (x < x_ + width) && (y > y_) && (y < y_ + height));
}
