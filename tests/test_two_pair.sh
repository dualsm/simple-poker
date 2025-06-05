#!/bin/bash
start=$(date +%s%N)

while true; do
    output=$(./main)
	
    two_pair_detected=$(echo "$output" | grep -o "Pair" | wc -l)
    if [ "$two_pair_detected" -eq 4 ]; then
        echo "test: Two Pair detected"
    	echo "$output"  
        break
    fi
done

end=$(date +%s%N)
elapsed_ns=$((end - start))
elapsed_sec=$(echo "scale=3; $elapsed_ns / 1000000000" | bc)
echo "Elapsed time: ${elapsed_sec} seconds"
