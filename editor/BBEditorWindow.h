/**
 *  @file   BBEditorWindow.h
 *  @author Blurred-9L
 */

#ifndef BB_EDITOR_WINDOW_H
#define BB_EDITOR_WINDOW_H

#include <QMainWindow>

class QMenu;
class BBEditorWidget;

/**
 *  @class  BBEditorWindow
 *
 *  @brief  Class that becomes the window on which the editor
 *          widget is embedded, providing the menu bar needed.
 */
class BBEditorWindow : public QMainWindow {
Q_OBJECT

private:
    /// The level file menu.
    QMenu * levelFileMenu;
    /// The editor widget.
    BBEditorWidget * editorWidget;
    
    /// Fills up the menu bar.
    void createMenu();

public:
    /// BBEditorWindow constructor.
    BBEditorWindow();
    /// BBEditorWindow destructor.
    virtual ~BBEditorWindow();
    
public slots:
    /// Handles level file name input.
    void saveLevel();
    /// Gets the name of the background tile file.
    void getBackground();

signals:
    /// Notifies that the level should be saved.
    void saveLevelTo(const char *);
    /// Notifies that the background tile has been chosen.
    void setBackgroundTile(const char *);
};

#endif /// NOT BB_EDITOR_WINDOW_H
