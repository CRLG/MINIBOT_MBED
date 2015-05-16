/*! \file CMatch.cpp
	\brief Classe qui contient toute l'application
*/
#include "mbed.h"
#include "RessourcesHardware.h"
#include "CMatch.h"
#include "CGlobale.h"
#include "ConfigSpecifiqueCoupe.h"

extern "C" {
 #include "ModeleRobot.h"  		// Le code généré par Matlab Simulink est en "C" et pas en "C++"
}



//___________________________________________________________________________
 /*!
   \brief Constructeur

   \param --
   \return --
*/
CMatch::CMatch() 
{
    Initialise();
}

//___________________________________________________________________________
 /*!
   \brief Destructeur

   \param --
   \return --
*/
CMatch::~CMatch() 
{

}


//___________________________________________________________________________
 /*!
   \brief Initialise toutes les structures de donnéess du match à jouer

   \param --
   \return --
*/
void CMatch::Initialise(void)
{
  m_duree = 0;
  m_couleur_equipe = 0;
  m_dde_test_actionneurs = 0;
  m_choix_strategie = 0;

  ModeleRobot_initialize(0);
  m_DdeMvtManuel_old = 0;
  m_DdeMvtDistanceAngle_old = 0;
  m_DdeMvtXY_old = 0;
  m_DdeMvtXYTeta_old=0;

  m_ResetCodeurAscenseur_old=0;
  m_ResetCodeurBarillet_old=0;
  //ModeleRobot_P.SFunction_p22=Application.TempsMaxGonflage;

  m_obstacleDetecte=0;

  _led1 = 0;
  _led2 = 0;
	_led3 = 0;
	_led4 = 0;

	Application.m_capteurs.RAZ_PositionCodeur(CODEUR_INCLINAISON,0);
}
	

