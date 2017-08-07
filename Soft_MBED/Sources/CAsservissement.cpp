//			Asservissement 2017
//
//	Modifications à valider ou calibrer :
//
//	Diag de blocage à calibrer : etait 12, pass� � 45
//	Calcul du coeff facteur_correction_avance_angle ne fonctionne pas correctement en passant pas la carto ?
//	Correction batterie à valider
//	Mouvement XY_TETA à valider
//	Initialisation des zones mortes suppr (en commentaire)
//	Flag de convergence rapide à valider
//	Todo : Diag de blocage par écart de boucle ?

/*! \file CAsservissement.cpp
	\brief Classe qui contient toute l'application
*/
#include "math.h"
#include "CAsservissement.h"
#include "CGlobale.h"


//___________________________________________________________________________
 /*!
   \brief Constructeur

   \param --
   \return --
*/
CAsservissement::CAsservissement() 
{
  Init();
}


//___________________________________________________________________________
 /*!
   \brief Destructeur

   \param --
   \return --
*/
CAsservissement::~CAsservissement() 
{

}


//___________________________________________________________________________
 /*!
   \brief Initialisation

   \param --
   \return --
*/
void CAsservissement::Init(void) 
{
 int i;
 
 // initialisation des paramètres de l'asservissement
 cde_max = 70;				// %	Commande maximum normalisée pour saturer la régulation
 cde_min = -70 ;			// %	Commande minimum normalisée pour saturer la régulation
 kp_distance =  0.8;		// 		Gain proportionnel pour la régulation en distance
 ki_distance =  1;		// 		Gain intégral pour la régulation en distance
 kp_angle =  20;			// 		Gain proportionnel pour la régulation en angle
 ki_angle =  10;			// 		Gain intégral pour la régulation en angle
 k_angle = 0.5;				//		Coeff de filtrage pour le terme dérivé
 seuil_conv_distance =  1;	// cm	Erreur en dessous de laquelle on considère que le robot est en position sur la distance
 seuil_conv_angle =  0.02;	// rad	Erreur en dessous de laquelle on considère que le robot est en position sur l'angle
 compteur_max = 3;			// 		Nombre de coups d'horloge (N*te) avant de confirmer que le robot est en position

 // Initialisation des zones mortes
 zone_morte_D = 49;
 zone_morte_G = 49;

 // Les variables de l'asservissement
 distance_consigne = 0;
 angle_consigne = 0;
 distance_roue_D = 0;
 distance_roue_G = 0;
 erreur_distance = 0;
 erreur_angle = 0;
 erreur_vitesse_avance = 0;
 erreur_vitesse_rotation = 0;
 int_terme_prec_distance = 0;
 int_terme_distance = 0;
 cde_distance_ulim = 0;
 cde_distance_recal = 0;
 cde_distance = 0;
 int_terme_prec_angle = 0;
 int_terme_angle = 0;
 cde_angle_ulim = 0;
 cde_angle = 0;
 cde_moteur_D = 0;
 cde_moteur_D_ulim = 0;
 cde_moteur_G = 0;
 cde_moteur_G_ulim = 0;
 angle_robot_prec = 0;
 distance_roue_D_prec = 0;
 distance_roue_G_prec = 0;
 X_robot_prec = 0;
 Y_robot_prec = 0;
 ddistance_roue_D = 0;
 ddistance_roue_G = 0;
 ddistance_robot = 0;
 distance_robot = 0;
 dangle_robot = 0;
 angle_robot = 0;
 dX_robot = 0;
 dY_robot = 0;
 X_robot = 0;
 X_consigne = 0;
 Y_robot = 0;
 X_erreur = 0;
 Y_erreur = 0;
 Y_consigne = 0;
 temp_cos_angle_robot = 0;
 temp_sin_angle_robot = 0;
 Xa = 0;
 Ya = 0;
 Xb = 0;
 Yb = 0;
 Offset_a = 0;
 Offset_b = 0;
 cde_offset_min_D = zone_morte_D;
 cde_offset_min_G = zone_morte_G;
 correction_ubatt = 1;
 //m_tension_batterie; // Externe
 ubatt_nominale=15.5;
 m_tension_batterie_filt = 1.44;
 m_tension_batterie_filt_prec = 14.4;
 k_batt = 0.9;							// Coeff de filtrage de la tension batterie (1 = pas de filtrage)
 vitesse_avance_robot = 0;
 vitesse_rotation_robot = 0;
 vitesse_avance_robot_filt_prec = 0;
 vitesse_avance_robot_filt = 0;
 k_filt_avance = 0.7;					// Coeff de filtrage de la vitesse d'avance (1 = pas de filtrage)
 vitesse_rotation_robot_filt_prec = 0;
 vitesse_rotation_robot_filt = 0;
 k_filt_rotation = 0.8;					// Coeff de filtrage de la vitesse de rotation (1 = pas de filtrage)
 consigne_vitesse_avance = 0;
 consigne_vitesse_rotation = 0;
 consigne_vitesse_avance_filt = 0;
 consigne_vitesse_avance_recal = 0;
 consigne_vitesse_rotation_cm = 0;
 consigne_vitesse_rotation_filt = 0;
 facteur_correction_avance_angle = 0;
 seuil_vitesse_diag_blocage = 2;		// cm/s
 commande_min_diag_blocage = 60;		// En cas de blocage l'égrateur charge rapidement à des valeurs importantes
 seuil_vitesse_diag_rotation = 0.1;	// rad/s
 seuil_max_compteur_diag_blocage = 50;	// k * te = g secondes
 inc_diag_blocage = 1;
 dec_diag_blocage = 2;
 compteur_diag_blocage = 0;
 diag_blocage = 0;
 convergence = 0;
 convergence_conf = 0;					// 0: Mvt en cours, 1: Convergence ok, 2: Blocage détecté
 saturation_distance = 0;
 saturation_angle = 0;
 saturation_moteur_D = 0;
 saturation_moteur_G = 0;
 verouillage_approche = 0;
 compteur_convergence = 0;
 ModeAsservissement = cMODE_MANUEL;
 TETA_consigne=0;
 convergence_rapide = 0;

 offset_vitesse_avance = 0;				//	[cm/s-2]
 offset_vitesse_rotation = 0;			//	[rad/s-2]
 vitesse_avance_max = 80;				//	[cm/s]
 vitesse_rotation_max = 3;				//	[rad/s]
 Ind_perfo = 0.8;

 // Initialisation des valeurs par défauts des tableaux
 for (i=0; i<NBRE_POINTS_CARTO_ERREUR; i++) {
	 conv_erreur_dist_vitesse_cur_x[i] = ini_conv_erreur_dist_vitesse_cur_x[i];
	 conv_erreur_dist_vitesse_1_cur[i] = ini_conv_erreur_dist_vitesse_1_cur[i];
	 conv_erreur_dist_vitesse_2_cur[i] = ini_conv_erreur_dist_vitesse_2_cur[i];
	 
	 conv_erreur_angle_vitesse_cur_x[i] = ini_conv_erreur_angle_vitesse_cur_x[i];
	 conv_erreur_angle_vitesse_1_cur[i] = ini_conv_erreur_angle_vitesse_1_cur[i];
	 conv_erreur_angle_vitesse_2_cur[i] = ini_conv_erreur_angle_vitesse_2_cur[i];
	 
	 //facteur_cor_vitesse_avance_cur_x[i] = ini_facteur_cor_vitesse_avance_cur_x[i];
	 //facteur_cor_vitesse_avance_cur[i] = ini_facteur_cor_vitesse_avance_cur[i];
 }




 // Initialise les positions des codeurs
 Application.m_roues.resetCodeurs();

}

