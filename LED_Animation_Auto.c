/*
 * LED_Animation_Auto.c
 *
 *  Created on: Dec 5, 2022
 *      Author: a0498597
 */

#include <I2C_EN.h>
#include <LED_Animation_Manual.h>
#include <LP5813.h>

/* Standard Includes */
#include <stdint.h>
#include <stdbool.h>

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

//4-scan TCM-mode



void RGB_Blink()
{
    Auto_DC_SET(LED_A0, 128);
    Auto_DC_SET(LED_A1, 0);
    Auto_DC_SET(LED_A2, 0);

    Auto_DC_SET(LED_B, 0);
    Auto_DC_SET(LED_B1, 128);
    Auto_DC_SET(LED_B2, 0);

    Auto_DC_SET(LED_C, 0);
    Auto_DC_SET(LED_C1, 0);
    Auto_DC_SET(LED_C2, 128);

    Auto_DC_SET(LED_D, 128);
    Auto_DC_SET(LED_D1, 128);
    Auto_DC_SET(LED_D2, 128);

    //Green
    AEU_Pause_Time_SET(LED_A, 0, 0, 15, 3);//LED_NUM, Pause_Time_start, Pause_Time_end, Playback_Times, AEU_select
    AEU_SET(LED_A, 0, 0, 192, 255, 192, 0, 2, 2, 2, 2, 2);//LED_NUM, AEU_NUM, PWM1, PWM2, PWM3, PWM4, PWM5, T1, T2, T3, T4, Playback_Times
    AEU_SET(LED_A, 1, 0, 192, 255, 192, 0, 3, 3, 3, 3, 2);
    AEU_SET(LED_A, 2, 0, 192, 255, 192, 0, 4, 4, 4, 4, 2);

    //Red
    AEU_Pause_Time_SET(LED_B1, 0, 0, 15, 3);//LED_NUM, Pause_Time_start, Pause_Time_end, Playback_Times, AEU_select
    AEU_SET(LED_B1, 0, 0, 192, 255, 192, 0, 2, 2, 2, 2, 2);//LED_NUM, AEU_NUM, PWM1, PWM2, PWM3, PWM4, PWM5, T1, T2, T3, T4, Playback_Times
    AEU_SET(LED_B1, 1, 0, 192, 255, 192, 0, 3, 3, 3, 3, 2);
    AEU_SET(LED_B1, 2, 0, 192, 255, 192, 0, 4, 4, 4, 4, 2);

    //Blue
    AEU_Pause_Time_SET(LED_C2, 0, 0, 15, 3);//LED_NUM, Pause_Time_start, Pause_Time_end, Playback_Times, AEU_select
    AEU_SET(LED_C2, 0, 0, 192, 255, 192, 0, 2, 2, 2, 2, 2);//LED_NUM, AEU_NUM, PWM1, PWM2, PWM3, PWM4, PWM5, T1, T2, T3, T4, Playback_Times
    AEU_SET(LED_C2, 1, 0, 192, 255, 192, 0, 3, 3, 3, 3, 2);
    AEU_SET(LED_C2, 2, 0, 192, 255, 192, 0, 4, 4, 4, 4, 2);

    //White
    AEU_Pause_Time_SET(LED_D, 0, 0, 15, 3);//LED_NUM, Pause_Time_start, Pause_Time_end, Playback_Times, AEU_select
    AEU_SET(LED_D, 0, 0, 192, 255, 192, 0, 2, 2, 2, 2, 2);//LED_NUM, AEU_NUM, PWM1, PWM2, PWM3, PWM4, PWM5, T1, T2, T3, T4, Playback_Times
    AEU_SET(LED_D, 1, 0, 192, 255, 192, 0, 3, 3, 3, 3, 2);
    AEU_SET(LED_D, 2, 0, 192, 255, 192, 0, 4, 4, 4, 4, 2);
    AEU_Pause_Time_SET(LED_D1, 0, 0, 15, 3);//LED_NUM, Pause_Time_start, Pause_Time_end, Playback_Times, AEU_select
    AEU_SET(LED_D1, 0, 0, 192, 255, 192, 0, 2, 2, 2, 2, 2);//LED_NUM, AEU_NUM, PWM1, PWM2, PWM3, PWM4, PWM5, T1, T2, T3, T4, Playback_Times
    AEU_SET(LED_D1, 1, 0, 192, 255, 192, 0, 3, 3, 3, 3, 2);
    AEU_SET(LED_D1, 2, 0, 192, 255, 192, 0, 4, 4, 4, 4, 2);
    AEU_Pause_Time_SET(LED_D2, 0, 0, 15, 3);//LED_NUM, Pause_Time_start, Pause_Time_end, Playback_Times, AEU_select
    AEU_SET(LED_D2, 0, 0, 192, 255, 192, 0, 2, 2, 2, 2, 2);//LED_NUM, AEU_NUM, PWM1, PWM2, PWM3, PWM4, PWM5, T1, T2, T3, T4, Playback_Times
    AEU_SET(LED_D2, 1, 0, 192, 255, 192, 0, 3, 3, 3, 3, 2);
    AEU_SET(LED_D2, 2, 0, 192, 255, 192, 0, 4, 4, 4, 4, 2);

    delay_ms(5);

    Update_CMD();
    delay_ms(5);
    Start_CMD();



}

