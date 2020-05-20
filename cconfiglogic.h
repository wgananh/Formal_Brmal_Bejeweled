#ifndef CCONFIGLOGIC_H
#define CCONFIGLOGIC_H

#include "cmusicplayer.h"
#include "cconfig.h"
#include "cconfigdao.h"

class CConfigLogic
{
public:
    CConfigLogic();
    void Theme_background_change();
    void Theme_gem_change();
    void Theme_mask_change();


private:
    CConfigDao *configdao = new CConfigDao();
    CConfig *config = new CConfig();
};

#endif // CCONFIGLOGIC_H
