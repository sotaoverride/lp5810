main: -I. i2c.c  I2C_EN.c LED_Animation_Auto.c LED_Animation_Manual.c LP5813.c main.c

        ${CXX} LED_Animation_Auto.c LED_Animation_Manual.c LP5813.c main.c -o main

clean:

        rm -f main
        rm -f *.o
