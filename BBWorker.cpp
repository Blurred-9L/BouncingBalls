#include "BBWorker.h"
#include "BBGame.h"
#include "Ball.h"
#include "Bar.h"
#include "BrickArea.h"
#include "GameObject.h"

#include <iostream>

BBWorker::BBWorker(unsigned id, BBGame & game, bool & goOn, unsigned width,
                   unsigned height, QObject * parent) :
    ThreadWorker(id, parent), game(game), goOn(goOn), width(width),
    height(height)
{
}

BBWorker::~BBWorker()
{
}

void BBWorker::execute()
{
    Bar & bar = game.bar();
    Ball & ball = game.ball();
    
    while(goOn) {
        bar.updatePosition();
        bar.checkBounds(width, height);
        ball.updatePosition();
        ball.checkBounds(width, height);
        if (!game.isActive()) {
            ball.setX(bar.x() + (bar.width() / 2) - ball.radius());
        } else if (BBGame::checkCollision(ball, bar)) {
            std::cout << "Collision!" << std::endl;
            game.onBarBallCollision();
        } else {
        }
        emit updateScene();
        sleep(16);
    }
    
    emit done();
}
