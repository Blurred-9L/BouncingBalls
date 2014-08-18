#include "BBEditorWindow.h"
#include "BBEditorWidget.h"

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFileDialog>

#include <QString>
#include <QDir>

/**
 *  @details    The BBEditorWindow object's constructor.
 */
BBEditorWindow::BBEditorWindow() :
    QMainWindow(), editorWidget(0)
{
    editorWidget = new BBEditorWidget(this);
    this->setCentralWidget(editorWidget);
    
    createMenu();
    
    connect(this, SIGNAL(saveLevelTo(const char *)),
            editorWidget, SIGNAL(saveLevelTo(const char *)));
    connect(this, SIGNAL(setBackgroundTile(const char *)),
            editorWidget, SIGNAL(setBackgroundTile(const char *)));
    
}

/**
 *  @details    The BBEditorWindow object's destructor.
 */
BBEditorWindow::~BBEditorWindow()
{
}

/**
 *  @details    Launches a dialog in order to obtain the name of
 *              the file on which to save the current level and
 *              then saves the level.
 */
void BBEditorWindow::saveLevel()
{
    QString levelName;
    
    levelName = QFileDialog::getSaveFileName(this, "Level file", QDir::homePath());
    if (!levelName.isEmpty()) {
        emit saveLevelTo(levelName.toAscii().data());
    }
}

/**
 *  @details    Launches a dialog in order to obtain an image to
 *              use as the background tile and then sets the 
 *              background tile to that image.
 */
void BBEditorWindow::getBackground()
{
    QString bgName;
    
    bgName = QFileDialog::getOpenFileName(this, "Background file", QDir::homePath(), "PNG (*.png);;All files (*)");
    if (!bgName.isEmpty()) {
        emit setBackgroundTile(bgName.toAscii().data());
    }
}

/////////////
// Private //
/////////////

/**
 *  @details    Creates the level menu on the window and its necessary actions
 *              in order to provide functionality for level saving, setting the
 *              background tile of the level and exitting.
 */
void BBEditorWindow::createMenu()
{
    QMenuBar * menuBar = this->menuBar();
    QAction * saveFileAction;
    QAction * setBackgroundAction;
    QAction * exitAction;
    
    levelFileMenu = menuBar->addMenu("Level");
    
    saveFileAction = levelFileMenu->addAction("Save");
    connect(saveFileAction, SIGNAL(triggered()), this, SLOT(saveLevel()));
    
    setBackgroundAction = levelFileMenu->addAction("Background");
    connect(setBackgroundAction, SIGNAL(triggered()), this, SLOT(getBackground()));
    
    exitAction = levelFileMenu->addAction("Quit");
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
}
