/*
 * File: ModeleRobot.c
 *
 * Real-Time Workshop code generated for Simulink model ModeleRobot.
 *
 * Model version                        : 1.1337
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Fri May 15 23:20:29 2015
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Fri May 15 23:20:29 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objective: Efficiency
 * Validation result: Passed (9), Warning (1), Error (0)
 */

#include "ModeleRobot.h"
#include "ModeleRobot_private.h"

/* Named constants for Stateflow: '<Root>/COMPORTEMENT' */
#define ModeleR_IN_FIN_REPOS_ACTIONNEUR (1)
#define ModeleR_IN_GOTO_BAS_DES_MARCHES (1)
#define ModeleRobot_IN_ACTION_00       (1)
#define ModeleRobot_IN_ACTION_01       (2)
#define ModeleRobot_IN_ACTION_010      (1)
#define ModeleRobot_IN_ACTION_012      (2)
#define ModeleRobot_IN_ACTION_013      (3)
#define ModeleRobot_IN_ACTION_014      (4)
#define ModeleRobot_IN_ACTION_015      (5)
#define ModeleRobot_IN_ACTION_02       (3)
#define ModeleRobot_IN_ACTION_02_p     (6)
#define ModeleRobot_IN_ACTION_03       (4)
#define ModeleRobot_IN_ACTION_03_p     (7)
#define ModeleRobot_IN_ACTION_04       (5)
#define ModeleRobot_IN_ACTION_04_p     (8)
#define ModeleRobot_IN_ACTION_05       (6)
#define ModeleRobot_IN_ACTION_05_p     (9)
#define ModeleRobot_IN_ACTION_06       (7)
#define ModeleRobot_IN_ACTION_06_p     (10)
#define ModeleRobot_IN_ACTION_07       (8)
#define ModeleRobot_IN_ACTION_07_p     (11)
#define ModeleRobot_IN_ACTION_08       (12)
#define ModeleRobot_IN_ACTION_09       (13)
#define ModeleRobot_IN_ATTENTE_TIRETTE (1)
#define ModeleRobot_IN_DETECT_OBSTACLE (1)
#define ModeleRobot_IN_EQUIPE_1        (1)
#define ModeleRobot_IN_EQUIPE_2        (2)
#define ModeleRobot_IN_EVITEMENT       (9)
#define ModeleRobot_IN_EVITEMENT1      (10)
#define ModeleRobot_IN_FIN_MATCH       (2)
#define ModeleRobot_IN_FIN_MATCH_01    (1)
#define ModeleRobot_IN_FIN_MATCH_02    (2)
#define ModeleRobot_IN_FIN_MATCH_03    (3)
#define ModeleRobot_IN_FIN_MATCH_04    (4)
#define ModeleRobot_IN_FIN_MATCH_05    (5)
#define ModeleRobot_IN_HOMOLO_FIN      (11)
#define ModeleRobot_IN_INIT            (1)
#define ModeleRobot_IN_INIT1           (2)
#define ModeleRobot_IN_INIT_STRATEGIE  (2)
#define ModeleRobot_IN_MATCH           (3)
#define ModeleRobot_IN_MONTE_MARCHE    (3)
#define ModeleRobot_IN_NO_ACTIVE_CHILD (0)
#define ModeleRobot_IN_REPOS_SERVOS    (2)
#define ModeleRobot_IN_STRATEGIE1      (1)
#define ModeleRobot_IN_TEST_ACT_3      (3)
#define ModeleRobot_IN_TEST_ACT_4      (4)
#define ModeleRobot_IN_TEST_ACT_5      (5)
#define ModeleRobot_IN_TEST_ACT_6      (6)
#define ModeleRobot_IN_TEST_ACT_FIN    (7)

/* Block signals (auto storage) */
BlockIO_ModeleRobot ModeleRobot_B;

/* Block states (auto storage) */
D_Work_ModeleRobot ModeleRobot_DWork;

/* External inputs (root inport signals with auto storage) */
ExternalInputs_ModeleRobot ModeleRobot_U;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_ModeleRobot ModeleRobot_Y;

