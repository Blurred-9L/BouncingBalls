/**
 *  @file   EditorController.cpp
 *  @author Blurred-9L
 */
 
#include "EditorController.h"
#include "EditorGraphicsView.h"

#include "../src/Brick.h"
#include "../src/BBResource.h"

#include <fstream>
using std::ofstream;

/**
 *  @details    The EditorController object's constructor.
 *
 *  @param[in]  parent              This object's QObject parent.
 */
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

/**
 *  @details    The EditorController object's destructor.
 */
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

/**
 *  @details    Sets the EditorController's cursorRow attribute.
 *
 *  @param[in]  cursorRow           The new row of the cursor image.
 */
void EditorController::setCursorRow(unsigned cursorRow)
{
    if (cursorRow < BBResource::DEFAULT_ROWS) {
        cursorRow_ = cursorRow;
    }
}

/**
 *  @details    Sets the EditorController's cursorColumn attribute.
 *
 *  @param[in]  cursorColumn        The new column of the cursor image.
 */
void EditorController::setCursorColumn(unsigned cursorColumn)
{
    if (cursorColumn < BBResource::DEFAULT_COLS) {
        cursorColumn_ = cursorColumn;
    }
}

/**
 *  @details    Moves the cursor location by interpreting a direction
 *              key input.
 *
 *  @param[in]  direction           The direction on which to move the cursor.
 */
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

/**
 *  @details    Interprets a digit key press in order to paint a brick
 *              of a specific color on the screen.
 *
 *  @param[in]  digit               The number of the pressed digit key.
 */
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

/**
 *  @details    Interprets a click on the scene and converts the click's
 *              coordinates into a row and column in the brick's grid.
 *
 *  @param[in]  x                   The click's x coordinate.
 *  @param[in]  y                   The click's y coordinate.
 */
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

/**
 *  @details    Performs the necessary operations in order to
 *              save into a file the contents of the bricks array.
 *
 *  @param[in]  levelName           The name of the file to write.
 */
void EditorController::saveLevel(const char * levelName)
{
    levelFileName_ = levelName;
    writeFile(levelName);
}

/**
 *  @details    Sets the background tile file name and tells the
 *              scene to draw the image on the file as the background
 *              tile.
 *
 *  @param[in]  backgroundName      The name of the background tile file.
 */
void EditorController::setBackgroundTile(const char * backgroundName)
{
    backgroundFileName_ = backgroundName;
    emit drawBackground(backgroundName);
}

/////////////
// Private //
/////////////

/**
 *  @details    Writes the contents of the bricks array into a file.
 *
 *  @param[in]  filename            The name of the file to open for writing.
 */
void EditorController::writeFile(const char * filename)
{
    ofstream levelFile(filename);
    unsigned size = BBResource::DEFAULT_ROWS * BBResource::DEFAULT_COLS;
    unsigned i;

    if (backgroundFileName_.empty()) {
        levelFile << "../img/BlueTile.png" << std::endl;
    } else {
        levelFile << backgroundFileName_ << std::endl;
    }
    /// Save array of bricks
    for (i = 0; i < size; i++) {
        if (bricks_[i] != 0) {
            levelFile << bricks_[i]->row() << ","
                      << bricks_[i]->column() << ","
                      << BBResource::COLOR_NAMES[bricks_[i]->color()] << std::endl;
        }
    }
    levelFile.close();
}
