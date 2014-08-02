/**
 *  @file   ThreadController.h
 *  @author Blurred-9L
 */

#ifndef THREAD_CONTROLLER_H
#define THREAD_CONTROLLER_H

#include <QObject>

class QThread;
class ThreadWorker;

/**
 *  @class  ThreadController
 *
 *  @brief  Base class to control threaded Qt applications.
 */
class ThreadController : public QObject {
Q_OBJECT

protected:
    /// The number of threads to use.
    unsigned numThreads;
    /// The active threads.
    QThread ** threads;
    /// The worker objects.
    ThreadWorker ** workers;
    
public:
    /// ThreadController constructor.
    ThreadController(unsigned numThreads, QObject * parent = 0);
    /// ThreadController destructor.
    virtual ~ThreadController();
    
public slots:
    /// Calls the threads to start.
    virtual void startThreads() = 0;
    /// Calls a thread to start.
    virtual void startThread(unsigned index) = 0;
    
};

#endif /// Not THREAD_CONTROLLER_H
