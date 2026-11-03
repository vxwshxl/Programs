# 3. write a shell script to input a number and check whether it is an odd or even number.

#!/bin/bash

echo "Enter a number:"
read n

if (( n % 2 == 0 ))
then
    echo "$n is an Even number"
else
    echo "$n is an Odd number"
fi

# ---------------- Output ----------------
# Enter a number:
# 7
# 7 is an Odd number
