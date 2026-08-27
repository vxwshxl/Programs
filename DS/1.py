# 1. Write a Python program to import and export datasets in CSV, Excel, and JSON formats using the Pandas library.

import pandas as pd
import numpy as np

# Import the original CSV dataset
file_path = "/Users/vee/Downloads/products-100.csv"
df = pd.read_csv(file_path)

# Export datasets
df.to_csv('/Users/vee/Downloads/data.csv', index=False)
df.to_json('/Users/vee/Downloads/data.json', orient='records')
df.to_excel('/Users/vee/Downloads/data.xlsx', index=False)

# Import datasets
df_csv = pd.read_csv('/Users/vee/Downloads/data.csv')
df_json = pd.read_json('/Users/vee/Downloads/data.json')
df_excel = pd.read_excel('/Users/vee/Downloads/data.xlsx')

print("CSV Data:\n", df_csv)
print("\nJSON Data:\n", df_json)
print("\nExcel Data:\n", df_excel)