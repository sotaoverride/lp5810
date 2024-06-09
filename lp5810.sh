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

test_all < $file
