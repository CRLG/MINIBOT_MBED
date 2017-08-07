
#ifndef IA_H_
#define IA_H_

#include "sc_types.h"
#include "StatemachineInterface.h"

/*! \file Header of the state machine 'IA'.
*/

class IA : public StatemachineInterface
{
	
	public:
		
		IA();
		
		~IA();
		
		/*! Enumeration of all states */ 
		typedef enum
		{
			STRATEGIE_ATTENTE_DEBUT_MATCH,
			STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_1,
			STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_2,
			STRATEGIE_MATCH,
			STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH,
			STRATEGIE_MATCH_MATCH_REGION_EVITEMENT,
			STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT,
			STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT,
			STRATEGIE_MATCH_MATCH_REGION_SORTIE_ZONE_DEPART,
			STRATEGIE_MATCH_MATCH_REGION_SORTIE_ZONE_DEPART_HOMOLOGATION_REGION_DECOLLAGE,
			STRATEGIE_MATCH_MATCH_REGION_SORTIE_ZONE_DEPART_HOMOLOGATION_REGION_Recalage_X,
			STRATEGIE_MATCH_MATCH_REGION_SORTIE_ZONE_DEPART_HOMOLOGATION_REGION_mi_recalage,
			STRATEGIE_MATCH_MATCH_REGION_SORTIE_ZONE_DEPART_HOMOLOGATION_REGION_Recalage_Y_Theta,
			STRATEGIE_MATCH_MATCH_REGION_SORTIE_ZONE_DEPART_HOMOLOGATION_REGION_DEVANT_FUSEE,
			STRATEGIE_MATCH_MATCH_REGION_SORTIE_ZONE_DEPART_HOMOLOGATION_REGION_DEGAGEMENT_BORDURE,
			STRATEGIE_MATCH_MATCH_REGION_SORTIE_ZONE_DEPART_HOMOLOGATION_REGION__final_,
			STRATEGIE_MATCH_MATCH_REGION_SORTIE_ZONE_DEPART_HOMOLOGATION_REGION_RANGEMENT_BRAS,
			STRATEGIE_MATCH_MATCH_REGION_SORTIE_ZONE_DEPART_HOMOLOGATION_REGION_INIT_BARILLET,
			STRATEGIE_MATCH_MATCH_REGION_COLLECTE_FUSEE1,
			STRATEGIE_MATCH_MATCH_REGION_COLLECTE_FUSEE1_HOMOLOGATION_REGION_INIT,
			STRATEGIE_MATCH_MATCH_REGION_COLLECTE_FUSEE1_HOMOLOGATION_REGION_RETRAIT,
			STRATEGIE_MATCH_MATCH_REGION_COLLECTE_FUSEE1_HOMOLOGATION_REGION_MONTEE_MODUL2b,
			STRATEGIE_MATCH_MATCH_REGION_COLLECTE_FUSEE1_HOMOLOGATION_REGION_MODUL_DANS_BARILLET,
			STRATEGIE_MATCH_MATCH_REGION_COLLECTE_FUSEE1_HOMOLOGATION_REGION_ROTATION_BARILLET,
			STRATEGIE_MATCH_MATCH_REGION_COLLECTE_FUSEE1_HOMOLOGATION_REGION_FIN_BARILLET,
			STRATEGIE_MATCH_MATCH_REGION_COLLECTE_FUSEE1_HOMOLOGATION_REGION__final_,
			STRATEGIE_MATCH_MATCH_REGION_COLLECTE_FUSEE1_HOMOLOGATION_REGION_MONTEE_MODUL1,
			STRATEGIE_MATCH_MATCH_REGION_COLLECTE_FUSEE1_HOMOLOGATION_REGION_COUPE_MOELDAR_OUCH_,
			STRATEGIE_MATCH_MATCH_REGION_COLLECTE_FUSEE1_HOMOLOGATION_REGION_PRISE,
			STRATEGIE_MATCH_MATCH_REGION_COLLECTE_FUSEE1_HOMOLOGATION_REGION_MONTEE_MODUL1b,
			STRATEGIE_MATCH_MATCH_REGION_COLLECTE_FUSEE1_HOMOLOGATION_REGION_MONTEE_MODUL2,
			STRATEGIE_MATCH_MATCH_REGION_COLLECTE_FUSEE1_HOMOLOGATION_REGION_PRISEb,
			STRATEGIE_MATCH_MATCH_REGION_COLLECTE_FUSEE1_HOMOLOGATION_REGION_aPRISE,
			STRATEGIE_MATCH_MATCH_REGION__final_,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTEa,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTEa_HOMOLOGATION_REGION_ACCOSTAGE,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTEa_HOMOLOGATION_REGION_POSITION_DEVANT_RAIL,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTEa_HOMOLOGATION_REGION_BRAS_MOELDAR,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTEa_HOMOLOGATION_REGION_RELEVE_MULTICOLOR,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTEa_HOMOLOGATION_REGION__final_,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTEa_HOMOLOGATION_REGION_POSITION_CONTRE_RAIL,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTEa_HOMOLOGATION_REGION_DEPLACEMENT,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTE,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTE_HOMOLOGATION_REGION_POSITION_DEVANT_RAIL,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTE_HOMOLOGATION_REGION_BRAS_MOELDAR,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTE_HOMOLOGATION_REGION__final_,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTE_HOMOLOGATION_REGION_POSITION_CONTRE_RAIL,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTE_HOMOLOGATION_REGION_DEPLACEMENT,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTE_HOMOLOGATION_REGION_Copy_1_ACCOSTAGE,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTE_HOMOLOGATION_REGION_Copy_1_RELEVE_MULTICOLOR,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTE_HOMOLOGATION_REGION_LACHER_MODUL,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTE_HOMOLOGATION_REGION_Copy_1_LACHER_MODUL,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTE_HOMOLOGATION_REGION_Copy_2_LACHER_MODUL,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTE_HOMOLOGATION_REGION_Copy_1_POSITION_DEVANT_RAIL,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_2,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_2_HOMOLOGATION_REGION_ACCOSTAGE,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_2_HOMOLOGATION_REGION_POSITION_DEVANT_RAIL,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_2_HOMOLOGATION_REGION_BRAS_MOELDAR,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_2_HOMOLOGATION_REGION_RELEVE_MULTICOLOR,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_2_HOMOLOGATION_REGION__final_,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_2_HOMOLOGATION_REGION_POSITION_CONTRE_RAIL,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_2_HOMOLOGATION_REGION_DEPOSE_MULTICOLOR,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_2_HOMOLOGATION_REGION_POSITION_DEVANT_RAILb,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_2_HOMOLOGATION_REGION_RECUL_DEVANT_RAIL,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_3,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_3_HOMOLOGATION_REGION_ACCOSTAGE,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_3_HOMOLOGATION_REGION_POSITION_DEVANT_RAIL,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_3_HOMOLOGATION_REGION_BRAS_MOELDAR,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_3_HOMOLOGATION_REGION_RELEVE_MULTICOLOR,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_3_HOMOLOGATION_REGION__final_,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_3_HOMOLOGATION_REGION_POSITION_CONTRE_RAIL,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_3_HOMOLOGATION_REGION_DEPOSE_MULTICOLOR,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_3_HOMOLOGATION_REGION_POSITION_DEVANT_RAILb,
			STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_3_HOMOLOGATION_REGION_RECUL_DEVANT_RAIL,
			STRATEGIE_MATCH_MATCH_REGION_EVITEMENT2,
			STRATEGIE_MATCH_MATCH_REGION_EVITEMENT2_EVITEMENT_REGION_ARRET_ROBOT,
			STRATEGIE_MATCH_MATCH_REGION_EVITEMENT2_EVITEMENT_REGION_SORTIE_EVITEMENT,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_DESCENTE_MODUL,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_ROTATION_BARILLET,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION__final_,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_POSITION_DEVANT_RAIL,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_LACHER_MODUL,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_AVANCE,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_INIT_BARILLET,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_DESCENTE_MODULb,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_DESCENTE_MODULc,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_1_LACHER_MODUL,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_1_REPOSITIONNEMENT,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_2_LACHER_MODUL,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_RECUL,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_CONTRE_BARILLET,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_3_POSITION_CONTRE_RAIL,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_1_DESCENTE_MODUL,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_1_DESCENTE_MODULb,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_1_DESCENTE_MODULc,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_1_ROTATION_BARILLET,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_RECULADE,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_1_CONTRE_BARILLET,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_AVANCE_FINALE,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_INIT,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_DESCENTE_MODUL,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_ROTATION_BARILLET,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_REPOSITIONNEMENT,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION__final_,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_POSITION_DEVANT_RAIL,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_LACHER_MODUL,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_AVANCE,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_INIT_BARILLET,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_DESCENTE_MODULb,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_DESCENTE_MODULc,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_Copy_1_REPOSITIONNEMENT,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_RECUL,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_CONTRE_BARILLET,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_Copy_2_POSITION_CONTRE_RAIL,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_Copy_3_POSITION_CONTRE_RAIL,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_Copy_1_DESCENTE_MODUL,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_Copy_1_DESCENTE_MODULb,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_Copy_1_DESCENTE_MODULc,
			STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_Copy_1_ROTATION_BARILLET,
			STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE,
			STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_DESCENTE_MODUL,
			STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_ROTATION_BARILLET,
			STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_REPOSITIONNEMENT,
			STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION__final_,
			STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_POSITION_DEVANT_RAIL,
			STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_LACHER_MODUL,
			STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_AVANCE,
			STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_INIT_BARILLET,
			STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_DESCENTE_MODULb,
			STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_DESCENTE_MODULc,
			STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_1_LACHER_MODUL,
			STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_2_LACHER_MODUL,
			STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_RECUL,
			STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_CONTRE_BARILLET,
			STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_2_POSITION_CONTRE_RAIL,
			STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_3_POSITION_CONTRE_RAIL,
			STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_1_DESCENTE_MODUL,
			STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_1_DESCENTE_MODULb,
			STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_1_DESCENTE_MODULc,
			STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_1_ROTATION_BARILLET,
			STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_RECULADE,
			STRATEGIE_MATCH_MATCH_REGION_DEPLACEMENT_CENTRE,
			STRATEGIE_MATCH_MATCH_REGION_DEPLACEMENT_CENTRE_HOMOLOGATION_REGION_D_placement,
			STRATEGIE_MATCH_MATCH_REGION_DEPLACEMENT_CENTRE_HOMOLOGATION_REGION__final_,
			STRATEGIE_MATCH_MATCH_REGION_DEPLACEMENT_CENTRE_HOMOLOGATION_REGION_POSITION1,
			STRATEGIE_MATCH_MATCH_REGION_DEPLACEMENT_CENTRE_HOMOLOGATION_REGION_Copy_1_POSITION1,
			STRATEGIE_MATCH_MATCH_REGION_DEPLACEMENT_CENTRE_HOMOLOGATION_REGION_ELOIGNEMENT,
			STRATEGIE_FIN_MATCH,
			STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_ACTIONNEURS,
			STRATEGIE_FIN_MATCH_FIN_MATCH_REGION__final_,
			STRATEGIE_TEMPS_INIT,
			IA_last_state
		} IAStates;
		
