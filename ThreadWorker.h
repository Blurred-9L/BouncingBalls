#ifndef THREAD_WORKER_H
#define THREAD_WORKER_H

#include <QObject>

/**
 *  @class  ThreadWorker
 */
class ThreadWorker : public QObject {
Q_OBJECT

private:
    /// This thread's id.
    unsigned workerId;
    
protected:
    /// Tells this thread to sleep.
    void sleep(unsigned msecs);

public:
    /// ThreadWorker constructor.
    ThreadWorker(unsigned id, QObject * parent = 0);
    /// ThreadWorker destructor.
    virtual ~ThreadWorker();
    
    /// Waits for the indicated milliseconds.
    static void wait(unsigned msecs);
    
public slots:
    /// Does work.
    virtual void execute() = 0;
    
signals:
    /// This thread's work is done function.
    void done();
};

#endif /// NOT THREAD_WORKER_H
