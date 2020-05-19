#include "cthemedlg.h"
#include "ui_cthemedlg.h"

CThemeDlg::CThemeDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CThemeDlg)
{
    ui->setupUi(this);
    this->hide();

    connect(parent,SIGNAL(setToTheme()),this,SLOT(doSetToTheme()));
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
    this->hide();
    emit themeToSet();
}

//当主题默认时，lineedit和toolbutton是锁定状态,并初始化lineedit中默认主题的图片路径
void CThemeDlg::Theme_default_locking(){
    if(ui->radioButton_Theme_default->isChecked()){
        ui->lineEdit_path_backgroundimags->setEnabled(false);
        ui->lineEdit_path_gemiamgs->setEnabled(false);
        ui->lineEdit_path_maskimags->setEnabled(false);
        ui->toolButton_selsect_backgroundiamgs->setEnabled(false);
        ui->toolButton_selsect_gemimags->setEnabled(false);
        ui->toolButton_selsect_maskimags->setEnabled(false);
        ui->lineEdit_path_backgroundimags->setText(backgroundimags_path);
        ui->lineEdit_path_gemiamgs->setText(gemimags_path);
        ui->lineEdit_path_maskimags->setText(maskiamgs_path);
    }
    else{
        ui->lineEdit_path_backgroundimags->setEnabled(true);
        ui->lineEdit_path_gemiamgs->setEnabled(true);
        ui->lineEdit_path_maskimags->setEnabled(true);
        ui->toolButton_selsect_backgroundiamgs->setEnabled(true);
        ui->toolButton_selsect_gemimags->setEnabled(true);
        ui->toolButton_selsect_maskimags->setEnabled(true);
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
        //当自定义按钮别选中时，lineedit里的文件路径清空
        ui->lineEdit_path_backgroundimags->clear();
        ui->lineEdit_path_gemiamgs->clear();
        ui->lineEdit_path_maskimags->clear();
    }
    Theme_default_locking();
}

//自定义时，选择背景图片
void CThemeDlg::on_toolButton_selsect_backgroundiamgs_clicked()
{
    backgroundimags_path = QFileDialog::getOpenFileName(this, "选择背景文件","/","所有文件 (*.*)");
    if(!backgroundimags_path.isEmpty()){
        ui->lineEdit_path_backgroundimags->setText(backgroundimags_path);
    }
}

//自定义时，选择宝石图片
void CThemeDlg::on_toolButton_selsect_gemimags_clicked()
{
    gemimags_path = QFileDialog::getOpenFileName(this, "选择宝石文件","/","所有文件 (*.*)");
    if(!gemimags_path.isEmpty()){
        ui->lineEdit_path_gemiamgs->setText(gemimags_path);
    }
}

//自定义时，选择掩码图片
void CThemeDlg::on_toolButton_selsect_maskimags_clicked()
{
    maskiamgs_path = QFileDialog::getOpenFileName(this, "选择掩码文件","/","所有文件 (*.*)");
    if(!gemimags_path.isEmpty()){
        ui->lineEdit_path_maskimags->setText(maskiamgs_path);
    }
}

void CThemeDlg::on_btn_theme_confirm_clicked()
{
    if(!ui->lineEdit_path_backgroundimags->text().isEmpty()){
        this->hide();
        emit theme_background_change(ui->lineEdit_path_backgroundimags->text());
        emit themeToSet();
    }
}

