/**
 *  @file   Bar.cpp
 *  @author Blurred-9L
 */

#include "Bar.h"

/**
 *  @details    The Bar object's default constructor. Sets width and height
 *              to 0.
 */
Bar::Bar() :
    GameObject(), width_(0.0), height_(0.0)
{
}

/**
 *  @details    The Bar object's destructor.
 */
Bar::~Bar()
{
}

/**
 *  @details    Gets the Bar's width attribute.
 *
 *  @return     The Bar's width.
 */
float Bar::width() const
{
    return width_;
}

/**
 *  @details    Gets the Bar's height attribute.
 *
 *  @return     The Bar's height.
 */
float Bar::height() const
{
    return height_;
}

/**
 *  @details    Sets the Bar's width attribute.
 *
 *  @param[in]  width               The new width.
 */
void Bar::setWidth(float width)
{
    width_ = width;
}

/**
 *  @details    Sets the Bar's height attribute.
 *
 *  @param[in]  height              The new height.
 */
void Bar::setHeight(float height)
{
    height_ = height;
}

/**
 *  @details    Updates the bar's position on the game's scene by adding
 *              it's speed on the respective axes to its current position.
 */
void Bar::updatePosition()
{
    x_ += xSpeed_;
    y_ += ySpeed_;
}

/**
 *  @details    Modifies the Bar's position to make it always stay inside
 *              the game's scene.
 *
 *  @param[in]  width               The game's scene width.
 *  @param[in]  height              The game's scene height.
 */
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

/**
 *  @details    Checks if a given point is inside the bar's bounding box.
 *
 *  @param[in]  x                   The x coordinate of the point.
 *  @param[in]  y                   The y coordinate of the point.
 *
 *  @return     A boolean value indicating if the given point is inside the
 *              bar's bounding box.
 */
bool Bar::contains(float x, float y)
{
    return ((x > x_) && (x < x_ + width_) && (y > y_) && (y < y_ + height_));
}

