#ifndef CTHEMEDLG_H
#define CTHEMEDLG_H

#include <QMainWindow>
#include "cconfig.h"

namespace Ui {
class CThemeDlg;
}

class CThemeDlg : public QMainWindow
{
    Q_OBJECT

public:
    explicit CThemeDlg(QWidget *parent = nullptr);
    ~CThemeDlg();

private:
    Ui::CThemeDlg *ui;
};

#endif // CTHEMEDLG_H
