/*
 * LED_Animation_Manual.c
 *
 *  Created on: Oct 24, 2022
 *      Author: a0498597
 */

#include <I2C_EN.h>
#include <LED_Animation_Manual.h>
#include <LP5813.h>
/* Standard Includes */
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "ti_msp_dl_config.h"


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

/***************************************************************************//**
 *4-SCAN TCM-mode
 ******************************************************************************/
#define RISING_TIME                        10
#define FALLING_TIME                       20
#define RING_TIME                          1


void RGB_ALL_FULL()
{
    AUTO_DISABLE();

    MANUL_RGB_DC(LED_A, 255, 255, 255);
    MANUL_RGB_DC(LED_B, 255, 255, 255);
    MANUL_RGB_DC(LED_C, 255, 255, 255);
    MANUL_RGB_DC(LED_D, 255, 255, 255);

    MANUL_RGB_PWM(LED_A, 255, 255, 255);
    MANUL_RGB_PWM(LED_B, 255, 255, 255);
    MANUL_RGB_PWM(LED_C, 255, 255, 255);
    MANUL_RGB_PWM(LED_D, 255, 255, 255);
    delay_ms(10);
}

void RGB_ALL_OFF()
{
    AUTO_DISABLE();

    MANUL_RGB_PWM(LED_A, 0, 0, 0);
    MANUL_RGB_PWM(LED_B, 0, 0, 0);
    MANUL_RGB_PWM(LED_C, 0, 0, 0);
    MANUL_RGB_PWM(LED_D, 0, 0, 0);
    delay_ms(10);
}


