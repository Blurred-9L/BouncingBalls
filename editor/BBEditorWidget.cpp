/**
 *  @file   BBEditorWidget.cpp
 *  @author Blurred-9L
 */
 
#include "BBEditorWidget.h"
#include "EditorGraphicsView.h"
#include "EditorController.h"
#include "../src/BBResource.h"

#include <QGraphicsScene>
#include <QVBoxLayout>

#include <QPixmap>
#include <QBrush>
#include <QPen>
#include <QGraphicsItem>

/**
 *  @details    The BBEditorWidget object's constructor.
 */
BBEditorWidget::BBEditorWidget(QWidget * parent) :
    QWidget(parent), controller(0)
{
    QPen linePen;
    unsigned width = BBResource::MAX_SCENE_WIDTH;
    unsigned height = BBResource::MAX_SCENE_HEIGHT;
    unsigned lowestBrickHeight = BBResource::DEFAULT_ROWS * BBResource::DEFAULT_BRICK_HEIGHT;
    unsigned i;
    
    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    
    editorScene = new QGraphicsScene(0, 0, width, height);
    editorView = new EditorGraphicsView(editorScene, this);
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
    
    controller = new EditorController(this);
    connect(editorView, SIGNAL(directionKeyPress(int)),
            controller, SLOT(handleDirectionKey(int)));
    connect(editorView, SIGNAL(digitKeyPress(int)),
            controller, SLOT(handleDigitKey(int)));
    connect(editorView, SIGNAL(clickedOn(int, int)),
            controller, SLOT(handleClick(int, int)));
    
    connect(controller, SIGNAL(moveCursor(unsigned, unsigned)),
            this, SLOT(moveCursor(unsigned, unsigned)));
    connect(controller, SIGNAL(putBrick(unsigned, unsigned, unsigned)),
            this, SLOT(putBrick(unsigned, unsigned, unsigned)));
    
    cursorItem = editorScene->addPixmap(QPixmap("../img/Cursor.png"));
    
    for (int i = 0; i < NUM_COLORS; i++) {
        brickPixmaps.append(new QPixmap(BBResource::BRICK_IMGS[i]));
    }
    brickItems.resize(BBResource::DEFAULT_ROWS * BBResource::DEFAULT_COLS);
}

/**
 *  @details    The BBEditorWidget object's destructor.
 */
BBEditorWidget::~BBEditorWidget()
{
}

/**
 *  @details    Moves the cursor item to the cell identified by the given
 *              row and column.
 *
 *  @param[in]  row                 The row to move the cursor to.
 *  @param[in]  column              The column to move the cursor to.
 */
void BBEditorWidget::moveCursor(unsigned row, unsigned column)
{
    unsigned x = column * BBResource::DEFAULT_BRICK_WIDTH;
    unsigned y = row * BBResource::DEFAULT_BRICK_HEIGHT;
    
    cursorItem->setPos(x, y);
}

/**
 *  @details    Places or replaces the graphics item for the brick on the
 *              row and column at which the cursor is at. The new graphics
 *              item will be of the color indicated.
 *
 *  @param[in]  color               The color of the brick.
 */
void BBEditorWidget::putBrick(unsigned row, unsigned column, unsigned color)
{
    unsigned index = row * BBResource::DEFAULT_ROWS + column;
    unsigned x = column * BBResource::DEFAULT_BRICK_WIDTH;
    unsigned y = row * BBResource::DEFAULT_BRICK_HEIGHT;
    
    if (brickItems[index] != 0) {
        editorScene->removeItem(brickItems[index]);
        delete brickItems[index];
        brickItems[index] = 0;
    }
    brickItems[index] = editorScene->addPixmap(*brickPixmaps[color]);
    brickItems[index]->setPos(x, y);
    brickItems[index]->stackBefore(cursorItem);
}
