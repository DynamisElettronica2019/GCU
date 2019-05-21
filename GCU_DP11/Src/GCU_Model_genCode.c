/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GCU_Model_genCode.c
 *
 * Code generated for Simulink model 'GCU_Model_genCode'.
 *
 * Model version                  : 1.173
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Tue May 21 18:47:07 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "GCU_Model_genCode.h"
#include "GCU_Model_genCode_private.h"

/* Named constants for Chart: '<S4>/MessageEvaluation1' */
#define ACC_CLUTCH_NOISE_LEVEL         ((uint8_T)30U)
#define GEAR_COMMAND_DOWN              ((uint16_T)200U)
#define GEAR_COMMAND_NEUTRAL_DOWN      ((uint16_T)100U)
#define GEAR_COMMAND_NEUTRAL_UP        ((uint16_T)50U)
#define STOP_COM                       ((uint16_T)0U)

/* Named constants for Chart: '<S5>/GCULogic' */
#define AAC_WORK_RATE_ms               ((uint16_T)25U)
#define GEAR_COMMAND_UP                ((uint16_T)400U)
#define IN_ACC                         ((uint8_T)1U)
#define IN_ACCELERATION                ((uint8_T)1U)
#define IN_ACTIVE                      ((uint8_T)1U)
#define IN_ChangeClutch                ((uint8_T)1U)
#define IN_CutOff                      ((uint8_T)1U)
#define IN_DOWNSHIFTING                ((uint8_T)1U)
#define IN_DOWN_BRAKE                  ((uint8_T)1U)
#define IN_DOWN_END                    ((uint8_T)2U)
#define IN_DOWN_PUSH                   ((uint8_T)2U)
#define IN_DOWN_REBOUND                ((uint8_T)3U)
#define IN_DOWN_START                  ((uint8_T)4U)
#define IN_Default                     ((uint8_T)1U)
#define IN_Default_c                   ((uint8_T)2U)
#define IN_IDLE                        ((uint8_T)3U)
#define IN_INIT                        ((uint8_T)2U)
#define IN_INIT_j                      ((uint8_T)4U)
#define IN_MANUAL_MODES                ((uint8_T)3U)
#define IN_NEUTRAL                     ((uint8_T)1U)
#define IN_NO_NEUTRAL                  ((uint8_T)2U)
#define IN_NotReady                    ((uint8_T)2U)
#define IN_READY                       ((uint8_T)1U)
#define IN_RELEASING                   ((uint8_T)2U)
#define IN_RUNNING                     ((uint8_T)3U)
#define IN_SCAN                        ((uint8_T)1U)
#define IN_SET_NEUTRAL                 ((uint8_T)3U)
#define IN_START                       ((uint8_T)4U)
#define IN_START_RELEASE               ((uint8_T)5U)
#define IN_START_b                     ((uint8_T)1U)
#define IN_STOP                        ((uint8_T)2U)
#define IN_STOPPING                    ((uint8_T)2U)
#define IN_SettingNeutral              ((uint8_T)2U)
#define IN_SettingNeutral_n            ((uint8_T)3U)
#define IN_UNSET_NEUTRAL               ((uint8_T)4U)
#define IN_UPSHIFTING                  ((uint8_T)5U)
#define IN_UP_BRAKE                    ((uint8_T)1U)
#define IN_UP_END                      ((uint8_T)6U)
#define IN_UP_PUSH                     ((uint8_T)2U)
#define IN_UP_REBOUND                  ((uint8_T)3U)
#define IN_UP_START                    ((uint8_T)4U)
#define IN_WAIT                        ((uint8_T)3U)
#define IN_WAIT_m                      ((uint8_T)2U)
#define event_GearshiftDown            (0)
#define event_GearshiftSetNeutral      (1)
#define event_GearshiftUp              (2)

/* Named constants for Chart: '<S7>/AccelerationRoutine' */
#define IN_ActivateAac                 ((uint8_T)1U)
#define IN_CHANGE_MODE                 ((uint8_T)2U)
#define IN_DajeDeGas                   ((uint8_T)3U)
#define IN_EXIT                        ((uint8_T)4U)
#define IN_EnterAcceleration           ((uint8_T)5U)
#define IN_InsertGear                  ((uint8_T)6U)
#define IN_Ready                       ((uint8_T)7U)
#define IN_TPS_On                      ((uint8_T)8U)
#define IN_Wait                        ((uint8_T)9U)
#define IN_delay                       ((uint8_T)10U)

const uint16_T GCU_Model_genCode_U16GND = 0U;/* uint16_T ground */

/* Block signals and states (default storage) */
DW rtDW;

