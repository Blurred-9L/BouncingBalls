#include "ThreadWorker.h"

#include <ctime>

/**
 *  @details    Constructs a ThreadWorker object assigning it an id.
 *
 *  @param[in]  id              The worker's id.
 *  @param[in]  parent          The worker's QObject parent.
 */
ThreadWorker::ThreadWorker(unsigned id, QObject * parent) :
    QObject(parent), workerId(id)
{
}

/**
 *  @details    Destroys a ThreadWorker object. Any memory used on
 *              the thread should be released here.
 */
ThreadWorker::~ThreadWorker()
{
}

/**
 *  @details    Makes the application wait the specified amount of
 *              milliseconds.
 *
 *  @param[in]  msecs           The milliseconds to wait.
 */
void ThreadWorker::wait(unsigned msecs)
{
    double seconds = (double)msecs / 1000;
    clock_t start = clock();
    
    while (((double)(clock() - start) / CLOCKS_PER_SEC) < seconds) {
    }
}

///////////////
// Protected //
///////////////

/**
 *  @details    Puts the thread to sleep for the specified amount of
 *              milliseconds.
 *
 *  @param[in]  msecs           The milliseconds to sleep.
 */
void ThreadWorker::sleep(unsigned msecs)
{
    double seconds = (double)msecs / 1000;
    clock_t start = clock();
    
    while (((double)(clock() - start) / CLOCKS_PER_SEC) < seconds) {
    }
}
