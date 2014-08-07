/**
 *  @file   BBWorker.h
 *  @author Blurred-9L
 */

#ifndef BB_WORKER_H
#define BB_WORKER_H

#include "ThreadWorker.h"

class BBGame;

/**
 *  @class  BBWorker
 *
 *  @brief  Handles the game's processing in a different thread.
 */
class BBWorker : public ThreadWorker {
Q_OBJECT

private:
    /// The game instance.
    BBGame & game;
    /// Flag indicating to go on.
    bool & goOn;
    /// The scene's width.
    unsigned width;
    /// The scene's height.
    unsigned height;

public:
    /// BBWorker constructor.
    BBWorker(unsigned id, BBGame & game, bool & goOn, unsigned width,
             unsigned height, QObject * parent = 0);
    /// BBWorker destructor.
    virtual ~BBWorker();
    
public slots:
    /// Does work.
    virtual void execute();
    
signals:
    /// Updates the scene viewed.
    void updateScene();

};

#endif /// NOT BB_WORKER_H
