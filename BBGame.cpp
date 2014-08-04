/**
 *  @file  BBGame.cpp
 *  @author Blurred-9L
 */

#include "BBGame.h"
#include "BrickArea.h"
#include "Ball.h"
#include "Bar.h"
#include "Brick.h"
#include "ThreadWorker.h"
#include "BBController.h"
#include "BBSoundPlayer.h"
#include "LevelLoader.h"

#include <cmath>
#include <iostream>

const unsigned BBGame::DEFAULT_ROWS = 20;
const unsigned BBGame::DEFAULT_COLS = 12;
const float BBGame::DEFAULT_BAR_SPEED = 6.0;
const float BBGame::DEFAULT_BALL_SPEED = 6.0;
const float BBGame::MIN_BALL_SPEED = 1.0;
const float BBGame::BALL_RADIUS = 6.0;
const float BBGame::BAR_WIDTH = 100.0;
const float BBGame::BAR_HEIGHT = 20.0;
const float BBGame::BALL_START_X = 234.0;
const float BBGame::BALL_START_Y = 568.0;
const float BBGame::BAR_START_X = 190.0;
const float BBGame::BAR_START_Y = 580.0;

/**
 *  @details    The BBGame object's constructor. Instantiates the
 *              ball, bar and brick area objects and sets their
 *              starting positions.
 */
BBGame::BBGame() :
    brickArea_(0), ball_(0), bar_(0), active_(false), drawLevel_(false),
    soundPlayer_(0), levelLoader_(0)
{
    /// Set ball starting position and radius.
    ball_ = new Ball();
    ball_->setRadius(BALL_RADIUS);
    ball_->setX(BALL_START_X);
    ball_->setY(BALL_START_Y);
    /// Set bar starting position, width and height.
    bar_ = new Bar();
    bar_->setWidth(BAR_WIDTH);
    bar_->setHeight(BAR_HEIGHT);
    bar_->setX(BAR_START_X);
    bar_->setY(BAR_START_Y);
    /// Creates the BrickArea object.
    brickArea_ = new BrickArea(DEFAULT_ROWS, DEFAULT_COLS);
    
    soundPlayer_ = new BBSoundPlayer();
    
    levelLoader_ = new LevelLoader();
}

/**
 *  @details    The BBGame object's destructor.
 */
BBGame::~BBGame()
{
    if (brickArea_ != 0) {
        delete brickArea_;
    }
    if (ball_ != 0) {
        delete ball_;
    }
    if (bar_ != 0) {
        delete bar_;
    }
    if (soundPlayer_ != 0) {
        delete soundPlayer_;
    }
    if (levelLoader_ != 0) {
        delete levelLoader_;
    }
}

/**
 *  @details    Gets the BBGame's brickArea attribute.
 *
 *  @return     A constant reference to the BBGame's BrickArea object.
 */
const BrickArea & BBGame::brickArea() const
{
    return *brickArea_;
}

/**
 *  @details    Gets the BBGame's brickArea attribute.
 *
 *  @return     A reference to the BBGame's BrickArea object.
 */
BrickArea & BBGame::brickArea()
{
    return *brickArea_;
}

/**
 *  @details    Gets the BBGame's ball attribute.
 *
 *  @return     A constant reference to the BBGame's Ball object.
 */
const Ball & BBGame::ball() const
{
    return *ball_;
}

/**
 *  @details    Gets the BBGame's ball attribute.
 *
 *  @return     A reference to the BBGame's Ball object.
 */
Ball & BBGame::ball()
{
    return *ball_;
}

/**
 *  @details    Gets the BBGame's bar attribute.
 *
 *  @return     A constant reference to the BBGame's Bar object.
 */
const Bar & BBGame::bar() const
{
    return *bar_;
}

/**
 *  @details    Gets the BBGame's bar attribute.
 *
 *  @return     A reference to the BBGame's Bar object.
 */
Bar & BBGame::bar()
{
    return *bar_;
}

/**
 *  @details    Gets the BBGame's active attribute.
 *
 *  @return     The boolean value of the game active flag.
 */
bool BBGame::isActive() const
{
    return active_;
}

/**
 *  @details    Gets the BBGame's drawLevel attribute.
 *
 *  @return     The boolean value of the 'should draw level' flag.
 */
bool BBGame::shouldDrawLevel() const
{
    return drawLevel_;
}

/**
 *  @details    Gets the BBGame's levelLoader attribute.
 *
 *  @return     A constant reference to the LevelLoader object.
 */
