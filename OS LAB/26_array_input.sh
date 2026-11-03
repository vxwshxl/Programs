# 26. Write a shell script to input the array elements and display it.

#!/bin/bash

echo "Enter the number of elements:"
read n

echo "Enter $n elements:"
for (( i = 0; i < n; i++ ))
do
    read arr[i]
done

echo "The array elements are:"
for (( i = 0; i < n; i++ ))
do
    echo "arr[$i] = ${arr[i]}"
done

# ---------------- Output ----------------
# Enter the number of elements:
# 5
# Enter 5 elements:
# 10
# 20
# 30
# 40
# 50
# The array elements are:
# arr[0] = 10
# arr[1] = 20
# arr[2] = 30
# arr[3] = 40
# arr[4] = 50
