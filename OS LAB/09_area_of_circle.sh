# 9. write a shell script to input Radius and print the area of the circle

#!/bin/bash

echo "Enter the radius of the circle:"
read r

area=$(echo "scale=2; 3.14 * $r * $r" | bc)

echo "Area of the circle = $area"

# ---------------- Output ----------------
# Enter the radius of the circle:
# 7
# Area of the circle = 153.86
