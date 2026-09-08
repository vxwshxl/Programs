# 9. Write a Python program to visualize data using Matplotlib and Seaborn.

import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

data = {
    'Name': ['Alice', 'Bob', 'Charlie', 'David', 'Eve'],
    'Age': [25, 30, 35, 40, 45],
    'Salary': [50000, 60000, 70000, 80000, 90000]
}

df = pd.DataFrame(data)

# Matplotlib visualization
plt.plot(df['Age'], df['Salary'], marker='o')
plt.title("Age vs Salary")
plt.xlabel("Age")
plt.ylabel("Salary")
plt.show()

# Seaborn visualization
sns.scatterplot(x='Age', y='Salary', data=df)
plt.title("Age vs Salary using Seaborn")
plt.show()