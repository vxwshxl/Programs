# 22. shell function to input a number and print the factorial of that number

#!/bin/bash

factorial()
{
    local n=$1
    local fact=1

    for (( i = 2; i <= n; i++ ))
    do
        fact=$((fact * i))
    done

    echo $fact
}

echo "Enter a number:"
read n

echo "Factorial of $n = $(factorial $n)"

# ---------------- Output ----------------
# Enter a number:
# 6
# Factorial of 6 = 720
