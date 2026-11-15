# 2. Data preprocessing: missing values, duplicates and inconsistent data.

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

# Output:
#     Name   Age   Salary
# 0  Alice  25.0  50000.0
# 1    Bob  25.0  60000.0
# 3  David  40.0  50000.0
# 4    Eve  22.0  45000.0
