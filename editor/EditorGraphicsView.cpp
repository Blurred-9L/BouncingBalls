/**
 *  @file   EditorGraphicsView.cpp
 *  @author Blurred-9L
 */

#include "EditorGraphicsView.h"

#include <QKeyEvent>
#include <QMouseEvent>
#include <QGraphicsScene>

EditorGraphicsView::EditorGraphicsView(QGraphicsScene * scene, QWidget * parent) :
    QGraphicsView(scene, parent)
{
}

EditorGraphicsView::~EditorGraphicsView()
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
void EditorGraphicsView::keyPressEvent(QKeyEvent * event)
{
    switch (event->key()) {
    case Qt::Key_Left:
        emit directionKeyPress(MOVE_LEFT);
        break;
    case Qt::Key_Right:
        emit directionKeyPress(MOVE_RIGHT);
        break;
    case Qt::Key_Up:
        emit directionKeyPress(MOVE_UP);
        break;
    case Qt::Key_Down:
        emit directionKeyPress(MOVE_DOWN);
        break;
    case Qt::Key_0: case Qt::Key_1: case Qt::Key_2:
    case Qt::Key_3: case Qt::Key_4: case Qt::Key_5:
    case Qt::Key_6: case Qt::Key_7: case Qt::Key_8:
    case Qt::Key_9:
        emit digitKeyPress(event->key() & 0x0F);
        break;
    default:
        /// Tells the parent to handle all other keys.
        QWidget::keyPressEvent(event);
        break;
    }
}

void EditorGraphicsView::mousePressEvent(QMouseEvent * event)
{
    emit clickedOn(event->x(), event->y());
}
