#ifndef BB_WIDGET_H
#define BB_WIDGET_H

#include <QWidget>

class QGraphicsScene;
class QGraphicsView;
class QGraphicsItem;

class QCloseEvent;

class BBController;
class GameObject;

/**
 *  @class  BBWidget
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
};

#endif /// NOT BB_WIDGET_H