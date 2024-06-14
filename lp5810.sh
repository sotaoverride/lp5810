#!/bin/sh
#LP5810 init seq
source ./utils
ti() {
        BUS=$1
        DEV=$2
        REG=$3
	WRITEVAL=$5
	if test -n "$WRITEVAL"; then 
		i2cset -y $BUS $DEV $REG $WRITEVAL
	       	RC=$?
		if test $RC = 0; then

					log i2cset cmd from $file to dev $DEV register $REG passed
		else
					log i2cset cmd from $file to dev $DEV register $REG failed
		fi
	else
		VAL=$(i2cget -y $BUS $DEV $REG c 2>&1)
		echo VAL
		log $VAL from config reg
        fi
}

test_all() {
        while read BUS DEV REG EXPECTEDVALUE WRITEVAL; do
                ti $BUS $DEV $REG $EXPECTEDVALUE $WRITEVAL;
        done
}
show_help() {
        echo " USAGE: $0 [-n <no of iterations to run>] [-f <meta-file>] ... [-f <meta-file>]
All Logs stored in log file 
format for i2c meta files:
BUS DEV REG WRITEVAL"
}


while getopts "n:f:h:" flag
do
        case $flag in
                n)
			iterations=${OPTARG}
			if test ! $iterations -gt 0
			then
				fatal "0 iterations, wtf?"
			fi
			;;
		f) file=("$OPTARG");;
                h|\? ) show_help
                exit 0
                ;;
        esac
done
shift $((OPTIND -1))
if [ "$#" -gt 0 ]; then
	echo check arguments
	show_help
	exit 0
fi
test_all 3 0x6c 0x0 0x1
test_all 3 0x6c 0x2 0x20
test_all 3 0x6c 0xD 0xB
test_all 3 0x6c 0x10 0x55
val=test_all 3 0x6f 0x0
while [ val eq 0 ] 
do
	test_all 3 0x6c 0xD 0xB
	test_all 3 0x6c 0x10 0x55
	val=test_all 3 0x6f 0x0
done
test_all 3 0x6c 0x20 0xF0
test_all 3 0x6c 0x21 0xFF
test_all 3 0x6c 0x35 0xCC
test_all 3 0x6c 0x38 0xcc
test_all 3 0x6c 0x36 0xCC
test_all 3 0x6c 0x37 0xCC
test_all 3 0x6c 0x39 0xCC
test_all 3 0x6c 0x3A 0xCC
test_all 3 0x6c 0x3c 0xCC
test_all 3 0x6c 0x44 0xFF
test_all 3 0x6c 0x45 0xFF
test_all 3 0x6c 0x46 0xFF
test_all 3 0x6c 0x47 0xFF
test_all 3 0x6c 0x48 0xFF
test_all 3 0x6c 0x49 0xFF
test_all 3 0x6c 0x4A 0xFF
test_all 3 0x6c 0x4B 0xFF
test_all 3 0x6c 0x4C 0xFF
test_all 3 0x6c 0x4D 0xFF
test_all 3 0x6c 0x4E 0xFF
test_all 3 0x6c 0x4F 0xFF

