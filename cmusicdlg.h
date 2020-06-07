#ifndef CMUSICDLG_H
#define CMUSICDLG_H

#include <QMainWindow>
#include <QFileDialog>
#include "cconfig.h"
#include "cmusicplayer.h"

namespace Ui {
class CMusicDlg;
}

class CMusicDlg : public QMainWindow
{
    Q_OBJECT

public:
    CMusicDlg(QWidget *parent = nullptr);
    ~CMusicDlg();

private slots:

    void on_Button_exit_clicked();

    void on_Button_sure_clicked();

    void on_btn_path_clicked();

signals:
    void musicToSet();
    void set_music_background_change(QString);
private:
    Ui::CMusicDlg *ui;

    QString BGM;

    void Music_Default();
};

#endif // CMUSICDLG_H
