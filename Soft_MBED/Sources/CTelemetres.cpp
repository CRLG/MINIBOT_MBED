/*! \file CTelemetres.cpp
	\brief Classe qui contient les méthodes pour le dialogue avec la capteur ultrason SRF08
*/
#include "RessourcesHardware.h"
#include "CTelemetres.h"
// ------------------------------------------------------
// Variables globales du fichier

// ------------------------------------------------------
// Variables globales externes

// ------------------------------------------------------
// Prototypes des fonctions externes

// ------------------------------------------------------
// Prototypes des fonctions locales


//___________________________________________________________________________
 /*!
   \brief Constructeur

   \param --
   \return --
*/
CTelemetres::CTelemetres() 
{
 
}

//___________________________________________________________________________
 /*!
   \brief Destructeur

   \param --
   \return --
*/
CTelemetres::~CTelemetres() 
{

}



//___________________________________________________________________________
 /*!
   \brief Traitement

   \param --
   \return --
   \remark la gestion des capteurs a ultrasons doit se faire de manière séquentielle
   c'est à dire que la mesure de distance est lancée sur un capteur puis à la séquence
   d'après sur l'autre et ainsi de suite.
   La période d'appel de cette fonction doit être calibrée pour que l'écho ultrason de la 
   précédente mesure soit revenu avant de lancer une mesure sur un nouveau capteur.
   Cette méthode permet d'éviter les perturbations mutuelles d'un capteur sur l'autre.
*/
void CTelemetres::Traitement(void)
{
 // Todo : appliquer un filtrage / une calibration automatique / une comparaison entre capteurs
  // Loi de commande : 9.8mV/inch = 9.8mV/2.54mm
  // TODO : réactiver les moyennes et hystérisis
  // resultat en cm
  m_distance[0] = _Eana2.read() * COEF_TELEMETRE_ULTRASON;
  m_distance[1] = _Eana3.read() * COEF_TELEMETRE_ULTRASON;
  m_distance[2] = 0; //que 2 capteurs US sur MiniBot
  m_distance[3] = 0;

//  m_distance[0] = MoyenneGlissante_float(_Eana1.read() * COEF_TELEMETRE_ULTRASON, m_tabFiltUS_AV, NBRE_ECH_FILTRAGE_CAPTEURS_US);
//  m_distance[1] = MoyenneGlissante_float(_Eana2.read() * COEF_TELEMETRE_ULTRASON, m_tabFiltUS_AR, NBRE_ECH_FILTRAGE_CAPTEURS_US);
//  m_distance[2] = MoyenneGlissante_float(_Eana3.read() * COEF_TELEMETRE_ULTRASON, m_tabFiltUS_AR, NBRE_ECH_FILTRAGE_CAPTEURS_US);
//  m_distance[3] = MoyenneGlissante_float(_Eana4.read() * COEF_TELEMETRE_ULTRASON, m_tabFiltUS_AR, NBRE_ECH_FILTRAGE_CAPTEURS_US);

}





// END