/* Forward declaration for local functions */
static void enter_internal_COMPORTEMENT_ROB(void);
static void enter_atomic_GOTO_BAS_DES_MARCH(void);
static void enter_internal_GOTO_BAS_DES_MAR(void);
static void Mod_enter_internal_MONTE_MARCHE(void);
static void Model_enter_internal_STRATEGIE1(void);
static void ModeleRobot_ATTENTE_TIRETTE(void);
static void ModeleRobot_FIN_MATCH(void);

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void enter_internal_COMPORTEMENT_ROB(void)
{
  /* Transition: '<S1>:1264' */
  /* Entry 'ATTENTE_TIRETTE': '<S1>:1005' */
  ModeleRobot_DWork.is_COMPORTEMENT_ROBOT = (uint8_T)
    ModeleRobot_IN_ATTENTE_TIRETTE;

  /* Entry 'ACTIONNEURS_REPOS': '<S1>:1006' */
  ModeleRobot_DWork.is_active_ACTIONNEURS_REPOS = 1U;

  /* Transition: '<S1>:1007' */
  /* Entry 'REPOS_SERVOS': '<S1>:1009' */
  ModeleRobot_DWork.is_ACTIONNEURS_REPOS = (uint8_T)ModeleRobot_IN_REPOS_SERVOS;

  /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
  /* Transition: '<S1>:1301' */
  ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
  ModeleRobot_B.CommandeManuelleG = 0.0;
  ModeleRobot_B.CommandeManuelleD = 0.0;

  /* Graphical Function 'setServoSpeed': '<S1>:3943' */
  /* Transition: '<S1>:3945' */
  ModeleRobot_B.SpdServo[(int32_T)(ModeleRobot_P.SFunction_p9 - 1.0)] =
    ModeleRobot_P.SFunction_p4;

  /* Graphical Function 'setServoSpeed': '<S1>:3943' */
  /* Transition: '<S1>:3945' */
  ModeleRobot_B.SpdServo[(int32_T)(ModeleRobot_P.SFunction_p6 - 1.0)] =
    ModeleRobot_P.SFunction_p4;

  /* Graphical Function 'setServoSpeed': '<S1>:3943' */
  /* Transition: '<S1>:3945' */
  ModeleRobot_B.SpdServo[(int32_T)(ModeleRobot_P.SFunction_p13 - 1.0)] =
    ModeleRobot_P.SFunction_p4;

  /* Graphical Function 'setServo': '<S1>:3938' */
  /* Transition: '<S1>:3940' */
  ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p9 - 1.0)] =
    ModeleRobot_P.SFunction_p10;

  /* Graphical Function 'setServo': '<S1>:3938' */
  /* Transition: '<S1>:3940' */
  ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p6 - 1.0)] =
    ModeleRobot_P.SFunction_p7;

  /* Graphical Function 'setServo': '<S1>:3938' */
  /* Transition: '<S1>:3940' */
  ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p13 - 1.0)] =
    ModeleRobot_P.SFunction_p14;
  ModeleRobot_DWork.TempoInit = 0.0;

  /* Entry 'CHOIX_EQUIPE': '<S1>:1011' */
  ModeleRobot_DWork.is_active_CHOIX_EQUIPE = 1U;

  /* Transition: '<S1>:1012' */
  /* Entry 'EQUIPE_1': '<S1>:1016' */
  ModeleRobot_DWork.is_CHOIX_EQUIPE = (uint8_T)ModeleRobot_IN_EQUIPE_1;
  ModeleRobot_B.EtatLed1 = 1.0;
  ModeleRobot_B.EtatLed2 = 0.0;

  /* Entry 'RECALAGE': '<S1>:1017' */
  ModeleRobot_DWork.is_active_RECALAGE = 1U;

  /* TODO: a faire si on veut respecter les coordonnees reelles du terrain */
  /* Transition: '<S1>:1371' */
  /* Entry 'INIT': '<S1>:1027' */
  ModeleRobot_DWork.is_RECALAGE = (uint8_T)ModeleRobot_IN_INIT;

  /* Entry 'TESTS_ACTIONNEUR': '<S1>:1036' */
  ModeleRobot_DWork.is_active_TESTS_ACTIONNEUR = 1U;
  ModeleRobot_DWork.TempoTestActionneurs = 0.0;

  /* Transition: '<S1>:1064' */
  /* Entry 'INIT': '<S1>:1109' */
  ModeleRobot_DWork.is_TESTS_ACTIONNEUR = (uint8_T)ModeleRobot_IN_INIT;

  /* Entry 'TESTS_CAPTEURS': '<S1>:3093' */
  ModeleRobot_DWork.is_active_TESTS_CAPTEURS = 1U;
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void enter_atomic_GOTO_BAS_DES_MARCH(void)
{
  /* Entry 'GOTO_BAS_DES_MARCHES': '<S1>:3463' */
  ModeleRobot_DWork.is_STRATEGIE1 = (uint8_T)ModeleR_IN_GOTO_BAS_DES_MARCHES;
  ModeleRobot_DWork.was_STRATEGIE1 = (uint8_T)ModeleR_IN_GOTO_BAS_DES_MARCHES;

  /* Tempo=0; */
  ModeleRobot_DWork.inhibeObstacle = 0.0;
  ModeleRobot_DWork.Etape_GotoMarche = 1.0;
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void enter_internal_GOTO_BAS_DES_MAR(void)
{
  switch (ModeleRobot_DWork.was_GOTO_BAS_DES_MARCHES) {
   case ModeleRobot_IN_ACTION_00:
    /* Entry 'ACTION_00': '<S1>:4090' */
    ModeleRobot_DWork.is_GOTO_BAS_DES_MARCHES = (uint8_T)
      ModeleRobot_IN_ACTION_00;
    ModeleRobot_DWork.was_GOTO_BAS_DES_MARCHES = (uint8_T)
      ModeleRobot_IN_ACTION_00;
    ModeleRobot_DWork.Tempo2 = 0.0;
    break;

   case ModeleRobot_IN_ACTION_01:
    /* Entry 'ACTION_01': '<S1>:3949' */
    ModeleRobot_DWork.is_GOTO_BAS_DES_MARCHES = (uint8_T)
      ModeleRobot_IN_ACTION_01;
    ModeleRobot_DWork.was_GOTO_BAS_DES_MARCHES = (uint8_T)
      ModeleRobot_IN_ACTION_01;

    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = 100.0;
    ModeleRobot_B.CommandeManuelleD = 100.0;
    break;

   case ModeleRobot_IN_ACTION_02:
    /* Entry 'ACTION_02': '<S1>:3951' */
    ModeleRobot_DWork.is_GOTO_BAS_DES_MARCHES = (uint8_T)
      ModeleRobot_IN_ACTION_02;
    ModeleRobot_DWork.was_GOTO_BAS_DES_MARCHES = (uint8_T)
      ModeleRobot_IN_ACTION_02;
    ModeleRobot_DWork.Tempo2 = 0.0;

    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = 100.0;
    ModeleRobot_B.CommandeManuelleD = 100.0;
    break;

   case ModeleRobot_IN_ACTION_03:
    /* Entry 'ACTION_03': '<S1>:3954' */
    ModeleRobot_DWork.is_GOTO_BAS_DES_MARCHES = (uint8_T)
      ModeleRobot_IN_ACTION_03;
    ModeleRobot_DWork.was_GOTO_BAS_DES_MARCHES = (uint8_T)
      ModeleRobot_IN_ACTION_03;
    ModeleRobot_DWork.Tempo = 0.0;

    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = 0.0;
    ModeleRobot_B.CommandeManuelleD = 0.0;

    /* Graphical Function 'setServo': '<S1>:3938' */
    /* Transition: '<S1>:3940' */
    ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p12 - 1.0)] = 130.0;
    break;

   case ModeleRobot_IN_ACTION_04:
    /* Entry 'ACTION_04': '<S1>:3956' */
    ModeleRobot_DWork.is_GOTO_BAS_DES_MARCHES = (uint8_T)
      ModeleRobot_IN_ACTION_04;
    ModeleRobot_DWork.was_GOTO_BAS_DES_MARCHES = (uint8_T)
      ModeleRobot_IN_ACTION_04;

    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = 0.0;
    ModeleRobot_B.CommandeManuelleD = 0.0;
    break;

   case ModeleRobot_IN_ACTION_05:
    /* Entry 'ACTION_05': '<S1>:3962' */
    ModeleRobot_DWork.is_GOTO_BAS_DES_MARCHES = (uint8_T)
      ModeleRobot_IN_ACTION_05;
    ModeleRobot_DWork.was_GOTO_BAS_DES_MARCHES = (uint8_T)
      ModeleRobot_IN_ACTION_05;
    ModeleRobot_DWork.Tempo = 0.0;

    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = 100.0;
    ModeleRobot_B.CommandeManuelleD = 0.0;
    break;

   case ModeleRobot_IN_ACTION_06:
    /* Entry 'ACTION_06': '<S1>:3965' */
    ModeleRobot_DWork.is_GOTO_BAS_DES_MARCHES = (uint8_T)
      ModeleRobot_IN_ACTION_06;
    ModeleRobot_DWork.was_GOTO_BAS_DES_MARCHES = (uint8_T)
      ModeleRobot_IN_ACTION_06;
    ModeleRobot_DWork.Tempo = 0.0;

    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = 0.0;
    ModeleRobot_B.CommandeManuelleD = 100.0;
    break;

   case ModeleRobot_IN_ACTION_07:
    /* Entry 'ACTION_07': '<S1>:4080' */
    ModeleRobot_DWork.is_GOTO_BAS_DES_MARCHES = (uint8_T)
      ModeleRobot_IN_ACTION_07;
    ModeleRobot_DWork.was_GOTO_BAS_DES_MARCHES = (uint8_T)
      ModeleRobot_IN_ACTION_07;
    ModeleRobot_DWork.Tempo = 0.0;

    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = 100.0;
    ModeleRobot_B.CommandeManuelleD = 100.0;

    /* Graphical Function 'setServo': '<S1>:3938' */
    /* Transition: '<S1>:3940' */
    ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p12 - 1.0)] = 115.0;
    break;

   case ModeleRobot_IN_EVITEMENT:
    /* Entry 'EVITEMENT': '<S1>:4084' */
    ModeleRobot_DWork.is_GOTO_BAS_DES_MARCHES = (uint8_T)
      ModeleRobot_IN_EVITEMENT;
    ModeleRobot_DWork.was_GOTO_BAS_DES_MARCHES = (uint8_T)
      ModeleRobot_IN_EVITEMENT;

    /* Dans le cas d'un mouvement distance on calcule la distance parcourue pour repartir
       avec une consigne adapt */
    /* Transition: '<S1>:4085' */
    /* Entry 'DETECT_OBSTACLE': '<S1>:4087' */
    ModeleRobot_DWork.is_EVITEMENT = (uint8_T)ModeleRobot_IN_DETECT_OBSTACLE;
    ModeleRobot_DWork.local_Tempo = 0.0;

    /* Mouvement_ArretBrutal(); // Arrête tout pendant un instant mais bug */
    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = 0.0;
    ModeleRobot_B.CommandeManuelleD = 0.0;

    /* Graphical Function 'CommandeLEDS': '<S1>:1339' */
    /* Transition: '<S1>:1341' */
    ModeleRobot_B.EtatLed1 = 1.0;
    ModeleRobot_B.EtatLed2 = 0.0;
    ModeleRobot_B.EtatLed3 = 0.0;
    ModeleRobot_B.EtatLed4 = 0.0;
    break;

   case ModeleRobot_IN_EVITEMENT1:
    /* Entry 'EVITEMENT1': '<S1>:4093' */
    ModeleRobot_DWork.is_GOTO_BAS_DES_MARCHES = (uint8_T)
      ModeleRobot_IN_EVITEMENT1;
    ModeleRobot_DWork.was_GOTO_BAS_DES_MARCHES = (uint8_T)
      ModeleRobot_IN_EVITEMENT1;

    /* Dans le cas d'un mouvement distance on calcule la distance parcourue pour repartir
       avec une consigne adapt */
    /* Transition: '<S1>:4094' */
    /* Entry 'DETECT_OBSTACLE': '<S1>:4095' */
    ModeleRobot_DWork.is_EVITEMENT1 = (uint8_T)ModeleRobot_IN_DETECT_OBSTACLE;
    ModeleRobot_DWork.local_Tempo = 0.0;

    /* Mouvement_ArretBrutal(); // Arrête tout pendant un instant mais bug */
    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = 0.0;
    ModeleRobot_B.CommandeManuelleD = 0.0;

    /* Graphical Function 'CommandeLEDS': '<S1>:1339' */
    /* Transition: '<S1>:1341' */
    ModeleRobot_B.EtatLed1 = 1.0;
    ModeleRobot_B.EtatLed2 = 0.0;
    ModeleRobot_B.EtatLed3 = 0.0;
    ModeleRobot_B.EtatLed4 = 0.0;
    break;

   case ModeleRobot_IN_HOMOLO_FIN:
    /* Entry 'HOMOLO_FIN': '<S1>:3510' */
    ModeleRobot_DWork.is_GOTO_BAS_DES_MARCHES = (uint8_T)
      ModeleRobot_IN_HOMOLO_FIN;
    ModeleRobot_DWork.was_GOTO_BAS_DES_MARCHES = (uint8_T)
      ModeleRobot_IN_HOMOLO_FIN;

    /*  Fin - en cours de debuggage on ne sort pour l'instant pas de l'homologation */
    ModeleRobot_DWork.Etape_GotoMarche = 0.0;
    break;

   default:
    /* Transition: '<S1>:3935' */
    /* Entry 'ACTION_00': '<S1>:4090' */
    ModeleRobot_DWork.is_GOTO_BAS_DES_MARCHES = (uint8_T)
      ModeleRobot_IN_ACTION_00;
    ModeleRobot_DWork.was_GOTO_BAS_DES_MARCHES = (uint8_T)
      ModeleRobot_IN_ACTION_00;
    ModeleRobot_DWork.Tempo2 = 0.0;
    break;
  }
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void Mod_enter_internal_MONTE_MARCHE(void)
{
  switch (ModeleRobot_DWork.was_MONTE_MARCHE) {
   case ModeleRobot_IN_ACTION_010:
    /* Entry 'ACTION_010': '<S1>:4054' */
    ModeleRobot_DWork.is_MONTE_MARCHE = (uint8_T)ModeleRobot_IN_ACTION_010;
    ModeleRobot_DWork.was_MONTE_MARCHE = (uint8_T)ModeleRobot_IN_ACTION_010;
    ModeleRobot_DWork.Tempo = 0.0;

    /* Graphical Function 'setServo': '<S1>:3938' */
    /* Transition: '<S1>:3940' */
    ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p12 - 1.0)] = 115.0;
    break;

   case ModeleRobot_IN_ACTION_012:
    /* Entry 'ACTION_012': '<S1>:4061' */
    ModeleRobot_DWork.is_MONTE_MARCHE = (uint8_T)ModeleRobot_IN_ACTION_012;
    ModeleRobot_DWork.was_MONTE_MARCHE = (uint8_T)ModeleRobot_IN_ACTION_012;
    ModeleRobot_DWork.Tempo = 0.0;

    /* Graphical Function 'setServo': '<S1>:3938' */
    /* Transition: '<S1>:3940' */
    ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p12 - 1.0)] = 115.0;

    /* setServo(SERVO_INCLINAISON, SERVO_INCLINAISON_DROIT); */
    break;

   case ModeleRobot_IN_ACTION_013:
    /* Entry 'ACTION_013': '<S1>:4074' */
    ModeleRobot_DWork.is_MONTE_MARCHE = (uint8_T)ModeleRobot_IN_ACTION_013;
    ModeleRobot_DWork.was_MONTE_MARCHE = (uint8_T)ModeleRobot_IN_ACTION_013;

    /* Tempo=0; */
    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = 0.0;
    ModeleRobot_B.CommandeManuelleD = 0.0;
    break;

   case ModeleRobot_IN_ACTION_014:
    /* Entry 'ACTION_014': '<S1>:4075' */
    ModeleRobot_DWork.is_MONTE_MARCHE = (uint8_T)ModeleRobot_IN_ACTION_014;
    ModeleRobot_DWork.was_MONTE_MARCHE = (uint8_T)ModeleRobot_IN_ACTION_014;
    ModeleRobot_DWork.Tempo = 0.0;

    /* Graphical Function 'setServo': '<S1>:3938' */
    /* Transition: '<S1>:3940' */
    ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p12 - 1.0)] = 130.0;
    break;

   case ModeleRobot_IN_ACTION_015:
    /* Entry 'ACTION_015': '<S1>:4077' */
    ModeleRobot_DWork.is_MONTE_MARCHE = (uint8_T)ModeleRobot_IN_ACTION_015;
    ModeleRobot_DWork.was_MONTE_MARCHE = (uint8_T)ModeleRobot_IN_ACTION_015;

    /* Tempo=0; */
    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = 70.0;
    ModeleRobot_B.CommandeManuelleD = 71.0;
    break;

   case ModeleRobot_IN_ACTION_02_p:
    /* Entry 'ACTION_02': '<S1>:4009' */
    ModeleRobot_DWork.is_MONTE_MARCHE = (uint8_T)ModeleRobot_IN_ACTION_02_p;
    ModeleRobot_DWork.was_MONTE_MARCHE = (uint8_T)ModeleRobot_IN_ACTION_02_p;

    /* Tempo=0; */
    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = 70.0;
    ModeleRobot_B.CommandeManuelleD = 70.0;

    /* Graphical Function 'CommandeLEDS': '<S1>:1339' */
    /* Transition: '<S1>:1341' */
    ModeleRobot_B.EtatLed1 = 1.0;
    ModeleRobot_B.EtatLed2 = 1.0;
    ModeleRobot_B.EtatLed3 = 1.0;
    ModeleRobot_B.EtatLed4 = 1.0;
    break;

   case ModeleRobot_IN_ACTION_03_p:
    /* Entry 'ACTION_03': '<S1>:4015' */
    ModeleRobot_DWork.is_MONTE_MARCHE = (uint8_T)ModeleRobot_IN_ACTION_03_p;
    ModeleRobot_DWork.was_MONTE_MARCHE = (uint8_T)ModeleRobot_IN_ACTION_03_p;
    ModeleRobot_DWork.Tempo = 0.0;

    /* Graphical Function 'setServo': '<S1>:3938' */
    /* Transition: '<S1>:3940' */
    ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p13 - 1.0)] =
      ModeleRobot_P.SFunction_p15;

    /* Graphical Function 'CommandeLEDS': '<S1>:1339' */
    /* Transition: '<S1>:1341' */
    ModeleRobot_B.EtatLed1 = 1.0;
    ModeleRobot_B.EtatLed2 = 0.0;
    ModeleRobot_B.EtatLed3 = 1.0;
    ModeleRobot_B.EtatLed4 = 1.0;
    break;

   case ModeleRobot_IN_ACTION_04_p:
    /* Entry 'ACTION_04': '<S1>:4028' */
    ModeleRobot_DWork.is_MONTE_MARCHE = (uint8_T)ModeleRobot_IN_ACTION_04_p;
    ModeleRobot_DWork.was_MONTE_MARCHE = (uint8_T)ModeleRobot_IN_ACTION_04_p;
    ModeleRobot_DWork.Tempo = 0.0;

    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = 0.0;
    ModeleRobot_B.CommandeManuelleD = 0.0;

    /* Graphical Function 'setServo': '<S1>:3938' */
    /* Transition: '<S1>:3940' */
    ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p6 - 1.0)] =
      ModeleRobot_P.SFunction_p8;

    /* Graphical Function 'CommandeLEDS': '<S1>:1339' */
    /* Transition: '<S1>:1341' */
    ModeleRobot_B.EtatLed1 = 1.0;
    ModeleRobot_B.EtatLed2 = 0.0;
    ModeleRobot_B.EtatLed3 = 0.0;
    ModeleRobot_B.EtatLed4 = 1.0;
    break;

   case ModeleRobot_IN_ACTION_05_p:
    /* Entry 'ACTION_05': '<S1>:4033' */
    ModeleRobot_DWork.is_MONTE_MARCHE = (uint8_T)ModeleRobot_IN_ACTION_05_p;
    ModeleRobot_DWork.was_MONTE_MARCHE = (uint8_T)ModeleRobot_IN_ACTION_05_p;
    ModeleRobot_DWork.Tempo = 0.0;

    /* Graphical Function 'setServo': '<S1>:3938' */
    /* Transition: '<S1>:3940' */
    ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p6 - 1.0)] =
      ModeleRobot_P.SFunction_p7;

    /* Graphical Function 'CommandeLEDS': '<S1>:1339' */
    /* Transition: '<S1>:1341' */
    ModeleRobot_B.EtatLed1 = 1.0;
    ModeleRobot_B.EtatLed2 = 0.0;
    ModeleRobot_B.EtatLed3 = 0.0;
    ModeleRobot_B.EtatLed4 = 0.0;
    break;

   case ModeleRobot_IN_ACTION_06_p:
    /* Entry 'ACTION_06': '<S1>:4038' */
    ModeleRobot_DWork.is_MONTE_MARCHE = (uint8_T)ModeleRobot_IN_ACTION_06_p;
    ModeleRobot_DWork.was_MONTE_MARCHE = (uint8_T)ModeleRobot_IN_ACTION_06_p;
    ModeleRobot_DWork.Tempo = 0.0;

    /* Graphical Function 'setServo': '<S1>:3938' */
    /* Transition: '<S1>:3940' */
    ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p9 - 1.0)] =
      ModeleRobot_P.SFunction_p11;
    break;

   case ModeleRobot_IN_ACTION_07_p:
    /* Entry 'ACTION_07': '<S1>:4043' */
    ModeleRobot_DWork.is_MONTE_MARCHE = (uint8_T)ModeleRobot_IN_ACTION_07_p;
    ModeleRobot_DWork.was_MONTE_MARCHE = (uint8_T)ModeleRobot_IN_ACTION_07_p;
    ModeleRobot_DWork.Tempo = 0.0;

    /* Graphical Function 'setServo': '<S1>:3938' */
    /* Transition: '<S1>:3940' */
    ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p9 - 1.0)] =
      ModeleRobot_P.SFunction_p10;

    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = 68.0;
    ModeleRobot_B.CommandeManuelleD = 70.0;
    break;

   case ModeleRobot_IN_ACTION_08:
    /* Entry 'ACTION_08': '<S1>:4044' */
    ModeleRobot_DWork.is_MONTE_MARCHE = (uint8_T)ModeleRobot_IN_ACTION_08;
    ModeleRobot_DWork.was_MONTE_MARCHE = (uint8_T)ModeleRobot_IN_ACTION_08;
    ModeleRobot_DWork.Tempo = 0.0;

    /* setServo(SERVO_DOIGT, 115); */
    /* Graphical Function 'setServo': '<S1>:3938' */
    /* Transition: '<S1>:3940' */
    ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p13 - 1.0)] =
      ModeleRobot_P.SFunction_p14;
    break;

   case ModeleRobot_IN_ACTION_09:
    /* Entry 'ACTION_09': '<S1>:4047' */
    ModeleRobot_DWork.is_MONTE_MARCHE = (uint8_T)ModeleRobot_IN_ACTION_09;
    ModeleRobot_DWork.was_MONTE_MARCHE = (uint8_T)ModeleRobot_IN_ACTION_09;
    ModeleRobot_DWork.Tempo = 0.0;

    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = 0.0;
    ModeleRobot_B.CommandeManuelleD = 0.0;
    break;

   default:
    /* Transition: '<S1>:4011' */
    /* Entry 'ACTION_02': '<S1>:4009' */
    ModeleRobot_DWork.is_MONTE_MARCHE = (uint8_T)ModeleRobot_IN_ACTION_02_p;
    ModeleRobot_DWork.was_MONTE_MARCHE = (uint8_T)ModeleRobot_IN_ACTION_02_p;

    /* Tempo=0; */
    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = 70.0;
    ModeleRobot_B.CommandeManuelleD = 70.0;

    /* Graphical Function 'CommandeLEDS': '<S1>:1339' */
    /* Transition: '<S1>:1341' */
    ModeleRobot_B.EtatLed1 = 1.0;
    ModeleRobot_B.EtatLed2 = 1.0;
    ModeleRobot_B.EtatLed3 = 1.0;
    ModeleRobot_B.EtatLed4 = 1.0;
    break;
  }
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void Model_enter_internal_STRATEGIE1(void)
{
  switch (ModeleRobot_DWork.was_STRATEGIE1) {
   case ModeleR_IN_GOTO_BAS_DES_MARCHES:
    enter_atomic_GOTO_BAS_DES_MARCH();
    enter_internal_GOTO_BAS_DES_MAR();
    break;

   case ModeleRobot_IN_INIT_STRATEGIE:
    /* Entry 'INIT_STRATEGIE': '<S1>:1128' */
    ModeleRobot_DWork.is_STRATEGIE1 = (uint8_T)ModeleRobot_IN_INIT_STRATEGIE;
    ModeleRobot_DWork.was_STRATEGIE1 = (uint8_T)ModeleRobot_IN_INIT_STRATEGIE;
    ModeleRobot_B.ConsigneVitesseAngle = 3.0;

    /*  [rad/sec] */
    ModeleRobot_B.ConsigneVitesseDistance = 80.0;

    /* [cm/sec] */
    ModeleRobot_DWork.inhibeObstacle = 0.0;
    break;

   case ModeleRobot_IN_MONTE_MARCHE:
    /* Entry 'MONTE_MARCHE': '<S1>:3983' */
    ModeleRobot_DWork.is_STRATEGIE1 = (uint8_T)ModeleRobot_IN_MONTE_MARCHE;
    ModeleRobot_DWork.was_STRATEGIE1 = (uint8_T)ModeleRobot_IN_MONTE_MARCHE;
    ModeleRobot_DWork.Tempo = 0.0;
    ModeleRobot_DWork.inhibeObstacle = 1.0;
    Mod_enter_internal_MONTE_MARCHE();
    break;

   default:
    /* Transition: '<S1>:1125' */
    /* Entry 'INIT_STRATEGIE': '<S1>:1128' */
    ModeleRobot_DWork.is_STRATEGIE1 = (uint8_T)ModeleRobot_IN_INIT_STRATEGIE;
    ModeleRobot_DWork.was_STRATEGIE1 = (uint8_T)ModeleRobot_IN_INIT_STRATEGIE;
    ModeleRobot_B.ConsigneVitesseAngle = 3.0;

    /*  [rad/sec] */
    ModeleRobot_B.ConsigneVitesseDistance = 80.0;

    /* [cm/sec] */
    ModeleRobot_DWork.inhibeObstacle = 0.0;
    break;
  }
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void ModeleRobot_ATTENTE_TIRETTE(void)
{
  /* During 'ATTENTE_TIRETTE': '<S1>:1005' */
  if (ModeleRobot_U.IN_Tirette != 0.0) {
    /* Transition: '<S1>:1265' */
    /* Exit 'TESTS_CAPTEURS': '<S1>:3093' */
    ModeleRobot_DWork.is_active_TESTS_CAPTEURS = 0U;

    /* Exit 'INIT': '<S1>:1109' */
    ModeleRobot_DWork.is_TESTS_ACTIONNEUR = (uint8_T)
      ModeleRobot_IN_NO_ACTIVE_CHILD;

    /* Exit 'INIT1': '<S1>:3674' */
    /* Exit 'TEST_ACT_3': '<S1>:3802' */
    /* Exit 'TEST_ACT_4': '<S1>:3805' */
    /* Exit 'TEST_ACT_5': '<S1>:3928' */
    /* Exit 'TEST_ACT_6': '<S1>:3932' */
    /* Exit 'TEST_ACT_FIN': '<S1>:1515' */
    /* Exit 'TESTS_ACTIONNEUR': '<S1>:1036' */
    ModeleRobot_DWork.is_active_TESTS_ACTIONNEUR = 0U;

    /* Exit 'INIT': '<S1>:1027' */
    ModeleRobot_DWork.is_RECALAGE = (uint8_T)ModeleRobot_IN_NO_ACTIVE_CHILD;

    /* Exit 'RECALAGE': '<S1>:1017' */
    ModeleRobot_DWork.is_active_RECALAGE = 0U;

    /* Exit 'EQUIPE_1': '<S1>:1016' */
    ModeleRobot_DWork.is_CHOIX_EQUIPE = (uint8_T)ModeleRobot_IN_NO_ACTIVE_CHILD;

    /* Exit 'EQUIPE_2': '<S1>:1015' */
    /* Exit 'CHOIX_EQUIPE': '<S1>:1011' */
    ModeleRobot_DWork.CouleurEquipe_memo = ModeleRobot_U.IN_CouleurEquipe;
    ModeleRobot_DWork.is_active_CHOIX_EQUIPE = 0U;

    /* Exit 'FIN_REPOS_ACTIONNEUR': '<S1>:3692' */
    ModeleRobot_DWork.is_ACTIONNEURS_REPOS = (uint8_T)
      ModeleRobot_IN_NO_ACTIVE_CHILD;

    /* Exit 'REPOS_SERVOS': '<S1>:1009' */
    /* Exit 'ACTIONNEURS_REPOS': '<S1>:1006' */
    ModeleRobot_DWork.is_active_ACTIONNEURS_REPOS = 0U;

    /* Exit 'ATTENTE_TIRETTE': '<S1>:1005' */
    /* Entry 'MATCH': '<S1>:1117' */
    ModeleRobot_DWork.is_COMPORTEMENT_ROBOT = (uint8_T)ModeleRobot_IN_MATCH;

    /* Entry 'CLOCK': '<S1>:1118' */
    ModeleRobot_DWork.is_active_CLOCK = 1U;

    /* Entry 'STRATEGIE': '<S1>:1119' */
    ModeleRobot_DWork.is_active_STRATEGIE = 1U;

    /* Transition: '<S1>:1120' */
    /* Entry 'STRATEGIE1': '<S1>:1123' */
    ModeleRobot_DWork.is_STRATEGIE = (uint8_T)ModeleRobot_IN_STRATEGIE1;

    /* during:
       CommandeLEDS_RVBO(ObstacleARG,ObstacleARD, ObstacleAVG,ObstacleAVD); */
    Model_enter_internal_STRATEGIE1();
  } else {
    /* During 'ACTIONNEURS_REPOS': '<S1>:1006' */
    switch (ModeleRobot_DWork.is_ACTIONNEURS_REPOS) {
     case ModeleR_IN_FIN_REPOS_ACTIONNEUR:
      break;

     case ModeleRobot_IN_REPOS_SERVOS:
      /* During 'REPOS_SERVOS': '<S1>:1009' */
      if (ModeleRobot_DWork.TempoInit > 2.0 / ModeleRobot_P.SFunction_p17) {
        /* Transition: '<S1>:1008' */
        /* Exit 'REPOS_SERVOS': '<S1>:1009' */
        /* Entry 'FIN_REPOS_ACTIONNEUR': '<S1>:3692' */
        ModeleRobot_DWork.is_ACTIONNEURS_REPOS = (uint8_T)
          ModeleR_IN_FIN_REPOS_ACTIONNEUR;

        /* Graphical Function 'setServo': '<S1>:3938' */
        /* Transition: '<S1>:3940' */
        ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p9 - 1.0)] =
          ModeleRobot_P.SFunction_p10;

        /* Graphical Function 'setServo': '<S1>:3938' */
        /* Transition: '<S1>:3940' */
        ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p6 - 1.0)] =
          ModeleRobot_P.SFunction_p7;

        /* Graphical Function 'setServo': '<S1>:3938' */
        /* Transition: '<S1>:3940' */
        ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p13 - 1.0)] =
          ModeleRobot_P.SFunction_p14;
        ModeleRobot_DWork.TempoInit = 0.0;
      } else {
        ModeleRobot_DWork.TempoInit = ModeleRobot_DWork.TempoInit + 1.0;
      }
      break;

     default:
      /* Transition: '<S1>:1007' */
      /* Entry 'REPOS_SERVOS': '<S1>:1009' */
      ModeleRobot_DWork.is_ACTIONNEURS_REPOS = (uint8_T)
        ModeleRobot_IN_REPOS_SERVOS;

      /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
      /* Transition: '<S1>:1301' */
      ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
      ModeleRobot_B.CommandeManuelleG = 0.0;
      ModeleRobot_B.CommandeManuelleD = 0.0;

      /* Graphical Function 'setServoSpeed': '<S1>:3943' */
      /* Transition: '<S1>:3945' */
      ModeleRobot_B.SpdServo[(int32_T)(ModeleRobot_P.SFunction_p9 - 1.0)] =
        ModeleRobot_P.SFunction_p4;

      /* Graphical Function 'setServoSpeed': '<S1>:3943' */
      /* Transition: '<S1>:3945' */
      ModeleRobot_B.SpdServo[(int32_T)(ModeleRobot_P.SFunction_p6 - 1.0)] =
        ModeleRobot_P.SFunction_p4;

      /* Graphical Function 'setServoSpeed': '<S1>:3943' */
      /* Transition: '<S1>:3945' */
      ModeleRobot_B.SpdServo[(int32_T)(ModeleRobot_P.SFunction_p13 - 1.0)] =
        ModeleRobot_P.SFunction_p4;

      /* Graphical Function 'setServo': '<S1>:3938' */
      /* Transition: '<S1>:3940' */
      ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p9 - 1.0)] =
        ModeleRobot_P.SFunction_p10;

      /* Graphical Function 'setServo': '<S1>:3938' */
      /* Transition: '<S1>:3940' */
      ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p6 - 1.0)] =
        ModeleRobot_P.SFunction_p7;

      /* Graphical Function 'setServo': '<S1>:3938' */
      /* Transition: '<S1>:3940' */
      ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p13 - 1.0)] =
        ModeleRobot_P.SFunction_p14;
      ModeleRobot_DWork.TempoInit = 0.0;
      break;
    }

    /* During 'CHOIX_EQUIPE': '<S1>:1011' */
    switch (ModeleRobot_DWork.is_CHOIX_EQUIPE) {
     case ModeleRobot_IN_EQUIPE_1:
      /* During 'EQUIPE_1': '<S1>:1016' */
      if (ModeleRobot_U.IN_CouleurEquipe == ModeleRobot_P.SFunction_p1) {
        /* Transition: '<S1>:1013' */
        /* Exit 'EQUIPE_1': '<S1>:1016' */
        /* Entry 'EQUIPE_2': '<S1>:1015' */
        ModeleRobot_DWork.is_CHOIX_EQUIPE = (uint8_T)ModeleRobot_IN_EQUIPE_2;
        ModeleRobot_B.EtatLed1 = 0.0;
        ModeleRobot_B.EtatLed2 = 1.0;
      }
      break;

     case ModeleRobot_IN_EQUIPE_2:
      /* During 'EQUIPE_2': '<S1>:1015' */
      if (ModeleRobot_U.IN_CouleurEquipe == ModeleRobot_P.SFunction_p2) {
        /* Transition: '<S1>:1014' */
        /* Exit 'EQUIPE_2': '<S1>:1015' */
        /* Entry 'EQUIPE_1': '<S1>:1016' */
        ModeleRobot_DWork.is_CHOIX_EQUIPE = (uint8_T)ModeleRobot_IN_EQUIPE_1;
        ModeleRobot_B.EtatLed1 = 1.0;
        ModeleRobot_B.EtatLed2 = 0.0;
      }
      break;

     default:
      /* Transition: '<S1>:1012' */
      /* Entry 'EQUIPE_1': '<S1>:1016' */
      ModeleRobot_DWork.is_CHOIX_EQUIPE = (uint8_T)ModeleRobot_IN_EQUIPE_1;
      ModeleRobot_B.EtatLed1 = 1.0;
      ModeleRobot_B.EtatLed2 = 0.0;
      break;
    }

    /* During 'TESTS_ACTIONNEUR': '<S1>:1036' */
    ModeleRobot_DWork.TempoTestActionneurs =
      ModeleRobot_DWork.TempoTestActionneurs + 1.0;
    switch (ModeleRobot_DWork.is_TESTS_ACTIONNEUR) {
     case ModeleRobot_IN_INIT:
      /* During 'INIT': '<S1>:1109' */
      /* Transition: '<S1>:3675' */
      if (ModeleRobot_U.IN_demande_test_actionneurs != 0) {
        /* Transition: '<S1>:3677' */
        /* Exit 'INIT': '<S1>:1109' */
        /* Entry 'INIT1': '<S1>:3674' */
        ModeleRobot_DWork.is_TESTS_ACTIONNEUR = (uint8_T)ModeleRobot_IN_INIT1;
        ModeleRobot_DWork.TempoTestActionneurs = 0.0;
      }
      break;

     case ModeleRobot_IN_INIT1:
      /* During 'INIT1': '<S1>:3674' */
      if (ModeleRobot_DWork.TempoTestActionneurs > 1.0 /
          ModeleRobot_P.SFunction_p17) {
        /* Transition: '<S1>:1418' */
        /* Exit 'INIT1': '<S1>:3674' */
        /* Entry 'TEST_ACT_3': '<S1>:3802' */
        ModeleRobot_DWork.is_TESTS_ACTIONNEUR = (uint8_T)
          ModeleRobot_IN_TEST_ACT_3;
        ModeleRobot_DWork.TempoTestActionneurs = 0.0;

        /* Graphical Function 'setServo': '<S1>:3938' */
        /* Transition: '<S1>:3940' */
        ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p9 - 1.0)] =
          ModeleRobot_P.SFunction_p11;

        /* Graphical Function 'setServo': '<S1>:3938' */
        /* Transition: '<S1>:3940' */
        ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p6 - 1.0)] =
          ModeleRobot_P.SFunction_p7;

        /* Graphical Function 'setServo': '<S1>:3938' */
        /* Transition: '<S1>:3940' */
        ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p13 - 1.0)] =
          ModeleRobot_P.SFunction_p14;
      }
      break;

     case ModeleRobot_IN_TEST_ACT_3:
      /* During 'TEST_ACT_3': '<S1>:3802' */
      if (ModeleRobot_DWork.TempoTestActionneurs > 2.0 /
          ModeleRobot_P.SFunction_p17) {
        /* Transition: '<S1>:3807' */
        /* Exit 'TEST_ACT_3': '<S1>:3802' */
        /* Entry 'TEST_ACT_4': '<S1>:3805' */
        ModeleRobot_DWork.is_TESTS_ACTIONNEUR = (uint8_T)
          ModeleRobot_IN_TEST_ACT_4;
        ModeleRobot_DWork.TempoTestActionneurs = 0.0;

        /* Graphical Function 'setServo': '<S1>:3938' */
        /* Transition: '<S1>:3940' */
        ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p9 - 1.0)] =
          ModeleRobot_P.SFunction_p10;

        /* Graphical Function 'setServo': '<S1>:3938' */
        /* Transition: '<S1>:3940' */
        ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p6 - 1.0)] =
          ModeleRobot_P.SFunction_p8;

        /* Graphical Function 'setServo': '<S1>:3938' */
        /* Transition: '<S1>:3940' */
        ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p13 - 1.0)] =
          ModeleRobot_P.SFunction_p14;
      }
      break;

     case ModeleRobot_IN_TEST_ACT_4:
      /* During 'TEST_ACT_4': '<S1>:3805' */
      if (ModeleRobot_DWork.TempoTestActionneurs > 2.0 /
          ModeleRobot_P.SFunction_p17) {
        /* Transition: '<S1>:3929' */
        /* Exit 'TEST_ACT_4': '<S1>:3805' */
        /* Entry 'TEST_ACT_5': '<S1>:3928' */
        ModeleRobot_DWork.is_TESTS_ACTIONNEUR = (uint8_T)
          ModeleRobot_IN_TEST_ACT_5;
        ModeleRobot_DWork.TempoTestActionneurs = 0.0;

        /* Graphical Function 'setServo': '<S1>:3938' */
        /* Transition: '<S1>:3940' */
        ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p9 - 1.0)] =
          ModeleRobot_P.SFunction_p10;

        /* Graphical Function 'setServo': '<S1>:3938' */
        /* Transition: '<S1>:3940' */
        ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p6 - 1.0)] =
          ModeleRobot_P.SFunction_p7;

        /* Graphical Function 'setServo': '<S1>:3938' */
        /* Transition: '<S1>:3940' */
        ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p13 - 1.0)] =
          ModeleRobot_P.SFunction_p15;
      }
      break;

     case ModeleRobot_IN_TEST_ACT_5:
      /* During 'TEST_ACT_5': '<S1>:3928' */
      if (ModeleRobot_DWork.TempoTestActionneurs > 2.0 /
          ModeleRobot_P.SFunction_p17) {
        /* Transition: '<S1>:3933' */
        /* Exit 'TEST_ACT_5': '<S1>:3928' */
        /* Entry 'TEST_ACT_6': '<S1>:3932' */
        ModeleRobot_DWork.is_TESTS_ACTIONNEUR = (uint8_T)
          ModeleRobot_IN_TEST_ACT_6;
        ModeleRobot_DWork.TempoTestActionneurs = 0.0;

        /* Graphical Function 'setServo': '<S1>:3938' */
        /* Transition: '<S1>:3940' */
        ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p9 - 1.0)] =
          ModeleRobot_P.SFunction_p10;

        /* Graphical Function 'setServo': '<S1>:3938' */
        /* Transition: '<S1>:3940' */
        ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p6 - 1.0)] =
          ModeleRobot_P.SFunction_p7;

        /* Graphical Function 'setServo': '<S1>:3938' */
        /* Transition: '<S1>:3940' */
        ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p13 - 1.0)] =
          ModeleRobot_P.SFunction_p14;
      }
      break;

     case ModeleRobot_IN_TEST_ACT_6:
      /* During 'TEST_ACT_6': '<S1>:3932' */
      if (ModeleRobot_DWork.TempoTestActionneurs > 2.0 /
          ModeleRobot_P.SFunction_p17) {
        /* Transition: '<S1>:3813' */
        /* Exit 'TEST_ACT_6': '<S1>:3932' */
        /* Entry 'TEST_ACT_FIN': '<S1>:1515' */
        ModeleRobot_DWork.is_TESTS_ACTIONNEUR = (uint8_T)
          ModeleRobot_IN_TEST_ACT_FIN;
        ModeleRobot_DWork.TempoTestActionneurs = 0.0;
      }
      break;

     case ModeleRobot_IN_TEST_ACT_FIN:
      /* During 'TEST_ACT_FIN': '<S1>:1515' */
      /* Transition: '<S1>:3678' */
      if (ModeleRobot_U.IN_demande_test_actionneurs != 0) {
        /* Transition: '<S1>:3677' */
        /* Exit 'TEST_ACT_FIN': '<S1>:1515' */
        /* Entry 'INIT1': '<S1>:3674' */
        ModeleRobot_DWork.is_TESTS_ACTIONNEUR = (uint8_T)ModeleRobot_IN_INIT1;
        ModeleRobot_DWork.TempoTestActionneurs = 0.0;
      }
      break;

     default:
      /* Transition: '<S1>:1064' */
      /* Entry 'INIT': '<S1>:1109' */
      ModeleRobot_DWork.is_TESTS_ACTIONNEUR = (uint8_T)ModeleRobot_IN_INIT;
      break;
    }

    /* During 'TESTS_CAPTEURS': '<S1>:3093' */
    /* CommandeLEDS(1,1, 1,1); */
  }
}

