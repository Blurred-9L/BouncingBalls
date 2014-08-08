/**
 *  @file   EditorController.cpp
 *  @author Blurred-9L
 */
 
#include "EditorController.h"
#include "EditorGraphicsView.h"

#include "../src/Brick.h"
#include "../src/BBResource.h"

EditorController::EditorController(QObject * parent) :
    QObject(parent), cursorRow_(0), cursorColumn_(0)
{
    unsigned size = BBResource::DEFAULT_ROWS * BBResource::DEFAULT_COLS;
    unsigned i;
    
    bricks_ = new Brick * [size];
    for (i = 0; i < size; i++) {
        bricks_[i] = 0;
    }
}

EditorController::~EditorController()
{
    unsigned size = BBResource::DEFAULT_ROWS * BBResource::DEFAULT_COLS;
    unsigned i;
    
    if (bricks_ != 0) {
        for (i = 0; i < size; i++) {
            if (bricks_[i] != 0) {
                delete bricks_[i];
            }
        }
        delete [] bricks_;
    }
}

void EditorController::setCursorRow(unsigned cursorRow)
{
    if (cursorRow < BBResource::DEFAULT_ROWS) {
        cursorRow_ = cursorRow;
    }
}

void EditorController::setCursorColumn(unsigned cursorColumn)
{
    if (cursorColumn < BBResource::DEFAULT_COLS) {
        cursorColumn_ = cursorColumn;
    }
}

void EditorController::handleDirectionKey(int direction)
{
    switch (direction) {
    case EditorGraphicsView::MOVE_RIGHT:
        setCursorColumn(cursorColumn_ + 1);
        break;
    case EditorGraphicsView::MOVE_LEFT:
        setCursorColumn(cursorColumn_ - 1);
        break;
    case EditorGraphicsView::MOVE_UP:
        setCursorRow(cursorRow_ - 1);
        break;
    case EditorGraphicsView::MOVE_DOWN:
        setCursorRow(cursorRow_ + 1);
        break;
    }
    emit moveCursor(cursorRow_, cursorColumn_);
}

void EditorController::handleDigitKey(int digit)
{
    unsigned index = cursorRow_ * BBResource::DEFAULT_COLS + cursorColumn_;
    
    if (digit < NUM_COLORS) {
        if (bricks_[index] == 0) {
            bricks_[index] = new Brick();
            bricks_[index]->setRow(cursorRow_);
            bricks_[index]->setColumn(cursorColumn_);
        }
        bricks_[index]->setColor(digit);
        emit putBrick(cursorRow_, cursorColumn_, digit);
    }
}

void EditorController::handleClick(int x, int y)
{
    unsigned width = BBResource::DEFAULT_BRICK_WIDTH;
    unsigned height = BBResource::DEFAULT_BRICK_HEIGHT;
    unsigned row = y / height;
    unsigned column = x / width;
    
    if ((row < BBResource::DEFAULT_ROWS) && (column < BBResource::DEFAULT_COLS)) {
        setCursorRow(row);
        setCursorColumn(column);
        moveCursor(cursorRow_, cursorColumn_);
    }
}
