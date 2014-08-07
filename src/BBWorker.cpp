/**
 *  @file   BBWorker.cpp
 *  @author Blurred-9L
 */

#include "BBWorker.h"
#include "BBGame.h"
#include "Ball.h"
#include "Bar.h"
#include "Brick.h"
#include "BrickArea.h"
#include "GameObject.h"

#include <iostream>

/**
 *  @details    The BBWorker object's constructor.
 *
 *  @param[in]  id                  The thread's id.
 *  @param[in]  game                The BBGame's instance.
 *  @param[in]  goOn                The reference to the flag to keep processing data.
 *  @param[in]  width               The game's scene width.
 *  @param[in]  height              The game's scene height.
 *  @param[in]  parent              This object's QObject parent.
 */
BBWorker::BBWorker(unsigned id, BBGame & game, bool & goOn, unsigned width,
                   unsigned height, QObject * parent) :
    ThreadWorker(id, parent), game(game), goOn(goOn), width(width),
    height(height)
{
}

/**
 *  @details    The BBWorker object's destructor.
 */
BBWorker::~BBWorker()
{
}

/**
 *  @details    Executes this thread's work. This includes updating
 *              positions, checking for collisions and asking the
 *              UI thread to update the scene.
 */
void BBWorker::execute()
{
    Bar & bar = game.bar();
    Ball & ball = game.ball();
    BrickArea & brickArea = game.brickArea();
    Brick * brick = 0;
    int brickCollisionStatus;
    unsigned i, nBricks;
    bool brickHit;
    
    while(goOn) {
        bar.updatePosition();
        bar.checkBounds(width, height);
        ball.updatePosition();
        ball.checkBounds(width, height);
        if (!game.isActive()) {
            ball.setX(bar.x() + (bar.width() / 2) - ball.radius());
        } else if (BBGame::checkCollision(ball, bar)) {
            game.onBarBallCollision();
        } else {
            nBricks = brickArea.totalBricks();
            brickHit = false;
            for (i = 0; i < nBricks && !brickHit; i++) {
                brick = &brickArea.bricks()[i];
                if (!brick->isBroken()) {
                    brickCollisionStatus = BBGame::checkCollision(ball, *brick);
                    if (brickCollisionStatus > 0) {
                        ball.setXSpeed(-ball.xSpeed());
                        game.onBrickHit(*brick);
                        brickHit = true;
                    } else if (brickCollisionStatus < 0 ) {
                        ball.setYSpeed(-ball.ySpeed());
                        game.onBrickHit(*brick);
                        brickHit = true;
                    }
                }
            }
        }
        if (ball.y() > height) {
            game.onLose();
        }
        emit updateScene();
        sleep(16);
    }
    
    emit done();
}