void RGB_Dot_Rainbow(uint8_t RGB_NUM,
                     uint8_t R_start,
                     uint8_t G_start,
                     uint8_t B_start)
{
    Auto_DC_SET(RGB_NUM, 255);
    Auto_DC_SET(RGB_NUM+1, 255);
    Auto_DC_SET(RGB_NUM+2, 255);

    int GS_Rainbow_R[4] = {128, 128, 0, 0};
    int GS_Rainbow_G[4] = {0, 0, 128, 128};
    int GS_Rainbow_B[4] = {128, 0, 0, 128};
    //G
    AEU_Pause_Time_SET(RGB_NUM, 0, 0, 15, 0);//LED_NUM, Pause_Time_start, Pause_Time_end, Playback_Times, AEU_select
    AEU_SET(RGB_NUM, 0, GS_Rainbow_G[G_start%4], GS_Rainbow_G[(1+G_start)%4], GS_Rainbow_G[(2+G_start)%4], GS_Rainbow_G[(3+G_start)%4], GS_Rainbow_G[(4+G_start)%4], 4, 4, 4, 4, 0);//LED_NUM, AEU_NUM, PWM1, PWM2, PWM3, PWM4, PWM5, T1, T2, T3, T4, Playback_Times
    //R
    AEU_Pause_Time_SET(RGB_NUM+1, 0, 0, 15, 0);
    AEU_SET(RGB_NUM+1, 0, GS_Rainbow_R[R_start%4], GS_Rainbow_R[(1+R_start)%4], GS_Rainbow_R[(2+R_start)%4], GS_Rainbow_R[(3+R_start)%4], GS_Rainbow_R[(4+R_start)%4], 4, 4, 4, 4, 0);
    //B
    AEU_Pause_Time_SET(RGB_NUM+2, 0, 0, 15, 0);
    AEU_SET(RGB_NUM+2, 0, GS_Rainbow_B[B_start%4], GS_Rainbow_B[(1+B_start)%4], GS_Rainbow_B[(2+B_start)%4], GS_Rainbow_B[(3+B_start)%4], GS_Rainbow_B[(4+B_start)%4], 4, 4, 4, 4, 0);


}

void RGB_ALL_Rainbow()
{
    RGB_Dot_Rainbow(LED_A, 0, 0, 0);
    RGB_Dot_Rainbow(LED_B, 1, 1, 1);
    RGB_Dot_Rainbow(LED_C, 2, 2, 2);
    RGB_Dot_Rainbow(LED_D, 3, 3, 3);

    Update_CMD();
    delay_ms(5);
    Start_CMD();
}

