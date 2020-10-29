/**
 * Generated 28_10_2020 at 15_51
 */

#include "sm_recup5bouees.h"
#include "CGlobale.h"

SM_Recup5Bouees::SM_Recup5Bouees()
{
	m_main_mission_type = true;
	m_max_score = 0;
}

const char* SM_Recup5Bouees::getName()
{
	return "SM_Recup5Bouees";
}

const char* SM_Recup5Bouees::stateToName(unsigned short state)
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
		case FIN_MISSION :	return "FIN_MISSION";
	}
	return "UNKNOWN_STATE";
}

// _____________________________________
void SM_Recup5Bouees::step()
{
	switch (m_state)
	{

	// ___________________________
	case STATE_1 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(-5,-57,3.14);/*face bouees*/
		}

			gotoStateIfConvergence(STATE_2,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_2 :
		if (onEntry()) {
			Application.m_servos_ax.setPosition(2,0);/*ouverture cames*/
		}

			gotoStateAfter(STATE_3,100);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_3 :
		if (onEntry()) {
			Application.m_servos_ax.setSpeed(1,100);/*tout doux*/
		}

			gotoStateAfter(STATE_4,100);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_4 :
		if (onEntry()) {
			Application.m_servos_ax.setPosition(1,750);/*on descend vers les bouees*/
		}

			gotoStateAfter(STATE_5,1500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_5 :
		if (onEntry()) {
			Application.m_servos_ax.setPosition(2,550);/*serrage toutes bouee*/
		}

			gotoStateAfter(STATE_6,1500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_6 :
		if (onEntry()) {
			Application.m_servos_ax.setPosition(1,300);/*remonte bouees*/
		}

			gotoStateAfter(STATE_7,1500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_7 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementDistanceAngle(-10,3.14);/*on s ecarte*/
		}

			gotoStateIfConvergence(FIN_MISSION,2000);
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
