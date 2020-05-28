#include "cthemedlg.h"
#include "ui_cthemedlg.h"

CThemeDlg::CThemeDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CThemeDlg)
{
    ui->setupUi(this);

    connect(parent,SIGNAL(setToTheme()),this,SLOT(doSetToTheme()));
    initialgemtype();
    Theme_default_locking();
}

CThemeDlg::~CThemeDlg()
{
    delete ui;
}

void CThemeDlg::doSetToTheme(){
    this->show();
}

void CThemeDlg::on_btn_themeToSet_clicked()
{
    this->close();
    emit themeToSet();
}

void CThemeDlg::initialgemtype(){
    ui->comboBox_gemtype->addItem("gem");
    ui->comboBox_gemtype->addItem("fish");
    ui->comboBox_gemtype->addItem("mine");
}

//当主题默认时，lineedit和toolbutton是锁定状态,并初始化lineedit中默认主题的图片路径
void CThemeDlg::Theme_default_locking(){
    if(ui->radioButton_Theme_default->isChecked()){
        ui->lineEdit_path_backgroundimags->setEnabled(false);
        ui->toolButton_selsect_backgroundiamgs->setEnabled(false);
        ui->comboBox_gemtype->setEnabled(false);
        ui->lineEdit_path_backgroundimags->setText(backgroundimags_path);
        ui->comboBox_gemtype->setCurrentIndex(0);
    }
    else{
        ui->lineEdit_path_backgroundimags->setEnabled(true);
        ui->toolButton_selsect_backgroundiamgs->setEnabled(true);
        ui->comboBox_gemtype->setEnabled(true);
        ui->lineEdit_path_backgroundimags->setText(backgroundimags_path);
        ui->comboBox_gemtype->setCurrentIndex(0);
    }
}

//主题默认和自定义两个按钮互锁（二选一）
void CThemeDlg::on_radioButton_Theme_default_clicked()
{
    if(ui->radioButton_Theme_custom->isChecked()){
        ui->radioButton_Theme_default->setChecked(false);
    }
    else{
        ui->radioButton_Theme_default->setChecked(true);
    }
    Theme_default_locking();
}

//主题默认和自定义两个按钮互锁（二选一）
void CThemeDlg::on_radioButton_Theme_custom_clicked()
{
    if(ui->radioButton_Theme_default->isChecked()){
        ui->radioButton_Theme_custom->setChecked(false);
    }
    else{
        ui->radioButton_Theme_custom->setChecked(true);
    }
    Theme_default_locking();
}

//自定义时，选择背景图片,将路径传递到CConfig类
void CThemeDlg::on_toolButton_selsect_backgroundiamgs_clicked()
{
    QString background_path = QFileDialog::getOpenFileName(this, "选择背景文件","/","所有文件 (*.*)");
    if(!background_path.isEmpty()){
        ui->lineEdit_path_backgroundimags->setText(background_path);
    }
}

//确定后对背景图片、宝石图片、掩码图片进行更改，将其路径保存到config类中，在configlogic类中对cgame的背景、宝石图片进行具体修改
void CThemeDlg::on_btn_theme_confirm_clicked()
{
    if(!ui->lineEdit_path_backgroundimags->text().isEmpty()){
        QString background_path=ui->lineEdit_path_backgroundimags->text(),gem_path,mask_path;
        this->hide();
        config->set_theme_background(background_path);
        emit set_theme_background_change(background_path);
        config->set_theme_gem(gem_path);
        emit set_theme_gem_change(ui->comboBox_gemtype->currentText());
        config->set_theme_mask(mask_path);

        emit themeToSet();
    }
}

