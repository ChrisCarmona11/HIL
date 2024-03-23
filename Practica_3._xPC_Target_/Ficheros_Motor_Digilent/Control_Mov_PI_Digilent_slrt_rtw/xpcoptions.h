#ifndef __Control_Mov_PI_Digilent_XPCOPTIONS_H___
#define __Control_Mov_PI_Digilent_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "Control_Mov_PI_Digilent.h"
#define XPCMDSSUPPORT                  0
#define MDSTASKSNUM                    0
#define FULLMULTITHREAD                0
#define SIZEOF_PARAMS                  (-1 * (int)sizeof(P_Control_Mov_PI_Digilent_T))
#define SIMMODE                        0
#define LOGTET                         1
#define LOGBUFSIZE                     100000
#define PROFILINGFLAG                  1
#define EVENTNUMBER                    5000
#define IRQ_NO                         0
#define IO_IRQ                         0
#define WWW_ACCESS_LEVEL               0
#define CPUCLOCK                       0
#define MAXOVERLOAD                    0
#define MAXOVERLOADLEN                 0
#define XPCMODELSTACKSIZEKB            2048
#define XPCSTARTUPFLAG                 1
#define PTLOADPARAMFLAG                0
#define DOUBLEBUFFERING                0
#define SLRTFTZOFFFLAG                 0

/* Change all stepsize using the newBaseRateStepSize */
void Control_Mov_PI_Digilent_ChangeStepSize(real_T newBaseRateStepSize,
  RT_MODEL_Control_Mov_PI_Digilent_T *const Control_Mov_PI_Digilent_M)
{
  real_T ratio = newBaseRateStepSize / 0.01;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  Control_Mov_PI_Digilent_M->Timing.stepSize0 =
    Control_Mov_PI_Digilent_M->Timing.stepSize0 * ratio;
  Control_Mov_PI_Digilent_M->Timing.stepSize1 =
    Control_Mov_PI_Digilent_M->Timing.stepSize1 * ratio;
  Control_Mov_PI_Digilent_M->Timing.stepSize =
    Control_Mov_PI_Digilent_M->Timing.stepSize * ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  Control_Mov_PI_Digilent_ChangeStepSize(stepSize, Control_Mov_PI_Digilent_M);
}

void XPCCALLCONV SLRTSetErrorStatus(const char * errMsg)
{
  rtmSetErrorStatus(Control_Mov_PI_Digilent_M, errMsg);
}

#endif                                 /* __Control_Mov_PI_Digilent_XPCOPTIONS_H___ */
