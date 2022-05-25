/**
 * Generated 25_05_2022 at 10_40
 */

#include "sm_autotest.h"
#include "CGlobale.h"

SM_Autotest::SM_Autotest()
{
	m_main_mission_type = true;
	m_max_score = 0;
}

const char* SM_Autotest::getName()
{
	return "SM_Autotest";
}

const char* SM_Autotest::stateToName(unsigned short state)
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
void SM_Autotest::step()
{
	switch (m_state)
	{

	// ___________________________
	case STATE_1 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(13,225);/*test kmar baisse*/
		}

			gotoStateAfter(STATE_2,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_2 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(13,105);/*test kmar milieu*/
		}

			gotoStateAfter(STATE_3,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_3 :
		if (onEntry()) {
            Application.m_servos_sd20.CommandePosition(13,55);/*test kmar range*/
		}

			gotoStateAfter(STATE_4,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_4 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(16,170);/*testeur D baisse*/
		}

			gotoStateAfter(STATE_5,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_5 :
		if (onEntry()) {
            Application.m_servos_sd20.CommandePosition(16,20);/*testeur D leve*/
		}

			gotoStateAfter(STATE_6,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_6 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(14,85);/*testeur G baisse*/
		}

			gotoStateAfter(STATE_7,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_7 :
		if (onEntry()) {
            Application.m_servos_sd20.CommandePosition(14,250);/*testeur G leve*/
		}

			gotoStateAfter(FIN_MISSION,1000);
		if (onExit()) {  }
		break;

	// ___________________________
	case FIN_MISSION :
        if (onEntry()) {
            //gotoState(STATE_1);  // Autorise la machine d'état à être relancée au début
            stop();
        }
        if (onExit()) {  }
        break;
	}
}
