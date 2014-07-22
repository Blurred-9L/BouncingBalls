#include "Ball.h"

Ball::Ball() :
    radius_(0)
{
}

Ball::~Ball()
{
}

float Ball::radius() const
{
    return radius_;
}

void Ball::setRadius(float radius)
{
    radius_ = radius;
}

void Ball::updatePosition()
{
    x_ += xSpeed_;
    y_ += ySpeed_;
}

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
    } else if (y_ + rectWidth > height) {
        ySpeed_ = -ySpeed_;
        y_ = height - rectWidth;
    }
}

bool Ball::contains(float x, float y)
{
    float width, height;
    
    width = height = radius_ * 2;
    
    return ((x > x_) && (x < x_ + width) && (y > y_) && (y < y_ + height));
}
