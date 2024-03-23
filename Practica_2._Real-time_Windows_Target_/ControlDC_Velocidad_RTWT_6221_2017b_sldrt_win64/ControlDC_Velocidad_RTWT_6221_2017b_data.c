/*
 * ControlDC_Velocidad_RTWT_6221_2017b_data.c
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

/* Block parameters (auto storage) */
P_ControlDC_Velocidad_RTWT_6221_2017b_T ControlDC_Velocidad_RTWT_6221_2017b_P =
  {
  /* Variable: T
   * Referenced by: '<Root>/Conversion RPM1'
   */
  0.04,

  /* Mask Parameter: PIDController_D
   * Referenced by: '<S2>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: FrequencyOutput1_Duty
   * Referenced by: '<Root>/Frequency Output1'
   */
  0.0,

  /* Mask Parameter: FrequencyOutput1_DutyFinalValue
   * Referenced by: '<Root>/Frequency Output1'
   */
  0.0,

  /* Mask Parameter: DigitalOutput1_FinalValue
   * Referenced by: '<Root>/Digital Output1'
   */
  0.0,

  /* Mask Parameter: FrequencyOutput1_Frequency
   * Referenced by: '<Root>/Frequency Output1'
   */
  100.0,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S2>/Integral Gain'
   */
  5.0,

  /* Mask Parameter: DigitalOutput1_InitialValue
   * Referenced by: '<Root>/Digital Output1'
   */
  0.0,

  /* Mask Parameter: EncoderInput_InputFilter
   * Referenced by: '<Root>/Encoder Input'
   */
  0.0,

  /* Mask Parameter: EncoderInput_MaxMissedTicks
   * Referenced by: '<Root>/Encoder Input'
   */
  10.0,

  /* Mask Parameter: DigitalOutput1_MaxMissedTicks
   * Referenced by: '<Root>/Digital Output1'
   */
  10.0,

  /* Mask Parameter: FrequencyOutput1_MaxMissedTicks
   * Referenced by: '<Root>/Frequency Output1'
   */
  10.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S2>/Proportional Gain'
   */
  0.6,

  /* Mask Parameter: EncoderInput_YieldWhenWaiting
   * Referenced by: '<Root>/Encoder Input'
   */
  0.0,

  /* Mask Parameter: DigitalOutput1_YieldWhenWaiting
   * Referenced by: '<Root>/Digital Output1'
   */
  0.0,

  /* Mask Parameter: FrequencyOutput1_YieldWhenWaiting
   * Referenced by: '<Root>/Frequency Output1'
   */
  0.0,

  /* Mask Parameter: DigitalOutput1_BitMode
   * Referenced by: '<Root>/Digital Output1'
   */
  0,

  /* Mask Parameter: EncoderInput_Channels
   * Referenced by: '<Root>/Encoder Input'
   */
  1,

  /* Mask Parameter: DigitalOutput1_Channels
   * Referenced by: '<Root>/Digital Output1'
   */
  0,

  /* Mask Parameter: FrequencyOutput1_Channels
   * Referenced by: '<Root>/Frequency Output1'
   */
  0,

  /* Expression: -0.1
   * Referenced by: '<Root>/Dead Zone'
   */
  -0.1,

  /* Expression: 0.1
   * Referenced by: '<Root>/Dead Zone'
   */
  0.1,

  /* Expression: 140
   * Referenced by: '<Root>/Consigna Velocidad'
   */
  140.0,

  /* Expression: 0.1
   * Referenced by: '<Root>/Consigna Velocidad'
   */
  0.1,

  /* Expression: 1/150
   * Referenced by: '<Root>/Normalizacion2'
   */
  0.0066666666666666671,

  /* Expression: 0
   * Referenced by: '<Root>/Unit Delay'
   */
  0.0,

  /* Expression: 1/150
   * Referenced by: '<Root>/Normalizacion1'
   */
  0.0066666666666666671,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Saturation'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Saturation'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<Root>/Constant3'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant2'
   */
  1.0,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  0U,

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<Root>/Manual Switch1'
   */
  1U
};
