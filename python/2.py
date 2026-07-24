#2. Create a student dictionary having roll no. -> name mapping. Demonstrate its operations on both sides; key -> value & vice-versa.

students = {
    1: "Amit",
    2: "Bhavna",
    3: "Chetan",
    4: "Divya",
}

print("Initial dictionary (roll no. -> name):")
print(students)

# Key -> Value: look up a name by roll no.
roll_no = 2
print(f"\nKey -> Value: roll no. {roll_no} maps to name '{students[roll_no]}'")

# Value -> Key: look up roll no. by name
name = "Chetan"
roll_for_name = next(roll for roll, n in students.items() if n == name)
print(f"Value -> Key: name '{name}' maps to roll no. {roll_for_name}")

# Add a new entry
students[5] = "Esha"
print(f"\nAfter adding roll no. 5 -> 'Esha':\n{students}")

# Update an existing entry
students[1] = "Amit Kumar"
print(f"\nAfter updating roll no. 1 to 'Amit Kumar':\n{students}")

# Delete an entry
del students[4]
print(f"\nAfter deleting roll no. 4:\n{students}")

# Check membership on both sides
check_roll = 3
check_name = "Bhavna"
print(f"\nIs roll no. {check_roll} present? {check_roll in students}")
print(f"Is name '{check_name}' present? {check_name in students.values()}")

# Iterate over both sides
print("\nAll roll no. -> name mappings:")
for roll, n in students.items():
    print(f"  {roll} -> {n}")

print("\nAll name -> roll no. mappings (reversed view):")
reversed_students = {n: roll for roll, n in students.items()}
for n, roll in reversed_students.items():
    print(f"  {n} -> {roll}")
