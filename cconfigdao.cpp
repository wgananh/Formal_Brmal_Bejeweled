#include "cconfigdao.h"

CConfigDao::CConfigDao()
{

}

void CConfigDao::set_theme_background(QString path){
    theme_background_path=path;
}

void CConfigDao::set_theme_gem(QString path){
    theme_gem_path=path;
}

void CConfigDao::set_theme_mask(QString path){
    theme_mask_path=path;
}

QString CConfigDao::get_theme_background(){
    return theme_background_path;
}

QString CConfigDao::get_theme_gem(){
    return theme_gem_path;
}

QString CConfigDao::get_theme_mask(){
    return theme_mask_path;
}
