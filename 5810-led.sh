#!/bin/sh
#LED Test
source ./utils
BUS=3
ADDR=0x50
#MANUAL DC REGISTERS FOR RGB
RED_MAN_CUR_REG=0x30
GREEN_MAN_CUR_REG=0x31
BLUE_MAN_CUR_REG=0x32
#MANUAL PWM REGISTERS FOR RGB
#MANUAL PWM REGISTERS WILL SETUP LATER..
RED_PWM_REG=
GREEN_PWM_REG=
BLUW_PWM_REG=
percentageToHEX() {
	#each hex step is 0.39 percent
	printf '0x%x' $((($1*100000)/0392156))
}
enable() {
	i2cset -y $BUS $ADDR 0x00 0x01
}
ts() {
	enable
	i2cset -y $BUS $ADDR $RED_MAN_CUR_REG "$(percentageToHEX $1)"
	i2cset -y $BUS $ADDR $GREEN_MAN_CUR_REG "$(percentageToHEX $2)"
	i2cset -y $BUS $ADDR $BLUE_MAN_CUR_REG "$(percentageToHEX $3)"
}

test_all() {
	ts $1 $2 $2;
}
show_help() {
	echo "USAGE: $0 [-r<intensity for red led> -g<intensity for green led> -b<intensity for blue led>] \n
Intencity units here are decipercent, so intensity of 1 would be 0.1% percent, intensity of  1000 would be 100.0%"
}

red_intensity=0x5c
green_intensity=0x5c
blue_intensity=0x5c
while getopts r:g:b:h flag
do
	case "${flag}" in
		r) red_intensity=${OPTARG};;
		g) green_intensity=${OPTARG};;
		b) blue_intenisty=${OPTARG};;
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

