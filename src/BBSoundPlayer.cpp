/**
 *  @file   BBSoundPlayer.cpp
 *  @author Blurred-9L
 */

#include "BBSoundPlayer.h"
#include "BBController.h"

#include <cstring>
#include <iostream>

const int BBSoundPlayer::nValidFilenames = 1;

/**
 *  @details    The BBSoundPlayer object's constructor.
 *
 *  @param[in]  parent              This object's QObject parent.
 */
BBSoundPlayer::BBSoundPlayer(QObject * parent) :
    QtSoundPlayer(parent), audioOutput(0), sounds(0)
{
    audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    sounds = new Phonon::MediaObject * [nValidFilenames];
    /// Instantiates MediaObjects for all used sounds.
    for (int i = 0; i < nValidFilenames; i++) {
        sounds[i] = new Phonon::MediaObject();
        connect(sounds[i], SIGNAL(stateChanged(Phonon::State, Phonon::State)),
                this, SLOT(stateChanged(Phonon::State, Phonon::State)));
        Phonon::createPath(sounds[i], audioOutput);
    }
}

/**
 *  @details    The BBSoundPlayer object's destructor.
 */
BBSoundPlayer::~BBSoundPlayer()
{
    if (sounds != 0) {
        /// Frees all the MediaObjects manually as they weren't added to Qt's
        /// object tree.
        for (int i = 0; i < nValidFilenames; i++) {
            if (sounds[i] != 0) {
                delete sounds[i];
            }
        }
        delete [] sounds;
    }
}

/**
 *  @details    Plays the sound on the given index. The indexes used can be
 *              found on the SoundIndex enum. 
 *
 *  @param[in]  soundIndex          The index of the sound to play.
 */
void BBSoundPlayer::playSound(int soundIndex)
{
    const char * validFilenames[] = {BBController::BALL_BOUNCE_FILE};
    
    if (soundIndex < nValidFilenames) {
        sounds[soundIndex]->setCurrentSource(Phonon::MediaSource(validFilenames[soundIndex]));
        sounds[soundIndex]->play();
    }
}
