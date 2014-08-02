/**
 *  @file   Bar.h
 *  @author Blurred-9L
 */

#ifndef BAR_H
#define BAR_H

#include "GameObject.h"

/**
 *  @class  Bar
 *
 *  @brief  Class representing the movable bar on the bottom
 *          of the screen used to mantain the ball in play.
 */
class Bar : public GameObject {
private:
    /// The Bar's width.
    float width_;
    /// The Bar's height.
    float height_;
    
public:

    /**
     *  @enum   BarPixelRange
     *
     *  @brief  Ranges used to check towards which direction the
     *          ball should bounce.
     */
    enum BarPixelRange {
        RANGE_LEFT_ACUTE = 5,
        RANGE_LEFT_STRAIGHT = 30,
        RANGE_LEFT_UPWARD = 50,
        RANGE_RIGHT_UPWARD = 70,
        RANGE_RIGHT_STRAIGHT = 95,
        RANGE_RIGHT_ACUTE = 100
    };

    /// Bar constructor.
    Bar();
    /// Bar destructor.
    virtual ~Bar();
    /// Gets the Bar's width.
    float width() const;
    /// Gets the Bar's height.
    float height() const;
    /// Sets the Bar's width.
    void setWidth(float width);
    /// Sets the Bar's height.
    void setHeight(float height);
    /// Updates position.
    virtual void updatePosition();
    /// Prevents out of bounds movement.
    virtual void checkBounds(unsigned width, unsigned height);
    /// Checks if a point is inside the bar's rectangle.
    virtual bool contains(float x, float y);
};

#endif /// NOT BAR_H