		//! Inner class for default interface scope.
		class DefaultSCI
		{
			
			public:
				/*! Raises the in event 'EV_Tirette' that is defined in the default interface scope. */
				void raise_eV_Tirette();
				
				/*! Raises the in event 'EV_Obstacle' that is defined in the default interface scope. */
				void raise_eV_Obstacle();
				
				/*! Raises the in event 'EV_ConvergenceMvt' that is defined in the default interface scope. */
				void raise_eV_ConvergenceMvt();
				
				/*! Raises the in event 'EV_ConvergenceMvt_Rapide' that is defined in the default interface scope. */
				void raise_eV_ConvergenceMvt_Rapide();
				
				/*! Raises the in event 'EV_IsDepression' that is defined in the default interface scope. */
				void raise_eV_IsDepression();
				
				/*! Raises the in event 'EV_IsModuleTaken' that is defined in the default interface scope. */
				void raise_eV_IsModuleTaken();
				
				/*! Gets the value of the variable 'IN_x_pos' that is defined in the default interface scope. */
				sc_real get_iN_x_pos();
				
				/*! Sets the value of the variable 'IN_x_pos' that is defined in the default interface scope. */
				void set_iN_x_pos(sc_real value);
				
				/*! Gets the value of the variable 'IN_y_pos' that is defined in the default interface scope. */
				sc_real get_iN_y_pos();
				
				/*! Sets the value of the variable 'IN_y_pos' that is defined in the default interface scope. */
				void set_iN_y_pos(sc_real value);
				
				/*! Gets the value of the variable 'IN_teta_pos' that is defined in the default interface scope. */
				sc_real get_iN_teta_pos();
				
				/*! Sets the value of the variable 'IN_teta_pos' that is defined in the default interface scope. */
				void set_iN_teta_pos(sc_real value);
				
				/*! Gets the value of the variable 'IN_vitesse' that is defined in the default interface scope. */
				sc_real get_iN_vitesse();
				
				/*! Sets the value of the variable 'IN_vitesse' that is defined in the default interface scope. */
				void set_iN_vitesse(sc_real value);
				
				/*! Gets the value of the variable 'IN_sens_deplacement' that is defined in the default interface scope. */
				sc_real get_iN_sens_deplacement();
				
				/*! Sets the value of the variable 'IN_sens_deplacement' that is defined in the default interface scope. */
				void set_iN_sens_deplacement(sc_real value);
				
				/*! Gets the value of the variable 'IN_Couleur' that is defined in the default interface scope. */
				sc_integer get_iN_Couleur();
				
