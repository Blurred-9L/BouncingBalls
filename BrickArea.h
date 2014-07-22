#ifndef BRICK_AREA_H
#define BRICK_AREA_H

class Brick;

/**
 *  @class  BrickArea
 */
class BrickArea {
private:
    /// The bricks on the area.
    Brick * bricks_;
    /// The number of rows.
    unsigned nRows_;
    /// The number of columns.
    unsigned nColumns_;
    /// The total number of bricks on the area.
    unsigned totalBricks_;
    /// The number of breakable bricks on the area.
    unsigned breakableBricks_;
    /// The number of not yet broken bricks.
    unsigned remainingBricks_;
    
public:
    /// BrickArea constructor.
    BrickArea(unsigned nRows, unsigned nColumns);
    /// BrickArea destructor.
    ~BrickArea();
    /// Gets the array of bricks.
    const Brick * bricks() const;
    /// Gets the array of bricks.
    Brick * bricks();
    /// Gets the number of rows.
    unsigned nRows() const;
    /// Gets the number of columns.
    unsigned nColumns() const;
    /// Gets the total of bricks.
    unsigned totalBricks() const;
    /// Gets the number of breakable bricks.
    unsigned breakableBricks() const;
    /// Gets the number of remaining bricks.
    unsigned remainingBricks() const;
    /// Sets the total of bricks.
    void setTotalBricks(unsigned totalBricks);
    /// Sets the number of breakable bricks.
    void setBreakableBricks(unsigned breakableBricks);
    /// Sets the number of reamining bricks.
    void setRemainingBricks(unsigned remainingBricks);
    /// Loads a level onto this object.
    bool loadLevel(const char * levelName);
    /// Checks if the area has been cleared.
    bool isCleared() const;
};

#endif /// NOT BRICK_AREA_H
