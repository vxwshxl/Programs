# 20. Write the shell script to print the grade after input the marks of four different subjects

#!/bin/bash

echo "Enter the marks of 4 subjects (out of 100):"
read m1 m2 m3 m4

total=$((m1 + m2 + m3 + m4))
percent=$((total / 4))

if (( percent >= 90 ))
then
    grade="A+"
elif (( percent >= 80 ))
then
    grade="A"
elif (( percent >= 70 ))
then
    grade="B"
elif (( percent >= 60 ))
then
    grade="C"
elif (( percent >= 50 ))
then
    grade="D"
else
    grade="F"
fi

echo "Total      = $total / 400"
echo "Percentage = $percent%"
echo "Grade      = $grade"

# ---------------- Output ----------------
# Enter the marks of 4 subjects (out of 100):
# 85 90 78 92
# Total      = 345 / 400
# Percentage = 86%
# Grade      = A