/* Previous zero-crossings (trigger) states */
PrevZCX rtPrevZCX;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Forward declaration for local functions */
static void NEUTRAL_STATE(void);
static int32_T Gearshift_getTime(void);
static void Clutch_setValue(uint8_T setValue);
static void GEARSHIFT(void);
static void checkShift(void);
static int32_T getAacParam(acc_params b_index);
static void aacCheckShift(void);
static void checkClutch(void);
static void enter_atomic_MANUAL_MODES(void);
static void ACCELERATION(void);
static void MODES(void);
static void updateOutput(void);
static void updateData(void);
static void checkGear(void);
static void sendAccCommand(uint16_T com);
static void sendClutchCommand(uint16_T com);
static void sendModeCommand(uint16_T com);
static void sendShiftCommand(uint16_T com);
static void sendStartEngCommand(void);
static void updateBuffer(const eepromRequest *BusConversion_InsertedFor_EEPRO);
uint16_T look1_iu16lu64n48_binlcse(uint16_T u0, const uint16_T bp0[], const
  uint16_T table[], uint32_T maxIndex)
{
  uint16_T y;
  uint64_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0ULL;
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = ((uint64_T)(uint16_T)((uint32_T)u0 - bp0[iLeft]) << 48) / (uint16_T)
      ((uint32_T)bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = 281474976710656ULL;
  }

  /* Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  if (table[iLeft + 1U] >= table[iLeft]) {
    y = (uint16_T)((uint32_T)(uint16_T)(((uint16_T)((uint32_T)table[iLeft + 1U]
      - table[iLeft]) * frac) >> 48) + table[iLeft]);
  } else {
    y = (uint16_T)((uint32_T)table[iLeft] - (uint16_T)(((uint16_T)((uint32_T)
      table[iLeft] - table[iLeft + 1U]) * frac) >> 48));
  }

  return y;
}

/*
 * Output and update for function-call system:
 *    '<S30>/Efi_setRpmLimiter'
 *    '<S35>/SetRPMLimiter'
 */
void Efi_setRpmLimiter(uint8_T *rty_rpmLimiter_pin, DW_Efi_setRpmLimiter
  *localDW)
{
  /* S-Function (Efi_setRPMLimiter): '<S32>/Efi SetRPMLimiter' */
  Efi_setRPMLimiter_Outputs_wrapper(&localDW->EfiSetRPMLimiter);

  /* SignalConversion: '<S32>/OutportBufferForrpmLimiter_pin' */
  *rty_rpmLimiter_pin = localDW->EfiSetRPMLimiter;
}

/*
 * Output and update for function-call system:
 *    '<S30>/Efi_unsetRpmLimiter'
 *    '<S35>/UnsetRPMLimiter'
 */
void Efi_unsetRpmLimiter(uint8_T *rty_rpmLimiter_pin, DW_Efi_unsetRpmLimiter
  *localDW)
{
  /* S-Function (Efi_unsetRPMLimiter): '<S33>/Efi UnSetRPMLimiter' */
  Efi_unsetRPMLimiter_Outputs_wrapper(&localDW->EfiUnSetRPMLimiter);

  /* SignalConversion: '<S33>/OutportBufferForrpmLimiter_pin' */
  *rty_rpmLimiter_pin = localDW->EfiUnSetRPMLimiter;
}

/* Output and update for function-call system: '<S4>/AAC_ExternalValues' */
void AAC_ExternalValues(uint16_T rtu_Value, uint16_T rtu_Index, uint16_T
  rty_Values[3], DW_AAC_ExternalValues *localDW)
{
  /* Assignment: '<S29>/Assignment' incorporates:
   *  UnitDelay: '<S29>/Unit Delay'
   */
  rty_Values[0] = localDW->UnitDelay_DSTATE[0];
  rty_Values[1] = localDW->UnitDelay_DSTATE[1];
  rty_Values[2] = localDW->UnitDelay_DSTATE[2];
  rty_Values[rtu_Index] = rtu_Value;

  /* Update for UnitDelay: '<S29>/Unit Delay' */
  localDW->UnitDelay_DSTATE[0] = rty_Values[0];
  localDW->UnitDelay_DSTATE[1] = rty_Values[1];
  localDW->UnitDelay_DSTATE[2] = rty_Values[2];
}

/* Output and update for function-call system: '<S38>/Gearmotor_release' */
void Gearmotor_release(void)
{
  /* S-Function (GearMotor_release): '<S49>/GearMotor Release' */
  GearMotor_release_Outputs_wrapper(&rtDW.GearMotorRelease);

  /* SignalConversion: '<S49>/OutportBufferForPin H' */
  rtDW.Pin_H = rtDW.GearMotorRelease;
}

/* Output and update for function-call system: '<S38>/Gearmotor_turnRight' */
void Gearmotor_turnRight(uint8_T *rty_Pin_In1, uint8_T *rty_Pin_In2, uint8_T
  *rty_Pin_H, DW_Gearmotor_turnRight *localDW)
{
  /* S-Function (GearMotor_turnRight): '<S51>/GearMotor Turn Right' */
  GearMotor_turnRight_Outputs_wrapper(&localDW->GearMotorTurnRight_o1,
    &localDW->GearMotorTurnRight_o2, &localDW->GearMotorTurnRight_o3);

  /* SignalConversion: '<S51>/OutportBufferForPin_H' */
  *rty_Pin_H = localDW->GearMotorTurnRight_o3;

  /* SignalConversion: '<S51>/OutportBufferForPin_In1' */
  *rty_Pin_In1 = localDW->GearMotorTurnRight_o1;

  /* SignalConversion: '<S51>/OutportBufferForPin_In2' */
  *rty_Pin_In2 = localDW->GearMotorTurnRight_o2;
}

/* Output and update for function-call system: '<S38>/Gearmotor_brake' */
void Gearmotor_brake(uint8_T *rty_Pin_In1, uint8_T *rty_Pin_In2, uint8_T
                     *rty_Pin_H, DW_Gearmotor_brake *localDW)
{
  /* S-Function (GearMotor_brake): '<S48>/GearMotor Brake' */
  GearMotor_brake_Outputs_wrapper(&localDW->GearMotorBrake_o1,
    &localDW->GearMotorBrake_o2, &localDW->GearMotorBrake_o3);

  /* SignalConversion: '<S48>/OutportBufferForPin_H' */
  *rty_Pin_H = localDW->GearMotorBrake_o3;

  /* SignalConversion: '<S48>/OutportBufferForPin_In1' */
  *rty_Pin_In1 = localDW->GearMotorBrake_o1;

  /* SignalConversion: '<S48>/OutportBufferForPin_In2' */
  *rty_Pin_In2 = localDW->GearMotorBrake_o2;
}

/* Output and update for function-call system: '<S36>/EngineControl_Start' */
void EngineControl_Start(uint8_T *rty_engine_starter, DW_EngineControl_Start
  *localDW)
{
  /* S-Function (EngineControl_start): '<S45>/EngineControl Start' */
  EngineControl_start_Outputs_wrapper(&localDW->EngineControlStart);

  /* SignalConversion: '<S45>/OutportBufferForengine_starter' */
  *rty_engine_starter = localDW->EngineControlStart;
}

/* Output and update for function-call system: '<S37>/SCAN_ADC.ScanADC' */
void SCAN_ADCScanADC(void)
{
  /* S-Function (ScanADC): '<S47>/ScanADC' */
  ScanADC_Outputs_wrapper();
}

/* Function for Chart: '<S5>/GCULogic' */
static void NEUTRAL_STATE(void)
{
  switch (rtDW.is_NEUTRAL_STATE) {
   case IN_NEUTRAL:
    if ((rtDW.sfEvent == event_GearshiftUp) || (rtDW.sfEvent ==
         event_GearshiftDown)) {
      rtDW.is_NEUTRAL_STATE = IN_UNSET_NEUTRAL;
    }
    break;

   case IN_NO_NEUTRAL:
    if (rtDW.sfEvent == event_GearshiftSetNeutral) {
      rtDW.is_NEUTRAL_STATE = IN_SET_NEUTRAL;
    }
    break;

   case IN_SET_NEUTRAL:
    if ((rtDW.is_GEARSHIFT == IN_DOWN_END) || (rtDW.is_GEARSHIFT == IN_UP_END))
    {
      rtDW.is_NEUTRAL_STATE = IN_NEUTRAL;
    }
    break;

   case IN_UNSET_NEUTRAL:
    if ((rtDW.is_GEARSHIFT == IN_DOWN_END) || (rtDW.is_GEARSHIFT == IN_UP_END))
    {
      rtDW.is_NEUTRAL_STATE = IN_NO_NEUTRAL;
    }
    break;
  }
}

/* Function for Chart: '<S5>/GCULogic' */
static int32_T Gearshift_getTime(void)
{
  int32_T time;
  if (rtDW.is_UPSHIFTING == IN_UP_START) {
    if (rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL) {
      time = rtDW.Merge_m[(int32_T)DEFAULT_NT_CLUTCH_DELAY];
    } else {
      time = rtDW.Merge_m[(int32_T)DELAY];
    }
  } else if (rtDW.is_UPSHIFTING == IN_UP_PUSH) {
    if (rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL) {
      time = rtDW.Merge_m[(int32_T)NT_CLUTCH_DELAY];
    } else {
      switch (rtDW.RateTransition) {
       case 1:
        time = rtDW.Merge_m[(int32_T)UP_PUSH_1_2];
        break;

       case 2:
        time = rtDW.Merge_m[(int32_T)UP_PUSH_2_3];
        break;

       case 3:
        time = rtDW.Merge_m[(int32_T)UP_PUSH_3_4];
        break;

       case 4:
        time = rtDW.Merge_m[(int32_T)UP_PUSH_4_5];
        break;

       default:
        time = rtDW.Merge_m[(int32_T)UP_PUSH_2_3];
        break;
      }
    }
  } else if (rtDW.is_UPSHIFTING == IN_UP_REBOUND) {
    if (rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL) {
      time = rtDW.Merge_m[(int32_T)NT_REBOUND_1_N];
    } else {
      time = rtDW.Merge_m[(int32_T)UP_REBOUND];
    }
  } else if (rtDW.is_UPSHIFTING == IN_UP_BRAKE) {
    if (rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL) {
      time = rtDW.Merge_m[(int32_T)NT_BRAKE_1_N];
    } else {
      time = rtDW.Merge_m[(int32_T)UP_BRAKE];
    }
  } else if (rtDW.is_DOWNSHIFTING == IN_DOWN_START) {
    time = rtDW.Merge_m[(int32_T)CLUTCH];
  } else if (rtDW.is_DOWNSHIFTING == IN_DOWN_PUSH) {
    time = rtDW.Merge_m[(int32_T)DN_PUSH];
  } else if (rtDW.is_DOWNSHIFTING == IN_DOWN_REBOUND) {
    time = rtDW.Merge_m[(int32_T)DN_REBOUND];
  } else {
    time = rtDW.Merge_m[(int32_T)DN_BRAKE];
  }

  return time;
}

/* Function for Chart: '<S5>/GCULogic' */
static void Clutch_setValue(uint8_T setValue)
{
  uint8_T tmp;
  rtDW.clutchCurrVal = setValue;

  /* Outputs for Function Call SubSystem: '<S34>/ClutchMotor SetPosition ' */
  /* Saturate: '<S39>/Saturation' */
  if (rtDW.clutchCurrVal < 100) {
    tmp = rtDW.clutchCurrVal;
  } else {
    tmp = 100U;
  }

  /* End of Saturate: '<S39>/Saturation' */

  /* Sum: '<S39>/Minus' incorporates:
   *  Constant: '<S39>/Constant'
   */
  rtDW.Minus = (uint8_T)(100 - tmp);

  /* S-Function (ClutchMotor_setPosition): '<S39>/ClutchMotor SetPosition' */
  ClutchMotor_setPosition_Outputs_wrapper(&rtDW.Minus);

  /* End of Outputs for SubSystem: '<S34>/ClutchMotor SetPosition ' */
}

/* Function for Chart: '<S5>/GCULogic' */
static void GEARSHIFT(void)
{
  switch (rtDW.is_GEARSHIFT) {
   case IN_DOWNSHIFTING:
    switch (rtDW.is_DOWNSHIFTING) {
     case IN_DOWN_BRAKE:
      if (rtDW.ticksCounter == 1) {
        rtDW.is_DOWN_BRAKE = 0;
        rtDW.is_DOWNSHIFTING = 0;
        rtDW.is_GEARSHIFT = 0;
        if (rtDW.is_GEARSHIFT != IN_DOWN_END) {
          rtDW.is_GEARSHIFT = IN_DOWN_END;

          /* Outputs for Function Call SubSystem: '<S38>/Gearmotor_release' */
          Gearmotor_release();

          /* End of Outputs for SubSystem: '<S38>/Gearmotor_release' */
        }
      } else if (rtDW.ticksCounter < -2147483647) {
        rtDW.ticksCounter = MIN_int32_T;
      } else {
        rtDW.ticksCounter--;
      }
      break;

     case IN_DOWN_PUSH:
      if (rtDW.ticksCounter == 1) {
        rtDW.is_DOWNSHIFTING = 0;
        if (rtDW.is_DOWNSHIFTING != IN_DOWN_REBOUND) {
          rtDW.is_DOWNSHIFTING = IN_DOWN_REBOUND;
          rtDW.ticksCounter = Gearshift_getTime();

          /* Outputs for Function Call SubSystem: '<S38>/Gearmotor_release' */
          Gearmotor_release();

          /* End of Outputs for SubSystem: '<S38>/Gearmotor_release' */
        }
      } else if (rtDW.ticksCounter < -2147483647) {
        rtDW.ticksCounter = MIN_int32_T;
      } else {
        rtDW.ticksCounter--;
      }
      break;

     case IN_DOWN_REBOUND:
      if (rtDW.ticksCounter == 1) {
        rtDW.is_DOWNSHIFTING = 0;
        if (rtDW.is_DOWNSHIFTING != IN_DOWN_BRAKE) {
          rtDW.is_DOWNSHIFTING = IN_DOWN_BRAKE;
          rtDW.ticksCounter = Gearshift_getTime();
        }

        if (rtDW.clutchCurrVal < 81) {
          if (rtDW.is_DOWN_BRAKE != IN_ChangeClutch) {
            rtDW.is_DOWN_BRAKE = IN_ChangeClutch;
            Clutch_setValue(80);

            /* Outputs for Function Call SubSystem: '<S38>/Gearmotor_brake' */
            Gearmotor_brake(&rtDW.Pin_In1, &rtDW.Pin_In2, &rtDW.Pin_H,
                            &rtDW.Gearmotor_brake_c);

            /* End of Outputs for SubSystem: '<S38>/Gearmotor_brake' */
          }
        } else {
          if (rtDW.is_DOWN_BRAKE != IN_Default_c) {
            rtDW.is_DOWN_BRAKE = IN_Default_c;

            /* Outputs for Function Call SubSystem: '<S38>/Gearmotor_brake' */
            Gearmotor_brake(&rtDW.Pin_In1, &rtDW.Pin_In2, &rtDW.Pin_H,
                            &rtDW.Gearmotor_brake_c);

            /* End of Outputs for SubSystem: '<S38>/Gearmotor_brake' */
          }
        }
      } else if (rtDW.ticksCounter < -2147483647) {
        rtDW.ticksCounter = MIN_int32_T;
      } else {
        rtDW.ticksCounter--;
      }
      break;

     case IN_DOWN_START:
      if (rtDW.ticksCounter == 1) {
        rtDW.is_DOWN_START = 0;
        rtDW.is_DOWNSHIFTING = 0;
        if (rtDW.is_DOWNSHIFTING != IN_DOWN_PUSH) {
          rtDW.is_DOWNSHIFTING = IN_DOWN_PUSH;
          rtDW.ticksCounter = Gearshift_getTime();

          /* Outputs for Function Call SubSystem: '<S38>/Gearmotor_turnLeft' */
          /* S-Function (GearMotor_turnLeft): '<S50>/GearMotor Turn Left' */
          GearMotor_turnLeft_Outputs_wrapper(&rtDW.GearMotorTurnLeft_o1,
            &rtDW.GearMotorTurnLeft_o2, &rtDW.GearMotorTurnLeft_o3);

          /* SignalConversion: '<S50>/OutportBufferForPin_H' */
          rtDW.Pin_H = rtDW.GearMotorTurnLeft_o3;

          /* SignalConversion: '<S50>/OutportBufferForPin_In1' */
          rtDW.Pin_In1 = rtDW.GearMotorTurnLeft_o1;

          /* SignalConversion: '<S50>/OutportBufferForPin_In2' */
          rtDW.Pin_In2 = rtDW.GearMotorTurnLeft_o2;

          /* End of Outputs for SubSystem: '<S38>/Gearmotor_turnLeft' */
        }
      } else if (rtDW.ticksCounter < -2147483647) {
        rtDW.ticksCounter = MIN_int32_T;
      } else {
        rtDW.ticksCounter--;
      }
      break;
    }
    break;

   case IN_DOWN_END:
    rtDW.is_GEARSHIFT = IN_IDLE;
    break;

   case IN_IDLE:
    if ((rtDW.sfEvent == event_GearshiftUp) && (rtDW.RateTransition < 5)) {
      rtDW.is_GEARSHIFT = IN_UPSHIFTING;
      if (rtDW.is_UPSHIFTING != IN_UP_START) {
        rtDW.is_UPSHIFTING = IN_UP_START;
        rtDW.ticksCounter = Gearshift_getTime();
      }

      if (rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL) {
        if (rtDW.is_UP_START != IN_SettingNeutral) {
          rtDW.is_UP_START = IN_SettingNeutral;
          Clutch_setValue(80);
        }
      } else {
        if (rtDW.is_UP_START != IN_Default) {
          rtDW.is_UP_START = IN_Default;

          /* Outputs for Function Call SubSystem: '<S35>/SetCut' */

          /* S-Function (Efi_setCut): '<S41>/Efi SetCut' */
          Efi_setCut_Outputs_wrapper(&rtDW.EfiSetCut);

          /* End of Outputs for SubSystem: '<S35>/SetCut' */
        }
      }
    } else {
      if (rtDW.sfEvent == event_GearshiftDown) {
        rtDW.is_GEARSHIFT = IN_DOWNSHIFTING;
        if (rtDW.is_DOWNSHIFTING != IN_DOWN_START) {
          rtDW.is_DOWNSHIFTING = IN_DOWN_START;
          rtDW.ticksCounter = Gearshift_getTime();
        }

        if ((rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL) && (rtDW.clutchCurrVal <=
             80)) {
          if (rtDW.is_DOWN_START != IN_SettingNeutral_n) {
            rtDW.is_DOWN_START = IN_SettingNeutral_n;
            Clutch_setValue(80);
          }
        } else if ((!(rtDW.is_NEUTRAL_STATE == IN_UNSET_NEUTRAL)) &&
                   (rtDW.clutchCurrVal <= 60)) {
          if (rtDW.is_DOWN_START != IN_ChangeClutch) {
            rtDW.is_DOWN_START = IN_ChangeClutch;
            Clutch_setValue(60);
          }
        } else {
          rtDW.is_DOWN_START = IN_Default_c;
        }
      }
    }
    break;

   case IN_INIT_j:
    rtDW.is_GEARSHIFT = IN_IDLE;
    break;

   case IN_UPSHIFTING:
    switch (rtDW.is_UPSHIFTING) {
     case IN_UP_BRAKE:
      if (rtDW.ticksCounter == 1) {
        rtDW.is_UPSHIFTING = 0;
        rtDW.is_GEARSHIFT = 0;
        if (rtDW.is_GEARSHIFT != IN_UP_END) {
          rtDW.is_GEARSHIFT = IN_UP_END;

          /* Outputs for Function Call SubSystem: '<S38>/Gearmotor_release' */
          Gearmotor_release();

          /* End of Outputs for SubSystem: '<S38>/Gearmotor_release' */
        }
      } else if (rtDW.ticksCounter < -2147483647) {
        rtDW.ticksCounter = MIN_int32_T;
      } else {
        rtDW.ticksCounter--;
      }
      break;

     case IN_UP_PUSH:
      if (rtDW.ticksCounter == 1) {
        rtDW.is_UP_PUSH = 0;
        rtDW.is_UPSHIFTING = 0;
        if (rtDW.is_UPSHIFTING != IN_UP_REBOUND) {
          rtDW.is_UPSHIFTING = IN_UP_REBOUND;
          rtDW.ticksCounter = Gearshift_getTime();
        }

        if (rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL) {
          if (rtDW.is_UP_REBOUND != IN_SettingNeutral) {
            rtDW.is_UP_REBOUND = IN_SettingNeutral;
            Clutch_setValue(0);

            /* Outputs for Function Call SubSystem: '<S38>/Gearmotor_release' */
            Gearmotor_release();

            /* End of Outputs for SubSystem: '<S38>/Gearmotor_release' */
          }
        } else {
          if (rtDW.is_UP_REBOUND != IN_Default) {
            rtDW.is_UP_REBOUND = IN_Default;

            /* Outputs for Function Call SubSystem: '<S38>/Gearmotor_release' */
            Gearmotor_release();

            /* End of Outputs for SubSystem: '<S38>/Gearmotor_release' */
          }
        }
      } else if (rtDW.ticksCounter < -2147483647) {
        rtDW.ticksCounter = MIN_int32_T;
      } else {
        rtDW.ticksCounter--;
      }
      break;

     case IN_UP_REBOUND:
      if (rtDW.ticksCounter == 1) {
        rtDW.is_UP_REBOUND = 0;
        rtDW.is_UPSHIFTING = 0;
        if (rtDW.is_UPSHIFTING != IN_UP_BRAKE) {
          rtDW.is_UPSHIFTING = IN_UP_BRAKE;
          rtDW.ticksCounter = Gearshift_getTime();

          /* Outputs for Function Call SubSystem: '<S38>/Gearmotor_brake' */
          Gearmotor_brake(&rtDW.Pin_In1, &rtDW.Pin_In2, &rtDW.Pin_H,
                          &rtDW.Gearmotor_brake_c);

          /* End of Outputs for SubSystem: '<S38>/Gearmotor_brake' */
        }
      } else if (rtDW.ticksCounter < -2147483647) {
        rtDW.ticksCounter = MIN_int32_T;
      } else {
        rtDW.ticksCounter--;
      }
      break;

     case IN_UP_START:
      if (rtDW.ticksCounter == 1) {
        rtDW.is_UP_START = 0;
        rtDW.is_UPSHIFTING = 0;
        if (rtDW.is_UPSHIFTING != IN_UP_PUSH) {
          rtDW.is_UPSHIFTING = IN_UP_PUSH;
          rtDW.ticksCounter = Gearshift_getTime();
        }

        if (!(rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL)) {
          if (rtDW.is_UP_PUSH != IN_CutOff) {
            rtDW.is_UP_PUSH = IN_CutOff;

            /* Outputs for Function Call SubSystem: '<S35>/UnsetCut' */

            /* S-Function (Efi_unsetCut): '<S43>/Efi UnSetCut' */
            Efi_unsetCut_Outputs_wrapper(&rtDW.EfiUnSetCut);

            /* End of Outputs for SubSystem: '<S35>/UnsetCut' */

            /* Outputs for Function Call SubSystem: '<S38>/Gearmotor_turnRight' */
            Gearmotor_turnRight(&rtDW.Pin_In1, &rtDW.Pin_In2, &rtDW.Pin_H,
                                &rtDW.Gearmotor_turnRight_f);

            /* End of Outputs for SubSystem: '<S38>/Gearmotor_turnRight' */
          }
        } else {
          if (rtDW.is_UP_PUSH != IN_Default_c) {
            rtDW.is_UP_PUSH = IN_Default_c;

            /* Outputs for Function Call SubSystem: '<S38>/Gearmotor_turnRight' */
            Gearmotor_turnRight(&rtDW.Pin_In1, &rtDW.Pin_In2, &rtDW.Pin_H,
                                &rtDW.Gearmotor_turnRight_f);

            /* End of Outputs for SubSystem: '<S38>/Gearmotor_turnRight' */
          }
        }
      } else if (rtDW.ticksCounter < -2147483647) {
        rtDW.ticksCounter = MIN_int32_T;
      } else {
        rtDW.ticksCounter--;
      }
      break;
    }
    break;

   case IN_UP_END:
    rtDW.is_GEARSHIFT = IN_IDLE;
    break;
  }
}

/* Function for Chart: '<S5>/GCULogic' */
static void checkShift(void)
{
  int32_T b_previousEvent;
  if (rtDW.RateTransition2[0] != rtDW.lastShiftCom) {
    rtDW.lastShiftCom = rtDW.RateTransition2[0];
    if (rtDW.RateTransition2[1] == GEAR_COMMAND_UP) {
      b_previousEvent = rtDW.sfEvent;
      rtDW.sfEvent = event_GearshiftUp;
      if (rtDW.is_active_NEUTRAL_STATE != 0U) {
        NEUTRAL_STATE();
      }

      rtDW.sfEvent = event_GearshiftUp;
      if (rtDW.is_active_GEARSHIFT != 0U) {
        GEARSHIFT();
      }

      rtDW.sfEvent = b_previousEvent;
    } else if (rtDW.RateTransition2[1] == GEAR_COMMAND_DOWN) {
      b_previousEvent = rtDW.sfEvent;
      rtDW.sfEvent = event_GearshiftDown;
      if (rtDW.is_active_NEUTRAL_STATE != 0U) {
        NEUTRAL_STATE();
      }

      rtDW.sfEvent = event_GearshiftDown;
      if (rtDW.is_active_GEARSHIFT != 0U) {
        GEARSHIFT();
      }

      rtDW.sfEvent = b_previousEvent;
    } else if (rtDW.RateTransition2[1] == GEAR_COMMAND_NEUTRAL_UP) {
      b_previousEvent = rtDW.sfEvent;
      rtDW.sfEvent = event_GearshiftSetNeutral;
      if (rtDW.is_active_NEUTRAL_STATE != 0U) {
        NEUTRAL_STATE();
      }

      rtDW.sfEvent = event_GearshiftUp;
      if (rtDW.is_active_GEARSHIFT != 0U) {
        GEARSHIFT();
      }

      rtDW.sfEvent = b_previousEvent;
    } else {
      if (rtDW.RateTransition2[1] == GEAR_COMMAND_NEUTRAL_DOWN) {
        b_previousEvent = rtDW.sfEvent;
        rtDW.sfEvent = event_GearshiftSetNeutral;
        if (rtDW.is_active_NEUTRAL_STATE != 0U) {
          NEUTRAL_STATE();
        }

        rtDW.sfEvent = event_GearshiftDown;
        if (rtDW.is_active_GEARSHIFT != 0U) {
          GEARSHIFT();
        }

        rtDW.sfEvent = b_previousEvent;
      }
    }
  }
}

/* Function for Chart: '<S5>/GCULogic' */
static int32_T getAacParam(acc_params b_index)
{
  return rtDW.Merge[b_index];
}

/* Function for Chart: '<S5>/GCULogic' */
static void aacCheckShift(void)
{
  int32_T b_previousEvent;
  if ((rtDW.lastShift == rtDW.RateTransition) && (rtDW.RateTransition1[RPM] >=
       rtDW.Merge[((int32_T)RPM_LIMIT_1_2 + rtDW.RateTransition) - 1]) &&
      (rtDW.RateTransition1[WHEEL_SPEED] >= rtDW.Merge[((int32_T)SPEED_LIMIT_1_2
        + rtDW.RateTransition) - 1])) {
    b_previousEvent = rtDW.sfEvent;
    rtDW.sfEvent = event_GearshiftUp;
    if (rtDW.is_active_GEARSHIFT != 0U) {
      GEARSHIFT();
    }

    rtDW.sfEvent = b_previousEvent;
    b_previousEvent = rtDW.lastShift + 1;
    if (b_previousEvent > 255) {
      b_previousEvent = 255;
    }

    rtDW.lastShift = (uint8_T)b_previousEvent;
  }
}

/* Function for Chart: '<S5>/GCULogic' */
static void checkClutch(void)
{
  if ((rtDW.RateTransition5[0] != rtDW.lastClutchCom) && (((!(rtDW.is_GEARSHIFT ==
          IN_DOWNSHIFTING)) && (!(rtDW.is_NEUTRAL_STATE == IN_SET_NEUTRAL))) ||
       (rtDW.is_NEUTRAL_STATE == IN_UNSET_NEUTRAL))) {
    rtDW.lastClutchCom = rtDW.RateTransition5[0];
    Clutch_setValue(rtDW.RateTransition5[1]);
  }
}

/* Function for Chart: '<S5>/GCULogic' */
static void enter_atomic_MANUAL_MODES(void)
{
  rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
  rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
  checkShift();
  checkClutch();
}

/* Function for Chart: '<S5>/GCULogic' */
static void ACCELERATION(void)
{
  int32_T q0;
  int32_T q1;
  int64_T tmp;
  uint8_T tmp_0;
  if ((rtDW.RateTransition8[0] != rtDW.lastModeCom[0]) && (rtDW.RateTransition8
       [1] != rtDW.lastModeCom[1])) {
    /* Outputs for Function Call SubSystem: '<S35>/UnsetRPMLimiter' */
    Efi_unsetRpmLimiter(&rtDW.Merge2, &rtDW.UnsetRPMLimiter_c);

    /* End of Outputs for SubSystem: '<S35>/UnsetRPMLimiter' */
    rtDW.accFb = (uint16_T)ACC_OFF;
    Clutch_setValue(0);
    if (rtDW.RateTransition8[1] == AUTOX_MODE) {
      rtDW.is_ACTIVE = 0;
      rtDW.is_ACC = 0;
      rtDW.is_ACCELERATION = 0;
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        enter_atomic_MANUAL_MODES();
      }
    } else if (rtDW.RateTransition8[1] == ENDURANCE_MODE) {
      rtDW.is_ACTIVE = 0;
      rtDW.is_ACC = 0;
      rtDW.is_ACCELERATION = 0;
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
        rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
        checkShift();
        checkClutch();
      }
    } else if (rtDW.RateTransition8[1] == SKIDPAD_MODE) {
      rtDW.is_ACTIVE = 0;
      rtDW.is_ACC = 0;
      rtDW.is_ACCELERATION = 0;
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
        rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
        checkShift();
        checkClutch();
      }
    } else if (rtDW.RateTransition8[1] == ACCELERATION_MODE) {
      rtDW.is_ACTIVE = 0;
      rtDW.is_ACC = 0;
      rtDW.is_ACCELERATION = 0;
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_ACCELERATION) {
        rtDW.is_MODES = IN_ACCELERATION;
        rtDW.lastAacCom = rtDW.RateTransition4[0];
        rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
        rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
      }

      if (rtDW.is_ACCELERATION != IN_NotReady) {
        rtDW.is_ACCELERATION = IN_NotReady;
        rtDW.accFb = (uint16_T)ACC_OFF;
        checkShift();
        checkClutch();
      }
    } else {
      rtDW.is_ACTIVE = 0;
      rtDW.is_ACC = 0;
      rtDW.is_ACCELERATION = 0;
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
        rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
        checkShift();
        checkClutch();
      }
    }
  } else {
    switch (rtDW.is_ACCELERATION) {
     case IN_ACC:
      switch (rtDW.is_ACC) {
       case IN_ACTIVE:
        if ((rtDW.RateTransition4[0] != rtDW.lastAacCom) &&
            (rtDW.RateTransition4[1] == ACC_OFF)) {
          rtDW.lastAacCom = rtDW.RateTransition4[0];
          rtDW.is_ACTIVE = 0;
          rtDW.is_ACC = 0;
          if (rtDW.is_ACC != IN_STOPPING) {
            rtDW.is_ACC = IN_STOPPING;

            /* Outputs for Function Call SubSystem: '<S35>/UnsetRPMLimiter' */
            Efi_unsetRpmLimiter(&rtDW.Merge2, &rtDW.UnsetRPMLimiter_c);

            /* End of Outputs for SubSystem: '<S35>/UnsetRPMLimiter' */
            Clutch_setValue(0);

            /* sendUpdatesSW(ACC_CODE, uint16(0)); */
          }
        } else {
          switch (rtDW.is_ACTIVE) {
           case IN_READY:
            if (rtDW.aacCounter <= 1) {
              if ((rtDW.RateTransition4[0] != rtDW.lastAacCom) &&
                  (rtDW.RateTransition4[1] == ACC_GO) &&
                  (rtDW.RateTransition1[TPS] >= getAacParam(TPS_START_LIMIT))) {
                rtDW.lastAacCom = rtDW.RateTransition4[0];
                rtDW.is_ACTIVE = 0;
                if (rtDW.is_ACTIVE != IN_START_RELEASE) {
                  rtDW.is_ACTIVE = IN_START_RELEASE;
                  rtDW.accFb = (uint16_T)ACC_GO;
                  rtDW.aac_clutchValue = getAacParam(RAMP_START);
                  if (rtDW.aac_clutchValue < 256.0) {
                    if (rtDW.aac_clutchValue >= 0.0) {
                      tmp_0 = (uint8_T)rtDW.aac_clutchValue;
                    } else {
                      tmp_0 = 0U;
                    }
                  } else {
                    tmp_0 = MAX_uint8_T;
                  }

                  Clutch_setValue(tmp_0);
                  rtDW.aac_dtRelease = getAacParam(RAMP_TIME) / AAC_WORK_RATE_ms;
                  q0 = getAacParam(RAMP_START);
                  q1 = getAacParam(RAMP_END);
                  if ((q0 >= 0) && (q1 < q0 - MAX_int32_T)) {
                    q0 = MAX_int32_T;
                  } else if ((q0 < 0) && (q1 > q0 - MIN_int32_T)) {
                    q0 = MIN_int32_T;
                  } else {
                    q0 -= q1;
                  }

                  tmp = (int64_T)q0 * AAC_WORK_RATE_ms;
                  if (tmp > 2147483647LL) {
                    tmp = 2147483647LL;
                  } else {
                    if (tmp < -2147483648LL) {
                      tmp = -2147483648LL;
                    }
                  }

                  rtDW.aac_clutchStep = (real_T)(int32_T)tmp / (real_T)
                    getAacParam(RAMP_TIME);
                  rtDW.aacCounter = AAC_WORK_RATE_ms;
                }
              } else {
                rtDW.is_ACTIVE = 0;
                if (rtDW.is_ACTIVE != IN_READY) {
                  rtDW.is_ACTIVE = IN_READY;
                  rtDW.accFb = (uint16_T)ACC_READY;
                  rtDW.aacCounter = AAC_WORK_RATE_ms;
                  Clutch_setValue(100);
                  checkShift();
                }
              }
            } else {
              q0 = rtDW.aacCounter - 1;
              if (q0 < 0) {
                q0 = 0;
              }

              rtDW.aacCounter = (uint16_T)q0;
              checkShift();
            }
            break;

           case IN_RELEASING:
            if (rtDW.aacCounter <= 1) {
              if ((rtDW.aac_dtRelease <= 0) || (rtDW.clutchCurrVal <=
                   getAacParam(RAMP_END))) {
                Clutch_setValue(0);

                /* Outputs for Function Call SubSystem: '<S35>/UnsetRPMLimiter' */
                Efi_unsetRpmLimiter(&rtDW.Merge2, &rtDW.UnsetRPMLimiter_c);

                /* End of Outputs for SubSystem: '<S35>/UnsetRPMLimiter' */
                rtDW.is_ACTIVE = 0;
                if (rtDW.is_ACTIVE != IN_RUNNING) {
                  rtDW.is_ACTIVE = IN_RUNNING;
                  rtDW.aacCounter = AAC_WORK_RATE_ms;
                  rtDW.lastShift = rtDW.RateTransition;
                  aacCheckShift();
                }
              } else {
                rtDW.is_ACTIVE = 0;
                if (rtDW.is_ACTIVE != IN_RELEASING) {
                  rtDW.is_ACTIVE = IN_RELEASING;
                  rtDW.aac_clutchValue -= rtDW.aac_clutchStep;
                  if (rtDW.aac_clutchValue < 256.0) {
                    if (rtDW.aac_clutchValue >= 0.0) {
                      tmp_0 = (uint8_T)rtDW.aac_clutchValue;
                    } else {
                      tmp_0 = 0U;
                    }
                  } else {
                    tmp_0 = MAX_uint8_T;
                  }

                  Clutch_setValue(tmp_0);
                  if (rtDW.aac_dtRelease < -2147483647) {
                    rtDW.aac_dtRelease = MIN_int32_T;
                  } else {
                    rtDW.aac_dtRelease--;
                  }

                  rtDW.aacCounter = AAC_WORK_RATE_ms;
                }
              }
            } else {
              q0 = rtDW.aacCounter - 1;
              if (q0 < 0) {
                q0 = 0;
              }

              rtDW.aacCounter = (uint16_T)q0;
            }
            break;

           case IN_RUNNING:
            if (rtDW.RateTransition >= 5) {
              rtDW.is_ACTIVE = 0;
              rtDW.is_ACC = 0;
              if (rtDW.is_ACC != IN_STOPPING) {
                rtDW.is_ACC = IN_STOPPING;

                /* Outputs for Function Call SubSystem: '<S35>/UnsetRPMLimiter' */
                Efi_unsetRpmLimiter(&rtDW.Merge2, &rtDW.UnsetRPMLimiter_c);

                /* End of Outputs for SubSystem: '<S35>/UnsetRPMLimiter' */
                Clutch_setValue(0);

                /* sendUpdatesSW(ACC_CODE, uint16(0)); */
              }
            } else {
              aacCheckShift();
            }
            break;

           case IN_START:
            if (rtDW.aacCounter <= 1) {
              rtDW.is_ACTIVE = 0;
              if (rtDW.is_ACTIVE != IN_READY) {
                rtDW.is_ACTIVE = IN_READY;
                rtDW.accFb = (uint16_T)ACC_READY;
                rtDW.aacCounter = AAC_WORK_RATE_ms;
                Clutch_setValue(100);
                checkShift();
              }
            } else {
              q0 = rtDW.aacCounter - 1;
              if (q0 < 0) {
                q0 = 0;
              }

              rtDW.aacCounter = (uint16_T)q0;
            }
            break;

           case IN_START_RELEASE:
            if (rtDW.aacCounter <= 1) {
              rtDW.is_ACTIVE = 0;
              if (rtDW.is_ACTIVE != IN_RELEASING) {
                rtDW.is_ACTIVE = IN_RELEASING;
                rtDW.aac_clutchValue -= rtDW.aac_clutchStep;
                if (rtDW.aac_clutchValue < 256.0) {
                  if (rtDW.aac_clutchValue >= 0.0) {
                    tmp_0 = (uint8_T)rtDW.aac_clutchValue;
                  } else {
                    tmp_0 = 0U;
                  }
                } else {
                  tmp_0 = MAX_uint8_T;
                }

                Clutch_setValue(tmp_0);
                if (rtDW.aac_dtRelease < -2147483647) {
                  rtDW.aac_dtRelease = MIN_int32_T;
                } else {
                  rtDW.aac_dtRelease--;
                }

                rtDW.aacCounter = AAC_WORK_RATE_ms;
              }
            } else {
              q0 = rtDW.aacCounter - 1;
              if (q0 < 0) {
                q0 = 0;
              }

              rtDW.aacCounter = (uint16_T)q0;
            }
            break;
          }
        }
        break;

       case IN_STOPPING:
        rtDW.is_ACC = 0;
        rtDW.is_ACCELERATION = 0;
        if (rtDW.is_ACCELERATION != IN_NotReady) {
          rtDW.is_ACCELERATION = IN_NotReady;
          rtDW.accFb = (uint16_T)ACC_OFF;
          checkShift();
          checkClutch();
        }
        break;
      }
      break;

     case IN_NotReady:
      if ((rtDW.RateTransition4[0] != rtDW.lastAacCom) && (rtDW.RateTransition4
           [1] == ACC_READY)) {
        rtDW.lastAacCom = rtDW.RateTransition4[0];
        rtDW.is_ACCELERATION = IN_ACC;
        rtDW.aacCounter = 0U;
        rtDW.aac_clutchValue = 0.0;
        rtDW.aac_clutchStep = 0.0;
        rtDW.aac_dtRelease = 0;
        rtDW.is_ACC = IN_ACTIVE;
        if (rtDW.is_ACTIVE != IN_START) {
          rtDW.is_ACTIVE = IN_START;
          rtDW.accFb = (uint16_T)ACC_READY;
          rtDW.aacCounter = AAC_WORK_RATE_ms;

          /* Outputs for Function Call SubSystem: '<S35>/SetRPMLimiter' */
          Efi_setRpmLimiter(&rtDW.Merge2, &rtDW.SetRPMLimiter_e);

          /* End of Outputs for SubSystem: '<S35>/SetRPMLimiter' */
          Clutch_setValue(100);
        }
      } else {
        rtDW.accFb = (uint16_T)ACC_OFF;
        checkShift();
        checkClutch();
      }
      break;
    }
  }
}

