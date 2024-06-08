#ifndef LP586x_H_
#define LP586x_H_
#include <stdint.h>
//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************

/***************************************************************************//**
 *Register Dev_config0 Value
 ******************************************************************************/
#define MAX_CURRENT_25_5                   0x0 //default
#define MAX_CURRENT_51                     0x1

#define BOOST_VOUT_3                       0x00 //default
#define BOOST_VOUT_3_3                     0x03
#define BOOST_VOUT_3_5                     0x05
#define BOOST_VOUT_4                       0x0A
#define BOOST_VOUT_5                       0x14
#define BOOST_VOUT_5_5                     0x1F



/***************************************************************************//**
 *Register Dev_config1 Value
 ******************************************************************************/
#define PWM_FREQ_24K                       0x0 //default
#define PWM_FREQ_12K                       0x1

#define LED_CONFIG_DIRECT                  0x0 //default
#define LED_CONFIG_1SCAN                   0x1
#define LED_CONFIG_2SCAN                   0x2
#define LED_CONFIG_3SCAN                   0x3
#define LED_CONFIG_4SCAN                   0x4
#define LED_CONFIG_MIX_1SCAN               0x5
#define LED_CONFIG_MIX_2SCAN               0x6
#define LED_CONFIG_MIX_3SCAN               0x7

#define MIX_SEL_LED_NONE                   0x0 //default
#define MIX_SEL_LED_OUT0                   0x1
#define MIX_SEL_LED_OUT1                   0x2
#define MIX_SEL_LED_OUT2                   0x4
#define MIX_SEL_LED_OUT3                   0x8


/***************************************************************************//**
 *Register Dev_config2 Value
 ******************************************************************************/
#define SCAN_ORDER_OUT0                   0x0
#define SCAN_ORDER_OUT1                   0x1
#define SCAN_ORDER_OUT2                   0x2
#define SCAN_ORDER_OUT3                   0x3



/***************************************************************************//**
 *Function definition
 ******************************************************************************/
extern void Chip_Standby();
extern void Chip_Normal();
extern void Device_Initial(uint8_t Max_Line,
                           uint8_t Data_Ref_Mode,
                           uint8_t PWM_Fre);
extern void Device_Configuration_0(uint8_t boost_vout,
                                   uint8_t max_current);
extern void Device_Configuration_1(uint8_t pwm_freq,
                            uint8_t led_config,
                            uint8_t mix_sel_led);
extern void Device_Configuration_2(uint8_t scan_order3,
                                   uint8_t scan_order2,
                                   uint8_t scan_order1,
                                   uint8_t scan_order0);
extern void Device_Configuration_11(uint8_t vsync_out_en,
                                    uint8_t blank_time);
extern void Device_Configuration_12(uint8_t vmid_sel,
                                    uint8_t clamp_sel,
                                    uint8_t clamp_dis,
                                    uint8_t lod_action,
                                    uint8_t lsd_action,
                                    uint8_t lsd_threshold);

extern void Update_CMD();
extern void Start_CMD();
extern void Stop_CMD();
extern void Pause_CMD();
extern void Continue_CMD();

extern void BOOST_Disable_EN();
extern void BOOST_Enable_EN();

extern void LED_DIRECT_EN();
extern void LED_MATRIX_EN();

extern void AUTO_DIRECT_EN();
extern void AUTO_MATRIX_EN();
extern void AUTO_DISABLE();

extern void EXP_DIM_DIRECT_EN();
extern void EXP_DIM_MATRIX_EN();
extern void EXP_DIM_DISABLE();


extern void MANUL_LED_PWM(uint8_t LED_NUM,
                          uint8_t PWM_Value);
extern void MANUL_LED_DC(uint8_t LED_NUM,
                         uint8_t DC_Value);
extern void MANUL_RGB_PWM(uint8_t RGB_NUM,
                          uint8_t PWM_R,
                          uint8_t PWM_G,
                          uint8_t PWM_B);
extern void MANUL_RGB_DC(uint8_t RGB_NUM,
                         uint8_t DC_R,
                         uint8_t DC_G,
                         uint8_t DC_B);

extern void Auto_DC_SET(uint8_t LED_NUM,
                        uint8_t DC_Value);
extern void AEU_Pause_Time_SET(uint8_t LED_NUM,
                               uint8_t Pause_Time_start,
                               uint8_t Pause_Time_end,
                               uint8_t Playback_Times,
                               uint8_t AEU_select
       //                        AEU number selection
       //                        0h = only use AEU1
       //                        1h = use AEU1 and AEU2
       //                        2h = use AEU1, AEU2 and AEU3
       //                        3h = use AEU1, AEU2 and AEU3
                               );
extern void AEU_SET(uint8_t LED_NUM,
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
                    );

extern void Reset();
extern void LOD_Clear();
extern void LSD_Clear();

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
#endif /* LP586x_H_ */
