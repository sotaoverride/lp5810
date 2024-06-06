#include <I2C_EN.h>
#include <LP5813.h>
/* Standard Includes */
#include <stdint.h>
#include <stdbool.h>
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
 *Function Definition
 ******************************************************************************/

extern uint8_t I2C_LP581X_5BIT_ADDRESS;



/* Set Chip_EN=0 to enter STANDBY mode */
void Chip_Standby()
{
    I2C_setSlave (SLAVE_ADDRESS,
                  Chip_Enable_Register);
    I2C_write (Chip_Enable_Register,
               Chip_Disable);
}

/* Set Chip_EN=1 to enter NORMAL mode */
void Chip_Normal()
{
    I2C_setSlave (SLAVE_ADDRESS,
                  Chip_Enable_Register);
    I2C_write (Chip_Enable_Register,
               Chip_Enable);
}

/* LP5813 Function for Boost Module*/

void BOOST_Disable_EN()
{
    //DL_GPIO_clearPins(GPIOA, BOOST_BOOST_ENBALE_PIN);
}

void BOOST_Enable_EN()
{
    //DL_GPIO_setPins(GPIOA, BOOST_BOOST_ENBALE_PIN);
}

/* Set up device configuration 0 */
void Device_Configuration_0(uint8_t boost_vout,
                            uint8_t max_current)
{
    int Device_Configuration_0_Value;
    Device_Configuration_0_Value = (boost_vout<<1) + max_current;

    I2C_setSlave (SLAVE_ADDRESS,
                  Dev_Config0_Register);
    I2C_write (Dev_Config0_Register,
               Device_Configuration_0_Value);
}

/* Set up device configuration 1 */
void Device_Configuration_1(uint8_t pwm_freq,
                            uint8_t led_config,
                            uint8_t mix_sel_led)
{
    int Device_Configuration_1_Value;
    Device_Configuration_1_Value = (pwm_freq<<7) + (led_config<<4) + mix_sel_led;

    I2C_setSlave (SLAVE_ADDRESS,
                  Dev_Config1_Register);
    I2C_write (Dev_Config1_Register,
               Device_Configuration_1_Value);
}

/* Set up device configuration 2 */
void Device_Configuration_2(uint8_t scan_order3,
                            uint8_t scan_order2,
                            uint8_t scan_order1,
                            uint8_t scan_order0)
{
    int Device_Configuration_2_Value;
    Device_Configuration_2_Value = (scan_order3<<6) + (scan_order2<<4) + (scan_order1<<2) + scan_order0;

    I2C_setSlave (SLAVE_ADDRESS,
                  Dev_Config2_Register);
    I2C_write (Dev_Config2_Register,
               Device_Configuration_2_Value);
}

void Device_Configuration_11(uint8_t vsync_out_en,//0h = Vsync is input, 1h = Vsync is output
                            uint8_t blank_time)
{
    int Device_Configuration_11_Value;
    Device_Configuration_11_Value = (vsync_out_en<<2) + blank_time;

    I2C_setSlave (SLAVE_ADDRESS,
                  Dev_Config11_Register);
    I2C_write (Dev_Config11_Register,
               Device_Configuration_11_Value);
}

void Device_Configuration_12(uint8_t vmid_sel,
                            uint8_t clamp_sel,
                            uint8_t clamp_dis,
                            uint8_t lod_action,
                            uint8_t lsd_action,
                            uint8_t lsd_threshold)
{
    int Device_Configuration_12_Value;
    Device_Configuration_12_Value = (vmid_sel<<6) + (clamp_sel<<5) + (clamp_dis<<4) + (lod_action<<3) + (lsd_action<<2) + lsd_threshold;

    I2C_setSlave (SLAVE_ADDRESS,
                  Dev_Config12_Register);
    I2C_write (Dev_Config12_Register,
               Device_Configuration_12_Value);
}


void Update_CMD()
{
    I2C_setSlave (SLAVE_ADDRESS,
                  Update_CMD_REG);
    I2C_write (Update_CMD_REG,
               Update_CMD_Value);
}

