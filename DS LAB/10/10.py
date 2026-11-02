# 10. Write a Python program to create bar charts, histograms,
# pie charts, box plots, scatter plots, and heatmaps.

import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

data = {
    'Name': ['Alice', 'Bob', 'Charlie', 'David', 'Eve'],
    'Age': [25, 30, 35, 40, 45],
    'Salary': [50000, 60000, 70000, 80000, 90000]
}

df = pd.DataFrame(data)

# All six charts are drawn on one figure, so they appear together
# instead of one window at a time
fig, axes = plt.subplots(2, 3, figsize=(15, 9))
fig.suptitle("Six Plot Types", fontsize=15)

# 1. Bar Chart
axes[0, 0].bar(df['Name'], df['Salary'])
axes[0, 0].set_title("Salary by Employee")
axes[0, 0].set_xlabel("Name")
axes[0, 0].set_ylabel("Salary")

# 2. Histogram
axes[0, 1].hist(df['Age'], bins=5)
axes[0, 1].set_title("Age Distribution")
axes[0, 1].set_xlabel("Age")
axes[0, 1].set_ylabel("Frequency")

# 3. Pie Chart
axes[0, 2].pie(df['Salary'], labels=df['Name'], autopct='%1.1f%%')
axes[0, 2].set_title("Salary Distribution")

# 4. Box Plot
axes[1, 0].boxplot(df['Salary'])
axes[1, 0].set_title("Salary Box Plot")
axes[1, 0].set_ylabel("Salary")

# 5. Scatter Plot
axes[1, 1].scatter(df['Age'], df['Salary'])
axes[1, 1].set_title("Age vs Salary")
axes[1, 1].set_xlabel("Age")
axes[1, 1].set_ylabel("Salary")

# 6. Heatmap
correlation = df[['Age', 'Salary']].corr()

sns.heatmap(correlation, annot=True, ax=axes[1, 2])
axes[1, 2].set_title("Correlation Heatmap")

# Keeps the titles and labels from overlapping
plt.tight_layout()

# One window, drawn once, holding every chart
plt.show()