const LevelLoader & BBGame::levelLoader() const
{
    return *levelLoader_;
}

/**
 *  @details    Gets the BBGame's levelLoader attribute.
 *
 *  @return     A reference to the LevelLoader object.
 */
LevelLoader & BBGame::levelLoader()
{
    return *levelLoader_;
}

/**
 *  @details    Sets the BBGame's active attribute.
 *
 *  @param[in]  active              The new value of the 'game is active' flag.
 */
void BBGame::setActive(bool active)
{
    active_ = active;
}

/**
 *  @details    Sets the BBGame's drawLevel attribute.
 *
 *  @param[in]  draw                The new value of the 'should draw level' flag.
 */
void BBGame::setDrawLevel(bool draw)
{
    drawLevel_ = draw;
}

/**
 *  @details    Responds to the event of a given brick being hit by the ball.
 *
 *  @param[in]  brick               The brick that was hit.
 */
void BBGame::onBrickHit(Brick & brick)
{
    if (!brick.isBroken() && brick.isBreakable()) {
        brick.setHitPoints(brick.hitPoints() - 1);
        soundPlayer_->playSound(BBController::BALL_BOUNCE_SOUND);
        if (brick.isBroken()) {
            this->onBrickBroken(brick);
        }
    }
}

/**
 *  @details    Responds to the event of a brick being broken by the ball.
 */
void BBGame::onBrickBroken(Brick & brick)
{
    brickArea_->setRemainingBricks(brickArea_->remainingBricks() - 1);
    /// Increase player score.
    if (brickArea_->isCleared()) {
        this->onAreaClear();
    }
}

/**
 *  @details    Responds to the event of the game area being cleared.
 */
void BBGame::onAreaClear()
{
    std::cout << "Area clear!" << std::endl;
    /// Update score counter.
    /// Play victory sound.
    /// Check if next level exists.
    /// Load next level.
    /// Set ball to default.
    ball_->setX(BALL_START_X);
    ball_->setY(BALL_START_Y);
    ball_->setXSpeed(0);
    ball_->setYSpeed(0);
    /// Set bar to default.
    bar_->setX(BAR_START_X);
    bar_->setY(BAR_START_Y);
    bar_->setXSpeed(0);
    bar_->setYSpeed(0);
    /// Wait a bit.
    ThreadWorker::wait(1000);
    /// Start again.
    active_ = false;
}

/**
 *  @details    Responds to the event of the ball falling off the game's
 *              scene.
 */
void BBGame::onLose()
{
    std::cout << "Lost a life!" << std::endl;
    /// Update life counter.
    /// Play death sound.
    /// Check that game is not over.
    /// Set ball to default.
    ball_->setX(BALL_START_X);
    ball_->setY(BALL_START_Y);
    ball_->setXSpeed(0);
    ball_->setYSpeed(0);
    /// Set bar to default.
    bar_->setX(BAR_START_X);
    bar_->setY(BAR_START_Y);
    bar_->setXSpeed(0);
    bar_->setYSpeed(0);
    /// Wait a bit.
    ThreadWorker::wait(1000);
    /// Start again.
    active_ = false;
}

/**
 *  @details    Responds to the event of the player losing all their available
 *              lives.
 */
void BBGame::onGameOver()
{
}

/**
 *  @details    Responds to the event of the Ball object colliding with the Bar
 *              object. The new direction of the Ball object is determined by
 *              the range on which the Ball was found colliding with the Bar.
 */
void BBGame::onBarBallCollision()
{
    float ballX = ball_->x();
    float barX = bar_->x();
    
    if ((ballX >= barX) && (ballX <= barX + Bar::RANGE_LEFT_ACUTE)) {
        ball_->setXSpeed(-DEFAULT_BALL_SPEED * 1.5);
    } else if ((ballX > barX + Bar::RANGE_LEFT_ACUTE) && (ballX <= barX + Bar::RANGE_LEFT_STRAIGHT)) {
        ball_->setXSpeed(-DEFAULT_BALL_SPEED);
    } else if ((ballX > barX + Bar::RANGE_LEFT_STRAIGHT) && (ballX <= barX + Bar::RANGE_LEFT_UPWARD)) {
        ball_->setXSpeed(-DEFAULT_BALL_SPEED * 0.5);
    } else if ((ballX > barX + Bar::RANGE_LEFT_UPWARD) && (ballX <= barX + Bar::RANGE_RIGHT_UPWARD)) {
        ball_->setXSpeed(DEFAULT_BALL_SPEED * 0.5);
    } else if ((ballX > barX + Bar::RANGE_RIGHT_UPWARD) && (ballX <= barX + Bar::RANGE_RIGHT_STRAIGHT)) {
        ball_->setXSpeed(DEFAULT_BALL_SPEED);
    } else if ((ballX > barX + Bar::RANGE_RIGHT_STRAIGHT) && (ballX <= barX + Bar::RANGE_RIGHT_UPWARD)){
        ball_->setXSpeed(DEFAULT_BALL_SPEED * 1.5);
    }
    ball_->setYSpeed(-ball_->ySpeed());
    soundPlayer_->playSound(BBController::BALL_BOUNCE_SOUND);
}

