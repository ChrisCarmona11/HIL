/*
 * Control_Mov_PI_Digilent_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Control_Mov_PI_Digilent".
 *
 * Model version              : 1.181
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Fri Feb 23 20:20:22 2024
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Control_Mov_PI_Digilent_private_h_
#define RTW_HEADER_Control_Mov_PI_Digilent_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

/* Used by FromWorkspace Block: '<S8>/FromWs' */
#ifndef rtInterpolate
# define rtInterpolate(v1,v2,f1,f2)    (((v1)==(v2))?((double)(v1)): (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif

#ifndef rtRound
# define rtRound(v)                    ( ((v) >= 0) ? floor((v) + 0.5) : ceil((v) - 0.5) )
#endif

extern const serialfifoptr serialfifoground;
extern const bcmsglist1553 bcmsg1553ground;
extern const bcstatus1553 bcstatground;
extern const bmmsglist1553 bmmsg1553ground;
extern const char *getRefMdlPath(const char *refMdl);
extern int getRefMdlSignalNumber(const char *mdlBlock, const char *signalName);
extern void encnipcim(SimStruct *rts);
extern void danipcim(SimStruct *rts);

/* private model entry point functions */
extern void Control_Mov_PI_Digilent_derivatives(void);

#endif                                 /* RTW_HEADER_Control_Mov_PI_Digilent_private_h_ */
