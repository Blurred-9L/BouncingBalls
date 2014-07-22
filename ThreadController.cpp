#include "ThreadController.h"
#include "ThreadWorker.h"

#include <QThread>

/**
 *  @details    Constructs a ThreadController object, which will be in
 *              charge of the specified number of threads. The arrays
 *              of threads and worker objects are initialized.
 *
 *  @param[in]  numThreads      The number of threads to use.
 *  @param[in]  parent          The controller's QObject parent.
 */
ThreadController::ThreadController(unsigned numThreads, QObject * parent) :
    QObject(parent), numThreads(numThreads), threads(0), workers(0)
{
    threads = new QThread * [numThreads];
    workers = new ThreadWorker * [numThreads];
    for (unsigned i = 0; i < numThreads; i++) {
        threads[i] = 0;
        workers[i] = 0;
    }
}

/**
 *  @details    Destroys a ThreadController object. Only the memory related
 *              to the arrays of workers and threads is released. Subclasses
 *              should implement their own destructor, making sure that the
 *              threads are stopped.
 */
ThreadController::~ThreadController()
{
    if (threads != 0) {
        delete [] threads;
    }
    if (workers != 0) {
        delete [] workers;
    }
}
