# 8. Write a Python program to manipulate and transform datasets
# using the Pandas library.

import pandas as pd

data = {
    'Name': ['Alice', 'Bob', 'Charlie', 'David'],
    'Age': [25, 30, 35, 40],
    'Salary': [50000, 60000, 70000, 80000]
}

df = pd.DataFrame(data)

print("Original Data:")
print(df)

# Add a new column
df['Bonus'] = df['Salary'] * 0.10

# Filter data
filtered_data = df[df['Age'] > 30]

# Sort data by Salary
sorted_data = df.sort_values('Salary', ascending=False)

print("\nAfter Adding Bonus:")
print(df)

print("\nFiltered Data:")
print(filtered_data)

print("\nSorted Data:")
print(sorted_data)