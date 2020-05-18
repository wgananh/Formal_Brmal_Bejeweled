#ifndef CBEJEWELEDDLG_H
#define CBEJEWELEDDLG_H

#include <QMainWindow>
#include "cgamedlg.h"
#include "chelpdlg.h"
#include "cmenudlg.h"
#include "cmusicdlg.h"
#include "csetdlg.h"
#include "cthemedlg.h"
#include "crankdlg.h"
#include "crankdlg.h"
#include "caboutdlg.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CBejeweledDlg; }
QT_END_NAMESPACE

class CBejeweledDlg : public QMainWindow
{
    Q_OBJECT

public:
    CBejeweledDlg(QWidget *parent = nullptr);
    ~CBejeweledDlg();

private slots:
    void on_btn_mainToGame_clicked();
    void doGameToMain();

signals:
    void mainToGame();

private:
    Ui::CBejeweledDlg *ui;
};
#endif // CBEJEWELEDDLG_H
