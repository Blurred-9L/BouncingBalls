/**
 *  @file   LevelLoader.cpp
 *  @author Blurred-9L
 */

#include "LevelLoader.h"
#include "BrickArea.h"
#include "Brick.h"

#include <fstream>
using std::ifstream;
#include <string>
using std::string;
#include <cstdio>
using std::scanf;

/// Parses a line into a Brick object.
static bool parseToBrick(const string & line, Brick & brick,
                         unsigned rows, unsigned cols);
       
/**
 *  @details    The LevelLoader object's constructor.
 */                  
LevelLoader::LevelLoader() :
    pathToBackgroundTile_()
{
}

/**
 *  @details    The LevelLoader object's destructor.
 */
LevelLoader::~LevelLoader()
{
}

/**
 *  @details    Gets the BrickArea's pathToBackgroundTile attribute.
 *
 *  @return     A string with the name of the path to the background file
 *              that is used in the current level.
 */
const string & LevelLoader::pathToBackgroundTile() const
{
    return pathToBackgroundTile_;
}

/**
 *  @details    Loads a level by reading a file and setting all required
 *              attributes on the array of bricks.
 *
 *  @param[in]  levelName           The name of the file with the level info.
 *  @param[in]  brickArea           The brickArea on which to load the level.
 *
 *  @return     A boolean value indicating if everything was ok when loading
 *              the level.
 */
bool LevelLoader::loadLevel(const char * levelName, BrickArea & brickArea)
{
    Brick * bricks = brickArea.bricks();
    ifstream levelFile(levelName);
    string line;
    unsigned index = 0;
    unsigned nRows = brickArea.nRows(), nColumns = brickArea.nColumns();
    unsigned totalBricks, breakableBricks, remainingBricks;
    bool levelLoaded = false;
    bool parseOk = true;
    
    if (levelFile.is_open()) {
        totalBricks = breakableBricks = remainingBricks = 0;
        getline(levelFile, pathToBackgroundTile_);
        getline(levelFile, line);
        while (!levelFile.eof() && parseOk) {
            parseOk = parseToBrick(line, bricks[index], nRows, nColumns);
            if (bricks[index].isBreakable()) {
                breakableBricks++;
                remainingBricks++;
            }
            totalBricks++;
            line = "";
            getline(levelFile, line);
            index++;
        }
        levelLoaded = (parseOk && levelFile.eof());
        levelFile.close();
    }
    
    if (levelLoaded) {
        brickArea.setTotalBricks(totalBricks);
        brickArea.setBreakableBricks(breakableBricks);
        brickArea.setRemainingBricks(remainingBricks);
    }
    
    return levelLoaded;
}

///////////////
// Functions //
///////////////

/**
 *  @details    Sets a bricks attributes to the ones specified by a line
 *              on the level file.
 *
 *  @param[in]  line                The line with the brick's data.
 *  @param[in}  brick               The brick to use.
 *  @param[in]  rows                The maximum number of rows.
 *  @param[in]  cols                The maximum number of columns.
 *
 *  @return     A boolean value indicating if the line was parsed correctly.
 */
bool parseToBrick(const string & line, Brick & brick,
                  unsigned rows, unsigned cols)
{
    unsigned row, column, color, breakable, type;
    bool parseOk = true;
    
    sscanf(line.c_str(), "%u,%u,%u,%u,%u", &row, &column, &color, &breakable, &type);
    if ((row >= rows) || (column >= cols) ||
        (color >= Brick::BRICK_COLOR_N_COLORS) ||
        (type >= Brick::BRICK_TYPE_N_TYPES)) {
        parseOk = false;
    }
    
    if (parseOk) {
        brick.setRow(row);
        brick.setColumn(column);
        brick.setBreakable(breakable != 0);
        switch (type) {
        case Brick::BRICK_TYPE_NORMAL:
            brick.setHitPoints(1);
            break;
        case Brick::BRICK_TYPE_METAL:
            brick.setHitPoints(2);
            color = Brick::BRICK_COLOR_SILVER;
            break;
        case Brick::BRICK_TYPE_IMMORTAL:
            brick.setHitPoints(0xFFFFFFFF);
            color = Brick::BRICK_COLOR_GOLDEN;
            break;
        }
        brick.setColor(color);
    }
    
    return parseOk;
}
