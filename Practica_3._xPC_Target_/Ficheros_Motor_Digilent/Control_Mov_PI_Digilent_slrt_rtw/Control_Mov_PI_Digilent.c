/*
 * Control_Mov_PI_Digilent.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Control_Mov_PI_Digilent".
 *
 * Model version              : 1.181
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Thu Mar 21 18:20:16 2024
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rt_logging_mmi.h"
#include "Control_Mov_PI_Digilent_capi.h"
#include "Control_Mov_PI_Digilent.h"
#include "Control_Mov_PI_Digilent_private.h"

/* Block signals (auto storage) */
B_Control_Mov_PI_Digilent_T Control_Mov_PI_Digilent_B;

/* Continuous states */
X_Control_Mov_PI_Digilent_T Control_Mov_PI_Digilent_X;

/* Block states (auto storage) */
DW_Control_Mov_PI_Digilent_T Control_Mov_PI_Digilent_DW;

/* Real-time model */
RT_MODEL_Control_Mov_PI_Digilent_T Control_Mov_PI_Digilent_M_;
RT_MODEL_Control_Mov_PI_Digilent_T *const Control_Mov_PI_Digilent_M =
  &Control_Mov_PI_Digilent_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Control_Mov_PI_Digilent_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Control_Mov_PI_Digilent_output();
  Control_Mov_PI_Digilent_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Control_Mov_PI_Digilent_output();
  Control_Mov_PI_Digilent_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void Control_Mov_PI_Digilent_output(void)
{
  real_T *lastU;
  real_T lastTime;
  if (rtmIsMajorTimeStep(Control_Mov_PI_Digilent_M)) {
    /* set solver stop time */
    if (!(Control_Mov_PI_Digilent_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Control_Mov_PI_Digilent_M->solverInfo,
                            ((Control_Mov_PI_Digilent_M->Timing.clockTickH0 + 1)
        * Control_Mov_PI_Digilent_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Control_Mov_PI_Digilent_M->solverInfo,
                            ((Control_Mov_PI_Digilent_M->Timing.clockTick0 + 1) *
        Control_Mov_PI_Digilent_M->Timing.stepSize0 +
        Control_Mov_PI_Digilent_M->Timing.clockTickH0 *
        Control_Mov_PI_Digilent_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Control_Mov_PI_Digilent_M)) {
    Control_Mov_PI_Digilent_M->Timing.t[0] = rtsiGetT
      (&Control_Mov_PI_Digilent_M->solverInfo);
  }

  /* S-Function (scblock): '<S1>/S-Function' */
  /* ok to acquire for <S1>/S-Function */
  Control_Mov_PI_Digilent_DW.SFunction_IWORK.AcquireOK = 1;

  /* S-Function (scblock): '<S2>/S-Function' */
  /* ok to acquire for <S2>/S-Function */
  Control_Mov_PI_Digilent_DW.SFunction_IWORK_b.AcquireOK = 1;

  /* S-Function (scblock): '<S3>/S-Function' */
  /* ok to acquire for <S3>/S-Function */
  Control_Mov_PI_Digilent_DW.SFunction_IWORK_c.AcquireOK = 1;

  /* FromWorkspace: '<S8>/FromWs' */
  {
    real_T *pDataValues = (real_T *)
      Control_Mov_PI_Digilent_DW.FromWs_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      Control_Mov_PI_Digilent_DW.FromWs_PWORK.TimePtr;
    int_T currTimeIndex = Control_Mov_PI_Digilent_DW.FromWs_IWORK.PrevIndex;
    real_T t = Control_Mov_PI_Digilent_M->Timing.t[0];
    if (t >= pTimeValues[21]) {
      Control_Mov_PI_Digilent_B.FromWs = pDataValues[21];
    } else {
      /* Get index */
      if (t <= pTimeValues[0]) {
        currTimeIndex = 0;
      } else if (t >= pTimeValues[21]) {
        currTimeIndex = 20;
      } else {
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }
      }

      Control_Mov_PI_Digilent_DW.FromWs_IWORK.PrevIndex = currTimeIndex;

      /* Post output */
      {
        real_T t1 = pTimeValues[currTimeIndex];
        real_T t2 = pTimeValues[currTimeIndex + 1];
        if (t1 == t2) {
          if (t < t1) {
            Control_Mov_PI_Digilent_B.FromWs = pDataValues[currTimeIndex];
          } else {
            Control_Mov_PI_Digilent_B.FromWs = pDataValues[currTimeIndex + 1];
          }
        } else {
          real_T f1 = (t2 - t) / (t2 - t1);
          real_T f2 = 1.0 - f1;
          real_T d1;
          real_T d2;
          int_T TimeIndex= currTimeIndex;
          d1 = pDataValues[TimeIndex];
          d2 = pDataValues[TimeIndex + 1];
          Control_Mov_PI_Digilent_B.FromWs = (real_T) rtInterpolate(d1, d2, f1,
            f2);
          pDataValues += 22;
        }
      }
    }
  }

  if (rtmIsMajorTimeStep(Control_Mov_PI_Digilent_M)) {
    /* S-Function (encnipcim): '<Root>/PCI 6221 ENC ' */

    /* Level2 S-Function Block: '<Root>/PCI 6221 ENC ' (encnipcim) */
    {
      SimStruct *rts = Control_Mov_PI_Digilent_M->childSfunctions[0];
      sfcnOutputs(rts,1);
    }

    /* Fcn: '<Root>/Encoder-Grados Reductora 1:53' */
    Control_Mov_PI_Digilent_B.EncoderGradosReductora153 = 360.0 *
      Control_Mov_PI_Digilent_B.PCI6221ENC / 635.0;
  }

  /* Sum: '<Root>/Sum' */
  Control_Mov_PI_Digilent_B.Sum = Control_Mov_PI_Digilent_B.FromWs -
    Control_Mov_PI_Digilent_B.EncoderGradosReductora153;

  /* Gain: '<S4>/Proportional Gain' */
  Control_Mov_PI_Digilent_B.ProportionalGain =
    Control_Mov_PI_Digilent_P.PIController_P * Control_Mov_PI_Digilent_B.Sum;

  /* Integrator: '<S4>/Integrator' */
  Control_Mov_PI_Digilent_B.Integrator =
    Control_Mov_PI_Digilent_X.Integrator_CSTATE;

  /* Gain: '<S4>/Derivative Gain' */
  Control_Mov_PI_Digilent_B.DerivativeGain =
    Control_Mov_PI_Digilent_P.PIController_D * Control_Mov_PI_Digilent_B.Sum;

  /* Derivative: '<S4>/Ideal Derivative' */
  if ((Control_Mov_PI_Digilent_DW.TimeStampA >=
       Control_Mov_PI_Digilent_M->Timing.t[0]) &&
      (Control_Mov_PI_Digilent_DW.TimeStampB >=
       Control_Mov_PI_Digilent_M->Timing.t[0])) {
    Control_Mov_PI_Digilent_B.IdealDerivative = 0.0;
  } else {
    lastTime = Control_Mov_PI_Digilent_DW.TimeStampA;
    lastU = &Control_Mov_PI_Digilent_DW.LastUAtTimeA;
    if (Control_Mov_PI_Digilent_DW.TimeStampA <
        Control_Mov_PI_Digilent_DW.TimeStampB) {
      if (Control_Mov_PI_Digilent_DW.TimeStampB <
          Control_Mov_PI_Digilent_M->Timing.t[0]) {
        lastTime = Control_Mov_PI_Digilent_DW.TimeStampB;
        lastU = &Control_Mov_PI_Digilent_DW.LastUAtTimeB;
      }
    } else {
      if (Control_Mov_PI_Digilent_DW.TimeStampA >=
          Control_Mov_PI_Digilent_M->Timing.t[0]) {
        lastTime = Control_Mov_PI_Digilent_DW.TimeStampB;
        lastU = &Control_Mov_PI_Digilent_DW.LastUAtTimeB;
      }
    }

    lastTime = Control_Mov_PI_Digilent_M->Timing.t[0] - lastTime;
    Control_Mov_PI_Digilent_B.IdealDerivative =
      (Control_Mov_PI_Digilent_B.DerivativeGain - *lastU) / lastTime;
  }

  /* End of Derivative: '<S4>/Ideal Derivative' */

  /* Sum: '<S4>/Sum' */
  Control_Mov_PI_Digilent_B.Sum_i = (Control_Mov_PI_Digilent_B.ProportionalGain
    + Control_Mov_PI_Digilent_B.Integrator) +
    Control_Mov_PI_Digilent_B.IdealDerivative;
  if (rtmIsMajorTimeStep(Control_Mov_PI_Digilent_M)) {
    /* Constant: '<Root>/Constant1' */
    Control_Mov_PI_Digilent_B.Constant1 =
      Control_Mov_PI_Digilent_P.Constant1_Value;

    /* S-Function (danipcim): '<Root>/PCI-6221 DA' */

    /* Level2 S-Function Block: '<Root>/PCI-6221 DA' (danipcim) */
    {
      SimStruct *rts = Control_Mov_PI_Digilent_M->childSfunctions[1];
      sfcnOutputs(rts,1);
    }
  }

  /* S-Function (scblock): '<S5>/S-Function' */
  /* ok to acquire for <S5>/S-Function */
  Control_Mov_PI_Digilent_DW.SFunction_IWORK_k.AcquireOK = 1;

  /* S-Function (scblock): '<S6>/S-Function' */
  /* ok to acquire for <S6>/S-Function */
  Control_Mov_PI_Digilent_DW.SFunction_IWORK_o.AcquireOK = 1;

  /* S-Function (scblock): '<S7>/S-Function' */
  /* ok to acquire for <S7>/S-Function */
  Control_Mov_PI_Digilent_DW.SFunction_IWORK_e.AcquireOK = 1;

  /* Gain: '<S4>/Integral Gain' */
  Control_Mov_PI_Digilent_B.IntegralGain =
    Control_Mov_PI_Digilent_P.PIController_I * Control_Mov_PI_Digilent_B.Sum;
}

/* Model update function */
void Control_Mov_PI_Digilent_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<S4>/Ideal Derivative' */
  if (Control_Mov_PI_Digilent_DW.TimeStampA == (rtInf)) {
    Control_Mov_PI_Digilent_DW.TimeStampA = Control_Mov_PI_Digilent_M->Timing.t
      [0];
    lastU = &Control_Mov_PI_Digilent_DW.LastUAtTimeA;
  } else if (Control_Mov_PI_Digilent_DW.TimeStampB == (rtInf)) {
    Control_Mov_PI_Digilent_DW.TimeStampB = Control_Mov_PI_Digilent_M->Timing.t
      [0];
    lastU = &Control_Mov_PI_Digilent_DW.LastUAtTimeB;
  } else if (Control_Mov_PI_Digilent_DW.TimeStampA <
             Control_Mov_PI_Digilent_DW.TimeStampB) {
    Control_Mov_PI_Digilent_DW.TimeStampA = Control_Mov_PI_Digilent_M->Timing.t
      [0];
    lastU = &Control_Mov_PI_Digilent_DW.LastUAtTimeA;
  } else {
    Control_Mov_PI_Digilent_DW.TimeStampB = Control_Mov_PI_Digilent_M->Timing.t
      [0];
    lastU = &Control_Mov_PI_Digilent_DW.LastUAtTimeB;
  }

  *lastU = Control_Mov_PI_Digilent_B.DerivativeGain;

  /* End of Update for Derivative: '<S4>/Ideal Derivative' */
  if (rtmIsMajorTimeStep(Control_Mov_PI_Digilent_M)) {
    rt_ertODEUpdateContinuousStates(&Control_Mov_PI_Digilent_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Control_Mov_PI_Digilent_M->Timing.clockTick0)) {
    ++Control_Mov_PI_Digilent_M->Timing.clockTickH0;
  }

  Control_Mov_PI_Digilent_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Control_Mov_PI_Digilent_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Control_Mov_PI_Digilent_M->Timing.clockTick1)) {
      ++Control_Mov_PI_Digilent_M->Timing.clockTickH1;
    }

    Control_Mov_PI_Digilent_M->Timing.t[1] =
      Control_Mov_PI_Digilent_M->Timing.clockTick1 *
      Control_Mov_PI_Digilent_M->Timing.stepSize1 +
      Control_Mov_PI_Digilent_M->Timing.clockTickH1 *
      Control_Mov_PI_Digilent_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void Control_Mov_PI_Digilent_derivatives(void)
{
  XDot_Control_Mov_PI_Digilent_T *_rtXdot;
  _rtXdot = ((XDot_Control_Mov_PI_Digilent_T *)
             Control_Mov_PI_Digilent_M->derivs);

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE = Control_Mov_PI_Digilent_B.IntegralGain;
}

