# 19. Write a program in shell script to swap the values without using the third variables

#!/bin/bash

echo "Enter the first number (a):"
read a

echo "Enter the second number (b):"
read b

echo "Before swapping: a = $a, b = $b"

a=$((a + b))
b=$((a - b))
a=$((a - b))

echo "After swapping:  a = $a, b = $b"

# ---------------- Output ----------------
# Enter the first number (a):
# 10
# Enter the second number (b):
# 20
# Before swapping: a = 10, b = 20
# After swapping:  a = 20, b = 10
