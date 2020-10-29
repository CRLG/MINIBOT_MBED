/**
 * Generated 28_10_2020 at 15_40
 */

#include "sm_releverdrapeau.h"
#include "CGlobale.h"

SM_ReleverDrapeau::SM_ReleverDrapeau()
{
	m_main_mission_type = true;
	m_max_score = 0;
}

const char* SM_ReleverDrapeau::getName()
{
	return "SM_ReleverDrapeau";
}

const char* SM_ReleverDrapeau::stateToName(unsigned short state)
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
		case FIN_MISSION :	return "FIN_MISSION";
	}
	return "UNKNOWN_STATE";
}

// _____________________________________
void SM_ReleverDrapeau::step()
{
	switch (m_state)
	{

	// ___________________________
	case STATE_1 :
		if (onEntry()) {
            Application.m_asservissement.setPosition_XYTeta(0.,0.,-1.57);
			Application.m_asservissement.CommandeMouvementXY_TETA(5,-83,-1.57);/*1er drapeau*/
		}

			gotoStateIfConvergence(STATE_2,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_2 :
		if (onEntry()) {
			Application.m_servos_ax.setPosition(2,350);/*semi range*/
            Application.m_asservissement.CommandeManuelle(10,10);
            //Application.m_moteurs.CommandeVitesse(1,10);/*accostage*/
            //Application.m_moteurs.CommandeVitesse(2,10);/*accostage*/
		}

			gotoStateAfter(STATE_3,2000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_3 :
		if (onEntry()) {
			Application.m_servos_ax.setSpeed(2,150);/*2*/
		}

			gotoStateAfter(STATE_4,100);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_4 :
		if (onEntry()) {
			Application.m_servos_ax.setPosition(2,850);/*2*/
		}

			gotoStateAfter(STATE_5,2000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_5 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementDistanceAngle(-10,0);/**/
			Application.m_servos_ax.setPosition(2,350);/*semi range*/
		}

			gotoStateIfConvergence(STATE_6,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_6 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementXY_TETA(46,-83,-1.57);/*2eme drapeau*/
		}

			gotoStateIfConvergence(STATE_7,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_7 :
		if (onEntry()) {
			Application.m_servos_ax.setPosition(2,350);/*2*/
            Application.m_asservissement.CommandeManuelle(10,10);
            //Application.m_moteurs.CommandeVitesse(1,10);/*accostage*/
            //Application.m_moteurs.CommandeVitesse(2,10);/*accostage*/
		}

			gotoStateAfter(STATE_8,200);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_8 :
		if (onEntry()) {
			Application.m_servos_ax.setSpeed(2,150);/*2*/
		}

			gotoStateAfter(STATE_9,100);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_9 :
		if (onEntry()) {
			Application.m_servos_ax.setPosition(2,850);/*2*/
		}

			gotoStateIfConvergence(STATE_10,2000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_10 :
		if (onEntry()) {
			Application.m_asservissement.CommandeMouvementDistanceAngle(-10,0);/**/
			Application.m_servos_ax.setPosition(2,150);/*2*/
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
