#include "cmusicplayer.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>

CMusicPlayer::CMusicPlayer()
{
    gameSound->setMedia(QUrl::fromLocalFile("D:\\Da Er 2\\Program\\Bejeweled\\bgm.mp3"));
    gameSound->setVolume(80);
}

void CMusicPlayer::MusicOn(){
    gameSound->play();
}

void CMusicPlayer::MusicOff(){
    gameSound->stop();
}
