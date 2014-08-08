/**
 *  @file   BBGraphicsView.cpp
 *  @author Blurred-9L
 */

#include "BBGraphicsView.h"

#include <QKeyEvent>
#include <QGraphicsScene>

/**
 *  @details    The BBGraphicsView object's constructor.
 *
 *  @param[in]  scene               The scene that this view will show.
 *  @param[in]  parent              This object's QObject parent.
 */
BBGraphicsView::BBGraphicsView(QGraphicsScene * scene, QWidget * parent) :
    QGraphicsView(scene, parent)
{
}

/**
 *  @details    The BBGraphicsView object's destructor.
 */
BBGraphicsView::~BBGraphicsView()
{
}

///////////////
// Protected //
///////////////

/**
 *  @details    Emits signals when movement or accept keys are
 *              pressed.
 *
 *  @param[in]  event               The key press related information.
 */
void BBGraphicsView::keyPressEvent(QKeyEvent * event)
{
    switch (event->key()) {
    case Qt::Key_A:
    case Qt::Key_Left:
        emit leftMoveEvent();
        break;
    case Qt::Key_D:
    case Qt::Key_Right:
        emit rightMoveEvent();
        break;
    case Qt::Key_Space:
        emit acceptEvent();
        break;
    default:
        /// Tells the parent to handle all other keys.
        QWidget::keyPressEvent(event);
        break;
    }
}

/**
 *  @details    Emits signals when movement keys are released
 *
 *  @param[in]  event               The key release related information.
 */
void BBGraphicsView::keyReleaseEvent(QKeyEvent * event)
{
    switch (event->key()) {
    case Qt::Key_A: 
    case Qt::Key_Left:
        emit leftMoveStopEvent();
        break;
    case Qt::Key_D: 
    case Qt::Key_Right:
        emit rightMoveStopEvent();
        break;
    default:
        /// Tells the parent to handle all other keys.
        QWidget::keyPressEvent(event);
        break;
    }
}
