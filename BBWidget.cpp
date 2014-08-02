#include "BBWidget.h"
#include "BBController.h"
#include "ThreadWorker.h"
#include "GameObject.h"
#include "Brick.h"
#include "BBGraphicsView.h"

#include <QGraphicsScene>
#include <QVBoxLayout>

#include <QPixmap>
#include <QBrush>
#include <QGraphicsItem>
#include <QCloseEvent>

#include <ctime>
#include <iostream>

BBWidget::BBWidget(BBController & controller, QWidget * parent) :
    QWidget(parent), ballItem(0), barItem(0), controller(controller)
{
    unsigned width = controller.width();
    unsigned height = controller.height();
    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    
    bouncingScene = new QGraphicsScene(0, 0, width, height);
    bouncingView = new BBGraphicsView(bouncingScene);
    bouncingView->setBackgroundBrush(QBrush(QPixmap("./img/BlueTile.png")));
    //bouncingView->setGeometry(0, 0, width, height);
    bouncingView->setMinimumSize(width, height);
    bouncingView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    bouncingView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    bouncingView->setFocusPolicy(Qt::NoFocus);
    bouncingView->show();
    mainLayout->addWidget(bouncingView, 0, Qt::AlignHCenter);
    
    connect(&controller, SIGNAL(drawBall(const GameObject &)),
            this, SLOT(drawBall(const GameObject &)));
    connect(&controller, SIGNAL(drawBar(const GameObject &)),
            this, SLOT(drawBar(const GameObject &)));
    connect(&controller, SIGNAL(drawBrick(const Brick &)),
            this, SLOT(drawBrick(const Brick &)));
    connect(&controller, SIGNAL(removeBrick(unsigned)),
            this, SLOT(removeBrick(unsigned)));
    connect(&controller, SIGNAL(resetBricks()),
            this, SLOT(resetBricks()));
    connect(bouncingView, SIGNAL(leftMoveEvent()),
            &controller, SLOT(handleLeftMovement()));
    connect(bouncingView, SIGNAL(rightMoveEvent()),
            &controller, SLOT(handleRightMovement()));
    connect(bouncingView, SIGNAL(acceptEvent()),
            &controller, SLOT(handleAccept()));
    connect(bouncingView, SIGNAL(leftMoveStopEvent()),
            &controller, SLOT(handleLeftStop()));
    connect(bouncingView, SIGNAL(rightMoveStopEvent()),
            &controller, SLOT(handleRightStop()));
            
    bouncingView->setFocus();
    
    for (int i = 0; i < NUM_COLORS; i++) {
        brickPixmaps.append(new QPixmap(BBController::BRICK_IMGS[i]));
    }
}

BBWidget::~BBWidget()
{
    for (int i = 0; i < NUM_COLORS; i++) {
        delete brickPixmaps[i];
    }
}

void BBWidget::closeEvent(QCloseEvent * event)
{
    controller.stopThreads();
    ThreadWorker::wait(10);
    event->accept();
}

void BBWidget::drawBall(const GameObject & ball)
{
    if (ballItem == 0) {
        ballItem = bouncingScene->addPixmap(QPixmap(BBController::BALL_IMG));
    }

    ballItem->setPos(ball.x(), ball.y());
}

void BBWidget::drawBar(const GameObject & bar)
{
    if (barItem == 0) {
        barItem = bouncingScene->addPixmap(QPixmap(BBController::BAR_IMG));
    }
    barItem->setPos(bar.x(), bar.y());
}

void BBWidget::drawBrick(const Brick & brick)
{
    unsigned row = brick.row(), column = brick.column();
    QGraphicsItem * brickItem;
    
    brickItem = bouncingScene->addPixmap(*brickPixmaps[brick.color()]);
    brickItem->setPos(column * Brick::DEFAULT_WIDTH, row * Brick::DEFAULT_HEIGHT);
    brickItems.append(brickItem);
}

void BBWidget::removeBrick(unsigned index)
{
    if (index < (unsigned)brickItems.size()) {
        if (brickItems[index] != 0) {
            bouncingScene->removeItem(brickItems[index]);
            delete brickItems[index];
            brickItems[index] = 0;
        }
    }
}

void BBWidget::resetBricks()
{
    int i, size = brickItems.size();
    
    for (i = 0; i < size; i++) {
        if (brickItems[i] != 0) {
            bouncingScene->removeItem(brickItems[i]);
            delete brickItems[i];
            brickItems[i] = 0;
        }
    }
    brickItems.clear();
}
