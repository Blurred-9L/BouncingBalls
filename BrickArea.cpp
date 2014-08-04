/**
 *  @file   BrickArea.cpp
 *  @author Blurred-9L
 */

#include "BrickArea.h"
#include "Brick.h"

/**
 *  @details    The BrickArea object's constructor. The coordinate (0,0)
 *              for (row, column) corresponds to the game's scene coordinate
 *              (0,0) in (x, y) coordinates.
 *
 *  @param[in]  nRows               The number of max rows on the brick area.
 *  @param[in]  nColumns            The number of max columns on the brick area.
 */
BrickArea::BrickArea(unsigned nRows, unsigned nColumns) :
    bricks_(0), nRows_(nRows), nColumns_(nColumns), totalBricks_(0),
    breakableBricks_(0), remainingBricks_(0)
{
    unsigned size = nRows * nColumns;
    
    bricks_ = new Brick[size];
    for (unsigned i = 0; i < size; i++) {
        bricks_[i].setParent(this);
    }
}

/**
 *  @details    The BrickArea object's destructor.
 */
BrickArea::~BrickArea()
{
    if (bricks_ != 0) {
        delete [] bricks_;
    }
}

/**
 *  @details    Gets the BrickArea's bricks attribute.
 *
 *  @return     A constant pointer to the array of bricks.
 */
const Brick * BrickArea::bricks() const
{
    return bricks_;
}

/**
 *  @details    Gets the BrickArea's bricks attribute.
 *
 *  @return     A pointer to the array of bricks.
 */
Brick * BrickArea::bricks()
{
    return bricks_;
}

/**
 *  @details    Gets the BrickArea's nRows attribute.
 *
 *  @return     The BrickArea's number of rows.
 */
unsigned BrickArea::nRows() const
{
    return nRows_;
}

/**
 *  @details    Gets the BrickArea's nColumns attribute.
 *
 *  @return     The BrickArea's number of columns.
 */
unsigned BrickArea::nColumns() const
{
    return nColumns_;
}

/**
 *  @details    Gets the BrickArea's totalBricks attribute.
 *
 *  @return     The BrickArea's total number of bricks including breakable
 *              and non-breakable.
 */
unsigned BrickArea::totalBricks() const
{
    return totalBricks_;
}

/**
 *  @details    Gets the BrickArea's breakableBricks attribute.
 *
 *  @return     The BrickArea's number of breakable bricks.
 */
unsigned BrickArea::breakableBricks() const
{
    return breakableBricks_;
}

/**
 *  @details    Gets the BrickArea's remainingBricks attribute.
 *
 *  @return     The BrickArea's number of bricks yet to be broken.
 */
unsigned BrickArea::remainingBricks() const
{
    return remainingBricks_;
}

/**
 *  @details    Sets the BrickArea's totalBricks attribute.
 *
 *  @param[in]  totalBricks         The new number of total bricks.
 */
void BrickArea::setTotalBricks(unsigned totalBricks)
{
    totalBricks_ = totalBricks;
}

/**
 *  @details    Sets the BrickArea's breakableBricks attribute.
 *
 *  @param[in]  breakableBricks     The new number of breakable bricks.
 */
void BrickArea::setBreakableBricks(unsigned breakableBricks)
{
    breakableBricks_ = breakableBricks;
}

/**
 *  @details    Sets the BrickArea's remainingBricks attribute.
 *
 *  @param[in]  remainingBricks     The new number of remaining bricks.
 */
void BrickArea::setRemainingBricks(unsigned remainingBricks)
{
    remainingBricks_ = remainingBricks;
}

/**
 *  @details    Checks if all the bricks that can be broken are
 *              already broken.
 *
 *  @return     A boolean value indicating if the area has been cleared.
 */
bool BrickArea::isCleared() const
{
    return (remainingBricks_ == 0);
}
