# 28. Write a shell script to input a term and print the pascal triangle of that term

#!/bin/bash

echo "Enter the number of terms:"
read n

for (( i = 0; i < n; i++ ))
do
    # Leading spaces to center the row
    for (( s = 0; s < n - i - 1; s++ ))
    do
        echo -n "  "
    done

    # Each value is C(i, j) = C(i, j - 1) * (i - j + 1) / j
    c=1
    for (( j = 0; j <= i; j++ ))
    do
        printf "%4d" $c
        c=$((c * (i - j) / (j + 1)))
    done

    echo
done

# ---------------- Output ----------------
# Enter the number of terms:
# 5
#            1
#          1   1
#        1   2   1
#      1   3   3   1
#    1   4   6   4   1
