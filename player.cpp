#include "player.h"

player::player(QWidget *parent) : QWidget(parent)
{
    initsys();
}

void player::initsys()
{
    play = new QMediaPlayer(this);
    connect(play,&QMediaPlayer::mediaStatusChanged,[=](QMediaPlayer::MediaStatus status)
    {
        if(status==QMediaPlayer::EndOfMedia)
        {
            play->setMedia(QUrl::fromLocalFile(filename));
            play->play();
        }
    });
    connect(this,&player::sig_value,play,&QMediaPlayer::setVolume);
}

void player::bofang_file(int state)  //播放音频
{
    switch (state) {
    case 1:
    {
        play->stop();
        filename = "../doudizhu-main/wav/zhuzhuxia.mp3";
        play->setMedia(QUrl::fromLocalFile(filename));
        play->play();
        break;
    }
    case 2:
    {
        play->stop();
        filename = "../doudizhu-main/wav/667.wav";
        play->setMedia(QUrl::fromLocalFile(filename));
        play->play();
        break;
    }
    case 3:
    {
        QMediaPlayer *pp = new QMediaPlayer(this);
        pp->setVolume(Cvalue_va);
        connect(pp,&QMediaPlayer::mediaStatusChanged,[=](QMediaPlayer::MediaStatus status)
        {
            if(status==QMediaPlayer::EndOfMedia)
            {
                pp->deleteLater();
            }
        });
        QString str1 = "../doudizhu-main/wav/yaobuqi.wav";
        pp->setMedia(QUrl::fromLocalFile(str1));
        pp->play();
        break;
    }
    default:
        break;
    }
}

void player::slot_value(int Cvalue)
{
    Cvalue_va = Cvalue;
    play->setVolume(Cvalue_va);
    emit sig_value(Cvalue_va);
}