void RGB_Breathing(uint8_t R_color,
               uint8_t G_color,
               uint8_t B_color)
{
    MANUL_RGB_DC(LED_A, R_color, G_color, B_color);
    MANUL_RGB_DC(LED_B, R_color, G_color, B_color);
    MANUL_RGB_DC(LED_C, R_color, G_color, B_color);
    MANUL_RGB_DC(LED_D, R_color, G_color, B_color);

    int i;
    int x=8;
    int loop_length=256/x;




    /*******************red*********************/
    for (i=0; i<=loop_length; i++)
    {
        if(i == loop_length){
            MANUL_RGB_PWM(LED_A, 255, 0, 0);
            MANUL_RGB_PWM(LED_B, 255, 0, 0);
            MANUL_RGB_PWM(LED_C, 255, 0, 0);
            MANUL_RGB_PWM(LED_D, 255, 0, 0);
        }else{
            MANUL_RGB_PWM(LED_A, x*i, 0, 0);
            MANUL_RGB_PWM(LED_B, x*i, 0, 0);
            MANUL_RGB_PWM(LED_C, x*i, 0, 0);
            MANUL_RGB_PWM(LED_D, x*i, 0, 0);
        }
        delay_ms(RISING_TIME);

    }

    for (i=0; i<=loop_length; i++)
    {
        if(i==0){
            MANUL_RGB_PWM(LED_A, 255, 0, 0);
            MANUL_RGB_PWM(LED_B, 255, 0, 0);
            MANUL_RGB_PWM(LED_C, 255, 0, 0);
            MANUL_RGB_PWM(LED_D, 255, 0, 0);
        }else{
            MANUL_RGB_PWM(LED_A, 256-x*i, 0, 0);
            MANUL_RGB_PWM(LED_B, 256-x*i, 0, 0);
            MANUL_RGB_PWM(LED_C, 256-x*i, 0, 0);
            MANUL_RGB_PWM(LED_D, 256-x*i, 0, 0);
        }
        delay_ms(FALLING_TIME);

    }

    /*******************orange*********************/
    for (i=0; i<=loop_length; i++)
    {
        if(i == loop_length){
            MANUL_RGB_PWM(LED_A, 255, 63, 0);
            MANUL_RGB_PWM(LED_B, 255, 63, 0);
            MANUL_RGB_PWM(LED_C, 255, 63, 0);
            MANUL_RGB_PWM(LED_D, 255, 63, 0);
        }else{
            MANUL_RGB_PWM(LED_A, x*i, 2*i, 0);
            MANUL_RGB_PWM(LED_B, x*i, 2*i, 0);
            MANUL_RGB_PWM(LED_C, x*i, 2*i, 0);
            MANUL_RGB_PWM(LED_D, x*i, 2*i, 0);
        }
        delay_ms(RISING_TIME);
    }

    for (i=0; i<=loop_length; i++)
    {
        if(i==0){
            MANUL_RGB_PWM(LED_A, 255, 63, 0);
            MANUL_RGB_PWM(LED_B, 255, 63, 0);
            MANUL_RGB_PWM(LED_C, 255, 63, 0);
            MANUL_RGB_PWM(LED_D, 255, 63, 0);
        }else{
            MANUL_RGB_PWM(LED_A, 256-x*i, 64-2*i, 0);
            MANUL_RGB_PWM(LED_B, 256-x*i, 64-2*i, 0);
            MANUL_RGB_PWM(LED_C, 256-x*i, 64-2*i, 0);
            MANUL_RGB_PWM(LED_D, 256-x*i, 64-2*i, 0);
        }
        delay_ms(FALLING_TIME);
    }

    /*******************yellow*********************/
    for (i=0; i<=loop_length; i++)
    {
        if(i == loop_length){
            MANUL_RGB_PWM(LED_A, 255, 255, 0);
            MANUL_RGB_PWM(LED_B, 255, 255, 0);
            MANUL_RGB_PWM(LED_C, 255, 255, 0);
            MANUL_RGB_PWM(LED_D, 255, 255, 0);
        }else{
            MANUL_RGB_PWM(LED_A, x*i, x*i, 0);
            MANUL_RGB_PWM(LED_B, x*i, x*i, 0);
            MANUL_RGB_PWM(LED_C, x*i, x*i, 0);
            MANUL_RGB_PWM(LED_D, x*i, x*i, 0);
        }
        delay_ms(RISING_TIME);
    }

    for (i=0; i<=loop_length; i++)
    {
        if(i==0){
            MANUL_RGB_PWM(LED_A, 255, 255, 0);
            MANUL_RGB_PWM(LED_B, 255, 255, 0);
            MANUL_RGB_PWM(LED_C, 255, 255, 0);
            MANUL_RGB_PWM(LED_D, 255, 255, 0);
        }else{
            MANUL_RGB_PWM(LED_A, 256-x*i, 256-x*i, 0);
            MANUL_RGB_PWM(LED_B, 256-x*i, 256-x*i, 0);
            MANUL_RGB_PWM(LED_C, 256-x*i, 256-x*i, 0);
            MANUL_RGB_PWM(LED_D, 256-x*i, 256-x*i, 0);
        }
        delay_ms(FALLING_TIME);
    }

    /*******************green*********************/
    for (i=0; i<=loop_length; i++)
    {
        if(i == loop_length){
            MANUL_RGB_PWM(LED_A, 0, 255, 0);
            MANUL_RGB_PWM(LED_B, 0, 255, 0);
            MANUL_RGB_PWM(LED_C, 0, 255, 0);
            MANUL_RGB_PWM(LED_D, 0, 255, 0);
        }else{
            MANUL_RGB_PWM(LED_A, 0, x*i, 0);
            MANUL_RGB_PWM(LED_B, 0, x*i, 0);
            MANUL_RGB_PWM(LED_C, 0, x*i, 0);
            MANUL_RGB_PWM(LED_D, 0, x*i, 0);
        }
        delay_ms(RISING_TIME);
    }

    for (i=0; i<=loop_length; i++)
    {
        if(i==0){
            MANUL_RGB_PWM(LED_A, 0, 255, 0);
            MANUL_RGB_PWM(LED_B, 0, 255, 0);
            MANUL_RGB_PWM(LED_C, 0, 255, 0);
            MANUL_RGB_PWM(LED_D, 0, 255, 0);
        }else{
            MANUL_RGB_PWM(LED_A, 0, 256-x*i, 0);
            MANUL_RGB_PWM(LED_B, 0, 256-x*i, 0);
            MANUL_RGB_PWM(LED_C, 0, 256-x*i, 0);
            MANUL_RGB_PWM(LED_D, 0, 256-x*i, 0);
        }
        delay_ms(FALLING_TIME);
    }

    /*******************cyan*********************/
    for (i=0; i<=loop_length; i++)
    {
        if(i == loop_length){
            MANUL_RGB_PWM(LED_A, 0, 255, 255);
            MANUL_RGB_PWM(LED_B, 0, 255, 255);
            MANUL_RGB_PWM(LED_C, 0, 255, 255);
            MANUL_RGB_PWM(LED_D, 0, 255, 255);
        }else{
            MANUL_RGB_PWM(LED_A, 0, x*i, x*i);
            MANUL_RGB_PWM(LED_B, 0, x*i, x*i);
            MANUL_RGB_PWM(LED_C, 0, x*i, x*i);
            MANUL_RGB_PWM(LED_D, 0, x*i, x*i);
        }
        delay_ms(RISING_TIME);
    }

    for (i=0; i<=loop_length; i++)
    {
        if(i==0){
            MANUL_RGB_PWM(LED_A, 0, 255, 255);
            MANUL_RGB_PWM(LED_B, 0, 255, 255);
            MANUL_RGB_PWM(LED_C, 0, 255, 255);
            MANUL_RGB_PWM(LED_D, 0, 255, 255);
        }else{
            MANUL_RGB_PWM(LED_A, 0, 256-x*i, 256-x*i);
            MANUL_RGB_PWM(LED_B, 0, 256-x*i, 256-x*i);
            MANUL_RGB_PWM(LED_C, 0, 256-x*i, 256-x*i);
            MANUL_RGB_PWM(LED_D, 0, 256-x*i, 256-x*i);
        }
        delay_ms(FALLING_TIME);
    }

    /*******************blue*********************/
    for (i=0; i<=loop_length; i++)
    {
        if(i == loop_length){
            MANUL_RGB_PWM(LED_A, 0, 0, 255);
            MANUL_RGB_PWM(LED_B, 0, 0, 255);
            MANUL_RGB_PWM(LED_C, 0, 0, 255);
            MANUL_RGB_PWM(LED_D, 0, 0, 255);
        }else{
            MANUL_RGB_PWM(LED_A, 0, 0, x*i);
            MANUL_RGB_PWM(LED_B, 0, 0, x*i);
            MANUL_RGB_PWM(LED_C, 0, 0, x*i);
            MANUL_RGB_PWM(LED_D, 0, 0, x*i);
        }
        delay_ms(RISING_TIME);
    }


    for (i=0; i<=loop_length; i++)
    {
        if(i==0){
            MANUL_RGB_PWM(LED_A, 0, 0, 255);
            MANUL_RGB_PWM(LED_B, 0, 0, 255);
            MANUL_RGB_PWM(LED_C, 0, 0, 255);
            MANUL_RGB_PWM(LED_D, 0, 0, 255);
        }else{
            MANUL_RGB_PWM(LED_A, 0, 0, 256-x*i);
            MANUL_RGB_PWM(LED_B, 0, 0, 256-x*i);
            MANUL_RGB_PWM(LED_C, 0, 0, 256-x*i);
            MANUL_RGB_PWM(LED_D, 0, 0, 256-x*i);
        }
        delay_ms(FALLING_TIME);
    }

    /*******************purple*********************/
    for (i=0; i<=loop_length; i++)
    {
        if(i == loop_length){
            MANUL_RGB_PWM(LED_A, 255, 0, 255);
            MANUL_RGB_PWM(LED_B, 255, 0, 255);
            MANUL_RGB_PWM(LED_C, 255, 0, 255);
            MANUL_RGB_PWM(LED_D, 255, 0, 255);
        }else{
            MANUL_RGB_PWM(LED_A, x*i, 0, x*i);
            MANUL_RGB_PWM(LED_B, x*i, 0, x*i);
            MANUL_RGB_PWM(LED_C, x*i, 0, x*i);
            MANUL_RGB_PWM(LED_D, x*i, 0, x*i);
        }
        delay_ms(RISING_TIME);
    }

    for (i=0; i<=loop_length; i++)
    {
        if(i==0){
            MANUL_RGB_PWM(LED_A, 255, 0, 255);
            MANUL_RGB_PWM(LED_B, 255, 0, 255);
            MANUL_RGB_PWM(LED_C, 255, 0, 255);
            MANUL_RGB_PWM(LED_D, 255, 0, 255);
        }else{
            MANUL_RGB_PWM(LED_A, 256-x*i, 0, 256-x*i);
            MANUL_RGB_PWM(LED_B, 256-x*i, 0, 256-x*i);
            MANUL_RGB_PWM(LED_C, 256-x*i, 0, 256-x*i);
            MANUL_RGB_PWM(LED_D, 256-x*i, 0, 256-x*i);
        }
        delay_ms(FALLING_TIME);
    }
}

