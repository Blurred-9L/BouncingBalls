/**
 *  @file   QtSoundPlayer.h
 *  @author Blurred-9L
 */

#ifndef QT_SOUND_PLAYER_H
#define QT_SOUND_PLAYER_H

#include "SoundPlayer.h"

#include <QObject>
#include <Phonon/MediaObject>

/**
 *  @class  QtSoundPlayer
 *
 *  @brief  Class that serves as the parent class for SoundPlayer
 *          classes that might use Qt to provide sound effects.
 */
class QtSoundPlayer : public QObject, public SoundPlayer {
Q_OBJECT

public:
    /// QtSoundPlayer constructor.
    QtSoundPlayer(QObject * parent = 0);
    /// QtSoundPlayer destructor.
    virtual ~QtSoundPlayer();
    /// Plays sound asynchronously.
    virtual void playSound(int soundIndex) = 0;
    
public slots:
    /// Checks state change.
    void stateChanged(Phonon::State newState, Phonon::State oldState);
};

#endif /// Not QT_SOUND_PLAYER_H
