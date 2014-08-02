/**
 *  @file   BBGraphicsView
 *  @author Blurred-9L
 */

#ifndef BB_GRAPHICS_VIEW_H
#define BB_GRAPHICS_VIEW_H

#include <QGraphicsView>

/**
 *  @class  BBGraphicsView
 *
 *  @brief  Custom QGraphicsView used to handle user input.
 */
class BBGraphicsView : public QGraphicsView {
Q_OBJECT

protected:
    /// Listens to key press events.
    virtual void keyPressEvent(QKeyEvent * event);
    /// Listens to key release events.
    virtual void keyReleaseEvent(QKeyEvent * event);

public:
    /// BBGraphicsView constructor.
    BBGraphicsView(QGraphicsScene * scene, QWidget * parent = 0);
    /// BBGraphicsView destructor.
    virtual ~BBGraphicsView();
    
signals:
    /// Reacts to right movement key press.
    void rightMoveEvent();
    /// Reacts to left movement key press.
    void leftMoveEvent();
    /// Reacts to accept key press.
    void acceptEvent();
    /// Reacts to right movement key release.
    void rightMoveStopEvent();
    /// Reacts to left movement key release.
    void leftMoveStopEvent();
    
};

#endif /// NOT BB_GRAPHICS_VIEW
