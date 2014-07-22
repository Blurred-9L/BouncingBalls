#ifndef BALL_H
#define BALL_H

#include "GameObject.h"

class Ball : public GameObject {
protected:
    float radius_;
    
public:
    /// Ball constructor.
    Ball();
    /// Ball destructor.
    virtual ~Ball();
    /// Gets the ball's radius.
    float radius() const;
    /// Sets the ball's radius.
    void setRadius(float radius);
    /// Updates position.
    virtual void updatePosition();
    /// Prevents out of bounds movement.
    virtual void checkBounds(unsigned width, unsigned height);
    /// Checks if a point is inside the ball's rectangle.
    virtual bool contains(float x, float y);
};

#endif /// NOT BALL_H
