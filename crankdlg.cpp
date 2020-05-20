#include "crankdlg.h"
#include "ui_crankdlg.h"
#include <QDebug>
CRankDlg::CRankDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CRankDlg)
{
    cranklogic = new CRankLogic();
    cranklogic->updateRank();
//    for(int i = 0; i < 10; i++)
//        for(int j = 0; j < 3; j++)
//            ui->tableWidget->setItem(i, j, new QTableWidgetItem(""));
    qDebug() << ui->
    ui->setupUi(this);

}

void CRankDlg::showRank()
{
//    cranklogic->updateRank();
    for(int i = 0; i < cranklogic->crankdao->totalNumber; i++)
    {
        const QString name = QString::fromLatin1(cranklogic->crankdao->ranks[i]->strName);
//        qDebug() << this->ui->tableWidget->item(1, 1)->text();
        this->ui->tableWidget->item(i, 0)->setText(name);
        const QString time = QString::fromStdString(to_string(cranklogic->crankdao->ranks[i]->nTime));
        this->ui->tableWidget->item(i, 1)->setText(time);
        const QString grade = QString::fromStdString(to_string(cranklogic->crankdao->ranks[i]->nGrade));
        this->ui->tableWidget->item(i, 2)->setText(grade);
    }
    this->show();
}

CRankDlg::~CRankDlg()
{
    delete ui;
}
