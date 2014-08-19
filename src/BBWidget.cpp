/**
 *  @file   BBWidget.cpp
 *  @author Blurred-9L
 */

#include "BBWidget.h"
#include "BBController.h"
#include "ThreadWorker.h"
#include "GameObject.h"
#include "Brick.h"
#include "BBGraphicsView.h"
#include "BBResource.h"
#include "GameArea.h"

#include <QGraphicsScene>
#include <QVBoxLayout>

#include <QPixmap>
#include <QBrush>
#include <QPen>
#include <QColor>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QCloseEvent>

#include <ctime>
#include <iostream>

/**
 *  @details    The BBWidget object's constructor.
 *
 *  @param[in]  controller          The application's controller.
 *  @param[in]  parent              This object's QObject parent.
 */
BBWidget::BBWidget(BBController & controller, QWidget * parent) :
    QWidget(parent), ballItem(0), barItem(0), controller(controller)
{
    QPen pen(QColor(0, 0, 0));
    QBrush brush(QColor(0, 0, 0));
    unsigned width = controller.width();
    unsigned height = controller.height();
    unsigned windowWidth = BBResource::SCENE_WIDTH;
    unsigned windowHeight = BBResource::SCENE_HEIGHT;
    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    
    bouncingScene = new QGraphicsScene(0, 0, windowWidth, windowHeight);
    bouncingView = new BBGraphicsView(bouncingScene, this);
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
    connect(&controller, SIGNAL(drawBackground(const char *)),
            this, SLOT(drawBackground(const char *)));
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
    
    bouncingScene->addRect(0, 0, windowWidth, windowHeight, pen, brush);
    gameArea = new GameArea();
    gameArea->setPos(BBResource::GAME_AREA_RECT_X, BBResource::GAME_AREA_RECT_Y);
    bouncingScene->addItem(gameArea);
    
    
    for (int i = 0; i < NUM_COLORS; i++) {
        brickPixmaps.append(new QPixmap(BBResource::BRICK_IMGS[i]));
    }
}

/**
 *  @details    The BBWidget object's destructor.
 */
BBWidget::~BBWidget()
{
    for (int i = 0; i < NUM_COLORS; i++) {
        delete brickPixmaps[i];
    }
}

/**
 *  @details    Handles a window close event in order to stop the threads
 *              used and free the required memory.
 */
void BBWidget::closeEvent(QCloseEvent * event)
{
    controller.stopThreads();
    ThreadWorker::wait(10);
    event->accept();
}

/**
 *  @details    Draws or updates the ball object on the screen.
 */
void BBWidget::drawBall(const GameObject & ball)
{
    if (ballItem == 0) {
        ballItem = bouncingScene->addPixmap(QPixmap(BBResource::BALL_IMG));
        ballItem->setParentItem(gameArea);
    }

    ballItem->setPos(ball.x(), ball.y());
}

/**
 *  @details    Draws or updates the bar object on the screen.
 */
void BBWidget::drawBar(const GameObject & bar)
{
    if (barItem == 0) {
        barItem = bouncingScene->addPixmap(QPixmap(BBResource::BAR_IMG));
        barItem->setParentItem(gameArea);
    }
    barItem->setPos(bar.x(), bar.y());
}

/**
 *  @details    Draws a brick on the scene.
 */
void BBWidget::drawBrick(const Brick & brick)
{
    unsigned row = brick.row(), column = brick.column();
    QGraphicsItem * brickItem;
    
    brickItem = bouncingScene->addPixmap(*brickPixmaps[brick.color()]);
    brickItem->setParentItem(gameArea);
    brickItem->setPos(column * BBResource::DEFAULT_BRICK_WIDTH, row * BBResource::DEFAULT_BRICK_HEIGHT);
    brickItems.append(brickItem);
}

/**
 *  @details    Removes a broken brick from the scene. 
 */
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

/**
 *  @details    Removes all bricks from the scene.
 */
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

/**
 *  @details    Draws the background by using the image tile given. This tile
 *              should be 40 x 40 pixels preferrably.
 *
 *  @param[in]  tileFile            The path to the file with the tile to use.
 */
void BBWidget::drawBackground(const char * tileFile)
{
    gameArea->setTileFile(tileFile);
    gameArea->update();
}
