/**
 *  @file   BBWidget.h
 *  @author Blurred-9L
 */

#ifndef BB_WIDGET_H
#define BB_WIDGET_H

#include <QWidget>
#include <QList>

class QGraphicsScene;
class QGraphicsView;
class QGraphicsItem;
class QPixmap;

class QCloseEvent;

class BBController;
class GameObject;
class Brick;

/**
 *  @class  BBWidget
 *
 *  @brief  Class that handles the graphic user interface used
 *          to display the game's objects and scene.
 */
class BBWidget : public QWidget {
Q_OBJECT

private:
    /// The widget's graphics view.
    QGraphicsView * bouncingView;
    /// The related graphics scene.
    QGraphicsScene * bouncingScene;
    /// The ball image object.
    QGraphicsItem * ballItem;
    /// The bar image object.
    QGraphicsItem * barItem;
    /// The bricks image objects.
    QList<QGraphicsItem *> brickItems;
    /// The bricks pixmaps.
    QList<QPixmap *> brickPixmaps;
    /// The widget's controller.
    BBController & controller;

protected:
    virtual void closeEvent(QCloseEvent * event);

public:
    /// The BBWidget's constructor.
    BBWidget(BBController & controller, QWidget * parent = 0);
    /// The BBWidget's destructor.
    virtual ~BBWidget();
    
public slots:
    /// Draws the ball on the scene.
    void drawBall(const GameObject & ball);
    /// Draws the bar on the scene.
    void drawBar(const GameObject & bar);
    /// Draws or stops drawing a brick on the screen.
    void drawBrick(const Brick & brick);
    /// Removes the brick on the given index.
    void removeBrick(unsigned index);
    /// Resets the number of bricks on the screen.
    void resetBricks();
    /// Draws the background tile.
    void drawBackground(const char * tileFile);
};

#endif /// NOT BB_WIDGET_H
