/**
 *  @file   GameArea.h
 *  @author Blurred-9L
 */
 
#ifndef GAME_AREA_H
#define GAME_AREA_H

#include <QGraphicsItem>
#include <QRectF>

#include <string>
using std::string;

class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;

/**
 *  @class  GameArea
 *  
 *  @brief  Class used to draw the tiled background of
 *          the game. The tiled background will be considered
 *          as an object on the scene.
 */
class GameArea : public QGraphicsItem {
private:
    /// The file path to the the tile image to use.
    string tileFile_;
    
public:
    /// GameArea constructor.
    GameArea(QGraphicsItem * parent = 0);
    /// Sets the GameArea's tileFile name.
    void setTileFile(const string & tileFile);
    /// GameArea destructor.
    virtual ~GameArea();
    /// Returns the bouncidng rectangle of the item.
    virtual QRectF boundingRect() const;
    /// Provides custom painting.
    virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
                       QWidget * widget = 0);
};

#endif /// NOT GAME_AREA_H
