# 1. Write a Python program to import and export datasets in CSV, Excel, and JSON formats using the Pandas library.

import pandas as pd

df = pd.DataFrame({'Name': ['Alice', 'Bob', 'Charlie'], 'Age': [25, 30, 35]})
df.to_csv('01.csv', index=False)
df.to_json('01.json', orient='records')
df.to_excel('01.xlsx', index=False)

print("CSV Data:\n", pd.read_csv('01.csv'))
print("\nJSON Data:\n", pd.read_json('01.json'))
print("\nExcel Data:\n", pd.read_excel('01.xlsx'))