void Start_CMD()
{
    I2C_setSlave (SLAVE_ADDRESS,
                  Start_CMD_REG);
    I2C_write (Start_CMD_REG,
               Start_CMD_Value);
}

void Stop_CMD()
{
    I2C_setSlave (SLAVE_ADDRESS,
                  Stop_CMD_REG);
    I2C_write (Stop_CMD_REG,
               Stop_CMD_Value);
}

void Pause_CMD()
{
    I2C_setSlave (SLAVE_ADDRESS,
                  Pause_CMD_REG);
    I2C_write (Pause_CMD_REG,
               Pause_CMD_Value);
}

void Continue_CMD()
{
    I2C_setSlave (SLAVE_ADDRESS,
                  Continue_CMD_REG);
    I2C_write (Continue_CMD_REG,
               204);
}

void LED_DIRECT_EN()
{
    I2C_setSlave (SLAVE_ADDRESS,
                  LED_EN1);
    I2C_write (LED_EN1,
               15);
}

void LED_MATRIX_EN()
{
    I2C_setSlave (SLAVE_ADDRESS,
                  LED_EN1);
    I2C_write (LED_EN1,
               240);
    I2C_setSlave (SLAVE_ADDRESS,
                  LED_EN2);
    I2C_write (LED_EN2,
               255);
}

void AUTO_DIRECT_EN()
{
    I2C_setSlave (SLAVE_ADDRESS,
                  Dev_Config3_Register);
    I2C_write (Dev_Config3_Register,
               15);
}

void AUTO_MATRIX_EN()
{
    I2C_setSlave (SLAVE_ADDRESS,
                  Dev_Config3_Register);
    I2C_write (Dev_Config3_Register,
               240);
    I2C_setSlave (SLAVE_ADDRESS,
                  Dev_Config4_Register);
    I2C_write (Dev_Config4_Register,
               255);
}

void AUTO_DISABLE() //default
{
    I2C_setSlave (SLAVE_ADDRESS,
                  Dev_Config3_Register);
    I2C_write (Dev_Config3_Register,
               0);
    I2C_setSlave (SLAVE_ADDRESS,
                  Dev_Config4_Register);
    I2C_write (Dev_Config4_Register,
               0);
}

void EXP_DIM_DIRECT_EN()
{
    I2C_setSlave (SLAVE_ADDRESS,
                  Dev_Config5_Register);
    I2C_write (Dev_Config5_Register,
               15);
}

void EXP_DIM_MATRIX_EN()
{
    I2C_setSlave (SLAVE_ADDRESS,
                  Dev_Config5_Register);
    I2C_write (Dev_Config5_Register,
               240);
    I2C_setSlave (SLAVE_ADDRESS,
                  Dev_Config6_Register);
    I2C_write (Dev_Config6_Register,
               255);
}

void EXP_DIM_DISABLE()
{
    I2C_setSlave (SLAVE_ADDRESS,
                  Dev_Config5_Register);
    I2C_write (Dev_Config5_Register,
               0);
    I2C_setSlave (SLAVE_ADDRESS,
                  Dev_Config6_Register);
    I2C_write (Dev_Config6_Register,
               0);
}

void Reset()
{
    I2C_setSlave (SLAVE_ADDRESS,
                  RESET_REG);
    I2C_write (RESET_REG,
               Reset_En);
}

/* Clear LOD flags */
void LOD_Clear()
{
    I2C_setSlave (SLAVE_ADDRESS,
                  Fault_CLR_REG);
    I2C_write (Fault_CLR_REG,
               LOD_Clear_EN);
}

/* Clear LSD flags */
void LSD_Clear()
{
    I2C_setSlave (SLAVE_ADDRESS,
                  Fault_CLR_REG);
    I2C_write (Fault_CLR_REG,
               LSD_Clear_EN);
}

/* LED PWM setting in manual mode */
void MANUL_LED_PWM(uint8_t LED_NUM,
                   uint8_t PWM_Value)
{
    I2C_setSlave (SLAVE_ADDRESS,
                  Manual_PWM_START + LED_NUM);
    I2C_write (Manual_PWM_START + LED_NUM,
               PWM_Value);
}

