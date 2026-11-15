# 8. Write a Python program to manipulate and transform datasets
# using the Pandas library.

import pandas as pd

df = pd.DataFrame({'Name': ['Alice', 'Bob', 'Charlie', 'David'],
                   'Age': [25, 30, 35, 40],
                   'Salary': [50000, 60000, 70000, 80000]})
df['Bonus'] = df['Salary'] * 0.10
print("After Adding Bonus:\n", df)
print("\nFiltered (Age > 30):\n", df[df['Age'] > 30])
print("\nSorted by Salary:\n", df.sort_values('Salary', ascending=False))

# Output:
# After Adding Bonus:
#        Name  Age  Salary   Bonus
# 0    Alice   25   50000  5000.0
# 1      Bob   30   60000  6000.0
# 2  Charlie   35   70000  7000.0
# 3    David   40   80000  8000.0
#
# Filtered (Age > 30):
#        Name  Age  Salary   Bonus
# 2  Charlie   35   70000  7000.0
# 3    David   40   80000  8000.0
#
# Sorted by Salary:
#        Name  Age  Salary   Bonus
# 3    David   40   80000  8000.0
# 2  Charlie   35   70000  7000.0
# 1      Bob   30   60000  6000.0
# 0    Alice   25   50000  5000.0
