# 10. Write a Python program to create bar charts, histograms,
# pie charts, box plots, scatter plots, and heatmaps.

import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

df = pd.DataFrame({'Name': ['Alice', 'Bob', 'Charlie', 'David', 'Eve'],
                   'Age': [25, 30, 35, 40, 45],
                   'Salary': [50000, 60000, 70000, 80000, 90000]})

fig, ax = plt.subplots(2, 3, figsize=(15, 9))
ax[0, 0].bar(df['Name'], df['Salary'])
ax[0, 0].set_title("Bar Chart")
ax[0, 1].hist(df['Age'], bins=5)
ax[0, 1].set_title("Histogram")
ax[0, 2].pie(df['Salary'], labels=df['Name'], autopct='%1.1f%%')
ax[0, 2].set_title("Pie Chart")
ax[1, 0].boxplot(df['Salary'])
ax[1, 0].set_title("Box Plot")
ax[1, 1].scatter(df['Age'], df['Salary'])
ax[1, 1].set_title("Scatter Plot")
sns.heatmap(df[['Age', 'Salary']].corr(), annot=True, ax=ax[1, 2]).set_title("Heatmap")
plt.tight_layout()
plt.show()

# Output:
# (graph only - no printed output)
