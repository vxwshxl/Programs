# 1. Write a Python program to import and export datasets in CSV, Excel, and JSON formats using the Pandas library.

import pandas as pd
import numpy as np

# Create a sample DataFrame
df = pd.DataFrame({'Name': ['Alice', 'Bob', 'Charlie'], 'Age': [25, 30, 35]})

# Export datasets
df.to_csv('01.csv', index=False)
df.to_json('01.json', orient='records')

# Requires openpyxl: pip install openpyxl
df.to_excel('01.xlsx', index=False)

# Import datasets
df_csv = pd.read_csv('01.csv')
df_json = pd.read_json('01.json')
df_excel = pd.read_excel('01.xlsx')

print("CSV Data:\n", df_csv)
print("\nJSON Data:\n", df_json)
print("\nExcel Data:\n", df_excel)