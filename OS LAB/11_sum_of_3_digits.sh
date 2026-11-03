# 11. Write the shell script to print the sum of the digit of the 3 digit number

#!/bin/bash

echo "Enter a 3 digit number:"
read n

if (( n < 100 || n > 999 ))
then
    echo "Please enter a 3 digit number"
    exit 1
fi

d1=$((n / 100))
d2=$((n / 10 % 10))
d3=$((n % 10))

sum=$((d1 + d2 + d3))

echo "$d1 + $d2 + $d3 = $sum"
echo "Sum of digits of $n = $sum"

# ---------------- Output ----------------
# Enter a 3 digit number:
# 456
# 4 + 5 + 6 = 15
# Sum of digits of 456 = 15
