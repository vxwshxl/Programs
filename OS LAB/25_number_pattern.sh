# 25. Write the shell script to print the following pattern after input term #n=3

#!/bin/bash
# For n = 3:
# 1
# 1 2
# 1 2 3

echo "Enter the number of terms:"
read n

for (( i = 1; i <= n; i++ ))
do
    for (( j = 1; j <= i; j++ ))
    do
        echo -n "$j "
    done
    echo
done

# ---------------- Output ----------------
# Enter the number of terms:
# 3
# 1
# 1 2
# 1 2 3
