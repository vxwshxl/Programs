# 6. Write a shell script to print the sum of the digit of the input term.

#!/bin/bash

echo "Enter a number:"
read n

num=$n
sum=0

while (( num > 0 ))
do
    sum=$((sum + num % 10))
    num=$((num / 10))
done

echo "Sum of digits of $n = $sum"

# ---------------- Output ----------------
# Enter a number:
# 4567
# Sum of digits of 4567 = 22