// Routine de calcul des cartographies avec interpolation linéaire

float CAsservissement::Calc_carto_cur(float entree_x, float axe_x[], float axe_z[], int nb_point_x)
{
	unsigned int i=1;
	float sortie=0;
	
	if (entree_x <= axe_x[0]) // saturation basse
		{
		sortie = axe_z[0];
		}
	else
		{
		if (entree_x >= axe_x[nb_point_x-1]) // saturation haute
			{
			sortie = axe_z[nb_point_x-1];
			}
		else
			{
			while (axe_x[i-1] <= entree_x)
				{
				if (axe_x[i] >= entree_x) // L'élément i est le point support sup, i-1 le point support inf
					{
					sortie = ( (axe_z[i] - axe_z[i-1]) / (axe_x[i] - axe_x[i-1]) ) * (entree_x - axe_x[i]) + axe_z[i];
					}
				i++;
				}
			}
		}
	
	return sortie;
}


//*******************************************************************************************
//									Initialisation des PID
//*******************************************************************************************

void CAsservissement::Initialisation_PID(void)
{
	int_terme_prec_distance = 0;
	int_terme_prec_angle = 0;
	int_terme_distance = 0;
	int_terme_angle = 0;
	consigne_vitesse_rotation_filt = vitesse_rotation_robot_filt;	// Permet dans le cas d'un blocage de réinitialiser le gradient
	consigne_vitesse_avance_filt = vitesse_avance_robot_filt;		// Permet dans le cas d'un blocage de réinitialiser le gradient
	offset_vitesse_avance = 3.2*Ind_perfo + 0.6;					// TODO mettre dans décode.c sur réception de trame
	offset_vitesse_rotation = 0.3*Ind_perfo + 0.1;					// TODO
}

//*******************************************************************************************
//									Reset des pas cumulés
//*******************************************************************************************

void CAsservissement::Reset_Pas_Cumules(void)
{
// Reset des 2 registres de la chaîne d'acquisisiton
Application.m_roues.resetCodeurs();
// Les mémoires pour le calcul de la position sont resetées
distance_roue_D_prec = 0;
distance_roue_G_prec = 0;

// Les consignes relatives sont resetées
distance_consigne = 0;
angle_consigne = 0;

}

//*******************************************************************************************
//								Arrêt de la commande brutale
//*******************************************************************************************

void CAsservissement::Stop_robot(void)
{
	Application.m_roues.AdapteCommandeMoteur_G(0);  // Avec "0", on met en shunt les ponts en "H"
	Application.m_roues.AdapteCommandeMoteur_D(0);
}

//*******************************************************************************************
//								Saturation des commandes
//*******************************************************************************************