/* LED Current setting in manual mode */
void MANUL_LED_DC(uint8_t LED_NUM,
                  uint8_t DC_Value)
{
    I2C_setSlave (SLAVE_ADDRESS,
                  Manual_DC_START + LED_NUM);
    I2C_write (Manual_DC_START + LED_NUM,
               DC_Value);
}

/* RGB LED PWM setting in manual mode (LED_A/B/C/D) */
void MANUL_RGB_PWM(uint8_t RGB_NUM,
                   uint8_t PWM_R,
                   uint8_t PWM_G,
                   uint8_t PWM_B)
{
    I2C_setSlave (I2C_LP581X_5BIT_ADDRESS,
                  Manual_PWM_START + RGB_NUM);
    I2C_write (Manual_PWM_START + RGB_NUM,
               PWM_G);
    I2C_setSlave (I2C_LP581X_5BIT_ADDRESS,
                  Manual_PWM_START + RGB_NUM + 1);
    I2C_write (Manual_PWM_START + RGB_NUM + 1,
               PWM_R);
    I2C_setSlave (I2C_LP581X_5BIT_ADDRESS,
                  Manual_PWM_START + RGB_NUM + 2);
    I2C_write (Manual_PWM_START + RGB_NUM + 2,
               PWM_B);
}

/* RGB LED DC setting in manual mode (LED_A/B/C/D) */
void MANUL_RGB_DC(uint8_t RGB_NUM,
                   uint8_t DC_R,
                   uint8_t DC_G,
                   uint8_t DC_B)
{
    I2C_setSlave (SLAVE_ADDRESS,
                  Manual_DC_START + RGB_NUM);
    I2C_write (Manual_DC_START + RGB_NUM,
               DC_G);
    I2C_setSlave (SLAVE_ADDRESS,
                  Manual_DC_START + RGB_NUM + 1);
    I2C_write (Manual_DC_START + RGB_NUM + 1,
               DC_R);
    I2C_setSlave (SLAVE_ADDRESS,
                  Manual_DC_START + RGB_NUM + 2);
    I2C_write (Manual_DC_START + RGB_NUM + 2,
               DC_B);
}



//AEU setting//
void Auto_DC_SET(uint8_t LED_NUM,
                 uint8_t DC_Value)
{
    I2C_setSlave (SLAVE_ADDRESS,
                  Auto_DC_START + LED_NUM);
    I2C_write (Auto_DC_START + LED_NUM,
               DC_Value);
}


void AEU_Pause_Time_SET(uint8_t LED_NUM,
                        uint8_t Pause_Time_start,
                        uint8_t Pause_Time_end,
                        uint8_t Playback_Times,//0-Fh, When set to Fh, infinite times.
                        uint8_t AEU_select
//                        AEU number selection
//                        0h = only use AEU1
//                        1h = use AEU1 and AEU2
//                        2h = use AEU1, AEU2 and AEU3
//                        3h = use AEU1, AEU2 and AEU3
                        )
{
    int Pause_Time_Value;
    Pause_Time_Value = (Pause_Time_end<<4) + Pause_Time_start;
    I2C_setSlave (SLAVE_ADDRESS,
                  LED0_Pause_Time + LED_NUM * 26);
    I2C_write (LED0_Pause_Time + LED_NUM * 26, Pause_Time_Value);

    int Playback_selct_Value;
    Playback_selct_Value = (AEU_select<<4) + Playback_Times;
    I2C_setSlave (SLAVE_ADDRESS,
                  LED0_Playback_Time + LED_NUM * 26);
    I2C_write (LED0_Playback_Time + LED_NUM * 26, Playback_selct_Value);

}


