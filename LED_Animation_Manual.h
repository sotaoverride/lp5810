/*
 * LED_Animation_Manual.h
 *
 *  Created on: Oct 24, 2022
 *      Author: a0498597
 */

#ifndef LED_ANIMATION_MANUAL_H_
#define LED_ANIMATION_MANUAL_H_

//4-scan TCM mode
extern void RGB_ALL_FULL();
extern void RGB_ALL_OFF();
extern void RGB_Breathing(uint8_t R_color,
                          uint8_t G_color,
                          uint8_t B_color);
extern void RGB_Rainbow();


//direct mode
extern void LED_ALL_FULL();
extern void LED_ALL_OFF();
extern void LED_Breathing();


#endif /* LED_ANIMATION_MANUAL_H_ */
