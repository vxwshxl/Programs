# 18. Write the shell script using infinite loop to multiply and subtract the two number using case statement

#!/bin/bash

while true
do
    echo
    echo "1. Multiply"
    echo "2. Subtract"
    echo "3. Exit"
    echo "Enter your choice:"
    read choice

    case $choice in
        1)
            echo "Enter two numbers:"
            read a b
            echo "$a x $b = $((a * b))"
            ;;
        2)
            echo "Enter two numbers:"
            read a b
            echo "$a - $b = $((a - b))"
            ;;
        3)
            echo "Exiting..."
            exit 0
            ;;
        *)
            echo "Invalid choice"
            ;;
    esac
done

# ---------------- Output ----------------
#
# 1. Multiply
# 2. Subtract
# 3. Exit
# Enter your choice:
# 1
# Enter two numbers:
# 6 7
# 6 x 7 = 42
#
# 1. Multiply
# 2. Subtract
# 3. Exit
# Enter your choice:
# 2
# Enter two numbers:
# 20 8
# 20 - 8 = 12
#
# 1. Multiply
# 2. Subtract
# 3. Exit
# Enter your choice:
# 3
# Exiting...
