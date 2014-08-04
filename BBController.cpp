/**
 *  @file   BBController.cpp
 *  @author Blurred-9L
 */

#include "BBController.h"
#include "Ball.h"
#include "Bar.h"
#include "Brick.h"
#include "BrickArea.h"
#include "BBGame.h"
#include "BBWorker.h"

#include <QThread>

#include <iostream>
#include <string>
using std::string;

const int BBController::MIN_WIDTH = 320;
const int BBController::MIN_HEIGHT = 480;
const int BBController::MAX_WIDTH = 480;
const int BBController::MAX_HEIGHT = 640;
const char * BBController::BALL_IMG = "./img/Ball.png";
const char * BBController::BAR_IMG = "./img/Bar.png";
const char * BBController::BRICK_IMGS[NUM_COLORS] =
                                    {"./img/RedBrick.png", "./img/GreenBrick.png", "./img/BlueBrick.png",
                                     "./img/CyanBrick.png", "./img/MagentaBrick.png", "./img/YellowBrick.png",
                                     "./img/SilverBrick.png", "./img/GoldenBrick.png"};
const char * BBController::LEVEL_NAME_PREFIX = "./levels/level_";
const char * BBController::BALL_BOUNCE_FILE = "./sound/Bounce.wav";

/**
 *  @details    The BBController object's constructor. It verifies that
 *              the given width and height are within the allowed ranges.
 *
 *  @param[in]  width               The game's scene width.
 *  @param[in]  height              The game's scene height.
 *  @param[in]  parent              The BBController's QObject parent.
 */
BBController::BBController(unsigned width, unsigned height, QObject * parent) :
    ThreadController(1, parent), isActive(false), width_(width), height_(height),
    game_(0)
{
    if (width < MIN_WIDTH) {
        width_ = MIN_WIDTH;
    } else if (width > MAX_WIDTH) {
        width_ = MAX_WIDTH;
    }
    if (height < MIN_HEIGHT) {
        height_ = MIN_HEIGHT;
    } else if (height > MAX_HEIGHT) {
        height_ = MAX_HEIGHT;
    }
}

/**
 *  @details    The BBController object's destructor.
 */
BBController::~BBController()
{
    if (game_ != 0) {
        delete game_;
    }
}

/**
 *  @details    Gets the BBController's game scene width attribute.
 *
 *  @return     The width of the game's scene.
 */
unsigned BBController::width()
{
    return width_;
}

/**
 *  @details    Gets the BBController's game scene height attribute.
 *
 *  @return     The height of the game's scene.
 */
unsigned BBController::height()
{
    return height_;
}

/**
 *  @details    Turns off the flag that keeps the active threads running.
 */
void BBController::stopThreads()
{
    isActive = false;
}

/**
 *  @details    Starts the necessary threads for the game to work. It also
 *              instantiates the Game object, which will hold game related
 *              data. The started thread will be in charge of handling all
 *              the position and state updating.
 */
void BBController::startThreads()
{
    QThread * thread;
    BBWorker * worker;
    string levelName = LEVEL_NAME_PREFIX;

    if (!isActive) {
        isActive = true;
        game_ = new BBGame();
        emit drawBall(game_->ball());
        emit drawBar(game_->bar());
        
        /// This is used for testing:
        levelName += "1";
        game_->brickArea().loadLevel(levelName.c_str());
        game_->setDrawLevel(true);
        
        /// Create new worker.
        worker = new BBWorker(0, *game_, isActive, width_, height_);
        thread = new QThread();
        /// Connect signals.
        worker->moveToThread(thread);
        /// When the thread starts, begin worker's execution.
        connect(thread, SIGNAL(started()), worker, SLOT(execute()));
        /// When the worker is done, tell the thread to exit.
        connect(worker, SIGNAL(done()), thread, SLOT(quit()));
        /// When the worker is done, schedule its deletion.
        connect(worker, SIGNAL(done()), worker, SLOT(deleteLater()));
        /// When the thread has exitted, schedule its deletion.
        connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
        /// Respond to redraw signals.
        connect(worker, SIGNAL(updateScene()), this, SLOT(updateScene()));
        /// Launch thread.
        thread->start();
    }
}

/**
 *  @details    Starts a single thread. No implementation given.
 *
 *  @param[in]  index               The index of the thread to start.
 */
void BBController::startThread(unsigned index)
{
}

/**
 *  @details    Updates the necessary objects on the game's scene
 *              by telling the scene to redraw objects as needed.
 */
void BBController::updateScene()
{
    BrickArea & brickArea = game_->brickArea();
    unsigned nBricks = brickArea.totalBricks();
    unsigned i;
    
    /// If the whole level needs to be drawn...
    if (game_->shouldDrawLevel()) {
        emit drawBackground(game_->brickArea().pathToBackgroundTile().c_str());
        emit resetBricks();
        /// Draws all bricks.
        for (i = 0; i < nBricks; i++) {
            emit drawBrick(brickArea.bricks()[i]);
        }
        game_->setDrawLevel(false);
    } else {
        /// Removes the broken bricks.
        for (i = 0; i < nBricks; i++) {
            if (brickArea.bricks()[i].isBroken()) {
                emit removeBrick(i);
            }
        }
    }
    /// Draws the ball and the bar's new position.
    emit drawBall(game_->ball());
    emit drawBar(game_->bar());
}

/**
 *  @details    Responds to the user's press of the left movement key.
 */
void BBController::handleLeftMovement()
{
    game_->bar().setXSpeed(-BBGame::DEFAULT_BAR_SPEED);
    if (!game_->isActive()) {
        game_->ball().setXSpeed(-BBGame::DEFAULT_BAR_SPEED);
    }
    
}

/**
 *  @details    Responds to the user's press of the right movement key.
 */
void BBController::handleRightMovement()
{
    game_->bar().setXSpeed(BBGame::DEFAULT_BAR_SPEED);
    if (!game_->isActive()) {
        game_->ball().setXSpeed(BBGame::DEFAULT_BAR_SPEED);
    }
}

/**
 *  @details    Responds to the user's press of the accept key.
 */
void BBController::handleAccept()
{
    if (!game_->isActive()) {
        game_->ball().setXSpeed(BBGame::DEFAULT_BALL_SPEED);
        game_->ball().setYSpeed(-BBGame::DEFAULT_BALL_SPEED);
        game_->setActive(true);
    }
}

/**
 *  @details    Responds to the user's release of the left movement key.
 */
void BBController::handleLeftStop()
{
    game_->bar().setXSpeed(0.0);
    if (!game_->isActive()) {
        game_->ball().setXSpeed(0.0);
    }
}

/**
 *  @details    Responds to the user's release of the right movement key.
 */
void BBController::handleRightStop()
{
    game_->bar().setXSpeed(0.0);
    if (!game_->isActive()) {
        game_->ball().setXSpeed(0.0);
    }
}
