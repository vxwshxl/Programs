# 1. Import and export datasets in CSV, Excel and JSON using Pandas.

import pandas as pd

df = pd.DataFrame({'Name': ['Alice', 'Bob', 'Charlie'], 'Age': [25, 30, 35]})
df.to_csv('01.csv', index=False)
df.to_json('01.json', orient='records')
df.to_excel('01.xlsx', index=False)

print("CSV Data:\n", pd.read_csv('01.csv'))
print("\nJSON Data:\n", pd.read_json('01.json'))
print("\nExcel Data:\n", pd.read_excel('01.xlsx'))

# Output:
# CSV Data:
#        Name  Age
# 0    Alice   25
# 1      Bob   30
# 2  Charlie   35
#
# JSON Data:
#        Name  Age
# 0    Alice   25
# 1      Bob   30
# 2  Charlie   35
#
# Excel Data:
#        Name  Age
# 0    Alice   25
# 1      Bob   30
# 2  Charlie   35
