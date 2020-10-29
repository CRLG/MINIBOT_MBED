/**
 * Generated 28_10_2020 at 15_42
 */

#include "sm_detecternordsud.h"
#include "CGlobale.h"

SM_DetecterNordSud::SM_DetecterNordSud()
{
	m_main_mission_type = true;
	m_max_score = 0;
}

const char* SM_DetecterNordSud::getName()
{
	return "SM_DetecterNordSud";
}

const char* SM_DetecterNordSud::stateToName(unsigned short state)
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
void SM_DetecterNordSud::step()
{
	switch (m_state)
	{

	// ___________________________
	case STATE_1 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(46,-58,1.57);/**/
		}

			gotoStateIfConvergence(STATE_2,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_2 :
		if (onEntry()) {
			
			//reco nordsud

		}

			gotoStateAfter(FIN_MISSION,2000);
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
