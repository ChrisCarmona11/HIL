/*
 * Control_Mov_PI_Digilent_capi.c
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

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "Control_Mov_PI_Digilent_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "Control_Mov_PI_Digilent.h"
#include "Control_Mov_PI_Digilent_capi.h"
#include "Control_Mov_PI_Digilent_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               (NULL)
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, TARGET_STRING("Constant1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 1, 0, TARGET_STRING("Encoder-Grados Reductora 1:53"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 2, 0, TARGET_STRING("PCI 6221 ENC "),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 3, 0, TARGET_STRING("Sum"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 4, 0, TARGET_STRING("PI Controller/Ideal Derivative"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 5, 0, TARGET_STRING("PI Controller/Derivative Gain"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 6, 0, TARGET_STRING("PI Controller/Integral Gain"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 7, 0, TARGET_STRING("PI Controller/Proportional Gain"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 8, 0, TARGET_STRING("PI Controller/Integrator"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 9, 0, TARGET_STRING("PI Controller/Sum"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 10, 0, TARGET_STRING("Trayectoria Posicion/FromWs"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 11, TARGET_STRING("PI Controller"),
    TARGET_STRING("P"), 0, 0, 0 },

  { 12, TARGET_STRING("PI Controller"),
    TARGET_STRING("I"), 0, 0, 0 },

  { 13, TARGET_STRING("PI Controller"),
    TARGET_STRING("D"), 0, 0, 0 },

  { 14, TARGET_STRING("Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 15, TARGET_STRING("PCI 6221 ENC "),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 16, TARGET_STRING("PCI 6221 ENC "),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 17, TARGET_STRING("PCI 6221 ENC "),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 18, TARGET_STRING("PCI 6221 ENC "),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 19, TARGET_STRING("PCI 6221 ENC "),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 20, TARGET_STRING("PCI 6221 ENC "),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 21, TARGET_STRING("PCI 6221 ENC "),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 22, TARGET_STRING("PCI 6221 ENC "),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 23, TARGET_STRING("PCI 6221 ENC "),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 24, TARGET_STRING("PCI 6221 ENC "),
    TARGET_STRING("P10"), 0, 0, 0 },

  { 25, TARGET_STRING("PCI-6221 DA"),
    TARGET_STRING("P1"), 0, 1, 0 },

  { 26, TARGET_STRING("PCI-6221 DA"),
    TARGET_STRING("P2"), 0, 1, 0 },

  { 27, TARGET_STRING("PCI-6221 DA"),
    TARGET_STRING("P3"), 0, 1, 0 },

  { 28, TARGET_STRING("PCI-6221 DA"),
    TARGET_STRING("P4"), 0, 1, 0 },

  { 29, TARGET_STRING("PCI-6221 DA"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 30, TARGET_STRING("PCI-6221 DA"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 31, TARGET_STRING("PCI-6221 DA"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 32, TARGET_STRING("PI Controller/Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

/* Tunable variable parameters */
static const rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 0, (NULL), 0, 0, 0 }
};

#ifndef HOST_CAPI_BUILD

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &Control_Mov_PI_Digilent_B.Constant1,/* 0: Signal */
  &Control_Mov_PI_Digilent_B.EncoderGradosReductora153,/* 1: Signal */
  &Control_Mov_PI_Digilent_B.PCI6221ENC,/* 2: Signal */
  &Control_Mov_PI_Digilent_B.Sum,      /* 3: Signal */
  &Control_Mov_PI_Digilent_B.IdealDerivative,/* 4: Signal */
  &Control_Mov_PI_Digilent_B.DerivativeGain,/* 5: Signal */
  &Control_Mov_PI_Digilent_B.IntegralGain,/* 6: Signal */
  &Control_Mov_PI_Digilent_B.ProportionalGain,/* 7: Signal */
  &Control_Mov_PI_Digilent_B.Integrator,/* 8: Signal */
  &Control_Mov_PI_Digilent_B.Sum_i,    /* 9: Signal */
  &Control_Mov_PI_Digilent_B.FromWs,   /* 10: Signal */
  &Control_Mov_PI_Digilent_P.PIController_P,/* 11: Mask Parameter */
  &Control_Mov_PI_Digilent_P.PIController_I,/* 12: Mask Parameter */
  &Control_Mov_PI_Digilent_P.PIController_D,/* 13: Mask Parameter */
  &Control_Mov_PI_Digilent_P.Constant1_Value,/* 14: Block Parameter */
  &Control_Mov_PI_Digilent_P.PCI6221ENC_P1,/* 15: Block Parameter */
  &Control_Mov_PI_Digilent_P.PCI6221ENC_P2,/* 16: Block Parameter */
  &Control_Mov_PI_Digilent_P.PCI6221ENC_P3,/* 17: Block Parameter */
  &Control_Mov_PI_Digilent_P.PCI6221ENC_P4,/* 18: Block Parameter */
  &Control_Mov_PI_Digilent_P.PCI6221ENC_P5,/* 19: Block Parameter */
  &Control_Mov_PI_Digilent_P.PCI6221ENC_P6,/* 20: Block Parameter */
  &Control_Mov_PI_Digilent_P.PCI6221ENC_P7,/* 21: Block Parameter */
  &Control_Mov_PI_Digilent_P.PCI6221ENC_P8,/* 22: Block Parameter */
  &Control_Mov_PI_Digilent_P.PCI6221ENC_P9,/* 23: Block Parameter */
  &Control_Mov_PI_Digilent_P.PCI6221ENC_P10,/* 24: Block Parameter */
  &Control_Mov_PI_Digilent_P.PCI6221DA_P1[0],/* 25: Block Parameter */
  &Control_Mov_PI_Digilent_P.PCI6221DA_P2[0],/* 26: Block Parameter */
  &Control_Mov_PI_Digilent_P.PCI6221DA_P3[0],/* 27: Block Parameter */
  &Control_Mov_PI_Digilent_P.PCI6221DA_P4[0],/* 28: Block Parameter */
  &Control_Mov_PI_Digilent_P.PCI6221DA_P5,/* 29: Block Parameter */
  &Control_Mov_PI_Digilent_P.PCI6221DA_P6,/* 30: Block Parameter */
  &Control_Mov_PI_Digilent_P.PCI6221DA_P7,/* 31: Block Parameter */
  &Control_Mov_PI_Digilent_P.Integrator_IC,/* 32: Block Parameter */
};

