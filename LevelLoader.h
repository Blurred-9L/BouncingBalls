/**
 *  @file   LevelLoader.h
 *  @author Blurred-9L
 */
 
#ifndef LEVEL_LOADER_H
#define LEVEL_LOADER_H

#include <string>
using std::string;

class BrickArea;

/**
 *  @class  LevelLoader
 *
 *  @brief  Class used to handle the loading of levels from
 *          files into a BrickArea object.
 */
class LevelLoader {
protected:
    /// The name of the current tile used for background.
    string pathToBackgroundTile_;
    
public:
    /// LevelLoader constructor.
    LevelLoader();
    /// LevelLoader destructor.
    virtual ~LevelLoader();
    /// Gets the path to the background tile.
    const string & pathToBackgroundTile() const;
    /// Loads a level.
    virtual bool loadLevel(const char * levelName, BrickArea & brickArea);
};

#endif /// NOT LEVEL_LOADER_H
