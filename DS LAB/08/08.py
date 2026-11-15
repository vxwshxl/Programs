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