void RGB_Fade_IN_And_OUT()
{
    EXP_DIM_MATRIX_EN();

    //Green
    Auto_DC_SET(LED_A0, 128);
    Auto_DC_SET(LED_A1, 0);
    Auto_DC_SET(LED_A2, 0);

    AEU_Pause_Time_SET(LED_A0, 0, 0, 15, 2);//LED_NUM, Pause_Time_start, Pause_Time_end, Playback_Times, AEU_select
    AEU_SET(LED_A0, 0, 0, 0, 153, 153, 204, 4, 3, 3, 2, 0);//LED_NUM, AEU_NUM, PWM1, PWM2, PWM3, PWM4, PWM5, T1, T2, T3, T4, Playback_Timest
    AEU_SET(LED_A0, 1, 204, 153, 204, 102, 102, 2, 2, 3, 3, 0);
    AEU_SET(LED_A0, 2, 102, 255, 255, 0, 0, 2, 6, 3, 0, 0);
    delay_ms(5);


    //Yellow
    Auto_DC_SET(LED_B0, 128);
    Auto_DC_SET(LED_B1, 128);
    Auto_DC_SET(LED_B2, 0);

    AEU_Pause_Time_SET(LED_B0, 0, 0, 15, 2);//LED_NUM, Pause_Time_start, Pause_Time_end, Playback_Times, AEU_select
    AEU_SET(LED_B0, 0, 0, 0, 153, 153, 204, 3, 3, 4, 2, 0);//LED_NUM, AEU_NUM, PWM1, PWM2, PWM3, PWM4, PWM5, T1, T2, T3, T4, Playback_Timest
    AEU_SET(LED_B0, 1, 204, 153, 204, 102, 102, 2, 2, 3, 2, 0);
    AEU_SET(LED_B0, 2, 102, 255, 255, 0, 0, 2, 6, 3, 2, 0);

    AEU_Pause_Time_SET(LED_B1, 0, 0, 15, 2);//LED_NUM, Pause_Time_start, Pause_Time_end, Playback_Times, AEU_select
    AEU_SET(LED_B1, 0, 0, 0, 153, 153, 204, 3, 3, 4, 2, 0);//LED_NUM, AEU_NUM, PWM1, PWM2, PWM3, PWM4, PWM5, T1, T2, T3, T4, Playback_Timest
    AEU_SET(LED_B1, 1, 204, 153, 204, 102, 102, 2, 2, 3, 2, 0);
    AEU_SET(LED_B1, 2, 102, 255, 255, 0, 0, 2, 6, 3, 2, 0);
    delay_ms(5);

    //Red
    Auto_DC_SET(LED_C0, 0);
    Auto_DC_SET(LED_C1, 128);
    Auto_DC_SET(LED_C2, 0);

    AEU_Pause_Time_SET(LED_C1, 0, 0, 15, 2);
    AEU_SET(LED_C1, 0, 0, 0, 153, 153, 153, 2, 3, 3, 3, 0);//LED_NUM, AEU_NUM, PWM1, PWM2, PWM3, PWM4, PWM5, T1, T2, T3, T4, Playback_Timest
    AEU_SET(LED_C1, 1, 153, 204, 153, 204, 102, 2, 2, 2, 3, 0);
    AEU_SET(LED_C1, 2, 102, 255, 255, 0, 0, 2, 6, 3, 3, 0);
    delay_ms(5);

    //Blue
    Auto_DC_SET(LED_D0, 0);
    Auto_DC_SET(LED_D1, 0);
    Auto_DC_SET(LED_D2, 128);

    AEU_Pause_Time_SET(LED_D2, 0, 0, 15, 2);
    AEU_SET(LED_D2, 0, 0, 0, 153, 153, 153, 0, 3, 3, 4, 0);//LED_NUM, AEU_NUM, PWM1, PWM2, PWM3, PWM4, PWM5, T1, T2, T3, T4, Playback_Timest
    AEU_SET(LED_D2, 1, 153, 204, 153, 204, 102, 2, 2, 2, 2, 0);
    AEU_SET(LED_D2, 2, 102, 255, 255, 0, 0, 2, 6, 3, 4, 0);
    delay_ms(5);

    Update_CMD();
    delay_ms(5);
    Start_CMD();

}



