/**
 *  @file   BBEditorWidget.h
 *  @author Blurred-9L
 */
 
#ifndef BB_EDITOR_WIDGET_H
#define BB_EDITOR_WIDGET_H

#include <QWidget>
#include <QVector>

class QGraphicsScene;
class QGraphicsView;
class QGraphicsItem;
class QPixmap;

class EditorController;

/**
 *  @class  BBEditorWidget
 *
 *  @brief  Class that handles the graphic user interface for the
 *          level editor of the arkanoid / breakout clone game.
 */
class BBEditorWidget : public QWidget {
Q_OBJECT

private:
    /// The widget's graphics view.
    QGraphicsView * editorView;
    /// The related graphics scene.
    QGraphicsScene * editorScene;
    /// The cursor's graphics item.
    QGraphicsItem * cursorItem;
    /// The bricks' graphics items.
    QVector<QGraphicsItem *> brickItems;
    /// The bricks pixmaps.
    QVector<QPixmap *> brickPixmaps;
    /// This widget's controller.
    EditorController * controller;

public:
    /// The BBEditorWidget's constructor.
    BBEditorWidget(QWidget * parent = 0);
    /// The BBEditorWidget's destructor.
    virtual ~BBEditorWidget();
    
public slots:
    /// Moves the cursor to the given row and column.
    void moveCursor(unsigned row, unsigned column);
    /// Draws or replaces a brick object.
    void putBrick(unsigned row, unsigned column, unsigned color);
    /// Draws the background.
    void drawBackground(const char * filename);
    
signals:
    /// Notifies that the level should be saved.
    void saveLevelTo(const char *);
    /// Notifies that the background tile has been chosen.
    void setBackgroundTile(const char *);
};

#endif /// NOT BB_EDITOR_WIDGET_H
