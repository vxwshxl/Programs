# 2. Write a Python program to perform data preprocessing by handling missing values, duplicate records, and inconsistent data.

import pandas as pd
import numpy as np

data = {'Name': ['Alice', 'Bob', 'Bob', 'David', 'eve '],
 'Age': [25, np.nan, np.nan, 40, 22],
 'Salary': [50000, 60000, 60000, -10000, 45000]}

df = pd.DataFrame(data)

# 1. Handle missing values (Fill with median)
df['Age'] = df['Age'].fillna(df['Age'].median())

# 2. Handle duplicate records
df = df.drop_duplicates()

# 3. Handle inconsistent data (Strip whitespace, fix negative salary)
df['Name'] = df['Name'].str.strip().str.title()
df['Salary'] = df['Salary'].apply(lambda x: x if x > 0 else np.nan)
df['Salary'] = df['Salary'].fillna(df['Salary'].median())

print(df)