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

BBController::~BBController()
{
    if (game_ != 0) {
        delete game_;
    }
}

unsigned BBController::width()
{
    return width_;
}

unsigned BBController::height()
{
    return height_;
}

void BBController::stopThreads()
{
    isActive = false;
}

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

void BBController::startThread(unsigned index)
{
}

void BBController::updateScene()
{
    BrickArea & brickArea = game_->brickArea();
    unsigned nBricks = brickArea.totalBricks();
    unsigned i;
    
    if (game_->shouldDrawLevel()) {
        emit resetBricks();
        for (i = 0; i < nBricks; i++) {
            emit drawBrick(brickArea.bricks()[i]);
        }
        game_->setDrawLevel(false);
    } else {
        for (i = 0; i < nBricks; i++) {
            if (brickArea.bricks()[i].isBroken()) {
                emit removeBrick(i);
            }
        }
    }
    emit drawBall(game_->ball());
    emit drawBar(game_->bar());
}

void BBController::handleLeftMovement()
{
    game_->bar().setXSpeed(-BBGame::DEFAULT_BAR_SPEED);
    if (!game_->isActive()) {
        game_->ball().setXSpeed(-BBGame::DEFAULT_BAR_SPEED);
    }
    
}

void BBController::handleRightMovement()
{
    game_->bar().setXSpeed(BBGame::DEFAULT_BAR_SPEED);
    if (!game_->isActive()) {
        game_->ball().setXSpeed(BBGame::DEFAULT_BAR_SPEED);
    }
}

void BBController::handleAccept()
{
    if (!game_->isActive()) {
        game_->ball().setXSpeed(BBGame::DEFAULT_BALL_SPEED);
        game_->ball().setYSpeed(-BBGame::DEFAULT_BALL_SPEED);
        game_->setActive(true);
    }
}

void BBController::handleLeftStop()
{
    game_->bar().setXSpeed(0.0);
    if (!game_->isActive()) {
        game_->ball().setXSpeed(0.0);
    }
}

void BBController::handleRightStop()
{
    game_->bar().setXSpeed(0.0);
    if (!game_->isActive()) {
        game_->ball().setXSpeed(0.0);
    }
}
