#include "GameArea.h"
#include "BBResource.h"

#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QPixmap>
#include <QPointF>

/**
 *  @details    The GameArea object's constructor.
 *
 *  @param[in]  parent              This graphics item parent on the scene.
 */
GameArea::GameArea(QGraphicsItem * parent) :
    QGraphicsItem(parent), tileFile_()
{
}

/**
 *   @details   The GameArea object's destructor.
 */
GameArea::~GameArea()
{
}

/**
 *  @details    Sets the GameArea's tileFile attribute.
 *
 *  @param[in]  tileFile            The new filepath of the tile image to use.
 */
void GameArea::setTileFile(const string & tileFile)
{
    tileFile_ = tileFile;
}

/**
 *  @details    Gets the bounding rectangle of the GameArea item.
 *
 *  @return     A rectangle object delimiting the GameArea item.
 */
QRectF GameArea::boundingRect() const
{
    float penWidth = 1;
    float w = BBResource::MAX_SCENE_WIDTH;
    float h = BBResource::MAX_SCENE_HEIGHT;
    
    return QRectF(x() - penWidth / 2, y() - penWidth / 2,
                  w + penWidth, h + penWidth);
}

/**
 *  @details    Provides custom painting for this item.
 *
 *  @param[in]  painter
 *  @param[in]  option
 *  @param[in]  widget
 */
void GameArea::paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
                     QWidget * widget)
{
    QRectF rectangle(0, 0, BBResource::MAX_SCENE_WIDTH, BBResource::MAX_SCENE_HEIGHT);
                     
    painter->drawTiledPixmap(rectangle, QPixmap(tileFile_.c_str()));
}