				/*! Sets the value of the variable 'IN_Couleur' that is defined in the default interface scope. */
				void set_iN_Couleur(sc_integer value);
				
				/*! Gets the value of the variable 'IN_Obstacle' that is defined in the default interface scope. */
				sc_integer get_iN_Obstacle();
				
				/*! Sets the value of the variable 'IN_Obstacle' that is defined in the default interface scope. */
				void set_iN_Obstacle(sc_integer value);
				
				/*! Gets the value of the variable 'IN_Pression' that is defined in the default interface scope. */
				sc_real get_iN_Pression();
				
				/*! Sets the value of the variable 'IN_Pression' that is defined in the default interface scope. */
				void set_iN_Pression(sc_real value);
				
				/*! Gets the value of the variable 'IN_Conv' that is defined in the default interface scope. */
				sc_integer get_iN_Conv();
				
				/*! Sets the value of the variable 'IN_Conv' that is defined in the default interface scope. */
				void set_iN_Conv(sc_integer value);
				
				/*! Gets the value of the variable 'countTimeMvt' that is defined in the default interface scope. */
				sc_real get_countTimeMvt();
				
				/*! Sets the value of the variable 'countTimeMvt' that is defined in the default interface scope. */
				void set_countTimeMvt(sc_real value);
				
				/*! Gets the value of the variable 'tempsMatch' that is defined in the default interface scope. */
				sc_integer get_tempsMatch();
				
				/*! Sets the value of the variable 'tempsMatch' that is defined in the default interface scope. */
				void set_tempsMatch(sc_integer value);
				
				/*! Gets the value of the variable 'countTempo' that is defined in the default interface scope. */
				sc_integer get_countTempo();
				
				/*! Sets the value of the variable 'countTempo' that is defined in the default interface scope. */
				void set_countTempo(sc_integer value);
				
				/*! Gets the value of the variable 'countTempo2' that is defined in the default interface scope. */
				sc_integer get_countTempo2();
				
				/*! Sets the value of the variable 'countTempo2' that is defined in the default interface scope. */
				void set_countTempo2(sc_integer value);
				
				/*! Gets the value of the variable 'countTime' that is defined in the default interface scope. */
				sc_real get_countTime();
				
				/*! Sets the value of the variable 'countTime' that is defined in the default interface scope. */
				void set_countTime(sc_real value);
				
				/*! Gets the value of the variable 'x_pos_mem' that is defined in the default interface scope. */
				sc_real get_x_pos_mem();
				
				/*! Sets the value of the variable 'x_pos_mem' that is defined in the default interface scope. */
				void set_x_pos_mem(sc_real value);
				
				/*! Gets the value of the variable 'y_pos_mem' that is defined in the default interface scope. */
				sc_real get_y_pos_mem();
				
				/*! Sets the value of the variable 'y_pos_mem' that is defined in the default interface scope. */
				void set_y_pos_mem(sc_real value);
				
				/*! Gets the value of the variable 'teta_pos_mem' that is defined in the default interface scope. */
				sc_real get_teta_pos_mem();
				
				/*! Sets the value of the variable 'teta_pos_mem' that is defined in the default interface scope. */
				void set_teta_pos_mem(sc_real value);
				
				/*! Gets the value of the variable 'positionBarillet' that is defined in the default interface scope. */
				sc_integer get_positionBarillet();
				
				/*! Sets the value of the variable 'positionBarillet' that is defined in the default interface scope. */
				void set_positionBarillet(sc_integer value);
				
				/*! Gets the value of the variable 'crantage' that is defined in the default interface scope. */
				sc_integer get_crantage();
				
				/*! Sets the value of the variable 'crantage' that is defined in the default interface scope. */
				void set_crantage(sc_integer value);
				
				/*! Gets the value of the variable 'SERVO_NON_DEFINI1' that is defined in the default interface scope. */
				const sc_integer get_sERVO_NON_DEFINI1();
				
				/*! Gets the value of the variable 'SERVO_NON_DEFINI2' that is defined in the default interface scope. */
				const sc_integer get_sERVO_NON_DEFINI2();
				
				/*! Gets the value of the variable 'BARILLET' that is defined in the default interface scope. */
				const sc_integer get_bARILLET();
				
				/*! Gets the value of the variable 'BASE_BRAS' that is defined in the default interface scope. */
				const sc_integer get_bASE_BRAS();
				
				/*! Gets the value of the variable 'BOUT_BRAS' that is defined in the default interface scope. */
				const sc_integer get_bOUT_BRAS();
				
				/*! Gets the value of the variable 'BASE_BRAS_RENTRE' that is defined in the default interface scope. */
				const sc_integer get_bASE_BRAS_RENTRE();
				
				/*! Gets the value of the variable 'BOUT_BRAS_RENTRE' that is defined in the default interface scope. */
				const sc_integer get_bOUT_BRAS_RENTRE();
				
				/*! Gets the value of the variable 'KMAR_PRENDRE' that is defined in the default interface scope. */
				const sc_integer get_kMAR_PRENDRE();
				
				/*! Gets the value of the variable 'VENTOUSE_G' that is defined in the default interface scope. */
				const sc_integer get_vENTOUSE_G();
				
				/*! Gets the value of the variable 'VENTOUSE_D' that is defined in the default interface scope. */
				const sc_integer get_vENTOUSE_D();
				
				/*! Gets the value of the variable 'KMAR_DROIT' that is defined in the default interface scope. */
				const sc_integer get_kMAR_DROIT();
				
				/*! Gets the value of the variable 'MOTEUR_ROUE_GAUCHE' that is defined in the default interface scope. */
				const sc_integer get_mOTEUR_ROUE_GAUCHE();
				
				/*! Gets the value of the variable 'MOTEUR_ROUE_DROITE' that is defined in the default interface scope. */
				const sc_integer get_mOTEUR_ROUE_DROITE();
				
				/*! Gets the value of the variable 'MOTEUR_NON_DEFINI1' that is defined in the default interface scope. */
				const sc_integer get_mOTEUR_NON_DEFINI1();
				
				/*! Gets the value of the variable 'MOTEUR_NON_DEFINI2' that is defined in the default interface scope. */
				const sc_integer get_mOTEUR_NON_DEFINI2();
				
				/*! Gets the value of the variable 'MOTEUR_ELECTROVANNE' that is defined in the default interface scope. */
				const sc_integer get_mOTEUR_ELECTROVANNE();
				
				/*! Gets the value of the variable 'MOELDAR' that is defined in the default interface scope. */
				const sc_integer get_mOELDAR();
				
				/*! Gets the value of the variable 'CODEUR_NON_DEFINI1' that is defined in the default interface scope. */
				const sc_integer get_cODEUR_NON_DEFINI1();
				
				/*! Gets the value of the variable 'CODEUR_NON_DEFINI2' that is defined in the default interface scope. */
				const sc_integer get_cODEUR_NON_DEFINI2();
				
				/*! Gets the value of the variable 'CODEUR_ROUE_DROITE' that is defined in the default interface scope. */
				const sc_integer get_cODEUR_ROUE_DROITE();
				
