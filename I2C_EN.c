/*
 * I2C_EN.c
 *
 *  Created on: Sep 23, 2022
 *      Author: a0498597
 */

#include <I2C_EN.h>
#include <stdio.h>
#include <stdint.h>
#include "ti_msp_dl_config.h"
#include "i2c.h"

/* Timer configuration */
//#define CPU_F ((double)48000000)
//#define delay_us(x) delay_cycles((long)(CPU_F*(double)x/1000000.0))
//#define delay_ms(x) delay_cycles((long)(CPU_F*(double)x/1000.0))

/***************************************************************************//**
 *Slave Address
 ******************************************************************************/
/* Slave Address for I2C Slave */
#define SLAVE_ADDRESS  0x1B //slave address for Broadcast
#define SLAVE_ADDRESS1 0x14 //slave address for U1
#define SLAVE_ADDRESS2 0x15 //slave address for U2
#define SLAVE_ADDRESS3 0x16 //slave address for U3
#define SLAVE_ADDRESS4 0x17 //slave address for U4

/***************************************************************************//**
 *Register Address
 ******************************************************************************/
/* Device Configuration Register Address*/
#define Chip_Enable_Register               0x000
#define Dev_Config0_Register               0x001//Max Current Sink Current & Boost Output Voltage
#define Dev_Config1_Register               0x002//Direct Connected Outputs(Only effective when configured to Mix Drive Mode) & LED Configuration & PWM Dimming Frequency Setting
#define Dev_Config2_Register               0x003//Scan Line FET Number in Matrix Mode
#define Dev_Config3_Register               0x004//LED Autonomous Control Enable
#define Dev_Config4_Register               0x005//LED Autonomous Control Enable
#define Dev_Config5_Register               0x006//LED Exponential Dimming Curve Enable
#define Dev_Config6_Register               0x007//LED Exponential Dimming Curve Enable
#define Dev_Config7_Register               0x008//PWM Phase Align Method
#define Dev_Config8_Register               0x009//PWM Phase Align Method
#define Dev_Config9_Register               0x00A//PWM Phase Align Method
#define Dev_Config10_Register              0x00B//PWM Phase Align Method
#define Dev_Config11_Register              0x00C//Line Change Time & Vsync setting
#define Dev_Config12_Register              0x00D//LSD Fault Comparator Threshold & Action When LSD/LOD & Clamp Behavior setting

/*Command registers*/
#define Update_CMD_REG                     0x010 //Write 55h to send this command
#define Start_CMD_REG                      0x011 //Write FFh to send this command
#define Stop_CMD_REG                       0x012 //Write AAh to send this command
#define Pause_CMD_REG                      0x013 //Write 33h to send this command
#define Continue_CMD_REG                   0x014 //Write CCh to send this command

/*LED_EN Registers*/
#define LED_EN1                            0x020
#define LED_EN2                            0x021

/*FAULT_CLEAR REGISTERS*/
#define Fault_CLR_REG                      0x022

/*RESET REGISTERS*/
#define RESET_REG                          0x023


/*MANUAL_DC REGISTERS*/
/*LED0/LED1/LED2/LED3/LED_A0/LED_A1/LED_A2/LED_B0/LED_B1/LED_B2/LED_C0/LED_C1/LED_C2/LED_D0/LED_D1/LED_D2/ */
#define Manual_DC_GAP                      0x001
#define Manual_DC_START                    0x030


/*MANUAL_PWM REGISTERS*/
/*LED0/LED1/LED2/LED3/LED_A0/LED_A1/LED_A2/LED_B0/LED_B1/LED_B2/LED_C0/LED_C1/LED_C2/LED_D0/LED_D1/LED_D2/ */
#define Manual_PWM_GAP                      0x001
#define Manual_PWM_START                    0x040


/*MANUAL_DC REGISTERS*/
/*LED0/LED1/LED2/LED3/LED_A0/LED_A1/LED_A2/LED_B0/LED_B1/LED_B2/LED_C0/LED_C1/LED_C2/LED_D0/LED_D1/LED_D2/ */
#define Auto_DC_GAP                         0x001
#define Auto_DC_START                       0x050


/*AUTONOMOUS CONTROL REGISTERS*/
/*LED0/LED1/LED2/LED3/LED_A0/LED_A1/LED_A2/LED_B0/LED_B1/LED_B2/LED_C0/LED_C1/LED_C2/LED_D0/LED_D1/LED_D2/ */
#define LED_AEU_GAP                         0x01A
#define AEU_GAP                             0x008

#define LED0_Pause_Time                     0x080
#define LED0_Playback_Time                  0x081
#define LED0_AEU1_PWM1                      0x082
#define LED0_AEU1_PWM2                      0x083
#define LED0_AEU1_PWM3                      0x084
#define LED0_AEU1_PWM4                      0x085
#define LED0_AEU1_PWM5                      0x086
#define LED0_AEU1_SlOPE_TIME1               0x087
#define LED0_AEU1_SlOPE_TIME2               0x088
#define LED0_AEU1_PT1                       0x089
#define LED0_AEU2_PWM1                      0x08A
#define LED0_AEU2_PWM2                      0x08B
#define LED0_AEU2_PWM3                      0x08C
#define LED0_AEU2_PWM4                      0x08D
#define LED0_AEU2_PWM5                      0x08E
#define LED0_AEU2_SlOPE_TIME1               0x08F
#define LED0_AEU2_SlOPE_TIME2               0x090
#define LED0_AEU2_PT1                       0x091
#define LED0_AEU3_PWM1                      0x092
#define LED0_AEU3_PWM2                      0x093
#define LED0_AEU3_PWM3                      0x094
#define LED0_AEU3_PWM4                      0x095
#define LED0_AEU3_PWM5                      0x096
#define LED0_AEU3_SlOPE_TIME1               0x097
#define LED0_AEU3_SlOPE_TIME2               0x098
#define LED0_AEU3_PT1                       0x099

