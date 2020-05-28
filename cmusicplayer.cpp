#include "cmusicplayer.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>

CMusicPlayer::CMusicPlayer()
{
    gameList->addMedia(QUrl("qrc:/bgm.mp3"));
    gameSound_eliminate->setMedia(QUrl("qrc:/eliminate_c.mp3"));
    gameSound_great->setMedia(QUrl("qrc:/great.mp3"));
    gameSound_excellent->setMedia(QUrl("qrc:/excellent.mp3"));
    gameSound_amazing->setMedia(QUrl("qrc:/amazing.mp3"));
    gameSound_unbelievable->setMedia(QUrl("qrc:/unbelievable.mp3"));
    gameSound_last_4s->setMedia(QUrl("qrc:/last_4s.mp3"));
    gameSound_down->setMedia(QUrl("qrc:/down.mp3"));
    gameList->setCurrentIndex(1);
    gameList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    gameSound->setPlaylist(gameList);
    gameSound->setVolume(10);
    gameSound_eliminate->setVolume(30);
    gameSound_great->setVolume(30);
    gameSound_excellent->setVolume(30);
    gameSound_amazing->setVolume(30);
    gameSound_unbelievable->setVolume(30);
    gameSound_last_4s->setVolume(10);
    gameSound_down->setVolume(20);
}

void CMusicPlayer::MusicOn(){
    gameSound->play();
}

void CMusicPlayer::MusicOff(){
    gameSound->stop();
}

void CMusicPlayer::Music_eliminate(){
    gameSound_eliminate->play();
}

void CMusicPlayer::Music_great(){
    gameSound_great->play();
}

void CMusicPlayer::Music_excellent(){
    gameSound_excellent->play();
}

void CMusicPlayer::Music_amazing(){
    gameSound_amazing->play();
}

void CMusicPlayer::Music_unbelievable(){
    gameSound_unbelievable->play();
}

void CMusicPlayer::Music_last_4sON(){
    gameSound_last_4s->play();
}

void CMusicPlayer::Music_last_4sOFF(){
    gameSound_last_4s->stop();
}

void CMusicPlayer::Music_down(){
    gameSound_down->play();
}