/* Declare Data Run-Time Dimension Buffer Addresses statically */
static int32_T* rtVarDimsAddrMap[] = {
  (NULL)
};

#endif

/* Data Type Map - use dataTypeMapIndex to access this structure */
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

/* Structure Element Map - use elemMapIndex to access this structure */
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { (NULL), 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static const rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_SCALAR, 0, 2, 0 },

  { rtwCAPI_VECTOR, 2, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  1,                                   /* 2 */
  2                                    /* 3 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.01, 0.0
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[1],
    1, 0 },

  { (const void *) &rtcapiStoredFloats[1], (const void *) &rtcapiStoredFloats[1],
    0, 0 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals,
   *           rootInputs, numRootInputs,
   *           rootOutputs, numRootOutputs},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { rtBlockSignals, 11,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 22,
    rtModelParameters, 0 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 846770372U,
    115146702U,
    3153434364U,
    755183199U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  Control_Mov_PI_Digilent_GetCAPIStaticMap(void)
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void Control_Mov_PI_Digilent_InitializeDataMapInfo(void)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(Control_Mov_PI_Digilent_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(Control_Mov_PI_Digilent_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(Control_Mov_PI_Digilent_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(Control_Mov_PI_Digilent_M->DataMapInfo.mmi,
    rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(Control_Mov_PI_Digilent_M->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache C-API rtp Address and size  into the Real-Time Model Data structure */
  Control_Mov_PI_Digilent_M->DataMapInfo.mmi.InstanceMap.rtpAddress =
    rtmGetDefaultParam(Control_Mov_PI_Digilent_M);
  Control_Mov_PI_Digilent_M->DataMapInfo.mmi.staticMap->rtpSize = sizeof
    (P_Control_Mov_PI_Digilent_T);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(Control_Mov_PI_Digilent_M->DataMapInfo.mmi,
    (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(Control_Mov_PI_Digilent_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(Control_Mov_PI_Digilent_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void Control_Mov_PI_Digilent_host_InitializeDataMapInfo
    (Control_Mov_PI_Digilent_host_DataMapInfo_T *dataMap, const char *path)
  {
    /* Set C-API version */
    rtwCAPI_SetVersion(dataMap->mmi, 1);

    /* Cache static C-API data into the Real-time Model Data structure */
    rtwCAPI_SetStaticMap(dataMap->mmi, &mmiStatic);

    /* host data address map is NULL */
    rtwCAPI_SetDataAddressMap(dataMap->mmi, NULL);

    /* host vardims address map is NULL */
    rtwCAPI_SetVarDimsAddressMap(dataMap->mmi, NULL);

    /* Set Instance specific path */
    rtwCAPI_SetPath(dataMap->mmi, path);
    rtwCAPI_SetFullPath(dataMap->mmi, NULL);

    /* Set reference to submodels */
    rtwCAPI_SetChildMMIArray(dataMap->mmi, (NULL));
    rtwCAPI_SetChildMMIArrayLen(dataMap->mmi, 0);
  }

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* EOF: Control_Mov_PI_Digilent_capi.c */
