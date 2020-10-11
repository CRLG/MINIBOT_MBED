#ifndef IA_H
#define IA_H

#include "iabase.h"
#include "sm_autotest.h"
#include "sm_recup5bouees.h"

#include "sm_activerphare.h"
#include "sm_depose3bouees.h"
#include "sm_depose2bouees.h"
#include "sm_detecternordsud.h"
#include "sm_arriverabonport.h"
#include "sm_debuginterface.h"

class IA : public IABase
{
public:
    IA();

    // States machines
    SM_Autotest                 m_sm_autotest;
    SM_ActiverPhare             m_sm_activer_phare;
    SM_Recup5Bouees             m_sm_recup_5_bouees;
    SM_Depose3bouees            m_sm_depose_3_bouees;
    SM_Depose3bouees            m_sm_depose_2_bouees;
    SM_DetecterNordSud          m_sm_detecter_nord_sud;
    SM_ArriverABonPort          m_sm_arriver_a_bon_port;

    void step();
    void init();

    void setStrategie(unsigned char strategie);
    void setMaxScores();
};

#endif // IA_H
