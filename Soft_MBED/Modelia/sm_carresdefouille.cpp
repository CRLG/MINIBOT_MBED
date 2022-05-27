/**
 * Generated 27_05_2022 at 06_36
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
		case NODE_CARRE_05 :		return "NODE_CARRE_05";
		case BLEU_CARRE_05 :		return "BLEU_CARRE_05";
		case STATE_9 :		return "STATE_9";
		case STATE_10 :		return "STATE_10";
		case STATE_11 :		return "STATE_11";
		case JAUNE_CARRE_05 :		return "JAUNE_CARRE_05";
		case STATE_13 :		return "STATE_13";
		case STATE_14 :		return "STATE_14";
		case STATE_15 :		return "STATE_15";
		case RIEN_CARRE_05 :		return "RIEN_CARRE_05";
		case STATE_17 :		return "STATE_17";
		case FIN_NODE_CARRE_05 :		return "FIN_NODE_CARRE_05";
		case STATE_19 :		return "STATE_19";
		case STATE_20 :		return "STATE_20";
		case STATE_21 :		return "STATE_21";
		case NODE_CARRE_04 :		return "NODE_CARRE_04";
		case BLEU_CARRE_04 :		return "BLEU_CARRE_04";
		case STATE_24 :		return "STATE_24";
		case STATE_25 :		return "STATE_25";
		case STATE_26 :		return "STATE_26";
		case JAUNE_CARRE_04 :		return "JAUNE_CARRE_04";
		case STATE_28 :		return "STATE_28";
		case STATE_29 :		return "STATE_29";
		case STATE_30 :		return "STATE_30";
		case RIEN_CARRE_04 :		return "RIEN_CARRE_04";
		case STATE_32 :		return "STATE_32";
		case FIN_NODE_CARRE_04 :		return "FIN_NODE_CARRE_04";
		case STATE_34 :		return "STATE_34";
		case STATE_35 :		return "STATE_35";
		case STATE_36 :		return "STATE_36";
		case NODE_CARRE_03 :		return "NODE_CARRE_03";
		case BLEU_CARRE_03 :		return "BLEU_CARRE_03";
		case STATE_39 :		return "STATE_39";
		case STATE_40 :		return "STATE_40";
		case STATE_41 :		return "STATE_41";
		case JAUNE_CARRE_03 :		return "JAUNE_CARRE_03";
		case STATE_43 :		return "STATE_43";
		case STATE_44 :		return "STATE_44";
		case STATE_45 :		return "STATE_45";
		case RIEN_CARRE_03 :		return "RIEN_CARRE_03";
		case STATE_47 :		return "STATE_47";
		case FIN_NODE_CARRE_03 :		return "FIN_NODE_CARRE_03";
		case STATE_49 :		return "STATE_49";
		case NODE_CARRE_02 :		return "NODE_CARRE_02";
		case BLEU_CARRE_02 :		return "BLEU_CARRE_02";
		case STATE_52 :		return "STATE_52";
		case JAUNE_CARRE_02 :		return "JAUNE_CARRE_02";
		case STATE_54 :		return "STATE_54";
		case FIN_NODE_CARRE_02 :		return "FIN_NODE_CARRE_02";
		case STATE_56 :		return "STATE_56";
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
			Application.m_asservissement.CommandeMouvementXY_TETA(135,-129,3.14);/**/
		}

			gotoStateIfConvergence(STATE_4,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_4 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(110,-134,3.14);/*face 5eme carre*/
		}

			gotoStateIfConvergence(STATE_5,4000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_5 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(14,85);/*on teste G*/
		}

			gotoStateAfter(STATE_6,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_6 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(16,170);/*on teste D*/
		}

			gotoStateAfter(NODE_CARRE_05,500);
		if (onExit()) {  /*Un seul lien vers un noeud: Ne rien mettre ici  (cf doc Modélia)*/  }
		break;
	// ___________________________
	case NODE_CARRE_05 :
		if (onEntry()) {
			/*Ne rien mettre ici (cf doc Modélia)*/
		}

			gotoStateIfTrue(BLEU_CARRE_05,(Application.m_electrobot.m_b_Eana5<0.3f)&&(internals()->couleur_equipe==EQUIPE_BLEU));
			gotoStateIfTrue(JAUNE_CARRE_05,(Application.m_electrobot.m_b_Eana5>=0.3f)&&(Application.m_electrobot.m_b_Eana5<1.0f)&&(internals()->couleur_equipe==EQUIPE_JAUNE));
			gotoStateIfTrue(RIEN_CARRE_05,((Application.m_electrobot.m_b_Eana5<0.3f)&&(internals()->couleur_equipe==EQUIPE_JAUNE)) ||((Application.m_electrobot.m_b_Eana5>=0.3f)&&(internals()->couleur_equipe==EQUIPE_BLEU))||(Application.m_electrobot.m_b_Eana5>=1.0f));
		if (onExit()) {  /* Mettre ici le code du onExit de létat STATE_6 car un seul lien avant le noeud (cf doc Modélia)*/  }
		break;
	// ___________________________
	case BLEU_CARRE_05 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(14,250);/*on leve G*/
		}

			gotoStateAfter(STATE_9,200);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_9 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(16,20);/*on leve D*/
		}

			gotoStateAfter(STATE_10,200);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_10 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(17,255);/*tombe carre D*/
		}

			gotoStateAfter(STATE_11,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_11 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(17,25);/*range D*/
		}

			gotoStateAfter(FIN_NODE_CARRE_05,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case JAUNE_CARRE_05 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(14,250);/*on leve G*/
		}

			gotoStateAfter(STATE_13,200);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_13 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(16,20);/*on leve D*/
		}

			gotoStateAfter(STATE_14,200);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_14 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(15,1);/*tombe carre G*/
		}

			gotoStateAfter(STATE_15,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_15 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(15,220);/*range G*/
		}

			gotoStateAfter(FIN_NODE_CARRE_05,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case RIEN_CARRE_05 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(14,250);/*on leve G*/
		}

			gotoStateAfter(STATE_17,200);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_17 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(16,20);/*on leve D*/
		}

			gotoStateAfter(FIN_NODE_CARRE_05,200);
		if (onExit()) {  }
		break;
	// ___________________________
	case FIN_NODE_CARRE_05 :
		if (onEntry()) {
			/*Ne rien mettre ici (cf doc Modélia)*/
		}

			gotoStateAfter(STATE_19,200);
		if (onExit()) {  /*Ne rien mettre ici  (cf doc Modélia)*/  }
		break;
	// ___________________________
	case STATE_19 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(91,-134,3.14);/*4 eme carre*/
		}

			gotoStateIfConvergence(STATE_20,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_20 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(14,85);/*on teste G*/
		}

			gotoStateAfter(STATE_21,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_21 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(16,170);/*on teste D*/
		}

			gotoStateAfter(NODE_CARRE_04,500);
		if (onExit()) {  /*Un seul lien vers un noeud: Ne rien mettre ici  (cf doc Modélia)*/  }
		break;
	// ___________________________
	case NODE_CARRE_04 :
		if (onEntry()) {
			/*Ne rien mettre ici (cf doc Modélia)*/
		}

			gotoStateIfTrue(BLEU_CARRE_04,(Application.m_electrobot.m_b_Eana5<0.3f)&&(internals()->couleur_equipe==EQUIPE_BLEU));
			gotoStateIfTrue(JAUNE_CARRE_04,(Application.m_electrobot.m_b_Eana5>=0.3f)&&(Application.m_electrobot.m_b_Eana5<1.0f)&&(internals()->couleur_equipe==EQUIPE_JAUNE));
			gotoStateIfTrue(RIEN_CARRE_04,((Application.m_electrobot.m_b_Eana5<0.3f)&&(internals()->couleur_equipe==EQUIPE_JAUNE)) ||((Application.m_electrobot.m_b_Eana5>=0.3f)&&(internals()->couleur_equipe==EQUIPE_BLEU))||(Application.m_electrobot.m_b_Eana5>=1.0f));
		if (onExit()) {  /* Mettre ici le code du onExit de létat STATE_21 car un seul lien avant le noeud (cf doc Modélia)*/  }
		break;
	// ___________________________
	case BLEU_CARRE_04 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(14,250);/*on leve G*/
		}

			gotoStateAfter(STATE_24,200);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_24 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(16,20);/*on leve D*/
		}

			gotoStateAfter(STATE_25,200);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_25 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(17,255);/*tombe carre D*/
		}

			gotoStateAfter(STATE_26,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_26 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(17,25);/*range D*/
		}

			gotoStateAfter(FIN_NODE_CARRE_04,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case JAUNE_CARRE_04 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(14,250);/*on leve G*/
		}

			gotoStateAfter(STATE_28,200);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_28 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(16,20);/*on leve D*/
		}

			gotoStateAfter(STATE_29,200);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_29 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(15,1);/*tombe carre G*/
		}

			gotoStateAfter(STATE_30,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_30 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(15,220);/*range G*/
		}

			gotoStateAfter(FIN_NODE_CARRE_04,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case RIEN_CARRE_04 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(14,250);/*on leve G*/
		}

			gotoStateAfter(STATE_32,200);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_32 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(16,20);/*on leve D*/
		}

			gotoStateAfter(FIN_NODE_CARRE_04,200);
		if (onExit()) {  }
		break;
	// ___________________________
	case FIN_NODE_CARRE_04 :
		if (onEntry()) {
			/*Ne rien mettre ici (cf doc Modélia)*/
		}

			gotoStateAfter(STATE_34,200);
		if (onExit()) {  /*Ne rien mettre ici  (cf doc Modélia)*/  }
		break;
	// ___________________________
	case STATE_34 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(73,-134,3.14);/*3 eme carre*/
		}

			gotoStateIfConvergence(STATE_35,5000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_35 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(14,85);/*on teste G*/
		}

			gotoStateAfter(STATE_36,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_36 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(16,170);/*on teste D*/
		}

			gotoStateAfter(NODE_CARRE_03,500);
		if (onExit()) {  /*Un seul lien vers un noeud: Ne rien mettre ici  (cf doc Modélia)*/  }
		break;
	// ___________________________
	case NODE_CARRE_03 :
		if (onEntry()) {
			/*Ne rien mettre ici (cf doc Modélia)*/
		}

			gotoStateIfTrue(BLEU_CARRE_03,(Application.m_electrobot.m_b_Eana5<0.3f)&&(internals()->couleur_equipe==EQUIPE_BLEU));
			gotoStateIfTrue(JAUNE_CARRE_03,(Application.m_electrobot.m_b_Eana5>=0.3f)&&(Application.m_electrobot.m_b_Eana5<1.0f)&&(internals()->couleur_equipe==EQUIPE_JAUNE));
			gotoStateIfTrue(RIEN_CARRE_03,((Application.m_electrobot.m_b_Eana5<0.3f)&&(internals()->couleur_equipe==EQUIPE_JAUNE)) ||((Application.m_electrobot.m_b_Eana5>=0.3f)&&(internals()->couleur_equipe==EQUIPE_BLEU))||(Application.m_electrobot.m_b_Eana5>=1.0f));
		if (onExit()) {  /* Mettre ici le code du onExit de létat STATE_36 car un seul lien avant le noeud (cf doc Modélia)*/  }
		break;
	// ___________________________
	case BLEU_CARRE_03 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(14,250);/*on leve G*/
		}

			gotoStateAfter(STATE_39,200);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_39 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(16,20);/*on leve D*/
		}

			gotoStateAfter(STATE_40,200);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_40 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(17,255);/*tombe carre D*/
		}

			gotoStateAfter(STATE_41,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_41 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(17,25);/*range D*/
		}

			gotoStateAfter(FIN_NODE_CARRE_03,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case JAUNE_CARRE_03 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(14,250);/*on leve G*/
		}

			gotoStateAfter(STATE_43,200);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_43 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(16,20);/*on leve D*/
		}

			gotoStateAfter(STATE_44,200);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_44 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(15,1);/*tombe carre G*/
		}

			gotoStateAfter(STATE_45,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_45 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(15,220);/*range G*/
		}

			gotoStateAfter(FIN_NODE_CARRE_03,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case RIEN_CARRE_03 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(14,250);/*on leve G*/
		}

			gotoStateAfter(STATE_47,200);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_47 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(16,20);/*on leve D*/
		}

			gotoStateAfter(FIN_NODE_CARRE_03,200);
		if (onExit()) {  }
		break;
	// ___________________________
	case FIN_NODE_CARRE_03 :
		if (onEntry()) {
			/*Ne rien mettre ici (cf doc Modélia)*/
		}

			gotoStateAfter(STATE_49,200);
		if (onExit()) {  /*Ne rien mettre ici  (cf doc Modélia)*/  }
		break;
	// ___________________________
	case STATE_49 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(55,-134,3.14);/*face 2eme carre*/
		}

			gotoStateIfConvergence(NODE_CARRE_02,5000);
		if (onExit()) {  /*Un seul lien vers un noeud: Ne rien mettre ici  (cf doc Modélia)*/  }
		break;
	// ___________________________
	case NODE_CARRE_02 :
		if (onEntry()) {
			/*Ne rien mettre ici (cf doc Modélia)*/
		}

			gotoStateIfTrue(BLEU_CARRE_02,(internals()->couleur_equipe==EQUIPE_BLEU));
			gotoStateIfTrue(JAUNE_CARRE_02,(internals()->couleur_equipe==EQUIPE_JAUNE));
		if (onExit()) {  /* Mettre ici le code du onExit de létat STATE_49 car un seul lien avant le noeud (cf doc Modélia)*/  }
		break;
	// ___________________________
	case BLEU_CARRE_02 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(17,255);/*tombe carre D*/
		}

			gotoStateAfter(STATE_52,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_52 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(17,25);/*range D*/
		}

			gotoStateAfter(FIN_NODE_CARRE_02,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case JAUNE_CARRE_02 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(15,1);/*tombe carre G*/
		}

			gotoStateAfter(STATE_54,1000);
		if (onExit()) {  }
		break;
	// ___________________________
	case STATE_54 :
		if (onEntry()) {
			Application.m_servos_sd20.CommandePosition(15,220);/*range G*/
		}

			gotoStateAfter(FIN_NODE_CARRE_02,500);
		if (onExit()) {  }
		break;
	// ___________________________
	case FIN_NODE_CARRE_02 :
		if (onEntry()) {
			/*Ne rien mettre ici (cf doc Modélia)*/
		}

			gotoStateAfter(STATE_56,200);
		if (onExit()) {  /*Ne rien mettre ici  (cf doc Modélia)*/  }
		break;
	// ___________________________
	case STATE_56 :
		if (onEntry()) {
			outputs()->CommandeMouvementXY_TETA_sym(44,-133,3.14);/**/
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
