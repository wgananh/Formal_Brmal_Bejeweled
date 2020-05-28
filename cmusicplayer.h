#ifndef CMUSICPLAYER_H
#define CMUSICPLAYER_H
#include <QMediaPlayer>
#include <QMediaPlaylist>

class CMusicPlayer
{
public:
    CMusicPlayer();

    QMediaPlayer *music;
    QMediaPlayer *gameSound = new QMediaPlayer;//创建播放器
    QMediaPlaylist *gameList = new QMediaPlaylist;//创建播放列表
    QMediaPlayer *gameSound_eliminate = new QMediaPlayer;//创建播放器
    QMediaPlayer *gameSound_great = new QMediaPlayer;
    QMediaPlayer *gameSound_excellent = new QMediaPlayer;
    QMediaPlayer *gameSound_amazing = new QMediaPlayer;
    QMediaPlayer *gameSound_unbelievable = new QMediaPlayer;
    QMediaPlayer *gameSound_last_4s = new QMediaPlayer;
    QMediaPlayer *gameSound_down = new QMediaPlayer;

    void MusicOn();
    void MusicOff();
    void Music_eliminate();
    void Music_great();
    void Music_excellent();
    void Music_amazing();
    void Music_unbelievable();
    void Music_last_4sON();
    void Music_last_4sOFF();
    void Music_down();
};

#endif // CMUSICPLAYER_H