float CAsservissement::saturation(float valeur_ulim, float valeur_min, float valeur_max)
{
float valeur_lim;

	valeur_lim = valeur_ulim;

	if (valeur_ulim > valeur_max)
		{
		valeur_lim = valeur_max;
		}
	if (valeur_ulim < valeur_min)
		{
		valeur_lim = valeur_min;
		}

return (valeur_lim);
}

//*******************************************************************************************
//							Lecture des codeurs et conversion en cm
//*******************************************************************************************

void CAsservissement::LectureCodeurCalculDistance(void)
{
	distance_roue_D = Application.m_roues.getCodeurD() * DISTANCE_PAR_PAS_CODEUR_D;	// [cm]
	distance_roue_G = Application.m_roues.getCodeurG() * DISTANCE_PAR_PAS_CODEUR_G; // [cm]
}	

//*******************************************************************************************
//								Asservissement polaire
//*******************************************************************************************

void CAsservissement::asservissement(void)
{
// Calcul de la convergence basée sur l'erreur entre les consignes et les mesures

if (ModeAsservissement == cMODE_DISTANCE_ANGLE)
	{
	if ((fabsf(erreur_angle) < seuil_conv_angle*3) && (fabsf(erreur_distance) < seuil_conv_distance*3))
		{
		convergence_rapide = 1;
		}
	else
		{
		convergence_rapide = 0;
		}
		
	if ( (fabsf(erreur_angle) < seuil_conv_angle) && (fabsf(erreur_distance) < seuil_conv_distance) )
		{
		if (compteur_convergence == compteur_max)
			{
			convergence_conf = 1;
			Stop_robot();			// Commande nulle pour économiser la batterie, ligne à retirer si la piste n'est pas plane
			}
		else
			{
			compteur_convergence++;
			}
		}

	else
		{
		convergence_conf = 0;
		compteur_convergence = 0;	// Reset du Compteur de convergence dès que l'on n'est plus dans les conditions
		}
	}

else // Asservissement XY_AUTO...
	{
	if (fabsf(erreur_distance) < seuil_conv_distance*3)
		{
		convergence_rapide = 1;
		}
	else
		{
		convergence_rapide = 0;
		}
	
	if (fabsf(erreur_distance) < seuil_conv_distance)
		{
		if (compteur_convergence == compteur_max)
			{
			convergence_conf = 1;
			Stop_robot();			// Commande nulle pour économiser la batterie, ligne à retirer si la piste n'est pas plane
			}
		else
			{
			compteur_convergence++;
			}
		}

	else
		{
		convergence_conf = 0;
		compteur_convergence = 0;	// Reset du Compteur de convergence dès que l'on n'est plus dans les conditions
		}
	}

	
if (convergence_conf == 0) // Pas la peine de calculer la commande si on a convergé => Terrain plat
	{
	//------------------------------------------------------------------------------------------
	// Le Premier PI calcul une commande pour faire avancer ou reculer le robot
	//------------------------------------------------------------------------------------------
		// Si une des commandes est saturée on fige le terme intégral
		if ((saturation_distance == 0) && (saturation_angle == 0) && (saturation_moteur_D == 0) && (saturation_moteur_G == 0))
			{
			int_terme_prec_distance = int_terme_distance; // Mémoire z-1
			int_terme_distance = ki_distance * te * erreur_vitesse_avance + int_terme_prec_distance;
			}

		cde_distance_ulim = kp_distance * erreur_vitesse_avance + int_terme_distance;
	
		if (cde_distance_ulim >= cde_max || cde_distance_ulim <= cde_min)
			{
			saturation_distance = 1;
			}
		else
			{
			saturation_distance = 0;
			}
	
		cde_distance = saturation(cde_distance_ulim, cde_min, cde_max);
	
	//-------------------------------------------------------------------------------------------
	// Le second PI calcul une commande pour corriger l'angle du robot
	//-------------------------------------------------------------------------------------------
		// Attention : Seule la saturation du PI en angle doit pouvoir figer le terme intégral
		if (saturation_angle == 0)
			{
			int_terme_prec_angle = int_terme_angle; // Mémoire z-1
			int_terme_angle = ki_angle * te * erreur_vitesse_rotation + int_terme_prec_angle;
			}
	
		cde_angle_ulim = kp_angle * erreur_vitesse_rotation + int_terme_angle;
	
		if ((cde_angle_ulim >= cde_max) || (cde_angle_ulim <= cde_min))
			{
			saturation_angle = 1;
			}
		else
			{
			saturation_angle = 0;
			}
	
		cde_angle = saturation(cde_angle_ulim, cde_min, cde_max);
	
	//-------------------------------------------------------------------------------------------
	// On fait la coordination des commandes selon le théorème de superposition
	// + recalcul de la commande en distance pour prioriser la commande en angle
	// + correction batterie et saturations
	// + Diag de blocage
	//-------------------------------------------------------------------------------------------

		cde_distance_recal = cde_distance;

	// Recalcul de la commande en distance en cas de saturation d'un des moteurs
		if ((cde_distance + cde_angle) >= cde_max)
			{
			cde_distance_recal = cde_max - cde_angle;
			}

		if ((cde_distance - cde_angle) <= cde_min)
			{
			cde_distance_recal = cde_min + cde_angle;
			}
			
		if ((cde_distance - cde_angle) >= cde_max)
			{
			cde_distance_recal = cde_max + cde_angle;
			}

		if ((cde_distance + cde_angle) <= cde_min)
			{
			cde_distance_recal = cde_min - cde_angle;
			}
			
	// Calcul de la commande du moteur droit
		cde_moteur_D_ulim = cde_distance_recal + cde_angle;
	
		if ((cde_moteur_D_ulim >= cde_max) || (cde_moteur_D_ulim <= cde_min))
			{
			saturation_moteur_D = 1;
			}
		else
			{
			saturation_moteur_D = 0;
			}
	
		cde_moteur_D = saturation(cde_moteur_D_ulim, cde_min, cde_max);
	
	// Calcul de la commande du moteur gauche
		cde_moteur_G_ulim = cde_distance_recal - cde_angle;
	
		if ((cde_moteur_G_ulim >= cde_max) || (cde_moteur_G_ulim <= cde_min))
			{
			saturation_moteur_G = 1;
			}
		else
			{
			saturation_moteur_G = 0;
			}
	
		cde_moteur_G = saturation(cde_moteur_G_ulim, cde_min, cde_max);

	// Correction des zones mortes des moteurs par précommande
		if (cde_moteur_D > 0)
			{
			cde_moteur_D += cde_offset_min_D;
			}
		else if (cde_moteur_D < 0)
			{
			cde_moteur_D -= cde_offset_min_D;
			}
		/* else ne rien faire : laisser la commande à "0" */
	
		if (cde_moteur_G > 0)
			{
			cde_moteur_G += cde_offset_min_G;
			}
		else if (cde_moteur_G < 0)
			{
			cde_moteur_G -= cde_offset_min_G;
			}
		/* else ne rien faire : laisser la commande à "0" */
	
		// Correction de la commande en fonction des fluctuations de la tension batterie.
		
		// Filtage de la tension batterie
		m_tension_batterie_filt_prec = m_tension_batterie_filt;
		// Nico:mise en commentaire
		//m_tension_batterie_filt = m_tension_batterie_filt_prec + k_batt * ((Application.m_capteurs.m_b_Mes_Vbat) - m_tension_batterie_filt_prec);
        // Nico->Guigui : pour récupérer la tension batterie, il faut faire "Application.m_capteurs.m_b_Mes_Vbat"
		
        // Correction de la commande de manière proportionnelle à la variation de tension batterie avant saturation
		// Nico:mise en commentaire
		//correction_ubatt = ubatt_nominale / m_tension_batterie_filt;
		cde_moteur_G *= correction_ubatt;
		cde_moteur_D *= correction_ubatt;
	
		// Nouvelle saturation après correction batterie et anti zone morte
		cde_moteur_G = saturation(cde_moteur_G, -100, 100);
		cde_moteur_D = saturation(cde_moteur_D, -100, 100);

		// Diag de blocage
		//if ( (vitesse_avance_robot * cde_distance_recal) > 0) // On regarde si la commande et la vitesse sont de même signe car par la suite on est en valeur abs, évite d'incrémenter le compteur durant le freinage
			//{
			if ( ((fabsf(vitesse_avance_robot) < seuil_vitesse_diag_blocage) && (fabsf(cde_distance_recal) > commande_min_diag_blocage)) || ((fabsf(vitesse_rotation_robot) < seuil_vitesse_diag_rotation) && (fabsf(cde_angle) > commande_min_diag_blocage)) )
				{
				if (compteur_diag_blocage < seuil_max_compteur_diag_blocage)
					{
					compteur_diag_blocage += inc_diag_blocage;
					}
				else
					{
					diag_blocage = 1;
					// Pour informer sur le CAN que l'asservissement à des problèmes, sur encode.c on envoi convergence_conf à 2
					}
				}
			else // Pas de problème de blocage
				{
				if ((compteur_diag_blocage > 0) && (diag_blocage == 0)) // && diag_blocage == 0 pour créer un état piège une fois le diag tilté, la réinit ce fait sur un nouvel ordre de mvt
					{
					compteur_diag_blocage -= dec_diag_blocage;
					}
				else if (diag_blocage == 0)
					{
					diag_blocage = 0;
					}
				}
			//}
			
		if (diag_blocage == 1)
			{
			Stop_robot();
			ModeAsservissement = cMODE_MANUEL; // Pour ne plus calculer le générateur de trajectoire
			}
		else
			{
			// Appliquer la commande
			Application.m_roues.AdapteCommandeMoteur_G(cde_moteur_G);
			Application.m_roues.AdapteCommandeMoteur_D(cde_moteur_D);
			}
	}
}

