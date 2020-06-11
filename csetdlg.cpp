#include "csetdlg.h"
#include "ui_csetdlg.h"

CSetDlg::CSetDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CSetDlg)
{
    ui->setupUi(this);
    this->hide();
    theme = new CThemeDlg(this);
    music = new CMusicDlg(this);

    connect(parent,SIGNAL(menuToSet()),this,SLOT(doMenuToSet()));
    connect(theme,SIGNAL(themeToSet()),this,SLOT(doThemeToSet()));
    connect(music,SIGNAL(musicToSet()),this,SLOT(doMusicToSet()));

    connect(theme,SIGNAL(set_theme_background_change(QString)),this,SLOT(do_theme_background_change(QString)));
    connect(theme,SIGNAL(set_theme_gem_change(QString)),this,SLOT(do_theme_gem_change(QString)));
    connect(music,SIGNAL(set_music_background_change(QString)),this,SLOT(do_music_background_change(QString)));
}

CSetDlg::~CSetDlg()
{
    delete ui;
}

void CSetDlg::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    on_btn_setToMenu_clicked();
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
    music->show();
}

void CSetDlg::doMusicToSet(){
    this->show();
}

void CSetDlg::do_theme_background_change(QString path){
    emit menu_theme_background_change(path);
}

void CSetDlg::do_theme_gem_change(QString path){
    emit menu_theme_gem_change(path);
}

void CSetDlg::do_music_background_change(QString path)
{
    emit menu_music_background_change(path);
}
