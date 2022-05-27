/**
 * Generated 27_05_2022 at 06_44
 */

#include "sm_deposerreplique.h"
#include "CGlobale.h"

SM_DeposerReplique::SM_DeposerReplique()
{
	m_main_mission_type = true;
	m_max_score = 0;
}

const char* SM_DeposerReplique::getName()
{
	return "SM_DeposerReplique";
}

const char* SM_DeposerReplique::stateToName(unsigned short state)
{
	switch(state)
	{
		case STATE_1 :		return "STATE_1";
		case COULEUR :		return "COULEUR";
		case COULEUR_J :		return "COULEUR_J";
		case COULEUR_B :		return "COULEUR_B";
		case FIN_COULEUR :		return "FIN_COULEUR";
		case STATE_6 :		return "STATE_6";
		case STATE_7 :		return "STATE_7";
		case STATE_8 :		return "STATE_8";
		case STATE_9 :		return "STATE_9";
		case FIN_MISSION :	return "FIN_MISSION";
	}
	return "UNKNOWN_STATE";
}

// _____________________________________
void SM_DeposerReplique::step()
{
	switch (m_state)
	{

	// ___________________________
	case STATE_1 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(10,-105,-2.3);/*face*/
		}

			gotoStateIfConvergence(COULEUR,5000);
		if (onExit()) {  /*Un seul lien vers un noeud: Ne rien mettre ici  (cf doc Modélia)*/  }
		break;
	// ___________________________
	case COULEUR :
		if (onEntry()) {
			/*Ne rien mettre ici (cf doc Modélia)*/
		}

			gotoStateIfTrue(COULEUR_J,internals()->couleur_equipe==EQUIPE_JAUNE);
			gotoStateIfTrue(COULEUR_B,internals()->couleur_equipe==EQUIPE_BLEU);
		if (onExit()) {  /* Mettre ici le code du onExit de létat STATE_1 car un seul lien avant le noeud (cf doc Modélia)*/  }
		break;
	// ___________________________
	case COULEUR_J :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(2,-114,-2.3);/*proche*/
		}

			gotoStateIfConvergence(FIN_COULEUR,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case COULEUR_B :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(7,119,2.3);/**/
		}

			gotoStateIfConvergence(FIN_COULEUR,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case FIN_COULEUR :
		if (onEntry()) {
			/*Ne rien mettre ici (cf doc Modélia)*/
		}

			gotoStateAfter(STATE_6,200);
		if (onExit()) {  /*Ne rien mettre ici  (cf doc Modélia)*/  }
		break;
	// ___________________________
	case STATE_6 :
		if (onEntry()) {
			Application.m_asservissement.CommandeManuelle(10,16);/*accostage*/
		}

			gotoStateAfter(STATE_7,2000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_7 :
		if (onEntry()) {
			Application.m_asservissement.CommandeManuelle(0,0);/**/
		}

			gotoStateAfter(STATE_8,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_8 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(18,1);/*libere replique*/
		}

			gotoStateAfter(STATE_9,200);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_9 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(10,-100,0);/**/
		}

			gotoStateIfConvergence(FIN_MISSION,5000);
		if (onExit()) {  }
		break;

	// ___________________________
	case FIN_MISSION :
		m_succes = true;
		m_score = m_max_score;
		stop();
		break;
	}
}
