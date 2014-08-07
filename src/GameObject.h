/**
 *  @file   GameObject.h
 *  @author Blurred-9L
 */

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

/**
 *  @class  GameObject
 *
 *  @brief  Base class that stores common data used during the game,
 *          including position coordinates and speed.
 */
class GameObject {
protected:
    /// The object's x coordinate.
    float x_;
    /// The object's y coordinate.
    float y_;
    /// The object's x speed.
    float xSpeed_;
    /// The object's y speed.
    float ySpeed_;
    
public:
    /// GameObject constructor.
    GameObject();
    /// GameObject destructor.
    virtual ~GameObject();
    /// Gets the object's x coordinate.
    float x() const;
    /// Gets the object's y coordinate.
    float y() const;
    /// Gets the object's x speed.
    float xSpeed() const;
    /// Gets the object's y speed.
    float ySpeed() const;
    /// Sets the object's x coordinate.
    void setX(float x);
    /// Sets the object's y coordinate.
    void setY(float y);
    /// Sets the object's x speed.
    void setXSpeed(float sx);
    /// Sets the object's y speed.
    void setYSpeed(float sy);
    /// Gets the magnitude of the speed vector.
    double getSpeedMagnitude() const;
    /// Gets the direction of the speed vector.
    double getSpeedDirection() const;
    /// Updates position.
    virtual void updatePosition() = 0;
    /// Prevents out of bounds movement.
    virtual void checkBounds(unsigned width, unsigned height) = 0;
    /// Checks if a point is inside the game's enclosing rectangle.
    virtual bool contains(float x, float y) = 0;
};

#endif /// NOT GAME_OBJECT_H
