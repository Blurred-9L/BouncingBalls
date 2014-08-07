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
    /// Draws the background of the level.
    void drawBackground(const char * tileFile);
};

#endif /// NOT BB_CONTROLLER_H
