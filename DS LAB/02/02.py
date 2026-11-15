# 2. Write a Python program to perform data preprocessing by handling missing values, duplicate records, and inconsistent data.

import pandas as pd
import numpy as np

df = pd.DataFrame({'Name': ['Alice', 'Bob', 'Bob', 'David', 'eve '],
                   'Age': [25, np.nan, np.nan, 40, 22],
                   'Salary': [50000, 60000, 60000, -10000, 45000]})

df['Age'] = df['Age'].fillna(df['Age'].median())
df = df.drop_duplicates()
df['Name'] = df['Name'].str.strip().str.title()
s = df['Salary'].where(df['Salary'] > 0)
df['Salary'] = s.fillna(s.median())
print(df)
