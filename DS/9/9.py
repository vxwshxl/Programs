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

# Both libraries plot onto the same figure, one axis each
fig, axes = plt.subplots(1, 2, figsize=(12, 5))

# Matplotlib visualization
axes[0].plot(df['Age'], df['Salary'], marker='o')
axes[0].set_title("Age vs Salary using Matplotlib")
axes[0].set_xlabel("Age")
axes[0].set_ylabel("Salary")

# Seaborn visualization
sns.scatterplot(x='Age', y='Salary', data=df, ax=axes[1])
axes[1].set_title("Age vs Salary using Seaborn")

plt.tight_layout()
plt.show()