/* FLAG Register Address*/
#define TSD_CONFIG_STATUS                   0x300
#define LOD_STATUS1                         0x301
#define LOD_STATUS2                         0x302
#define LSD_STATUS1                         0x303
#define LSD_STATUS2                         0x304

/* TEST Register Address*/
#define OTP_CONFIG_Register                 0x352
#define SRAM_CONFIG_Register                0x353
#define CLOCK_GATING_EN_Register            0x354


/***************************************************************************//**
 *Register Value
 ******************************************************************************/
#define Chip_Disable                       0x00
#define Chip_Enable                        0x01


#define LOD_Clear_EN                       0x01
#define LSD_Clear_EN                       0x02
#define Reset_En                           0x66


#define LED0                               0x00
#define LED1                               0x01
#define LED2                               0x02
#define LED3                               0x03
#define LED_A0                             0x04
#define LED_A1                             0x05
#define LED_A2                             0x06
#define LED_B0                             0x07
#define LED_B1                             0x08
#define LED_B2                             0x09
#define LED_C0                             0x0A
#define LED_C1                             0x0B
#define LED_C2                             0x0C
#define LED_D0                             0x0D
#define LED_D1                             0x0E
#define LED_D2                             0x0F

#define LED_A                              0x04
#define LED_B                              0x07
#define LED_C                              0x0A
#define LED_D                              0x0D

#define Update_CMD_Value                   0x55 //Write 55h to send this command
#define Start_CMD_Value                    0xFF //Write FFh to send this command
#define Stop_CMD_Value                     0xAA //Write AAh to send this command
#define Pause_CMD_Value                    0x33 //Write 33h to send this command
#define Continue_CMD_Value                 0xCC //Write CCh to send this command

#define AEU1                               0x00
#define AEU2                               0x01
#define AEU3                               0x02




/***************************************************************************//**
 * @brief  Initialize GPIO for I2C
 * @param  none
 * @return none
 ******************************************************************************/


uint8_t I2C_LP581X_5BIT_ADDRESS;

void I2C_setSlave(uint16_t slaveAdr_5bit, uint16_t regAdr_10bit)
{
    I2C_LP581X_5BIT_ADDRESS = (uint8_t) slaveAdr_5bit;
}

// This function writes data to a register on the slave device
void I2C_write(uint16_t regAdr_10bit, uint8_t data)
{
        /*set slave address*/
        uint8_t I2C_TARGET_ADDRESS;
        I2C_TARGET_ADDRESS = (I2C_LP581X_5BIT_ADDRESS<<2) + (regAdr_10bit>>8);

        /* Transfer data format to I2C standard*/
        uint8_t regAdr_8bit = (uint8_t) regAdr_10bit;
        struct I2cDevice dev;
        int rc;

        /*
         * Set the I2C bus filename and slave address,
         */
        dev.filename = "/dev/i2c-3";
        dev.addr = I2C_TARGET_ADDRESS;

        /*
         * Start the I2C device.
         */
        rc = i2c_start(&dev);
        if (rc) {
                printf("failed to start i2c device\r\n");
                //return rc;
        }
        rc = i2c_write_reg(&dev, reg_Adr_8bit, data);
        if (rc <= 0) {
                printf("failed to write to i2c device\r\n");
                //return rc;
        }
#if 0
    /* Set up the TX packet with the register address */
    uint8_t gTxPacket[8] = {0};
    gTxPacket[0] = regAdr_8bit;

    /* Set up the data to be written */
    gTxPacket[1] = data;

    //DL_I2C_flushControllerTXFIFO(I2C_INST);

    DL_I2C_fillControllerTXFIFO(I2C_INST, &gTxPacket[0], 2);

    /* Ensure I2C is idle before starting the transaction */
    while (!(DL_I2C_getControllerStatus(I2C_INST) & DL_I2C_CONTROLLER_STATUS_IDLE))
        ;

    /* Start the write operation */
    DL_I2C_startControllerTransfer(I2C_INST, I2C_TARGET_ADDRESS,
        DL_I2C_CONTROLLER_DIRECTION_TX, 2);

    /* Wait until the transaction is completed */
    while (DL_I2C_getControllerStatus(I2C_INST) &
           DL_I2C_CONTROLLER_STATUS_BUSY_BUS)
        ;

    //DL_I2C_flushControllerTXFIFO(I2C_INST);

    /* Check for errors */
    if (DL_I2C_getControllerStatus(I2C_INST) &
        DL_I2C_CONTROLLER_STATUS_ERROR) {
        // An error occurred, insert error handling code here
        __BKPT(0);
    }
#endif
}






