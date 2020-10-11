#ifndef _TELEMETRE_H_
#define _TELEMETRE_H_

#include "CTelemetresBase.h"

// Constantes 
// ---------------------------------


// Types
// ---------------------------------

#define NOMBRE_TELEMETRES 2
// -----------------------------
//! Classe de gestion des options d'exécution passees en ligne de commande
class CTelemetres : public CTelemetresBase
{
public :
	CTelemetres();
	~CTelemetres();
	
    // Ré-implémentation des méthodes virtuelles pures de la classe de base
    /*virtual*/ float getDistanceAVG();
    /*virtual*/ float getDistanceAVD();
    /*virtual*/ float getDistanceARG();
    /*virtual*/ float getDistanceARD();

	//! Traitements
	void Traitement(void);


private :
    float m_distance[NOMBRE_TELEMETRES];

    float MoyenneGlissante_float(float currentVal, float *buf_oldSamples, unsigned int samplesNumbers);
    unsigned char Hysterisis (float vin, unsigned char *etat, float swapOff, float swapOn, unsigned char valOff, unsigned char valOn);
};

#endif

// END


