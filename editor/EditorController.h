/**
 *  @file   EditorController.h
 *  @author Blurred-9L
 */

#ifndef EDITOR_CONTROLLER_H
#define EDITOR_CONTROLLER_H

#include <QObject>

class Brick;

/**
 *  @class  EditorController
 *
 *  @brief  Class used to handle events from the EditorGraphicsView,
 *          modifying the underlying data and requesting updates on
 *          the graphical user interface.
 */
class EditorController : public QObject {
Q_OBJECT

private:
    /// The cursor's current row.
    unsigned cursorRow_;
    /// The cursor's current column.
    unsigned cursorColumn_;
    /// The bricks' information.
    Brick ** bricks_;

public:
    /// The EditorController's constructor.
    EditorController(QObject * parent = 0);
    /// The EditorController's destructor.
    virtual ~EditorController();
    /// Sets the cursor's row.
    void setCursorRow(unsigned cursorRow);
    /// Sets the cursor's column.
    void setCursorColumn(unsigned cursorColumn);
    
public slots:
    /// Handles direction key presses.
    void handleDirectionKey(int direction);
    /// Handles digit key presses.
    void handleDigitKey(int digit);
    /// Handles clicks.
    void handleClick(int x, int y);
    
signals:
    /// Moves the cursor to the given row and column.
    void moveCursor(unsigned row, unsigned column);
    /// Draws or replaces a brick object.
    void putBrick(unsigned row, unsigned column, unsigned color);
};

#endif /// NOT EDITOR_CONTROLLER_H
