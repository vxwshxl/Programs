# 13. Write a shell script to print the multiplication table of the input term

#!/bin/bash

echo "Enter a number:"
read n

for (( i = 1; i <= 10; i++ ))
do
    echo "$n x $i = $((n * i))"
done

# ---------------- Output ----------------
# Enter a number:
# 7
# 7 x 1 = 7
# 7 x 2 = 14
# 7 x 3 = 21
# 7 x 4 = 28
# 7 x 5 = 35
# 7 x 6 = 42
# 7 x 7 = 49
# 7 x 8 = 56
# 7 x 9 = 63
# 7 x 10 = 70
