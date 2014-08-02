#include "QtSoundPlayer.h"

QtSoundPlayer::QtSoundPlayer(QObject * parent) :
    QObject(parent), SoundPlayer()
{
}

QtSoundPlayer::~QtSoundPlayer()
{
}

void QtSoundPlayer::stateChanged(Phonon::State newState, Phonon::State oldState)
{
}
