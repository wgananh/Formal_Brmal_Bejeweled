#include "csetdlg.h"
#include "ui_csetdlg.h"

CSetDlg::CSetDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CSetDlg)
{
    ui->setupUi(this);
    this->hide();
    CThemeDlg *theme = new CThemeDlg(this);
    connect(parent,SIGNAL(menuToSet()),this,SLOT(doMenuToSet()));
    connect(theme,SIGNAL(themeToSet()),this,SLOT(doThemeToSet()));
    connect(theme,SIGNAL(set_theme_background_change(QString)),this,SLOT(do_theme_background_change(QString)));
}

CSetDlg::~CSetDlg()
{
    delete ui;
}

void CSetDlg::doMenuToSet(){
    this->show();
}

void CSetDlg::on_btn_setToMenu_clicked()
{
    this->hide();
    emit setToMenu();
}

void CSetDlg::on_btn_setToTheme_clicked()
{
    this->hide();
    emit setToTheme();
}

void CSetDlg::doThemeToSet(){
    this->show();
}

void CSetDlg::on_btn_setToMusic_clicked()
{
    this->hide();
    CMusicDlg *cm = new CMusicDlg(this);
    connect(cm,SIGNAL(musicToSet()),this,SLOT(doMusicToSet()));
    cm->show();
}

void CSetDlg::doMusicToSet(){
    this->show();
}

void CSetDlg::do_theme_background_change(QString path){
    emit menu_theme_background_change(path);
}
