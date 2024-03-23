/*
 * Control_Mov_PI_Digilent_data.c
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

#include "Control_Mov_PI_Digilent.h"
#include "Control_Mov_PI_Digilent_private.h"

/* Block parameters (auto storage) */
P_Control_Mov_PI_Digilent_T Control_Mov_PI_Digilent_P = {
  /* Mask Parameter: PIController_D
   * Referenced by: '<S4>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIController_I
   * Referenced by: '<S4>/Integral Gain'
   */
  0.01,

  /* Mask Parameter: PIController_P
   * Referenced by: '<S4>/Proportional Gain'
   */
  1.0,

  /* Computed Parameter: PCI6221ENC_P1_Size
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  { 1.0, 1.0 },

  /* Expression: device
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  21.0,

  /* Computed Parameter: PCI6221ENC_P2_Size
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  { 1.0, 1.0 },

  /* Expression: channel
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  1.0,

  /* Computed Parameter: PCI6221ENC_P3_Size
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  { 1.0, 1.0 },

  /* Expression: countMode
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  3.0,

  /* Computed Parameter: PCI6221ENC_P4_Size
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  { 1.0, 1.0 },

  /* Expression: initCount
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  0.0,

  /* Computed Parameter: PCI6221ENC_P5_Size
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  { 1.0, 1.0 },

  /* Expression: reload
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  0.0,

  /* Computed Parameter: PCI6221ENC_P6_Size
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  { 1.0, 1.0 },

  /* Expression: indexPhase
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  1.0,

  /* Computed Parameter: PCI6221ENC_P7_Size
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  { 1.0, 1.0 },

  /* Expression: filter
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  1.0,

  /* Computed Parameter: PCI6221ENC_P8_Size
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  { 1.0, 1.0 },

  /* Expression: outmask
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  0.0,

  /* Computed Parameter: PCI6221ENC_P9_Size
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  { 1.0, 1.0 },

  /* Expression: sampleTime
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  0.01,

  /* Computed Parameter: PCI6221ENC_P10_Size
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  { 1.0, 1.0 },

  /* Expression: slot
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Integrator'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<Root>/Constant1'
   */
  5.0,

  /* Computed Parameter: PCI6221DA_P1_Size
   * Referenced by: '<Root>/PCI-6221 DA'
   */
  { 1.0, 2.0 },

  /* Expression: channel
   * Referenced by: '<Root>/PCI-6221 DA'
   */
  { 1.0, 2.0 },

  /* Computed Parameter: PCI6221DA_P2_Size
   * Referenced by: '<Root>/PCI-6221 DA'
   */
  { 1.0, 2.0 },

  /* Expression: range
   * Referenced by: '<Root>/PCI-6221 DA'
   */
  { 0.0, 0.0 },

  /* Computed Parameter: PCI6221DA_P3_Size
   * Referenced by: '<Root>/PCI-6221 DA'
   */
  { 1.0, 2.0 },

  /* Expression: reset
   * Referenced by: '<Root>/PCI-6221 DA'
   */
  { 1.0, 1.0 },

  /* Computed Parameter: PCI6221DA_P4_Size
   * Referenced by: '<Root>/PCI-6221 DA'
   */
  { 1.0, 2.0 },

  /* Expression: initValue
   * Referenced by: '<Root>/PCI-6221 DA'
   */
  { 0.0, 0.0 },

  /* Computed Parameter: PCI6221DA_P5_Size
   * Referenced by: '<Root>/PCI-6221 DA'
   */
  { 1.0, 1.0 },

  /* Expression: sampletime
   * Referenced by: '<Root>/PCI-6221 DA'
   */
  0.01,

  /* Computed Parameter: PCI6221DA_P6_Size
   * Referenced by: '<Root>/PCI-6221 DA'
   */
  { 1.0, 1.0 },

  /* Expression: slot
   * Referenced by: '<Root>/PCI-6221 DA'
   */
  -1.0,

  /* Computed Parameter: PCI6221DA_P7_Size
   * Referenced by: '<Root>/PCI-6221 DA'
   */
  { 1.0, 1.0 },

  /* Expression: boardType
   * Referenced by: '<Root>/PCI-6221 DA'
   */
  21.0
};
