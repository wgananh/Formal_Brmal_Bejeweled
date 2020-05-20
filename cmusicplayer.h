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

    void MusicOn();
    void MusicOff();
};

#endif // CMUSICPLAYER_H