/* Function for Chart: '<S5>/GCULogic' */
static void MODES(void)
{
  switch (rtDW.is_MODES) {
   case IN_ACCELERATION:
    ACCELERATION();
    break;

   case IN_INIT:
    if (rtDW.RateTransition8[1] == AUTOX_MODE) {
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
        rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
        checkShift();
        checkClutch();
      }
    } else if (rtDW.RateTransition8[1] == ENDURANCE_MODE) {
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
        rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
        checkShift();
        checkClutch();
      }
    } else if (rtDW.RateTransition8[1] == SKIDPAD_MODE) {
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
        rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
        checkShift();
        checkClutch();
      }
    } else if (rtDW.RateTransition8[1] == ACCELERATION_MODE) {
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_ACCELERATION) {
        rtDW.is_MODES = IN_ACCELERATION;
        rtDW.lastAacCom = rtDW.RateTransition4[0];
        rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
        rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
      }

      if (rtDW.is_ACCELERATION != IN_NotReady) {
        rtDW.is_ACCELERATION = IN_NotReady;
        rtDW.accFb = (uint16_T)ACC_OFF;
        checkShift();
        checkClutch();
      }
    } else {
      rtDW.is_MODES = 0;
      if (rtDW.is_MODES != IN_MANUAL_MODES) {
        rtDW.is_MODES = IN_MANUAL_MODES;
        rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
        rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
        checkShift();
        checkClutch();
      }
    }
    break;

   case IN_MANUAL_MODES:
    if ((rtDW.RateTransition8[0] != rtDW.lastModeCom[0]) &&
        (rtDW.RateTransition8[1] != rtDW.lastModeCom[1])) {
      if (rtDW.RateTransition8[1] == AUTOX_MODE) {
        rtDW.is_MODES = 0;
        if (rtDW.is_MODES != IN_MANUAL_MODES) {
          rtDW.is_MODES = IN_MANUAL_MODES;
          rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
          rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
          checkShift();
          checkClutch();
        }
      } else if (rtDW.RateTransition8[1] == ENDURANCE_MODE) {
        rtDW.is_MODES = 0;
        if (rtDW.is_MODES != IN_MANUAL_MODES) {
          rtDW.is_MODES = IN_MANUAL_MODES;
          rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
          rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
          checkShift();
          checkClutch();
        }
      } else if (rtDW.RateTransition8[1] == SKIDPAD_MODE) {
        rtDW.is_MODES = 0;
        if (rtDW.is_MODES != IN_MANUAL_MODES) {
          rtDW.is_MODES = IN_MANUAL_MODES;
          rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
          rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
          checkShift();
          checkClutch();
        }
      } else if (rtDW.RateTransition8[1] == ACCELERATION_MODE) {
        rtDW.is_MODES = 0;
        if (rtDW.is_MODES != IN_ACCELERATION) {
          rtDW.is_MODES = IN_ACCELERATION;
          rtDW.lastAacCom = rtDW.RateTransition4[0];
          rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
          rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
        }

        if (rtDW.is_ACCELERATION != IN_NotReady) {
          rtDW.is_ACCELERATION = IN_NotReady;
          rtDW.accFb = (uint16_T)ACC_OFF;
          checkShift();
          checkClutch();
        }
      } else {
        rtDW.is_MODES = 0;
        if (rtDW.is_MODES != IN_MANUAL_MODES) {
          rtDW.is_MODES = IN_MANUAL_MODES;
          rtDW.lastModeCom[0] = rtDW.RateTransition8[0];
          rtDW.lastModeCom[1] = rtDW.RateTransition8[1];
          checkShift();
          checkClutch();
        }
      }
    } else {
      checkShift();
      checkClutch();
    }
    break;
  }
}

