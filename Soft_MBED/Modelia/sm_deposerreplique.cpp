/**
 * Generated 26_05_2022 at 16_10
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
		case STATE_2 :		return "STATE_2";
		case STATE_3 :		return "STATE_3";
		case STATE_4 :		return "STATE_4";
		case STATE_5 :		return "STATE_5";
		case STATE_6 :		return "STATE_6";
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

			gotoStateIfConvergence(STATE_2,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_2 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(2,-114,-2.3);/*proche*/
		}

			gotoStateIfConvergence(STATE_3,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_3 :
		if (onEntry()) {
			Application.m_asservissement.CommandeManuelle(10,13);/*accostage*/
		}

			gotoStateAfter(STATE_4,2000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_4 :
		if (onEntry()) {
			Application.m_asservissement.CommandeManuelle(0,0);/**/
		}

			gotoStateAfter(STATE_5,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_5 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(18,1);/*libere replique*/
		}

			gotoStateAfter(STATE_6,200);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_6 :
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