//*************************************************************************************
//
//					Calcul de la position absolue du robot V1.1
//
//		1.0 Validé fonctionnellement le 01/03/08
//		1.1 Ajout du calculs des positions des points A et B
//
//		Entrées : Cumul des pas des codeurs D du robot
//		Sorties : X, Y, Xa, Ya, Xb, Yb l'angle du robot (angle normalisé ]-pi; pi]),
//		,la distance parcourue, les vitesses filtrées du robot (avance et rotation)
//
//
//*************************************************************************************

void CAsservissement::CalculXY (void)
{
// On ne prend que les pas réalisés entre deux appels de tâche dans ddistance_roue_X
ddistance_roue_D = distance_roue_D - distance_roue_D_prec;
distance_roue_D_prec = distance_roue_D; // Cette offset est remis à 0 par Reset_Pas_Cumules()

ddistance_roue_G = distance_roue_G - distance_roue_G_prec;
distance_roue_G_prec = distance_roue_G; // Cette offset est remis à 0 par Reset_Pas_Cumules()

// On calcul les estimations élémentaires de la distance et de la rotation réalisées par le robot
ddistance_robot = (ddistance_roue_D + ddistance_roue_G)*0.5;
dangle_robot = (ddistance_roue_D - ddistance_roue_G)*FACTEUR_CONV_DELTA_DIST_VERS_ANGLE; // 2pi/(pi*voie_robot) Conversion distance vers angle

// On calcul la vitesse instantanée [cm/s] du robot
vitesse_avance_robot = ddistance_robot / te;
vitesse_avance_robot_filt_prec = vitesse_avance_robot_filt;
vitesse_avance_robot_filt = vitesse_avance_robot_filt_prec + k_filt_avance * (vitesse_avance_robot - vitesse_avance_robot_filt_prec);

// On calcul la vitesse instantannée [rad/s] du robot
vitesse_rotation_robot = dangle_robot / te;
vitesse_rotation_robot_filt_prec = vitesse_rotation_robot_filt;
vitesse_rotation_robot_filt = vitesse_rotation_robot_filt_prec + k_filt_rotation * (vitesse_rotation_robot - vitesse_rotation_robot_filt_prec);

// On calcul l'angle robot en cumulant les rotations élémentaires et on le normalise ]-pi ; pi]
angle_robot = dangle_robot + angle_robot_prec;

// On calcul la distance parcourue du robot
distance_robot = (distance_roue_D + distance_roue_G)*0.5;

// Attention ne par faire plus de 2pi par Te ! Ceci n'est pas un modulo
if (angle_robot > 3.14)
	{
	angle_robot = angle_robot - 6.28;
	}

if (angle_robot <= -3.14)
	{
	angle_robot = angle_robot + 6.28;
	}
angle_robot_prec = angle_robot;

// On calcul cos(angle_robot) et sin(angle_robot) => temp afin d'éviter de faire plusieurs fois le calcul pas la suite
temp_cos_angle_robot = cos(angle_robot);
temp_sin_angle_robot = sin(angle_robot);

// On calcul les déplacements élémentaires en X et Y
dX_robot = ddistance_robot*temp_cos_angle_robot;
dY_robot = ddistance_robot*temp_sin_angle_robot;

// On calcul la position du robot en cumulant les déplacements élémentaires
X_robot = dX_robot + X_robot_prec;
X_robot_prec = X_robot;

Y_robot = dY_robot + Y_robot_prec;
Y_robot_prec = Y_robot;

// On calcul la position des points A et B
Xa = X_robot + Offset_a*temp_cos_angle_robot;
Ya = Y_robot + Offset_a*temp_sin_angle_robot;
Xb = X_robot - Offset_b*temp_cos_angle_robot;
Yb = Y_robot - Offset_b*temp_sin_angle_robot;

}

