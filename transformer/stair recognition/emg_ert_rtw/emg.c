/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: emg.c
 *
 * Code generated for Simulink model 'emg'.
 *
 * Model version                  : 4.0
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed Sep 24 14:06:08 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "emg.h"
#include "emg_private.h"

/* Block signals (default storage) */
B_emg_T emg_B;

/* Block states (default storage) */
DW_emg_T emg_DW;

/* Real-time model */
static RT_MODEL_emg_T emg_M_;
RT_MODEL_emg_T *const emg_M = &emg_M_;

/* Model step function */
void emg_step(void)
{
  /* MATLABSystem: '<Root>/Analog Input1' */
  emg_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(18UL);

  /* MATLABSystem: '<Root>/Analog Input1' */
  MW_AnalogInSingle_ReadResult(emg_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
    &emg_B.AnalogInput1, MW_ANALOGIN_UINT16);

  /* MATLABSystem: '<Root>/Analog Input' */
  emg_DW.obj_i.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(19UL);

  /* MATLABSystem: '<Root>/Analog Input' */
  MW_AnalogInSingle_ReadResult(emg_DW.obj_i.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
    &emg_B.AnalogInput, MW_ANALOGIN_UINT16);

  /* MATLABSystem: '<Root>/Analog Input3' */
  emg_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(20UL);

  /* MATLABSystem: '<Root>/Analog Input3' */
  MW_AnalogInSingle_ReadResult(emg_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
    &emg_B.AnalogInput3, MW_ANALOGIN_UINT16);

  /* MATLABSystem: '<Root>/Analog Input2' */
  emg_DW.obj_o.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(21UL);

  /* MATLABSystem: '<Root>/Analog Input2' */
  MW_AnalogInSingle_ReadResult(emg_DW.obj_o.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
    &emg_B.AnalogInput2, MW_ANALOGIN_UINT16);

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  emg_M->Timing.taskTime0 =
    ((time_T)(++emg_M->Timing.clockTick0)) * emg_M->Timing.stepSize0;
}

/* Model initialize function */
void emg_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(emg_M, -1);
  emg_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  emg_M->Sizes.checksums[0] = (2710117859U);
  emg_M->Sizes.checksums[1] = (38821697U);
  emg_M->Sizes.checksums[2] = (151519491U);
  emg_M->Sizes.checksums[3] = (3214206466U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    emg_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(emg_M->extModeInfo,
      &emg_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(emg_M->extModeInfo, emg_M->Sizes.checksums);
    rteiSetTFinalTicks(emg_M->extModeInfo, -1);
  }

  /* Start for MATLABSystem: '<Root>/Analog Input1' */
  emg_DW.obj_n.matlabCodegenIsDeleted = false;
  emg_DW.obj_n.isInitialized = 1L;
  emg_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open
    (18UL);
  emg_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  emg_DW.obj_i.matlabCodegenIsDeleted = false;
  emg_DW.obj_i.isInitialized = 1L;
  emg_DW.obj_i.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open
    (19UL);
  emg_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input3' */
  emg_DW.obj.matlabCodegenIsDeleted = false;
  emg_DW.obj.isInitialized = 1L;
  emg_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(20UL);
  emg_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input2' */
  emg_DW.obj_o.matlabCodegenIsDeleted = false;
  emg_DW.obj_o.isInitialized = 1L;
  emg_DW.obj_o.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open
    (21UL);
  emg_DW.obj_o.isSetupComplete = true;
}

/* Model terminate function */
void emg_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  if (!emg_DW.obj_n.matlabCodegenIsDeleted) {
    emg_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((emg_DW.obj_n.isInitialized == 1L) && emg_DW.obj_n.isSetupComplete) {
      emg_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle
        (18UL);
      MW_AnalogIn_Close(emg_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input1' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!emg_DW.obj_i.matlabCodegenIsDeleted) {
    emg_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((emg_DW.obj_i.isInitialized == 1L) && emg_DW.obj_i.isSetupComplete) {
      emg_DW.obj_i.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle
        (19UL);
      MW_AnalogIn_Close(emg_DW.obj_i.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input3' */
  if (!emg_DW.obj.matlabCodegenIsDeleted) {
    emg_DW.obj.matlabCodegenIsDeleted = true;
    if ((emg_DW.obj.isInitialized == 1L) && emg_DW.obj.isSetupComplete) {
      emg_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle
        (20UL);
      MW_AnalogIn_Close(emg_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input3' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input2' */
  if (!emg_DW.obj_o.matlabCodegenIsDeleted) {
    emg_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((emg_DW.obj_o.isInitialized == 1L) && emg_DW.obj_o.isSetupComplete) {
      emg_DW.obj_o.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle
        (21UL);
      MW_AnalogIn_Close(emg_DW.obj_o.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
