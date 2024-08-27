/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: RW1.h
 *
 * Code generated for Simulink model 'RW1'.
 *
 * Model version                  : 1.66
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Nov 30 13:04:30 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_RW1_h_
#define RTW_HEADER_RW1_h_
#ifndef RW1_COMMON_INCLUDES_
#define RW1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* RW1_COMMON_INCLUDES_ */

#include <string.h>
#include <stddef.h>

/* Model Code Variants */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#define RW1_M                          (rtM)

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>/RW1 Steering Angle' */
typedef struct {
  real_T theta_D;                      /* '<S1>/Transfer Fcn1' */
  real_T BackEMFConstant;              /* '<S1>/Back EMF Constant' */
  real_T Integrator;                   /* '<S37>/Integrator' */
  real_T Memory4;                      /* '<S4>/Memory4' */
  real_T Memory3;                      /* '<S4>/Memory3' */
  real_T Filter;                       /* '<S32>/Filter' */
  real_T Sum1;                         /* '<S1>/Sum1' */
  real_T d;                            /* '<S4>/Switch' */
  real_T Memory4_PreviousInput;        /* '<S4>/Memory4' */
  real_T Memory3_PreviousInput;        /* '<S4>/Memory3' */
} DW_RW1SteeringAngle;

/* Continuous states for system '<Root>/RW1 Steering Angle' */
typedef struct {
  real_T TransferFcn1_CSTATE;          /* '<S1>/Transfer Fcn1' */
  real_T Integrator_CSTATE;            /* '<S37>/Integrator' */
  real_T Integrator_CSTATE_e;          /* '<S1>/Integrator' */
  real_T Filter_CSTATE;                /* '<S32>/Filter' */
  real_T TransferFcn_CSTATE;           /* '<S1>/Transfer Fcn' */
} X_RW1SteeringAngle;

/* State derivatives for system '<Root>/RW1 Steering Angle' */
typedef struct {
  real_T TransferFcn1_CSTATE;          /* '<S1>/Transfer Fcn1' */
  real_T Integrator_CSTATE;            /* '<S37>/Integrator' */
  real_T Integrator_CSTATE_e;          /* '<S1>/Integrator' */
  real_T Filter_CSTATE;                /* '<S32>/Filter' */
  real_T TransferFcn_CSTATE;           /* '<S1>/Transfer Fcn' */
} XDot_RW1SteeringAngle;

/* State Disabled for system '<Root>/RW1 Steering Angle' */
typedef struct {
  boolean_T TransferFcn1_CSTATE;       /* '<S1>/Transfer Fcn1' */
  boolean_T Integrator_CSTATE;         /* '<S37>/Integrator' */
  boolean_T Integrator_CSTATE_e;       /* '<S1>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S32>/Filter' */
  boolean_T TransferFcn_CSTATE;        /* '<S1>/Transfer Fcn' */
} XDis_RW1SteeringAngle;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_RW1SteeringAngle RW1SteeringAngle_m;/* '<Root>/RW1 Steering Angle' */
  real_T y;                            /* '<S4>/Ratchet' */
} DW;

/* Continuous states (default storage) */
typedef struct {
  X_RW1SteeringAngle RW1SteeringAngle_m;/* '<Root>/RW1 Steering Angle' */
} X;

/* State derivatives (default storage) */
typedef struct {
  XDot_RW1SteeringAngle RW1SteeringAngle_m;/* '<Root>/RW1 Steering Angle' */
} XDot;

/* State disabled  */
typedef struct {
  XDis_RW1SteeringAngle RW1SteeringAngle_m;/* '<Root>/RW1 Steering Angle' */
} XDis;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T desiredrw1;                   /* '<Root>/desired rw1' */
  real_T Fx;                           /* '<Root>/Fx' */
  real_T Fy;                           /* '<Root>/Fy' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Actualrw1;                    /* '<Root>/Actual rw1' */
} ExtY;

/* Parameters for system: '<Root>/RW1 Steering Angle' */
struct P_RW1SteeringAngle_ {
  real_T PIDController_D;              /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S31>/Derivative Gain'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S34>/Integral Gain'
                                        */
  real_T PIDController_InitialConditionForFilter;
                      /* Mask Parameter: PIDController_InitialConditionForFilter
                       * Referenced by: '<S32>/Filter'
                       */
  real_T PIDController_InitialConditionForIntegrator;
                  /* Mask Parameter: PIDController_InitialConditionForIntegrator
                   * Referenced by: '<S37>/Integrator'
                   */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S40>/Filter Coefficient'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S42>/Proportional Gain'
                                        */
  real_T PowerAmplifier_Gain;          /* Expression: 1
                                        * Referenced by: '<S1>/Power Amplifier'
                                        */
  real_T TransferFcn1_A;               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<S1>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C;               /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<S1>/Transfer Fcn1'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S1>/Integrator'
                                        */
  real_T Memory4_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S4>/Memory4'
                                        */
  real_T Memory3_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S4>/Memory3'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S1>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S1>/Transfer Fcn'
                                        */
};

