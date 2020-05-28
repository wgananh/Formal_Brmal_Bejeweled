#include "cmusicplayer.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>

CMusicPlayer::CMusicPlayer()
{
    gameList->addMedia(QUrl("qrc:/bgm.mp3"));
    gameList->setCurrentIndex(1);
    gameList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    gameSound->setPlaylist(gameList);
    gameSound->setVolume(10);
}

void CMusicPlayer::MusicOn(){
    gameSound->play();
}

void CMusicPlayer::MusicOff(){
    gameSound->stop();
}