/* Function for Chart: '<S2>/EEPROM_OutputRequest' */
static void updateOutput(void)
{
  int32_T i;
  if (rtDW.lastEvaluatedIndex >= 20.0) {
    rtDW.lastEvaluatedIndex = 1.0;
  } else {
    rtDW.lastEvaluatedIndex++;
  }

  rtDW.outputRequest.operation = rtDW.TmpRTBAtEEPROM_Load_BufferOut_m[(int32_T)
    rtDW.lastEvaluatedIndex - 1].operation;
  rtDW.outputRequest.page = rtDW.TmpRTBAtEEPROM_Load_BufferOut_m[(int32_T)
    rtDW.lastEvaluatedIndex - 1].page;
  rtDW.outputRequest.cell = rtDW.TmpRTBAtEEPROM_Load_BufferOut_m[(int32_T)
    rtDW.lastEvaluatedIndex - 1].cell;
  rtDW.outputRequest.dataSize = rtDW.TmpRTBAtEEPROM_Load_BufferOut_m[(int32_T)
    rtDW.lastEvaluatedIndex - 1].dataSize;
  for (i = 0; i < 16; i++) {
    rtDW.outputRequest.data[i] = rtDW.TmpRTBAtEEPROM_Load_BufferOut_m[(int32_T)
      rtDW.lastEvaluatedIndex - 1].data[i];
  }
}

/* Function for Chart: '<S7>/AccelerationRoutine' */
static void updateData(void)
{
  uint32_T tmp;
  boolean_T guard1 = false;
  if ((rtDW.RateTransition7 == 0) && (rtDW.lastGearPin == 1)) {
    tmp = rtDW.currGear_c + 1U;
    if (tmp > 65535U) {
      tmp = 65535U;
    }

    rtDW.currGear_c = (uint16_T)tmp;
  } else {
    guard1 = false;
    if (rtDW.RateTransition7 == 1) {
      rtDW.rpm = 0U;
      rtDW.wheelSpeed = 0U;
      guard1 = true;
    } else {
      tmp = rtDW.rpm + 150U;
      if (tmp > 65535U) {
        tmp = 65535U;
      }

      rtDW.rpm = (uint16_T)tmp;
      tmp = rtDW.wheelSpeed + 5U;
      if (tmp > 65535U) {
        tmp = 65535U;
      }

      rtDW.wheelSpeed = (uint16_T)tmp;
      if (rtDW.message == 0.0) {
        guard1 = true;
      } else {
        rtDW.message = 0.0;
        rtDW.id = 774U;
        rtDW.firstInt = rtDW.wheelSpeed;
      }
    }

    if (guard1) {
      rtDW.message = 1.0;
      rtDW.id = 773U;
      rtDW.firstInt = rtDW.currGear_c;
      rtDW.secondInt = rtDW.rpm;
    }
  }

  rtDW.lastGearPin = rtDW.RateTransition7;
}

/* Function for Chart: '<S7>/AccelerationRoutine' */
static void checkGear(void)
{
  uint32_T tmp;
  if ((rtDW.RateTransition7 == 0) && (rtDW.lastGearPin == 1)) {
    tmp = rtDW.currGear_c + 1U;
    if (tmp > 65535U) {
      tmp = 65535U;
    }

    rtDW.currGear_c = (uint16_T)tmp;
  }

  rtDW.lastGearPin = rtDW.RateTransition7;
}

/* Function for Chart: '<S4>/MessageEvaluation1' */
static void sendAccCommand(uint16_T com)
{
  int32_T tmp;
  if (rtDW.accCommand[0] >= 255) {
    rtDW.accCommand[0] = 0U;
  } else {
    tmp = rtDW.accCommand[0] + 1;
    if (tmp > 65535) {
      tmp = 65535;
    }

    rtDW.accCommand[0] = (uint16_T)tmp;
  }

  rtDW.accCommand[1] = com;
}

/* Function for Chart: '<S4>/MessageEvaluation1' */
static void sendClutchCommand(uint16_T com)
{
  uint16_T tmp;
  int32_T tmp_0;
  if (rtDW.clutchCommand[0] >= 255) {
    rtDW.clutchCommand[0] = 0U;
  } else {
    tmp_0 = rtDW.clutchCommand[0] + 1;
    if (tmp_0 > 255) {
      tmp_0 = 255;
    }

    rtDW.clutchCommand[0] = (uint8_T)tmp_0;
  }

  tmp = com;
  if (com > 255) {
    tmp = 255U;
  }

  rtDW.clutchCommand[1] = (uint8_T)tmp;
}

/* Function for Chart: '<S4>/MessageEvaluation1' */
static void sendModeCommand(uint16_T com)
{
  int32_T tmp;
  if (rtDW.modeCommand[0] >= 255) {
    rtDW.modeCommand[0] = 0U;
  } else {
    tmp = rtDW.modeCommand[0] + 1;
    if (tmp > 65535) {
      tmp = 65535;
    }

    rtDW.modeCommand[0] = (uint16_T)tmp;
  }

  rtDW.modeCommand[1] = com;
}

/* Function for Chart: '<S4>/MessageEvaluation1' */
static void sendShiftCommand(uint16_T com)
{
  int32_T tmp;
  if (rtDW.shiftCommand[0] >= 255) {
    rtDW.shiftCommand[0] = 0U;
  } else {
    tmp = rtDW.shiftCommand[0] + 1;
    if (tmp > 65535) {
      tmp = 65535;
    }

    rtDW.shiftCommand[0] = (uint16_T)tmp;
  }

  rtDW.shiftCommand[1] = com;
  if ((rtDW.RateTransition6 != 100) && ((com == GEAR_COMMAND_NEUTRAL_UP) || (com
        == GEAR_COMMAND_NEUTRAL_DOWN) || (com == GEAR_COMMAND_DOWN))) {
    sendAccCommand(STOP_COM);
  }
}

/* Function for Chart: '<S4>/MessageEvaluation1' */
static void sendStartEngCommand(void)
{
  int32_T tmp;
  if (rtDW.startEngCommand >= 255) {
    rtDW.startEngCommand = 0U;
  } else {
    tmp = rtDW.startEngCommand + 1;
    if (tmp > 255) {
      tmp = 255;
    }

    rtDW.startEngCommand = (uint8_T)tmp;
  }
}

/* Function for Chart: '<S2>/EEPROM_Load_Buffer' */
static void updateBuffer(const eepromRequest *BusConversion_InsertedFor_EEPRO)
{
  int32_T i;
  if (rtDW.lastInsertedIndex >= 20.0) {
    rtDW.lastInsertedIndex = 1.0;
  } else {
    rtDW.lastInsertedIndex++;
  }

  i = (int32_T)rtDW.lastInsertedIndex - 1;
  rtDW.requestBuffer[i].operation = BusConversion_InsertedFor_EEPRO->operation;
  rtDW.requestBuffer[i].page = BusConversion_InsertedFor_EEPRO->page;
  rtDW.requestBuffer[i].cell = BusConversion_InsertedFor_EEPRO->cell;
  rtDW.requestBuffer[i].dataSize = BusConversion_InsertedFor_EEPRO->dataSize;
  for (i = 0; i < 16; i++) {
    rtDW.requestBuffer[(int32_T)rtDW.lastInsertedIndex - 1].data[i] =
      BusConversion_InsertedFor_EEPRO->data[i];
  }
}

