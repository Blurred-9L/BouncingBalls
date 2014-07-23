#ifndef BRICK_H
#define BRICK_H

class BrickArea;

/**
 *  @class  Brick
 */
class Brick {
private:
    /// The brick's row on its parent.
    unsigned row_;
    /// The brick's column on its parent.
    unsigned column_;
    /// The brick's BrickArea parent.
    BrickArea * parent_;
    /// The brick's hit points.
    int hitPoints_;
    /// Flag indicating if the brick can be broken.
    bool breakable_;
    /// The brick's color.
    unsigned color_;

public:
    /// The default brick width.
    static const float DEFAULT_WIDTH;
    /// The default brick height.
    static const float DEFAULT_HEIGHT;

    /**
     *  @enum   BrickType
     */
    enum BrickType {
        BRICK_TYPE_NORMAL,
        BRICK_TYPE_METAL,
        BRICK_TYPE_IMMORTAL,
        BRICK_TYPE_N_TYPES
    };
     
    /**
     *  @enum   BrickColor
     */
    enum BrickColor {
        BRICK_COLOR_RED,
        BRICK_COLOR_GREEN,
        BRICK_COLOR_BLUE,
        BRICK_COLOR_CYAN,
        BRICK_COLOR_MAGENTA,
        BRICK_COLOR_YELLOW,
        BRICK_COLOR_SILVER,
        BRICK_COLOR_GOLDEN,
        BRICK_COLOR_N_COLORS
    };

    /// Brick default constructor.
    Brick();
    /// Brick destructor.
    ~Brick();
    /// Gets the brick's row.
    unsigned row() const;
    /// Gets the brick's column.
    unsigned column() const;
    /// Gets the brick's parent.
    const BrickArea & parent() const;
    /// Gets the brick's parent.
    BrickArea & parent();
    /// Gets the brick's hit points.
    int hitPoints() const;
    /// Checks if the brick is breakable.
    bool isBreakable() const;
    /// Gets the brick's color.
    unsigned color() const;
    /// Sets the brick's row.
    void setRow(unsigned row);
    /// Sets the brick's column.
    void setColumn(unsigned column);
    /// Sets the brick's parent.
    void setParent(BrickArea * parent);
    /// Sets the brick's hit points.
    void setHitPoints(int hitPoints);
    /// Sets the brick's breakable status.
    void setBreakable(bool breakable);
    /// Sets the brick's color.
    void setColor(unsigned color);
    /// Checks if the brick is broken.
    bool isBroken() const;
};

#endif /// NOT BRICK_H
