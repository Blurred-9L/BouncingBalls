#ifndef BAR_H
#define BAR_H

#include "GameObject.h"

class Bar : public GameObject {
private:
    /// The Bar's width.
    float width_;
    /// The Bar's height.
    float height_;
    
public:
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
