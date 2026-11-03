# 21. write the shell script to print the power of an input number and bash without using any predefined function

#!/bin/bash

echo "Enter the base:"
read base

echo "Enter the exponent:"
read exp

result=1

for (( i = 1; i <= exp; i++ ))
do
    result=$((result * base))
done

echo "$base ^ $exp = $result"

# ---------------- Output ----------------
# Enter the base:
# 2
# Enter the exponent:
# 10
# 2 ^ 10 = 1024
