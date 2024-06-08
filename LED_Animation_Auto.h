/*
 * LED_Animation_Auto.h
 *
 *  Created on: Dec 5, 2022
 *      Author: a0498597
 */

#ifndef LED_ANIMATION_AUTO_H_
#define LED_ANIMATION_AUTO_H_

//4-scan TCM-mode
extern void RGB_Dot_Rainbow(uint8_t RGB_NUM,
                            uint8_t R_Start,
                            uint8_t G_Start,
                            uint8_t B_Start);
extern void RGB_ALL_Rainbow();
extern void RGB_Blink();
extern void RGB_Fade_IN_And_OUT();
extern void RGB_Horse_Race();

//direct mode
extern void LED_Blink();
extern void LED_Fade_IN_And_OUT();
extern void LED_Horse_Race();


#endif /* LED_ANIMATION_AUTO_H_ */
