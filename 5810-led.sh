#!/bin/sh
#LED Test
source ./utils
set -x
BUS=3
ADDR=0x50
#MANUAL DC REGISTERS FOR RGB
RED_MAN_CUR_REG=0x30
GREEN_MAN_CUR_REG=0x31
BLUE_MAN_CUR_REG=0x32
#MANUAL PWM REGISTERS FOR RGB
#MANUAL PWM REGISTERS WILL SETUP LATER..
RED_PWM_REG=0x40
GREEN_PWM_REG=0x41
BLUE_PWM_REG=0x42
percentageToHEX() {
	#each hex step is 0.39 percent
	printf '0x%x' $1
}
reset() {
	i2cset -y $BUS $ADDR $RED_MAN_CUR_REG 0
	i2cset -y $BUS $ADDR $GREEN_MAN_CUR_REG 0
	i2cset -y $BUS $ADDR $BLUE_MAN_CUR_REG 0
	i2cset -y $BUS $ADDR $RED_PWM_REG 0
	i2cset -y $BUS $ADDR $GREEN_PWM_REG 0
	i2cset -y $BUS $ADDR $BLUE_PWM_REG 0

}
enable() {
	i2cset -y $BUS $ADDR 0x00 0x01
	i2cset -y $BUS $ADDR 0x10 0x55
}
stick() {
	i2cset -y $BUS $ADDR 0x20 0x0f
}
ts() {
	enable
	reset
	stick
	enable
	i2cset -y $BUS $ADDR $RED_MAN_CUR_REG "$(percentageToHEX $1)"
	i2cset -y $BUS $ADDR $GREEN_MAN_CUR_REG "$(percentageToHEX $2)"
	i2cset -y $BUS $ADDR $BLUE_MAN_CUR_REG "$(percentageToHEX $3)"
	i2cset -y $BUS $ADDR $RED_PWM_REG "$(percentageToHEX $1)"
	i2cset -y $BUS $ADDR $GREEN_PWM_REG "$(percentageToHEX $2)"
	i2cset -y $BUS $ADDR $BLUE_PWM_REG "$(percentageToHEX $3)"
}

test_all() {
	ts $1 $2 $3
}
show_help() {
	echo "USAGE: $0 [-r<intensity for red led> -g<intensity for green led> -b<intensity for blue led>] \n
	Intensity can take values from 0x00 to 0xff each setp being .39%"
}

red_intensity=0x5c
green_intensity=0x5c
blue_intensity=0x5c
while getopts r:g:b:h flag
do
	case "${flag}" in
		r) red_intensity=${OPTARG};;
		g) green_intensity=${OPTARG};;
		b) blue_intensity=${OPTARG};;
		h|\?) show_help
		exit 0
		;;
	esac
done
shift $((OPTIND -1))
checkCmdParams $OPTIND $# LEDTest
seq 1 $iterations | while read x; do
	test_all $red_intensity $green_intensity $blue_intensity
done