				/*! Gets the value of the variable 'CODEUR_ROUE_GAUCHE' that is defined in the default interface scope. */
				const sc_integer get_cODEUR_ROUE_GAUCHE();
				
				/*! Gets the value of the variable 'JAUNE' that is defined in the default interface scope. */
				sc_integer get_jAUNE();
				
				/*! Gets the value of the variable 'BLEU' that is defined in the default interface scope. */
				sc_integer get_bLEU();
				
				
			protected:
				friend class IA;
				sc_boolean EV_Tirette_raised;
				sc_boolean EV_Obstacle_raised;
				sc_boolean EV_ConvergenceMvt_raised;
				sc_boolean EV_ConvergenceMvt_Rapide_raised;
				sc_boolean EV_IsDepression_raised;
				sc_boolean EV_IsModuleTaken_raised;
				sc_real IN_x_pos;
				sc_real IN_y_pos;
				sc_real IN_teta_pos;
				sc_real IN_vitesse;
				sc_real IN_sens_deplacement;
				sc_integer IN_Couleur;
				sc_integer IN_Obstacle;
				sc_real IN_Pression;
				sc_integer IN_Conv;
				sc_real countTimeMvt;
				sc_integer tempsMatch;
				sc_integer countTempo;
				sc_integer countTempo2;
				sc_real countTime;
				sc_real x_pos_mem;
				sc_real y_pos_mem;
				sc_real teta_pos_mem;
				sc_integer positionBarillet;
				sc_integer crantage;
				static const sc_integer SERVO_NON_DEFINI1;
				static const sc_integer SERVO_NON_DEFINI2;
				static const sc_integer BARILLET;
				static const sc_integer BASE_BRAS;
				static const sc_integer BOUT_BRAS;
				static const sc_integer BASE_BRAS_RENTRE;
				static const sc_integer BOUT_BRAS_RENTRE;
				static const sc_integer KMAR_PRENDRE;
				static const sc_integer VENTOUSE_G;
				static const sc_integer VENTOUSE_D;
				static const sc_integer KMAR_DROIT;
				static const sc_integer MOTEUR_ROUE_GAUCHE;
				static const sc_integer MOTEUR_ROUE_DROITE;
				static const sc_integer MOTEUR_NON_DEFINI1;
				static const sc_integer MOTEUR_NON_DEFINI2;
				static const sc_integer MOTEUR_ELECTROVANNE;
				static const sc_integer MOELDAR;
				static const sc_integer CODEUR_NON_DEFINI1;
				static const sc_integer CODEUR_NON_DEFINI2;
				static const sc_integer CODEUR_ROUE_DROITE;
				static const sc_integer CODEUR_ROUE_GAUCHE;
				sc_integer JAUNE;
				sc_integer BLEU;
		};
				
		
		/*! Returns an instance of the interface class 'DefaultSCI'. */
		DefaultSCI* getDefaultSCI();
		
		/*! Raises the in event 'EV_Tirette' that is defined in the default interface scope. */
		void raise_eV_Tirette();
		
		/*! Raises the in event 'EV_Obstacle' that is defined in the default interface scope. */
		void raise_eV_Obstacle();
		
		/*! Raises the in event 'EV_ConvergenceMvt' that is defined in the default interface scope. */
		void raise_eV_ConvergenceMvt();
		
		/*! Raises the in event 'EV_ConvergenceMvt_Rapide' that is defined in the default interface scope. */
		void raise_eV_ConvergenceMvt_Rapide();
		
		/*! Raises the in event 'EV_IsDepression' that is defined in the default interface scope. */
		void raise_eV_IsDepression();
		
		/*! Raises the in event 'EV_IsModuleTaken' that is defined in the default interface scope. */
		void raise_eV_IsModuleTaken();
		
		/*! Gets the value of the variable 'IN_x_pos' that is defined in the default interface scope. */
		sc_real get_iN_x_pos();
		
		/*! Sets the value of the variable 'IN_x_pos' that is defined in the default interface scope. */
		void set_iN_x_pos(sc_real value);
		
		/*! Gets the value of the variable 'IN_y_pos' that is defined in the default interface scope. */
		sc_real get_iN_y_pos();
		
		/*! Sets the value of the variable 'IN_y_pos' that is defined in the default interface scope. */
		void set_iN_y_pos(sc_real value);
		
		/*! Gets the value of the variable 'IN_teta_pos' that is defined in the default interface scope. */
		sc_real get_iN_teta_pos();
		
		/*! Sets the value of the variable 'IN_teta_pos' that is defined in the default interface scope. */
		void set_iN_teta_pos(sc_real value);
		
		/*! Gets the value of the variable 'IN_vitesse' that is defined in the default interface scope. */
		sc_real get_iN_vitesse();
		
		/*! Sets the value of the variable 'IN_vitesse' that is defined in the default interface scope. */
		void set_iN_vitesse(sc_real value);
		
		/*! Gets the value of the variable 'IN_sens_deplacement' that is defined in the default interface scope. */
		sc_real get_iN_sens_deplacement();
		
		/*! Sets the value of the variable 'IN_sens_deplacement' that is defined in the default interface scope. */
		void set_iN_sens_deplacement(sc_real value);
		
		/*! Gets the value of the variable 'IN_Couleur' that is defined in the default interface scope. */
		sc_integer get_iN_Couleur();
		
		/*! Sets the value of the variable 'IN_Couleur' that is defined in the default interface scope. */
		void set_iN_Couleur(sc_integer value);
		
		/*! Gets the value of the variable 'IN_Obstacle' that is defined in the default interface scope. */
		sc_integer get_iN_Obstacle();
		
		/*! Sets the value of the variable 'IN_Obstacle' that is defined in the default interface scope. */
		void set_iN_Obstacle(sc_integer value);
		
		/*! Gets the value of the variable 'IN_Pression' that is defined in the default interface scope. */
		sc_real get_iN_Pression();
		
		/*! Sets the value of the variable 'IN_Pression' that is defined in the default interface scope. */
		void set_iN_Pression(sc_real value);
		
		/*! Gets the value of the variable 'IN_Conv' that is defined in the default interface scope. */
		sc_integer get_iN_Conv();
		
		/*! Sets the value of the variable 'IN_Conv' that is defined in the default interface scope. */
		void set_iN_Conv(sc_integer value);
		
		/*! Gets the value of the variable 'countTimeMvt' that is defined in the default interface scope. */
		sc_real get_countTimeMvt();
		
		/*! Sets the value of the variable 'countTimeMvt' that is defined in the default interface scope. */
		void set_countTimeMvt(sc_real value);
		
		/*! Gets the value of the variable 'tempsMatch' that is defined in the default interface scope. */
		sc_integer get_tempsMatch();
		
		/*! Sets the value of the variable 'tempsMatch' that is defined in the default interface scope. */
		void set_tempsMatch(sc_integer value);
		
		/*! Gets the value of the variable 'countTempo' that is defined in the default interface scope. */
		sc_integer get_countTempo();
		
