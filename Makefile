main: i2c.c  I2C_EN.c  I2C_EN.h  i2c.h  LED_Animation_Auto.c  LED_Animation_Auto.h  LED_Animation_Manual.c  LED_Animation_Manual.h  LP5813.c  LP5813.h  main.c

        ${CXX} i2c.c  I2C_EN.c  I2C_EN.h  i2c.h  LED_Animation_Auto.c  LED_Animation_Auto.h  LED_Animation_Manual.c  LED_Animation_Manual.h  LP5813.c  LP5813.h  main.c -o main

clean:

        rm -f main
        rm -f *.o