void AEU_SET(uint8_t LED_NUM,
             uint8_t AEU_NUM, //AEU1/2/3
             uint8_t PWM1,//0-255
             uint8_t PWM2,
             uint8_t PWM3,
             uint8_t PWM4,
             uint8_t PWM5,
             uint8_t T1,//0-15 from 0-8s
             uint8_t T2,
             uint8_t T3,
             uint8_t T4,
             uint8_t PT//playback time 0h = 0 time, 1h = 1 time, 2h = 2 times, 3h = infinite times
             )
{
//
    int SLOPE_TIME1, SLOPE_TIME2;
    SLOPE_TIME1 = (T2<<4) + T1;
    SLOPE_TIME2 = (T4<<4) + T3;
    I2C_setSlave (SLAVE_ADDRESS,
                  LED0_AEU1_PWM1 + LED_NUM * 26 + AEU_NUM * 8);
    I2C_write (LED0_AEU1_PWM1 + LED_NUM * 26 + AEU_NUM * 8, PWM1);
    I2C_setSlave (SLAVE_ADDRESS,
                  LED0_AEU1_PWM1 + LED_NUM * 26 + AEU_NUM * 8 + 1);
    I2C_write (LED0_AEU1_PWM1 + LED_NUM * 26 + AEU_NUM * 8 + 1, PWM2);
    I2C_setSlave (SLAVE_ADDRESS,
                  LED0_AEU1_PWM1 + LED_NUM * 26 + AEU_NUM * 8 + 2);
    I2C_write (LED0_AEU1_PWM1 + LED_NUM * 26 + AEU_NUM * 8 + 2, PWM3);
    I2C_setSlave (SLAVE_ADDRESS,
                  LED0_AEU1_PWM1 + LED_NUM * 26 + AEU_NUM * 8 + 3);
    I2C_write (LED0_AEU1_PWM1 + LED_NUM * 26 + AEU_NUM * 8 + 3, PWM4);
    I2C_setSlave (SLAVE_ADDRESS,
                  LED0_AEU1_PWM1 + LED_NUM * 26 + AEU_NUM * 8 + 4);
    I2C_write (LED0_AEU1_PWM1 + LED_NUM * 26 + AEU_NUM * 8 + 4, PWM5);
    I2C_setSlave (SLAVE_ADDRESS,
                  LED0_AEU1_PWM1 + LED_NUM * 26 + AEU_NUM * 8 + 5);
    I2C_write (LED0_AEU1_PWM1 + LED_NUM * 26 + AEU_NUM * 8 + 5, SLOPE_TIME1);
    I2C_setSlave (SLAVE_ADDRESS,
                  LED0_AEU1_PWM1 + LED_NUM * 26 + AEU_NUM * 8 + 6);
    I2C_write (LED0_AEU1_PWM1 + LED_NUM * 26 + AEU_NUM * 8 + 6, SLOPE_TIME2);
    I2C_setSlave (SLAVE_ADDRESS,
                  LED0_AEU1_PWM1 + LED_NUM * 26 + AEU_NUM * 8 + 7);
    I2C_write (LED0_AEU1_PWM1 + LED_NUM * 26 + AEU_NUM * 8 + 7, PT);


//    int SLOPE_TIME1, SLOPE_TIME2;
//    SLOPE_TIME1 = (T2<<4) + T1;
//    SLOPE_TIME2 = (T4<<4) + T3;
//    I2C_setSlave (SLAVE_ADDRESS,
//                  LED0_AEU1_PWM1 + LED_NUM * 26 + AEU_NUM * 8);
//    I2C_write (LED0_AEU1_PWM1 + LED_NUM * 26 + AEU_NUM * 8, PWM1);
//    I2C_write (LED0_AEU1_PWM1 + LED_NUM * 26 + AEU_NUM * 8 + 1, PWM2);
//    I2C_write (LED0_AEU1_PWM1 + LED_NUM * 26 + AEU_NUM * 8 + 2, PWM3);
//    I2C_write (LED0_AEU1_PWM1 + LED_NUM * 26 + AEU_NUM * 8 + 3, PWM4);
//    I2C_write (LED0_AEU1_PWM1 + LED_NUM * 26 + AEU_NUM * 8 + 4, PWM5);
//    I2C_write (LED0_AEU1_PWM1 + LED_NUM * 26 + AEU_NUM * 8 + 5, SLOPE_TIME1);
//    I2C_write (LED0_AEU1_PWM1 + LED_NUM * 26 + AEU_NUM * 8 + 6, SLOPE_TIME2);
//    I2C_write (LED0_AEU1_PWM1 + LED_NUM * 26 + AEU_NUM * 8 + 7, PT);

}