void RGB_Horse_Race()
{
    EXP_DIM_MATRIX_EN();

    //Red
    Auto_DC_SET(LED_A, 0);
    Auto_DC_SET(LED_A+1, 255);
    Auto_DC_SET(LED_A+2, 0);
    //Yellow
    Auto_DC_SET(LED_B, 255);
    Auto_DC_SET(LED_B+1, 255);
    Auto_DC_SET(LED_B+2, 0);
    //Blue
    Auto_DC_SET(LED_C, 0);
    Auto_DC_SET(LED_C+1, 0);
    Auto_DC_SET(LED_C+2, 255);
    //Green
    Auto_DC_SET(LED_D, 255);
    Auto_DC_SET(LED_D+1, 0);
    Auto_DC_SET(LED_D+2, 0);

    //R
    AEU_Pause_Time_SET(LED_A+1, 1, 0, 15, 0);//LED_NUM, Pause_Time_start, Pause_Time_end, Playback_Times, AEU_select
    AEU_SET(LED_A+1, 0, 128, 0, 0, 0, 128, 5, 5, 5, 5, 0);//LED_NUM, AEU_NUM, PWM1, PWM2, PWM3, PWM4, PWM5, T1, T2, T3, T4, Playback_Timest

    //Y
    AEU_Pause_Time_SET(LED_B, 1, 0, 15, 0);
    AEU_SET(LED_B, 0, 0, 128, 0, 0, 0, 5, 5, 5, 5, 0);

    AEU_Pause_Time_SET(LED_B+1, 1, 0, 15, 0);
    AEU_SET(LED_B+1, 0, 0, 128, 0, 0, 0, 5, 5, 5, 5, 0);

    //B
    AEU_Pause_Time_SET(LED_C+2, 1, 0, 15, 0);
    AEU_SET(LED_C+2, 0, 0, 0, 128, 0, 0, 5, 5, 5, 5, 0);


    //G
    AEU_Pause_Time_SET(LED_D, 1, 0, 15, 0);
    AEU_SET(LED_D, 0, 0, 0, 0, 128, 0, 5, 5, 5, 5, 0);


    Update_CMD();
    delay_ms(5);
    Start_CMD();


}

//direct mode
void LED_Dot_Breathing(uint8_t LED_NUM,
                       uint8_t GS_start,
                       uint8_t GS_end)
{
    AEU_Pause_Time_SET(LED_NUM, 2, 2, 15, 3);//LED_NUM, Pause_Time_start, Pause_Time_end, Playback_Times, AEU_select
    AEU_SET(LED_NUM, 0, GS_start, (GS_start+GS_end)/2, GS_end, (GS_start+GS_end)/2, GS_start, 2, 2, 2, 2, 2);//LED_NUM, AEU_NUM, PWM1, PWM2, PWM3, PWM4, PWM5, T1, T2, T3, T4, Playback_Times
    AEU_SET(LED_NUM, 1, GS_start, (GS_start+GS_end)/2, GS_end, (GS_start+GS_end)/2, GS_start, 3, 3, 3, 3, 2);
    AEU_SET(LED_NUM, 2, GS_start, (GS_start+GS_end)/2, GS_end, (GS_start+GS_end)/2, GS_start, 4, 4, 4, 4, 2);
}

void LED_ALL_Breathing()
{
    LED_Dot_Breathing(LED0, 0, 255);
    LED_Dot_Breathing(LED1, 0, 255);
    LED_Dot_Breathing(LED2, 0, 255);
    LED_Dot_Breathing(LED3, 0, 255);

    Update_CMD();
    delay_ms(5);
    Start_CMD();

}

