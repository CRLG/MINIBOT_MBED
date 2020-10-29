/**
 * Generated 25_10_2020 at 11_51
 */

#include "sm_depose3bouees.h"
#include "CGlobale.h"

SM_Depose3bouees::SM_Depose3bouees()
{
	m_main_mission_type = true;
	m_max_score = 0;
}

const char* SM_Depose3bouees::getName()
{
	return "SM_Depose3bouees";
}

const char* SM_Depose3bouees::stateToName(unsigned short state)
{
	switch(state)
	{
		case STATE_1 :		return "STATE_1";
		case STATE_2 :		return "STATE_2";
		case FIN_MISSION :	return "FIN_MISSION";
	}
	return "UNKNOWN_STATE";
}

// _____________________________________
void SM_Depose3bouees::step()
{
	switch (m_state)
	{

	// ___________________________
	case STATE_1 :
		if (onEntry()) {
            Application.m_asservissement.CommandeMouvementXY_TETA(40,0,0);/**/
		}

			gotoStateIfConvergence(STATE_2,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_2 :
		if (onEntry()) {
            Application.m_servos_ax.setPosition(3,500);/*2*/
		}

			gotoStateAfter(FIN_MISSION, 4000);
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
