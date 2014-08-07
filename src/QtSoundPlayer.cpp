/**
 *  @file   QtSoundPlayer.cpp
 *  @author Blurred-9L
 */

#include "QtSoundPlayer.h"

/**
 *  @details    The QtSoundPlayer object's constructor.
 *
 *  @param[in]  parent              This object's QObject parent.
 */
QtSoundPlayer::QtSoundPlayer(QObject * parent) :
    QObject(parent), SoundPlayer()
{
}

/**
 *  @details    The QtSoundPlayer object's destructor.
 */
QtSoundPlayer::~QtSoundPlayer()
{
}

/**
 *  @details    Method to be registered as callback for Qt's
 *              Phonon::MediaObjects to call when a state change
 *              occurs.
 *
 *  @param[in]  newState            The new state.
 *  @param[in]  oldState            The old state.
 */
void QtSoundPlayer::stateChanged(Phonon::State newState, Phonon::State oldState)
{
}
