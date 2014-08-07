/**
 *  @file   BBEditorWidget.h
 *  @author Blurred-9L
 */
 
#ifndef BB_EDITOR_WIDGET_H
#define BB_EDITOR_WIDGET_H

#include <QWidget>

class QGraphicsScene;
class QGraphicsView;
class QGraphicsItem;
class QPixmap;

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

public:
    /// The BBEditorWidget's constructor.
    BBEditorWidget(QWidget * parent = 0);
    /// The BBEditorWidget's destructor.
    virtual ~BBEditorWidget();
};

#endif /// NOT BB_EDITOR_WIDGET_H
