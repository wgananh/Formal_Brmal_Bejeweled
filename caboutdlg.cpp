#include "caboutdlg.h"
#include "ui_caboutdlg.h"

CAboutDlg::CAboutDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CAboutDlg)
{
    ui->setupUi(this);
    static const QDate buildDate = QLocale( QLocale::English ).toDate( QString(__DATE__).replace("  ", " 0"), "MMM dd yyyy");
    static const QTime buildTime = QTime::fromString(__TIME__, "hh:mm:ss");
    lastupdatetime = QString("%1 %2").arg(buildDate.toString("yyyy.MM.dd")).arg(buildTime.toString());
    ui->label_8->setText(lastupdatetime);
}


CAboutDlg::~CAboutDlg()
{
    delete ui;
}

