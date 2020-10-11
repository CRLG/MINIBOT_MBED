/*! \file CTelemetres.cpp
	\brief Classe qui contient les méthodes pour le dialogue avec la capteur ultrason SRF08
*/
#include "RessourcesHardware.h"
#include "CTelemetres.h"
#include "ConfigSpecifiqueCoupe.h"
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
float CTelemetres::getDistanceAVG()
{
    return m_distance[INDEX_TELEMETRE_AV];
}

float CTelemetres::getDistanceAVD()
{
    return m_distance[INDEX_TELEMETRE_AV];
}

float CTelemetres::getDistanceARG()
{
    return m_distance[INDEX_TELEMETRE_AR];
}

float CTelemetres::getDistanceARD()
{
    return m_distance[INDEX_TELEMETRE_AR];
}

//___________________________________________________________________________
 /*!
   \brief Traitement

   \param --
   \return --
   \remark
*/
#define COEF_TELEMETRE_ULTRASON (3.3 * 259.183)
void CTelemetres::Traitement(void)
{
    // Todo : appliquer un filtrage / une calibration automatique / une comparaison entre capteurs
      // Loi de commande : 9.8mV/inch = 9.8mV/2.54mm
      // TODO : réactiver les moyennes
      // resultat en cm
      m_distance[0] = _Eana2.read() * COEF_TELEMETRE_ULTRASON;
      m_distance[1] = _Eana3.read() * COEF_TELEMETRE_ULTRASON;
  }


  // _____________________________________________________
  /*!
     \brief Calcul la moyenne glissante sur un nombre donnÃ© d'Ã©chantillon pour des donnÃ©es de type char
      \param currentVal : le dernier echantillon recu
      \param *old_samples : le tableau des Ã©chantillons prÃ©cÃ©dents
      \param samplesNumbers : le nombre d'echantillons pour le calcul la moyenne glissante
      \return La valeur moyenne entre le dernier echantillon recu et les (nbreEchantillonsMoyenne)  precedents echantillons

      \remarks La moyenne se fait sur "samplesNumbers" valeurs :
              - L'echantillons courant currentVal
              - Les (samplesNumbers-1) echantillons precedents
              Le tableau old_sanmples doit donc avoir une taille de (samplesNumber - 1) valeurs
  */
  float CTelemetres::MoyenneGlissante_float(float currentVal, float *buf_oldSamples, unsigned int samplesNumbers)
  {
    float moy=currentVal;
    int i=0;  // Attention : doit Ãªtre un "int" et non un "unsigned int" Ã  cause du test de fin dans le "for"

    // Traite tous les Ã©chantillons sauf le 1er (index 0 du tableau) qui est un cas particulier
    for (i=(samplesNumbers-2); i>0; i--) {
        moy = moy + buf_oldSamples[i];
        buf_oldSamples[i] = buf_oldSamples[i-1];
    }

    // Cas particulier pour la 1Ã¨re case du tableau oÃ¹ la nouvelle valeur ne provient pas de l'index prÃ©cÃ©dent du tableau mais du nouvel Ã©chantillon
    moy = moy + buf_oldSamples[0];
    buf_oldSamples[0] = currentVal;

    moy = moy / (float)samplesNumbers;

    return(moy);
  }


  // _____________________________________________________
  /*!
     \brief Gestion d'un hysterisis
      \param vin le signal d'entree
      \param *etat la valeur precedente de la sortie
      \param swapOff le seuil de basculement vers inactif
      \param swapOn le seuil de basculement vers actif
      \param valOff la valeur de la sortie a l'etat inactif
      \param valOn la valeur de la sortie a l'etat actif

      \return la valeur de la sortie apres passage dans l'hysterisis

      \remarks
  */
  unsigned char CTelemetres::Hysterisis (float vin, unsigned char *etat, float swapOff, float swapOn, unsigned char valOff, unsigned char valOn)
  {
      if (vin <= swapOff) { // seuil bas
          *etat = valOff;
      } else if (vin >= swapOn) { // seuil haut
          *etat = valOn;
      } else {
          //on ne fait rien
      }
      if (*etat == 0xFF) { // cas d'init
          *etat = valOff;
      } // else on ne fait rien
      return *etat;
  }

// END