/* Function for Stateflow: '<Root>/COMPORTEMENT' */
static void ModeleRobot_FIN_MATCH(void)
{
  /* During 'FIN_MATCH': '<S1>:1258' */
  switch (ModeleRobot_DWork.is_FIN_MATCH) {
   case ModeleRobot_IN_FIN_MATCH_01:
    /* During 'FIN_MATCH_01': '<S1>:1262' */
    if (ModeleRobot_DWork.TempoImage > 3.0 / ModeleRobot_P.SFunction_p17) {
      /* Transition: '<S1>:1260' */
      /* Exit 'FIN_MATCH_01': '<S1>:1262' */
      /* Entry 'FIN_MATCH_02': '<S1>:1263' */
      ModeleRobot_DWork.is_FIN_MATCH = (uint8_T)ModeleRobot_IN_FIN_MATCH_02;

      /* chenillard de led */
      /* Graphical Function 'CommandeLEDS': '<S1>:1339' */
      /* Transition: '<S1>:1341' */
      ModeleRobot_B.EtatLed1 = 1.0;
      ModeleRobot_B.EtatLed2 = 0.0;
      ModeleRobot_B.EtatLed3 = 0.0;
      ModeleRobot_B.EtatLed4 = 0.0;
      ModeleRobot_DWork.TempoImage = 0.0;
    } else {
      ModeleRobot_DWork.TempoImage = ModeleRobot_DWork.TempoImage + 1.0;
    }
    break;

   case ModeleRobot_IN_FIN_MATCH_02:
    /* During 'FIN_MATCH_02': '<S1>:1263' */
    if (ModeleRobot_DWork.TempoImage > 1.0 / ModeleRobot_P.SFunction_p17) {
      /* Transition: '<S1>:3781' */
      /* Exit 'FIN_MATCH_02': '<S1>:1263' */
      /* Entry 'FIN_MATCH_03': '<S1>:3777' */
      ModeleRobot_DWork.is_FIN_MATCH = (uint8_T)ModeleRobot_IN_FIN_MATCH_03;

      /* chenillard de led */
      /* Graphical Function 'CommandeLEDS': '<S1>:1339' */
      /* Transition: '<S1>:1341' */
      ModeleRobot_B.EtatLed1 = 0.0;
      ModeleRobot_B.EtatLed2 = 1.0;
      ModeleRobot_B.EtatLed3 = 0.0;
      ModeleRobot_B.EtatLed4 = 0.0;
      ModeleRobot_DWork.TempoImage = 0.0;
    } else {
      ModeleRobot_DWork.TempoImage = ModeleRobot_DWork.TempoImage + 1.0;
    }
    break;

   case ModeleRobot_IN_FIN_MATCH_03:
    /* During 'FIN_MATCH_03': '<S1>:3777' */
    if (ModeleRobot_DWork.TempoImage > 1.0 / ModeleRobot_P.SFunction_p17) {
      /* Transition: '<S1>:3782' */
      /* Exit 'FIN_MATCH_03': '<S1>:3777' */
      /* Entry 'FIN_MATCH_04': '<S1>:3778' */
      ModeleRobot_DWork.is_FIN_MATCH = (uint8_T)ModeleRobot_IN_FIN_MATCH_04;

      /* chenillard de led */
      /* Graphical Function 'CommandeLEDS': '<S1>:1339' */
      /* Transition: '<S1>:1341' */
      ModeleRobot_B.EtatLed1 = 0.0;
      ModeleRobot_B.EtatLed2 = 0.0;
      ModeleRobot_B.EtatLed3 = 1.0;
      ModeleRobot_B.EtatLed4 = 0.0;
      ModeleRobot_DWork.TempoImage = 0.0;
    } else {
      ModeleRobot_DWork.TempoImage = ModeleRobot_DWork.TempoImage + 1.0;
    }
    break;

   case ModeleRobot_IN_FIN_MATCH_04:
    /* During 'FIN_MATCH_04': '<S1>:3778' */
    if (ModeleRobot_DWork.TempoImage > 1.0 / ModeleRobot_P.SFunction_p17) {
      /* Transition: '<S1>:3783' */
      /* Exit 'FIN_MATCH_04': '<S1>:3778' */
      /* Entry 'FIN_MATCH_05': '<S1>:3779' */
      ModeleRobot_DWork.is_FIN_MATCH = (uint8_T)ModeleRobot_IN_FIN_MATCH_05;

      /* chenillard de led */
      /* Graphical Function 'CommandeLEDS': '<S1>:1339' */
      /* Transition: '<S1>:1341' */
      ModeleRobot_B.EtatLed1 = 0.0;
      ModeleRobot_B.EtatLed2 = 0.0;
      ModeleRobot_B.EtatLed3 = 0.0;
      ModeleRobot_B.EtatLed4 = 1.0;
      ModeleRobot_DWork.TempoImage = 0.0;
    } else {
      ModeleRobot_DWork.TempoImage = ModeleRobot_DWork.TempoImage + 1.0;
    }
    break;

   case ModeleRobot_IN_FIN_MATCH_05:
    /* During 'FIN_MATCH_05': '<S1>:3779' */
    if (ModeleRobot_DWork.TempoImage > 1.0 / ModeleRobot_P.SFunction_p17) {
      /* Transition: '<S1>:3784' */
      /* Exit 'FIN_MATCH_05': '<S1>:3779' */
      /* Entry 'FIN_MATCH_02': '<S1>:1263' */
      ModeleRobot_DWork.is_FIN_MATCH = (uint8_T)ModeleRobot_IN_FIN_MATCH_02;

      /* chenillard de led */
      /* Graphical Function 'CommandeLEDS': '<S1>:1339' */
      /* Transition: '<S1>:1341' */
      ModeleRobot_B.EtatLed1 = 1.0;
      ModeleRobot_B.EtatLed2 = 0.0;
      ModeleRobot_B.EtatLed3 = 0.0;
      ModeleRobot_B.EtatLed4 = 0.0;
      ModeleRobot_DWork.TempoImage = 0.0;
    } else {
      ModeleRobot_DWork.TempoImage = ModeleRobot_DWork.TempoImage + 1.0;
    }
    break;

   default:
    /* Transition: '<S1>:1259' */
    /* Entry 'FIN_MATCH_01': '<S1>:1262' */
    ModeleRobot_DWork.is_FIN_MATCH = (uint8_T)ModeleRobot_IN_FIN_MATCH_01;

    /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
    /* Transition: '<S1>:1301' */
    ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
    ModeleRobot_B.CommandeManuelleG = 0.0;
    ModeleRobot_B.CommandeManuelleD = 0.0;

    /* Graphical Function 'setServo': '<S1>:3938' */
    /* Transition: '<S1>:3940' */
    ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p9 - 1.0)] =
      ModeleRobot_P.SFunction_p10;

    /* Graphical Function 'setServo': '<S1>:3938' */
    /* Transition: '<S1>:3940' */
    ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p6 - 1.0)] =
      ModeleRobot_P.SFunction_p7;

    /* Graphical Function 'setServo': '<S1>:3938' */
    /* Transition: '<S1>:3940' */
    ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p13 - 1.0)] =
      ModeleRobot_P.SFunction_p14;

    /* Graphical Function 'CommandeLEDS': '<S1>:1339' */
    /* Transition: '<S1>:1341' */
    ModeleRobot_B.EtatLed1 = 1.0;
    ModeleRobot_B.EtatLed2 = 1.0;
    ModeleRobot_B.EtatLed3 = 1.0;
    ModeleRobot_B.EtatLed4 = 1.0;
    ModeleRobot_DWork.TempoImage = 0.0;
    break;
  }
}