		/*! Sets the value of the variable 'countTempo' that is defined in the default interface scope. */
		void set_countTempo(sc_integer value);
		
		/*! Gets the value of the variable 'countTempo2' that is defined in the default interface scope. */
		sc_integer get_countTempo2();
		
		/*! Sets the value of the variable 'countTempo2' that is defined in the default interface scope. */
		void set_countTempo2(sc_integer value);
		
		/*! Gets the value of the variable 'countTime' that is defined in the default interface scope. */
		sc_real get_countTime();
		
		/*! Sets the value of the variable 'countTime' that is defined in the default interface scope. */
		void set_countTime(sc_real value);
		
		/*! Gets the value of the variable 'x_pos_mem' that is defined in the default interface scope. */
		sc_real get_x_pos_mem();
		
		/*! Sets the value of the variable 'x_pos_mem' that is defined in the default interface scope. */
		void set_x_pos_mem(sc_real value);
		
		/*! Gets the value of the variable 'y_pos_mem' that is defined in the default interface scope. */
		sc_real get_y_pos_mem();
		
		/*! Sets the value of the variable 'y_pos_mem' that is defined in the default interface scope. */
		void set_y_pos_mem(sc_real value);
		
		/*! Gets the value of the variable 'teta_pos_mem' that is defined in the default interface scope. */
		sc_real get_teta_pos_mem();
		
		/*! Sets the value of the variable 'teta_pos_mem' that is defined in the default interface scope. */
		void set_teta_pos_mem(sc_real value);
		
		/*! Gets the value of the variable 'positionBarillet' that is defined in the default interface scope. */
		sc_integer get_positionBarillet();
		
		/*! Sets the value of the variable 'positionBarillet' that is defined in the default interface scope. */
		void set_positionBarillet(sc_integer value);
		
		/*! Gets the value of the variable 'crantage' that is defined in the default interface scope. */
		sc_integer get_crantage();
		
		/*! Sets the value of the variable 'crantage' that is defined in the default interface scope. */
		void set_crantage(sc_integer value);
		
		/*! Gets the value of the variable 'SERVO_NON_DEFINI1' that is defined in the default interface scope. */
		const sc_integer get_sERVO_NON_DEFINI1();
		
		/*! Gets the value of the variable 'SERVO_NON_DEFINI2' that is defined in the default interface scope. */
		const sc_integer get_sERVO_NON_DEFINI2();
		
		/*! Gets the value of the variable 'BARILLET' that is defined in the default interface scope. */
		const sc_integer get_bARILLET();
		
		/*! Gets the value of the variable 'BASE_BRAS' that is defined in the default interface scope. */
		const sc_integer get_bASE_BRAS();
		
		/*! Gets the value of the variable 'BOUT_BRAS' that is defined in the default interface scope. */
		const sc_integer get_bOUT_BRAS();
		
		/*! Gets the value of the variable 'BASE_BRAS_RENTRE' that is defined in the default interface scope. */
		const sc_integer get_bASE_BRAS_RENTRE();
		
		/*! Gets the value of the variable 'BOUT_BRAS_RENTRE' that is defined in the default interface scope. */
		const sc_integer get_bOUT_BRAS_RENTRE();
		
		/*! Gets the value of the variable 'KMAR_PRENDRE' that is defined in the default interface scope. */
		const sc_integer get_kMAR_PRENDRE();
		
		/*! Gets the value of the variable 'VENTOUSE_G' that is defined in the default interface scope. */
		const sc_integer get_vENTOUSE_G();
		
		/*! Gets the value of the variable 'VENTOUSE_D' that is defined in the default interface scope. */
		const sc_integer get_vENTOUSE_D();
		
		/*! Gets the value of the variable 'KMAR_DROIT' that is defined in the default interface scope. */
		const sc_integer get_kMAR_DROIT();
		
		/*! Gets the value of the variable 'MOTEUR_ROUE_GAUCHE' that is defined in the default interface scope. */
		const sc_integer get_mOTEUR_ROUE_GAUCHE();
		
		/*! Gets the value of the variable 'MOTEUR_ROUE_DROITE' that is defined in the default interface scope. */
		const sc_integer get_mOTEUR_ROUE_DROITE();
		
		/*! Gets the value of the variable 'MOTEUR_NON_DEFINI1' that is defined in the default interface scope. */
		const sc_integer get_mOTEUR_NON_DEFINI1();
		
		/*! Gets the value of the variable 'MOTEUR_NON_DEFINI2' that is defined in the default interface scope. */
		const sc_integer get_mOTEUR_NON_DEFINI2();
		
		/*! Gets the value of the variable 'MOTEUR_ELECTROVANNE' that is defined in the default interface scope. */
		const sc_integer get_mOTEUR_ELECTROVANNE();
		
		/*! Gets the value of the variable 'MOELDAR' that is defined in the default interface scope. */
		const sc_integer get_mOELDAR();
		
		/*! Gets the value of the variable 'CODEUR_NON_DEFINI1' that is defined in the default interface scope. */
		const sc_integer get_cODEUR_NON_DEFINI1();
		
		/*! Gets the value of the variable 'CODEUR_NON_DEFINI2' that is defined in the default interface scope. */
		const sc_integer get_cODEUR_NON_DEFINI2();
		
		/*! Gets the value of the variable 'CODEUR_ROUE_DROITE' that is defined in the default interface scope. */
		const sc_integer get_cODEUR_ROUE_DROITE();
		
		/*! Gets the value of the variable 'CODEUR_ROUE_GAUCHE' that is defined in the default interface scope. */
		const sc_integer get_cODEUR_ROUE_GAUCHE();
		
		/*! Gets the value of the variable 'JAUNE' that is defined in the default interface scope. */
		sc_integer get_jAUNE();
		
		/*! Gets the value of the variable 'BLEU' that is defined in the default interface scope. */
		sc_integer get_bLEU();
		
		
		//! Inner class for asser interface scope.
		class SCI_Asser
		{
			
			public:
				
			protected:
				friend class IA;
		};
				
				//! Inner class for asser interface scope operation callbacks.
				class SCI_Asser_OCB
				{
					public:
						static void XY(sc_real x, sc_real y);
						
						static void XYTeta(sc_real x, sc_real y, sc_real teta);
						
						static void Manuel(sc_real mot_gauche, sc_real mot_droit);
						
						static void DistanceAngle(sc_real distance, sc_real angle);
						
						static void Vitesse(sc_real speedDist, sc_real speedRot);
						
						static void setPosition(sc_real x, sc_real y, sc_real teta);
				};
		
		/*! Returns an instance of the interface class 'SCI_Asser'. */
		SCI_Asser* getSCI_Asser();
		
		//! Inner class for servo interface scope.
		class SCI_Servo
		{
			
			public:
				
			protected:
				friend class IA;
		};
				
				//! Inner class for servo interface scope operation callbacks.
				class SCI_Servo_OCB
				{
					public:
						static void setPos(sc_integer idServo, sc_integer value);
						
