# 8. write a shell script to input a term and print the Fibonacci Series of that term

#!/bin/bash

echo "Enter the number of terms:"
read n

a=0
b=1

echo "Fibonacci Series of $n terms:"

for (( i = 1; i <= n; i++ ))
do
    echo -n "$a "
    c=$((a + b))
    a=$b
    b=$c
done

echo

# ---------------- Output ----------------
# Enter the number of terms:
# 10
# Fibonacci Series of 10 terms:
# 0 1 1 2 3 5 8 13 21 34