//*************************************************************************************
//
//							Générateur de trajectoire V1.3
//
//		1. Entrées : Coordonnées absolues cible X_consigne, Y_consigne ou distance et angle
//		2. Sorties : Erreurs des boucles d'asservissement en vitesse de distance et en vitesse angulaire
//
//		1.2 Recalcul de la vitesse d'avance VS vitesse de rotation
//		1.3 Ajout du switch sur la position à asservir (X,Y , Xa,Ya ou Xb,Yb)
//
//*************************************************************************************

void CAsservissement::Generateur_trajectoire (void)
{
// Normalisation de l'angle de consigne par le principe des 4 cadrans
//
//	   î y
//	   |
//	 3 | 1
//	--------> x
//	 4 | 2
//

if ((ModeAsservissement == cMODE_XY_AUTO) || (ModeAsservissement == cMODE_XY_AUTO_A) ||(ModeAsservissement == cMODE_XY_AUTO_B || (ModeAsservissement == cMODE_XY_TETA))) // asservissement polaire ou polaire décalé
	{

	switch (ModeAsservissement)
	{	
		case cMODE_XY_AUTO_A :
			X_erreur = X_consigne - Xa;
			Y_erreur = Y_consigne - Ya;
		break;
		
		case cMODE_XY_AUTO_B :
			X_erreur = X_consigne - Xb;
			Y_erreur = Y_consigne - Yb;
		break;
		
		case cMODE_XY_AUTO :
			X_erreur = X_consigne - X_robot;
			Y_erreur = Y_consigne - Y_robot;
		break;		
		
		case cMODE_XY_TETA :
			X_erreur = X_consigne - X_robot;
			Y_erreur = Y_consigne - Y_robot;
		break;
	}
		
	erreur_distance = sqrt((X_erreur * X_erreur) + (Y_erreur * Y_erreur));

	if (fabsf(erreur_distance) > 0.1) // Ne calcul pas l'angle si la distance est trop petite (=> figeage)
		{
		if (X_erreur >= 0)
			{
			if (Y_erreur >= 0)
				{
				//cadran = 1;
				angle_consigne = asinf(fabsf(Y_erreur / erreur_distance));
				}
			else
				{
				//cadran = 2;
				angle_consigne = - asinf(fabsf(Y_erreur / erreur_distance));
				}
			}
		else
			{
			if (Y_erreur >= 0)
				{
				//cadran = 3;
				angle_consigne = 3.14 - asinf(fabsf(Y_erreur / erreur_distance));
				}
			else
				{
				//cadran = 4;
				angle_consigne = asinf(fabsf(Y_erreur / erreur_distance)) - 3.14;
				}
			}
		}

	// On calcul la différence entre l'angle consigne et l'angle robot puis on déternime le sens de rotation le plus court

	erreur_angle = angle_consigne - angle_robot;
	if (erreur_angle > 3.14)
		{
		erreur_angle -= 6.28;
		}
	if (erreur_angle <= -3.14)
		{
		erreur_angle += 6.28;
		}
	
	// On détermine si le robot doit avancer ou reculer pour atteindre le point cible
	
	if (fabsf(erreur_angle) > 1.57) // Le point est derrière le robot
		{
		erreur_distance = -erreur_distance;	// On change le signe de l'erreur pour faire marche arrière
		
		if (erreur_angle >= 0)		// On change de repère pour l'erreur de l'angle
			{
			erreur_angle -= 3.14;
			}
		else
			{
			erreur_angle += 3.14;
			}
		}

	// A ce stade il faut corriger l'erreur angle afin de ne pas avoir un robot qui danse autour du point XY consigne

	// Si le robot est proche du point de convergence et dans l'axe on impose une erreur d'angle nulle, on désactive la stratégie si l'erreur en distance devient trop importante
	if ((fabs(erreur_distance) < 2) && (fabsf(erreur_angle) < 3*seuil_conv_angle))
		{
		verouillage_approche = 1; // Set verrouillage
		}

	if (fabs(erreur_distance) > (3*seuil_conv_distance))
		{
		verouillage_approche = 0; // Reset le verrouillage
		}
	
	if (verouillage_approche == 1)
		{
		erreur_angle = 0; // Si verrouillage, le robot est à peu près dans l'axe, reste à avancer un peu !
		}
	}

else	// asservissement distance, angle
	{

	// Calcul des erreurs de distance et d'angle
	
	erreur_distance = distance_consigne - distance_robot;
	erreur_angle = angle_consigne - angle_robot; // Erreur brute à ce stade il faut la corriger selon le sens de rotation le plus court

	// On détermine le sens de rotation le plus court avec la gestion du modulo de l'angle du robot

	if (erreur_angle > 3.14)
		{
		erreur_angle -= 6.28;
		}
	if (erreur_angle <= -3.14)
		{
		erreur_angle +=6.28;
		}
	}
	
	// On calcul la consigne de vitesse de rotation en fonction de l'erreur d'angle (Forumule théorique v = sqrt(2*Accel*erreur) pour mvt accel uniforme)
	consigne_vitesse_rotation_base = Calc_carto_cur(erreur_angle, conv_erreur_angle_vitesse_cur_x, conv_erreur_angle_vitesse_1_cur, NBRE_POINTS_CARTO_ERREUR);
	consigne_vitesse_rotation_perfo = Calc_carto_cur(erreur_angle, conv_erreur_angle_vitesse_cur_x, conv_erreur_angle_vitesse_2_cur, NBRE_POINTS_CARTO_ERREUR);
	// Interpolation entre les deux courbes base et perfo
	consigne_vitesse_rotation = consigne_vitesse_rotation_base * (1 - Ind_perfo) + consigne_vitesse_rotation_perfo * Ind_perfo;
	// Limitation de vitesse au besoin
	consigne_vitesse_rotation = saturation(consigne_vitesse_rotation, -vitesse_rotation_max, vitesse_rotation_max);
	
	// On calcul la consigne de vitesse d'avance en fonction de l'erreur de distance (Forumule théorique v = sqrt(2*Accel*erreur) pour mvt accel uniforme)
	consigne_vitesse_avance_base = Calc_carto_cur(erreur_distance, conv_erreur_dist_vitesse_cur_x, conv_erreur_dist_vitesse_1_cur, NBRE_POINTS_CARTO_ERREUR);
	consigne_vitesse_avance_perfo = Calc_carto_cur(erreur_distance, conv_erreur_dist_vitesse_cur_x, conv_erreur_dist_vitesse_2_cur, NBRE_POINTS_CARTO_ERREUR);
	// Interpolation entre les deux courbes base et perfo
	consigne_vitesse_avance = consigne_vitesse_avance_base * (1 - Ind_perfo) + consigne_vitesse_avance_perfo * Ind_perfo;
	consigne_vitesse_avance = saturation(consigne_vitesse_avance, -vitesse_avance_max, vitesse_avance_max);
	
	// Diminution de la vitesse d'avance si l'erreur d'angle est importante => Priorité rotation sur l'avance mais pas trop pour faire des courbes
	//facteur_correction_avance_angle = Cal_carto_cur(erreur_angle, facteur_cor_vitesse_avance_cur_x, facteur_cor_vitesse_avance_cur, NBRE_POINTS_CARTO_ERREUR);
	// Le calcul de la carto de correction semble avoir un problème... TO CHECK... On utlise la vieille méthode qui marche de 2012.
	if (erreur_angle >= 0)
		{
		facteur_correction_avance_angle = -0.8 * erreur_angle + 1;
		facteur_correction_avance_angle = max(facteur_correction_avance_angle, 0);
		}
	else // Erreur_angle < 0
		{
		facteur_correction_avance_angle = 0.8 * erreur_angle + 1;
		facteur_correction_avance_angle = max(facteur_correction_avance_angle, 0);	
		}	
	facteur_correction_avance_angle=1;  //pour essais 20 juillet 2017
	consigne_vitesse_avance_recal = consigne_vitesse_avance*facteur_correction_avance_angle;
	
	// Grandient max consigne vitesse rotation
	if (consigne_vitesse_rotation >= 0)
		{
		if (consigne_vitesse_rotation_filt < consigne_vitesse_rotation)
			{
			consigne_vitesse_rotation_filt += offset_vitesse_rotation;
			consigne_vitesse_rotation_filt = min(consigne_vitesse_rotation_filt, consigne_vitesse_rotation);
			}
		else
			{
			consigne_vitesse_rotation_filt = consigne_vitesse_rotation;
			}
		}

	else if (consigne_vitesse_rotation < 0)
		{
		if (consigne_vitesse_rotation_filt > consigne_vitesse_rotation)
			{
			consigne_vitesse_rotation_filt -= offset_vitesse_rotation;
			consigne_vitesse_rotation_filt = max(consigne_vitesse_rotation_filt, consigne_vitesse_rotation);
			}
		else
			{
			consigne_vitesse_rotation_filt = consigne_vitesse_rotation;
			}
		}

	// Gradient max consigne vitesse avance
	if (consigne_vitesse_avance_recal >= 0)
		{
		if (consigne_vitesse_avance_filt < consigne_vitesse_avance_recal)
			{
			consigne_vitesse_avance_filt += offset_vitesse_avance;
			consigne_vitesse_avance_filt = min(consigne_vitesse_avance_filt, consigne_vitesse_avance_recal);
			}
		else
			{
			consigne_vitesse_avance_filt = consigne_vitesse_avance_recal;
			}
		}

	else if (consigne_vitesse_avance_recal < 0)
		{
		if (consigne_vitesse_avance_filt > consigne_vitesse_avance_recal)
			{
			consigne_vitesse_avance_filt -= offset_vitesse_avance;
			consigne_vitesse_avance_filt = max(consigne_vitesse_avance_filt, consigne_vitesse_avance_recal);
			}
		else
			{
			consigne_vitesse_avance_filt = consigne_vitesse_avance_recal;
			}
		}	
		
	// Calcul des erreurs de boucle pour les régulateurs
	erreur_vitesse_avance = consigne_vitesse_avance_filt - vitesse_avance_robot_filt;
	erreur_vitesse_rotation = consigne_vitesse_rotation_filt - vitesse_rotation_robot_filt;

}

