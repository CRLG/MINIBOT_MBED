/**
 * Generated 26_05_2022 at 16_20
 */

#include "sm_carresdefouille.h"
#include "CGlobale.h"

SM_CarresDeFouille::SM_CarresDeFouille()
{
	m_main_mission_type = true;
	m_max_score = 0;
}

const char* SM_CarresDeFouille::getName()
{
	return "SM_CarresDeFouille";
}

const char* SM_CarresDeFouille::stateToName(unsigned short state)
{
	switch(state)
	{
		case STATE_1 :		return "STATE_1";
		case STATE_2 :		return "STATE_2";
		case STATE_3 :		return "STATE_3";
		case STATE_4 :		return "STATE_4";
		case STATE_5 :		return "STATE_5";
		case STATE_6 :		return "STATE_6";
		case STATE_7 :		return "STATE_7";
		case STATE_8 :		return "STATE_8";
		case STATE_9 :		return "STATE_9";
		case STATE_10 :		return "STATE_10";
		case STATE_11 :		return "STATE_11";
		case STATE_12 :		return "STATE_12";
		case STATE_13 :		return "STATE_13";
		case STATE_14 :		return "STATE_14";
		case STATE_15 :		return "STATE_15";
		case FIN_MISSION :	return "FIN_MISSION";
	}
	return "UNKNOWN_STATE";
}

// _____________________________________
void SM_CarresDeFouille::step()
{
	switch (m_state)
	{

	// ___________________________
	case STATE_1 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(44,-52,0);/**/
		}

			gotoStateIfConvergence(STATE_2,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_2 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(107,-61,-1.57);/**/
		}

			gotoStateIfConvergence(STATE_3,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_3 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(110,-133,3.14);/*face 5eme carre*/
		}

			gotoStateIfConvergence(STATE_4,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_4 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(91,-133,3.14);/*4 eme carre*/
		}

			gotoStateIfConvergence(STATE_5,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_5 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(73,-133,3.14);/*3 eme carre*/
		}

			gotoStateIfConvergence(STATE_6,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_6 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(54,-133,3.14);/*face 2eme carre*/
		}

			gotoStateIfConvergence(STATE_7,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_7 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(14,85);/*on teste G*/
		}

			gotoStateAfter(STATE_8,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_8 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(16,170);/*on teste D*/
		}

			gotoStateAfter(STATE_9,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_9 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(14,250);/*on leve G*/
		}

			gotoStateAfter(STATE_10,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_10 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(16,20);/*on leve D*/
		}

			gotoStateAfter(STATE_11,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_11 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(15,1);/*tombe carre G*/
		}

			gotoStateAfter(STATE_12,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_12 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(17,255);/*tombe carre D*/
		}

			gotoStateAfter(STATE_13,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_13 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(15,220);/*range G*/
		}

			gotoStateAfter(STATE_14,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_14 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(17,25);/*range D*/
		}

			gotoStateAfter(STATE_15,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_15 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(39,-133,3.14);/**/
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
