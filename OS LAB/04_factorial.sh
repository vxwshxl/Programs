# 4. write a shell script to input a number and print the factorial of that number

#!/bin/bash

echo "Enter a number:"
read n

fact=1
i=1

while (( i <= n ))
do
    fact=$((fact * i))
    i=$((i + 1))
done

echo "Factorial of $n = $fact"

# ---------------- Output ----------------
# Enter a number:
# 5
# Factorial of 5 = 120
