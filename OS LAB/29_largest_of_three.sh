# 29. shell script to print the largest of three input numbers

#!/bin/bash

echo "Enter three numbers:"
read a b c

if (( a >= b && a >= c ))
then
    largest=$a
elif (( b >= a && b >= c ))
then
    largest=$b
else
    largest=$c
fi

echo "Largest of $a, $b and $c = $largest"

# ---------------- Output ----------------
# Enter three numbers:
# 15 42 27
# Largest of 15, 42 and 27 = 42
