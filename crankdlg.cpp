#include "crankdlg.h"
#include "ui_crankdlg.h"
#include <QDebug>
CRankDlg::CRankDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CRankDlg)
{
    ui->setupUi(this);

}

void CRankDlg::showRank()
{
    QString name;
    QString time;
    QString grade;

    switch (CRankDao::getRank())
    {
    case 10:
        name = QString::fromLatin1(ranks[9]->strName);
        ui->label_28->setText(name);
        time = QString::fromStdString(to_string(ranks[9]->nTime));
        ui->label_29->setText(time);
        grade = QString::fromStdString(to_string(ranks[9]->nGrade));
        ui->label_30->setText(grade);
    case 9:
        name = QString::fromLatin1(ranks[8]->strName);
        ui->label_25->setText(name);
        time = QString::fromStdString(to_string(ranks[8]->nTime));
        ui->label_26->setText(time);
        grade = QString::fromStdString(to_string(ranks[8]->nGrade));
        ui->label_27->setText(grade);
    case 8:
        name = QString::fromLatin1(ranks[7]->strName);
        ui->label_22->setText(name);
        time = QString::fromStdString(to_string(ranks[7]->nTime));
        ui->label_23->setText(time);
        grade = QString::fromStdString(to_string(ranks[7]->nGrade));
        ui->label_24->setText(grade);
    case 7:
        name = QString::fromLatin1(ranks[6]->strName);
        ui->label_19->setText(name);
        time = QString::fromStdString(to_string(ranks[6]->nTime));
        ui->label_20->setText(time);
        grade = QString::fromStdString(to_string(ranks[6]->nGrade));
        ui->label_21->setText(grade);
    case 6:
        name = QString::fromLatin1(ranks[5]->strName);
        ui->label_16->setText(name);
        time = QString::fromStdString(to_string(ranks[5]->nTime));
        ui->label_17->setText(time);
        grade = QString::fromStdString(to_string(ranks[5]->nGrade));
        ui->label_18->setText(grade);
    case 5:
        name = QString::fromLatin1(ranks[4]->strName);
        ui->label_13->setText(name);
        time = QString::fromStdString(to_string(ranks[4]->nTime));
        ui->label_14->setText(time);
        grade = QString::fromStdString(to_string(ranks[4]->nGrade));
        ui->label_15->setText(grade);
    case 4:
        name = QString::fromLatin1(ranks[3]->strName);
        ui->label_10->setText(name);
        time = QString::fromStdString(to_string(ranks[3]->nTime));
        ui->label_11->setText(time);
        grade = QString::fromStdString(to_string(ranks[3]->nGrade));
        ui->label_12->setText(grade);
    case 3:
        name = QString::fromLatin1(ranks[2]->strName);
        ui->label_7->setText(name);
        time = QString::fromStdString(to_string(ranks[2]->nTime));
        ui->label_8->setText(time);
        grade = QString::fromStdString(to_string(ranks[2]->nGrade));
        ui->label_9->setText(grade);
    case 2:
        name = QString::fromLatin1(ranks[1]->strName);
        ui->label_4->setText(name);
        time = QString::fromStdString(to_string(ranks[1]->nTime));
        ui->label_5->setText(time);
        grade = QString::fromStdString(to_string(ranks[1]->nGrade));
        ui->label_6->setText(grade);
    case 1:
        name = QString::fromLatin1(ranks[0]->strName);
        ui->label_1->setText(name);
        time = QString::fromStdString(to_string(ranks[0]->nTime));
        ui->label_2->setText(time);
        grade = QString::fromStdString(to_string(ranks[0]->nGrade));
        ui->label_3->setText(grade);
    case 0:
        this->show();
    }
}

CRankDlg::~CRankDlg()
{
    delete ui;
}

void CRankDlg::on_actionClear_triggered()
{
    for(int i = 0; ranks[i] != 0; i++)
    {
        ranks[i]->nTime = 0;
        ranks[i]->nGrade = 0;
        ranks[i]->strName[0] = 0;
    }
    CRankDao::saveRank();
}
