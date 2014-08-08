/**
 *  @file   EditorGraphicsView.h
 *  @author Blurred-9L
 */

#ifndef EDITOR_GRAPHICS_VIEW_H
#define EDITOR_GRAPHICS_VIEW_H

#include <QGraphicsView>

/**
 *  @class  EditorGraphicsView
 *
 *  @brief  Custom QGraphicsView class used to handle user inputs
 *          from keyboard or mouse clicks.
 */
class EditorGraphicsView : public QGraphicsView {
Q_OBJECT

protected:
    /// Listens to key press events.
    virtual void keyPressEvent(QKeyEvent * event);
    /// Listens to mouse click events.
    virtual void mousePressEvent(QMouseEvent * event);

public:
    /**
     *  @enum   MovementDirection
     *
     *  @brief  Set of values used to determine the direction pressed.
     */
    enum MovementDirection {
        MOVE_RIGHT,
        MOVE_LEFT,
        MOVE_UP,
        MOVE_DOWN
    };
    
    /// EditorGraphicsView constructor.
    EditorGraphicsView(QGraphicsScene * scene, QWidget * parent = 0);
    /// EditorGraphicsView destructor.
    virtual ~EditorGraphicsView();
    
signals:
    /// Reacts to a direction key press.
    void directionKeyPress(int direction);
    /// Reacts to a digit key press.
    void digitKeyPress(int digit);
    /// Reacts to a click.
    void clickedOn(int x, int y);
};

#endif /// NOT EDITOR_GRAPHICS_VIEW