void LED_Blink()
{
    Auto_DC_SET(LED0, 128);
    Auto_DC_SET(LED1, 128);
    Auto_DC_SET(LED2, 128);
    Auto_DC_SET(LED3, 128);


    AEU_Pause_Time_SET(LED0, 0, 0, 15, 3);//LED_NUM, Pause_Time_start, Pause_Time_end, Playback_Times, AEU_select
    AEU_SET(LED0, 0, 0, 192, 255, 192, 0, 2, 2, 2, 2, 2);//LED_NUM, AEU_NUM, PWM1, PWM2, PWM3, PWM4, PWM5, T1, T2, T3, T4, Playback_Times
    AEU_SET(LED0, 1, 0, 192, 255, 192, 0, 3, 3, 3, 3, 2);
    AEU_SET(LED0, 2, 0, 192, 255, 192, 0, 4, 4, 4, 4, 2);

    //Red
    AEU_Pause_Time_SET(LED1, 0, 0, 15, 3);//LED_NUM, Pause_Time_start, Pause_Time_end, Playback_Times, AEU_select
    AEU_SET(LED1, 0, 0, 192, 255, 192, 0, 2, 2, 2, 2, 2);//LED_NUM, AEU_NUM, PWM1, PWM2, PWM3, PWM4, PWM5, T1, T2, T3, T4, Playback_Times
    AEU_SET(LED1, 1, 0, 192, 255, 192, 0, 3, 3, 3, 3, 2);
    AEU_SET(LED1, 2, 0, 192, 255, 192, 0, 4, 4, 4, 4, 2);

    //Blue
    AEU_Pause_Time_SET(LED2, 0, 0, 15, 3);//LED_NUM, Pause_Time_start, Pause_Time_end, Playback_Times, AEU_select
    AEU_SET(LED2, 0, 0, 192, 255, 192, 0, 2, 2, 2, 2, 2);//LED_NUM, AEU_NUM, PWM1, PWM2, PWM3, PWM4, PWM5, T1, T2, T3, T4, Playback_Times
    AEU_SET(LED2, 1, 0, 192, 255, 192, 0, 3, 3, 3, 3, 2);
    AEU_SET(LED2, 2, 0, 192, 255, 192, 0, 4, 4, 4, 4, 2);

    //White
    AEU_Pause_Time_SET(LED3, 0, 0, 15, 3);//LED_NUM, Pause_Time_start, Pause_Time_end, Playback_Times, AEU_select
    AEU_SET(LED3, 0, 0, 192, 255, 192, 0, 2, 2, 2, 2, 2);//LED_NUM, AEU_NUM, PWM1, PWM2, PWM3, PWM4, PWM5, T1, T2, T3, T4, Playback_Times
    AEU_SET(LED3, 1, 0, 192, 255, 192, 0, 3, 3, 3, 3, 2);
    AEU_SET(LED3, 2, 0, 192, 255, 192, 0, 4, 4, 4, 4, 2);

    delay_ms(5);

    Update_CMD();
    delay_ms(5);
    Start_CMD();



}

void LED_Fade_IN_And_OUT()
{
    EXP_DIM_MATRIX_EN();



    //1
    Auto_DC_SET(LED0, 255);
    AEU_Pause_Time_SET(LED0, 0, 0, 15, 2);//LED_NUM, Pause_Time_start, Pause_Time_end, Playback_Times, AEU_select
    AEU_SET(LED0, 0, 0, 0, 153, 153, 204, 4, 3, 3, 2, 0);//LED_NUM, AEU_NUM, PWM1, PWM2, PWM3, PWM4, PWM5, T1, T2, T3, T4, Playback_Timest
    AEU_SET(LED0, 1, 204, 153, 204, 102, 102, 2, 2, 3, 3, 0);
    AEU_SET(LED0, 2, 102, 255, 255, 0, 0, 2, 6, 3, 0, 0);
    delay_ms(5);

    //2
    Auto_DC_SET(LED1, 255);
    AEU_Pause_Time_SET(LED1, 0, 0, 15, 2);//LED_NUM, Pause_Time_start, Pause_Time_end, Playback_Times, AEU_select
    AEU_SET(LED1, 0, 0, 0, 153, 153, 204, 3, 3, 4, 2, 0);//LED_NUM, AEU_NUM, PWM1, PWM2, PWM3, PWM4, PWM5, T1, T2, T3, T4, Playback_Timest
    AEU_SET(LED1, 1, 204, 153, 204, 102, 102, 2, 2, 3, 2, 0);
    AEU_SET(LED1, 2, 102, 255, 255, 0, 0, 2, 6, 3, 2, 0);

    //3
    Auto_DC_SET(LED2, 255);
    AEU_Pause_Time_SET(LED2, 0, 0, 15, 2);
    AEU_SET(LED2, 0, 0, 0, 153, 153, 153, 2, 3, 3, 3, 0);//LED_NUM, AEU_NUM, PWM1, PWM2, PWM3, PWM4, PWM5, T1, T2, T3, T4, Playback_Timest
    AEU_SET(LED2, 1, 153, 204, 153, 204, 102, 2, 2, 2, 3, 0);
    AEU_SET(LED2, 2, 102, 255, 255, 0, 0, 2, 6, 3, 3, 0);
    delay_ms(5);

    //4
    Auto_DC_SET(LED3, 255);
    AEU_Pause_Time_SET(LED3, 0, 0, 15, 2);
    AEU_SET(LED3, 0, 0, 0, 153, 153, 153, 0, 3, 3, 4, 0);//LED_NUM, AEU_NUM, PWM1, PWM2, PWM3, PWM4, PWM5, T1, T2, T3, T4, Playback_Timest
    AEU_SET(LED3, 1, 153, 204, 153, 204, 102, 2, 2, 2, 2, 0);
    AEU_SET(LED3, 2, 102, 255, 255, 0, 0, 2, 6, 3, 4, 0);
    delay_ms(5);

    Update_CMD();
    delay_ms(5);
    Start_CMD();

}