/* Initial conditions for atomic system: '<Root>/COMPORTEMENT' */
void ModeleRobot_COMPORTEMENT_Init(void)
{
  /* InitializeConditions for Stateflow: '<Root>/COMPORTEMENT' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/isFrontMontantConvergence'
   *  InitializeConditions for SubSystem: '<S1>/isFrontMontantMvtBloque'
   */

  /* InitializeConditions for UnitDelay: '<S7>/Delay Input1' */
  ModeleRobot_DWork.DelayInput1_DSTATE_d = ModeleRobot_P.DelayInput1_X0;

  /* InitializeConditions for UnitDelay: '<S10>/Delay Input1' */
  ModeleRobot_DWork.DelayInput1_DSTATE = ModeleRobot_P.DelayInput1_X0_o;
}

/* Output and update for atomic system: '<Root>/COMPORTEMENT' */
void ModeleRobot_COMPORTEMENT(void)
{
  /* Stateflow: '<Root>/COMPORTEMENT' incorporates:
   *  Inport: '<Root>/IN_inclinaison'
   */
  /* Gateway: COMPORTEMENT */
  /* During: COMPORTEMENT */
  if (ModeleRobot_DWork.is_active_c1_ModeleRobot == 0) {
    /* Entry: COMPORTEMENT */
    ModeleRobot_DWork.is_active_c1_ModeleRobot = 1U;

    /* Entry 'COMPORTEMENT_ROBOT': '<S1>:1004' */
    ModeleRobot_DWork.is_active_COMPORTEMENT_ROBOT = 1U;
    enter_internal_COMPORTEMENT_ROB();

    /* Entry 'FONCTIONS_GLOBALES_DEPLACEMENT_ROBOT': '<S1>:936' */
    ModeleRobot_DWork.is_active_FONCTIONS_GLOBALES_DE = 1U;

    /* Entry 'FONCTIONS_GLOBALES_COMMANDE_SERVOS': '<S1>:1312' */
    ModeleRobot_DWork.is_active_FONCTIONS_GLOBALES__i = 1U;

    /* Entry 'FONCTIONS_GLOBALES_DETECTION_OBSTACLES': '<S1>:1315' */
    ModeleRobot_DWork.is_active_FONCTIONS_GLOBALES__j = 1U;

    /* Entry 'FONCTIONS_GLOBALES_COMMANDE_LEDS': '<S1>:1318' */
    ModeleRobot_DWork.is_active_FONCTIONS_GLOBALES_CO = 1U;

    /* Entry 'FONCTIONS_GLOBALES_DIVERS': '<S1>:1335' */
    ModeleRobot_DWork.is_active_FONCTIONS_GLOBALES_DI = 1U;

    /* Entry 'FONCTIONS_RECalAGE_POSITION': '<S1>:2810' */
    ModeleRobot_DWork.is_active_FONCTIONS_RECalAGE_PO = 1U;
  } else {
    /* During 'COMPORTEMENT_ROBOT': '<S1>:1004' */
    switch (ModeleRobot_DWork.is_COMPORTEMENT_ROBOT) {
     case ModeleRobot_IN_ATTENTE_TIRETTE:
      ModeleRobot_ATTENTE_TIRETTE();
      break;

     case ModeleRobot_IN_FIN_MATCH:
      ModeleRobot_FIN_MATCH();
      break;

     case ModeleRobot_IN_MATCH:
      /* During 'MATCH': '<S1>:1117' */
      if (ModeleRobot_DWork.DureeMatch > 90.0 / ModeleRobot_P.SFunction_p17) {
        /* Transition: '<S1>:1266' */
        /* Exit 'ACTION_00': '<S1>:4090' */
        ModeleRobot_DWork.is_GOTO_BAS_DES_MARCHES = (uint8_T)
          ModeleRobot_IN_NO_ACTIVE_CHILD;

        /* Exit 'ACTION_01': '<S1>:3949' */
        /* Exit 'ACTION_02': '<S1>:3951' */
        /* Exit 'ACTION_03': '<S1>:3954' */
        /* Exit 'ACTION_04': '<S1>:3956' */
        /* Exit 'ACTION_05': '<S1>:3962' */
        /* Exit 'ACTION_06': '<S1>:3965' */
        /* Exit 'ACTION_07': '<S1>:4080' */
        /* Exit 'DETECT_OBSTACLE': '<S1>:4087' */
        ModeleRobot_DWork.is_EVITEMENT = (uint8_T)ModeleRobot_IN_NO_ACTIVE_CHILD;

        /* Exit 'EVITEMENT': '<S1>:4084' */
        /* Exit 'DETECT_OBSTACLE': '<S1>:4095' */
        ModeleRobot_DWork.is_EVITEMENT1 = (uint8_T)
          ModeleRobot_IN_NO_ACTIVE_CHILD;

        /* Exit 'EVITEMENT1': '<S1>:4093' */
        /* Exit 'HOMOLO_FIN': '<S1>:3510' */
        /* Exit 'GOTO_BAS_DES_MARCHES': '<S1>:3463' */
        ModeleRobot_DWork.is_STRATEGIE1 = (uint8_T)
          ModeleRobot_IN_NO_ACTIVE_CHILD;

        /* Exit 'INIT_STRATEGIE': '<S1>:1128' */
        /* Exit 'ACTION_010': '<S1>:4054' */
        ModeleRobot_DWork.is_MONTE_MARCHE = (uint8_T)
          ModeleRobot_IN_NO_ACTIVE_CHILD;

        /* Exit 'ACTION_012': '<S1>:4061' */
        /* Exit 'ACTION_013': '<S1>:4074' */
        /* Exit 'ACTION_014': '<S1>:4075' */
        /* Exit 'ACTION_015': '<S1>:4077' */
        /* Exit 'ACTION_02': '<S1>:4009' */
        /* Exit 'ACTION_03': '<S1>:4015' */
        /* Exit 'ACTION_04': '<S1>:4028' */
        /* Exit 'ACTION_05': '<S1>:4033' */
        /* Exit 'ACTION_06': '<S1>:4038' */
        /* Exit 'ACTION_07': '<S1>:4043' */
        /* Exit 'ACTION_08': '<S1>:4044' */
        /* Exit 'ACTION_09': '<S1>:4047' */
        /* Exit 'MONTE_MARCHE': '<S1>:3983' */
        /* Exit 'STRATEGIE1': '<S1>:1123' */
        ModeleRobot_DWork.is_STRATEGIE = (uint8_T)ModeleRobot_IN_NO_ACTIVE_CHILD;

        /* Exit 'STRATEGIE': '<S1>:1119' */
        ModeleRobot_DWork.is_active_STRATEGIE = 0U;

        /* Exit 'CLOCK': '<S1>:1118' */
        ModeleRobot_DWork.is_active_CLOCK = 0U;

        /* Exit 'MATCH': '<S1>:1117' */
        /* Entry 'FIN_MATCH': '<S1>:1258' */
        ModeleRobot_DWork.is_COMPORTEMENT_ROBOT = (uint8_T)
          ModeleRobot_IN_FIN_MATCH;

        /* Transition: '<S1>:1259' */
        /* Entry 'FIN_MATCH_01': '<S1>:1262' */
        ModeleRobot_DWork.is_FIN_MATCH = (uint8_T)ModeleRobot_IN_FIN_MATCH_01;

        /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
        /* Transition: '<S1>:1301' */
        ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
        ModeleRobot_B.CommandeManuelleG = 0.0;
        ModeleRobot_B.CommandeManuelleD = 0.0;

        /* Graphical Function 'setServo': '<S1>:3938' */
        /* Transition: '<S1>:3940' */
        ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p9 - 1.0)] =
          ModeleRobot_P.SFunction_p10;

        /* Graphical Function 'setServo': '<S1>:3938' */
        /* Transition: '<S1>:3940' */
        ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p6 - 1.0)] =
          ModeleRobot_P.SFunction_p7;

        /* Graphical Function 'setServo': '<S1>:3938' */
        /* Transition: '<S1>:3940' */
        ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p13 - 1.0)] =
          ModeleRobot_P.SFunction_p14;

        /* Graphical Function 'CommandeLEDS': '<S1>:1339' */
        /* Transition: '<S1>:1341' */
        ModeleRobot_B.EtatLed1 = 1.0;
        ModeleRobot_B.EtatLed2 = 1.0;
        ModeleRobot_B.EtatLed3 = 1.0;
        ModeleRobot_B.EtatLed4 = 1.0;
        ModeleRobot_DWork.TempoImage = 0.0;
      } else {
        /* During 'CLOCK': '<S1>:1118' */
        ModeleRobot_DWork.DureeMatch = ModeleRobot_DWork.DureeMatch + 1.0;

        /* During 'STRATEGIE': '<S1>:1119' */
        /* During 'STRATEGIE1': '<S1>:1123' */
        switch (ModeleRobot_DWork.is_STRATEGIE1) {
         case ModeleR_IN_GOTO_BAS_DES_MARCHES:
          /* During 'GOTO_BAS_DES_MARCHES': '<S1>:3463' */
          if (ModeleRobot_DWork.Etape_GotoMarche == 0.0) {
            /* Transition: '<S1>:4006' */
            /* Exit 'ACTION_00': '<S1>:4090' */
            ModeleRobot_DWork.is_GOTO_BAS_DES_MARCHES = (uint8_T)
              ModeleRobot_IN_NO_ACTIVE_CHILD;

            /* Exit 'ACTION_01': '<S1>:3949' */
            /* Exit 'ACTION_02': '<S1>:3951' */
            /* Exit 'ACTION_03': '<S1>:3954' */
            /* Exit 'ACTION_04': '<S1>:3956' */
            /* Exit 'ACTION_05': '<S1>:3962' */
            /* Exit 'ACTION_06': '<S1>:3965' */
            /* Exit 'ACTION_07': '<S1>:4080' */
            /* Exit 'DETECT_OBSTACLE': '<S1>:4087' */
            ModeleRobot_DWork.is_EVITEMENT = (uint8_T)
              ModeleRobot_IN_NO_ACTIVE_CHILD;

            /* Exit 'EVITEMENT': '<S1>:4084' */
            /* Exit 'DETECT_OBSTACLE': '<S1>:4095' */
            ModeleRobot_DWork.is_EVITEMENT1 = (uint8_T)
              ModeleRobot_IN_NO_ACTIVE_CHILD;

            /* Exit 'EVITEMENT1': '<S1>:4093' */
            /* Exit 'HOMOLO_FIN': '<S1>:3510' */
            /* Exit 'GOTO_BAS_DES_MARCHES': '<S1>:3463' */
            /* Entry 'MONTE_MARCHE': '<S1>:3983' */
            ModeleRobot_DWork.is_STRATEGIE1 = (uint8_T)
              ModeleRobot_IN_MONTE_MARCHE;
            ModeleRobot_DWork.was_STRATEGIE1 = (uint8_T)
              ModeleRobot_IN_MONTE_MARCHE;
            ModeleRobot_DWork.Tempo = 0.0;
            ModeleRobot_DWork.inhibeObstacle = 1.0;
            Mod_enter_internal_MONTE_MARCHE();
          } else {
            ModeleRobot_DWork.Tempo = ModeleRobot_DWork.Tempo + 1.0;
            switch (ModeleRobot_DWork.is_GOTO_BAS_DES_MARCHES) {
             case ModeleRobot_IN_ACTION_00:
              /* During 'ACTION_00': '<S1>:4090' */
              /* Transition: '<S1>:4091' */
              /* Exit 'ACTION_00': '<S1>:4090' */
              /* Entry 'ACTION_01': '<S1>:3949' */
              ModeleRobot_DWork.is_GOTO_BAS_DES_MARCHES = (uint8_T)
                ModeleRobot_IN_ACTION_01;
              ModeleRobot_DWork.was_GOTO_BAS_DES_MARCHES = (uint8_T)
                ModeleRobot_IN_ACTION_01;

              /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
              /* Transition: '<S1>:1301' */
              ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
              ModeleRobot_B.CommandeManuelleG = 100.0;
              ModeleRobot_B.CommandeManuelleD = 100.0;
              break;

             case ModeleRobot_IN_ACTION_01:
              /* During 'ACTION_01': '<S1>:3949' */
              if (ModeleRobot_DWork.Tempo2 > 7.5 / ModeleRobot_P.SFunction_p17)
              {
                /* Transition: '<S1>:3950' */
                if (ModeleRobot_DWork.CouleurEquipe_memo ==
                    ModeleRobot_P.SFunction_p2) {
                  /* Transition: '<S1>:3966' */
                  /* Exit 'ACTION_01': '<S1>:3949' */
                  /* Entry 'ACTION_06': '<S1>:3965' */
                  ModeleRobot_DWork.is_GOTO_BAS_DES_MARCHES = (uint8_T)
                    ModeleRobot_IN_ACTION_06;
                  ModeleRobot_DWork.was_GOTO_BAS_DES_MARCHES = (uint8_T)
                    ModeleRobot_IN_ACTION_06;
                  ModeleRobot_DWork.Tempo = 0.0;

                  /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
                  /* Transition: '<S1>:1301' */
                  ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
                  ModeleRobot_B.CommandeManuelleG = 0.0;
                  ModeleRobot_B.CommandeManuelleD = 100.0;
                } else {
                  /* Transition: '<S1>:3963' */
                  /* Exit 'ACTION_01': '<S1>:3949' */
                  /* Entry 'ACTION_05': '<S1>:3962' */
                  ModeleRobot_DWork.is_GOTO_BAS_DES_MARCHES = (uint8_T)
                    ModeleRobot_IN_ACTION_05;
                  ModeleRobot_DWork.was_GOTO_BAS_DES_MARCHES = (uint8_T)
                    ModeleRobot_IN_ACTION_05;
                  ModeleRobot_DWork.Tempo = 0.0;

                  /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
                  /* Transition: '<S1>:1301' */
                  ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
                  ModeleRobot_B.CommandeManuelleG = 100.0;
                  ModeleRobot_B.CommandeManuelleD = 0.0;
                }
              } else if ((ModeleRobot_Y.OUT_isObstacle == 1) &&
                         (ModeleRobot_DWork.inhibeObstacle == 0.0)) {
                /* Transition: '<S1>:4089' */
                /* Exit 'ACTION_01': '<S1>:3949' */
                /* Entry 'EVITEMENT': '<S1>:4084' */
                ModeleRobot_DWork.is_GOTO_BAS_DES_MARCHES = (uint8_T)
                  ModeleRobot_IN_EVITEMENT;
                ModeleRobot_DWork.was_GOTO_BAS_DES_MARCHES = (uint8_T)
                  ModeleRobot_IN_EVITEMENT;

                /* Dans le cas d'un mouvement distance on calcule la distance parcourue pour repartir
                   avec une consigne adapt */
                /* Transition: '<S1>:4085' */
                /* Entry 'DETECT_OBSTACLE': '<S1>:4087' */
                ModeleRobot_DWork.is_EVITEMENT = (uint8_T)
                  ModeleRobot_IN_DETECT_OBSTACLE;
                ModeleRobot_DWork.local_Tempo = 0.0;

                /* Mouvement_ArretBrutal(); // Arrête tout pendant un instant mais bug */
                /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
                /* Transition: '<S1>:1301' */
                ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
                ModeleRobot_B.CommandeManuelleG = 0.0;
                ModeleRobot_B.CommandeManuelleD = 0.0;

                /* Graphical Function 'CommandeLEDS': '<S1>:1339' */
                /* Transition: '<S1>:1341' */
                ModeleRobot_B.EtatLed1 = 1.0;
                ModeleRobot_B.EtatLed2 = 0.0;
                ModeleRobot_B.EtatLed3 = 0.0;
                ModeleRobot_B.EtatLed4 = 0.0;
              } else {
                ModeleRobot_DWork.Tempo2 = ModeleRobot_DWork.Tempo2 + 1.0;
              }
              break;

             case ModeleRobot_IN_ACTION_02:
              /* During 'ACTION_02': '<S1>:3951' */
              if (ModeleRobot_DWork.Tempo2 > 3.0 / ModeleRobot_P.SFunction_p17)
              {
                /* Transition: '<S1>:3953' */
                /* Exit 'ACTION_02': '<S1>:3951' */
                /* Entry 'ACTION_07': '<S1>:4080' */
                ModeleRobot_DWork.is_GOTO_BAS_DES_MARCHES = (uint8_T)
                  ModeleRobot_IN_ACTION_07;
                ModeleRobot_DWork.was_GOTO_BAS_DES_MARCHES = (uint8_T)
                  ModeleRobot_IN_ACTION_07;
                ModeleRobot_DWork.Tempo = 0.0;

                /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
                /* Transition: '<S1>:1301' */
                ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
                ModeleRobot_B.CommandeManuelleG = 100.0;
                ModeleRobot_B.CommandeManuelleD = 100.0;

                /* Graphical Function 'setServo': '<S1>:3938' */
                /* Transition: '<S1>:3940' */
                ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p12 -
                  1.0)] = 115.0;
              } else if ((ModeleRobot_Y.OUT_isObstacle == 1) &&
                         (ModeleRobot_DWork.inhibeObstacle == 0.0)) {
                /* Transition: '<S1>:4096' */
                /* Exit 'ACTION_02': '<S1>:3951' */
                /* Entry 'EVITEMENT1': '<S1>:4093' */
                ModeleRobot_DWork.is_GOTO_BAS_DES_MARCHES = (uint8_T)
                  ModeleRobot_IN_EVITEMENT1;
                ModeleRobot_DWork.was_GOTO_BAS_DES_MARCHES = (uint8_T)
                  ModeleRobot_IN_EVITEMENT1;

                /* Dans le cas d'un mouvement distance on calcule la distance parcourue pour repartir
                   avec une consigne adapt */
                /* Transition: '<S1>:4094' */
                /* Entry 'DETECT_OBSTACLE': '<S1>:4095' */
                ModeleRobot_DWork.is_EVITEMENT1 = (uint8_T)
                  ModeleRobot_IN_DETECT_OBSTACLE;
                ModeleRobot_DWork.local_Tempo = 0.0;

                /* Mouvement_ArretBrutal(); // Arrête tout pendant un instant mais bug */
                /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
                /* Transition: '<S1>:1301' */
                ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
                ModeleRobot_B.CommandeManuelleG = 0.0;
                ModeleRobot_B.CommandeManuelleD = 0.0;

                /* Graphical Function 'CommandeLEDS': '<S1>:1339' */
                /* Transition: '<S1>:1341' */
                ModeleRobot_B.EtatLed1 = 1.0;
                ModeleRobot_B.EtatLed2 = 0.0;
                ModeleRobot_B.EtatLed3 = 0.0;
                ModeleRobot_B.EtatLed4 = 0.0;
              } else {
                ModeleRobot_DWork.Tempo2 = ModeleRobot_DWork.Tempo2 + 1.0;

                /* setServo(SERVO_DOIGT, 120); */
              }
              break;

             case ModeleRobot_IN_ACTION_03:
              /* During 'ACTION_03': '<S1>:3954' */
              if (ModeleRobot_DWork.Tempo > 1.3 / ModeleRobot_P.SFunction_p17) {
                /* Transition: '<S1>:3955' */
                /* Exit 'ACTION_03': '<S1>:3954' */
                /* Entry 'ACTION_04': '<S1>:3956' */
                ModeleRobot_DWork.is_GOTO_BAS_DES_MARCHES = (uint8_T)
                  ModeleRobot_IN_ACTION_04;
                ModeleRobot_DWork.was_GOTO_BAS_DES_MARCHES = (uint8_T)
                  ModeleRobot_IN_ACTION_04;

                /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
                /* Transition: '<S1>:1301' */
                ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
                ModeleRobot_B.CommandeManuelleG = 0.0;
                ModeleRobot_B.CommandeManuelleD = 0.0;
              }
              break;

             case ModeleRobot_IN_ACTION_04:
              /* During 'ACTION_04': '<S1>:3956' */
              if (ModeleRobot_DWork.Tempo > 1.0 / ModeleRobot_P.SFunction_p17) {
                /* Transition: '<S1>:3957' */
                /* Exit 'ACTION_04': '<S1>:3956' */
                /* Entry 'HOMOLO_FIN': '<S1>:3510' */
                ModeleRobot_DWork.is_GOTO_BAS_DES_MARCHES = (uint8_T)
                  ModeleRobot_IN_HOMOLO_FIN;
                ModeleRobot_DWork.was_GOTO_BAS_DES_MARCHES = (uint8_T)
                  ModeleRobot_IN_HOMOLO_FIN;

                /*  Fin - en cours de debuggage on ne sort pour l'instant pas de l'homologation */
                ModeleRobot_DWork.Etape_GotoMarche = 0.0;
              }
              break;

             case ModeleRobot_IN_ACTION_05:
              /* During 'ACTION_05': '<S1>:3962' */
              if (ModeleRobot_DWork.Tempo > 2.6 / ModeleRobot_P.SFunction_p17) {
                /* Transition: '<S1>:3970' */
                /* Exit 'ACTION_05': '<S1>:3962' */
                /* Entry 'ACTION_02': '<S1>:3951' */
                ModeleRobot_DWork.is_GOTO_BAS_DES_MARCHES = (uint8_T)
                  ModeleRobot_IN_ACTION_02;
                ModeleRobot_DWork.was_GOTO_BAS_DES_MARCHES = (uint8_T)
                  ModeleRobot_IN_ACTION_02;
                ModeleRobot_DWork.Tempo2 = 0.0;

                /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
                /* Transition: '<S1>:1301' */
                ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
                ModeleRobot_B.CommandeManuelleG = 100.0;
                ModeleRobot_B.CommandeManuelleD = 100.0;
              }
              break;

             case ModeleRobot_IN_ACTION_06:
              /* During 'ACTION_06': '<S1>:3965' */
              if (ModeleRobot_DWork.Tempo > 2.7 / ModeleRobot_P.SFunction_p17) {
                /* Transition: '<S1>:3971' */
                /* Exit 'ACTION_06': '<S1>:3965' */
                /* Entry 'ACTION_02': '<S1>:3951' */
                ModeleRobot_DWork.is_GOTO_BAS_DES_MARCHES = (uint8_T)
                  ModeleRobot_IN_ACTION_02;
                ModeleRobot_DWork.was_GOTO_BAS_DES_MARCHES = (uint8_T)
                  ModeleRobot_IN_ACTION_02;
                ModeleRobot_DWork.Tempo2 = 0.0;

                /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
                /* Transition: '<S1>:1301' */
                ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
                ModeleRobot_B.CommandeManuelleG = 100.0;
                ModeleRobot_B.CommandeManuelleD = 100.0;
              }
              break;

             case ModeleRobot_IN_ACTION_07:
              /* During 'ACTION_07': '<S1>:4080' */
              if (ModeleRobot_DWork.Tempo > 1.0 / ModeleRobot_P.SFunction_p17) {
                /* Transition: '<S1>:4081' */
                /* Exit 'ACTION_07': '<S1>:4080' */
                /* Entry 'ACTION_03': '<S1>:3954' */
                ModeleRobot_DWork.is_GOTO_BAS_DES_MARCHES = (uint8_T)
                  ModeleRobot_IN_ACTION_03;
                ModeleRobot_DWork.was_GOTO_BAS_DES_MARCHES = (uint8_T)
                  ModeleRobot_IN_ACTION_03;
                ModeleRobot_DWork.Tempo = 0.0;

                /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
                /* Transition: '<S1>:1301' */
                ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
                ModeleRobot_B.CommandeManuelleG = 0.0;
                ModeleRobot_B.CommandeManuelleD = 0.0;

                /* Graphical Function 'setServo': '<S1>:3938' */
                /* Transition: '<S1>:3940' */
                ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p12 -
                  1.0)] = 130.0;
              }
              break;

             case ModeleRobot_IN_EVITEMENT:
              /* During 'EVITEMENT': '<S1>:4084' */
              if (ModeleRobot_Y.OUT_isObstacle == 0) {
                /* Transition: '<S1>:4083' */
                /* Exit 'DETECT_OBSTACLE': '<S1>:4087' */
                ModeleRobot_DWork.is_EVITEMENT = (uint8_T)
                  ModeleRobot_IN_NO_ACTIVE_CHILD;

                /* Exit 'EVITEMENT': '<S1>:4084' */
                /* Entry 'ACTION_01': '<S1>:3949' */
                ModeleRobot_DWork.is_GOTO_BAS_DES_MARCHES = (uint8_T)
                  ModeleRobot_IN_ACTION_01;
                ModeleRobot_DWork.was_GOTO_BAS_DES_MARCHES = (uint8_T)
                  ModeleRobot_IN_ACTION_01;

                /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
                /* Transition: '<S1>:1301' */
                ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
                ModeleRobot_B.CommandeManuelleG = 100.0;
                ModeleRobot_B.CommandeManuelleD = 100.0;
              } else {
                ModeleRobot_DWork.local_Tempo = ModeleRobot_DWork.local_Tempo +
                  1.0;
              }
              break;

             case ModeleRobot_IN_EVITEMENT1:
              /* During 'EVITEMENT1': '<S1>:4093' */
              if (ModeleRobot_Y.OUT_isObstacle == 0) {
                /* Transition: '<S1>:4092' */
                /* Exit 'DETECT_OBSTACLE': '<S1>:4095' */
                ModeleRobot_DWork.is_EVITEMENT1 = (uint8_T)
                  ModeleRobot_IN_NO_ACTIVE_CHILD;

                /* Exit 'EVITEMENT1': '<S1>:4093' */
                /* Entry 'ACTION_02': '<S1>:3951' */
                ModeleRobot_DWork.is_GOTO_BAS_DES_MARCHES = (uint8_T)
                  ModeleRobot_IN_ACTION_02;
                ModeleRobot_DWork.was_GOTO_BAS_DES_MARCHES = (uint8_T)
                  ModeleRobot_IN_ACTION_02;
                ModeleRobot_DWork.Tempo2 = 0.0;

                /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
                /* Transition: '<S1>:1301' */
                ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
                ModeleRobot_B.CommandeManuelleG = 100.0;
                ModeleRobot_B.CommandeManuelleD = 100.0;
              } else {
                ModeleRobot_DWork.local_Tempo = ModeleRobot_DWork.local_Tempo +
                  1.0;
              }
              break;

             case ModeleRobot_IN_HOMOLO_FIN:
              break;

             default:
              enter_internal_GOTO_BAS_DES_MAR();
              break;
            }
          }
          break;

         case ModeleRobot_IN_INIT_STRATEGIE:
          /* During 'INIT_STRATEGIE': '<S1>:1128' */
          if (ModeleRobot_DWork.DureeMatch > 0.04 / ModeleRobot_P.SFunction_p17)
          {
            /* Transition: '<S1>:2244' */
            /* Exit 'INIT_STRATEGIE': '<S1>:1128' */
            ModeleRobot_DWork.is_STRATEGIE1 = (uint8_T)
              ModeleRobot_IN_NO_ACTIVE_CHILD;
            enter_atomic_GOTO_BAS_DES_MARCH();
            enter_internal_GOTO_BAS_DES_MAR();
          }
          break;

         case ModeleRobot_IN_MONTE_MARCHE:
          /* During 'MONTE_MARCHE': '<S1>:3983' */
          /*  Pas de détection d'obostacle pendant la montée des marches */
          ModeleRobot_DWork.Tempo = ModeleRobot_DWork.Tempo + 1.0;
          switch (ModeleRobot_DWork.is_MONTE_MARCHE) {
           case ModeleRobot_IN_ACTION_010:
            /* During 'ACTION_010': '<S1>:4054' */
            if (ModeleRobot_DWork.Tempo > 0.5 / ModeleRobot_P.SFunction_p17) {
              /* Transition: '<S1>:4018' */
              /* Exit 'ACTION_010': '<S1>:4054' */
              /* Entry 'ACTION_013': '<S1>:4074' */
              ModeleRobot_DWork.is_MONTE_MARCHE = (uint8_T)
                ModeleRobot_IN_ACTION_013;
              ModeleRobot_DWork.was_MONTE_MARCHE = (uint8_T)
                ModeleRobot_IN_ACTION_013;

              /* Tempo=0; */
              /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
              /* Transition: '<S1>:1301' */
              ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
              ModeleRobot_B.CommandeManuelleG = 0.0;
              ModeleRobot_B.CommandeManuelleD = 0.0;
            }
            break;

           case ModeleRobot_IN_ACTION_012:
            /* During 'ACTION_012': '<S1>:4061' */
            if (ModeleRobot_DWork.Tempo > 4.0 / ModeleRobot_P.SFunction_p17) {
              /* Transition: '<S1>:4063' */
              /* Exit 'ACTION_012': '<S1>:4061' */
              /* Entry 'ACTION_09': '<S1>:4047' */
              ModeleRobot_DWork.is_MONTE_MARCHE = (uint8_T)
                ModeleRobot_IN_ACTION_09;
              ModeleRobot_DWork.was_MONTE_MARCHE = (uint8_T)
                ModeleRobot_IN_ACTION_09;
              ModeleRobot_DWork.Tempo = 0.0;

              /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
              /* Transition: '<S1>:1301' */
              ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
              ModeleRobot_B.CommandeManuelleG = 0.0;
              ModeleRobot_B.CommandeManuelleD = 0.0;
            }
            break;

           case ModeleRobot_IN_ACTION_013:
            /* During 'ACTION_013': '<S1>:4074' */
            if (ModeleRobot_DWork.Tempo > 0.1 / ModeleRobot_P.SFunction_p17) {
              /* Transition: '<S1>:4076' */
              /* Exit 'ACTION_013': '<S1>:4074' */
              /* Entry 'ACTION_014': '<S1>:4075' */
              ModeleRobot_DWork.is_MONTE_MARCHE = (uint8_T)
                ModeleRobot_IN_ACTION_014;
              ModeleRobot_DWork.was_MONTE_MARCHE = (uint8_T)
                ModeleRobot_IN_ACTION_014;
              ModeleRobot_DWork.Tempo = 0.0;

              /* Graphical Function 'setServo': '<S1>:3938' */
              /* Transition: '<S1>:3940' */
              ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p12 - 1.0)]
                = 130.0;
            }
            break;

           case ModeleRobot_IN_ACTION_014:
            /* During 'ACTION_014': '<S1>:4075' */
            /* Transition: '<S1>:4078' */
            /* Exit 'ACTION_014': '<S1>:4075' */
            /* Entry 'ACTION_015': '<S1>:4077' */
            ModeleRobot_DWork.is_MONTE_MARCHE = (uint8_T)
              ModeleRobot_IN_ACTION_015;
            ModeleRobot_DWork.was_MONTE_MARCHE = (uint8_T)
              ModeleRobot_IN_ACTION_015;

            /* Tempo=0; */
            /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
            /* Transition: '<S1>:1301' */
            ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
            ModeleRobot_B.CommandeManuelleG = 70.0;
            ModeleRobot_B.CommandeManuelleD = 71.0;
            break;

           case ModeleRobot_IN_ACTION_015:
            /* During 'ACTION_015': '<S1>:4077' */
            if (ModeleRobot_U.IN_inclinaison > 50.0) {
              /* Transition: '<S1>:4079' */
              /* Exit 'ACTION_015': '<S1>:4077' */
              /* Entry 'ACTION_03': '<S1>:4015' */
              ModeleRobot_DWork.is_MONTE_MARCHE = (uint8_T)
                ModeleRobot_IN_ACTION_03_p;
              ModeleRobot_DWork.was_MONTE_MARCHE = (uint8_T)
                ModeleRobot_IN_ACTION_03_p;
              ModeleRobot_DWork.Tempo = 0.0;

              /* Graphical Function 'setServo': '<S1>:3938' */
              /* Transition: '<S1>:3940' */
              ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p13 - 1.0)]
                = ModeleRobot_P.SFunction_p15;

              /* Graphical Function 'CommandeLEDS': '<S1>:1339' */
              /* Transition: '<S1>:1341' */
              ModeleRobot_B.EtatLed1 = 1.0;
              ModeleRobot_B.EtatLed2 = 0.0;
              ModeleRobot_B.EtatLed3 = 1.0;
              ModeleRobot_B.EtatLed4 = 1.0;
            }
            break;

           case ModeleRobot_IN_ACTION_02_p:
            /* During 'ACTION_02': '<S1>:4009' */
            if ((ModeleRobot_DWork.Tempo > 2.0 / ModeleRobot_P.SFunction_p17) &&
                (ModeleRobot_U.IN_inclinaison < 20.0)) {
              /* Transition: '<S1>:4056' */
              /* Exit 'ACTION_02': '<S1>:4009' */
              /* Entry 'ACTION_010': '<S1>:4054' */
              ModeleRobot_DWork.is_MONTE_MARCHE = (uint8_T)
                ModeleRobot_IN_ACTION_010;
              ModeleRobot_DWork.was_MONTE_MARCHE = (uint8_T)
                ModeleRobot_IN_ACTION_010;
              ModeleRobot_DWork.Tempo = 0.0;

              /* Graphical Function 'setServo': '<S1>:3938' */
              /* Transition: '<S1>:3940' */
              ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p12 - 1.0)]
                = 115.0;
            } else {
              if ((ModeleRobot_DWork.Tempo > 2.0 / ModeleRobot_P.SFunction_p17) ||
                  (ModeleRobot_U.IN_inclinaison > 50.0)) {
                /* Transition: '<S1>:4072' */
                /* Exit 'ACTION_02': '<S1>:4009' */
                /* Entry 'ACTION_03': '<S1>:4015' */
                ModeleRobot_DWork.is_MONTE_MARCHE = (uint8_T)
                  ModeleRobot_IN_ACTION_03_p;
                ModeleRobot_DWork.was_MONTE_MARCHE = (uint8_T)
                  ModeleRobot_IN_ACTION_03_p;
                ModeleRobot_DWork.Tempo = 0.0;

                /* Graphical Function 'setServo': '<S1>:3938' */
                /* Transition: '<S1>:3940' */
                ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p13 -
                  1.0)] = ModeleRobot_P.SFunction_p15;

                /* Graphical Function 'CommandeLEDS': '<S1>:1339' */
                /* Transition: '<S1>:1341' */
                ModeleRobot_B.EtatLed1 = 1.0;
                ModeleRobot_B.EtatLed2 = 0.0;
                ModeleRobot_B.EtatLed3 = 1.0;
                ModeleRobot_B.EtatLed4 = 1.0;
              }
            }
            break;

           case ModeleRobot_IN_ACTION_03_p:
            /* During 'ACTION_03': '<S1>:4015' */
            if (ModeleRobot_DWork.Tempo > 5.3 / ModeleRobot_P.SFunction_p17) {
              /* Transition: '<S1>:4029' */
              /* Exit 'ACTION_03': '<S1>:4015' */
              /* Entry 'ACTION_04': '<S1>:4028' */
              ModeleRobot_DWork.is_MONTE_MARCHE = (uint8_T)
                ModeleRobot_IN_ACTION_04_p;
              ModeleRobot_DWork.was_MONTE_MARCHE = (uint8_T)
                ModeleRobot_IN_ACTION_04_p;
              ModeleRobot_DWork.Tempo = 0.0;

              /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
              /* Transition: '<S1>:1301' */
              ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
              ModeleRobot_B.CommandeManuelleG = 0.0;
              ModeleRobot_B.CommandeManuelleD = 0.0;

              /* Graphical Function 'setServo': '<S1>:3938' */
              /* Transition: '<S1>:3940' */
              ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p6 - 1.0)]
                = ModeleRobot_P.SFunction_p8;

              /* Graphical Function 'CommandeLEDS': '<S1>:1339' */
              /* Transition: '<S1>:1341' */
              ModeleRobot_B.EtatLed1 = 1.0;
              ModeleRobot_B.EtatLed2 = 0.0;
              ModeleRobot_B.EtatLed3 = 0.0;
              ModeleRobot_B.EtatLed4 = 1.0;
            }
            break;

           case ModeleRobot_IN_ACTION_04_p:
            /* During 'ACTION_04': '<S1>:4028' */
            if (ModeleRobot_DWork.Tempo > 1.0 / ModeleRobot_P.SFunction_p17) {
              /* Transition: '<S1>:4031' */
              /* Exit 'ACTION_04': '<S1>:4028' */
              /* Entry 'ACTION_05': '<S1>:4033' */
              ModeleRobot_DWork.is_MONTE_MARCHE = (uint8_T)
                ModeleRobot_IN_ACTION_05_p;
              ModeleRobot_DWork.was_MONTE_MARCHE = (uint8_T)
                ModeleRobot_IN_ACTION_05_p;
              ModeleRobot_DWork.Tempo = 0.0;

              /* Graphical Function 'setServo': '<S1>:3938' */
              /* Transition: '<S1>:3940' */
              ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p6 - 1.0)]
                = ModeleRobot_P.SFunction_p7;

              /* Graphical Function 'CommandeLEDS': '<S1>:1339' */
              /* Transition: '<S1>:1341' */
              ModeleRobot_B.EtatLed1 = 1.0;
              ModeleRobot_B.EtatLed2 = 0.0;
              ModeleRobot_B.EtatLed3 = 0.0;
              ModeleRobot_B.EtatLed4 = 0.0;
            }
            break;

           case ModeleRobot_IN_ACTION_05_p:
            /* During 'ACTION_05': '<S1>:4033' */
            if (ModeleRobot_DWork.Tempo > 0.5 / ModeleRobot_P.SFunction_p17) {
              /* Transition: '<S1>:4032' */
              /* Exit 'ACTION_05': '<S1>:4033' */
              /* Entry 'ACTION_06': '<S1>:4038' */
              ModeleRobot_DWork.is_MONTE_MARCHE = (uint8_T)
                ModeleRobot_IN_ACTION_06_p;
              ModeleRobot_DWork.was_MONTE_MARCHE = (uint8_T)
                ModeleRobot_IN_ACTION_06_p;
              ModeleRobot_DWork.Tempo = 0.0;

              /* Graphical Function 'setServo': '<S1>:3938' */
              /* Transition: '<S1>:3940' */
              ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p9 - 1.0)]
                = ModeleRobot_P.SFunction_p11;
            }
            break;

           case ModeleRobot_IN_ACTION_06_p:
            /* During 'ACTION_06': '<S1>:4038' */
            if (ModeleRobot_DWork.Tempo > 1.0 / ModeleRobot_P.SFunction_p17) {
              /* Transition: '<S1>:4037' */
              /* Exit 'ACTION_06': '<S1>:4038' */
              /* Entry 'ACTION_07': '<S1>:4043' */
              ModeleRobot_DWork.is_MONTE_MARCHE = (uint8_T)
                ModeleRobot_IN_ACTION_07_p;
              ModeleRobot_DWork.was_MONTE_MARCHE = (uint8_T)
                ModeleRobot_IN_ACTION_07_p;
              ModeleRobot_DWork.Tempo = 0.0;

              /* Graphical Function 'setServo': '<S1>:3938' */
              /* Transition: '<S1>:3940' */
              ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p9 - 1.0)]
                = ModeleRobot_P.SFunction_p10;

              /* Graphical Function 'Mouvement_Manuel': '<S1>:1299' */
              /* Transition: '<S1>:1301' */
              ModeleRobot_B.DdeMvtManuel = ModeleRobot_B.DdeMvtManuel + 1.0;
              ModeleRobot_B.CommandeManuelleG = 68.0;
              ModeleRobot_B.CommandeManuelleD = 70.0;
            }
            break;

           case ModeleRobot_IN_ACTION_07_p:
            /* During 'ACTION_07': '<S1>:4043' */
            if ((ModeleRobot_DWork.Tempo > 12.0 / ModeleRobot_P.SFunction_p17) ||
                (ModeleRobot_U.IN_inclinaison < 30.0)) {
              /* Transition: '<S1>:4042' */
              /* Exit 'ACTION_07': '<S1>:4043' */
              /* Entry 'ACTION_08': '<S1>:4044' */
              ModeleRobot_DWork.is_MONTE_MARCHE = (uint8_T)
                ModeleRobot_IN_ACTION_08;
              ModeleRobot_DWork.was_MONTE_MARCHE = (uint8_T)
                ModeleRobot_IN_ACTION_08;
              ModeleRobot_DWork.Tempo = 0.0;

              /* setServo(SERVO_DOIGT, 115); */
              /* Graphical Function 'setServo': '<S1>:3938' */
              /* Transition: '<S1>:3940' */
              ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p13 - 1.0)]
                = ModeleRobot_P.SFunction_p14;
            }
            break;

           case ModeleRobot_IN_ACTION_08:
            /* During 'ACTION_08': '<S1>:4044' */
            if (ModeleRobot_DWork.Tempo > 1.0 / ModeleRobot_P.SFunction_p17) {
              /* Transition: '<S1>:4045' */
              /* Exit 'ACTION_08': '<S1>:4044' */
              /* Entry 'ACTION_012': '<S1>:4061' */
              ModeleRobot_DWork.is_MONTE_MARCHE = (uint8_T)
                ModeleRobot_IN_ACTION_012;
              ModeleRobot_DWork.was_MONTE_MARCHE = (uint8_T)
                ModeleRobot_IN_ACTION_012;
              ModeleRobot_DWork.Tempo = 0.0;

              /* Graphical Function 'setServo': '<S1>:3938' */
              /* Transition: '<S1>:3940' */
              ModeleRobot_B.CmdServo[(int32_T)(ModeleRobot_P.SFunction_p12 - 1.0)]
                = 115.0;

              /* setServo(SERVO_INCLINAISON, SERVO_INCLINAISON_DROIT); */
            }
            break;

           case ModeleRobot_IN_ACTION_09:
            break;

           default:
            Mod_enter_internal_MONTE_MARCHE();
            break;
          }
          break;

         default:
          Model_enter_internal_STRATEGIE1();
          break;
        }
      }
      break;

     default:
      enter_internal_COMPORTEMENT_ROB();
      break;
    }
  }
}

