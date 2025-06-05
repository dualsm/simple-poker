#!/bin/bash

make

while true; do
    output=$(./main)


    if echo "$output" | grep -q "Full House"; then
        echo "test.sh: Full House detected"
    	echo "$output"  
        break
    else
        echo "test.sh: fail"
    fi
done
