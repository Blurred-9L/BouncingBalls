#ifndef BB_CONTROLLER_H
#define BB_CONTROLLER_H

#include "ThreadController.h"

class BBGame;
class GameObject;

/**
 *  @class  BBController
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
};

#endif /// NOT BB_CONTROLLER_H
