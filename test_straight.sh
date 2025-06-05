#!/bin/bash
start=$(date +%s%N)

while true; do
    output=$(./main)


    if echo "$output" | grep -q "Straight"; then
        echo "test: Straight detected"
    	echo "$output"  
        break
    fi
done

end=$(date +%s%N)
elapsed_ns=$((end - start))
elapsed_sec=$(echo "scale=3; $elapsed_ns / 1000000000" | bc)
echo "Elapsed time: ${elapsed_sec} seconds"
