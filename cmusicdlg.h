#ifndef CMUSICDLG_H
#define CMUSICDLG_H

#include <QMainWindow>
#include "cconfig.h"

namespace Ui {
class CMusicDlg;
}

class CMusicDlg : public QMainWindow
{
    Q_OBJECT

public:
    explicit CMusicDlg(QWidget *parent = nullptr);
    ~CMusicDlg();

private slots:

    void on_Button_exit_clicked();

    void on_Button_sure_clicked();

signals:
    void musicToSet();

private:
    Ui::CMusicDlg *ui;

    QString BGM;

    void Music_Default();
};

#endif // CMUSICDLG_H
