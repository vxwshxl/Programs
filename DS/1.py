# 1. Write a Python program to import and export datasets in CSV, Excel, and JSON formats using the Pandas library.

import pandas as pd
import numpy as np

# Import the original CSV dataset
file_path = "1-100.csv"
df = pd.read_csv(file_path)

# Export datasets
df.to_csv('data.csv', index=False)
df.to_json('data.json', orient='records')
df.to_excel('data.xlsx', index=False)

# Import datasets
df_csv = pd.read_csv('data.csv')
df_json = pd.read_json('data.json')
df_excel = pd.read_excel('data.xlsx')

print("CSV Data:\n", df_csv)
print("\nJSON Data:\n", df_json)
print("\nExcel Data:\n", df_excel)