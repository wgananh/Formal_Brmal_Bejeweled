#ifndef CNAMEDLG_H
#define CNAMEDLG_H

#include <QMainWindow>
#include <QCloseEvent>

namespace Ui {
class CNameDlg;
}

class CNameDlg : public QMainWindow
{
    Q_OBJECT

public:
    explicit CNameDlg(QWidget *parent = nullptr);
    ~CNameDlg();

signals:
    void nameConfirm(const char * name);

private slots:
    void on_btn_confirm_clicked();

private:
    void closeEvent(QCloseEvent *event);
    Ui::CNameDlg *ui;
};

#endif // CNAMEDLG_H