						static void setPosSpd(sc_integer idServo, sc_integer pos, sc_integer spd);
						
						static void setRelache(sc_integer idServo, sc_real time_ms);
				};
		
		/*! Returns an instance of the interface class 'SCI_Servo'. */
		SCI_Servo* getSCI_Servo();
		
		//! Inner class for ax interface scope.
		class SCI_Ax
		{
			
			public:
				
			protected:
				friend class IA;
		};
				
				//! Inner class for ax interface scope operation callbacks.
				class SCI_Ax_OCB
				{
					public:
						static void setPos(sc_integer idServo, sc_integer value);
						
						static void setPosSpd(sc_integer idServo, sc_integer pos, sc_integer spd);
						
						static void setRelache(sc_integer idServo);
				};
		
		/*! Returns an instance of the interface class 'SCI_Ax'. */
		SCI_Ax* getSCI_Ax();
		
		//! Inner class for moteur interface scope.
		class SCI_Moteur
		{
			
			public:
				
			protected:
				friend class IA;
		};
				
				//! Inner class for moteur interface scope operation callbacks.
				class SCI_Moteur_OCB
				{
					public:
						static void setPWM(sc_integer idMot, sc_real pwm);
				};
		
		/*! Returns an instance of the interface class 'SCI_Moteur'. */
		SCI_Moteur* getSCI_Moteur();
		
		//! Inner class for capteur interface scope.
		class SCI_Capteur
		{
			
			public:
				
			protected:
				friend class IA;
		};
				
				//! Inner class for capteur interface scope operation callbacks.
				class SCI_Capteur_OCB
				{
					public:
						static void resetCodeur(sc_integer idCodeur, sc_integer value);
				};
		
		/*! Returns an instance of the interface class 'SCI_Capteur'. */
		SCI_Capteur* getSCI_Capteur();
		
		//! Inner class for ihm interface scope.
		class SCI_Ihm
		{
			
			public:
				
			protected:
				friend class IA;
		};
				
				//! Inner class for ihm interface scope operation callbacks.
				class SCI_Ihm_OCB
				{
					public:
						static void setLed(sc_integer idLed, sc_boolean onoff);
				};
		
		/*! Returns an instance of the interface class 'SCI_Ihm'. */
		SCI_Ihm* getSCI_Ihm();
		
		
		void init();
		
		void enter();
		
		void exit();
		
		void runCycle();
		
		/*!
		* Checks if the state machine is active (until 2.4.1 this method was used for states).
		* A state machine is active if it has been entered. It is inactive if it has not been entered at all or if it has been exited.
		*/
		sc_boolean isActive();
		
		
		/*!
		* Checks if all active states are final. 
		* If there are no active states then the state machine is considered being inactive. In this case this method returns false.
		*/
		sc_boolean isFinal();
		
		
		/*! Checks if the specified state is active (until 2.4.1 the used method for states was calles isActive()). */
		sc_boolean isStateActive(IAStates state);
	
	protected:
	
		//! Inner class for internal interface scope.
		class InternalSCI
		{
			
			public:
				/*! Gets the value of the variable 'Couleur' that is defined in the internal scope. */
				sc_integer get_couleur();
				
				/*! Sets the value of the variable 'Couleur' that is defined in the internal scope. */
				void set_couleur(sc_integer value);
				
				/*! Gets the value of the variable 'invMouv' that is defined in the internal scope. */
				sc_integer get_invMouv();
				
				/*! Sets the value of the variable 'invMouv' that is defined in the internal scope. */
				void set_invMouv(sc_integer value);
				
				/*! Gets the value of the variable 'Te' that is defined in the internal scope. */
				sc_real get_te();
				
				/*! Sets the value of the variable 'Te' that is defined in the internal scope. */
				void set_te(sc_real value);
				
				/*! Gets the value of the variable 'PI' that is defined in the internal scope. */
				sc_real get_pI();
				
				/*! Gets the value of the variable 'inhibeObstacle' that is defined in the internal scope. */
				sc_boolean get_inhibeObstacle();
				
				/*! Sets the value of the variable 'inhibeObstacle' that is defined in the internal scope. */
				void set_inhibeObstacle(sc_boolean value);
				
				/*! Gets the value of the variable 'evitementEnCours' that is defined in the internal scope. */
				sc_boolean get_evitementEnCours();
				
				/*! Sets the value of the variable 'evitementEnCours' that is defined in the internal scope. */
				void set_evitementEnCours(sc_boolean value);
				
				/*! Gets the value of the variable 'evitementTempo' that is defined in the internal scope. */
				sc_real get_evitementTempo();
				
				/*! Sets the value of the variable 'evitementTempo' that is defined in the internal scope. */
				void set_evitementTempo(sc_real value);
				
				/*! Gets the value of the variable 'sequence1' that is defined in the internal scope. */
				sc_boolean get_sequence1();
				
				/*! Sets the value of the variable 'sequence1' that is defined in the internal scope. */
				void set_sequence1(sc_boolean value);
				
				/*! Gets the value of the variable 'sequence2' that is defined in the internal scope. */
				sc_boolean get_sequence2();
				
				/*! Sets the value of the variable 'sequence2' that is defined in the internal scope. */
				void set_sequence2(sc_boolean value);
				
				/*! Gets the value of the variable 'sequence3' that is defined in the internal scope. */
				sc_boolean get_sequence3();
				
				/*! Sets the value of the variable 'sequence3' that is defined in the internal scope. */
				void set_sequence3(sc_boolean value);
				
				/*! Gets the value of the variable 'sequence11' that is defined in the internal scope. */
				sc_boolean get_sequence11();
				
				/*! Sets the value of the variable 'sequence11' that is defined in the internal scope. */
				void set_sequence11(sc_boolean value);
				
				/*! Gets the value of the variable 'sequence12' that is defined in the internal scope. */
				sc_boolean get_sequence12();
				
				/*! Sets the value of the variable 'sequence12' that is defined in the internal scope. */
				void set_sequence12(sc_boolean value);
				
				/*! Gets the value of the variable 'sequence13' that is defined in the internal scope. */
				sc_boolean get_sequence13();
				
				/*! Sets the value of the variable 'sequence13' that is defined in the internal scope. */
				void set_sequence13(sc_boolean value);
				
				/*! Gets the value of the variable 'sequence14' that is defined in the internal scope. */
				sc_boolean get_sequence14();
				
				/*! Sets the value of the variable 'sequence14' that is defined in the internal scope. */
				void set_sequence14(sc_boolean value);
				
				/*! Gets the value of the variable 'sequence21' that is defined in the internal scope. */
				sc_boolean get_sequence21();
				
				/*! Sets the value of the variable 'sequence21' that is defined in the internal scope. */
				void set_sequence21(sc_boolean value);
				
				/*! Gets the value of the variable 'sequence22' that is defined in the internal scope. */
				sc_boolean get_sequence22();
				