void RGB_Rainbow()
{
    int i;
    int GS_Rainbow_R[256] = {
                          255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
                          255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
                          255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
                          255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
                          255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
                          255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
                          250,238,228,217,207,198,188,179,170,162,154,145,137,130,123,116,
                          109,103, 97, 91, 85, 80, 75, 70, 65, 60, 56, 62, 48, 44, 40, 37,
                           34, 31, 28, 25, 23, 21, 19, 17, 15, 13, 11, 10,  9,  8,  7,  6,
                            5,  5,  4,  4,  4,  3,  3,  3,  2,  2,  2,  2,  1,  1,  1,  1,
                            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                            1,  1,  1,  1,  2,  2,  2,  2,  3,  3,  3,  4,  4,  4,  5,  5,
                            6,  7,  8,  9, 10, 11, 13, 15, 17, 19, 21, 23, 25, 28, 31, 34,
                           37, 40, 44, 48, 62, 56, 60, 65, 70, 75, 80, 85, 91, 97,103,109,
                          116,123,130,137,145,154,162,170,179,188,198,207,217,228,238,250
                         };

    int GS_Rainbow_G[256] = {
                            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                            1,  1,  1,  1,  2,  2,  2,  2,  3,  3,  3,  4,  4,  4,  5,  5,
                            6,  7,  8,  9, 10, 11, 13, 15, 17, 19, 21, 23, 25, 28, 31, 34,
                           37, 40, 44, 48, 52, 56, 60, 65, 70, 75, 80, 85, 91, 97,103,109,
                          116,123,130,137,145,154,162,170,179,188,198,207,217,228,238,250,
                          255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
                          255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
                          255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
                          255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
                          250,238,228,217,207,198,188,179,170,162,154,145,137,130,123,116,
                          109,103, 97, 91, 85, 80, 75, 70, 65, 60, 56, 52, 48, 44, 40, 37,
                           34, 31, 28, 25, 23, 21, 19, 17, 15, 13, 11, 10,  9,  8,  7,  6,
                            5,  5,  4,  4,  4,  3,  3,  3,  2,  2,  2,  2,  1,  1,  1,  1,
                            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
                         };

    int GS_Rainbow_B[256] = {
                          250,238,228,217,207,198,188,179,170,162,154,145,137,130,123,116,
                          109,103, 97, 91, 85, 80, 75, 70, 65, 60, 56, 52, 48, 44, 40, 37,
                           34, 31, 28, 25, 23, 21, 19, 17, 15, 13, 11, 10,  9,  8,  7,  6,
                            5,  5,  4,  4,  4,  3,  3,  3,  2,  2,  2,  2,  1,  1,  1,  1,
                            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                            1,  1,  1,  1,  2,  2,  2,  2,  3,  3,  3,  4,  4,  4,  5,  5,
                            6,  7,  8,  9, 10, 11, 13, 15, 17, 19, 21, 23, 25, 28, 31, 34,
                           37, 40, 44, 48, 52, 56, 60, 65, 70, 75, 80, 85, 91, 97,103,109,
                          116,123,130,137,145,154,162,170,179,188,198,207,217,228,238,250,
                          255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
                          255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
                          255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
                          255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255
                         };
    int Rainbow_GS_length = (sizeof(GS_Rainbow_R)) / (sizeof(GS_Rainbow_R[0]));
    while (1)
    {
        int x=5, y=20;
        int loop_length = Rainbow_GS_length/x;
        for (i=0; i<loop_length; i++)
        {
            MANUL_RGB_PWM(LED_A,
                          GS_Rainbow_R[(x*i) % Rainbow_GS_length],
                          GS_Rainbow_G[(x*i) % Rainbow_GS_length],
                          GS_Rainbow_B[(x*i) % Rainbow_GS_length]);
            MANUL_RGB_PWM(LED_B,
                          GS_Rainbow_R[(x*i+y) % Rainbow_GS_length],
                          GS_Rainbow_G[(x*i+y) % Rainbow_GS_length],
                          GS_Rainbow_B[(x*i+y) % Rainbow_GS_length]);
            MANUL_RGB_PWM(LED_C,
                          GS_Rainbow_R[(x*i+2*y) % Rainbow_GS_length],
                          GS_Rainbow_G[(x*i+2*y) % Rainbow_GS_length],
                          GS_Rainbow_B[(x*i+2*y) % Rainbow_GS_length]);
            MANUL_RGB_PWM(LED_D,
                          GS_Rainbow_R[(x*i+3*y) % Rainbow_GS_length],
                          GS_Rainbow_G[(x*i+3*y) % Rainbow_GS_length],
                          GS_Rainbow_B[(x*i+3*y) % Rainbow_GS_length]);

            delay_ms(3);
        }
    }
}



