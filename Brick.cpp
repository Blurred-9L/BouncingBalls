/**
 *  @file   Brick.cpp
 *  @author Blurred-9L
 */

#include "Brick.h"
#include "BrickArea.h"

const float Brick::DEFAULT_WIDTH = 40.0;
const float Brick::DEFAULT_HEIGHT = 20.0;

/**
 *  @details    The Brick object's constructor.
 */
Brick::Brick() :
    row_(0), column_(0), parent_(0), hitPoints_(1), breakable_(true),
    color_(0)
{
}

/**
 *  @details    The Brick object's destructor.
 */
Brick::~Brick()
{
}

/**
 *  @details    Gets the Brick's row attribute.
 *
 *  @return     The Brick's row.
 */
unsigned Brick::row() const
{
    return row_;
}

/**
 *  @details    Gets the Brick's column attribute.
 *
 *  @return     The Brick's column.
 */
unsigned Brick::column() const
{
    return column_;
}

/**
 *  @details    Gets the Brick's parent attribute.
 *
 *  @return     A constant reference to the Brick's parent.
 */
const BrickArea & Brick::parent() const
{
    return *parent_;
}

/**
 *  @details    Gets the Brick's parent attribute.
 *
 *  @return     A reference to the Brick's parent.
 */
BrickArea & Brick::parent()
{
    return *parent_;
}

/**
 *  @details    Gets the Brick's hitPoints attribute.
 *
 *  @return     The Brick's hit points.
 */
int Brick::hitPoints() const
{
    return hitPoints_;
}

/**
 *  @details    Gets the Brick's breakable attribute.
 *
 *  @return     The value of the 'brick is breakable' flag.
 */
bool Brick::isBreakable() const
{
    return breakable_;
}

/**
 *  @details    Gets the Brick's color attribute.
 *
 *  @return     The Brick's color.
 */
unsigned Brick::color() const
{
    return color_;
}

/**
 *  @details    Sets the Brick's row attribute.
 *
 *  @param[in]  row                 The brick's new row.
 */
void Brick::setRow(unsigned row)
{
    row_ = row;
}

/**
 *  @details    Sets the Brick's column attribute.
 *
 *  @param[in]  column              The brick's new column.
 */
void Brick::setColumn(unsigned column)
{
    column_ = column;
}

/**
 *  @details    Sets the Brick's parent attribute.
 *
 *  @param[in]  parent              The brick's new parent.
 */
void Brick::setParent(BrickArea * parent)
{
    parent_ = parent;
}

/**
 *  @details    Sets the Brick's hitPoints attribute.
 *
 *  @param[in]  hitPoints           The brick's new hit points value.
 */
void Brick::setHitPoints(int hitPoints)
{
    hitPoints_ = hitPoints;
}

/**
 *  @details    Sets the Brick's breakable attribute.
 *
 *  @param[in]  breakable           The new state of the 'brick is breakable' flag.
 */
void Brick::setBreakable(bool breakable)
{
    breakable_ = breakable;
}

/**
 *  @details    Sets the Brick's color attribute.
 *
 *  @param[in]  color               The brick's new color.
 */
void Brick::setColor(unsigned color)
{
    if (color < BRICK_COLOR_N_COLORS) {
        color_ = color;
    }
}

/**
 *  @details    Checks if the brick is already broken.
 *
 *  @return     A boolean value indicating if the brick is broken.
 */
bool Brick::isBroken() const
{
    return hitPoints_ == 0;
}
