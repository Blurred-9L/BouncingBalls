#ifndef SOUND_PLAYER_H
#define SOUND_PLAYER_H

/**
 *  @class  SoundPlayer
 */
class SoundPlayer {
public:
    /// SoundPlayer constructor.
    SoundPlayer();
    /// SoundPlayer destructor.
    virtual ~SoundPlayer();
    /// Plays a sound asynchronously.
    virtual void playSound(int soundIndex) = 0;
};

#endif /// Not SOUND_PLAYER_H
