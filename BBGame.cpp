#include "BBGame.h"
#include "BrickArea.h"
#include "Ball.h"
#include "Bar.h"
#include "Brick.h"

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

BBGame::BBGame() :
    brickArea_(0), ball_(0), bar_(0), active_(false), drawLevel_(false)
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
}

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
}

const BrickArea & BBGame::brickArea() const
{
    return *brickArea_;
}

BrickArea & BBGame::brickArea()
{
    return *brickArea_;
}

const Ball & BBGame::ball() const
{
    return *ball_;
}

Ball & BBGame::ball()
{
    return *ball_;
}

const Bar & BBGame::bar() const
{
    return *bar_;
}

Bar & BBGame::bar()
{
    return *bar_;
}

bool BBGame::isActive() const
{
    return active_;
}

bool BBGame::shouldDrawLevel() const
{
    return drawLevel_;
}

void BBGame::setActive(bool active)
{
    active_ = active;
}

void BBGame::setDrawLevel(bool draw)
{
    drawLevel_ = draw;
}

void BBGame::onBrickHit(Brick & brick)
{
    if (!brick.isBroken() && brick.isBreakable()) {
        brick.setHitPoints(brick.hitPoints() - 1);
        /// Play hit sound.
        if (brick.isBroken()) {
            this->onBrickBroken(brick);
        }
    }
}

void BBGame::onBrickBroken(Brick & brick)
{
    brickArea_->setRemainingBricks(brickArea_->remainingBricks() - 1);
    /// Increase player score.
    if (brickArea_->isCleared()) {
        this->onAreaClear();
    }
}

void BBGame::onAreaClear()
{
}

void BBGame::onLose()
{
}

void BBGame::onGameOver()
{
}

/*void BBGame::onBarBallCollision()
{
    float x = ball_->x();
    float y = ball_->y();
    float w = ball_->radius() * 2;
    float h = w;
    float xSpeed = ball_->xSpeed();
    bool containsTopLeft = bar_->contains(x + w, y + h);
    bool containsTopRight = bar_->contains(x, y + h);
    bool containsBtmLeft = bar_->contains(x + w, y);
    bool containsBtmRight = bar_->contains(x, y);
    bool hitTop = containsTopRight && containsTopLeft;
    bool hitBtm = containsBtmRight && containsBtmLeft;
    bool hitRight = containsTopRight || containsBtmRight;
    bool hitLeft = containsTopLeft || containsBtmLeft;
    
    if (hitTop && hitBtm) {
        std::cout << "Contained\n";
        ball_->setYSpeed(-ball_->ySpeed());
        ball_->setY(y - (y - bar_->y() * 2));
    } else if (hitTop) {
        ball_->setYSpeed(-ball_->ySpeed());
    } else if (containsTopRight) {
        if (xSpeed > 0) {
            ball_->setXSpeed(xSpeed + 1);
        } else if (xSpeed < -MIN_BALL_SPEED) {
            ball_->setXSpeed(xSpeed + 1);
        }
        ball_->setYSpeed(-ball_->ySpeed());
    } else if (containsTopLeft) {
        if (xSpeed < 0) {
            ball_->setXSpeed(xSpeed - 1);
        } else if (xSpeed > MIN_BALL_SPEED) {
            ball_->setXSpeed(xSpeed - 1);
        }
        ball_->setYSpeed(-ball_->ySpeed());
    } else if (hitRight) {
        std::cout << "Right\n";
        ball_->setXSpeed(-ball_->xSpeed());
    } else if (hitLeft) {
        std::cout << "Left\n";
        ball_->setXSpeed(-ball_->xSpeed());
    } else if (hitBtm) {
        ball_->setYSpeed(-ball_->ySpeed());
    }
    /// Play hit ball sound.
}*/

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
}

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

/*bool BBGame::checkCollision(Ball & ball, Bar & bar)
{
    float x = ball.x();
    float y = ball.y();
    float bWidth = ball.radius() * 2;
    float bHeight = bWidth;
    bool noCollision = false;
    
    /// Checks if a collision IS NOT happening, which is
    /// faster than checking if a collision is happening.
    noCollision = (!(bar.contains(x, y)) &&
                   !(bar.contains(x + bWidth, y)) &&
                   !(bar.contains(x, y + bHeight)) &&
                   !(bar.contains(x + bWidth, y + bWidth)));
                   
    /// Mind-screwyness due to efficiency.
    return !noCollision;
}*/

