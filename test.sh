#!/bin/bash
make
while true; do
	./main
	if [ $? -ne 0 ]; then
		echo 'test.sh: score detected'
		break
	else
		echo 'test.sh: fail'
	fi
done
