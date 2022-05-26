/**
 * Generated 26_05_2022 at 16_29
 */

#include "sm_retourzonedepart.h"
#include "CGlobale.h"

SM_RetourZoneDepart::SM_RetourZoneDepart()
{
	m_main_mission_type = true;
	m_max_score = 0;
}

const char* SM_RetourZoneDepart::getName()
{
	return "SM_RetourZoneDepart";
}

const char* SM_RetourZoneDepart::stateToName(unsigned short state)
{
	switch(state)
	{
		case 1 :		return "1";
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
void SM_RetourZoneDepart::step()
{
	switch (m_state)
	{

	// ___________________________
	case 1 :
		if (onEntry()) {
			//AUCUNE ACTION
		}

			gotoStateIfConvergence(STATE_1,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_2 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(100,-100,2.3);/**/
		}

			gotoStateIfConvergence(STATE_3,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_3 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(13,-25,2.3);/**/
		}

			gotoStateIfConvergence(STATE_4,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_4 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(0,-62,3.14);/**/
		}

			gotoStateIfConvergence(STATE_5,3000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_5 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(15,1);/*15*/
		}

			gotoStateAfter(STATE_6,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_6 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(17,255);/*17*/
		}

			gotoStateAfter(FIN_MISSION,500);
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
