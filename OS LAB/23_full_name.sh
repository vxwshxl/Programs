# 23. shell script to print full name after input name and title separately

#!/bin/bash

echo "Enter the title (Mr/Ms/Dr):"
read title

echo "Enter the name:"
read name

full_name="$title. $name"

echo "Full Name: $full_name"

# ---------------- Output ----------------
# Enter the title (Mr/Ms/Dr):
# Mr
# Enter the name:
# John Smith
# Full Name: Mr. John Smith
