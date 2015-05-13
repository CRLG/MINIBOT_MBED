/*
 * File: ModeleRobot.h
 *
 * Real-Time Workshop code generated for Simulink model ModeleRobot.
 *
 * Model version                        : 1.1311
 * Real-Time Workshop file version      : 7.4  (R2009b)  29-Jun-2009
 * Real-Time Workshop file generated on : Thu May 14 01:38:49 2015
 * TLC version                          : 7.4 (Jul 14 2009)
 * C/C++ source code generated on       : Thu May 14 01:38:50 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objective: Efficiency
 * Validation result: Passed (9), Warning (1), Error (0)
 */

#ifndef RTW_HEADER_ModeleRobot_h_
#define RTW_HEADER_ModeleRobot_h_
#ifndef ModeleRobot_COMMON_INCLUDES_
# define ModeleRobot_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ModeleRobot_COMMON_INCLUDES_ */

#include "ModeleRobot_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((void*) 0)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((void) 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T ConsigneX;                    /* '<Root>/COMPORTEMENT' */
  real_T ConsigneY;                    /* '<Root>/COMPORTEMENT' */
  real_T DdeMvtXY;                     /* '<Root>/COMPORTEMENT' */
  real_T ConsigneTeta;                 /* '<Root>/COMPORTEMENT' */
  real_T ConsigneVitesseAngle;         /* '<Root>/COMPORTEMENT' */
  real_T ConsigneDistance;             /* '<Root>/COMPORTEMENT' */
  real_T ConsigneVitesseDistance;      /* '<Root>/COMPORTEMENT' */
  real_T DdeMvtDistanceAngle;          /* '<Root>/COMPORTEMENT' */
  real_T CommandeManuelleG;            /* '<Root>/COMPORTEMENT' */
  real_T CommandeManuelleD;            /* '<Root>/COMPORTEMENT' */
  real_T DdeMvtManuel;                 /* '<Root>/COMPORTEMENT' */
  real_T CmdServo[20];                 /* '<Root>/COMPORTEMENT' */
  real_T SpdServo[20];                 /* '<Root>/COMPORTEMENT' */
  real_T EtatLed1;                     /* '<Root>/COMPORTEMENT' */
  real_T EtatLed2;                     /* '<Root>/COMPORTEMENT' */
  real_T EtatLed3;                     /* '<Root>/COMPORTEMENT' */
  real_T EtatLed4;                     /* '<Root>/COMPORTEMENT' */
  real_T DdeMvtXYTeta;                 /* '<Root>/COMPORTEMENT' */
  real_T OuvertureElectroAimants;      /* '<Root>/COMPORTEMENT' */
  real_T DdeRecalagePosition;          /* '<Root>/COMPORTEMENT' */
} BlockIO_ModeleRobot;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S10>/Delay Input1' */
  real_T DelayInput1_DSTATE_d;         /* '<S7>/Delay Input1' */
  real_T DureeMatch;                   /* '<Root>/COMPORTEMENT' */
  real_T invMouv;                      /* '<Root>/COMPORTEMENT' */
  real_T Tempo;                        /* '<Root>/COMPORTEMENT' */
  real_T TempoInit;                    /* '<Root>/COMPORTEMENT' */
  real_T TempoTestActionneurs;         /* '<Root>/COMPORTEMENT' */
  real_T EvitementEnCours;             /* '<Root>/COMPORTEMENT' */
  real_T x_old;                        /* '<Root>/COMPORTEMENT' */
  real_T y_old;                        /* '<Root>/COMPORTEMENT' */
  real_T inhibeObstacle;               /* '<Root>/COMPORTEMENT' */
  real_T TempoImage;                   /* '<Root>/COMPORTEMENT' */
  real_T local_Tempo;                  /* '<Root>/COMPORTEMENT' */
  uint8_T is_active_c1_ModeleRobot;    /* '<Root>/COMPORTEMENT' */
  uint8_T is_active_COMPORTEMENT_ROBOT;/* '<Root>/COMPORTEMENT' */
  uint8_T is_COMPORTEMENT_ROBOT;       /* '<Root>/COMPORTEMENT' */
  uint8_T is_active_FONCTIONS_GLOBALES_DE;/* '<Root>/COMPORTEMENT' */
  uint8_T is_active_FONCTIONS_GLOBALES_CO;/* '<Root>/COMPORTEMENT' */
  uint8_T is_active_FONCTIONS_GLOBALES__j;/* '<Root>/COMPORTEMENT' */
  uint8_T is_active_ACTIONNEURS_REPOS; /* '<Root>/COMPORTEMENT' */
  uint8_T is_ACTIONNEURS_REPOS;        /* '<Root>/COMPORTEMENT' */
  uint8_T is_active_CHOIX_EQUIPE;      /* '<Root>/COMPORTEMENT' */
  uint8_T is_CHOIX_EQUIPE;             /* '<Root>/COMPORTEMENT' */
  uint8_T is_active_RECALAGE;          /* '<Root>/COMPORTEMENT' */
  uint8_T is_RECALAGE;                 /* '<Root>/COMPORTEMENT' */
  uint8_T is_active_FONCTIONS_GLOBALES__i;/* '<Root>/COMPORTEMENT' */
  uint8_T is_active_TESTS_ACTIONNEUR;  /* '<Root>/COMPORTEMENT' */
  uint8_T is_TESTS_ACTIONNEUR;         /* '<Root>/COMPORTEMENT' */
  uint8_T is_active_FONCTIONS_GLOBALES_DI;/* '<Root>/COMPORTEMENT' */
  uint8_T is_FIN_MATCH;                /* '<Root>/COMPORTEMENT' */
  uint8_T is_active_STRATEGIE;         /* '<Root>/COMPORTEMENT' */
  uint8_T is_STRATEGIE;                /* '<Root>/COMPORTEMENT' */
  uint8_T is_STRATEGIE1;               /* '<Root>/COMPORTEMENT' */
  uint8_T was_STRATEGIE1;              /* '<Root>/COMPORTEMENT' */
  uint8_T is_active_CLOCK;             /* '<Root>/COMPORTEMENT' */
  uint8_T is_DEMO;                     /* '<Root>/COMPORTEMENT' */
  uint8_T was_DEMO;                    /* '<Root>/COMPORTEMENT' */
  uint8_T is_active_FONCTIONS_RECalAGE_PO;/* '<Root>/COMPORTEMENT' */
  uint8_T is_EVITEMENT;                /* '<Root>/COMPORTEMENT' */
  uint8_T is_active_TESTS_CAPTEURS;    /* '<Root>/COMPORTEMENT' */
} D_Work_ModeleRobot;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T IN_Tirette;                   /* '<Root>/IN_Tirette' */
  real_T IN_x_pos;                     /* '<Root>/IN_x_pos' */
  real_T IN_y_pos;                     /* '<Root>/IN_y_pos' */
  real_T IN_teta_pos;                  /* '<Root>/IN_teta_pos' */
  real_T IN_ConvergenceMvt;            /* '<Root>/IN_ConvergenceMvt' */
  real_T IN_CouleurEquipe;             /* '<Root>/IN_CouleurEquipe' */
  real_T IN_ObstacleAV;                /* '<Root>/IN_ObstacleAV' */
  real_T IN_Temps_absolu;              /* '<Root>/IN_Temps_absolu' */
  uint8_T IN_demande_test_actionneurs; /* '<Root>/IN_demande_test_actionneurs' */
  real_T IN_ObstacleAR;                /* '<Root>/IN_ObstacleAR' */
  real_T IN_ConvergenceMvt_Rapide;     /* '<Root>/IN_ConvergenceMvt_Rapide' */
  real_T IN_Vitesse;                   /* '<Root>/IN_Vitesse' */
  real_T IN_SensDeplacement;           /* '<Root>/IN_SensDeplacement' */
  uint8_T IN_isDepression;             /* '<Root>/IN_isDepression' */
  uint8_T IN_isMurFresque;             /* '<Root>/IN_isMurFresque' */
} ExternalInputs_ModeleRobot;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T OUT_ConsigneX;                /* '<Root>/OUT_ConsigneX' */
  real_T OUT_ConsigneY;                /* '<Root>/OUT_ConsigneY' */
  real_T OUT_DdeMvtXY;                 /* '<Root>/OUT_DdeMvtXY' */
  real_T OUT_ConsigneTeta;             /* '<Root>/OUT_ConsigneTeta' */
  real_T OUT_ConsigneVitesseAngle;     /* '<Root>/OUT_ConsigneVitesseAngle' */
  real_T OUT_ConsigneDistance;         /* '<Root>/OUT_ConsigneDistance' */
  real_T OUT_ConsigneVitesseDistance;  /* '<Root>/OUT_ConsigneVitesseDistance' */
  real_T OUT_DdeMvtDistanceAngle;      /* '<Root>/OUT_DdeMvtDistanceAngle' */
  real_T OUT_CommandeManuelleG;        /* '<Root>/OUT_CommandeManuelleG' */
  real_T OUT_CommandeManuelleD;        /* '<Root>/OUT_CommandeManuelleD' */
  real_T OUT_DdeMvtManuel;             /* '<Root>/OUT_DdeMvtManuel' */
  real_T OUT_CommandeServo[20];        /* '<Root>/OUT_CommandeServo' */
  real_T OUT_SpeedServo[20];           /* '<Root>/OUT_SpeedServo' */
  real_T OUT_EtatLed1;                 /* '<Root>/OUT_EtatLed1' */
  real_T OUT_EtatLed2;                 /* '<Root>/OUT_EtatLed2' */
  real_T OUT_EtatLed3;                 /* '<Root>/OUT_EtatLed3' */
  real_T OUT_EtatLed4;                 /* '<Root>/OUT_EtatLed4' */
  real_T OUT_DdeMvtXYTeta;             /* '<Root>/OUT_DdeMvtXYTeta' */
  real_T OUT_OuvertureElectroAimants;  /* '<Root>/OUT_OuvertureElectroAimants' */
  real_T OUT_DdeRecalagePosition;      /* '<Root>/OUT_DdeRecalagePosition' */
  uint8_T OUT_isObstacle;              /* '<Root>/OUT_isObstacle' */
} ExternalOutputs_ModeleRobot;

