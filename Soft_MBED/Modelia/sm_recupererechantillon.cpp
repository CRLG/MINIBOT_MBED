/**
 * Generated 25_05_2022 at 09_56
 */

#include "sm_recupererechantillon.h"
#include "CGlobale.h"

SM_RecupererEchantillon::SM_RecupererEchantillon()
{
	m_main_mission_type = true;
	m_max_score = 0;
}

const char* SM_RecupererEchantillon::getName()
{
	return "SM_RecupererEchantillon";
}

const char* SM_RecupererEchantillon::stateToName(unsigned short state)
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
		case STATE_16 :		return "STATE_16";
		case FIN_MISSION :	return "FIN_MISSION";
	}
	return "UNKNOWN_STATE";
}

// _____________________________________
void SM_RecupererEchantillon::step()
{
	switch (m_state)
	{

	// ___________________________
	case STATE_1 :
		if (onEntry()) {
			Application.m_asservissement.setPosition_XYTeta(0,0,0);/**/
		}

			gotoStateAfter(STATE_2,50);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_2 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(40,0,0);/*eloigner du depart*/
		}

			gotoStateIfConvergence(STATE_3,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_3 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(40,-79,-2.3);/*face a abri chantier*/
		}

			gotoStateIfConvergence(STATE_4,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_4 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(29,-90,-2.3);/*proche abri chantier*/
		}

			gotoStateIfConvergence(STATE_5,3000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_5 :
		if (onEntry()) {
			Application.m_asservissement.CommandeManuelle(10,13);/*contre abri chantier*/
		}

			gotoStateAfter(STATE_6,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_6 :
		if (onEntry()) {
			Application.m_asservissement.CommandeManuelle(0,0);/**/
		}

			gotoStateAfter(STATE_7,50);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_7 :
		if (onEntry()) {
			Application.m_power_electrobot.setOutput((dsPicPowerElectrobotBase::tSwitchOutput)8,true);/*pompe activee*/
		}

			gotoStateAfter(STATE_8,200);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_8 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(13,105);/*on baisse le kmar*/
		}

			gotoStateAfter(STATE_9,1500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_9 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(40,-79,-2.3);/*on tire echantillon*/
		}

			gotoStateIfConvergence(STATE_10,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_10 :
		if (onEntry()) {
			Application.m_power_electrobot.setOutput((dsPicPowerElectrobotBase::tSwitchOutput)8,false);/*pompe desactivee*/
		}

			gotoStateAfter(STATE_11,50);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_11 :
		if (onEntry()) {
			Application.m_power_electrobot.setOutput((dsPicPowerElectrobotBase::tSwitchOutput)7,true);/*electrovanne activee*/
		}

			gotoStateAfter(STATE_12,50);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_12 :
		if (onEntry()) {
			Application.m_power_electrobot.setOutput((dsPicPowerElectrobotBase::tSwitchOutput)7,false);/*electrovanne desactivee*/
		}

			gotoStateAfter(STATE_13,50);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_13 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(29,-90,-2.3);/*on pousse echantillon sous abri*/
		}

			gotoStateIfConvergence(STATE_14,3000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_14 :
		if (onEntry()) {
			Application.m_asservissement.CommandeManuelle(10,13);/*dernier coup pour etre certain*/
		}

			gotoStateAfter(STATE_15,2000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_15 :
		if (onEntry()) {
			Application.m_asservissement.CommandeManuelle(0,0);/**/
		}

			gotoStateAfter(STATE_16,200);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_16 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(40,-79,-2.3);/*on recule pour admirer le travail*/
		}

			gotoStateIfConvergence(FIN_MISSION,3000);
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