/* Model step function */
void ModeleRobot_step(void)
{
  real_T rtb_Switch;
  real_T rtb_Switch1;
  int32_T i;

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<Root>/LimiteOut1'
   *  Constant: '<Root>/LimiteOut2'
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/SeuilDistance'
   *  Inport: '<Root>/IN_ObstacleAV'
   *  Logic: '<S2>/Logical Operator'
   *  RelationalOperator: '<S14>/Compare'
   *  RelationalOperator: '<S2>/Relational Operator'
   *  RelationalOperator: '<S2>/Relational Operator1'
   */
  if ((ModeleRobot_P.LimiteOut2_Value > 0.0) >= ModeleRobot_P.Switch_Threshold)
  {
    rtb_Switch = (real_T)((ModeleRobot_P.LimiteOut1_Value <=
      ModeleRobot_P.SeuilDistance_Value) || (ModeleRobot_U.IN_ObstacleAV <=
      ModeleRobot_P.SeuilDistance_Value));
  } else {
    rtb_Switch = ModeleRobot_P.Constant1_Value;
  }

  /* Switch: '<S2>/Switch1' incorporates:
   *  Constant: '<Root>/LimiteOut'
   *  Constant: '<Root>/LimiteOut2'
   *  Constant: '<Root>/LimiteOut3'
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/SeuilDistance'
   *  Logic: '<S2>/Logical Operator1'
   *  RelationalOperator: '<S13>/Compare'
   *  RelationalOperator: '<S2>/Relational Operator2'
   *  RelationalOperator: '<S2>/Relational Operator3'
   */
  if ((ModeleRobot_P.LimiteOut2_Value < 0.0) >= ModeleRobot_P.Switch1_Threshold)
  {
    rtb_Switch1 = (real_T)((ModeleRobot_P.LimiteOut_Value <=
      ModeleRobot_P.SeuilDistance_Value) || (ModeleRobot_P.LimiteOut3_Value <=
      ModeleRobot_P.SeuilDistance_Value));
  } else {
    rtb_Switch1 = ModeleRobot_P.Constant_Value_e;
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  Logic: '<S2>/Logical Operator2'
   */
  ModeleRobot_Y.OUT_isObstacle = ((rtb_Switch != 0.0) || (rtb_Switch1 != 0.0));

  /* Stateflow: '<Root>/COMPORTEMENT' */
  ModeleRobot_COMPORTEMENT();

  /* Outport: '<Root>/OUT_ConsigneX' */
  ModeleRobot_Y.OUT_ConsigneX = ModeleRobot_B.ConsigneX;

  /* Outport: '<Root>/OUT_ConsigneY' */
  ModeleRobot_Y.OUT_ConsigneY = ModeleRobot_B.ConsigneY;

  /* Outport: '<Root>/OUT_DdeMvtXY' */
  ModeleRobot_Y.OUT_DdeMvtXY = ModeleRobot_B.DdeMvtXY;

  /* Outport: '<Root>/OUT_ConsigneTeta' */
  ModeleRobot_Y.OUT_ConsigneTeta = ModeleRobot_B.ConsigneTeta;

  /* Outport: '<Root>/OUT_ConsigneVitesseAngle' */
  ModeleRobot_Y.OUT_ConsigneVitesseAngle = ModeleRobot_B.ConsigneVitesseAngle;

  /* Outport: '<Root>/OUT_ConsigneDistance' */
  ModeleRobot_Y.OUT_ConsigneDistance = ModeleRobot_B.ConsigneDistance;

  /* Outport: '<Root>/OUT_ConsigneVitesseDistance' */
  ModeleRobot_Y.OUT_ConsigneVitesseDistance =
    ModeleRobot_B.ConsigneVitesseDistance;

  /* Outport: '<Root>/OUT_DdeMvtDistanceAngle' */
  ModeleRobot_Y.OUT_DdeMvtDistanceAngle = ModeleRobot_B.DdeMvtDistanceAngle;

  /* Outport: '<Root>/OUT_CommandeManuelleG' */
  ModeleRobot_Y.OUT_CommandeManuelleG = ModeleRobot_B.CommandeManuelleG;

  /* Outport: '<Root>/OUT_CommandeManuelleD' */
  ModeleRobot_Y.OUT_CommandeManuelleD = ModeleRobot_B.CommandeManuelleD;

  /* Outport: '<Root>/OUT_DdeMvtManuel' */
  ModeleRobot_Y.OUT_DdeMvtManuel = ModeleRobot_B.DdeMvtManuel;
  for (i = 0; i < 20; i++) {
    /* Outport: '<Root>/OUT_CommandeServo' */
    ModeleRobot_Y.OUT_CommandeServo[i] = ModeleRobot_B.CmdServo[i];

    /* Outport: '<Root>/OUT_SpeedServo' */
    ModeleRobot_Y.OUT_SpeedServo[i] = ModeleRobot_B.SpdServo[i];
  }

  /* Outport: '<Root>/OUT_EtatLed1' */
  ModeleRobot_Y.OUT_EtatLed1 = ModeleRobot_B.EtatLed1;

  /* Outport: '<Root>/OUT_EtatLed2' */
  ModeleRobot_Y.OUT_EtatLed2 = ModeleRobot_B.EtatLed2;

  /* Outport: '<Root>/OUT_EtatLed3' */
  ModeleRobot_Y.OUT_EtatLed3 = ModeleRobot_B.EtatLed3;

  /* Outport: '<Root>/OUT_EtatLed4' */
  ModeleRobot_Y.OUT_EtatLed4 = ModeleRobot_B.EtatLed4;

  /* Outport: '<Root>/OUT_DdeMvtXYTeta' */
  ModeleRobot_Y.OUT_DdeMvtXYTeta = ModeleRobot_B.DdeMvtXYTeta;

  /* Outport: '<Root>/OUT_OuvertureElectroAimants' */
  ModeleRobot_Y.OUT_OuvertureElectroAimants =
    ModeleRobot_B.OuvertureElectroAimants;

  /* Outport: '<Root>/OUT_DdeRecalagePosition' */
  ModeleRobot_Y.OUT_DdeRecalagePosition = ModeleRobot_B.DdeRecalagePosition;
}

/* Model initialize function */
void ModeleRobot_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* InitializeConditions for Stateflow: '<Root>/COMPORTEMENT' */
  ModeleRobot_COMPORTEMENT_Init();
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