// -----------------------------------------------------------------------------------------------------------------------
// Fonction qui regroupe tous les appels pour l'asservissement en fonction du mode de déplacement

void CAsservissement::CalculsMouvementsRobots(void)
{
  
  LectureCodeurCalculDistance();
  CalculXY();

  	switch (ModeAsservissement)
	{	
		case cMODE_DISTANCE_ANGLE :
			Generateur_trajectoire();
			asservissement();
		break;		
		
		case cMODE_XY_AUTO_A :
			Generateur_trajectoire();
			asservissement();
		break;
		
		case cMODE_XY_AUTO_B :
			Generateur_trajectoire();
			asservissement();
		break;
		
		case cMODE_XY_AUTO :
			Generateur_trajectoire();
			asservissement();
		break;
		
		case cMODE_XY_TETA :
			Generateur_trajectoire(); 		// Actions identiques au mode XY_AUTO dans un premier temps
			asservissement();				// Fait tomber le flag de convergence la première fois et le compteur_convergence est à 0		
			if (compteur_convergence >= 1)	// On est en mode XY_TETA, attendre la convergence pour basculer en mode distance angle /!\ on regarde le compteur et non convergence_conf afin de ne pas avoir deux fronts de convergence_conf
				{
					Reset_Pas_Cumules();							// Reset du Feedback
					distance_consigne = 0;							// Ne pas avancer ou reculer
					angle_consigne = TETA_consigne;					// Mais tourner jusqu'à l'angle TETA_consigne
					ModeAsservissement = cMODE_DISTANCE_ANGLE;		// On bascule de mode de fonctionnement
				}			
		break;
		
		//case cMODE_MANUEL :
			// Ne rien faire
		//break;
	}
}	

