# 1. Write a shell script to add the two numbers

#!/bin/bash

echo "Enter the first number:"
read a

echo "Enter the second number:"
read b

sum=$((a + b))

echo "Sum of $a and $b = $sum"

# ---------------- Output ----------------
# Enter the first number:
# 12
# Enter the second number:
# 8
# Sum of 12 and 8 = 20
