# 27. Write a shell script to print the largest element from an array

#!/bin/bash

echo "Enter the number of elements:"
read n

echo "Enter $n elements:"
for (( i = 0; i < n; i++ ))
do
    read arr[i]
done

max=${arr[0]}

for (( i = 1; i < n; i++ ))
do
    if (( arr[i] > max ))
    then
        max=${arr[i]}
    fi
done

echo "Array: ${arr[*]}"
echo "Largest element = $max"

# ---------------- Output ----------------
# Enter the number of elements:
# 5
# Enter 5 elements:
# 12
# 45
# 7
# 89
# 23
# Array: 12 45 7 89 23
# Largest element = 89