// ************************************************************************************
// Fonctions externes de calcul 
// ************************************************************************************

float CAsservissement::max(float Inp1, float Inp2)
{
	float Outp;

	if (Inp1 >= Inp2)		Outp=Inp1;
	else		Outp=Inp2;

	return Outp;
}

float CAsservissement::min(float Inp1, float Inp2)
{
	float Outp;

	if (Inp1 <= Inp2)		Outp=Inp1;
	else		Outp=Inp2;

	return Outp;
}

float CAsservissement::SAT(float Inp_max, float Inp_min, float Inp)
{
	return 	min(Inp_max,max(Inp,Inp_min));
}


float  CAsservissement::BornageAngle(float angle){
    float ret=0;

    if (angle > M_PI){
        ret = angle - (2.0*M_PI);
    }
    else if (angle <= (-1.0*M_PI)){
        ret = angle + (2*M_PI);
    }
    else{ // pas de saturation
        ret = angle;
    }

    return(ret);
}

// ************************************************************************************
// Fonctions externes de haut niveau pour demander des mouvements
// ************************************************************************************

// ----------------------------------------------------------
// Décodage de la trame et affectation des variables
void CAsservissement::CommandeMouvementXY(float x, float y)
{
	diag_blocage = 0;
	compteur_diag_blocage = 0;
	Reset_Pas_Cumules();	// Nouvelle commande -> nouvel origine relatif pour éviter les débordements après plusieurs appels ( à mettre avant l'écrasement des consignes)
	Initialisation_PID();	// Permet de ne pas avoir l'effet mémoire de la commande du mouvement précédent
	X_consigne = x;
	Y_consigne = y;
	ModeAsservissement = cMODE_XY_AUTO;	
}