				/*! Sets the value of the variable 'sequence22' that is defined in the internal scope. */
				void set_sequence22(sc_boolean value);
				
				
			protected:
				friend class IA;
				sc_integer Couleur;
				sc_integer invMouv;
				sc_real Te;
				sc_real PI;
				sc_boolean inhibeObstacle;
				sc_boolean evitementEnCours;
				sc_real evitementTempo;
				sc_boolean sequence1;
				sc_boolean sequence2;
				sc_boolean sequence3;
				sc_boolean sequence11;
				sc_boolean sequence12;
				sc_boolean sequence13;
				sc_boolean sequence14;
				sc_boolean sequence21;
				sc_boolean sequence22;
		};
	
		//! the maximum number of orthogonal states defines the dimension of the state configuration vector.
		static const sc_integer maxOrthogonalStates = 1;
		//! dimension of the state configuration vector for history states
		static const sc_integer maxHistoryStates = 9;
		
		
		IAStates stateConfVector[maxOrthogonalStates];
		
		IAStates historyVector[maxHistoryStates];
		sc_ushort stateConfVectorPosition;
		
		DefaultSCI iface;
		InternalSCI ifaceInternalSCI;
		SCI_Asser ifaceAsser;
		SCI_Servo ifaceServo;
		SCI_Ax ifaceAx;
		SCI_Moteur ifaceMoteur;
		SCI_Capteur ifaceCapteur;
		SCI_Ihm ifaceIhm;
		
		// prototypes of all internal functions
		
