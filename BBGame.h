#ifndef BB_GAME_H
#define BB_GAME_H

class BrickArea;
class Brick;
class Ball;
class Bar;

class BBGame {
private:
    /// The BrickArea object.
    BrickArea * brickArea_;
    /// The Ball object.
    Ball * ball_;
    /// The Bar object.
    Bar * bar_;
    /// Flag indicating if the game has started.
    bool active_;

public:
    /// The default number of rows.
    static const unsigned DEFAULT_ROWS;
    /// The default number of columns.
    static const unsigned DEFAULT_COLS;
    /// The default bar speed.
    static const float DEFAULT_BAR_SPEED;
    /// The default ball speed.
    static const float DEFAULT_BALL_SPEED;
    /// The minimum ball speed.
    static const float MIN_BALL_SPEED;

    /// BBGame default constructor.
    BBGame();
    /// BBGame destructor.
    ~BBGame();
    /// Gets the BrickArea instance.
    const BrickArea & brickArea() const;
    /// Gets the BrickArea instance.
    BrickArea & brickArea();
    /// Gets the Ball instance.
    const Ball & ball() const;
    /// Gets the Ball instance.
    Ball & ball();
    /// Gets the Bar instance.
    const Bar & bar() const;
    /// Gets the Bar instance.
    Bar & bar();
    /// Checks if the game is active.
    bool isActive() const;
    /// Sets the game active flag.
    void setActive(bool active);
    /// Performs action when a brick is hit.
    void onBrickHit(Brick & brick);
    /// Performs action when a brick is broken.
    void onBrickBroken(Brick & brick);
    /// Performs action when brick area is cleared.
    void onAreaClear();
    /// Performs action when the ball falls away.
    void onLose();
    /// Performs action when game over.
    void onGameOver();
    /// Performs action when Ball collides with Brick.
    void onBarBallCollision();
    /// Performs action when Ball collides with Bar.
    void onBrickBallCollision(Brick & brick);
    
    /// Checks collision between bar and ball.
    static bool checkCollision(Ball & ball, Bar & bar);
    /// Checks collision between bar and brick.
};

#endif /// NOT BB_GAME_H