/* Parameters (auto storage) */
struct Parameters_ModeleRobot_ {
  real_T SeuilDistance_Value;          /* Expression: 20
                                        * Referenced by: '<S2>/SeuilDistance'
                                        */
  real_T LimiteOut2_Value;             /* Expression: 1
                                        * Referenced by: '<Root>/LimiteOut2'
                                        */
  real_T Constant_Value;               /* Expression: const
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T DelayInput1_X0;               /* Expression: vinit
                                        * Referenced by: '<S7>/Delay Input1'
                                        */
  real_T Constant_Value_h;             /* Expression: const
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T DelayInput1_X0_o;             /* Expression: vinit
                                        * Referenced by: '<S10>/Delay Input1'
                                        */
  real_T SFunction_p1;                 /* Expression: EQUIPE_JAUNE
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p2;                 /* Expression: EQUIPE_VERTE
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p4;                 /* Expression: MAX_SPEED_SERVOS
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p5;                 /* Expression: PI
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p6;                 /* Expression: SERVO_BEQUILLE
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p7;                 /* Expression: SERVO_BRAS_D
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p8;                 /* Expression: SERVO_BRAS_D_FERME
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p9;                 /* Expression: SERVO_BRAS_D_OUVERT
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p10;                /* Expression: SERVO_BRAS_G
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p11;                /* Expression: SERVO_BRAS_G_FERME
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p12;                /* Expression: SERVO_BRAS_G_OUVERT
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p13;                /* Expression: SERVO_INCLINAISON
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p14;                /* Expression: SERVO_INCLINAISON_DROIT
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p15;                /* Expression: SERVO_INCLINAISON_PENCHE
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T SFunction_p17;                /* Expression: Te
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  real_T Constant_Value_e;             /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T LimiteOut3_Value;             /* Expression: 1000
                                        * Referenced by: '<Root>/LimiteOut3'
                                        */
  real_T LimiteOut_Value;              /* Expression: 1000
                                        * Referenced by: '<Root>/LimiteOut'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T LimiteOut1_Value;             /* Expression: 1000
                                        * Referenced by: '<Root>/LimiteOut1'
                                        */
  int8_T SFunction_p3;                 /* Computed Parameter: SFunction_p3
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  int8_T SFunction_p16;                /* Computed Parameter: SFunction_p16
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  uint8_T Switch_Threshold;            /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S2>/Switch'
                                        */
  uint8_T Switch1_Threshold;           /* Computed Parameter: Switch1_Threshold
                                        * Referenced by: '<S2>/Switch1'
                                        */
};

