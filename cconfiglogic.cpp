#include "cconfiglogic.h"

CConfigLogic::CConfigLogic()
{
}

void CConfigLogic::Theme_background_change(){
    QString path=config->get_theme_background();
    configdao->set_theme_background(path);

}

void CConfigLogic::Theme_gem_change(){
    QString path=config->get_theme_gem();
    configdao->set_theme_gem(path);

}


void CConfigLogic::Theme_mask_change(){
    QString path=config->get_theme_mask();
    configdao->set_theme_mask(path);
}