/* Model step function for TID0 */
void GCU_Model_genCode_step0(void)     /* Sample time: [9.9999999999999991E-5s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID1 */
void GCU_Model_genCode_step1(void)     /* Sample time: [0.001s, 0.0s] */
{
  ZCEventType zcEvent[23];
  int32_T rtb_RateTransition1;
  int32_T rtb_RateTransition;
  ZCEventType zcEvent_0[12];
  uint8_T Merge_b;
  int32_T i;
  boolean_T tmp;
  ZCEventType zcEvent_idx_0;
  ZCEventType zcEvent_idx_1;

  /* Outputs for Triggered SubSystem: '<S24>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S28>/Trigger'
   */
  for (i = 0; i < 23; i++) {
    zcEvent[i] = rt_I32ZCFcn(ANY_ZERO_CROSSING,
      &rtPrevZCX.TriggeredSubsystem_Trig_ZCE[i],
      (rtDW.load_default_timings[i]));
  }

  tmp = false;
  for (i = 0; i < 23; i++) {
    tmp = (tmp || (zcEvent[i] != NO_ZCEVENT));
  }

  if (tmp) {
    /* Inport: '<S28>/In1' */
    memcpy(&rtDW.Merge_m[0], &rtDW.load_default_timings[0], 23U * sizeof(int32_T));
  }

  /* End of Outputs for SubSystem: '<S24>/Triggered Subsystem' */

  /* RateTransition: '<S24>/Rate Transition1' */
  rtb_RateTransition1 = rtDW.RateTransition1_Buffer0;

  /* RateTransition: '<S24>/Rate Transition' */
  rtb_RateTransition = rtDW.RateTransition_Buffer0;

  /* Outputs for Triggered SubSystem: '<S24>/ ' incorporates:
   *  TriggerPort: '<S27>/Trigger'
   */
  zcEvent_idx_0 = rt_I32ZCFcn(ANY_ZERO_CROSSING,&rtPrevZCX._Trig_ZCE[0],
    (rtb_RateTransition1));
  zcEvent_idx_1 = rt_I32ZCFcn(ANY_ZERO_CROSSING,&rtPrevZCX._Trig_ZCE[1],
    (rtb_RateTransition));
  if ((zcEvent_idx_0 != NO_ZCEVENT) || (zcEvent_idx_1 != NO_ZCEVENT)) {
    /* Assignment: '<S27>/Assignment' incorporates:
     *  UnitDelay: '<S24>/Unit Delay'
     */
    memcpy(&rtDW.Merge_m[0], &rtDW.UnitDelay_DSTATE[0], 23U * sizeof(int32_T));
    rtDW.Merge_m[rtb_RateTransition1] = rtb_RateTransition;
  }

  /* End of Outputs for SubSystem: '<S24>/ ' */

  /* Outputs for Triggered SubSystem: '<S23>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S26>/Trigger'
   */
  for (i = 0; i < 12; i++) {
    zcEvent_0[i] = rt_I32ZCFcn(ANY_ZERO_CROSSING,
      &rtPrevZCX.TriggeredSubsystem_Trig_ZCE_j[i],
      (rtDW.load_accParameters[i]));
  }

  tmp = false;
  for (i = 0; i < 12; i++) {
    tmp = (tmp || (zcEvent_0[i] != NO_ZCEVENT));
  }

  if (tmp) {
    /* Inport: '<S26>/In1' */
    for (i = 0; i < 12; i++) {
      rtDW.Merge[i] = rtDW.load_accParameters[i];
    }

    /* End of Inport: '<S26>/In1' */
  }

  /* End of Outputs for SubSystem: '<S23>/Triggered Subsystem' */

  /* RateTransition: '<S23>/Rate Transition1' */
  rtb_RateTransition1 = rtDW.RateTransition1_Buffer0_a;

  /* RateTransition: '<S23>/Rate Transition' */
  rtb_RateTransition = rtDW.RateTransition_Buffer0_k;

  /* Outputs for Triggered SubSystem: '<S23>/ ' incorporates:
   *  TriggerPort: '<S25>/Trigger'
   */
  zcEvent_idx_0 = rt_I32ZCFcn(ANY_ZERO_CROSSING,&rtPrevZCX._Trig_ZCE_i[0],
    (rtb_RateTransition1));
  zcEvent_idx_1 = rt_I32ZCFcn(ANY_ZERO_CROSSING,&rtPrevZCX._Trig_ZCE_i[1],
    (rtb_RateTransition));
  if ((zcEvent_idx_0 != NO_ZCEVENT) || (zcEvent_idx_1 != NO_ZCEVENT)) {
    /* Assignment: '<S25>/Assignment' incorporates:
     *  UnitDelay: '<S23>/Unit Delay'
     */
    for (i = 0; i < 12; i++) {
      rtDW.Merge[i] = rtDW.UnitDelay_DSTATE_j[i];
    }

    rtDW.Merge[rtb_RateTransition1] = rtb_RateTransition;

    /* End of Assignment: '<S25>/Assignment' */
  }

  /* End of Outputs for SubSystem: '<S23>/ ' */

  /* RateTransition: '<Root>/Rate Transition' */
  rtDW.RateTransition = rtDW.RateTransition_Buffer0_b;

  /* RateTransition: '<Root>/Rate Transition1' */
  i = rtDW.RateTransition1_ActiveBufIdx * 3;
  rtDW.RateTransition1[0] = rtDW.RateTransition1_Buffer[i];
  rtDW.RateTransition1[1] = rtDW.RateTransition1_Buffer[1 + i];
  rtDW.RateTransition1[2] = rtDW.RateTransition1_Buffer[2 + i];

  /* RateTransition: '<Root>/Rate Transition2' */
  i = rtDW.RateTransition2_ActiveBufIdx << 1;
  rtDW.RateTransition2[0] = rtDW.RateTransition2_Buffer[i];
  rtDW.RateTransition2[1] = rtDW.RateTransition2_Buffer[1 + i];

  /* RateTransition: '<Root>/Rate Transition3' */
  rtDW.RateTransition3 = rtDW.RateTransition3_Buffer0;

  /* RateTransition: '<Root>/Rate Transition4' */
  i = rtDW.RateTransition4_ActiveBufIdx << 1;
  rtDW.RateTransition4[0] = rtDW.RateTransition4_Buffer[i];
  rtDW.RateTransition4[1] = rtDW.RateTransition4_Buffer[1 + i];

  /* RateTransition: '<Root>/Rate Transition5' */
  i = rtDW.RateTransition5_ActiveBufIdx << 1;
  rtDW.RateTransition5[0] = rtDW.RateTransition5_Buffer[i];
  rtDW.RateTransition5[1] = rtDW.RateTransition5_Buffer[1 + i];

  /* RateTransition: '<Root>/Rate Transition8' */
  i = rtDW.RateTransition8_ActiveBufIdx << 1;
  rtDW.RateTransition8[0] = rtDW.RateTransition8_Buffer[i];
  rtDW.RateTransition8[1] = rtDW.RateTransition8_Buffer[1 + i];

  /* RateTransition: '<S2>/TmpRTBAtEEPROM_Load_BufferOutport1' */
  i = rtDW.TmpRTBAtEEPROM_Load_BufferOut_g * 20;
  for (rtb_RateTransition1 = 0; rtb_RateTransition1 < 20; rtb_RateTransition1++)
  {
    rtDW.TmpRTBAtEEPROM_Load_BufferOut_m[rtb_RateTransition1] =
      rtDW.TmpRTBAtEEPROM_Load_BufferOutpo[rtb_RateTransition1 + i];
  }

  /* End of RateTransition: '<S2>/TmpRTBAtEEPROM_Load_BufferOutport1' */

  /* RateTransition: '<S2>/TmpRTBAtEEPROM_Load_BufferOutport2' */
  rtDW.TmpRTBAtEEPROM_Load_BufferOut_n = rtDW.TmpRTBAtEEPROM_Load_BufferOut_l;

  /* Outputs for Atomic SubSystem: '<Root>/GCU_timer' */
  /* Chart: '<S5>/GCULogic' */
  rtDW.sfEvent = -1;
  if (rtDW.is_active_c1_GCU_Model_genCode == 0U) {
    rtDW.is_active_c1_GCU_Model_genCode = 1U;
    rtDW.is_active_MODES = 1U;
    rtDW.lastAacCom = 0U;
    rtDW.lastShiftCom = 0U;
    rtDW.lastClutchCom = 0U;
    rtDW.is_MODES = IN_INIT;
    rtDW.is_active_NEUTRAL_STATE = 1U;
    rtDW.is_NEUTRAL_STATE = IN_NEUTRAL;
    rtDW.is_active_GEARSHIFT = 1U;
    rtDW.ticksCounter = 0;
    if (rtDW.is_GEARSHIFT != IN_INIT_j) {
      rtDW.is_GEARSHIFT = IN_INIT_j;
      rtDW.ticksCounter = 0;
    }

    rtDW.is_active_START_ENGINE = 1U;
    rtDW.lastCom = 0U;
    rtDW.startCounter = 0U;
    rtDW.is_START_ENGINE = IN_WAIT;
    if (rtDW.is_active_SCAN_ADC != 1U) {
      rtDW.is_active_SCAN_ADC = 1U;
      rtDW.timerCounter = 0U;
    }

    if (rtDW.is_SCAN_ADC != IN_SCAN) {
      rtDW.is_SCAN_ADC = IN_SCAN;

      /* Outputs for Function Call SubSystem: '<S37>/SCAN_ADC.ScanADC' */
      SCAN_ADCScanADC();

      /* End of Outputs for SubSystem: '<S37>/SCAN_ADC.ScanADC' */
    }

    rtDW.is_active_EEPROM_TRIGGER = 1U;
  } else {
    if (rtDW.is_active_MODES != 0U) {
      MODES();
    }

    if (rtDW.is_active_NEUTRAL_STATE != 0U) {
      NEUTRAL_STATE();
    }

    if (rtDW.is_active_GEARSHIFT != 0U) {
      GEARSHIFT();
    }

    if (rtDW.is_active_START_ENGINE != 0U) {
      switch (rtDW.is_START_ENGINE) {
       case IN_START_b:
        if (rtDW.startCounter <= 0) {
          rtDW.is_START_ENGINE = 0;
          if (rtDW.is_START_ENGINE != IN_STOP) {
            rtDW.is_START_ENGINE = IN_STOP;

            /* Outputs for Function Call SubSystem: '<S36>/EngineControl_Stop' */

            /* S-Function (EngineControl_stop): '<S46>/EngineControl Stop' */
            EngineControl_stop_Outputs_wrapper(&rtDW.EngineControlStop);

            /* End of Outputs for SubSystem: '<S36>/EngineControl_Stop' */
          }
        } else if (rtDW.RateTransition3 != rtDW.lastCom) {
          rtDW.is_START_ENGINE = 0;
          if (rtDW.is_START_ENGINE != IN_START_b) {
            rtDW.is_START_ENGINE = IN_START_b;

            /* Outputs for Function Call SubSystem: '<S36>/EngineControl_Start' */
            EngineControl_Start(&Merge_b, &rtDW.EngineControl_Start_h);

            /* End of Outputs for SubSystem: '<S36>/EngineControl_Start' */
            rtDW.lastCom = rtDW.RateTransition3;
            rtDW.startCounter = 100U;
          }
        } else {
          i = rtDW.startCounter - 1;
          if (i < 0) {
            i = 0;
          }

          rtDW.startCounter = (uint8_T)i;
        }
        break;

       case IN_STOP:
        if (rtDW.RateTransition3 != rtDW.lastCom) {
          rtDW.is_START_ENGINE = 0;
          if (rtDW.is_START_ENGINE != IN_START_b) {
            rtDW.is_START_ENGINE = IN_START_b;

            /* Outputs for Function Call SubSystem: '<S36>/EngineControl_Start' */
            EngineControl_Start(&Merge_b, &rtDW.EngineControl_Start_h);

            /* End of Outputs for SubSystem: '<S36>/EngineControl_Start' */
            rtDW.lastCom = rtDW.RateTransition3;
            rtDW.startCounter = 100U;
          }
        }
        break;

       case IN_WAIT:
        if (rtDW.RateTransition3 != rtDW.lastCom) {
          rtDW.is_START_ENGINE = 0;
          if (rtDW.is_START_ENGINE != IN_START_b) {
            rtDW.is_START_ENGINE = IN_START_b;

            /* Outputs for Function Call SubSystem: '<S36>/EngineControl_Start' */
            EngineControl_Start(&Merge_b, &rtDW.EngineControl_Start_h);

            /* End of Outputs for SubSystem: '<S36>/EngineControl_Start' */
            rtDW.lastCom = rtDW.RateTransition3;
            rtDW.startCounter = 100U;
          }
        }
        break;
      }
    }

    if (rtDW.is_active_SCAN_ADC != 0U) {
      switch (rtDW.is_SCAN_ADC) {
       case IN_SCAN:
        rtDW.is_SCAN_ADC = 0;
        if (rtDW.is_SCAN_ADC != IN_WAIT_m) {
          rtDW.is_SCAN_ADC = IN_WAIT_m;
          rtDW.timerCounter = 0U;
        }
        break;

       case IN_WAIT_m:
        if (rtDW.timerCounter >= ADC_PERIOD) {
          rtDW.is_SCAN_ADC = 0;
          if (rtDW.is_SCAN_ADC != IN_SCAN) {
            rtDW.is_SCAN_ADC = IN_SCAN;

            /* Outputs for Function Call SubSystem: '<S37>/SCAN_ADC.ScanADC' */
            SCAN_ADCScanADC();

            /* End of Outputs for SubSystem: '<S37>/SCAN_ADC.ScanADC' */
          }
        } else {
          i = rtDW.timerCounter + 1;
          if (i > 65535) {
            i = 65535;
          }

          rtDW.timerCounter = (uint16_T)i;
        }
        break;
      }
    }

    /* Chart: '<S2>/EEPROM_OutputRequest' */
    /* Chart: '<S2>/EEPROM_OutputRequest' */
    if ((rtDW.is_active_EEPROM_TRIGGER != 0U) &&
        (rtDW.TmpRTBAtEEPROM_Load_BufferOut_n != rtDW.lastEvaluatedIndex)) {
      updateOutput();

      /* Outputs for Function Call SubSystem: '<S2>/Evaluate_Request' */
      /* If: '<S20>/If' incorporates:
       *  Constant: '<S20>/Constant'
       *  Constant: '<S20>/Constant1'
       */
      if (rtDW.outputRequest.operation == 87) {
        /* Outputs for IfAction SubSystem: '<S20>/Write' incorporates:
         *  ActionPort: '<S22>/Action Port'
         */

        /* S-Function (Eeprom_write): '<S22>/Eeprom_write' */

        /* Level2 S-Function Block: '<S22>/Eeprom_write' (Eeprom_write) */
        {
          SimStruct *rts = rtM->childSfunctions[0];
          sfcnOutputs(rts,1);
        }

        /* End of Outputs for SubSystem: '<S20>/Write' */
      } else {
        if (rtDW.outputRequest.operation == 82) {
          /* Outputs for IfAction SubSystem: '<S20>/Read' incorporates:
           *  ActionPort: '<S21>/Action Port'
           */

          /* S-Function (Eeprom_read): '<S21>/Eeprom_read' */
          Eeprom_read_Outputs_wrapper(&rtDW.outputRequest.page,
            &rtDW.outputRequest.cell, &rtDW.outputRequest.dataSize,
            &rtDW.Eeprom_read_o1, &rtDW.Eeprom_read_o2[0]);

          /* End of Outputs for SubSystem: '<S20>/Read' */
        }
      }

      /* End of If: '<S20>/If' */
      /* End of Outputs for SubSystem: '<S2>/Evaluate_Request' */
    }

    /* End of Chart: '<S2>/EEPROM_OutputRequest' */
  }

  /* End of Chart: '<S5>/GCULogic' */
  /* End of Outputs for SubSystem: '<Root>/GCU_timer' */

  /* Outputs for Triggered SubSystem: '<S10>/Triggered_Subsystem' incorporates:
   *  TriggerPort: '<S53>/Trigger'
   */
  if (((rtDW.Merge2 > 0) != (rtPrevZCX.Triggered_Subsystem_Trig_ZCE == POS_ZCSIG))
      && (rtPrevZCX.Triggered_Subsystem_Trig_ZCE != UNINITIALIZED_ZCSIG)) {
    /* Inport: '<S53>/In1' */
    rtDW.Merge_j = rtDW.Merge2;
  }

  rtPrevZCX.Triggered_Subsystem_Trig_ZCE = (ZCSigState)(rtDW.Merge2 > 0);

  /* End of Outputs for SubSystem: '<S10>/Triggered_Subsystem' */

  /* Outputs for Triggered SubSystem: '<S10>/Triggered_Subsystem1' incorporates:
   *  TriggerPort: '<S54>/Trigger'
   */
  /* RateTransition: '<S10>/Rate Transition' incorporates:
   *  Inport: '<S54>/In1'
   */
  if (((rtDW.RateTransition_Buffer0_g > 0) !=
       (rtPrevZCX.Triggered_Subsystem1_Trig_ZCE == POS_ZCSIG)) &&
      (rtPrevZCX.Triggered_Subsystem1_Trig_ZCE != UNINITIALIZED_ZCSIG)) {
    rtDW.Merge_j = rtDW.RateTransition_Buffer0_g;
  }

  rtPrevZCX.Triggered_Subsystem1_Trig_ZCE = (ZCSigState)
    (rtDW.RateTransition_Buffer0_g > 0);

  /* End of RateTransition: '<S10>/Rate Transition' */
  /* End of Outputs for SubSystem: '<S10>/Triggered_Subsystem1' */

  /* Outport: '<Root>/outputRequest' */
  rtY.outputRequest = rtDW.outputRequest;

  /* Outport: '<Root>/dataRead' */
  for (i = 0; i < 16; i++) {
    rtY.dataRead[i] = rtDW.Eeprom_read_o2[i];
  }

  /* End of Outport: '<Root>/dataRead' */

  /* Update for UnitDelay: '<S24>/Unit Delay' */
  memcpy(&rtDW.UnitDelay_DSTATE[0], &rtDW.Merge_m[0], 23U * sizeof(int32_T));

  /* Update for UnitDelay: '<S23>/Unit Delay' */
  for (i = 0; i < 12; i++) {
    rtDW.UnitDelay_DSTATE_j[i] = rtDW.Merge[i];
  }

  /* End of Update for UnitDelay: '<S23>/Unit Delay' */

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   */
  rtM->Timing.t[1] =
    (++rtM->Timing.clockTick1) * rtM->Timing.stepSize1;
}

