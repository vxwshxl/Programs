# 17. Write the shell script to input a year and check whether it is leap year or not

#!/bin/bash

echo "Enter a year:"
read y

if (( (y % 4 == 0 && y % 100 != 0) || y % 400 == 0 ))
then
    echo "$y is a Leap Year"
else
    echo "$y is not a Leap Year"
fi

# ---------------- Output ----------------
# Enter a year:
# 2024
# 2024 is a Leap Year
