#!/bin/bash
gcc -Wall -o sic si.c player.c gameLogic.c
RESULT=$?

if [ $RESULT -ne 0 ]
then
	echo "**** compile error: $RESULT ****"
else
	echo "**** compilation OK ****"
	chmod +x sic
	./sic
fi

