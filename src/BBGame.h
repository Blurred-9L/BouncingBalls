/**
 *  @file   BBGame.h
 *  @author Blurred-9L
 */

#ifndef BB_GAME_H
#define BB_GAME_H

class BrickArea;
class Brick;
class Ball;
class Bar;
class SoundPlayer;
class LevelLoader;

/**
 *  @class  BBGame
 *
 *  @brief  Holds related information to the BouncingBalls game.
 */
class BBGame {
private:
    /// The BrickArea object.
    BrickArea * brickArea_;
    /// The Ball object.
    Ball * ball_;
    /// The Bar object.
    Bar * bar_;
    /// The current level being played.
    unsigned levelNumber_;
    /// Flag indicating if the game has started.
    bool active_;
    /// Flag indicating if the level needs to be redrawn.
    bool drawLevel_;
    /// The sound player used for sound effect.
    SoundPlayer * soundPlayer_;
    /// The level loader used.
    LevelLoader * levelLoader_;

public:
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
    /// Gets the level number.
    unsigned levelNumber() const;
    /// Checks if the game is active.
    bool isActive() const;
    /// Checks if level should be drawn.
    bool shouldDrawLevel() const;
    /// Gets the LevelLoader instance.
    const LevelLoader & levelLoader() const;
    /// Gets the LevelLoader instance.
    LevelLoader & levelLoader();
    /// Sets the level number.
    void setLevelNumber(unsigned levelNumber);
    /// Sets the game active flag.
    void setActive(bool active);
    /// Sets the draw level flag.
    void setDrawLevel(bool draw);
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
    
    /// Checks collision between bar and ball.
    static bool checkCollision(Ball & ball, Bar & bar);
    /// Checks collision between ball and brick.
    static int checkCollision(Ball & ball, Brick & brick);
};

#endif /// NOT BB_GAME_H
