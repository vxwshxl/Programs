# 24. shell script to print pyramid

#!/bin/bash

echo "Enter the number of rows:"
read n

for (( i = 1; i <= n; i++ ))
do
    # Leading spaces
    for (( s = 1; s <= n - i; s++ ))
    do
        echo -n " "
    done

    # Stars
    for (( j = 1; j <= 2 * i - 1; j++ ))
    do
        echo -n "*"
    done

    echo
done

# ---------------- Output ----------------
# Enter the number of rows:
# 5
#     *
#    ***
#   *****
#  *******
# *********
