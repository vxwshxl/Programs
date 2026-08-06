# 1. Write a Python program to import and export datasets in CSV, Excel, and JSON formats using the Pandas library.

import pandas as pd
import numpy as np

# Create a sample DataFrame
df = pd.DataFrame({'Name': ['Alice', 'Bob', 'Charlie'], 'Age': [25, 30, 35]})

# Export datasets
df.to_csv('data.csv', index=False)
df.to_json('data.json', orient='records')

# Requires openpyxl: pip install openpyxl
df.to_excel('data.xlsx', index=False)

# Import datasets
df_csv = pd.read_csv('data.csv')
df_json = pd.read_json('data.json')
df_excel = pd.read_excel('data.xlsx')

print("CSV Data:\n", df_csv)