/* Model initialize function */
void Control_Mov_PI_Digilent_initialize(void)
{
  /* Start for S-Function (scblock): '<S1>/S-Function' */

  /* S-Function Block: <S1>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(4)) == 0) {
      if ((i = rl32eDefScope(4,1)) != 0) {
        printf("Error creating scope 4\n");
      } else {
        rl32eAddSignal(4, rl32eGetSignalNo("PI Controller/Sum"));
        rl32eSetScope(4, 4, 4950);
        rl32eSetScope(4, 5, 0);
        rl32eSetScope(4, 6, 1);
        rl32eSetScope(4, 0, 0);
        rl32eSetScope(4, 3, rl32eGetSignalNo("PI Controller/Sum"));
        rl32eSetScope(4, 1, 0.0);
        rl32eSetScope(4, 2, 0);
        rl32eSetScope(4, 9, 0);
        xpceScopeAcqOK(4, &Control_Mov_PI_Digilent_DW.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(4);
    }
  }

  /* Start for S-Function (scblock): '<S2>/S-Function' */

  /* S-Function Block: <S2>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(1)) == 0) {
      if ((i = rl32eDefScope(1,3)) != 0) {
        printf("Error creating scope 1\n");
      } else {
        rl32eAddSignal(1, rl32eGetSignalNo("Sum"));
        rl32eSetScope(1, 4, 4950);
        rl32eSetScope(1, 5, 0);
        rl32eSetScope(1, 6, 1);
        rl32eSetScope(1, 0, 0);
        xpceFSScopeSet(1, "C:\\Rafa\\Error_1.dat", 0, 512, 0, 536870912);
        rl32eSetScope (1, 10, 0);
        rl32eSetScope(1, 3, rl32eGetSignalNo("Sum"));
        rl32eSetScope(1, 1, 0.0);
        rl32eSetScope(1, 2, 0);
        rl32eSetScope(1, 9, 0);
        xpceScopeAcqOK(1,
                       &Control_Mov_PI_Digilent_DW.SFunction_IWORK_b.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* Start for S-Function (scblock): '<S3>/S-Function' */

  /* S-Function Block: <S3>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(6)) == 0) {
      if ((i = rl32eDefScope(6,1)) != 0) {
        printf("Error creating scope 6\n");
      } else {
        rl32eAddSignal(6, rl32eGetSignalNo("Sum"));
        rl32eSetScope(6, 4, 4950);
        rl32eSetScope(6, 5, 0);
        rl32eSetScope(6, 6, 1);
        rl32eSetScope(6, 0, 0);
        rl32eSetScope(6, 3, rl32eGetSignalNo("Sum"));
        rl32eSetScope(6, 1, 0.0);
        rl32eSetScope(6, 2, 0);
        rl32eSetScope(6, 9, 0);
        xpceScopeAcqOK(6,
                       &Control_Mov_PI_Digilent_DW.SFunction_IWORK_c.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(6);
    }
  }

  /* Start for FromWorkspace: '<S8>/FromWs' */
  {
    static real_T pTimeValues0[] = { 0.0, 5.0, 5.0, 10.0, 10.0, 15.0, 15.0, 20.0,
      20.0, 25.0, 25.0, 30.0, 30.0, 35.0, 35.0, 37.300000000000004,
      37.300000000000004, 42.1, 42.1, 45.1, 45.1, 50.0 } ;

    static real_T pDataValues0[] = { 350.0, 350.0, 0.0, 0.0, 250.0, 250.0, 100.0,
      100.0, 360.0, 360.0, -1.0, -1.0, 49.0, 49.0, 35.0, 35.0, 150.0, 150.0,
      90.0, 90.0, -1.0, -1.0 } ;

    Control_Mov_PI_Digilent_DW.FromWs_PWORK.TimePtr = (void *) pTimeValues0;
    Control_Mov_PI_Digilent_DW.FromWs_PWORK.DataPtr = (void *) pDataValues0;
    Control_Mov_PI_Digilent_DW.FromWs_IWORK.PrevIndex = 0;
  }

  /* Start for S-Function (encnipcim): '<Root>/PCI 6221 ENC ' */
  /* Level2 S-Function Block: '<Root>/PCI 6221 ENC ' (encnipcim) */
  {
    SimStruct *rts = Control_Mov_PI_Digilent_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<Root>/Constant1' */
  Control_Mov_PI_Digilent_B.Constant1 =
    Control_Mov_PI_Digilent_P.Constant1_Value;

  /* Start for S-Function (danipcim): '<Root>/PCI-6221 DA' */
  /* Level2 S-Function Block: '<Root>/PCI-6221 DA' (danipcim) */
  {
    SimStruct *rts = Control_Mov_PI_Digilent_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (scblock): '<S5>/S-Function' */

  /* S-Function Block: <S5>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(5)) == 0) {
      if ((i = rl32eDefScope(5,3)) != 0) {
        printf("Error creating scope 5\n");
      } else {
        rl32eAddSignal(5, rl32eGetSignalNo("Trayectoria Posicion/FromWs"));
        rl32eAddSignal(5, rl32eGetSignalNo("Encoder-Grados Reductora 1:53"));
        rl32eSetScope(5, 4, 4950);
        rl32eSetScope(5, 5, 0);
        rl32eSetScope(5, 6, 1);
        rl32eSetScope(5, 0, 0);
        xpceFSScopeSet(5, "C:\\out_bad.dat", 0, 512, 0, 536870912);
        rl32eSetScope (5, 10, 0);
        rl32eSetScope(5, 3, rl32eGetSignalNo("Trayectoria Posicion/FromWs"));
        rl32eSetScope(5, 1, 0.0);
        rl32eSetScope(5, 2, 0);
        rl32eSetScope(5, 9, 0);
        xpceScopeAcqOK(5,
                       &Control_Mov_PI_Digilent_DW.SFunction_IWORK_k.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(5);
    }
  }

  /* Start for S-Function (scblock): '<S6>/S-Function' */

  /* S-Function Block: <S6>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(3)) == 0) {
      if ((i = rl32eDefScope(3,1)) != 0) {
        printf("Error creating scope 3\n");
      } else {
        rl32eAddSignal(3, rl32eGetSignalNo("Trayectoria Posicion/FromWs"));
        rl32eAddSignal(3, rl32eGetSignalNo("Encoder-Grados Reductora 1:53"));
        rl32eSetScope(3, 4, 4950);
        rl32eSetScope(3, 5, 0);
        rl32eSetScope(3, 6, 1);
        rl32eSetScope(3, 0, 0);
        rl32eSetScope(3, 3, rl32eGetSignalNo("Trayectoria Posicion/FromWs"));
        rl32eSetScope(3, 1, 0.0);
        rl32eSetScope(3, 2, 0);
        rl32eSetScope(3, 9, 0);
        xpceScopeAcqOK(3,
                       &Control_Mov_PI_Digilent_DW.SFunction_IWORK_o.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(3);
    }
  }

  /* Start for S-Function (scblock): '<S7>/S-Function' */

  /* S-Function Block: <S7>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(2)) == 0) {
      if ((i = rl32eDefScope(2,2)) != 0) {
        printf("Error creating scope 2\n");
      } else {
        rl32eAddSignal(2, rl32eGetSignalNo("Trayectoria Posicion/FromWs"));
        rl32eAddSignal(2, rl32eGetSignalNo("Encoder-Grados Reductora 1:53"));
        rl32eSetScope(2, 4, 1000);
        rl32eSetScope(2, 5, 0);
        rl32eSetScope(2, 6, 1);
        rl32eSetScope(2, 0, 0);
        rl32eSetScope(2, 3, rl32eGetSignalNo("Trayectoria Posicion/FromWs"));
        rl32eSetScope(2, 1, 0.0);
        rl32eSetScope(2, 2, 0);
        rl32eSetScope(2, 9, 0);
        rl32eSetTargetScope(2, 11, 0.0);
        rl32eSetTargetScope(2, 10, 50.0);
        xpceScopeAcqOK(2,
                       &Control_Mov_PI_Digilent_DW.SFunction_IWORK_e.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  Control_Mov_PI_Digilent_X.Integrator_CSTATE =
    Control_Mov_PI_Digilent_P.Integrator_IC;

  /* InitializeConditions for Derivative: '<S4>/Ideal Derivative' */
  Control_Mov_PI_Digilent_DW.TimeStampA = (rtInf);
  Control_Mov_PI_Digilent_DW.TimeStampB = (rtInf);
}

/* Model terminate function */
void Control_Mov_PI_Digilent_terminate(void)
{
  /* Terminate for S-Function (encnipcim): '<Root>/PCI 6221 ENC ' */
  /* Level2 S-Function Block: '<Root>/PCI 6221 ENC ' (encnipcim) */
  {
    SimStruct *rts = Control_Mov_PI_Digilent_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (danipcim): '<Root>/PCI-6221 DA' */
  /* Level2 S-Function Block: '<Root>/PCI-6221 DA' (danipcim) */
  {
    SimStruct *rts = Control_Mov_PI_Digilent_M->childSfunctions[1];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  Control_Mov_PI_Digilent_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Control_Mov_PI_Digilent_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Control_Mov_PI_Digilent_initialize();
}

void MdlTerminate(void)
{
  Control_Mov_PI_Digilent_terminate();
}

/* Registration function */
RT_MODEL_Control_Mov_PI_Digilent_T *Control_Mov_PI_Digilent(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Control_Mov_PI_Digilent_M, 0,
                sizeof(RT_MODEL_Control_Mov_PI_Digilent_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Control_Mov_PI_Digilent_M->solverInfo,
                          &Control_Mov_PI_Digilent_M->Timing.simTimeStep);
    rtsiSetTPtr(&Control_Mov_PI_Digilent_M->solverInfo, &rtmGetTPtr
                (Control_Mov_PI_Digilent_M));
    rtsiSetStepSizePtr(&Control_Mov_PI_Digilent_M->solverInfo,
                       &Control_Mov_PI_Digilent_M->Timing.stepSize0);
    rtsiSetdXPtr(&Control_Mov_PI_Digilent_M->solverInfo,
                 &Control_Mov_PI_Digilent_M->derivs);
    rtsiSetContStatesPtr(&Control_Mov_PI_Digilent_M->solverInfo, (real_T **)
                         &Control_Mov_PI_Digilent_M->contStates);
    rtsiSetNumContStatesPtr(&Control_Mov_PI_Digilent_M->solverInfo,
      &Control_Mov_PI_Digilent_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Control_Mov_PI_Digilent_M->solverInfo,
      &Control_Mov_PI_Digilent_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Control_Mov_PI_Digilent_M->solverInfo,
      &Control_Mov_PI_Digilent_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Control_Mov_PI_Digilent_M->solverInfo,
      &Control_Mov_PI_Digilent_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Control_Mov_PI_Digilent_M->solverInfo,
                          (&rtmGetErrorStatus(Control_Mov_PI_Digilent_M)));
    rtsiSetRTModelPtr(&Control_Mov_PI_Digilent_M->solverInfo,
                      Control_Mov_PI_Digilent_M);
  }

  rtsiSetSimTimeStep(&Control_Mov_PI_Digilent_M->solverInfo, MAJOR_TIME_STEP);
  Control_Mov_PI_Digilent_M->intgData.y = Control_Mov_PI_Digilent_M->odeY;
  Control_Mov_PI_Digilent_M->intgData.f[0] = Control_Mov_PI_Digilent_M->odeF[0];
  Control_Mov_PI_Digilent_M->intgData.f[1] = Control_Mov_PI_Digilent_M->odeF[1];
  Control_Mov_PI_Digilent_M->intgData.f[2] = Control_Mov_PI_Digilent_M->odeF[2];
  Control_Mov_PI_Digilent_M->contStates = ((real_T *) &Control_Mov_PI_Digilent_X);
  rtsiSetSolverData(&Control_Mov_PI_Digilent_M->solverInfo, (void *)
                    &Control_Mov_PI_Digilent_M->intgData);
  rtsiSetSolverName(&Control_Mov_PI_Digilent_M->solverInfo,"ode3");
  Control_Mov_PI_Digilent_M->solverInfoPtr =
    (&Control_Mov_PI_Digilent_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Control_Mov_PI_Digilent_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Control_Mov_PI_Digilent_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Control_Mov_PI_Digilent_M->Timing.sampleTimes =
      (&Control_Mov_PI_Digilent_M->Timing.sampleTimesArray[0]);
    Control_Mov_PI_Digilent_M->Timing.offsetTimes =
      (&Control_Mov_PI_Digilent_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Control_Mov_PI_Digilent_M->Timing.sampleTimes[0] = (0.0);
    Control_Mov_PI_Digilent_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    Control_Mov_PI_Digilent_M->Timing.offsetTimes[0] = (0.0);
    Control_Mov_PI_Digilent_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Control_Mov_PI_Digilent_M,
             &Control_Mov_PI_Digilent_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Control_Mov_PI_Digilent_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Control_Mov_PI_Digilent_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Control_Mov_PI_Digilent_M, 50.0);
  Control_Mov_PI_Digilent_M->Timing.stepSize0 = 0.01;
  Control_Mov_PI_Digilent_M->Timing.stepSize1 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    Control_Mov_PI_Digilent_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    /*
     * Set pointers to the data and signal info each state
     */
    {
      static int_T rt_LoggedStateWidths[] = {
        1
      };

      static int_T rt_LoggedStateNumDimensions[] = {
        1
      };

      static int_T rt_LoggedStateDimensions[] = {
        1
      };

      static boolean_T rt_LoggedStateIsVarDims[] = {
        0
      };

      static BuiltInDTypeId rt_LoggedStateDataTypeIds[] = {
        SS_DOUBLE
      };

      static int_T rt_LoggedStateComplexSignals[] = {
        0
      };

      static const char_T *rt_LoggedStateLabels[] = {
        "CSTATE"
      };

      static const char_T *rt_LoggedStateBlockNames[] = {
        "Control_Mov_PI_Digilent/PI Controller/Integrator"
      };

      static const char_T *rt_LoggedStateNames[] = {
        ""
      };

      static boolean_T rt_LoggedStateCrossMdlRef[] = {
        0
      };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedStateSignalInfo = {
        1,
        rt_LoggedStateWidths,
        rt_LoggedStateNumDimensions,
        rt_LoggedStateDimensions,
        rt_LoggedStateIsVarDims,
        (NULL),
        (NULL),
        rt_LoggedStateDataTypeIds,
        rt_LoggedStateComplexSignals,
        (NULL),
        (NULL),

        { rt_LoggedStateLabels },
        (NULL),
        (NULL),
        (NULL),

        { rt_LoggedStateBlockNames },

        { rt_LoggedStateNames },
        rt_LoggedStateCrossMdlRef,
        rt_RTWLogDataTypeConvert
      };

      static void * rt_LoggedStateSignalPtrs[1];
      rtliSetLogXSignalPtrs(Control_Mov_PI_Digilent_M->rtwLogInfo,
                            (LogSignalPtrsType) rt_LoggedStateSignalPtrs);
      rtliSetLogXSignalInfo(Control_Mov_PI_Digilent_M->rtwLogInfo,
                            &rt_LoggedStateSignalInfo);
      rt_LoggedStateSignalPtrs[0] = (void*)
        &Control_Mov_PI_Digilent_X.Integrator_CSTATE;
    }

    rtliSetLogT(Control_Mov_PI_Digilent_M->rtwLogInfo, "tout");
    rtliSetLogX(Control_Mov_PI_Digilent_M->rtwLogInfo, "xout");
    rtliSetLogXFinal(Control_Mov_PI_Digilent_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Control_Mov_PI_Digilent_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Control_Mov_PI_Digilent_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(Control_Mov_PI_Digilent_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Control_Mov_PI_Digilent_M->rtwLogInfo, 1);
    rtliSetLogY(Control_Mov_PI_Digilent_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Control_Mov_PI_Digilent_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Control_Mov_PI_Digilent_M->rtwLogInfo, (NULL));
  }

  Control_Mov_PI_Digilent_M->solverInfoPtr =
    (&Control_Mov_PI_Digilent_M->solverInfo);
  Control_Mov_PI_Digilent_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&Control_Mov_PI_Digilent_M->solverInfo, 0.01);
  rtsiSetSolverMode(&Control_Mov_PI_Digilent_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Control_Mov_PI_Digilent_M->blockIO = ((void *) &Control_Mov_PI_Digilent_B);

  {
    Control_Mov_PI_Digilent_B.FromWs = 0.0;
    Control_Mov_PI_Digilent_B.PCI6221ENC = 0.0;
    Control_Mov_PI_Digilent_B.EncoderGradosReductora153 = 0.0;
    Control_Mov_PI_Digilent_B.Sum = 0.0;
    Control_Mov_PI_Digilent_B.ProportionalGain = 0.0;
    Control_Mov_PI_Digilent_B.Integrator = 0.0;
    Control_Mov_PI_Digilent_B.DerivativeGain = 0.0;
    Control_Mov_PI_Digilent_B.IdealDerivative = 0.0;
    Control_Mov_PI_Digilent_B.Sum_i = 0.0;
    Control_Mov_PI_Digilent_B.Constant1 = 0.0;
    Control_Mov_PI_Digilent_B.IntegralGain = 0.0;
  }

  /* parameters */
  Control_Mov_PI_Digilent_M->defaultParam = ((real_T *)
    &Control_Mov_PI_Digilent_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Control_Mov_PI_Digilent_X;
    Control_Mov_PI_Digilent_M->contStates = (x);
    (void) memset((void *)&Control_Mov_PI_Digilent_X, 0,
                  sizeof(X_Control_Mov_PI_Digilent_T));
  }

  /* states (dwork) */
  Control_Mov_PI_Digilent_M->dwork = ((void *) &Control_Mov_PI_Digilent_DW);
  (void) memset((void *)&Control_Mov_PI_Digilent_DW, 0,
                sizeof(DW_Control_Mov_PI_Digilent_T));
  Control_Mov_PI_Digilent_DW.TimeStampA = 0.0;
  Control_Mov_PI_Digilent_DW.LastUAtTimeA = 0.0;
  Control_Mov_PI_Digilent_DW.TimeStampB = 0.0;
  Control_Mov_PI_Digilent_DW.LastUAtTimeB = 0.0;

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      Control_Mov_PI_Digilent_DW.PCI6221DA_RWORK[i] = 0.0;
    }
  }

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  Control_Mov_PI_Digilent_InitializeDataMapInfo();

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &Control_Mov_PI_Digilent_M->NonInlinedSFcns.sfcnInfo;
    Control_Mov_PI_Digilent_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus
      (Control_Mov_PI_Digilent_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &Control_Mov_PI_Digilent_M->Sizes.numSampTimes);
    Control_Mov_PI_Digilent_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (Control_Mov_PI_Digilent_M)[0]);
    Control_Mov_PI_Digilent_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (Control_Mov_PI_Digilent_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,
                   Control_Mov_PI_Digilent_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(Control_Mov_PI_Digilent_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(Control_Mov_PI_Digilent_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (Control_Mov_PI_Digilent_M));
    rtssSetStepSizePtr(sfcnInfo, &Control_Mov_PI_Digilent_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (Control_Mov_PI_Digilent_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &Control_Mov_PI_Digilent_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &Control_Mov_PI_Digilent_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &Control_Mov_PI_Digilent_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &Control_Mov_PI_Digilent_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &Control_Mov_PI_Digilent_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &Control_Mov_PI_Digilent_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &Control_Mov_PI_Digilent_M->solverInfoPtr);
  }

  Control_Mov_PI_Digilent_M->Sizes.numSFcns = (2);

  /* register each child */
  {
    (void) memset((void *)
                  &Control_Mov_PI_Digilent_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  2*sizeof(SimStruct));
    Control_Mov_PI_Digilent_M->childSfunctions =
      (&Control_Mov_PI_Digilent_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    Control_Mov_PI_Digilent_M->childSfunctions[0] =
      (&Control_Mov_PI_Digilent_M->NonInlinedSFcns.childSFunctions[0]);
    Control_Mov_PI_Digilent_M->childSfunctions[1] =
      (&Control_Mov_PI_Digilent_M->NonInlinedSFcns.childSFunctions[1]);

    /* Level2 S-Function Block: Control_Mov_PI_Digilent/<Root>/PCI 6221 ENC  (encnipcim) */
    {
      SimStruct *rts = Control_Mov_PI_Digilent_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        Control_Mov_PI_Digilent_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        Control_Mov_PI_Digilent_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        Control_Mov_PI_Digilent_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Control_Mov_PI_Digilent_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Control_Mov_PI_Digilent_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Control_Mov_PI_Digilent_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Control_Mov_PI_Digilent_M->NonInlinedSFcns.methods2
                           [0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Control_Mov_PI_Digilent_M->NonInlinedSFcns.methods3
                           [0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Control_Mov_PI_Digilent_M->NonInlinedSFcns.methods4
                           [0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Control_Mov_PI_Digilent_M->
                         NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &Control_Mov_PI_Digilent_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Control_Mov_PI_Digilent_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Control_Mov_PI_Digilent_M->NonInlinedSFcns.Sfcn0.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Control_Mov_PI_Digilent_B.PCI6221ENC));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI 6221 ENC ");
      ssSetPath(rts, "Control_Mov_PI_Digilent/PCI 6221 ENC ");
      ssSetRTModel(rts,Control_Mov_PI_Digilent_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Control_Mov_PI_Digilent_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Control_Mov_PI_Digilent_P.PCI6221ENC_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Control_Mov_PI_Digilent_P.PCI6221ENC_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Control_Mov_PI_Digilent_P.PCI6221ENC_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Control_Mov_PI_Digilent_P.PCI6221ENC_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Control_Mov_PI_Digilent_P.PCI6221ENC_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Control_Mov_PI_Digilent_P.PCI6221ENC_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       Control_Mov_PI_Digilent_P.PCI6221ENC_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       Control_Mov_PI_Digilent_P.PCI6221ENC_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       Control_Mov_PI_Digilent_P.PCI6221ENC_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       Control_Mov_PI_Digilent_P.PCI6221ENC_P10_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &Control_Mov_PI_Digilent_DW.PCI6221ENC_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Control_Mov_PI_Digilent_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Control_Mov_PI_Digilent_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Control_Mov_PI_Digilent_DW.PCI6221ENC_PWORK);
      }

      /* registration */
      encnipcim(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Control_Mov_PI_Digilent/<Root>/PCI-6221 DA (danipcim) */
    {
      SimStruct *rts = Control_Mov_PI_Digilent_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        Control_Mov_PI_Digilent_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        Control_Mov_PI_Digilent_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap =
        Control_Mov_PI_Digilent_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Control_Mov_PI_Digilent_M->NonInlinedSFcns.blkInfo2[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Control_Mov_PI_Digilent_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Control_Mov_PI_Digilent_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Control_Mov_PI_Digilent_M->NonInlinedSFcns.methods2
                           [1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Control_Mov_PI_Digilent_M->NonInlinedSFcns.methods3
                           [1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Control_Mov_PI_Digilent_M->NonInlinedSFcns.methods4
                           [1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Control_Mov_PI_Digilent_M->
                         NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &Control_Mov_PI_Digilent_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &Control_Mov_PI_Digilent_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Control_Mov_PI_Digilent_M->NonInlinedSFcns.Sfcn1.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Control_Mov_PI_Digilent_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &Control_Mov_PI_Digilent_B.Sum_i;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Control_Mov_PI_Digilent_M->NonInlinedSFcns.Sfcn1.UPtrs1;
          sfcnUPtrs[0] = &Control_Mov_PI_Digilent_B.Constant1;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6221 DA");
      ssSetPath(rts, "Control_Mov_PI_Digilent/PCI-6221 DA");
      ssSetRTModel(rts,Control_Mov_PI_Digilent_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Control_Mov_PI_Digilent_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Control_Mov_PI_Digilent_P.PCI6221DA_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Control_Mov_PI_Digilent_P.PCI6221DA_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Control_Mov_PI_Digilent_P.PCI6221DA_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Control_Mov_PI_Digilent_P.PCI6221DA_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Control_Mov_PI_Digilent_P.PCI6221DA_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       Control_Mov_PI_Digilent_P.PCI6221DA_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       Control_Mov_PI_Digilent_P.PCI6221DA_P7_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &Control_Mov_PI_Digilent_DW.PCI6221DA_RWORK[0]);
      ssSetIWork(rts, (int_T *) &Control_Mov_PI_Digilent_DW.PCI6221DA_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Control_Mov_PI_Digilent_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Control_Mov_PI_Digilent_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 6);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Control_Mov_PI_Digilent_DW.PCI6221DA_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 41);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &Control_Mov_PI_Digilent_DW.PCI6221DA_IWORK[0]);
      }

      /* registration */
      danipcim(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }
  }

  /* Initialize Sizes */
  Control_Mov_PI_Digilent_M->Sizes.numContStates = (1);/* Number of continuous states */
  Control_Mov_PI_Digilent_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  Control_Mov_PI_Digilent_M->Sizes.numY = (0);/* Number of model outputs */
  Control_Mov_PI_Digilent_M->Sizes.numU = (0);/* Number of model inputs */
  Control_Mov_PI_Digilent_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Control_Mov_PI_Digilent_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Control_Mov_PI_Digilent_M->Sizes.numBlocks = (18);/* Number of blocks */
  Control_Mov_PI_Digilent_M->Sizes.numBlockIO = (11);/* Number of block outputs */
  Control_Mov_PI_Digilent_M->Sizes.numBlockPrms = (60);/* Sum of parameter "widths" */
  return Control_Mov_PI_Digilent_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
