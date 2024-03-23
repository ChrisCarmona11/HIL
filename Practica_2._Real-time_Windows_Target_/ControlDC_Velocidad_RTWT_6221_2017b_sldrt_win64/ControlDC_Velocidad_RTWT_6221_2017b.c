/*
 * ControlDC_Velocidad_RTWT_6221_2017b.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ControlDC_Velocidad_RTWT_6221_2017b".
 *
 * Model version              : 1.72
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Thu Jan 11 18:15:51 2024
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ControlDC_Velocidad_RTWT_6221_2017b.h"
#include "ControlDC_Velocidad_RTWT_6221_2017b_private.h"
#include "ControlDC_Velocidad_RTWT_6221_2017b_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  1.0,
  1.0,
  20480.0,
  3.0,
  2.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.04, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "National_Instruments/PCI-6221", 4294967295U, 5, SLDRTBoardOptions0 },
};

/* Block signals (auto storage) */
B_ControlDC_Velocidad_RTWT_6221_2017b_T ControlDC_Velocidad_RTWT_6221_2017b_B;

/* Continuous states */
X_ControlDC_Velocidad_RTWT_6221_2017b_T ControlDC_Velocidad_RTWT_6221_2017b_X;

/* Block states (auto storage) */
DW_ControlDC_Velocidad_RTWT_6221_2017b_T ControlDC_Velocidad_RTWT_6221_2017b_DW;

/* Real-time model */
RT_MODEL_ControlDC_Velocidad_RTWT_6221_2017b_T
  ControlDC_Velocidad_RTWT_6221_2017b_M_;
RT_MODEL_ControlDC_Velocidad_RTWT_6221_2017b_T *const
  ControlDC_Velocidad_RTWT_6221_2017b_M =
  &ControlDC_Velocidad_RTWT_6221_2017b_M_;