/* Block parameters (auto storage) */
extern Parameters_ModeleRobot ModeleRobot_P;

/* Block signals (auto storage) */
extern BlockIO_ModeleRobot ModeleRobot_B;

/* Block states (auto storage) */
extern D_Work_ModeleRobot ModeleRobot_DWork;

/* External inputs (root inport signals with auto storage) */
extern ExternalInputs_ModeleRobot ModeleRobot_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_ModeleRobot ModeleRobot_Y;

/* Model entry point functions */
extern void ModeleRobot_initialize(boolean_T firstTime);
extern void ModeleRobot_step(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : ModeleRobot
 * '<S1>'   : ModeleRobot/COMPORTEMENT
 * '<S2>'   : ModeleRobot/DetectionObstacle
 * '<S3>'   : ModeleRobot/Model Info
 * '<S4>'   : ModeleRobot/COMPORTEMENT/isFrontMontantConvergence
 * '<S5>'   : ModeleRobot/COMPORTEMENT/isFrontMontantMvtBloque
 * '<S6>'   : ModeleRobot/COMPORTEMENT/isFrontMontantConvergence/Compare To Constant
 * '<S7>'   : ModeleRobot/COMPORTEMENT/isFrontMontantConvergence/Detect Change
 * '<S8>'   : ModeleRobot/COMPORTEMENT/isFrontMontantConvergence/Model Info
 * '<S9>'   : ModeleRobot/COMPORTEMENT/isFrontMontantMvtBloque/Compare To Constant
 * '<S10>'  : ModeleRobot/COMPORTEMENT/isFrontMontantMvtBloque/Detect Change
 * '<S11>'  : ModeleRobot/COMPORTEMENT/isFrontMontantMvtBloque/Model Info
 * '<S12>'  : ModeleRobot/DetectionObstacle/Model Info
 * '<S13>'  : ModeleRobot/DetectionObstacle/marcheArriere
 * '<S14>'  : ModeleRobot/DetectionObstacle/marcheAvant
 */
#endif                                 /* RTW_HEADER_ModeleRobot_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
