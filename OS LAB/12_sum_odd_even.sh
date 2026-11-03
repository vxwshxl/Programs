# 12. Write a shell script to print the sum of odd and even numbers from 1 to 50

#!/bin/bash

odd=0
even=0

for (( i = 1; i <= 50; i++ ))
do
    if (( i % 2 == 0 ))
    then
        even=$((even + i))
    else
        odd=$((odd + i))
    fi
done

echo "Sum of odd numbers from 1 to 50  = $odd"
echo "Sum of even numbers from 1 to 50 = $even"

# ---------------- Output ----------------
# Sum of odd numbers from 1 to 50  = 625
# Sum of even numbers from 1 to 50 = 650
