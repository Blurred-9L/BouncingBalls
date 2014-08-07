/**
 *  @file   BBEditorWidget.cpp
 *  @author Blurred-9L
 */
 
#include "BBEditorWidget.h"
#include "../src/BBResource.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVBoxLayout>

#include <QPixmap>
#include <QBrush>
#include <QPen>
#include <QGraphicsItem>

/**
 *  @details    The BBEditorWidget object's constructor.
 */
BBEditorWidget::BBEditorWidget(QWidget * parent) :
    QWidget(parent)
{
    QPen linePen;
    unsigned width = BBResource::MAX_SCENE_WIDTH;
    unsigned height = BBResource::MAX_SCENE_HEIGHT;
    unsigned lowestBrickHeight = BBResource::DEFAULT_ROWS * BBResource::DEFAULT_BRICK_HEIGHT;
    unsigned i;
    
    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    
    editorScene = new QGraphicsScene(0, 0, width, height);
    editorView = new QGraphicsView(editorScene);
    editorView->setMinimumSize(width, height);
    editorView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    editorView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    editorView->setFocusPolicy(Qt::NoFocus);
    editorView->show();
    mainLayout->addWidget(editorView, 0, Qt::AlignHCenter);
    editorView->setFocus();
    
    linePen.setWidth(1);
    linePen.setStyle(Qt::DashLine);
    for (i = 1; i <= BBResource::DEFAULT_ROWS; i++) {
        editorScene->addLine(0, i * BBResource::DEFAULT_BRICK_HEIGHT, 
                             width, i * BBResource::DEFAULT_BRICK_HEIGHT,
                             linePen);
    }
    for (i = 1; i < BBResource::DEFAULT_COLS; i++) {
        editorScene->addLine(i * BBResource::DEFAULT_BRICK_WIDTH, 0,
                             i * BBResource::DEFAULT_BRICK_WIDTH, lowestBrickHeight,
                             linePen);
    }
}

/**
 *  @details    The BBEditorWidget object's destructor.
 */
BBEditorWidget::~BBEditorWidget()
{
}
