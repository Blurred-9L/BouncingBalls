/**
 *  @file   BBResource.h
 *  @author Blurred-9L
 */
 
#ifndef BB_RESOURCE_H
#define BB_RESOURCE_H

/// The number of brick colors.
const int NUM_COLORS = 8;

/**
 *  @class  BBResouce
 *
 *  @brief  Class used as a namespace in which important constants
 *          can be accessed.
 */
class BBResource {
public:
    /**
     *  @enum   SoundIndex
     *
     *  @brief  Index values to use with the SoundPlayer class.
     */
    enum SoundIndex {
        BALL_BOUNCE_SOUND
    };

    /// The default brick width.
    static const float DEFAULT_BRICK_WIDTH;
    /// The default brick height.
    static const float DEFAULT_BRICK_HEIGHT;
    /// The default number of rows on a brick area.
    static const unsigned DEFAULT_ROWS;
    /// The default number of columns on a brick area.
    static const unsigned DEFAULT_COLS;
    /// The default bar speed.
    static const float DEFAULT_BAR_SPEED;
    /// The default ball speed.
    static const float DEFAULT_BALL_SPEED;
    /// The minimum ball speed.
    static const float MIN_BALL_SPEED;
    /// The constant for the ball's radius.
    static const float BALL_RADIUS;
    /// The constant for the bar's width.
    static const float BAR_WIDTH;
    /// The constant for the bar's height.
    static const float BAR_HEIGHT;
    /// The ball's initial x coordinate.
    static const float BALL_START_X;
    /// The ball's initial y coordinate.
    static const float BALL_START_Y;
    /// The bar's initial x coordinate.
    static const float BAR_START_X;
    /// The bar's initial y coordinate.
    static const float BAR_START_Y;
    /// The game area's minimum width
    static const unsigned MIN_SCENE_WIDTH;
    /// The game area's minimum height.
    static const unsigned MIN_SCENE_HEIGHT;
    /// The game area's maximum width.
    static const unsigned MAX_SCENE_WIDTH;
    /// The game area's maximum height.
    static const unsigned MAX_SCENE_HEIGHT;
    /// The whole scene's width.
    static const unsigned SCENE_WIDTH;
    /// The whole scene's height.
    static const unsigned SCENE_HEIGHT;
    /// The game's area x coordinate.
    static const float GAME_AREA_RECT_X;
    /// The game's area y coordinate.
    static const float GAME_AREA_RECT_Y;
    /// Path to the ball's image.
    static const char * BALL_IMG;
    /// Path to the bar's image.
    static const char * BAR_IMG;
    /// Path to the bricks' images.
    static const char * BRICK_IMGS[NUM_COLORS];
    /// Prefix for default levels.
    static const char * LEVEL_NAME_PREFIX;
    /// Path to bounce sound file.
    static const char * BALL_BOUNCE_FILE;
    /// Color names.
    static const char * COLOR_NAMES[NUM_COLORS];
};

#endif /// NOT BB_RESOURCE_H