/*
 * This function updates continuous states using the ODE5 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE5_A[6] = {
    1.0/5.0, 3.0/10.0, 4.0/5.0, 8.0/9.0, 1.0, 1.0
  };

  static const real_T rt_ODE5_B[6][6] = {
    { 1.0/5.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

    { 3.0/40.0, 9.0/40.0, 0.0, 0.0, 0.0, 0.0 },

    { 44.0/45.0, -56.0/15.0, 32.0/9.0, 0.0, 0.0, 0.0 },

    { 19372.0/6561.0, -25360.0/2187.0, 64448.0/6561.0, -212.0/729.0, 0.0, 0.0 },

    { 9017.0/3168.0, -355.0/33.0, 46732.0/5247.0, 49.0/176.0, -5103.0/18656.0,
      0.0 },

    { 35.0/384.0, 0.0, 500.0/1113.0, 125.0/192.0, -2187.0/6784.0, 11.0/84.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE5_IntgData *id = (ODE5_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T *f4 = id->f[4];
  real_T *f5 = id->f[5];
  real_T hB[6];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ControlDC_Velocidad_RTWT_6221_2017b_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  ControlDC_Velocidad_RTWT_6221_2017b_output();
  ControlDC_Velocidad_RTWT_6221_2017b_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  ControlDC_Velocidad_RTWT_6221_2017b_output();
  ControlDC_Velocidad_RTWT_6221_2017b_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  ControlDC_Velocidad_RTWT_6221_2017b_output();
  ControlDC_Velocidad_RTWT_6221_2017b_derivatives();

  /* f(:,5) = feval(odefile, t + hA(4), y + f*hB(:,4), args(:)(*)); */
  for (i = 0; i <= 3; i++) {
    hB[i] = h * rt_ODE5_B[3][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[3]);
  rtsiSetdX(si, f4);
  ControlDC_Velocidad_RTWT_6221_2017b_output();
  ControlDC_Velocidad_RTWT_6221_2017b_derivatives();

  /* f(:,6) = feval(odefile, t + hA(5), y + f*hB(:,5), args(:)(*)); */
  for (i = 0; i <= 4; i++) {
    hB[i] = h * rt_ODE5_B[4][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f5);
  ControlDC_Velocidad_RTWT_6221_2017b_output();
  ControlDC_Velocidad_RTWT_6221_2017b_derivatives();

  /* tnew = t + hA(6);
     ynew = y + f*hB(:,6); */
  for (i = 0; i <= 5; i++) {
    hB[i] = h * rt_ODE5_B[5][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4] + f5[i]*hB[5]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void ControlDC_Velocidad_RTWT_6221_2017b_output(void)
{
  real_T *lastU;
  real_T rtb_ConversionRPM1;
  if (rtmIsMajorTimeStep(ControlDC_Velocidad_RTWT_6221_2017b_M)) {
    /* set solver stop time */
    if (!(ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ControlDC_Velocidad_RTWT_6221_2017b_M->solverInfo,
                            ((ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.clockTickH0
        + 1) * ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.stepSize0 *
        4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ControlDC_Velocidad_RTWT_6221_2017b_M->solverInfo,
                            ((ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.clockTick0
        + 1) * ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.stepSize0 +
        ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.clockTickH0 *
        ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ControlDC_Velocidad_RTWT_6221_2017b_M)) {
    ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.t[0] = rtsiGetT
      (&ControlDC_Velocidad_RTWT_6221_2017b_M->solverInfo);
  }

  /* SignalGenerator: '<Root>/Consigna Velocidad' */
  rtb_ConversionRPM1 =
    ControlDC_Velocidad_RTWT_6221_2017b_P.ConsignaVelocidad_Frequency *
    ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.t[0];

  /* Gain: '<Root>/Normalizacion2' incorporates:
   *  SignalGenerator: '<Root>/Consigna Velocidad'
   */
  ControlDC_Velocidad_RTWT_6221_2017b_B.Normalizacion2 = (1.0 -
    (rtb_ConversionRPM1 - floor(rtb_ConversionRPM1)) * 2.0) *
    ControlDC_Velocidad_RTWT_6221_2017b_P.ConsignaVelocidad_Amplitude *
    ControlDC_Velocidad_RTWT_6221_2017b_P.Normalizacion2_Gain;
  if (rtmIsMajorTimeStep(ControlDC_Velocidad_RTWT_6221_2017b_M)) {
    /* S-Function (sldrtei): '<Root>/Encoder Input' */
    /* S-Function Block: <Root>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter =
        ControlDC_Velocidad_RTWT_6221_2017b_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                     &ControlDC_Velocidad_RTWT_6221_2017b_P.EncoderInput_Channels,
                     &ControlDC_Velocidad_RTWT_6221_2017b_B.EncoderInput_o1,
                     &parm);
      ControlDC_Velocidad_RTWT_6221_2017b_B.EncoderInput_o2 = 0;/* Missed Ticks value is always zero */
    }

    /* UnitDelay: '<Root>/Unit Delay' */
    ControlDC_Velocidad_RTWT_6221_2017b_B.UnitDelay =
      ControlDC_Velocidad_RTWT_6221_2017b_DW.UnitDelay_DSTATE;

    /* Sum: '<Root>/Sum' */
    ControlDC_Velocidad_RTWT_6221_2017b_B.Sum =
      ControlDC_Velocidad_RTWT_6221_2017b_B.EncoderInput_o1 -
      ControlDC_Velocidad_RTWT_6221_2017b_B.UnitDelay;

    /* Gain: '<Root>/Conversion RPM1' */
    rtb_ConversionRPM1 = 5.0 / (53.0 * ControlDC_Velocidad_RTWT_6221_2017b_P.T) *
      ControlDC_Velocidad_RTWT_6221_2017b_B.Sum;

    /* RateTransition: '<Root>/Rate Transition1' */
    if (rtmIsMajorTimeStep(ControlDC_Velocidad_RTWT_6221_2017b_M)) {
      ControlDC_Velocidad_RTWT_6221_2017b_B.RateTransition1 = rtb_ConversionRPM1;
    }

    /* End of RateTransition: '<Root>/Rate Transition1' */

    /* Gain: '<Root>/Normalizacion1' */
    ControlDC_Velocidad_RTWT_6221_2017b_B.Normalizacion1 =
      ControlDC_Velocidad_RTWT_6221_2017b_P.Normalizacion1_Gain *
      ControlDC_Velocidad_RTWT_6221_2017b_B.RateTransition1;
  }

  /* Sum: '<Root>/Sum1' */
  ControlDC_Velocidad_RTWT_6221_2017b_B.Sum1 =
    ControlDC_Velocidad_RTWT_6221_2017b_B.Normalizacion2 -
    ControlDC_Velocidad_RTWT_6221_2017b_B.Normalizacion1;

  /* Gain: '<S2>/Derivative Gain' */
  ControlDC_Velocidad_RTWT_6221_2017b_B.DerivativeGain =
    ControlDC_Velocidad_RTWT_6221_2017b_P.PIDController_D *
    ControlDC_Velocidad_RTWT_6221_2017b_B.Sum1;

  /* Derivative: '<S2>/Ideal Derivative' */
  if ((ControlDC_Velocidad_RTWT_6221_2017b_DW.TimeStampA >=
       ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.t[0]) &&
      (ControlDC_Velocidad_RTWT_6221_2017b_DW.TimeStampB >=
       ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.t[0])) {
    rtb_ConversionRPM1 = 0.0;
  } else {
    rtb_ConversionRPM1 = ControlDC_Velocidad_RTWT_6221_2017b_DW.TimeStampA;
    lastU = &ControlDC_Velocidad_RTWT_6221_2017b_DW.LastUAtTimeA;
    if (ControlDC_Velocidad_RTWT_6221_2017b_DW.TimeStampA <
        ControlDC_Velocidad_RTWT_6221_2017b_DW.TimeStampB) {
      if (ControlDC_Velocidad_RTWT_6221_2017b_DW.TimeStampB <
          ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.t[0]) {
        rtb_ConversionRPM1 = ControlDC_Velocidad_RTWT_6221_2017b_DW.TimeStampB;
        lastU = &ControlDC_Velocidad_RTWT_6221_2017b_DW.LastUAtTimeB;
      }
    } else {
      if (ControlDC_Velocidad_RTWT_6221_2017b_DW.TimeStampA >=
          ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.t[0]) {
        rtb_ConversionRPM1 = ControlDC_Velocidad_RTWT_6221_2017b_DW.TimeStampB;
        lastU = &ControlDC_Velocidad_RTWT_6221_2017b_DW.LastUAtTimeB;
      }
    }

    rtb_ConversionRPM1 = (ControlDC_Velocidad_RTWT_6221_2017b_B.DerivativeGain -
                          *lastU) /
      (ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.t[0] - rtb_ConversionRPM1);
  }

  /* End of Derivative: '<S2>/Ideal Derivative' */

  /* Sum: '<S2>/Sum' incorporates:
   *  Gain: '<S2>/Proportional Gain'
   *  Integrator: '<S2>/Integrator'
   */
  rtb_ConversionRPM1 += ControlDC_Velocidad_RTWT_6221_2017b_P.PIDController_P *
    ControlDC_Velocidad_RTWT_6221_2017b_B.Sum1 +
    ControlDC_Velocidad_RTWT_6221_2017b_X.Integrator_CSTATE;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_ConversionRPM1 >
      ControlDC_Velocidad_RTWT_6221_2017b_P.Saturation_UpperSat) {
    ControlDC_Velocidad_RTWT_6221_2017b_B.Saturation =
      ControlDC_Velocidad_RTWT_6221_2017b_P.Saturation_UpperSat;
  } else if (rtb_ConversionRPM1 <
             ControlDC_Velocidad_RTWT_6221_2017b_P.Saturation_LowerSat) {
    ControlDC_Velocidad_RTWT_6221_2017b_B.Saturation =
      ControlDC_Velocidad_RTWT_6221_2017b_P.Saturation_LowerSat;
  } else {
    ControlDC_Velocidad_RTWT_6221_2017b_B.Saturation = rtb_ConversionRPM1;
  }

  /* End of Saturate: '<Root>/Saturation' */
  if (rtmIsMajorTimeStep(ControlDC_Velocidad_RTWT_6221_2017b_M)) {
    /* Constant: '<Root>/Constant1' */
    ControlDC_Velocidad_RTWT_6221_2017b_B.Constant1 =
      ControlDC_Velocidad_RTWT_6221_2017b_P.Constant1_Value;
  }

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Abs: '<Root>/Abs'
   *  DeadZone: '<Root>/Dead Zone'
   */
  if (ControlDC_Velocidad_RTWT_6221_2017b_P.ManualSwitch_CurrentSetting == 1) {
    ControlDC_Velocidad_RTWT_6221_2017b_B.ManualSwitch =
      ControlDC_Velocidad_RTWT_6221_2017b_B.Constant1;
  } else {
    if (ControlDC_Velocidad_RTWT_6221_2017b_B.Saturation >
        ControlDC_Velocidad_RTWT_6221_2017b_P.DeadZone_End) {
      /* DeadZone: '<Root>/Dead Zone' */
      rtb_ConversionRPM1 = ControlDC_Velocidad_RTWT_6221_2017b_B.Saturation -
        ControlDC_Velocidad_RTWT_6221_2017b_P.DeadZone_End;
    } else if (ControlDC_Velocidad_RTWT_6221_2017b_B.Saturation >=
               ControlDC_Velocidad_RTWT_6221_2017b_P.DeadZone_Start) {
      /* DeadZone: '<Root>/Dead Zone' */
      rtb_ConversionRPM1 = 0.0;
    } else {
      /* DeadZone: '<Root>/Dead Zone' */
      rtb_ConversionRPM1 = ControlDC_Velocidad_RTWT_6221_2017b_B.Saturation -
        ControlDC_Velocidad_RTWT_6221_2017b_P.DeadZone_Start;
    }

    ControlDC_Velocidad_RTWT_6221_2017b_B.ManualSwitch = fabs(rtb_ConversionRPM1);
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */
  if (rtmIsMajorTimeStep(ControlDC_Velocidad_RTWT_6221_2017b_M)) {
    /* Constant: '<Root>/Constant3' */
    ControlDC_Velocidad_RTWT_6221_2017b_B.Constant3 =
      ControlDC_Velocidad_RTWT_6221_2017b_P.Constant3_Value;

    /* Constant: '<Root>/Constant2' */
    ControlDC_Velocidad_RTWT_6221_2017b_B.Constant2 =
      ControlDC_Velocidad_RTWT_6221_2017b_P.Constant2_Value;
  }

  /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
   *  Constant: '<S1>/Constant'
   *  RelationalOperator: '<S1>/Compare'
   */
  if (ControlDC_Velocidad_RTWT_6221_2017b_P.ManualSwitch1_CurrentSetting == 1) {
    rtb_ConversionRPM1 = (ControlDC_Velocidad_RTWT_6221_2017b_B.Saturation <
                          ControlDC_Velocidad_RTWT_6221_2017b_P.Constant_Value);
  } else {
    rtb_ConversionRPM1 = ControlDC_Velocidad_RTWT_6221_2017b_B.Constant3;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch1' */

  /* Product: '<Root>/Product2' */
  ControlDC_Velocidad_RTWT_6221_2017b_B.Product2 = rtb_ConversionRPM1 *
    ControlDC_Velocidad_RTWT_6221_2017b_B.Constant2;
  if (rtmIsMajorTimeStep(ControlDC_Velocidad_RTWT_6221_2017b_M)) {
    /* S-Function (sldrtdo): '<Root>/Digital Output1' */
    /* S-Function Block: <Root>/Digital Output1 */
    {
      RTBIO_DriverIO(0, DIGITALOUTPUT, IOWRITE, 1,
                     &ControlDC_Velocidad_RTWT_6221_2017b_P.DigitalOutput1_Channels,
                     ((real_T*) (&ControlDC_Velocidad_RTWT_6221_2017b_B.Product2)),
                     &ControlDC_Velocidad_RTWT_6221_2017b_P.DigitalOutput1_BitMode);
    }
  }

  /* S-Function (sldrtqo): '<Root>/Frequency Output1' */
  /* S-Function Block: <Root>/Frequency Output1 */
  {
    {
      RTBIO_DriverIO(0, FREQUENCYOUTPUT, IOWRITE, 1,
                     &ControlDC_Velocidad_RTWT_6221_2017b_P.FrequencyOutput1_Channels,
                     &ControlDC_Velocidad_RTWT_6221_2017b_P.FrequencyOutput1_Frequency,
                     ((real_T*)
                      (&ControlDC_Velocidad_RTWT_6221_2017b_B.ManualSwitch)));
    }
  }

  if (rtmIsMajorTimeStep(ControlDC_Velocidad_RTWT_6221_2017b_M)) {
  }

  /* Gain: '<S2>/Integral Gain' */
  ControlDC_Velocidad_RTWT_6221_2017b_B.IntegralGain =
    ControlDC_Velocidad_RTWT_6221_2017b_P.PIDController_I *
    ControlDC_Velocidad_RTWT_6221_2017b_B.Sum1;
}

/* Model update function */
void ControlDC_Velocidad_RTWT_6221_2017b_update(void)
{
  real_T *lastU;
  if (rtmIsMajorTimeStep(ControlDC_Velocidad_RTWT_6221_2017b_M)) {
    /* Update for UnitDelay: '<Root>/Unit Delay' */
    ControlDC_Velocidad_RTWT_6221_2017b_DW.UnitDelay_DSTATE =
      ControlDC_Velocidad_RTWT_6221_2017b_B.EncoderInput_o1;
  }

  /* Update for Derivative: '<S2>/Ideal Derivative' */
  if (ControlDC_Velocidad_RTWT_6221_2017b_DW.TimeStampA == (rtInf)) {
    ControlDC_Velocidad_RTWT_6221_2017b_DW.TimeStampA =
      ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.t[0];
    lastU = &ControlDC_Velocidad_RTWT_6221_2017b_DW.LastUAtTimeA;
  } else if (ControlDC_Velocidad_RTWT_6221_2017b_DW.TimeStampB == (rtInf)) {
    ControlDC_Velocidad_RTWT_6221_2017b_DW.TimeStampB =
      ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.t[0];
    lastU = &ControlDC_Velocidad_RTWT_6221_2017b_DW.LastUAtTimeB;
  } else if (ControlDC_Velocidad_RTWT_6221_2017b_DW.TimeStampA <
             ControlDC_Velocidad_RTWT_6221_2017b_DW.TimeStampB) {
    ControlDC_Velocidad_RTWT_6221_2017b_DW.TimeStampA =
      ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.t[0];
    lastU = &ControlDC_Velocidad_RTWT_6221_2017b_DW.LastUAtTimeA;
  } else {
    ControlDC_Velocidad_RTWT_6221_2017b_DW.TimeStampB =
      ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.t[0];
    lastU = &ControlDC_Velocidad_RTWT_6221_2017b_DW.LastUAtTimeB;
  }

  *lastU = ControlDC_Velocidad_RTWT_6221_2017b_B.DerivativeGain;

  /* End of Update for Derivative: '<S2>/Ideal Derivative' */
  if (rtmIsMajorTimeStep(ControlDC_Velocidad_RTWT_6221_2017b_M)) {
    rt_ertODEUpdateContinuousStates
      (&ControlDC_Velocidad_RTWT_6221_2017b_M->solverInfo);
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
  if (!(++ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.clockTick0)) {
    ++ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.clockTickH0;
  }

  ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.t[0] = rtsiGetSolverStopTime
    (&ControlDC_Velocidad_RTWT_6221_2017b_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.04s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.clockTick1)) {
      ++ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.clockTickH1;
    }

    ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.t[1] =
      ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.clockTick1 *
      ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.stepSize1 +
      ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.clockTickH1 *
      ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ControlDC_Velocidad_RTWT_6221_2017b_derivatives(void)
{
  XDot_ControlDC_Velocidad_RTWT_6221_2017b_T *_rtXdot;
  _rtXdot = ((XDot_ControlDC_Velocidad_RTWT_6221_2017b_T *)
             ControlDC_Velocidad_RTWT_6221_2017b_M->derivs);

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE =
    ControlDC_Velocidad_RTWT_6221_2017b_B.IntegralGain;
}

/* Model initialize function */
void ControlDC_Velocidad_RTWT_6221_2017b_initialize(void)
{
  /* Start for S-Function (sldrtdo): '<Root>/Digital Output1' */

  /* S-Function Block: <Root>/Digital Output1 */
  {
    RTBIO_DriverIO(0, DIGITALOUTPUT, IOWRITE, 1,
                   &ControlDC_Velocidad_RTWT_6221_2017b_P.DigitalOutput1_Channels,
                   &ControlDC_Velocidad_RTWT_6221_2017b_P.DigitalOutput1_InitialValue,
                   &ControlDC_Velocidad_RTWT_6221_2017b_P.DigitalOutput1_BitMode);
  }

  /* Start for S-Function (sldrtqo): '<Root>/Frequency Output1' */

  /* S-Function Block: <Root>/Frequency Output1 */
  {
    {
      RTBIO_DriverIO(0, FREQUENCYOUTPUT, IOWRITE, 1,
                     &ControlDC_Velocidad_RTWT_6221_2017b_P.FrequencyOutput1_Channels,
                     &ControlDC_Velocidad_RTWT_6221_2017b_P.FrequencyOutput1_Frequency,
                     &ControlDC_Velocidad_RTWT_6221_2017b_P.FrequencyOutput1_Duty);
    }
  }

  /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input' */

  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter =
      ControlDC_Velocidad_RTWT_6221_2017b_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &ControlDC_Velocidad_RTWT_6221_2017b_P.EncoderInput_Channels,
                   NULL, &parm);
  }

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  ControlDC_Velocidad_RTWT_6221_2017b_DW.UnitDelay_DSTATE =
    ControlDC_Velocidad_RTWT_6221_2017b_P.UnitDelay_InitialCondition;

  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  ControlDC_Velocidad_RTWT_6221_2017b_X.Integrator_CSTATE =
    ControlDC_Velocidad_RTWT_6221_2017b_P.Integrator_IC;

  /* InitializeConditions for Derivative: '<S2>/Ideal Derivative' */
  ControlDC_Velocidad_RTWT_6221_2017b_DW.TimeStampA = (rtInf);
  ControlDC_Velocidad_RTWT_6221_2017b_DW.TimeStampB = (rtInf);
}

/* Model terminate function */
void ControlDC_Velocidad_RTWT_6221_2017b_terminate(void)
{
  /* Terminate for S-Function (sldrtdo): '<Root>/Digital Output1' */

  /* S-Function Block: <Root>/Digital Output1 */
  {
    RTBIO_DriverIO(0, DIGITALOUTPUT, IOWRITE, 1,
                   &ControlDC_Velocidad_RTWT_6221_2017b_P.DigitalOutput1_Channels,
                   &ControlDC_Velocidad_RTWT_6221_2017b_P.DigitalOutput1_FinalValue,
                   &ControlDC_Velocidad_RTWT_6221_2017b_P.DigitalOutput1_BitMode);
  }

  /* Terminate for S-Function (sldrtqo): '<Root>/Frequency Output1' */

  /* S-Function Block: <Root>/Frequency Output1 */
  {
    {
      RTBIO_DriverIO(0, FREQUENCYOUTPUT, IOWRITE, 1,
                     &ControlDC_Velocidad_RTWT_6221_2017b_P.FrequencyOutput1_Channels,
                     &ControlDC_Velocidad_RTWT_6221_2017b_P.FrequencyOutput1_Frequency,
                     &ControlDC_Velocidad_RTWT_6221_2017b_P.FrequencyOutput1_DutyFinalValue);
    }
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
  ControlDC_Velocidad_RTWT_6221_2017b_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ControlDC_Velocidad_RTWT_6221_2017b_update();
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
  ControlDC_Velocidad_RTWT_6221_2017b_initialize();
}

void MdlTerminate(void)
{
  ControlDC_Velocidad_RTWT_6221_2017b_terminate();
}

/* Registration function */
RT_MODEL_ControlDC_Velocidad_RTWT_6221_2017b_T
  *ControlDC_Velocidad_RTWT_6221_2017b(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  ControlDC_Velocidad_RTWT_6221_2017b_P.EncoderInput_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)ControlDC_Velocidad_RTWT_6221_2017b_M, 0,
                sizeof(RT_MODEL_ControlDC_Velocidad_RTWT_6221_2017b_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ControlDC_Velocidad_RTWT_6221_2017b_M->solverInfo,
                          &ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.simTimeStep);
    rtsiSetTPtr(&ControlDC_Velocidad_RTWT_6221_2017b_M->solverInfo, &rtmGetTPtr
                (ControlDC_Velocidad_RTWT_6221_2017b_M));
    rtsiSetStepSizePtr(&ControlDC_Velocidad_RTWT_6221_2017b_M->solverInfo,
                       &ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.stepSize0);
    rtsiSetdXPtr(&ControlDC_Velocidad_RTWT_6221_2017b_M->solverInfo,
                 &ControlDC_Velocidad_RTWT_6221_2017b_M->derivs);
    rtsiSetContStatesPtr(&ControlDC_Velocidad_RTWT_6221_2017b_M->solverInfo,
                         (real_T **)
                         &ControlDC_Velocidad_RTWT_6221_2017b_M->contStates);
    rtsiSetNumContStatesPtr(&ControlDC_Velocidad_RTWT_6221_2017b_M->solverInfo,
      &ControlDC_Velocidad_RTWT_6221_2017b_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr
      (&ControlDC_Velocidad_RTWT_6221_2017b_M->solverInfo,
       &ControlDC_Velocidad_RTWT_6221_2017b_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&ControlDC_Velocidad_RTWT_6221_2017b_M->solverInfo,
       &ControlDC_Velocidad_RTWT_6221_2017b_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&ControlDC_Velocidad_RTWT_6221_2017b_M->solverInfo,
       &ControlDC_Velocidad_RTWT_6221_2017b_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&ControlDC_Velocidad_RTWT_6221_2017b_M->solverInfo,
                          (&rtmGetErrorStatus
      (ControlDC_Velocidad_RTWT_6221_2017b_M)));
    rtsiSetRTModelPtr(&ControlDC_Velocidad_RTWT_6221_2017b_M->solverInfo,
                      ControlDC_Velocidad_RTWT_6221_2017b_M);
  }

  rtsiSetSimTimeStep(&ControlDC_Velocidad_RTWT_6221_2017b_M->solverInfo,
                     MAJOR_TIME_STEP);
  ControlDC_Velocidad_RTWT_6221_2017b_M->intgData.y =
    ControlDC_Velocidad_RTWT_6221_2017b_M->odeY;
  ControlDC_Velocidad_RTWT_6221_2017b_M->intgData.f[0] =
    ControlDC_Velocidad_RTWT_6221_2017b_M->odeF[0];
  ControlDC_Velocidad_RTWT_6221_2017b_M->intgData.f[1] =
    ControlDC_Velocidad_RTWT_6221_2017b_M->odeF[1];
  ControlDC_Velocidad_RTWT_6221_2017b_M->intgData.f[2] =
    ControlDC_Velocidad_RTWT_6221_2017b_M->odeF[2];
  ControlDC_Velocidad_RTWT_6221_2017b_M->intgData.f[3] =
    ControlDC_Velocidad_RTWT_6221_2017b_M->odeF[3];
  ControlDC_Velocidad_RTWT_6221_2017b_M->intgData.f[4] =
    ControlDC_Velocidad_RTWT_6221_2017b_M->odeF[4];
  ControlDC_Velocidad_RTWT_6221_2017b_M->intgData.f[5] =
    ControlDC_Velocidad_RTWT_6221_2017b_M->odeF[5];
  ControlDC_Velocidad_RTWT_6221_2017b_M->contStates = ((real_T *)
    &ControlDC_Velocidad_RTWT_6221_2017b_X);
  rtsiSetSolverData(&ControlDC_Velocidad_RTWT_6221_2017b_M->solverInfo, (void *)
                    &ControlDC_Velocidad_RTWT_6221_2017b_M->intgData);
  rtsiSetSolverName(&ControlDC_Velocidad_RTWT_6221_2017b_M->solverInfo,"ode5");

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.sampleTimeTaskIDPtr =
      (&mdlTsMap[0]);
    ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.sampleTimes =
      (&ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.sampleTimesArray[0]);
    ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.offsetTimes =
      (&ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.sampleTimes[0] = (0.0);
    ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.sampleTimes[1] = (0.04);

    /* task offsets */
    ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.offsetTimes[0] = (0.0);
    ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ControlDC_Velocidad_RTWT_6221_2017b_M,
             &ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits =
      ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ControlDC_Velocidad_RTWT_6221_2017b_M, 20.0);
  ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.stepSize0 = 0.04;
  ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.stepSize1 = 0.04;

  /* External mode info */
  ControlDC_Velocidad_RTWT_6221_2017b_M->Sizes.checksums[0] = (1379066141U);
  ControlDC_Velocidad_RTWT_6221_2017b_M->Sizes.checksums[1] = (1194921155U);
  ControlDC_Velocidad_RTWT_6221_2017b_M->Sizes.checksums[2] = (3972692041U);
  ControlDC_Velocidad_RTWT_6221_2017b_M->Sizes.checksums[3] = (3550116033U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    ControlDC_Velocidad_RTWT_6221_2017b_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr
      (ControlDC_Velocidad_RTWT_6221_2017b_M->extModeInfo,
       &ControlDC_Velocidad_RTWT_6221_2017b_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ControlDC_Velocidad_RTWT_6221_2017b_M->extModeInfo,
                        ControlDC_Velocidad_RTWT_6221_2017b_M->Sizes.checksums);
    rteiSetTPtr(ControlDC_Velocidad_RTWT_6221_2017b_M->extModeInfo, rtmGetTPtr
                (ControlDC_Velocidad_RTWT_6221_2017b_M));
  }

  ControlDC_Velocidad_RTWT_6221_2017b_M->solverInfoPtr =
    (&ControlDC_Velocidad_RTWT_6221_2017b_M->solverInfo);
  ControlDC_Velocidad_RTWT_6221_2017b_M->Timing.stepSize = (0.04);
  rtsiSetFixedStepSize(&ControlDC_Velocidad_RTWT_6221_2017b_M->solverInfo, 0.04);
  rtsiSetSolverMode(&ControlDC_Velocidad_RTWT_6221_2017b_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ControlDC_Velocidad_RTWT_6221_2017b_M->blockIO = ((void *)
    &ControlDC_Velocidad_RTWT_6221_2017b_B);
  (void) memset(((void *) &ControlDC_Velocidad_RTWT_6221_2017b_B), 0,
                sizeof(B_ControlDC_Velocidad_RTWT_6221_2017b_T));

  /* parameters */
  ControlDC_Velocidad_RTWT_6221_2017b_M->defaultParam = ((real_T *)
    &ControlDC_Velocidad_RTWT_6221_2017b_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ControlDC_Velocidad_RTWT_6221_2017b_X;
    ControlDC_Velocidad_RTWT_6221_2017b_M->contStates = (x);
    (void) memset((void *)&ControlDC_Velocidad_RTWT_6221_2017b_X, 0,
                  sizeof(X_ControlDC_Velocidad_RTWT_6221_2017b_T));
  }

  /* states (dwork) */
  ControlDC_Velocidad_RTWT_6221_2017b_M->dwork = ((void *)
    &ControlDC_Velocidad_RTWT_6221_2017b_DW);
  (void) memset((void *)&ControlDC_Velocidad_RTWT_6221_2017b_DW, 0,
                sizeof(DW_ControlDC_Velocidad_RTWT_6221_2017b_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ControlDC_Velocidad_RTWT_6221_2017b_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  ControlDC_Velocidad_RTWT_6221_2017b_M->Sizes.numContStates = (1);/* Number of continuous states */
  ControlDC_Velocidad_RTWT_6221_2017b_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ControlDC_Velocidad_RTWT_6221_2017b_M->Sizes.numY = (0);/* Number of model outputs */
  ControlDC_Velocidad_RTWT_6221_2017b_M->Sizes.numU = (0);/* Number of model inputs */
  ControlDC_Velocidad_RTWT_6221_2017b_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ControlDC_Velocidad_RTWT_6221_2017b_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ControlDC_Velocidad_RTWT_6221_2017b_M->Sizes.numBlocks = (39);/* Number of blocks */
  ControlDC_Velocidad_RTWT_6221_2017b_M->Sizes.numBlockIO = (16);/* Number of block outputs */
  ControlDC_Velocidad_RTWT_6221_2017b_M->Sizes.numBlockPrms = (36);/* Sum of parameter "widths" */
  return ControlDC_Velocidad_RTWT_6221_2017b_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
