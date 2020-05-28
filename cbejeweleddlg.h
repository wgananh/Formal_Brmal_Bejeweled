#ifndef CBEJEWELEDDLG_H
#define CBEJEWELEDDLG_H

#include <QMainWindow>
#include "cgamedlg.h"
#include "chelpdlg.h"
#include "cmenudlg.h"
#include "cmusicdlg.h"
#include "csetdlg.h"
#include "cthemedlg.h"
#include "caboutdlg.h"
#include "crankdlg.h"
#include "cnamedlg.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CBejeweledDlg; }
QT_END_NAMESPACE

class CBejeweledDlg : public QMainWindow
{
    Q_OBJECT

public:
    CBejeweledDlg(QWidget *parent = nullptr);
    ~CBejeweledDlg();
    CRankDlg *rank;

private slots:
    void on_btn_mainToGame_clicked();
    void doGameToMain();

    void on_btn_mainToRank_clicked();

    void doNameConfirm();

    void on_btn_name_clicked();

signals:
    void mainToGame();

private:
    Ui::CBejeweledDlg *ui;
    CGameDlg *game;
    CNameDlg *name;

};
#endif // CBEJEWELEDDLG_H
