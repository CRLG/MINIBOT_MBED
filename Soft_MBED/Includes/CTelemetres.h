#ifndef _SRF08_H_
#define _SRF08_H_


// Constantes 
// ---------------------------------
//Loi de commande : (VCC/512)/inch = (5/512)/2.54cm  
#define COEF_TELEMETRE_ULTRASON (3.3 * 259.183)
#define NOMBRE_TELEMETRES       4

// Types
// ---------------------------------

// -----------------------------
//! Classe de gestion des options d'ex�cution passees en ligne de commande
class CTelemetres {
public :
	CTelemetres();
	~CTelemetres();
	
	//! Traitements
	void Traitement(void);
	//! Recupere la derni�re mesure lue sur le capteur en [cm]
	float getDistance_Telemetre(unsigned char numero);

    //! M�morise la derni�re distanc mesur�e 
    float m_distance[NOMBRE_TELEMETRES];

private :


};

#endif

// END