//___________________________________________________________________________
 /*!
   \brief Execute un pas de calcul du match

   \param --
   \return --
*/
void CMatch::step(void)
{
	// ___________________________ 
	// Recopie les entrées des capteurs vers les entrées du modèle
	
	//Ecran
	ModeleRobot_U.IN_CouleurEquipe = m_couleur_equipe;
	ModeleRobot_U.IN_demande_test_actionneurs = m_dde_test_actionneurs;
    // TODO : relier le numéro de stratégie à une entrée du modèle
    // ModeleRobot_U.IN_xxx = m_choix_strategie;
	
	//capteurs analogiques
	//Pour binariser le capteur effet hall pour la tirette
	//1 = tirette enlevee
	if (Application.m_capteurs.m_b_Eana1>=0.5)
		ModeleRobot_U.IN_Tirette = 1;
	else
		ModeleRobot_U.IN_Tirette = 0;
	
	//capteurs US
	//pour les obstacles on ne passe plus un booleen a la strategie mais la distance
	ModeleRobot_U.IN_ObstacleAR=Application.m_capteurs.m_telemetres.m_distance[1];
	ModeleRobot_U.IN_ObstacleAV=Application.m_capteurs.m_telemetres.m_distance[0];

	//Codeur
	ModeleRobot_U.IN_inclinaison=Application.m_capteurs.m_CumulCodeurPosition1;

	//Capteurs TOR
	//m_b_Etor3 est déjà pris pour piloter l'electrovanne
	ModeleRobot_U.IN_isMurFresque=!Application.m_capteurs.m_b_Etor1;
	
		
	//____________________________
	//Variables de l'aservissement
	ModeleRobot_U.IN_ConvergenceMvt = Application.m_asservissement.convergence_conf;  
	ModeleRobot_U.IN_x_pos = Application.m_asservissement.X_robot;
	ModeleRobot_U.IN_y_pos = Application.m_asservissement.Y_robot;
	ModeleRobot_U.IN_teta_pos = Application.m_asservissement.angle_robot;
	ModeleRobot_U.IN_ConvergenceMvt_Rapide = Application.m_asservissement.convergence_rapide;
	ModeleRobot_U.IN_Vitesse = Application.m_asservissement.vitesse_avance_robot; //vitesse de deplacement: a verifier avec guigui
	ModeleRobot_U.IN_SensDeplacement = Application.m_asservissement.erreur_distance; //sens de deplacement: en fonction du signe si + alors marche avant
	//TODO:
	//diag de blocage, pour l'instant on claque les tempo
	
	// ___________________________ 
	//Appel de la strategie du modele matlab
	ModeleRobot_step();
	
	// ___________________________ 
	// Remise à zéro des variables pour les tests actionneurs pour pouvoir les recommencer   
	//ModeleRobot_U.IN_demande_test_actionneurs=0;
	//m_dde_test_actionneurs=0;
	
	
	// ___________________________ 
	//Consignes pour l'asservissement
	Application.m_asservissement.CommandeVitesseMouvement(ModeleRobot_Y.OUT_ConsigneVitesseDistance, ModeleRobot_Y.OUT_ConsigneVitesseAngle);
	
	//Mvt Manuel
	if (ModeleRobot_Y.OUT_DdeMvtManuel != m_DdeMvtManuel_old) {
		Application.m_asservissement.CommandeManuelle(ModeleRobot_Y.OUT_CommandeManuelleG, ModeleRobot_Y.OUT_CommandeManuelleD);
	}
	m_DdeMvtManuel_old = ModeleRobot_Y.OUT_DdeMvtManuel;
	
	//Mvt Distance Angle
	if (ModeleRobot_Y.OUT_DdeMvtDistanceAngle != m_DdeMvtDistanceAngle_old) {
		Application.m_asservissement.CommandeMouvementDistanceAngle(ModeleRobot_Y.OUT_ConsigneDistance, ModeleRobot_Y.OUT_ConsigneTeta);
	}
	m_DdeMvtDistanceAngle_old = ModeleRobot_Y.OUT_DdeMvtDistanceAngle;
	
	//Mvt XY
	if (ModeleRobot_Y.OUT_DdeMvtXY != m_DdeMvtXY_old) {
		Application.m_asservissement.CommandeMouvementXY(ModeleRobot_Y.OUT_ConsigneX, ModeleRobot_Y.OUT_ConsigneY);
	}
	m_DdeMvtXY_old = ModeleRobot_Y.OUT_DdeMvtXY;
	
	//Mvt XYTeta
	if (ModeleRobot_Y.OUT_DdeMvtXYTeta != m_DdeMvtXYTeta_old) {
		Application.m_asservissement.CommandeMouvementXY_TETA(ModeleRobot_Y.OUT_ConsigneX, ModeleRobot_Y.OUT_ConsigneY, ModeleRobot_Y.OUT_ConsigneTeta);
	}
	m_DdeMvtXYTeta_old = ModeleRobot_Y.OUT_DdeMvtXYTeta;
	
	/*if (ModeleRobot_Y.OUT_DdeRecalagePosition != m_DdeRecalagePosition_old) {
		Application.m_asservissement.setPosition_XYTeta(ModeleRobot_Y.OUT_ConsigneX, ModeleRobot_Y.OUT_ConsigneY, ModeleRobot_Y.OUT_ConsigneTeta);
	}
	m_DdeRecalagePosition_old = ModeleRobot_Y.OUT_DdeRecalagePosition;*/
	
	// ___________________________ 
	//Consignes actionneurs
    // Les commande d'actionneurs peuvent venir soit du modèle, soit de l'écran tactile
	/*if (ModeleRobot_Y.OUT_OuvertureElectroAimants != m_old_cde_mot[MOTEUR_ELECTRO_AIMANTS]) {
        Application.m_moteurs.CommandeVitesse(MOTEUR_ELECTRO_AIMANTS, ModeleRobot_Y.OUT_OuvertureElectroAimants); // ELECTROVANNE
	    m_old_cde_mot[MOTEUR_ELECTRO_AIMANTS] = ModeleRobot_Y.OUT_OuvertureElectroAimants;
    }*/    

	// ___________________________ 
	// Commande des servos moteurs
	if (ModeleRobot_Y.OUT_CommandeServo[SERVO_INCLINAISON-1] != m_old_cde_servo[SERVO_INCLINAISON]) { 
        Application.m_servos_sd20.CommandePositionVitesse(SERVO_INCLINAISON, ModeleRobot_Y.OUT_CommandeServo[SERVO_INCLINAISON-1], ModeleRobot_Y.OUT_SpeedServo[SERVO_INCLINAISON-1]);
        m_old_cde_servo[SERVO_INCLINAISON] = ModeleRobot_Y.OUT_CommandeServo[SERVO_INCLINAISON-1];
    } 
	
	if (ModeleRobot_Y.OUT_CommandeServo[SERVO_BRAS_D-1] != m_old_cde_servo[SERVO_BRAS_D]) { 
        Application.m_servos_sd20.CommandePositionVitesse(SERVO_BRAS_D, ModeleRobot_Y.OUT_CommandeServo[SERVO_BRAS_D-1],ModeleRobot_Y.OUT_SpeedServo[SERVO_BRAS_D-1]);
        m_old_cde_servo[SERVO_BRAS_D] = ModeleRobot_Y.OUT_CommandeServo[SERVO_BRAS_D-1];
    } 

	if (ModeleRobot_Y.OUT_CommandeServo[SERVO_BRAS_G-1] != m_old_cde_servo[SERVO_BRAS_G]) { 
        Application.m_servos_sd20.CommandePositionVitesse(SERVO_BRAS_G, ModeleRobot_Y.OUT_CommandeServo[SERVO_BRAS_G-1], ModeleRobot_Y.OUT_SpeedServo[SERVO_BRAS_G-1]);
        m_old_cde_servo[SERVO_BRAS_G] = ModeleRobot_Y.OUT_CommandeServo[SERVO_BRAS_G-1];
    } 
	
	if (ModeleRobot_Y.OUT_CommandeServo[SERVO_DOIGT-1] != m_old_cde_servo[SERVO_DOIGT]) { 
        Application.m_servos_sd20.CommandePositionVitesse(SERVO_DOIGT, ModeleRobot_Y.OUT_CommandeServo[SERVO_DOIGT-1], ModeleRobot_Y.OUT_SpeedServo[SERVO_DOIGT-1]);
        m_old_cde_servo[SERVO_DOIGT] = ModeleRobot_Y.OUT_CommandeServo[SERVO_DOIGT-1];
    }

	
	//SORTIES de MODELE
	m_obstacleDetecte=ModeleRobot_Y.OUT_isObstacle;

	// ___________________________ 
	// Divers
	m_duree = ModeleRobot_DWork.DureeMatch * 0.02;    // m_match.m_duree est en nombre de passage dans la boucle de 20msec
	
	
	// ___________________________ 
	// Les LEDs
	_led1 = ModeleRobot_Y.OUT_EtatLed1;
	_led2 = ModeleRobot_Y.OUT_EtatLed2;
	_led3 = ModeleRobot_Y.OUT_EtatLed3;
	_led4 = ModeleRobot_Y.OUT_EtatLed4;


	// Asservissement
	Application.m_asservissement.CalculsMouvementsRobots();
}




