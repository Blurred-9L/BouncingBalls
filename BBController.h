/**
 *  @file   BBcontroller.h
 *  @author Blurred-9L
 */

#ifndef BB_CONTROLLER_H
#define BB_CONTROLLER_H

#include "ThreadController.h"

class BBGame;
class GameObject;
class Brick;

/// The number of brick colors.
const int NUM_COLORS = 8;

/**
 *  @class  BBController
 *
 *  @brief  Class that handles interactions between the game's
 *          processing, user input and the scene's drawing.
 */
class BBController : public ThreadController {
Q_OBJECT

private:
    /// Flag indicating the game goes on.
    bool isActive;
    /// The effective width.
    unsigned width_;
    /// The effective height.
    unsigned height_;
    /// The game instance.
    BBGame * game_;

public:
    /// The scene's minimum width
    static const int MIN_WIDTH;
    /// The scene's minimum height.
    static const int MIN_HEIGHT;
    /// The scene's maximum width.
    static const int MAX_WIDTH;
    /// The scene's maximum height.
    static const int MAX_HEIGHT;
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
    
    /**
     *  @enum   SoundIndex
     *
     *  @brief  Index values to use with the SoundPlayer class.
     */
    enum SoundIndex {
        BALL_BOUNCE_SOUND
    };

    /// BBController constructor.
    explicit BBController(unsigned width, unsigned height, QObject * parent = 0);
    /// BBController destructor.
    virtual ~BBController();
    /// Gets the width.
    unsigned width();
    /// Gets the height.
    unsigned height();
    /// Stops threads.
    void stopThreads();
    
public slots:
    /// Calls the threads to start.
    virtual void startThreads();
    /// Calls a thread to start.
    virtual void startThread(unsigned index);
    /// Updates the scene viewed.
    void updateScene();
    /// Handles left movement events.
    void handleLeftMovement();
    /// Handles right movement events.
    void handleRightMovement();
    /// Handles accept events.
    void handleAccept();
    /// Handles left stop events.
    void handleLeftStop();
    /// Handles right stop events.
    void handleRightStop();
    
signals:
    /// Draws the ball on the scene.
    void drawBall(const GameObject & ball);
    /// Draws the bar on the scene.
    void drawBar(const GameObject & bar);
    /// Draws the brick on the scene.
    void drawBrick(const Brick & brick);
    /// Removes the brick on the given index.
    void removeBrick(unsigned index);
    /// Resets the number of bricks objects on the scene.
    void resetBricks();
};

#endif /// NOT BB_CONTROLLER_H
