# 5. write a shell script to input a number and print the reverse of that number

#!/bin/bash

echo "Enter a number:"
read n

num=$n
rev=0

while (( num > 0 ))
do
    digit=$((num % 10))
    rev=$((rev * 10 + digit))
    num=$((num / 10))
done

echo "Reverse of $n = $rev"

# ---------------- Output ----------------
# Enter a number:
# 12345
# Reverse of 12345 = 54321