/* Parameters for system: '<Root>/RW1 Steering Angle' */
typedef struct P_RW1SteeringAngle_ P_RW1SteeringAngle;

/* Parameters (default storage) */
struct P_ {
  real_T Ka;                           /* Variable: Ka
                                        * Referenced by: '<S1>/Torque Constant'
                                        */
  real_T Ke;                           /* Variable: Ke
                                        * Referenced by: '<S1>/Back EMF Constant'
                                        */
  real_T Ws1;                          /* Variable: Ws1
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T cs1;                          /* Variable: cs1
                                        * Referenced by:
                                        *   '<S1>/Constant2'
                                        *   '<S1>/Gain2'
                                        */
  real_T mu;                           /* Variable: mu
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T tpo;                          /* Variable: tpo
                                        * Referenced by: '<S1>/Constant1'
                                        */
  P_RW1SteeringAngle RW1SteeringAngle_m;/* '<Root>/RW1 Steering Angle' */
};

/* Parameters (default storage) */
typedef struct P_ P;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[5];
  real_T odeF[4][5];
  ODE4_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P rtP;

/* Continuous states (default storage) */
extern X rtX;

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void RW1_initialize(void);
extern void RW1_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Scope1' : Unused code path elimination
 * Block '<S1>/Scope2' : Unused code path elimination
 * Block '<S1>/Scope4' : Unused code path elimination
 * Block '<S1>/Scope5' : Unused code path elimination
 * Block '<S1>/Scope6' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('MalaksModelSub/RW1 Steering Angle')    - opens subsystem MalaksModelSub/RW1 Steering Angle
 * hilite_system('MalaksModelSub/RW1 Steering Angle/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'MalaksModelSub'
 * '<S1>'   : 'MalaksModelSub/RW1 Steering Angle'
 * '<S2>'   : 'MalaksModelSub/RW1 Steering Angle/MATLAB Function'
 * '<S3>'   : 'MalaksModelSub/RW1 Steering Angle/PID Controller'
 * '<S4>'   : 'MalaksModelSub/RW1 Steering Angle/Ratchet'
 * '<S5>'   : 'MalaksModelSub/RW1 Steering Angle/pneumatic trail '
 * '<S6>'   : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Anti-windup'
 * '<S7>'   : 'MalaksModelSub/RW1 Steering Angle/PID Controller/D Gain'
 * '<S8>'   : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Filter'
 * '<S9>'   : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Filter ICs'
 * '<S10>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/I Gain'
 * '<S11>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Ideal P Gain'
 * '<S12>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Ideal P Gain Fdbk'
 * '<S13>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Integrator'
 * '<S14>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Integrator ICs'
 * '<S15>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/N Copy'
 * '<S16>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/N Gain'
 * '<S17>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/P Copy'
 * '<S18>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Parallel P Gain'
 * '<S19>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Reset Signal'
 * '<S20>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Saturation'
 * '<S21>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Saturation Fdbk'
 * '<S22>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Sum'
 * '<S23>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Sum Fdbk'
 * '<S24>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Tracking Mode'
 * '<S25>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Tracking Mode Sum'
 * '<S26>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Tsamp - Integral'
 * '<S27>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Tsamp - Ngain'
 * '<S28>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/postSat Signal'
 * '<S29>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/preSat Signal'
 * '<S30>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Anti-windup/Passthrough'
 * '<S31>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/D Gain/Internal Parameters'
 * '<S32>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Filter/Cont. Filter'
 * '<S33>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S34>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/I Gain/Internal Parameters'
 * '<S35>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Ideal P Gain/Passthrough'
 * '<S36>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S37>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Integrator/Continuous'
 * '<S38>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Integrator ICs/Internal IC'
 * '<S39>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/N Copy/Disabled'
 * '<S40>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/N Gain/Internal Parameters'
 * '<S41>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/P Copy/Disabled'
 * '<S42>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S43>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Reset Signal/Disabled'
 * '<S44>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Saturation/Passthrough'
 * '<S45>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Saturation Fdbk/Disabled'
 * '<S46>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Sum/Sum_PID'
 * '<S47>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Sum Fdbk/Disabled'
 * '<S48>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Tracking Mode/Disabled'
 * '<S49>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S50>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Tsamp - Integral/Passthrough'
 * '<S51>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S52>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/postSat Signal/Forward_Path'
 * '<S53>'  : 'MalaksModelSub/RW1 Steering Angle/PID Controller/preSat Signal/Forward_Path'
 * '<S54>'  : 'MalaksModelSub/RW1 Steering Angle/Ratchet/Ratchet'
 * '<S55>'  : 'MalaksModelSub/RW1 Steering Angle/Ratchet/Switch'
 */
#endif                                 /* RTW_HEADER_RW1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
