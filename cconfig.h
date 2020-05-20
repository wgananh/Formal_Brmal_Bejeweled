#ifndef CCONFIG_H
#define CCONFIG_H
#include <QMainWindow>

class CConfig
{
public:
    CConfig();
    void set_theme_background(QString);
    void set_theme_gem(QString);
    void set_theme_mask(QString);
    QString get_theme_background();
    QString get_theme_gem();
    QString get_theme_mask();

private:
    QString theme_background_path,theme_gem_path,theme_mask_path;

};

#endif // CCONFIG_H
