#ifndef IA_H
#define IA_H

#include "iabase.h"
#include "sm_autotest.h"

#include "sm_carresdefouille.h"
#include "sm_deposerreplique.h"
#include "sm_recupererechantillon.h"
#include "sm_retourzonedepart.h"

#include "sm_debuginterface.h"

class IA : public IABase
{
public:
    IA();

    // States machines
    SM_Autotest                 m_sm_autotest;
    SM_CarresDeFouille          m_sm_carres_de_fouille;
    SM_DeposerReplique          m_sm_deposer_replique;
    SM_RecupererEchantillon     m_sm_recuperer_echantillon;
    SM_RetourZoneDepart         m_sm_retour_zone_depart;

    void step();
    void init();

    void setStrategie(unsigned char strategie);
    void setMaxScores();
};

#endif // IA_H
