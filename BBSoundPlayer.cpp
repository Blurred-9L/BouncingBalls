#include "BBSoundPlayer.h"
#include "BBController.h"

#include <cstring>
#include <iostream>

const int BBSoundPlayer::nValidFilenames = 1;

BBSoundPlayer::BBSoundPlayer(QObject * parent) :
    QtSoundPlayer(parent), audioOutput(0), sounds(0)
{
    audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    sounds = new Phonon::MediaObject * [nValidFilenames];
    for (int i = 0; i < nValidFilenames; i++) {
        sounds[i] = new Phonon::MediaObject();
        connect(sounds[i], SIGNAL(stateChanged(Phonon::State, Phonon::State)),
                this, SLOT(stateChanged(Phonon::State, Phonon::State)));
        Phonon::createPath(sounds[i], audioOutput);
    }
}

BBSoundPlayer::~BBSoundPlayer()
{
    if (sounds != 0) {
        for (int i = 0; i < nValidFilenames; i++) {
            if (sounds[i] != 0) {
                delete sounds[i];
            }
        }
        delete [] sounds;
    }
}

void BBSoundPlayer::playSound(int soundIndex)
{
    const char * validFilenames[] = {BBController::BALL_BOUNCE_FILE};
    
    if (soundIndex < nValidFilenames) {
        sounds[soundIndex]->setCurrentSource(Phonon::MediaSource(validFilenames[soundIndex]));
        sounds[soundIndex]->play();
    }
}
