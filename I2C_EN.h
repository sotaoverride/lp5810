/*
 * I2C_EN.h
 *
 *  Created on: Sep 23, 2022
 *      Author: a0498597
 */
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#ifndef I2C_IFS_EN_H_
#define I2C_IFS_EN_H_

#define CPU_F ((double)48000000)
#define delay_us(x) sleep((long)((double)x/1000000.0))
#define delay_ms(x) sleep((long)((double)x/1000.0))


extern void I2C_setSlave(unsigned short slaveAdr_5bit,
                         unsigned short regAdr_10bit);
extern void I2C_write (unsigned short regAdr_10bit,
                       uint8_t writeByte);



#endif /* I2C_EN_H_ */