// -------------------------------------
// Décodage de la trame et affectation des variables
void CAsservissement::CommandeMouvementDistanceAngle(float distance, float angle)
{
	diag_blocage = 0;
	compteur_diag_blocage = 0;
	Reset_Pas_Cumules();	// Nouvelle commande -> nouvel origine relatif pour éviter les débordements après plusieurs appels ( à mettre avant l'écrasement des consignes)
	Initialisation_PID();	// Permet de ne pas avoir l'effet mémoire de la commande du mouvement précédent
	distance_consigne = distance;
	angle_consigne = BornageAngle(angle);
	ModeAsservissement = cMODE_DISTANCE_ANGLE;
} 

// -------------------------------------
// Décodage de la trame et affectation des variables
void CAsservissement::CommandeManuelle(float cde_G, float cde_D)
{
	diag_blocage = 0;
	compteur_diag_blocage = 0;
	Application.m_roues.AdapteCommandeMoteur_G(cde_G);
	Application.m_roues.AdapteCommandeMoteur_D(cde_D);
	ModeAsservissement = cMODE_MANUEL;
}

// ----------------------------------------------------------
// Décodage de la trame et affectation des variables 
void CAsservissement::CommandeMouvementXY_A(float x, float y)
{
	diag_blocage = 0;
	compteur_diag_blocage = 0;
	Reset_Pas_Cumules();	// Nouvelle commande -> nouvel origine relatif pour éviter les débordements après plusieurs appels ( à mettre avant l'écrasement des consignes)
	Initialisation_PID();	// Permet de ne pas avoir l'effet mémoire de la commande du mouvement précédent
	X_consigne = x;
	Y_consigne = y;
	ModeAsservissement = cMODE_XY_AUTO_A;	
}

// ----------------------------------------------------------
// Décodage de la trame et affectation des variables
void CAsservissement::CommandeMouvementXY_B(float x, float y) 
{
	diag_blocage = 0;
	compteur_diag_blocage = 0;
	Reset_Pas_Cumules();	// Nouvelle commande -> nouvel origine relatif pour éviter les débordements après plusieurs appels ( à mettre avant l'écrasement des consignes)
	Initialisation_PID();	// Permet de ne pas avoir l'effet mémoire de la commande du mouvement précédent
	X_consigne = x;
	Y_consigne = y;
	ModeAsservissement = cMODE_XY_AUTO_B;	
}	


// -------------------------------------
// Décodage de la trame et affectation des variables
void CAsservissement::CommandeVitesseMouvement(float vit_avance, float vit_angle) 
{
	vitesse_avance_max = vit_avance;
	vitesse_rotation_max = vit_angle;
}

// ----------------------------------------------------------
// Décodage de la trame et affectation des variables
void CAsservissement::CommandeMouvementXY_TETA(float x, float y, float teta) 
{
	diag_blocage = 0;
	compteur_diag_blocage = 0;
	Reset_Pas_Cumules();	// Nouvelle commande -> nouvel origine relatif pour éviter les débordements après plusieurs appels ( à mettre avant l'écrasement des consignes)
	Initialisation_PID();	// Permet de ne pas avoir l'effet mémoire de la commande du mouvement précédent
	X_consigne = x;
	Y_consigne = y;
	TETA_consigne = teta;
	ModeAsservissement = cMODE_XY_TETA;
}
// -----------------------------------------------------------------------------------------------------------------------
// Fonction qui initialise la position du robot avec des valeurs données
void CAsservissement::setPosition_XYTeta(float x, float y, float teta)
{
  X_robot = x;
  X_robot_prec = x;
  Y_robot = y;
  Y_robot_prec = y;
  angle_robot = teta;
  angle_robot_prec=teta;
}	