//___________________________________________________________________________
 /*!
   \brief Envoie les infos sur la  RS232

   \param --
   \return --
*/
void CMatch::debug(void)
{
   _rs232_pc_tx.putc(0xC);	// Saut de page pour que toutes les infos soient affichées toujours au meme endroit sur la page (avec hyperterminal)
   _rs232_pc_tx.printf("DureeMatch=%f\r\n", m_duree); 
   _rs232_pc_tx.printf("MvtManuel=%f(%f, %f)\n\r", ModeleRobot_Y.OUT_DdeMvtManuel, ModeleRobot_Y.OUT_CommandeManuelleG, ModeleRobot_Y.OUT_CommandeManuelleD);
   _rs232_pc_tx.printf("MvtDistAngle=%f(%f, %f)\n\r", ModeleRobot_Y.OUT_DdeMvtDistanceAngle, ModeleRobot_Y.OUT_ConsigneDistance, ModeleRobot_Y.OUT_ConsigneTeta);
   _rs232_pc_tx.printf("MvtXY=%f(%f, %f)\n\r", ModeleRobot_Y.OUT_DdeMvtXY, ModeleRobot_Y.OUT_ConsigneX, ModeleRobot_Y.OUT_ConsigneY); 
   _rs232_pc_tx.printf("CdeMotG=%f - CdeMotD=%f\n\r", Application.m_asservissement.cde_moteur_G, Application.m_asservissement.cde_moteur_D); 
}




