#include "BBGraphicsView.h"

#include <QMouseEvent>
#include <QGraphicsScene>

BBGraphicsView::BBGraphicsView(QGraphicsScene * scene, QWidget * parent) :
    QGraphicsView(scene, parent)
{
}

BBGraphicsView::~BBGraphicsView()
{
}

///////////////
// Protected //
///////////////

void BBGraphicsView::keyPressEvent(QKeyEvent * event)
{
    switch (event->key()) {
    case Qt::Key_A:
        emit leftMoveEvent();
        break;
    case Qt::Key_D:
        emit rightMoveEvent();
        break;
    case Qt::Key_X:
        emit acceptEvent();
        break;
    default:
        /// Tells the parent to handle all other keys.
        QWidget::keyPressEvent(event);
        break;
    }
}

void BBGraphicsView::keyReleaseEvent(QKeyEvent * event)
{
    switch (event->key()) {
    case Qt::Key_A:
        emit leftMoveStopEvent();
        break;
    case Qt::Key_D:
        emit rightMoveStopEvent();
        break;
    default:
        /// Tells the parent to handle all other keys.
        QWidget::keyPressEvent(event);
        break;
    }
}
