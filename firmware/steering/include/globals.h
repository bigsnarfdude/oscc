/**
 * @file globals.h
 * @brief Module globals.
 *
 */


#ifndef _KIA_SOUL_STEERING_GLOBALS_H_
#define _KIA_SOUL_STEERING_GLOBALS_H_


#include "DAC_MCP49xx.h"
#include "mcp_can.h"

#include "steering_control.h"


/*
 * @brief Chip select pin of the DAC IC.
 *
 */
#define PIN_DAC_CHIP_SELECT ( 9 )

/*
 * @brief Chip select pin of the CAN IC.
 *
 */
#define PIN_CAN_CHIP_SELECT ( 10 )

/*
 * @brief High signal pin of the torque sensor.
 *
 */
#define PIN_TORQUE_SENSOR_HIGH ( A0 )

/*
 * @brief Low signal pin of the torque sensor.
 *
 */
#define PIN_TORQUE_SENSOR_LOW ( A1 )

/*
 * @brief High signal pin of the torque spoof output.
 *
 */
#define PIN_TORQUE_SPOOF_HIGH ( A2 )

/*
 * @brief Low signal pin of the torque spoof output.
 *
 */
#define PIN_TORQUE_SPOOF_LOW ( A3 )

/*
 * @brief Relay enable pin for the spoof output.
 *
 */
#define PIN_SPOOF_ENABLE ( 6 )


#ifdef GLOBAL_DEFINED
    DAC_MCP49xx g_dac( DAC_MCP49xx::MCP4922, PIN_DAC_CHIP_SELECT );
    MCP_CAN g_control_can( PIN_CAN_CHIP_SELECT );

    #define EXTERN
#else
    extern DAC_MCP49xx g_dac;
    extern MCP_CAN g_control_can;

    #define EXTERN extern
#endif


EXTERN volatile bool g_steering_command_timeout;

EXTERN volatile steering_control_state_s g_steering_control_state;


#endif
