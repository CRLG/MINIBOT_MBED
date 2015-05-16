/*
 * File: ModeleRobot_data.c
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

/* Block parameters (auto storage) */
Parameters_ModeleRobot ModeleRobot_P = {
  20.0,                                /* Expression: 20
                                        * Referenced by: '<S2>/SeuilDistance'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/LimiteOut2'
                                        */
  1.0,                                 /* Expression: const
                                        * Referenced by: '<S6>/Constant'
                                        */
  0.0,                                 /* Expression: vinit
                                        * Referenced by: '<S7>/Delay Input1'
                                        */
  2.0,                                 /* Expression: const
                                        * Referenced by: '<S9>/Constant'
                                        */
  0.0,                                 /* Expression: vinit
                                        * Referenced by: '<S10>/Delay Input1'
                                        */
  0.0,                                 /* Expression: EQUIPE_JAUNE
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  1.0,                                 /* Expression: EQUIPE_VERTE
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  0.0,                                 /* Expression: MAX_SPEED_SERVOS
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  3.1415926535897931E+000,             /* Expression: PI
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  14.0,                                /* Expression: SERVO_BRAS_D
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  5.0,                                 /* Expression: SERVO_BRAS_D_FERME
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  104.0,                               /* Expression: SERVO_BRAS_D_OUVERT
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  15.0,                                /* Expression: SERVO_BRAS_G
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  18.0,                                /* Expression: SERVO_BRAS_G_FERME
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  62.0,                                /* Expression: SERVO_BRAS_G_OUVERT
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  16.0,                                /* Expression: SERVO_DOIGT
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  13.0,                                /* Expression: SERVO_INCLINAISON
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  8.0,                                 /* Expression: SERVO_INCLINAISON_DROIT
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  80.0,                                /* Expression: SERVO_INCLINAISON_PENCHE
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  0.02,                                /* Expression: Te
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */
  1000.0,                              /* Expression: 1000
                                        * Referenced by: '<Root>/LimiteOut3'
                                        */
  1000.0,                              /* Expression: 1000
                                        * Referenced by: '<Root>/LimiteOut'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant1'
                                        */
  1000.0,                              /* Expression: 1000
                                        * Referenced by: '<Root>/LimiteOut1'
                                        */
  1,                                   /* Computed Parameter: SFunction_p3
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  1,                                   /* Computed Parameter: SFunction_p16
                                        * Referenced by: '<Root>/COMPORTEMENT'
                                        */
  1U,                                  /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S2>/Switch'
                                        */
  1U                                   /* Computed Parameter: Switch1_Threshold
                                        * Referenced by: '<S2>/Switch1'
                                        */
};

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