/**
 *  @details    Checks if a collision occurred between the Ball object and
 *              the Bar object.
 *
 *  @param[in]  ball                The ball object.
 *  @param[in]  bar                 The bar object.
 *
 *  @return     A boolean value indicating if there was a collision or not.
 */
bool BBGame::checkCollision(Ball & ball, Bar & bar)
{
    float left, right, up, down;
    float barHalfWidth = bar.width() * 0.5;
    float barHalfHeight = bar.height() * 0.5;
    float ballCenterX = ball.x() + ball.radius();
    float ballCenterY = ball.y() + ball.radius();
    float barCenterX = bar.x() + barHalfWidth;
    float barCenterY = bar.y() + barHalfHeight;
    float auxValue, lengthX, lengthY, gapX, gapY;
    bool collision = false;
    bool onRight = false;
    bool onTop = false;
    
    left = ballCenterX;
    right = barCenterX;
    if (ballCenterX >= barCenterX) {
        auxValue = left;
        left = right;
        right = auxValue;
        onRight = true;
    }
    lengthX = right - left;
    gapX = lengthX - ball.radius() - barHalfWidth; 
    if (gapX <= 0) {
        up = barCenterY;    
        down = ballCenterY;
        if (ballCenterY <= barCenterY) {
            auxValue = up;
            up = down;
            down = auxValue;
            onTop = true;
        }
        lengthY = down - up;
        gapY = lengthY - ball.radius() - barHalfHeight;
        if (gapY <= 0) {
            collision = true;
        }
    }
    
    return collision;
}

/**
 *  @details    Checks if a collision occurred between the Ball object and
 *              a Brick object.
 *
 *  @param[in]  ball                The ball object.
 *  @param[in]  brick               The brick object.
 *
 *  @return     An integer value indicating if there was a collision and the
 *              axis that needs to be reversed during the ball's posterior
 *              bounce.
 *
 *  @retval     0                   No collision occurred.
 *  @retval     1                   A collision ocurred. Reverse on x axis needed.
 *  @retval     -1                  A collision ocurred. Reverse on y axis needed.
 */
int BBGame::checkCollision(Ball & ball, Brick & brick)
{
    float left, right, up, down;
    float brickHalfWidth = Brick::DEFAULT_WIDTH * 0.5;
    float brickHalfHeight = Brick::DEFAULT_HEIGHT * 0.5;
    float ballCenterX = ball.x() + ball.radius();
    float ballCenterY = ball.y() + ball.radius();
    float brickCenterX = brick.column() * Brick::DEFAULT_WIDTH + brickHalfWidth;
    float brickCenterY = brick.row() * Brick::DEFAULT_HEIGHT + brickHalfHeight;
    float auxValue, lengthX, lengthY, gapX, gapY;
    bool collision = false;
    bool onRight = false;
    bool onTop = false;
    int retValue = 0;
    
    left = ballCenterX;
    right = brickCenterX;
    if (ballCenterX >= brickCenterX) {
        auxValue = left;
        left = right;
        right = auxValue;
        onRight = true;
    }
    lengthX = right - left;
    gapX = lengthX - ball.radius() - brickHalfWidth; 
    if (gapX <= 0) {
        up = brickCenterY;    
        down = ballCenterY;
        if (ballCenterY <= brickCenterY) {
            auxValue = up;
            up = down;
            down = auxValue;
            onTop = true;
        }
        lengthY = down - up;
        gapY = lengthY - ball.radius() - brickHalfHeight;
        if (gapY <= 0) {
            collision = true;
        }
    }
    
    if (collision) {
        if (gapX > gapY) {
            retValue = 1;
        } else {
            retValue = -1;
        }
    }
    
    return retValue;
}

