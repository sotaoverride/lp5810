
//                     MSPM0L1306
//                 -----------------
//            /|\ |                 |
//             |  |                 |
//             ---|RST              |
//                |                 |
//                |                 |
//                |                 |
//                |             PA15|-> SCL
//                |                 |
//                |             PA16|<- SDA
//                |                 |
//                |             PA11|-> EN (if necessary)

#include <I2C_EN.h>
#include <LP5813.h>
#include <stdio.h>
#include <stdint.h>
#include <LED_Animation_Manual.h>
#include <LED_Animation_Auto.h>

/***************************************************************************//**
*4-scan TCM manual mode
******************************************************************************/
void LED_Manual()
{
    LED_DIRECT_EN();
    delay_ms(10);
    Device_Configuration_0(BOOST_VOUT_4, MAX_CURRENT_25_5);
    Device_Configuration_1(PWM_FREQ_24K, LED_CONFIG_DIRECT, MIX_SEL_LED_NONE); //Direct model
    Update_CMD();
    delay_ms(10);

    AUTO_DISABLE();
    EXP_DIM_DISABLE();
    delay_ms(10);
    Update_CMD();
    delay_ms(10);

//  EXP_DIM_DIRECT_EN();

    while(1)
    {
        //LED manual pattern
        LED_ALL_FULL();
        delay_ms(10);
        LED_ALL_OFF();
        delay_ms(10);
        LED_Breathing();
    }


}

void RGB_Manual()
{
    delay_ms(10);


    //for debug only
    //DL_GPIO_setPins(GPIO_LEDS_PORT, GPIO_LEDS_USER_LED_1_PIN);

    /*RGB MANNUAL*/
    Device_Configuration_0(BOOST_VOUT_3, MAX_CURRENT_25_5);
    delay_ms(100);
    Device_Configuration_0(BOOST_VOUT_3_3, MAX_CURRENT_25_5);
    delay_ms(100);
    Device_Configuration_0(BOOST_VOUT_3_5, MAX_CURRENT_25_5);
    delay_ms(100);
    Device_Configuration_0(BOOST_VOUT_4, MAX_CURRENT_25_5);
    delay_ms(100);
    Device_Configuration_1(PWM_FREQ_24K, LED_CONFIG_4SCAN, MIX_SEL_LED_NONE); //4-scan TCM-model
    delay_ms(10);
    Device_Configuration_2(SCAN_ORDER_OUT3, SCAN_ORDER_OUT2, SCAN_ORDER_OUT1, SCAN_ORDER_OUT0);
    delay_ms(10);


    Update_CMD();

    delay_ms(10);
    LED_MATRIX_EN();
    AUTO_DISABLE();
    EXP_DIM_DISABLE();
//                EXP_DIM_MATRIX_EN();
    delay_ms(10);
    Update_CMD();
    /*RGB MANNUAL*/



    int counter = 0;

    while(1)
    {
        //RGB manual pattern
        RGB_ALL_FULL();
        delay_ms(50);
        RGB_ALL_OFF();
        delay_ms(50);
        RGB_Breathing(255, 255, 255);
        delay_ms(10);
        RGB_Rainbow();
        delay_ms(10);

    }
}

void LED_Auto()
{
    delay_ms(10);
    LED_DIRECT_EN();
    delay_ms(10);
    Device_Configuration_0(BOOST_VOUT_3, MAX_CURRENT_25_5);
    delay_ms(100);
    Device_Configuration_0(BOOST_VOUT_3_3, MAX_CURRENT_25_5);
    delay_ms(100);
    Device_Configuration_0(BOOST_VOUT_3_5, MAX_CURRENT_25_5);
    delay_ms(100);
    Device_Configuration_0(BOOST_VOUT_4, MAX_CURRENT_25_5);
    delay_ms(100);
    Device_Configuration_1(PWM_FREQ_24K, LED_CONFIG_DIRECT, MIX_SEL_LED_NONE); //Direct model
    Update_CMD();
    delay_ms(10);

    AUTO_DIRECT_EN();
//    EXP_DIM_DISABLE();
    EXP_DIM_DIRECT_EN();
    delay_ms(10);
    Update_CMD();
    delay_ms(10);

    while(1)
    {
        LED_Blink();
        delay_ms(5000);
        Pause_CMD();

        LED_Fade_IN_And_OUT();
        delay_ms(5000);
        Pause_CMD();

        LED_Horse_Race();
        delay_ms(5000);
        Pause_CMD();
    }
}

void RGB_Auto()
{
    delay_ms(10);
    LED_MATRIX_EN();
    delay_ms(10);
    Device_Configuration_0(BOOST_VOUT_3, MAX_CURRENT_25_5);
    delay_ms(100);
    Device_Configuration_0(BOOST_VOUT_3_3, MAX_CURRENT_25_5);
    delay_ms(100);
    Device_Configuration_0(BOOST_VOUT_3_5, MAX_CURRENT_25_5);
    delay_ms(100);
    Device_Configuration_0(BOOST_VOUT_4, MAX_CURRENT_25_5);
    delay_ms(100);
    Device_Configuration_1(PWM_FREQ_24K, LED_CONFIG_4SCAN, MIX_SEL_LED_NONE); //4-scan TCM-model
    Device_Configuration_2(SCAN_ORDER_OUT3, SCAN_ORDER_OUT2, SCAN_ORDER_OUT1, SCAN_ORDER_OUT0);
    Update_CMD();
    delay_ms(10);
    AUTO_MATRIX_EN(); //Autonomous control

    EXP_DIM_DISABLE();
//  EXP_DIM_MATRIX_EN();
    Update_CMD();

//RGB auto animation pattern//
    while(1)
    {
        RGB_Blink();
        delay_ms(7000);
        Pause_CMD();

        RGB_ALL_Rainbow();
        delay_ms(5000);
        Pause_CMD();

        RGB_Horse_Race();
        delay_ms(5000);
        Pause_CMD();

        RGB_Fade_IN_And_OUT();
        delay_ms(5000);
        Pause_CMD();
    }

}


int main(void)
{
    printf("hello here now \n");
    delay_ms(200);
    //SYSCFG_DL_init();
    delay_ms(10);

    //ENABLE BOOST
    BOOST_Disable_EN();
    BOOST_Enable_EN();
    delay_ms(10);

    //Chip Enable
    Reset();
    delay_ms(10);
    Chip_Normal();
    delay_ms(10);
    Update_CMD();
    delay_ms(10);

/***************************************************************************//**
*4-scan/direct mode              Manual/ Auto animation mode
******************************************************************************/
//    LED_Manual();
//    RGB_Manual();
//    LED_Auto();
    RGB_Auto();




    return 0;
}
