#include "cmusicdlg.h"
#include "ui_cmusicdlg.h"

CMusicDlg::CMusicDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CMusicDlg)
{
    ui->setupUi(this);
    //Music_Default();
}

CMusicDlg::~CMusicDlg()
{
    delete ui;
}
void CMusicDlg::Music_Default(){
    ui->radioButton->setChecked(true);
    ui->radioButton_3->setChecked(true);
}

void CMusicDlg::on_Button_exit_clicked()
{
    emit musicToSet();
    this->close();
}

void CMusicDlg::on_Button_sure_clicked()
{
    if(ui->radioButton->isChecked()){
        ui->radioButton->setChecked(true);
        ui->radioButton_2->setChecked(false);
    }
    if(ui->radioButton_2->isChecked()){
        ui->radioButton->setChecked(false);
        ui->radioButton_2->setChecked(true);
    }
    if(ui->radioButton_3->isChecked()){
        ui->radioButton_3->setChecked(true);
        ui->radioButton_4->setChecked(false);
    }
    if(ui->radioButton_4->isChecked()){
        ui->radioButton_3->setChecked(false);
        ui->radioButton_4->setChecked(true);
    }
}