		void shenseq_STRATEGIE_MATCH_MATCH_REGION_SORTIE_ZONE_DEPART_HOMOLOGATION_REGION();
		void shenseq_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTEa_HOMOLOGATION_REGION();
		void shenseq_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTE_HOMOLOGATION_REGION();
		void shenseq_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_2_HOMOLOGATION_REGION();
		void shenseq_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_3_HOMOLOGATION_REGION();
		void shenseq_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION();
		void shenseq_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION();
		void shenseq_STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION();
		void shenseq_STRATEGIE_MATCH_MATCH_REGION_DEPLACEMENT_CENTRE_HOMOLOGATION_REGION();
		void react_STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_1();
		void react_STRATEGIE_ATTENTE_DEBUT_MATCH_CHOIX_EQUIPE_EQUIPE_2();
		void react_STRATEGIE_MATCH_MATCH_REGION_INIT_MATCH();
		void react_STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_ARRET_ROBOT();
		void react_STRATEGIE_MATCH_MATCH_REGION_EVITEMENT_EVITEMENT_REGION_SORTIE_EVITEMENT();
		void react_STRATEGIE_MATCH_MATCH_REGION_SORTIE_ZONE_DEPART_HOMOLOGATION_REGION_DECOLLAGE();
		void react_STRATEGIE_MATCH_MATCH_REGION_SORTIE_ZONE_DEPART_HOMOLOGATION_REGION_Recalage_X();
		void react_STRATEGIE_MATCH_MATCH_REGION_SORTIE_ZONE_DEPART_HOMOLOGATION_REGION_mi_recalage();
		void react_STRATEGIE_MATCH_MATCH_REGION_SORTIE_ZONE_DEPART_HOMOLOGATION_REGION_Recalage_Y_Theta();
		void react_STRATEGIE_MATCH_MATCH_REGION_SORTIE_ZONE_DEPART_HOMOLOGATION_REGION_DEVANT_FUSEE();
		void react_STRATEGIE_MATCH_MATCH_REGION_SORTIE_ZONE_DEPART_HOMOLOGATION_REGION_DEGAGEMENT_BORDURE();
		void react_STRATEGIE_MATCH_MATCH_REGION_SORTIE_ZONE_DEPART_HOMOLOGATION_REGION__final_();
		void react_STRATEGIE_MATCH_MATCH_REGION_SORTIE_ZONE_DEPART_HOMOLOGATION_REGION_RANGEMENT_BRAS();
		void react_STRATEGIE_MATCH_MATCH_REGION_SORTIE_ZONE_DEPART_HOMOLOGATION_REGION_INIT_BARILLET();
		void react_STRATEGIE_MATCH_MATCH_REGION_COLLECTE_FUSEE1_HOMOLOGATION_REGION_INIT();
		void react_STRATEGIE_MATCH_MATCH_REGION_COLLECTE_FUSEE1_HOMOLOGATION_REGION_RETRAIT();
		void react_STRATEGIE_MATCH_MATCH_REGION_COLLECTE_FUSEE1_HOMOLOGATION_REGION_MONTEE_MODUL2b();
		void react_STRATEGIE_MATCH_MATCH_REGION_COLLECTE_FUSEE1_HOMOLOGATION_REGION_MODUL_DANS_BARILLET();
		void react_STRATEGIE_MATCH_MATCH_REGION_COLLECTE_FUSEE1_HOMOLOGATION_REGION_ROTATION_BARILLET();
		void react_STRATEGIE_MATCH_MATCH_REGION_COLLECTE_FUSEE1_HOMOLOGATION_REGION_FIN_BARILLET();
		void react_STRATEGIE_MATCH_MATCH_REGION_COLLECTE_FUSEE1_HOMOLOGATION_REGION__final_();
		void react_STRATEGIE_MATCH_MATCH_REGION_COLLECTE_FUSEE1_HOMOLOGATION_REGION_MONTEE_MODUL1();
		void react_STRATEGIE_MATCH_MATCH_REGION_COLLECTE_FUSEE1_HOMOLOGATION_REGION_COUPE_MOELDAR_OUCH_();
		void react_STRATEGIE_MATCH_MATCH_REGION_COLLECTE_FUSEE1_HOMOLOGATION_REGION_PRISE();
		void react_STRATEGIE_MATCH_MATCH_REGION_COLLECTE_FUSEE1_HOMOLOGATION_REGION_MONTEE_MODUL1b();
		void react_STRATEGIE_MATCH_MATCH_REGION_COLLECTE_FUSEE1_HOMOLOGATION_REGION_MONTEE_MODUL2();
		void react_STRATEGIE_MATCH_MATCH_REGION_COLLECTE_FUSEE1_HOMOLOGATION_REGION_PRISEb();
		void react_STRATEGIE_MATCH_MATCH_REGION_COLLECTE_FUSEE1_HOMOLOGATION_REGION_aPRISE();
		void react_STRATEGIE_MATCH_MATCH_REGION__final_();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTEa_HOMOLOGATION_REGION_ACCOSTAGE();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTEa_HOMOLOGATION_REGION_POSITION_DEVANT_RAIL();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTEa_HOMOLOGATION_REGION_BRAS_MOELDAR();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTEa_HOMOLOGATION_REGION_RELEVE_MULTICOLOR();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTEa_HOMOLOGATION_REGION__final_();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTEa_HOMOLOGATION_REGION_POSITION_CONTRE_RAIL();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTEa_HOMOLOGATION_REGION_DEPLACEMENT();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTE_HOMOLOGATION_REGION_POSITION_DEVANT_RAIL();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTE_HOMOLOGATION_REGION_BRAS_MOELDAR();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTE_HOMOLOGATION_REGION__final_();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTE_HOMOLOGATION_REGION_POSITION_CONTRE_RAIL();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTE_HOMOLOGATION_REGION_DEPLACEMENT();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTE_HOMOLOGATION_REGION_Copy_1_ACCOSTAGE();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTE_HOMOLOGATION_REGION_Copy_1_RELEVE_MULTICOLOR();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTE_HOMOLOGATION_REGION_LACHER_MODUL();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTE_HOMOLOGATION_REGION_Copy_1_LACHER_MODUL();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTE_HOMOLOGATION_REGION_Copy_2_LACHER_MODUL();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_COTE_HOMOLOGATION_REGION_Copy_1_POSITION_DEVANT_RAIL();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_2_HOMOLOGATION_REGION_ACCOSTAGE();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_2_HOMOLOGATION_REGION_POSITION_DEVANT_RAIL();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_2_HOMOLOGATION_REGION_BRAS_MOELDAR();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_2_HOMOLOGATION_REGION_RELEVE_MULTICOLOR();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_2_HOMOLOGATION_REGION__final_();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_2_HOMOLOGATION_REGION_POSITION_CONTRE_RAIL();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_2_HOMOLOGATION_REGION_DEPOSE_MULTICOLOR();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_2_HOMOLOGATION_REGION_POSITION_DEVANT_RAILb();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_2_HOMOLOGATION_REGION_RECUL_DEVANT_RAIL();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_3_HOMOLOGATION_REGION_ACCOSTAGE();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_3_HOMOLOGATION_REGION_POSITION_DEVANT_RAIL();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_3_HOMOLOGATION_REGION_BRAS_MOELDAR();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_3_HOMOLOGATION_REGION_RELEVE_MULTICOLOR();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_3_HOMOLOGATION_REGION__final_();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_3_HOMOLOGATION_REGION_POSITION_CONTRE_RAIL();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_3_HOMOLOGATION_REGION_DEPOSE_MULTICOLOR();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_3_HOMOLOGATION_REGION_POSITION_DEVANT_RAILb();
		void react_STRATEGIE_MATCH_MATCH_REGION_MULTICOLOR_3_HOMOLOGATION_REGION_RECUL_DEVANT_RAIL();
		void react_STRATEGIE_MATCH_MATCH_REGION_EVITEMENT2_EVITEMENT_REGION_ARRET_ROBOT();
		void react_STRATEGIE_MATCH_MATCH_REGION_EVITEMENT2_EVITEMENT_REGION_SORTIE_EVITEMENT();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_DESCENTE_MODUL();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_ROTATION_BARILLET();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION__final_();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_POSITION_DEVANT_RAIL();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_LACHER_MODUL();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_AVANCE();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_INIT_BARILLET();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_DESCENTE_MODULb();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_DESCENTE_MODULc();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_1_LACHER_MODUL();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_1_REPOSITIONNEMENT();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_2_LACHER_MODUL();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_RECUL();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_CONTRE_BARILLET();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_3_POSITION_CONTRE_RAIL();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_1_DESCENTE_MODUL();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_1_DESCENTE_MODULb();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_1_DESCENTE_MODULc();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_1_ROTATION_BARILLET();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_RECULADE();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_1_CONTRE_BARILLET();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_AVANCE_FINALE();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_INIT();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_DESCENTE_MODUL();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_ROTATION_BARILLET();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_REPOSITIONNEMENT();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION__final_();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_POSITION_DEVANT_RAIL();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_LACHER_MODUL();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_AVANCE();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_INIT_BARILLET();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_DESCENTE_MODULb();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_DESCENTE_MODULc();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_Copy_1_REPOSITIONNEMENT();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_RECUL();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_CONTRE_BARILLET();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_Copy_2_POSITION_CONTRE_RAIL();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_Copy_3_POSITION_CONTRE_RAIL();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_Copy_1_DESCENTE_MODUL();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_Copy_1_DESCENTE_MODULb();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_Copy_1_DESCENTE_MODULc();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_DEPART_HOMOLOGATION_REGION_Copy_1_ROTATION_BARILLET();
		void react_STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_DESCENTE_MODUL();
		void react_STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_ROTATION_BARILLET();
		void react_STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_REPOSITIONNEMENT();
		void react_STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION__final_();
		void react_STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_POSITION_DEVANT_RAIL();
		void react_STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_LACHER_MODUL();
		void react_STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_AVANCE();
		void react_STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_INIT_BARILLET();
		void react_STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_DESCENTE_MODULb();
		void react_STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_DESCENTE_MODULc();
		void react_STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_1_LACHER_MODUL();
		void react_STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_2_LACHER_MODUL();
		void react_STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_RECUL();
		void react_STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_CONTRE_BARILLET();
		void react_STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_2_POSITION_CONTRE_RAIL();
		void react_STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_3_POSITION_CONTRE_RAIL();
		void react_STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_1_DESCENTE_MODUL();
		void react_STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_1_DESCENTE_MODULb();
		void react_STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_1_DESCENTE_MODULc();
		void react_STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_Copy_1_ROTATION_BARILLET();
		void react_STRATEGIE_MATCH_MATCH_REGION_Copy_1_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION_RECULADE();
		void react_STRATEGIE_MATCH_MATCH_REGION_DEPLACEMENT_CENTRE_HOMOLOGATION_REGION_D_placement();
		void react_STRATEGIE_MATCH_MATCH_REGION_DEPLACEMENT_CENTRE_HOMOLOGATION_REGION__final_();
		void react_STRATEGIE_MATCH_MATCH_REGION_DEPLACEMENT_CENTRE_HOMOLOGATION_REGION_POSITION1();
		void react_STRATEGIE_MATCH_MATCH_REGION_DEPLACEMENT_CENTRE_HOMOLOGATION_REGION_Copy_1_POSITION1();
		void react_STRATEGIE_MATCH_MATCH_REGION_DEPLACEMENT_CENTRE_HOMOLOGATION_REGION_ELOIGNEMENT();
		void react_STRATEGIE_FIN_MATCH_FIN_MATCH_REGION_ARRET_ACTIONNEURS();
		void react_STRATEGIE_FIN_MATCH_FIN_MATCH_REGION__final_();
		void react_STRATEGIE_TEMPS_INIT();
		void react_STRATEGIE_MATCH_MATCH_REGION_COLLECTE_FUSEE1_HOMOLOGATION_REGION__choice_0();
		void react_STRATEGIE_MATCH_MATCH_REGION__choice_0();
		void react_STRATEGIE_MATCH_MATCH_REGION__choice_1();
		void react_STRATEGIE_MATCH_MATCH_REGION_DECHARGEMENT_CENTRE_HOMOLOGATION_REGION__choice_0();
		void clearInEvents();
		void clearOutEvents();
		
};
#endif /* IA_H_ */
