#ifndef BB_SOUND_PLAYER_H
#define BB_SOUND_PLAYER_H

#include "QtSoundPlayer.h"

#include <QObject>
#include <Phonon/MediaObject>
#include <Phonon/AudioOutput>

/**
 *  @class  BBSoundPlayer
 */
class BBSoundPlayer : public QtSoundPlayer {
Q_OBJECT

private:
    /// The audio output to connect.
    Phonon::AudioOutput * audioOutput;
    /// The media objects sounds array.
    Phonon::MediaObject ** sounds;
    
public:
    /// The number of known filenames.
    static const int nValidFilenames;

    /// BBSoundPlayer constructor.
    BBSoundPlayer(QObject * parent = 0);
    /// QtSoundPlayer destructor.
    virtual ~BBSoundPlayer();
    /// Plays sound asynchronously.
    virtual void playSound(int soundIndex);
};

#endif /// Not BB_SOUND_PLAYER_H
