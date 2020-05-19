#ifndef CCONFIGDAO_H
#define CCONFIGDAO_H

#include "cconfig.h"

class CConfigDao
{
public:
    CConfigDao();
    void set_theme_background(QString);
    void set_theme_gem(QString);
    void set_theme_mask(QString);
    QString get_theme_background();
    QString get_theme_gem();
    QString get_theme_mask();

private:
    QString theme_background_path,theme_gem_path,theme_mask_path;
};

#endif // CCONFIGDAO_H
