#include "Bar.h"

Bar::Bar() :
    GameObject(), width_(0.0), height_(0.0)
{
}

Bar::~Bar()
{
}

float Bar::width() const
{
    return width_;
}

float Bar::height() const
{
    return height_;
}

void Bar::setWidth(float width)
{
    width_ = width;
}

void Bar::setHeight(float height)
{
    height_ = height;
}

void Bar::updatePosition()
{
    x_ += xSpeed_;
    y_ += ySpeed_;
}

void Bar::checkBounds(unsigned width, unsigned height)
{
    if (x_ < 0) {
        x_ = 0;
    } else if (x_ + width_ > width) {
        x_ = width - width_;
    }
    
    if (y_ < 0) {
        y_ = 0;
    } else if (y_ + height_ > height) {
        y_ = height - height_;
    }
}

bool Bar::contains(float x, float y)
{
    return ((x > x_) && (x < x_ + width_) && (y > y_) && (y < y_ + height_));
}