/* Model step function for TID2 */
void GCU_Model_genCode_step2(void)     /* Sample time: [0.001s, 0.0002s] */
{
  int32_T rtb_Cast1;
  int32_T rtb_Cast_h;
  int32_T rtb_Cast1_i;
  int32_T i;
  uint16_T tmp;

  /* RateTransition: '<Root>/Rate Transition7' */
  rtDW.RateTransition7 = rtDW.Pin_In1;

  /* Outputs for Atomic SubSystem: '<Root>/Simulink_Debug' */
  /* Chart: '<S7>/AccelerationRoutine' */
  switch (rtDW.is_c3_GCU_Model_genCode) {
   case IN_ActivateAac:
    rtDW.is_c3_GCU_Model_genCode = IN_InsertGear;
    rtDW.id = 512U;
    rtDW.firstInt = 400U;
    break;

   case IN_CHANGE_MODE:
   case IN_EXIT:
    break;

   case IN_DajeDeGas:
    if (rtDW.currGear_c == 4) {
      rtDW.is_c3_GCU_Model_genCode = IN_CHANGE_MODE;
      rtDW.id = 1000U;
      rtDW.firstInt = 2U;
    } else {
      updateData();
    }
    break;

   case IN_EnterAcceleration:
    rtDW.is_c3_GCU_Model_genCode = IN_ActivateAac;
    rtDW.id = 514U;
    rtDW.firstInt = 1U;
    break;

   case IN_InsertGear:
    if (rtDW.currGear_c == 1) {
      rtDW.is_c3_GCU_Model_genCode = IN_TPS_On;
      rtDW.id = 773U;
      rtDW.thirdInt = 100U;
    } else {
      checkGear();
    }
    break;

   case IN_Ready:
    rtDW.is_c3_GCU_Model_genCode = IN_DajeDeGas;
    rtDW.id = 0U;
    rtDW.rpm = 0U;
    rtDW.wheelSpeed = 0U;
    break;

   case IN_TPS_On:
    rtDW.thirdInt = 100U;
    rtDW.is_c3_GCU_Model_genCode = IN_Ready;
    rtDW.id = 514U;
    rtDW.firstInt = 2U;
    break;

   case IN_Wait:
    rtDW.is_c3_GCU_Model_genCode = IN_delay;
    rtDW.count = 0.0;
    break;

   default:
    if (rtDW.count == 10.0) {
      rtDW.is_c3_GCU_Model_genCode = IN_EnterAcceleration;
      rtDW.id = 513U;
      rtDW.secondInt = 5U;
    } else {
      rtDW.count++;
    }
    break;
  }

  /* End of Chart: '<S7>/AccelerationRoutine' */

  /* S-Function (PackCanUART): '<S7>/PackCanUart' */
  PackCanUART_Outputs_wrapper(&rtDW.id, &rtDW.firstInt, &rtDW.secondInt,
    &rtDW.thirdInt, (uint16_T*)&GCU_Model_genCode_U16GND, &rtDW.PackCanUart[0]);

  /* End of Outputs for SubSystem: '<Root>/Simulink_Debug' */

  /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
   *  Inport: '<Root>/CAN'
   *  Inport: '<Root>/SelectMode'
   *  Inport: '<Root>/UART_debug'
   */
  switch ((int32_T)rtU.SelectMode) {
   case 1:
    for (i = 0; i < 10; i++) {
      rtDW.MultiportSwitch[i] = rtU.UART_debug[i];
    }
    break;

   case 2:
    for (i = 0; i < 10; i++) {
      rtDW.MultiportSwitch[i] = rtU.CAN[i];
    }
    break;

   default:
    for (i = 0; i < 10; i++) {
      rtDW.MultiportSwitch[i] = rtDW.PackCanUart[i];
    }
    break;
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

  /* RateTransition: '<Root>/Rate Transition6' */
  rtDW.RateTransition6 = rtDW.clutchCurrVal;

  /* Outputs for Atomic SubSystem: '<Root>/GCU_CAN_Read' */
  /* S-Function (UnpackCanUART): '<S4>/UnpackCanUart' */
  UnpackCanUART_Outputs_wrapper(&rtDW.MultiportSwitch[0], &rtDW.UnpackCanUart_o1,
    &rtDW.UnpackCanUart_o2, &rtDW.UnpackCanUart_o3, &rtDW.UnpackCanUart_o4,
    &rtDW.UnpackCanUart_o5);

  /* Chart: '<S4>/MessageEvaluation1' */
  if (rtDW.UnpackCanUart_o1 == EFI_GEAR_RPM_TPS_PH2O_ID) {
    rtDW.currGear = rtDW.UnpackCanUart_o2;

    /* Outputs for Function Call SubSystem: '<S4>/AAC_ExternalValues' */
    AAC_ExternalValues(rtDW.UnpackCanUart_o3, (uint16_T)RPM, rtDW.Assignment,
                       &rtDW.AAC_ExternalValues_f);
    AAC_ExternalValues(rtDW.UnpackCanUart_o4, (uint16_T)TPS, rtDW.Assignment,
                       &rtDW.AAC_ExternalValues_f);

    /* End of Outputs for SubSystem: '<S4>/AAC_ExternalValues' */
  } else if (rtDW.UnpackCanUart_o1 == SW_FIRE_GCU_ID) {
    sendStartEngCommand();
  } else if (rtDW.UnpackCanUart_o1 == SW_GEARSHIFT_ID) {
    sendShiftCommand(rtDW.UnpackCanUart_o2);
  } else if (rtDW.UnpackCanUart_o1 == EFI_TRACTION_CONTROL_ID) {
    /* Outputs for Function Call SubSystem: '<S4>/AAC_ExternalValues' */
    AAC_ExternalValues((uint16_T)(rtDW.UnpackCanUart_o2 / 10U), (uint16_T)
                       WHEEL_SPEED, rtDW.Assignment, &rtDW.AAC_ExternalValues_f);

    /* End of Outputs for SubSystem: '<S4>/AAC_ExternalValues' */
  } else if (rtDW.UnpackCanUart_o1 == SW_CLUTCH_MODE_MAP_GCU_ID) {
    tmp = rtDW.UnpackCanUart_o2;
    if (rtDW.UnpackCanUart_o2 > 255) {
      tmp = 255U;
    }

    sendModeCommand(rtDW.UnpackCanUart_o3);
    rtDW.mapTarget = rtDW.UnpackCanUart_o4;
    if ((uint8_T)tmp > ACC_CLUTCH_NOISE_LEVEL) {
      sendAccCommand(STOP_COM);
    }

    sendClutchCommand((uint16_T)(uint8_T)tmp);
  } else if (rtDW.UnpackCanUart_o1 == SW_OK_BUTTON_GCU_ID) {
    sendAccCommand(rtDW.UnpackCanUart_o2);
    if (rtDW.accCommand[1] == ACC_OFF) {
      sendClutchCommand(0);
    }
  } else {
    if (rtDW.UnpackCanUart_o1 == SW_TRACTION_LIMITER_GCU_ID) {
      i = rtDW.UnpackCanUart_o2 * 100;
      if (i > 65535) {
        i = 65535;
      }

      rtDW.tractionTarget = (uint16_T)i;
    }
  }

  /* End of Chart: '<S4>/MessageEvaluation1' */
  /* End of Outputs for SubSystem: '<Root>/GCU_CAN_Read' */

  /* RateTransition: '<Root>/Rate Transition14' */
  if (!(rtDW.RateTransition14_semaphoreTaken != 0)) {
    rtDW.RateTransition14_Buffer0[0] = rtDW.Assignment[0];
    rtDW.RateTransition14_Buffer0[1] = rtDW.Assignment[1];
    rtDW.RateTransition14_Buffer0[2] = rtDW.Assignment[2];
  }

  /* End of RateTransition: '<Root>/Rate Transition14' */

  /* DataTypeConversion: '<S23>/Cast' */
  i = rtDW.accParametersIndex;

  /* DataTypeConversion: '<S23>/Cast1' */
  rtb_Cast1 = rtDW.accParametersValue;

  /* DataTypeConversion: '<S24>/Cast' */
  rtb_Cast_h = rtDW.timingsIndex;

  /* DataTypeConversion: '<S24>/Cast1' */
  rtb_Cast1_i = rtDW.timingsValue;

  /* Update for RateTransition: '<S24>/Rate Transition1' */
  rtDW.RateTransition1_Buffer0 = rtb_Cast_h;

  /* Update for RateTransition: '<S24>/Rate Transition' */
  rtDW.RateTransition_Buffer0 = rtb_Cast1_i;

  /* Update for RateTransition: '<S23>/Rate Transition1' */
  rtDW.RateTransition1_Buffer0_a = i;

  /* Update for RateTransition: '<S23>/Rate Transition' */
  rtDW.RateTransition_Buffer0_k = rtb_Cast1;

  /* Update for RateTransition: '<Root>/Rate Transition' incorporates:
   *  DataTypeConversion: '<Root>/Cast'
   */
  rtDW.RateTransition_Buffer0_b = (uint8_T)rtDW.currGear;

  /* Update for RateTransition: '<Root>/Rate Transition1' */
  rtDW.RateTransition1_Buffer[(rtDW.RateTransition1_ActiveBufIdx == 0) * 3] =
    rtDW.Assignment[0];
  rtDW.RateTransition1_Buffer[1 + (rtDW.RateTransition1_ActiveBufIdx == 0) * 3] =
    rtDW.Assignment[1];
  rtDW.RateTransition1_Buffer[2 + (rtDW.RateTransition1_ActiveBufIdx == 0) * 3] =
    rtDW.Assignment[2];
  rtDW.RateTransition1_ActiveBufIdx = (int8_T)(rtDW.RateTransition1_ActiveBufIdx
    == 0);

  /* Update for RateTransition: '<Root>/Rate Transition2' */
  rtDW.RateTransition2_Buffer[(rtDW.RateTransition2_ActiveBufIdx == 0) << 1] =
    rtDW.shiftCommand[0];
  rtDW.RateTransition2_Buffer[1 + ((rtDW.RateTransition2_ActiveBufIdx == 0) << 1)]
    = rtDW.shiftCommand[1];
  rtDW.RateTransition2_ActiveBufIdx = (int8_T)(rtDW.RateTransition2_ActiveBufIdx
    == 0);

  /* Update for RateTransition: '<Root>/Rate Transition3' */
  rtDW.RateTransition3_Buffer0 = rtDW.startEngCommand;

  /* Update for RateTransition: '<Root>/Rate Transition4' */
  rtDW.RateTransition4_Buffer[(rtDW.RateTransition4_ActiveBufIdx == 0) << 1] =
    rtDW.accCommand[0];
  rtDW.RateTransition4_Buffer[1 + ((rtDW.RateTransition4_ActiveBufIdx == 0) << 1)]
    = rtDW.accCommand[1];
  rtDW.RateTransition4_ActiveBufIdx = (int8_T)(rtDW.RateTransition4_ActiveBufIdx
    == 0);

  /* Update for RateTransition: '<Root>/Rate Transition5' */
  rtDW.RateTransition5_Buffer[(rtDW.RateTransition5_ActiveBufIdx == 0) << 1] =
    rtDW.clutchCommand[0];
  rtDW.RateTransition5_Buffer[1 + ((rtDW.RateTransition5_ActiveBufIdx == 0) << 1)]
    = rtDW.clutchCommand[1];
  rtDW.RateTransition5_ActiveBufIdx = (int8_T)(rtDW.RateTransition5_ActiveBufIdx
    == 0);

  /* Update for RateTransition: '<Root>/Rate Transition8' */
  rtDW.RateTransition8_Buffer[(rtDW.RateTransition8_ActiveBufIdx == 0) << 1] =
    rtDW.modeCommand[0];
  rtDW.RateTransition8_Buffer[1 + ((rtDW.RateTransition8_ActiveBufIdx == 0) << 1)]
    = rtDW.modeCommand[1];
  rtDW.RateTransition8_ActiveBufIdx = (int8_T)(rtDW.RateTransition8_ActiveBufIdx
    == 0);

  /* Update for RateTransition: '<S10>/Rate Transition' */
  rtDW.RateTransition_Buffer0_g = rtDW.Merge_i;
}

/* Model step function for TID3 */
void GCU_Model_genCode_step3(void)     /* Sample time: [0.001s, 0.0004s] */
{
  uint16_T rtb_RateTransition12;
  uint16_T rtb_RateTransition25;
  uint32_T rtb_RateTransition9[9];
  uint16_T rtb_RateTransition27;
  uint8_T rtb_RateTransition10;
  uint8_T rtb_RateTransition11;
  uint16_T rtb_RateTransition16;
  uint16_T rtb_RateTransition13;
  uint8_T rtb_RateTransition15;
  uint8_T rtb_RateTransition17;
  uint8_T rtb_RateTransition24;
  uint16_T rtb_RateTransition14[3];
  uint16_T Cast_n[9];
  int32_T i;
  int32_T i_0;
  uint16_T Cast_n_0;

  /* RateTransition: '<Root>/Rate Transition14' */
  rtDW.RateTransition14_semaphoreTaken = 1;
  rtb_RateTransition14[0] = rtDW.RateTransition14_Buffer0[0];
  rtb_RateTransition14[1] = rtDW.RateTransition14_Buffer0[1];
  rtb_RateTransition14[2] = rtDW.RateTransition14_Buffer0[2];
  rtDW.RateTransition14_semaphoreTaken = 0;

  /* RateTransition: '<Root>/Rate Transition12' */
  rtb_RateTransition12 = rtDW.tractionTarget;

  /* RateTransition: '<Root>/Rate Transition25' */
  rtb_RateTransition25 = rtDW.mapTarget;

  /* RateTransition: '<Root>/Rate Transition9' */
  i = rtDW.RateTransition9_ActiveBufIdx * 9;
  for (i_0 = 0; i_0 < 9; i_0++) {
    rtb_RateTransition9[i_0] = rtDW.RateTransition9_Buffer[i_0 + i];
  }

  /* End of RateTransition: '<Root>/Rate Transition9' */

  /* RateTransition: '<Root>/Rate Transition27' */
  rtb_RateTransition27 = rtDW.RateTransition27_Buffer0;

  /* RateTransition: '<Root>/Rate Transition10' */
  rtb_RateTransition10 = rtDW.Merge_j;

  /* RateTransition: '<Root>/Rate Transition11' */
  rtb_RateTransition11 = rtDW.clutchCurrVal;

  /* RateTransition: '<Root>/Rate Transition16' */
  rtb_RateTransition16 = rtDW.accFb;

  /* RateTransition: '<Root>/Rate Transition13' */
  rtb_RateTransition13 = rtDW.lastModeCom[1];

  /* RateTransition: '<Root>/Rate Transition15' */
  rtb_RateTransition15 = rtDW.Pin_In1;

  /* RateTransition: '<Root>/Rate Transition17' */
  rtb_RateTransition17 = rtDW.Pin_In2;

  /* RateTransition: '<Root>/Rate Transition24' */
  rtb_RateTransition24 = rtDW.Pin_H;

  /* S-Function (fcncallgen): '<Root>/Function_Call_Generator' incorporates:
   *  SubSystem: '<Root>/debugUART'
   */
  for (i = 0; i < 9; i++) {
    /* DataTypeConversion: '<S9>/Cast' */
    Cast_n_0 = (uint16_T)rtb_RateTransition9[i];

    /* SignalConversion: '<S9>/TmpSignal ConversionAtPack_Uart_MessageInport1' */
    rtDW.TmpSignalConversionAtPack_Uart_[i] = Cast_n_0;

    /* DataTypeConversion: '<S9>/Cast' */
    Cast_n[i] = Cast_n_0;
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtPack_Uart_MessageInport1' incorporates:
   *  DataTypeConversion: '<S9>/Cast1'
   *  DataTypeConversion: '<S9>/Cast10'
   *  DataTypeConversion: '<S9>/Cast11'
   *  DataTypeConversion: '<S9>/Cast2'
   *  DataTypeConversion: '<S9>/Cast3'
   *  DataTypeConversion: '<S9>/Cast4'
   *  DataTypeConversion: '<S9>/Cast5'
   *  DataTypeConversion: '<S9>/Cast6'
   *  DataTypeConversion: '<S9>/Cast7'
   *  DataTypeConversion: '<S9>/Cast8'
   *  DataTypeConversion: '<S9>/Cast9'
   */
  rtDW.TmpSignalConversionAtPack_Uart_[9] = rtb_RateTransition27;
  rtDW.TmpSignalConversionAtPack_Uart_[10] = rtb_RateTransition10;
  rtDW.TmpSignalConversionAtPack_Uart_[11] = rtb_RateTransition11;
  rtDW.TmpSignalConversionAtPack_Uart_[12] = rtb_RateTransition16;
  rtDW.TmpSignalConversionAtPack_Uart_[13] = rtb_RateTransition12;
  rtDW.TmpSignalConversionAtPack_Uart_[14] = rtb_RateTransition13;
  rtDW.TmpSignalConversionAtPack_Uart_[15] = rtb_RateTransition25;
  rtDW.TmpSignalConversionAtPack_Uart_[16] = rtb_RateTransition14[1];
  rtDW.TmpSignalConversionAtPack_Uart_[17] = rtb_RateTransition15;
  rtDW.TmpSignalConversionAtPack_Uart_[18] = rtb_RateTransition17;
  rtDW.TmpSignalConversionAtPack_Uart_[19] = rtb_RateTransition24;

  /* S-Function (PackUARTMsg): '<S9>/Pack_Uart_Message' */
  PackUARTMsg_Outputs_wrapper(&rtDW.TmpSignalConversionAtPack_Uart_[0],
    &rtDW.Pack_Uart_Message[0]);

  /* S-Function (sendUART): '<S9>/SendUART' */
  sendUART_Outputs_wrapper(&rtDW.Pack_Uart_Message[0]);

  /* End of Outputs for S-Function (fcncallgen): '<Root>/Function_Call_Generator' */

  /* Outport: '<Root>/debugValues  ' incorporates:
   *  DataTypeConversion: '<S9>/Cast1'
   *  DataTypeConversion: '<S9>/Cast10'
   *  DataTypeConversion: '<S9>/Cast11'
   *  DataTypeConversion: '<S9>/Cast2'
   *  DataTypeConversion: '<S9>/Cast3'
   *  DataTypeConversion: '<S9>/Cast4'
   *  DataTypeConversion: '<S9>/Cast5'
   *  DataTypeConversion: '<S9>/Cast6'
   *  DataTypeConversion: '<S9>/Cast7'
   *  DataTypeConversion: '<S9>/Cast8'
   *  DataTypeConversion: '<S9>/Cast9'
   */
  for (i = 0; i < 9; i++) {
    rtY.debugValues[i] = Cast_n[i];
  }

  /* S-Function (fcncallgen): '<Root>/Function_Call_Generator' incorporates:
   *  SubSystem: '<Root>/debugUART'
   */
  rtY.debugValues[9] = rtb_RateTransition27;
  rtY.debugValues[10] = rtb_RateTransition10;
  rtY.debugValues[11] = rtb_RateTransition11;
  rtY.debugValues[12] = rtb_RateTransition16;
  rtY.debugValues[13] = rtb_RateTransition12;
  rtY.debugValues[14] = rtb_RateTransition13;
  rtY.debugValues[15] = rtb_RateTransition25;
  rtY.debugValues[16] = rtb_RateTransition14[1];
  rtY.debugValues[17] = rtb_RateTransition15;
  rtY.debugValues[18] = rtb_RateTransition17;
  rtY.debugValues[19] = rtb_RateTransition24;

  /* End of Outport: '<Root>/debugValues  ' */
  /* End of Outputs for S-Function (fcncallgen): '<Root>/Function_Call_Generator' */
}

/* Model step function for TID4 */
void GCU_Model_genCode_step4(void)     /* Sample time: [0.001s, 0.0006s] */
{
  uint32_T Multiply[9];
  int32_T i;

  /* S-Function (fcncallgen): '<Root>/Function_Call_Generator1' incorporates:
   *  SubSystem: '<Root>/update_ADC_data'
   */
  /* S-Function (update_ADC_data): '<S11>/update_ADC_data' incorporates:
   *  Inport: '<Root>/adc_buffer'
   */
  update_ADC_data_Outputs_wrapper(&rtU.adc_buffer[0], &rtDW.update_ADC_data[0]);

  /* Product: '<S11>/Multiply' */
  for (i = 0; i < 9; i++) {
    Multiply[i] = rtDW.update_ADC_data[i];
  }

  /* End of Product: '<S11>/Multiply' */

  /* S-Function (Read_oil_sensor): '<S11>/Read_oil_sensor' */
  Read_oil_sensor_Outputs_wrapper(&rtDW.Read_oil_sensor);

  /* End of Outputs for S-Function (fcncallgen): '<Root>/Function_Call_Generator1' */

  /* RateTransition: '<Root>/Rate Transition18' */
  if (!(rtDW.RateTransition18_semaphoreTaken != 0)) {
    for (i = 0; i < 9; i++) {
      rtDW.RateTransition18_Buffer0[i] = Multiply[i];
    }
  }

  /* End of RateTransition: '<Root>/Rate Transition18' */

  /* Outport: '<Root>/adc_data_vector' */
  for (i = 0; i < 9; i++) {
    rtY.adc_data_vector[i] = Multiply[i];
  }

  /* End of Outport: '<Root>/adc_data_vector' */

  /* Update for RateTransition: '<Root>/Rate Transition9' */
  for (i = 0; i < 9; i++) {
    rtDW.RateTransition9_Buffer[i + (rtDW.RateTransition9_ActiveBufIdx == 0) * 9]
      = Multiply[i];
  }

  rtDW.RateTransition9_ActiveBufIdx = (int8_T)(rtDW.RateTransition9_ActiveBufIdx
    == 0);

  /* End of Update for RateTransition: '<Root>/Rate Transition9' */

  /* Update for RateTransition: '<Root>/Rate Transition27' */
  rtDW.RateTransition27_Buffer0 = rtDW.Read_oil_sensor;
}

/* Model step function for TID5 */
void GCU_Model_genCode_step5(void)     /* Sample time: [0.001s, 0.0008s] */
{
  uint32_T rtb_RateTransition18[9];
  uint8_T rtb_RateTransition19;
  uint8_T rtb_RateTransition20;
  int32_T i;
  uint16_T uDLookupTable2_tmp;

  /* RateTransition: '<Root>/Rate Transition22' */
  rtDW.RateTransition22 = rtDW.tractionTarget;

  /* RateTransition: '<Root>/Rate Transition26' */
  rtDW.RateTransition26 = rtDW.mapTarget;

  /* RateTransition: '<Root>/Rate Transition18' */
  rtDW.RateTransition18_semaphoreTaken = 1;
  for (i = 0; i < 9; i++) {
    rtb_RateTransition18[i] = rtDW.RateTransition18_Buffer0[i];
  }

  rtDW.RateTransition18_semaphoreTaken = 0;

  /* End of RateTransition: '<Root>/Rate Transition18' */

  /* RateTransition: '<Root>/Rate Transition19' */
  rtb_RateTransition19 = rtDW.Merge_j;

  /* RateTransition: '<Root>/Rate Transition20' */
  rtb_RateTransition20 = rtDW.clutchCurrVal;

  /* RateTransition: '<Root>/Rate Transition21' */
  rtDW.RateTransition21 = rtDW.accFb;

  /* RateTransition: '<Root>/Rate Transition23' */
  rtDW.RateTransition23 = rtDW.lastModeCom[1];

  /* RateTransition: '<Root>/Rate Transition28' */
  rtDW.RateTransition28 = rtDW.Read_oil_sensor;

  /* S-Function (fcncallgen): '<Root>/Function_Call_Generator2' incorporates:
   *  SubSystem: '<Root>/CAN_Send'
   */
  /* Chart: '<S1>/CAN_id' */
  rtDW.gcu_traction_limiter_loil_efi_i = (uint16_T)
    GCU_TRACTION_LIMITER_LOIL_EFI_ID;
  rtDW.gcu_clutch_mode_map_sw_id = (uint16_T)GCU_CLUTCH_MODE_MAP_SW_ID;
  rtDW.gcu_traction_limiter_autog_acc_ = (uint16_T)
    GCU_TRACTION_LIMITER_AUTOG_ACC_SW_ID;
  rtDW.gcu_debug_1_id = (uint16_T)GCU_DEBUG_1_ID;
  rtDW.gcu_debug_2_id = (uint16_T)GCU_DEBUG_2_ID;

  /* Lookup_n-D: '<S1>/1-D Lookup Table2' incorporates:
   *  Lookup_n-D: '<S1>/1-D Lookup Table1'
   */
  uDLookupTable2_tmp = look1_iu16lu64n48_binlcse(rtDW.RateTransition22,
    rtConstP.pooled4, rtConstP.pooled3, 7U);
  rtDW.uDLookupTable2 = uDLookupTable2_tmp;

  /* Lookup_n-D: '<S1>/1-D Lookup Table1' */
  rtDW.uDLookupTable1 = uDLookupTable2_tmp;

  /* Lookup_n-D: '<S1>/1-D Lookup Table3' incorporates:
   *  DataTypeConversion: '<S1>/Cast'
   */
  rtDW.uDLookupTable3 = look1_iu16lu64n48_binlcse(rtb_RateTransition19,
    rtConstP.pooled4, rtConstP.pooled3, 7U);

  /* S-Function (PackCANMsg): '<S13>/PackCANMsg' */
  PackCANMsg_Outputs_wrapper(&rtDW.uDLookupTable2, &rtDW.uDLookupTable1,
    &rtDW.uDLookupTable3, &rtDW.RateTransition28, &rtDW.PackCANMsg[0]);

  /* S-Function (sendCAN): '<S13>/sendCAN' */
  sendCAN_Outputs_wrapper(&rtDW.gcu_traction_limiter_loil_efi_i,
    &rtDW.PackCANMsg[0]);

  /* DataTypeConversion: '<S14>/Cast' */
  rtDW.Cast = rtb_RateTransition20;

  /* S-Function (PackCANMsg): '<S14>/PackCANMsg' incorporates:
   *  Constant: '<S1>/Constant'
   */
  PackCANMsg_Outputs_wrapper(&rtDW.Cast, &rtDW.RateTransition23,
    &rtDW.RateTransition26, &rtConstP.pooled5, &rtDW.PackCANMsg_l[0]);

  /* S-Function (sendCAN): '<S14>/sendCAN' */
  sendCAN_Outputs_wrapper(&rtDW.gcu_clutch_mode_map_sw_id, &rtDW.PackCANMsg_l[0]);

  /* DataTypeConversion: '<S15>/Cast1' */
  rtDW.Cast1 = rtb_RateTransition19;

  /* S-Function (PackCANMsg): '<S15>/PackCANMsg' */
  PackCANMsg_Outputs_wrapper(&rtDW.RateTransition22, &rtDW.Cast1, (uint16_T*)
    &GCU_Model_genCode_U16GND, &rtDW.RateTransition21, &rtDW.PackCANMsg_e[0]);

  /* S-Function (sendCAN): '<S15>/sendCAN' */
  sendCAN_Outputs_wrapper(&rtDW.gcu_traction_limiter_autog_acc_,
    &rtDW.PackCANMsg_e[0]);

  /* DataTypeConversion: '<S16>/Cast' */
  rtDW.Cast_d = (uint16_T)rtb_RateTransition18[4];

  /* DataTypeConversion: '<S16>/Cast1' */
  rtDW.Cast1_h = (uint16_T)rtb_RateTransition18[5];

  /* DataTypeConversion: '<S16>/Cast2' */
  rtDW.Cast2 = (uint16_T)rtb_RateTransition18[3];

  /* DataTypeConversion: '<S16>/Cast3' */
  rtDW.Cast3 = (uint16_T)rtb_RateTransition18[8];

  /* S-Function (PackCANMsg): '<S16>/PackCANMsg' */
  PackCANMsg_Outputs_wrapper(&rtDW.Cast_d, &rtDW.Cast1_h, &rtDW.Cast2,
    &rtDW.Cast3, &rtDW.PackCANMsg_f[0]);

  /* S-Function (sendCAN): '<S16>/sendCAN' */
  sendCAN_Outputs_wrapper(&rtDW.gcu_debug_1_id, &rtDW.PackCANMsg_f[0]);

  /* DataTypeConversion: '<S17>/Cast' */
  rtDW.Cast_o = (uint16_T)rtb_RateTransition18[6];

  /* DataTypeConversion: '<S17>/Cast1' */
  rtDW.Cast1_c = (uint16_T)rtb_RateTransition18[0];

  /* DataTypeConversion: '<S17>/Cast2' */
  rtDW.Cast2_e = (uint16_T)rtb_RateTransition18[1];

  /* DataTypeConversion: '<S17>/Cast3' */
  rtDW.Cast3_j = (uint16_T)rtb_RateTransition18[2];

  /* S-Function (PackCANMsg): '<S17>/PackCANMsg' */
  PackCANMsg_Outputs_wrapper(&rtDW.Cast_o, &rtDW.Cast1_c, &rtDW.Cast2_e,
    &rtDW.Cast3_j, &rtDW.PackCANMsg_o[0]);

  /* S-Function (sendCAN): '<S17>/sendCAN' */
  sendCAN_Outputs_wrapper(&rtDW.gcu_debug_2_id, &rtDW.PackCANMsg_o[0]);

  /* End of Outputs for S-Function (fcncallgen): '<Root>/Function_Call_Generator2' */
}

/* Model step function for TID6 */
void GCU_Model_genCode_step6(void)     /* Sample time: [0.001s, 0.0009s] */
{
  eepromRequest BusConversion_InsertedFor_EEPRO;
  int32_T i;

  /* BusCreator: '<S2>/BusConversion_InsertedFor_EEPROM_Load_Buffer_at_inport_0' incorporates:
   *  Inport: '<Root>/inputRequest'
   */
  BusConversion_InsertedFor_EEPRO.operation = rtU.inputRequest[0];
  BusConversion_InsertedFor_EEPRO.page = rtU.inputRequest[1];
  BusConversion_InsertedFor_EEPRO.cell = rtU.inputRequest[2];
  BusConversion_InsertedFor_EEPRO.dataSize = rtU.inputRequest[3];
  for (i = 0; i < 16; i++) {
    BusConversion_InsertedFor_EEPRO.data[i] = rtU.inputRequest[i + 4];
  }

  /* End of BusCreator: '<S2>/BusConversion_InsertedFor_EEPROM_Load_Buffer_at_inport_0' */

  /* S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
   *  Chart: '<S2>/EEPROM_Load_Buffer'
   */
  /* Chart: '<S2>/EEPROM_Load_Buffer' */
  updateBuffer(&BusConversion_InsertedFor_EEPRO);

  /* End of Outputs for S-Function (fcncallgen): '<Root>/Function-Call Generator' */

  /* Update for RateTransition: '<S2>/TmpRTBAtEEPROM_Load_BufferOutport1' */
  for (i = 0; i < 20; i++) {
    rtDW.TmpRTBAtEEPROM_Load_BufferOutpo[i +
      (rtDW.TmpRTBAtEEPROM_Load_BufferOut_g == 0) * 20] = rtDW.requestBuffer[i];
  }

  rtDW.TmpRTBAtEEPROM_Load_BufferOut_g = (int8_T)
    (rtDW.TmpRTBAtEEPROM_Load_BufferOut_g == 0);

  /* End of Update for RateTransition: '<S2>/TmpRTBAtEEPROM_Load_BufferOutport1' */

  /* Update for RateTransition: '<S2>/TmpRTBAtEEPROM_Load_BufferOutport2' */
  rtDW.TmpRTBAtEEPROM_Load_BufferOut_l = rtDW.lastInsertedIndex;
}

/* Model initialize function */
void GCU_Model_genCode_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtsiSetSolverName(&rtM->solverInfo,"FixedStepDiscrete");
  rtM->solverInfoPtr = (&rtM->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = rtM->Timing.sampleTimeTaskIDArray;
    int_T i;
    for (i = 0; i < 7; i++) {
      mdlTsMap[i] = i;
    }

    rtM->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    rtM->Timing.sampleTimes = (&rtM->Timing.sampleTimesArray[0]);
    rtM->Timing.offsetTimes = (&rtM->Timing.offsetTimesArray[0]);

    /* task periods */
    rtM->Timing.sampleTimes[0] = (9.9999999999999991E-5);
    rtM->Timing.sampleTimes[1] = (0.001);
    rtM->Timing.sampleTimes[2] = (0.001);
    rtM->Timing.sampleTimes[3] = (0.001);
    rtM->Timing.sampleTimes[4] = (0.001);
    rtM->Timing.sampleTimes[5] = (0.001);
    rtM->Timing.sampleTimes[6] = (0.001);

    /* task offsets */
    rtM->Timing.offsetTimes[0] = (0.0);
    rtM->Timing.offsetTimes[1] = (0.0);
    rtM->Timing.offsetTimes[2] = (0.0002);
    rtM->Timing.offsetTimes[3] = (0.0004);
    rtM->Timing.offsetTimes[4] = (0.0006);
    rtM->Timing.offsetTimes[5] = (0.0008);
    rtM->Timing.offsetTimes[6] = (0.0009);
  }

  rtmSetTPtr(rtM, &rtM->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = rtM->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = rtM->Timing.perTaskSampleHitsArray;
    rtM->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    rtM->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(rtM, -1);
  rtM->Timing.stepSize1 = 0.001;

  /* initialize sample time offsets */
  /* initialize sample time offsets */
  /* initialize sample time offsets */
  /* initialize sample time offsets */
  /* initialize sample time offsets */
  rtM->solverInfoPtr = (&rtM->solverInfo);
  rtM->Timing.stepSize = (9.9999999999999991E-5);
  rtsiSetFixedStepSize(&rtM->solverInfo, 9.9999999999999991E-5);
  rtsiSetSolverMode(&rtM->solverInfo, SOLVER_MODE_MULTITASKING);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &rtM->NonInlinedSFcns.sfcnInfo;
    rtM->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, ((const char_T **)(&rtmGetErrorStatus(rtM))));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &rtM->Sizes.numSampTimes);
    rtM->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(rtM)[0]);
    rtM->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(rtM)[1]);
    rtM->NonInlinedSFcns.taskTimePtrs[2] = &(rtmGetTPtr(rtM)[2]);
    rtM->NonInlinedSFcns.taskTimePtrs[3] = &(rtmGetTPtr(rtM)[3]);
    rtM->NonInlinedSFcns.taskTimePtrs[4] = &(rtmGetTPtr(rtM)[4]);
    rtM->NonInlinedSFcns.taskTimePtrs[5] = &(rtmGetTPtr(rtM)[5]);
    rtM->NonInlinedSFcns.taskTimePtrs[6] = &(rtmGetTPtr(rtM)[6]);
    rtM->NonInlinedSFcns.taskTimePtrs[7] = &(rtmGetTPtr(rtM)[7]);
    rtssSetTPtrPtr(sfcnInfo,rtM->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(rtM));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(rtM));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(rtM));
    rtssSetStepSizePtr(sfcnInfo, &rtM->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(rtM));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo, &rtM->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &rtM->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &rtM->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &rtM->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &rtM->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &rtM->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &rtM->solverInfoPtr);
  }

  rtM->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)&rtM->NonInlinedSFcns.childSFunctions[0], 0,
                  1*sizeof(SimStruct));
    rtM->childSfunctions = (&rtM->NonInlinedSFcns.childSFunctionPtrs[0]);
    rtM->childSfunctions[0] = (&rtM->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: GCU_Model_genCode/<S22>/Eeprom_write (Eeprom_write) */
    {
      SimStruct *rts = rtM->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = rtM->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = rtM->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = rtM->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &rtM->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts, &rtM->
        NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &rtM->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &rtM->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &rtM->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &rtM->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts, &rtM->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 4);
        ssSetPortInfoForInputs(rts, &rtM->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &rtM->NonInlinedSFcns.Sfcn0.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        ssSetInputPortUnit(rts, 2, 0);
        ssSetInputPortUnit(rts, 3, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &rtM->NonInlinedSFcns.Sfcn0.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);
        ssSetInputPortIsContinuousQuantity(rts, 2, 0);
        ssSetInputPortIsContinuousQuantity(rts, 3, 0);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &rtDW.outputRequest.page);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &rtDW.outputRequest.cell);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          ssSetInputPortRequiredContiguous(rts, 2, 1);
          ssSetInputPortSignal(rts, 2, &rtDW.outputRequest.dataSize);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          int_T *dimensions = (int_T *) &rtM->NonInlinedSFcns.Sfcn0.iDims3;
          ssSetInputPortRequiredContiguous(rts, 3, 1);
          ssSetInputPortSignal(rts, 3, rtDW.outputRequest.data);
          dimensions[0] = 1;
          dimensions[1] = 16;
          _ssSetInputPortDimensionsPtr(rts, 3, dimensions);
          _ssSetInputPortNumDimensions(rts, 3, 2);
          ssSetInputPortWidth(rts, 3, 16);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts, &rtM->NonInlinedSFcns.Sfcn0.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 2);
        _ssSetPortInfo2ForOutputUnits(rts,
          &rtM->NonInlinedSFcns.Sfcn0.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &rtM->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *) &rtDW.Eeprom_write_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((uint8_T *) &rtDW.Eeprom_write_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "Eeprom_write");
      ssSetPath(rts,
                "GCU_Model_genCode/EEPROM/Evaluate_Request/Write/Eeprom_write");
      ssSetRTModel(rts,rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* registration */
      Eeprom_write(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetInputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
      ssSetInputPortBufferDstPort(rts, 3, -1);
    }
  }

  {
    int32_T i;

    /* SetupRuntimeResources for Atomic SubSystem: '<Root>/GCU_timer' */

    /* SetupRuntimeResources for Chart: '<S5>/GCULogic' incorporates:
     *  Chart: '<S2>/EEPROM_OutputRequest'
     */
    /* SetupRuntimeResources for Chart: '<S2>/EEPROM_OutputRequest' incorporates:
     *  SubSystem: '<S2>/Evaluate_Request'
     */

    /* End of SetupRuntimeResources for SubSystem: '<Root>/GCU_timer' */

    /* Start for Atomic SubSystem: '<Root>/GCU_timer' */

    /* Start for Chart: '<S5>/GCULogic' incorporates:
     *  Chart: '<S2>/EEPROM_OutputRequest'
     */
    /* Start for Chart: '<S2>/EEPROM_OutputRequest' incorporates:
     *  SubSystem: '<S2>/Evaluate_Request'
     */

    /* Start for IfAction SubSystem: '<S20>/Write' */

    /* Start for S-Function (Eeprom_write): '<S22>/Eeprom_write' */
    /* Level2 S-Function Block: '<S22>/Eeprom_write' (Eeprom_write) */
    {
      SimStruct *rts = rtM->childSfunctions[0];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* End of Start for SubSystem: '<S20>/Write' */

    /* End of Start for SubSystem: '<Root>/GCU_timer' */
    rtPrevZCX._Trig_ZCE_i[0] = UNINITIALIZED_ZCSIG;
    rtPrevZCX._Trig_ZCE[0] = UNINITIALIZED_ZCSIG;
    rtPrevZCX._Trig_ZCE_i[1] = UNINITIALIZED_ZCSIG;
    rtPrevZCX._Trig_ZCE[1] = UNINITIALIZED_ZCSIG;
    rtPrevZCX.Triggered_Subsystem_Trig_ZCE = UNINITIALIZED_ZCSIG;
    rtPrevZCX.Triggered_Subsystem1_Trig_ZCE = UNINITIALIZED_ZCSIG;

    /* SystemInitialize for Triggered SubSystem: '<S24>/Triggered Subsystem' */
    for (i = 0; i < 23; i++) {
      rtPrevZCX.TriggeredSubsystem_Trig_ZCE[i] = ZERO_ZCSIG;
    }

    /* End of SystemInitialize for SubSystem: '<S24>/Triggered Subsystem' */

    /* SystemInitialize for Triggered SubSystem: '<S23>/Triggered Subsystem' */
    /* SystemInitialize for Merge: '<S23>/Merge' */
    for (i = 0; i < 12; i++) {
      rtPrevZCX.TriggeredSubsystem_Trig_ZCE_j[i] = ZERO_ZCSIG;
    }

    /* End of SystemInitialize for Merge: '<S23>/Merge' */
    /* End of SystemInitialize for SubSystem: '<S23>/Triggered Subsystem' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/GCU_timer' */
    rtDW.sfEvent = -1;

    /* SystemInitialize for Chart: '<S5>/GCULogic' incorporates:
     *  Chart: '<S2>/EEPROM_OutputRequest'
     */
    /* SystemInitialize for Chart: '<S2>/EEPROM_OutputRequest' */
    rtDW.lastEvaluatedIndex = 1.0;

    /* End of SystemInitialize for SubSystem: '<Root>/GCU_timer' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Simulink_Debug' */
    /* Chart: '<S7>/AccelerationRoutine' */
    rtDW.is_c3_GCU_Model_genCode = IN_Wait;

    /* End of SystemInitialize for SubSystem: '<Root>/Simulink_Debug' */

    /* SystemInitialize for S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
     *  Chart: '<S2>/EEPROM_Load_Buffer'
     */
    /* SystemInitialize for Chart: '<S2>/EEPROM_Load_Buffer' */
    rtDW.lastInsertedIndex = 1.0;

    /* End of SystemInitialize for S-Function (fcncallgen): '<Root>/Function-Call Generator' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/InitializeFunction' */

    /* S-Function (load_accParameters): '<S6>/load_accParameters' */
    load_accParameters_Outputs_wrapper(&rtDW.load_accParameters[0]);

    /* S-Function (load_default_timings): '<S6>/load_default_timings' */
    load_default_timings_Outputs_wrapper(&rtDW.load_default_timings[0]);

    /* S-Function (CAN_Load_id): '<S6>/CAN_Load_id' */
    CAN_Load_id_Outputs_wrapper(&rtDW.CAN_Load_id[0]);

    /* S-Function (Eeprom_init): '<S6>/Eeprom_init' */
    Eeprom_init_Outputs_wrapper(&rtDW.Eeprom_init_o1, &rtDW.Eeprom_init_o2,
      &rtDW.Eeprom_init_o3);

    /* S-Function (CAN_Start): '<S6>/CAN_Start' */
    CAN_Start_Outputs_wrapper();

    /* S-Function (ClutchMotor_init): '<S6>/ClutchMotor Init' */
    ClutchMotor_init_Outputs_wrapper();

    /* S-Function (Efi_init): '<S6>/Efi Init' */
    Efi_init_Outputs_wrapper();

    /* S-Function (GearMotor_init): '<S6>/GearMotor Init' */
    GearMotor_init_Outputs_wrapper();

    /* S-Function (InitTimer): '<S6>/InitTimer' */
    InitTimer_Outputs_wrapper();

    /* S-Function (InitUART): '<S6>/InitUART' */
    InitUART_Outputs_wrapper();

    /* S-Function (ScanADC): '<S6>/ScanADC' */
    ScanADC_Outputs_wrapper();

    /* End of SystemInitialize for SubSystem: '<Root>/InitializeFunction' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
