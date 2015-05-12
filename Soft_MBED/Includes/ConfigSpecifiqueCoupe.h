/*! \file ConfigSpecifiqueCoupe.h
	\brief Déclare
*/
#ifndef _CONFIG_SPECIFIQUE_COUPE 
#define _CONFIG_SPECIFIQUE_COUPE

#include "CMoteurs.h"
#include "CServoMoteurSD20.h"
#include "CServoMoteurAX.h"

// Affectation des sorties moteurs
typedef enum {
   MOTEUR_ROUE_GAUCHE = MOTEUR_1,
   MOTEUR_ROUE_DROITE  // MOTEUR_2
}eATTRIBUTION_MOTEURS;

// Affectation des codeurs de position
typedef enum {
   CODEUR_INCLINAISON  =   CODEUR_1,
   CODEUR_INDEFINI,    // CODEUR_2
   CODEUR_ROUE_DROITE,  // CODEUR_3
   CODEUR_ROUE_GAUCHE   // CODEUR_4

}eATTRIBUTION_CODEURS;

//! cet enumere contient les numeros d'attribution des servos pour 2014
typedef enum {
	SERVO_INCLINAISON=13,
	SERVO_BRAS_D,
	SERVO_BRAS_G,
	SERVO_4,
	SERVO_5
} eATTRIBUTION_SERVOS_SD20;

//! cet enumere contient les numeros d'attribution des servos pour 2014
typedef enum {
	SERVO_xxx=1,
    SERVO_yyy
} eATTRIBUTION_SERVOS_AX;


#endif // _CONFIG_SPECIFIQUE_COUPE

