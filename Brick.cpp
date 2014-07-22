#include "Brick.h"
#include "BrickArea.h"

Brick::Brick() :
    row_(0), column_(0), parent_(0), hitPoints_(1), breakable_(true),
    color_(0)
{
}

Brick::~Brick()
{
}

unsigned Brick::row() const
{
    return row_;
}

unsigned Brick::column() const
{
    return column_;
}

const BrickArea & Brick::parent() const
{
    return *parent_;
}

BrickArea & Brick::parent()
{
    return *parent_;
}

int Brick::hitPoints() const
{
    return hitPoints_;
}

bool Brick::isBreakable() const
{
    return breakable_;
}

unsigned Brick::color() const
{
    return color_;
}

void Brick::setRow(unsigned row)
{
    row_ = row;
}

void Brick::setColumn(unsigned column)
{
    column_ = column;
}

void Brick::setParent(BrickArea * parent)
{
    parent_ = parent;
}

void Brick::setHitPoints(int hitPoints)
{
    hitPoints_ = hitPoints;
}

void Brick::setBreakable(bool breakable)
{
    breakable_ = breakable;
}

void Brick::setColor(unsigned color)
{
    if (color < BRICK_COLOR_N_COLORS) {
        color_ = color;
    }
}

bool Brick::isBroken() const
{
    return hitPoints_ != 0;
}