void LED_Horse_Race()
{
    EXP_DIM_MATRIX_EN();

    //1
    Auto_DC_SET(LED0, 255);
    //2
    Auto_DC_SET(LED1, 255);
    //3
    Auto_DC_SET(LED2, 255);
    //4
    Auto_DC_SET(LED3, 255);

    //1
    AEU_Pause_Time_SET(LED0, 1, 0, 0, 0);//LED_NUM, Pause_Time_start, Pause_Time_end, Playback_Times, AEU_select
    AEU_SET(LED0, 0, 128, 0, 0, 0, 128, 5, 5, 5, 5, 3);//LED_NUM, AEU_NUM, PWM1, PWM2, PWM3, PWM4, PWM5, T1, T2, T3, T4, Playback_Timest

    //2
    AEU_Pause_Time_SET(LED1, 1, 0, 0, 0);
    AEU_SET(LED1, 0, 0, 128, 0, 0, 0, 5, 5, 5, 5, 3);


    //3
    AEU_Pause_Time_SET(LED2, 1, 0, 0, 0);
    AEU_SET(LED2, 0, 0, 0, 128, 0, 0, 5, 5, 5, 5, 3);


    //4
    AEU_Pause_Time_SET(LED3, 1, 0, 0, 0);
    AEU_SET(LED3, 0, 0, 0, 0, 128, 0, 5, 5, 5, 5, 3);


    Update_CMD();
    delay_ms(5);
    Start_CMD();


}



/***************************************************************************//**
 *direct-mode
 ******************************************************************************/
void LED_ALL_FULL()
{
    AUTO_DISABLE();

    MANUL_LED_DC(LED0, 255);
    MANUL_LED_DC(LED1, 255);
    MANUL_LED_DC(LED2, 255);
    MANUL_LED_DC(LED3, 255);

    MANUL_LED_PWM(LED0, 255);
    MANUL_LED_PWM(LED1, 255);
    MANUL_LED_PWM(LED2, 255);
    MANUL_LED_PWM(LED3, 255);
    delay_ms(10);
}

void LED_ALL_OFF()
{
    AUTO_DISABLE();

    MANUL_LED_PWM(LED0, 0);
    MANUL_LED_PWM(LED1, 0);
    MANUL_LED_PWM(LED2, 0);
    MANUL_LED_PWM(LED3, 0);
    delay_ms(10);
}

void LED_Breathing()
{

    AUTO_DISABLE();

    int i;
    int x=3;
    int loop_length=256/x;
    for (i=0; i<loop_length; i++)
    {
        MANUL_LED_PWM(LED0, x*i);
        MANUL_LED_PWM(LED1, x*i);
        MANUL_LED_PWM(LED2, x*i);
        MANUL_LED_PWM(LED3, x*i);
        delay_ms(5);
    }

}













